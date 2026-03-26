#!/usr/bin/env fish

# ==========================================
# 🍪 โหลด COOKIE (อย่าลืมไปเอาคุกกี้เว็บ CMU มาใส่ใหม่นะ!)
# ==========================================
if test -f script/secrets.fish
    source script/secrets.fish
else
    echo "❌ ไม่เจอไฟล์ secrets.fish!"
    exit 1
end

if test -z "$USER_COOKIE"
    echo "❌ มึงยังไม่ได้ใส่ Cookie ใน secrets.fish!"
    exit 1
end

# ฟังก์ชั่นโหลดไฟล์
function download_task
    set id $argv[1]
    
    # อัปเดต URL ตามระบบ Grader ค่าย 2
    set url "https://www.cs.science.cmu.ac.th/gradero/02_comp_o_camp2/tasks/$id/statements/pdf"
    
    # ดันไฟล์ไปเก็บไว้ในโฟลเดอร์ค่าย 2
    set target_dir "src/2_incamp/$id"
    set output_file "$target_dir/$id.pdf"

    # สร้างโฟลเดอร์รอไว้เลย จะได้เป็นระเบียบ
    mkdir -p "$target_dir"

    echo "⬇️  กำลังโหลด: $id ..."

    aria2c -c -x 16 -s 16 \
        --header="Cookie: $USER_COOKIE" \
        --user-agent="Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36" \
        -o "$output_file" \
        "$url"
    
    # เช็คขนาดไฟล์ว่าโหลดมาเป็น PDF จริง หรือติดหน้า Login HTML
    set filesize (du -k "$output_file" | cut -f1)
    if test "$filesize" -lt 5
        echo "⚠️  ไฟล์ $id เล็กผิดปกติ ($filesize KB) คุกกี้อาจจะหมดอายุ หรือโจทย์ยังไม่เปิดให้ดู"
        # ลบไฟล์เสียทิ้ง จะได้ไม่รก
        rm "$output_file"
    else
        echo "✅ โหลด $id เสร็จแล้ว!"
        
        # (แถม) สร้างไฟล์ .cpp รอไว้เลย ถ้ายังไม่มี
        if not test -f "$target_dir/$id.cpp"
            cp template "$target_dir/$id.cpp"
            echo "   📝 สร้างไฟล์ $id.cpp พร้อม template เรียบร้อย!"
        end
    end
end

# ==========================================
# 🔄 ชุดลูปโหลดโจทย์ (อิงตาม Task Overview ค่าย 2)
# ==========================================

echo "🚀 เริ่มมหกรรมดูดโจทย์ค่าย 2..."

# 1. หมวด C2P (01 ถึง 99)
for i in (seq -f "%02g" 1 99)
    download_task "C2P$i"
end

# 2. หมวด C2T (01 ถึง 19)
for i in (seq -f "%02g" 1 19)
    download_task "C2T$i"
end

# 3. หมวด C2E - Exam (01 ถึง 12)
for i in (seq -f "%02g" 1 12)
    download_task "C2E$i"
end

# 4. หมวด TASK พิเศษ (เลขกระโดด) และโจทย์เดี่ยวๆ
set special_tasks TASK_024 TASK_025 TASK_028 TASK_034 TASK_035 TASK_036 TASK_046 TASK_047 TASK_095 TASK_098 TASK_124 TASK_166 TASK_242 C2Q001
for t in $special_tasks
    download_task $t
end

echo "🎉 จบงาน! ไปลุยเขียนโค้ดใน src/2_incamp/ ได้เลย!"