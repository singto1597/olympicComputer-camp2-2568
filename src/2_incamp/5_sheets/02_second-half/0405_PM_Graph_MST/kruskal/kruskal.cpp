#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include "dsu.h"
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main() {
  int V, E, u, v, w, mst_cost = 0;
  scanf("%d %d", &V, &E);

  vector<pair<int, ii> > EdgeList;

  for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &u, &v, &w);
    EdgeList.push_back(make_pair(w, ii(u, v)));
  }

  //implement Kruskal's algorithm for MST
  sort(EdgeList.begin(), EdgeList.end());

  DSU dsu(V);

  for (int i = 0; i < E; i++){
    // printf("%d ", EdgeList[i].first);
    if (!dsu.isSameSet(EdgeList[i].second.first, EdgeList[i].second.second)){
      mst_cost += EdgeList[i].first;
      dsu.unionSet(EdgeList[i].second.first, EdgeList[i].second.second);
    }
  }

  






  printf("MST cost = %d (Kruskal's)\n", mst_cost);
  return 0;
}