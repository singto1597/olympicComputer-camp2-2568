#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AdjList;
set<int> taken;               
priority_queue<ii> pq;  


void process(int vtx) {
  //implement this
 







}  

int main() {
  int V, E, u, v, w;
  scanf("%d %d", &V, &E);
  AdjList.assign(V, vii());
  for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &u, &v, &w);   
          AdjList[u].push_back(ii(v, w));
    AdjList[v].push_back(ii(u, w));
  }

  process(0);   //เริ่มที่โหนด 0
  //implement this








    





  printf("MST cost = %d (Prim's)\n", mst_cost);
  return 0;
}

