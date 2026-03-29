#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie();
    int booth_number, people_number;
    cin >> booth_number >> people_number;

    int booth_minimum[booth_number] = {};
    int people_offer[people_number] = {};

    for (int i = 0; i < booth_number; i++){
        cin >> booth_minimum[i];
    }
    for (int i = 0; i < people_number; i++){
        cin >> people_offer[i];
    }

    sort(booth_minimum, booth_minimum + booth_number);
    sort(people_offer, people_offer + people_number);

    reverse(booth_minimum, booth_minimum + booth_number);
    reverse(people_offer, people_offer + people_number);

    int answer = 0;

    for (int i = 0; i < booth_number; i++){
        bool isCanOffer = false;
        for (int j = 0; j < people_number; j++){
            if (people_offer[j] > booth_minimum[i] && booth_minimum[i] != -1){
                answer += people_offer[j];
                people_offer[j] = -1;
                isCanOffer = true;
                break;
            }
        }
        if(isCanOffer == false){
            booth_minimum[i] = -1;
        }
    }
    cout << answer << endl;
}