/*
 * Recursive Brute-force Change-maker
 *  Assumption: coins are input in order from smaller coin to largest
 */
#include <stdio.h>
#include <stdlib.h>

/* make change for j up to ith coin (from 0th */
int makeChange(int i, int j, int *coin)
{
    // printf("Call makeChange(%d, %d)\n", i, j);

    if(j == 0) return 0;
    /* smallest coin */
    else if(i == 0) {
        if (j < coin[i]){
            /* dead end */
            return -1;
        } else {
            int a = makeChange(i, j - coin[i], coin);

            if(a == -1) return -1;
            else return 1 + makeChange(i, j - coin[i], coin);
        }
    }
    else if(j < coin[i]){
        /* can't use current coin */
        return makeChange(i-1, j, coin);

    } else {
        /* first choice, not using current coin */
        int a = makeChange(i-1, j, coin);

        /* second choice, using one current coin*/
        int b = makeChange(i, j-coin[i], coin);
        if(a == -1){
            if (b == -1){
                // can't use either choice
                return -1;
            } else {
                // can't use a
                return 1 + b;
            }
        } else {
            if (b == -1){
                // can't use b
                return a;
            } else {
                // can use either a or b
                if(a < 1 + b) return a;
                else return 1 + b;
            }
        }
    }
}


int main()
{
    int n;  /* amount to make change for */
    int k;  /* number of coin types */
    int i,j;  /* for loops */
    int coinNum = 0;    /* number of coins used to make changes (answer) */

    scanf("%d", &n);
    scanf("%d", &k);

    int coin[k];    /* array of coins' amounts. coin[0] should be smallest */

    for(i = 0; i < k; i++){
        scanf("%d", &coin[i]);
    }

    printf("%d", makeChange(k-1, n, coin));

    return 0;
}
