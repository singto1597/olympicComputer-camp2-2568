/*
 * Greedy Change-maker
 *  Assumption: coins are input in order from smaller coin to largest
 */
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n;  /* amount to make change for */
    int k;  /* number of coin types */
    int i;  /* for loops */
    int coinNum = 0;    /* number of coins used to make changes (answer) */

    scanf("%d", &n);
    scanf("%d", &k);

    int coin[k];    /* array of coins' amounts. coin[0] should be smallest */

    for(i = 0; i < k; i++){
        scanf("%d", &coin[i]);
    }

    /*-- DEBUG print coins' amounts --*/
    /*
    printf("\n");
    for(i = 0; i < k; i++){
        printf("%d\t", coin[i]);
    }
    printf("\n");
    */
    /*-- END DEBUG --*/

    /* Greedy Loop */
    i = k-1;    /* last coin */

    while(n > 0){
        if(n >= coin[i]){
            n = n - coin[i];
            coinNum++;
        } else {
            if(i == 0){       /* Can't make changes */
                printf("-1");
                exit(1);
            }
            else {
                i--;
            }
        }
    }
    printf("%d", coinNum);
}
