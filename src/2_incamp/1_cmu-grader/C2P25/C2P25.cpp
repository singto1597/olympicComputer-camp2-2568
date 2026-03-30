#include <bits/stdc++.h>
#define itemType char
using namespace std;

vector<int> value;
struct Node{
    itemType data;
    Node *left;
    Node *right;

    Node(itemType val) : data(val), left(nullptr), right(nullptr) {}
};


int print_formation(Node* root){
    if(!root->left && root->right){
        return value[root->data - 'A'];
    }
    else{
        
    }
}


int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int number;
        cin >> number;
        value.push_back(number);
    }

    int question_number, choise;
    cin >> question_number, choise;


    for (int _ = 0; _ < question_number; _++){
        string problem;
        cin >> problem;

        vector<Node*> expArr;

        for(int i = 0; i < problem.size(); i++){
            Node *newNode = new Node(problem[i]);
            if(isalpha(problem[i])){
                expArr.push_back(newNode);
            }
            else{
                newNode->right = expArr.back();
                expArr.pop_back();
                newNode->left = expArr.back();
                expArr.pop_back();
                expArr.push_back(newNode);
            }
        }





    }
}