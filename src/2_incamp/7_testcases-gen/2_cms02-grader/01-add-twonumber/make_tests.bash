#!/bin/bash

# สั่งให้สคริปต์หยุดทำงานทันทีถ้ามี Error เกิดขึ้น
set -e

echo "🚀 Compiling solution and generator..."
# คอมไพล์แบบ -O2 ให้โค้ดทำงานเร็วปรู๊ดปร๊าด
g++ -O2 solution.cpp -o sol
g++ -O2 gen.cpp -o gen

# สร้างโฟลเดอร์เก็บเทสเคส (ลบของเก่าทิ้งก่อนเพื่อความชัวร์ จะได้ไม่ปนกัน)
rm -rf tests testcases.zip
mkdir -p tests

# ลูปสร้าง 10 เทสเคส
for i in {01..10}; do
    echo "Generating test case $i..."

    # 1. รัน gen เซฟผลลัพธ์ลงไฟล์ .in
    ./gen $i > tests/$i.in

    # 2. รัน sol คายคำตอบออกมาเป็นไฟล์ .out (เปลี่ยนจาก .sol เป็น .out)
    ./sol < tests/$i.in > tests/$i.out
done

echo "🧹 Cleaning up executable files..."
rm sol gen

echo "📦 Zipping testcases for CMS..."
# เข้าไปในโฟลเดอร์ tests แล้ว zip เฉพาะไฟล์ข้างใน (CMS ไม่ชอบให้ zip ติดชื่อโฟลเดอร์)
cd tests
zip -q ../testcases.zip *.in *.out
cd ..

echo "✅ Done! ไฟล์ 'testcases.zip' พร้อมอัปโหลดขึ้น CMS แล้ว!"