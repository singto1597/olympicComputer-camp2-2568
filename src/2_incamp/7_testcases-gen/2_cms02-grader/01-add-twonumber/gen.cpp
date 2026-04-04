#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    // 1. รับค่า Seed จาก Bash Script
    int seed = (argc > 1) ? atoi(argv[1]) : 1;
    
    // ใช้ mt19937_64 เพราะเราต้องการสุ่มเลขระดับ long long (64-bit)
    mt19937_64 rng(seed); 

    // 2. สุ่มค่า N (จำนวนบรรทัด) สมมติให้สุ่มตั้งแต่ 1 ถึง 100 บรรทัด
    uniform_int_distribution<int> distN(1, 100);
    int n = distN(rng);
    cout << n << "\n";

    // 3. สุ่มค่า a และ b (กำหนดขอบเขตตั้งแต่ 1 ถึง 4,000,000,000,000,000,000)
    // ใส่ LL ต่อท้ายตัวเลขด้วยนะ คอมจะได้รู้ว่าเป็น long long
    uniform_int_distribution<long long> distNum(-100000000LL, 1000000000LL);

    for (int i = 0; i < n; i++) {
        long long a = distNum(rng);
        long long b = distNum(rng);
        
        // พ่นข้อมูลออกมาเป็น input ให้ solution
        cout << a << " " << b << "\n";
    }

    return 0;
}