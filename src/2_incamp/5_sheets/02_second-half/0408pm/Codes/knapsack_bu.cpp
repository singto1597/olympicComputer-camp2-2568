/* Knapsack Problem, Bottom-up DP
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
    int w;  // weight
    int v;  // value
};

// compare knapsack items by weights
bool ksItemCompare(ksItem LHS, ksItem RHS){
    return LHS.w < RHS.w;
}

int main()
{
    int W, n;

    time_t t_start, t_end;

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

    // sort item (not really necessary for DP)
    // sort(itemArray.begin(), itemArray.end(), ksItemCompare);

    // create 2-dimensional array P[0..n-1][0..W] for problem solving
    // P[i][j] = maximum values subproblem of weight limit j, using up to ith item
    int P[n][W+1];
    // perform bottom up dynamic programing
    for(int i = 0; i < n; i++){
		for(int j = 0; j <= W; j++){
			if(j == 0){ // Base case 1: no weight left
				P[i][j] = 0;
			} else {                   
				if(i == 0){ // Base case 2: first item
					if(itemArray[i].w > j){                          
						P[i][j] = 0;	// can't fit
					} else { P[i][j] = itemArray[i].v; }
				} else {
					if(itemArray[i].w > j){        
						P[i][j] = P[i-1][j]; // can't fit
					} else {
						// max between use or not use
						P[i][j] = max(itemArray[i].v + P[i-1][j-itemArray[i].w]
									,P[i-1][j]);
					}
				}
			}
		}
    }
    cout << P[n-1][W] << endl;	 // Answer

    // DEBUG, print out P
    /*for(int i = 0; i < n; i++){
        cerr << i << ":\t";
        for(int j = 0; j <= W; j++){
            cerr << P[i][j] << " ";
        }
        cerr << endl;
    }*/
}
