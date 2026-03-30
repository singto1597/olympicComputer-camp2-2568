    #include <bits/stdc++.h>
    #define itemType char
    using namespace std;

    vector<double> value;
    struct Node{
        itemType data;
        Node *left;
        Node *right;

        Node(itemType val) : data(val), left(nullptr), right(nullptr) {}
    };


    void print_formation(Node* root){
        if (!root) return;
        if(!root->left && !root->right){
            cout << value[toupper(root->data) - 'A'];
        }
        else{
            cout << "(";
            print_formation(root->left);
            cout << root->data ;
            print_formation(root->right);
            cout << ")";
        }
    }

    double calculate_result(Node* root){
        if (!root) return 0;
        if(!root->left && !root->right){
            return value[toupper(root->data) - 'A'];
        }

        double left_node = calculate_result(root->left);
        double right_node = calculate_result(root->right);

        switch(root->data){
            case '+':
                return left_node + right_node;
                break;

            case '-':
                return left_node - right_node;
                break;

            case '*':
                return left_node * right_node;
                break;

            case '/':
                return left_node / right_node;
                break;

            case '^':
                return pow(left_node, right_node);
                break;
        }

        return 0;

    }

    int main(){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            double number;
            cin >> number;
            value.push_back(number);
        }

        int question_number, choise;
        cin >> question_number >> choise;


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

            switch (choise){
                case 0: print_formation(expArr[0]); break;
                case 1:
                    double ans = calculate_result(expArr[0]);
                    // ถ้าค่าน้อยมากๆ เข้าใกล้ 0 ให้จับเท่ากับ 0 ไปเลย เพื่อกัน -0.00
                    if (fabs(ans) < 1e-9) ans = 0.0; 
                    printf("%.2lf", ans);
                    break;

            }
            
            cout << endl;

        }
        return 0;
    }