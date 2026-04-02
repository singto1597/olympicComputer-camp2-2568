import re
import os
import shutil

# -----------------------------------------------------
# ตั้งค่า Path ต่างๆ (อิงจากการรันที่โฟลเดอร์ root ของโปรเจกต์)
# -----------------------------------------------------
score_path = 'script/score.txt'
readme_path = 'readme.md'
target_dir = 'src/2_incamp/1_cmu-grader'
done_dir = os.path.join(target_dir, '__DONE__')

# 1. อ่านไฟล์ score.txt ที่ก๊อปมาจาก Grader
try:
    with open(score_path, 'r', encoding='utf-8') as f:
        text = f.read()
except FileNotFoundError:
    print(f"❌ หาไฟล์ไม่เจอ: เช็คให้ชัวร์ว่าเอาตารางคะแนนไปแปะไว้ใน '{score_path}' แล้ว")
    exit()

# ใช้ Regex จับคู่เฉพาะข้อที่ได้ "100 / 100"
matches = re.findall(r'100\s*/\s*100\s*([A-Za-z0-9_]+)', text)

# สร้างโฟลเดอร์ __DONE__ รอไว้เลยถ้ายังไม่มี
if not os.path.exists(done_dir):
    os.makedirs(done_dir)

moved_count = 0
updated_readme_count = 0

# 2. อ่านไฟล์ readme.md เพื่อเตรียมติ๊กถูก
try:
    with open(readme_path, 'r', encoding='utf-8') as f:
        readme_content = f.read()
except FileNotFoundError:
    print(f"⚠️ หาไฟล์ '{readme_path}' ไม่เจอ ข้ามสเต็ปการอัปเดต Readme ไปนะ")
    readme_content = ""

# 3. ลุยงาน! (ย้ายโฟลเดอร์ + อัปเดต Readme)
for task in matches:
    # ย้ายโฟลเดอร์
    task_path = os.path.join(target_dir, task)
    
    # ถ้าเจอโฟลเดอร์งานอยู่ข้างนอก และยังไม่ได้อยู่ใน __DONE__ ให้ย้ายซะ
    if os.path.exists(task_path) and not os.path.isdir(os.path.join(done_dir, task)):
        shutil.move(task_path, done_dir)
        print(f"📦 ย้ายโฟลเดอร์: {task} -> __DONE__")
        moved_count += 1
    
    # อัปเดต Readme (ค้นหาคำว่า "- [ ] C2Pxx" แล้วเปลี่ยนเป็น "- [x] C2Pxx")
    if readme_content:
        pattern = rf"- \[ \] {task}\b"
        if re.search(pattern, readme_content):
            readme_content = re.sub(pattern, f"- [x] {task}", readme_content)
            print(f"📝 ติ๊กถูกใน Readme: {task} แล้ว!")
            updated_readme_count += 1

# 4. เขียนข้อมูลใหม่ทับไฟล์ readme.md
if readme_content:
    with open(readme_path, 'w', encoding='utf-8') as f:
        f.write(readme_content)

print("-" * 40)
if moved_count == 0 and updated_readme_count == 0:
    print("😎 ไม่มีอะไรให้อัปเดต งานปัจจุบันเคลียร์หมดแล้ว!")
else:
    print(f"🎉 สรุป: ย้ายไฟล์ไป {moved_count} ข้อ | ติ๊กถูกใน Readme ไป {updated_readme_count} ข้อ")