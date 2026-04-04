#include <bits/stdc++.h>
using namespace std;

int main() {
    // ปรับให้ I/O เร็วปรู๊ดปร๊าด
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        long long a, b;
        cin >> a >> b;
        // ปริ้นผลบวก
        cout << a + b << "\n";
    }

    return 0;
}