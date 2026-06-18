#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
/*
 * Any Graph (if separate graphs) Should be a complete graph.
 * That's meaning the if the n.of nodes, n.of edges = n * (n-1) / 2
 * this formula make sure that each node in any graph is connected directly with all nodes in the same graph.
 * So:
 */

Graph adj;
vector<bool> vis;
// will be long long becase will happen an overflow when use the formula.
ll nodes, edges;

// O(V + E)
void dfs(int i) {
       vis[i] = true;
       ++nodes;

       for(int ch: adj[i]) 
              if(!vis[ch])
                     dfs(ch);

       // But by this way each edge in this graph will be added twice
       // so will handel that below by get the sum edges over 2 (ed /= 2).
       edges += (int) adj[i].size();
}

void addEdge(int from, int to) {
       adj[from].push_back(to);
       adj[to].push_back(from);
}

void testCase(void) {
       int n, m; cin >> n >> m;
       adj.resize(n+1, {});
       vis.resize(n+1);

       int u, v;
       while(m-- && cin >> u && cin >> v)
              addEdge(u, v);

       for(int i {1}; i <= n; ++i) {
              if(!vis[i]) {
                     nodes = 0, edges = 0;
                     dfs(i);

                     edges /= 2; // each edge added twice.
                     if(edges != nodes * (nodes-1) / 2) 
                            return void (cout << "NO\n");
              }
       } cout << "YES\n";
}

int main () {        
       ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
       #ifndef ONLINE_JUDGE
              freopen("cpp.in", "rt", stdin);
       #endif

       testCase();
       return 0;
}