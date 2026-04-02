#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

#define itemType long long

struct Node{
    itemType data;
    Node *left;
    Node *right;

    Node(itemType val) : data(val), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, itemType data){
    Node *p, *previous;
    p = root;

    if (!root){
        root = new Node(data);
        return root;
    }

    while (p != nullptr){
        previous = p;
        if (p -> data > data){
            p = p->left;
        }
        else if (p -> data < data){
            p = p->right;
        }
        else{
            return root;
        }
    }



    if (data < previous -> data){
        previous -> left = new Node(data);
    }
    else if (data > previous -> data){
        previous -> right = new Node(data);
    }

    return root;
}

void print_preOrder(Node *root){

    if (root){
        cout << root -> data << " ";
        print_preOrder(root ->left);
        print_preOrder(root ->right);
    }

    
}

void print_inOrder(Node *root){
    if (root){
        print_inOrder(root ->left);
        cout << root -> data << " ";
        print_inOrder(root ->right);
    }
}

void print_postOrder(Node *root){
    if (root){
        print_postOrder(root ->left);
        print_postOrder(root ->right);
        cout << root -> data << " ";
    }
}

void print_bfs(Node *root){
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    int depth = 0;

    while(!q.empty()){
        int level_size = q.size();
        
        cout << depth << ":";
        
        for(int i = 0; i < level_size; i++){
            Node* u = q.front();
            q.pop();

            cout << u->data << " ";

            if(u->left) q.push(u->left);
            if(u->right) q.push(u->right);
        }
        cout << "\n";
        depth++; 
    }

}


void print_leafs(Node *root){
    if (root){
        print_leafs(root ->left);
        print_leafs(root ->right);
        if (!root->left && !root->right){
            cout << root -> data << " ";
    
        }
    }

}


int main(){
    int n;
    cin >> n;
    Node *root = nullptr;
    for (long long i = 0; i < n; i ++){
        // int data;
        // cin >> data;
        root = insert(root, i);
        cout << i << " ";
    }
    // int oper;
    // cin >> oper;

    // for (int i = 0; i < oper; i ++){
    //     int c;
    //     cin >> c;
    //     switch(c){
    //         case 1:
    //             print_preOrder(root);
    //             break;

    //         case 2:
    //             print_inOrder(root);
    //             break;

    //         case 3:
    //             print_postOrder(root);
    //             break;

    //         case 4:
    //             print_bfs(root);
    //             continue;
    //         case 5:
    //             print_leafs(root);
    //             break;
    //     }
    //     cout << "\n";
    // }
}