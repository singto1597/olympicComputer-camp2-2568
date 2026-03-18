#include <iostream>
using namespace std;

int direction = 0;
int currentIndexX = 1;
int currentIndexY = 1;
/*
          Forward
             0


Left 270          90 Right


            180
          Backward

*/

int number[120][120] = {0};
bool isVisited[120][120] = {0};

void turnLeft(){
    direction = direction - 90;
    if (direction == -90) direction = 270;
}
void turnRight(){
    direction = direction + 90;
    if (direction == 360) direction = 0;
}

void forWard(){
    switch (direction){
    case 0:
        currentIndexY += 1;
        break;
    case 90:
        currentIndexX -= 1;
        break;
    case 180:
        currentIndexY -= 1;
        break;
    case 270:
        currentIndexX += 1;
        break;
    default:
        break;
    }
}

void backWard(){
    switch (direction){
    case 0:
        currentIndexY -= 1;
        break;
    case 90:
        currentIndexX += 1;
        break;
    case 180:
        currentIndexY += 1;
        break;
    case 270:
        currentIndexX -= 1;
        break;
    default:
        break;
    }
}


int checkForWard(int directionForCheck){
    switch (directionForCheck){
    case 0:
        return number[currentIndexY + 1][currentIndexX];
        break;
    case 90:
        return number[currentIndexY][currentIndexX - 1];
        break;
    case 180:
        return number[currentIndexY - 1][currentIndexX];
        break;
    case 270:
        return number[currentIndexY][currentIndexX + 1];
        break;
    default:
        return -1;
        break;
    }
}

int checkBackWard(int directionForCheck){
    switch (directionForCheck){
    case 0:
        return number[currentIndexY - 1][currentIndexX];
        break;
    case 90:
        return number[currentIndexY][currentIndexX + 1];
        break;
    case 180:
        return number[currentIndexY + 1][currentIndexX];
        break;
    case 270:
        return number[currentIndexY][currentIndexX - 1];
        break;
    default:
        return -1;
        break;
    }
}


int checkLeft(){
    int directionForCheck = direction - 90;
    if (directionForCheck == -90) directionForCheck = 270;
    return checkForWard(directionForCheck);
}

int checkRight(){
    int directionForCheck = direction + 90;
    if (directionForCheck == 360) directionForCheck = 0;
    return checkForWard(directionForCheck);
}


int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n ; i++){
        for (int j = 1; j <= m; j++){
            cin >> number[i][j];
            
        }
    }
    if (number[1][1] == 0){
        cout << "NO" << endl;
        return 0;
    }
    int step_counter = 0;
    int max_steps = n * m;

    bool found_path = false;

    // ทำ loop 2 รอบ สำหรับการลอง 2 วิธี (ซ้ายก่อน / ขวาก่อน)
    for (int attempt = 0; attempt < 2; ++attempt) {
        
        // รีเซ็ตทุกอย่าง
        currentIndexX = 1;
        currentIndexY = 1;
        direction = 0; // ตั้งทิศเริ่มต้น
        
        step_counter = 0;
        max_steps = n * m * 2;

        while (true){
            step_counter++;
            if (step_counter > max_steps) {
                break; 
            }

            // เลือกใช้กฎตามรอบที่ลอง
            if (attempt == 0) {
                // รอบแรก: กฎมือซ้าย
                if (checkLeft() == 1) {
                    turnLeft();
                    forWard();
                } else if (checkForWard(direction) == 1) {
                    forWard();
                } else if (checkRight() == 1) {
                    turnRight();
                    forWard();
                } else {
                    turnRight();
                    turnRight();
                    forWard();
                }
            } else {
                // รอบสอง: กฎมือขวา (สลับ checkRight กับ checkLeft)
                if (checkRight() == 1) {
                    turnRight();
                    forWard();
                } else if (checkForWard(direction) == 1) {
                    forWard();
                } else if (checkLeft() == 1) {
                    turnLeft();
                    forWard();
                } else {
                    turnLeft();
                    turnLeft();
                    forWard();
                }
            }
            
            if (currentIndexY == n && currentIndexX == m) {
                found_path = true;
                break;
            }
        }

        if (found_path) {
            break; // ถ้าเจอทางแล้ว ก็ไม่ต้องลองรอบที่สอง
        }
    }

    if (found_path){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
