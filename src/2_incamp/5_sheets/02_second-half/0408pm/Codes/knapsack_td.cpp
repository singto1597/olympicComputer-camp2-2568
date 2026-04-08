/* Knapsack Problem, Top-dowm DP, using Memoization (vector)
 * Input:
 *      n           :   number of items
 *      W           :   knapsack's weight limit
 *      v[1]..v[n]  :   item 1 to n's value
 *      w[1]..w[n]  :   item 1 to n's weights
 * Output:
 *      v_OPT       :   maximum combined values of objects with combined weights
 *                      not exceeding W
 *
 *  Note: in the code, we will use 0..n-1 instead of 1..n
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>


using namespace std;

// item of knapsack
struct ksItem{
    int v;  // value
    int w;  // weight
};

// compare knapsack items by weights
bool ksItemCompare(ksItem LHS, ksItem RHS){
    return LHS.w < RHS.w;
}

// Top-down DP, i is the ith (0..n-1) item being considered
// Assume objects cannot be divided
// DP structure P is passed by reference to retain the value
long knapsackTopDown(long w, vector<ksItem> itemArray, int i, vector<vector<long>> &P){
    long value = 0;
    // base case, first item
    if (i == 0){
        // no previous item to consider, either use, or return 0
        value = 0;
        if(w >= itemArray[i].w){
            value = itemArray[i].v; // no Repeat!
        }
    } else { // Recursive case
        
        // 1st case: don't use i-th item      
        if(P[i-1][w] == -1){ // check if the value has already been compute           
            value = knapsackTopDown(w, itemArray, i-1, P); // if not, compute for the first time
        }
        else value = P[i-1][w];

        // 2nd case: use i-th item (if possible)
        if(w >= itemArray[i].w){
            long newValue;
            if(P[i-1][w - itemArray[i].w] == -1){
                newValue = itemArray[i].v + knapsackTopDown(w - itemArray[i].w, itemArray, i-1, P);
            }
            else newValue = itemArray[i].v + P[i-1][w - itemArray[i].w];
            if(newValue > value){
                value = newValue;
            }
        }
    }  
    P[i][w] = value; // update DP Table
    return value;
}

int main(){
    long n, W;

    cin >> n >> W;  // Read in n, W

    // no item or weight
    if(n==0 || W == 0){
        cout << 0;
        exit(0);
    }

    //Read in items
    ksItem tempItem;
    vector<ksItem> itemArray;
    itemArray.clear();
    for(int i = 0; i < n; i++){
        cin >> tempItem.v >> tempItem.w;
        itemArray.push_back(tempItem);
    }

    // create 2-dimensional array P[0..n][0..W] for problem solving
    // P[i][j] = maximum values subproblem of weight limit j, using up to ith item
    vector<vector<long>> P;

    P.resize(n);

    // set P[][] to default value (-1)
    for(int i = 0; i < P.size(); i++){
        if(i < n)
            P[i].resize(W+1, -1);   // default values
        else
            P[i].resize(W+1, 0);    // sentinel, i goes over legal number of items
        P[i][0] = 0;
    }

    cout << knapsackTopDown(W, itemArray, n-1, P) << endl;

    // DEBUG, print out P
    /*for(int i = 0; i < P.size(); i++){
        cerr << i << ":\t";
        for(int j = 0; j < P[i].size(); j++){
            cerr << P[i][j] << " ";
        }
        cerr << endl;
    }*/

    return 0;
}
