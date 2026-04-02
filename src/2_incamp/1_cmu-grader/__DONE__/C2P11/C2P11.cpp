#include <bits/stdc++.h>

using namespace std;

typedef struct node { 
 
    int value; 
    struct node *next; 
 
} node_t; 

node_t *head = nullptr;

void insert_index(int index, int value){
    if (index < 0) {
        cout << "[" << index << ": " << value <<" not inserted]" << endl;
        return;
    }


    node_t *newNode = new node_t();
    newNode->next = nullptr;
    newNode->value = value;
    node_t *temp = head;
    if(!index){
        newNode->next = temp;
        head = newNode;
        return;
    }

    int current_index = 0;

    while(temp != nullptr && current_index < index - 1){
        temp = temp -> next;
        current_index++;
    }

    if (temp == nullptr){
        cout << "[" << index << ": " << value <<" not inserted]" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp-> next = newNode;

    
}

void delete_index(int index){
    node_t *temp = head;

    if (!head){
        cout << "[" << index << ": not deleted]" << endl;
        return;
    }

    if (index < 0) {
        cout << "[" << index << ": not deleted]" << endl;
        return;
    }

    if (index == 0){
        int value = head->value;
        head = head -> next;
        delete temp;
        cout << "[" << index << ": " << value << " deleted]" << endl;
        return;
    }

    int current_index = 0;

    while(temp != nullptr && current_index < index -1){
        temp = temp -> next;
        current_index++;
    }

    if (!temp || !temp->next){
        cout << "[" << index << ": not deleted]" << endl;
        return;
    }

    node_t *target = temp->next;
    int value = target->value;

    temp->next = target->next;

    delete target;
    cout << "[" << index << ": " << value << " deleted]" << endl;
    
    
}

void print_index(int index){
    node_t *temp = head;
    int current_index = 0;
    if (index < 0) { 
        cout << "[" << index << ": invalid index]" << endl;
        return;
    }
    while(temp && current_index < index){

        temp = temp -> next;
        current_index++;
    }
    if (!temp){
        cout << "[" << index << ": invalid index]" << endl;
    }
    else{
        cout << index << ": " << temp -> value;
        cout << endl;
    }
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
        int index, value;
        cin >> choise;
        switch(choise){
            case 'i':
                cin >> index >> value;
                insert_index(index, value);
                break;

            case 'd':
                cin >> index;
                delete_index(index);
                break;
            
            case 'v':
                cin >> index;
                print_index(index);
                break;

            case 'p':
                print_list();
                break;

        }



    }
}