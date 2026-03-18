#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // ตั้งค่าเริ่มต้นให้การสุ่ม
    
    int n = 20; // เปลี่ยนขนาดแถวตรงนี้
    int m = 20; // เปลี่ยนขนาดคอลัมน์ตรงนี้
    
    cout << n << " " << m << "\n";
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // บังคับให้จุดเริ่มต้น (1,1) และจุดจบ (n,m) เป็นทางเดินเสมอ
            if ((i == 1 && j == 1) || (i == n && j == m)) {
                cout << "1 ";
                continue;
            }
            
            // สุ่มทางเดิน (1) ให้มีโอกาสออก 70% และกำแพง (0) 30%
            // จะได้มีโอกาสเดินทะลุไปถึงฝั่งได้เยอะหน่อย
            int rand_val = rand() % 100;
            if (rand_val < 70) cout << "1 ";
            else cout << "0 ";
        }
        cout << "\n";
    }
    
    return 0;
}