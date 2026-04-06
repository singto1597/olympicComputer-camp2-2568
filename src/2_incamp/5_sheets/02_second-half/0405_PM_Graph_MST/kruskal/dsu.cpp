#include "dsu.h"

DSU::DSU(int n) {
    initSet(n);
}

void DSU::initSet(int n) {
    //implement constructor
    parent.assign(n,0);
    ranks.assign(n,0);

    for (int i = 0; i< n; i++){
        parent[i] = i;
    }



    
}

int DSU::findSet(int i) {
    //implement
    if (parent[i] == i) return i;
    parent[i] = findSet(parent[i]);
    return parent[i] ;




}

bool DSU::isSameSet(int i, int j) {
    //implement
    return findSet(i) == findSet(j);
}

void DSU::unionSet(int i, int j) {
    //implement union by rank

    int x = findSet(i);

    int y = findSet(j);
    if (x==y) return;

    if (ranks[x] > ranks[y]){
        parent[y] = x;
    }
    else{
            parent[x] = y;
            if (ranks[x] == ranks[y]){
                ranks[y]++;
            }


    }


}