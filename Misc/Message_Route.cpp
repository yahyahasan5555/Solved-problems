//https://cses.fi/problemset/task/1667
// BFS ALGO.

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> grapho;
vector<bool> vis;
vector<int> parent; // parent[i] --> the node that pusshed 'i'

void bfs(int i) {
       queue<int> cur_lvl;
       cur_lvl.push(i);

       vis[i] = true;
       parent[i] = -1;
       
       while(!cur_lvl.empty()) {
              int cur_node {cur_lvl.front()};
              cur_lvl.pop();

              for(auto neighbor: grapho[cur_node]) {
                     if(vis[neighbor]) continue;

                     cur_lvl.push(neighbor);
                     vis[neighbor] = true;
                     parent[neighbor] = cur_node;
              }
       }
}

void addEdge(int from, int to) {
       grapho[from].push_back(to);
       grapho[to].push_back(from);
}

void testCase(void) {
       cin >> n >> m;
       grapho.resize(n+1);
       vis.resize(n+1);
       parent.resize(n+1);

       int u, v; 
       while(m-- && cin >> u >> v)
              addEdge(u, v);

       bfs(1);

       if(!parent[n]) // disconnected
              return void(cout << "IMPOSSIBLE\n");

       stack<int> path_nodes;
       int i {n};
       while(i != -1) 
              path_nodes.push(i),
              i = parent[i];

       cout << path_nodes.size() << '\n';
       while(!path_nodes.empty())
              cout << path_nodes.top() << ' ', 
              path_nodes.pop();
       cout << endl;
}

int main () {        
       ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
       #ifndef ONLINE_JUDGE
              freopen("cpp.in", "rt", stdin);
       #endif

       testCase();
       return 0;
}