#!/usr/bin/env fish

# เช็คก่อนว่ามีไฟล์ต้นแบบมั้ย
if not test -f template
    echo "❌ หาไฟล์ 'template' ไม่เจอ! เช็คก่อนว่าสร้างไว้หน้าโฟลเดอร์สุดหรือยัง?"
    exit 1
end

echo "🔥 กำลังไล่อัดโค้ดจาก template ลงทุกไฟล์ .cpp..."

# เพิ่มความลึกของ path ไปอีก 1 ชั้น (src/บทเรียน/ข้อ/ไฟล์.cpp)
for file in src/*/*/*.cpp
    cp template "$file"
    echo "✅ อัปเดตทับ: $file"
end

echo "🎉 เสร็จ! อัดโค้ดลงทุกไฟล์เรียบร้อย"