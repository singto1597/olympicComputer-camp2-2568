#include <bits/stdc++.h>

using namespace std;

typedef struct node { 
 
    int value; 
    struct node *next; 
 
} node_t; 

node_t *head = nullptr;

void insert_order(int value){
    node_t *newNode = new node_t();
    newNode->next = nullptr;
    newNode->value = value;
    node_t *temp = head;
    if(!temp || value < temp -> value){
        newNode->next = temp;
        head = newNode;
        return;
    }
    while(temp -> next && temp -> next -> value < value){
        temp = temp -> next;
    }

    newNode->next = temp->next;
    temp-> next = newNode;

    
}

void delete_value(int value){
    node_t *temp = head;

    if (!head){
        cout << value << " [not deleted]" << endl;
        return;
    }
    else{
        if (head -> value == value){
            node_t *target = head;
            head = head -> next;
            delete target;
            cout << value << " [deleted]" << endl;
            return;
        }
    }

    while(temp -> next && temp -> next -> value < value ){
        temp = temp -> next;
    }

    
    if (!temp -> next){
        cout << value << " [not deleted]" << endl;
        return;
    }
    else if (temp -> next -> value != value ){
        cout << value << " [not deleted]" << endl;
        return;
    }
    else{
        node_t *target = temp -> next;
        temp -> next = temp -> next -> next;
        delete target;
    }
    
    cout << value << " [deleted]" << endl;
}

void print_list(){
    node_t *temp = head;

    while(temp){
        cout << temp -> value << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;


    for (int i = 0; i < n; i ++){
        char choise;
        int value;
        cin >> choise;
        switch(choise){
            case 'i':
                cin >> value;
                insert_order(value);
                break;

            case 'd':
                cin >> value;
                delete_value(value);
                break;

            case 'p':
                print_list();
                break;

        }



    }
}