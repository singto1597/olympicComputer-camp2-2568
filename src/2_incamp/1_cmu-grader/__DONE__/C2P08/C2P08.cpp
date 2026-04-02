#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

int main(){
    map<char,int> map_values;
    map_values['3'] = 1;
    map_values['4'] = 2;
    map_values['5'] = 3;
    map_values['6'] = 4;
    map_values['7'] = 5;
    map_values['8'] = 6;
    map_values['9'] = 7;
    map_values['T'] = 8;
    map_values['J'] = 9;
    map_values['Q'] = 10;
    map_values['K'] = 11;
    map_values['A'] = 12;
    map_values['2'] = 13;

    map_values['C'] = 20;
    map_values['D'] = 21;
    map_values['H'] = 22;
    map_values['S'] = 23;

    map<int,char> map_char;
    map_char[1] = '3';
    map_char[2] = '4';
    map_char[3] = '5';
    map_char[4] = '6';
    map_char[5] = '7';
    map_char[6] = '8';
    map_char[7] = '9';
    map_char[8] = 'T';
    map_char[9] = 'J';
    map_char[10] = 'Q';
    map_char[11] = 'K';
    map_char[12] = 'A';
    map_char[13] = '2';

    map_char[20] = 'C';
    map_char[21] = 'D';
    map_char[22] = 'H';
    map_char[23] = 'S';

    int n;
    cin >> n;

    pair<int,int> value[n];

    for (int i = 0; i < n; i++){
        char card_value;
        char card_type;
        cin >> card_value >> card_type;
        value[i] = {map_values[card_value], map_values[card_type]};
    }

    sort(value, value + n);

    for (int i = 0; i < n; i++){
        cout << map_char[value[i].f] << " " << map_char[value[i].s] << endl;
    }

}