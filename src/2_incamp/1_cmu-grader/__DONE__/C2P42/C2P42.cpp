#include <bits/stdc++.h>

using namespace std;

int main(){
    int A, B, C;

    cin >> A >> B >> C;

    // bool isFound = false;

    for(int x = -100; x <= 100; x++){
        for(int y = -100; y <= 100; y++){
            int z = A - (x + y);
            if (x != y && y != z && z != x){
                if (x * y * z == B && x*x + y*y + z*z == C ) {
                    cout << x << " " << y << " " << z << "\n";
                    return 0;

                }

            }
        }
    }

    cout << "No solution." << endl;
    return 0;
}