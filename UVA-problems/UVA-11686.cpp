
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<int> in_degree;
vector<bool> vis;
vector<int> sorted;
int n, m;

// TOPO-SORT
void bfs() {
       queue<int> q;
       for(int i {1}; i <= n; ++i) 
              if(!in_degree[i])
                     q.push(i), vis[i] = true;
       
       while(!q.empty()) {
              int cur {q.front()};
              q.pop();

              sorted.push_back(cur);
              for(int neighbor: adj[cur]) {
                     --in_degree[neighbor];

                     if(!in_degree[neighbor])
                            q.push(neighbor), vis[neighbor] = true;
              }
       }
}

void testCase(void) {
       while(cin >> n >> m && n) {   
              adj.assign(n+1, {});
              vis.assign(n+1, false);
              in_degree.assign(n+1, 0);

              int from, to;
              while(m-- && cin >> from >> to)
                     adj[from].push_back(to), 
                     ++in_degree[to];

              bfs();
              if((int)sorted.size() < n)
                     return void(cout << "IMPOSSIBLE\n");

              for(int x: sorted) cout << x << '\n';
       }
}

signed main () {        
       ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
       #ifndef ONLINE_JUDGE
              freopen("cpp.in", "rt", stdin);
       #endif
       
       
       testCase();
       return 0;
}