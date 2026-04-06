#ifndef DSU_H
#define DSU_H

#include <vector>

class DSU {
private:
    std::vector<int> parent;
    std::vector<int> ranks;

public:
    DSU(int n);
    void initSet(int n);
    int findSet(int i);
    bool isSameSet(int i, int j);
    void unionSet(int i, int j);
};

#endif