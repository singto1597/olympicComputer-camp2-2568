/* 2026 Computer Olympic, Camp 02
 * 1/0 Knapsack Problem, example code
 * Input:
 *      n           :   number of items
 *      W           :   knapsack's weight limit
 * Then followed by n line for each object
 *      v  :   item's value
 *      w  :   item's weight
 * Output:
 *      v_OPT       :   maximum combined values of objects with combined weights
 *                      not exceeding W
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
// item of knapsack
struct ksItem{
    int v;  // value
    int w;  // weight
    double vPerW;   // value/weight ratio
};

// compare knapsack items by weights
bool ksItemCompare(ksItem LHS, ksItem RHS){
    return LHS.vPerW > RHS.vPerW;
}

// Greedy version
double knapsackGreedy(int W, vector<ksItem> itemArray){

    int i = 0;
    double totalV = 0.0;  // total value in knapsack
    while(W > 0 && i < itemArray.size()){
        // Can fit ith item
        if(W >= itemArray[i].w){
            totalV += itemArray[i].v;
            W -= itemArray[i].w;
        } 
        /* (for divisible) else {
            // cannot fit whole item, fir fraction instead
            totalV += itemArray[i].v * ((double)W/itemArray[i].w);
            W = 0;
        }*/
        i++;
    }

    return totalV;
}

// Enumerate all possible answers, using itemArray.size()-bit binary to represent choice
double knapsackEnumerate(int W, vector<ksItem> itemArray){
    vector<bool> choice; // choice[0] is using itemArray[0] or not, and so on
    choice.resize(itemArray.size());

    int nLoop = exp2(itemArray.size()); // number of choices is 2^itemArray.size()
    int totalW = 0;
    int totalV = 0;
    int maxV = 0; // contain answers
    int tempC;
    // run from 0 (000...000 - using nothing) -> 000.001 -> 111...111 using - everything
    for(int c = 0; c < nLoop; c++){
        totalW = 0;
        totalV = 0;

        tempC = c;
        // convert c into choices
        for(int i = 0; i < itemArray.size(); i++){  
            choice[i] = (tempC % 2 == 1); // true if using that item
            tempC = tempC / 2;

        }

        // calculate total weight, values
        for(int i = 0; i < itemArray.size(); i++){
            if(choice[i]){
                totalW += itemArray[i].w;
                totalV += itemArray[i].v;
            }
        }

        // if value is better AND the weight limit is not exceeded, update maxV
        if (totalW <= W && totalV > maxV){
            maxV = totalV;
        }
    }

    return maxV;
    
}

// Exhaustive version, i is the ith (0..n-1) item being considered
// Assume objects cannot be divided
double knapsackRecursive(int W, vector<ksItem> itemArray, int i){
    double value = 0.0;

    // DEBUG
    cerr << "knapsack(" << W << ", " << i << ")\n";

    if(W==0 || i >= itemArray.size()) {
        return 0;
    }   else {
        // 1st case: don't use ith item
        value = knapsackRecursive(W, itemArray, i+1);

        // 2nd case: use (if possible)
        if(W >= itemArray[i].w){
            double newValue = itemArray[i].v
                + knapsackRecursive(W - itemArray[i].w, itemArray, i+1);
            if(newValue > value){
                value = newValue;
            }
        }
    }
    return value;
}

int main(){
    int n, W;

    cin >> n >> W;  // Read in n, W

    // no item or weight
    if(n==0 || W == 0){
        cout << 0;
        return 0;
    }

    //Read in items
    ksItem tempItem;
    vector<ksItem> itemArray;
    itemArray.clear();
    for(int i = 0; i < n; i++){
        cin >> tempItem.v >> tempItem.w;
        tempItem.vPerW = (double)tempItem.v/tempItem.w;
        itemArray.push_back(tempItem);
    }

    

    // DEBUG, check if order is correct
    /*for(int i = 0; i < n; i++){
        cout << itemArray[i].v << "," << itemArray[i].w << ",";
        cout << itemArray[i].vPerW << endl;
    }*/
    double ans;
    // Greedy
    // sort item (for greedy)
    sort(itemArray.begin(), itemArray.end(), ksItemCompare);
    ans = knapsackGreedy(W, itemArray);
    cout << "Greedy - " << ans << endl;

    // Exhaustive (Enumerate)
    ans = knapsackEnumerate(W, itemArray);
    cout << "Enumerate - " << ans << endl;

    // Exhaustive (Recursive)
    ans = knapsackRecursive(W, itemArray,0);
    cout << "Recursive - " << ans << endl;

    return 0;
}
