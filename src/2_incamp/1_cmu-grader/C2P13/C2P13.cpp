#include <bits/stdc++.h>

using namespace std;

int main(){ 
    map<string, int> wordCount;

    string word;

    while(cin >> word){
        string clean_word = "";

        for (char c : word) {

            if (isalnum(c)) { 

                clean_word += tolower(c); 
            }
        }

        if (!clean_word.empty()) {
            wordCount[clean_word]++;
        }
    }

    for (auto const& pair : wordCount) {
        cout << pair.first << " " << pair.second << "\n";
    }

}