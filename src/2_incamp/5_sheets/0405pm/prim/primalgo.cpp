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
 
  taken.insert(vtx);

  for (int i = 0; i < (int)AdjList[vtx].size(); i++){
    if (taken.count(AdjList[vtx][i].first) == 0){
      pq.push(ii(-AdjList[vtx][i].second, -AdjList[vtx][i].first));
    }
  }



}  

int main() {
  int V, E, u, v, w;
  scanf("%d %d", &V, &E);
  AdjList.assign(V, vii());
  for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &u, &v, &w);   
    AdjList[u].push_back(ii(v, w));
    AdjList[v].push_back(ii(u, w));
    // AdjList[u].push_back(ii(v, w));
  }

  process(0);   //เริ่มที่โหนด 0
  //implement this
  int mst_cost = 0;

  while(!pq.empty() && (int)taken.size() < V){
    ii currnt_weight_node = pq.top();
    pq.pop();
    if (taken.count(-currnt_weight_node.second) == 0){
      mst_cost+= (-currnt_weight_node.first);
      process(-currnt_weight_node.second);
    }
  }







    





  printf("MST cost = %d (Prim's)\n", mst_cost);
  return 0;
}

