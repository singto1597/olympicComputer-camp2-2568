#include <bits/stdc++.h>

using namespace std;

#define itemType int

struct Node{
    itemType data;
    Node *left;
    Node *right;

    Node(itemType val) : data(val), left(nullptr), right(nullptr) {}
};