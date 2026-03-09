#!/usr/bin/env fish

# เช็คแค่ว่ามีโฟลเดอร์ src มั้ย จะได้ไม่ต้องผูกติดกับชื่อโปรเจกต์เดิม
if not test -d src
    echo "❌ Error: กรุณารันสคริปต์จากหน้า folder หลักที่มีโฟลเดอร์ 'src'"
    exit 1
end

echo "🚀 เริ่มจัดระเบียบไฟล์โจทย์..."

# วนลูปหาไฟล์ PDF ในโฟลเดอร์ย่อย 1 ชั้น (เช่น src/1_precamp/*.pdf)
for file in src/*/*.pdf
    # 1. ดึงชื่อไฟล์แบบไม่เอา .pdf ออกมา (เช่น "01-Squid Game")
    set basename_no_ext (basename -s .pdf "$file")
    
    # 2. เปลี่ยนเว้นวรรค เป็น _ จะได้พิมพ์ใน Terminal ง่ายๆ (เช่น "01-Squid_Game")
    set id (string replace -a " " "_" "$basename_no_ext")
    
    # 3. ดึงชื่อโฟลเดอร์แม่มันมา (เช่น "src/1_precamp")
    set parent_dir (dirname "$file")
    
    # กำหนด path ปลายทาง (เช่น "src/1_precamp/01-Squid_Game")
    set target_dir "$parent_dir/$id"
    
    # สร้างโฟลเดอร์
    mkdir -p "$target_dir"
    
    # ย้ายไฟล์ PDF เข้าไปเก็บ
    mv "$file" "$target_dir/"
    
    # สร้างไฟล์ .cpp โดยใช้ชื่อใหม่ที่ไม่มีเว้นวรรค
    set cpp_file "$target_dir/$id.cpp"
    
    if not test -e "$cpp_file"
        if test -f template
            cp template "$cpp_file"
            echo "✅ $id: สร้างโฟลเดอร์ & ดึงโค้ดจาก Template"
        else
            touch "$cpp_file"
            echo "⚠️ $id: สร้างโฟลเดอร์ & .cpp (ไฟล์เปล่า เพราะไม่เจอ template หน้าสุด)"
        end
    else
        echo "ℹ️  $id: จัดระเบียบ PDF แล้ว (.cpp มีอยู่แล้ว)"
    end
end

echo "🎉 เสร็จเรียบร้อย! พร้อมลุยค่าย 2!"