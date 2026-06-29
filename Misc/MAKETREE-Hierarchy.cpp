//https://www.spoj.com/problems/MAKETREE/en/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<int> indegree;
vector<int> topo;

void bfs(int start) {
       queue<int> q;
       
       q.push(start);
       topo.push_back(0); // for get parent of the boss (parent of node = previous node in topo)

       while(!q.empty()) {
              int cur {q.front()};
              q.pop();
              topo.push_back(cur);

              for(int neighbor: adj[cur]) 
                     if(--indegree[neighbor] == 0) 
                            q.push(neighbor);
       }
}

void testCase(void) {
       int n, k; cin >> n >> k;

       adj.resize(n+1);
       indegree.resize(n+1);

       for(int i {1}; i <= k; ++i) {
              int num, u; cin >> num;

              while(num-- && cin >> u)
                     adj[i].push_back(u),
                     ++indegree[u];
       }

       // get the boss, and make it superior on other superiors.
       int boss {};
       for(int i {1}; i <= n; ++i)
              if(!indegree[i] && !boss)
                     boss = i;
              else if(!indegree[i])       
                     adj[boss].push_back(i),
                     ++indegree[i];

       bfs(boss);

       /* ------------------------------------------------------
        * parent of a node is it's previous node in 'topo' array
        * for that we start the 'topo' with 0 (parent of boss = 0)
        */
       vector<int> parent(n+1);
       for(int i {1}; i <= n; ++i)
              parent[topo[i]] = topo[i-1];

       for(int i {1}; i <= n; ++i)
              cout << parent[i] << '\n';
}
       
       

signed main() {
       ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
       #ifndef ONLINE_JUDGE
              freopen("cpp.in", "rt", stdin);
       #endif

       testCase();
       return 0;
}