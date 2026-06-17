#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<int>> GRAPH;

/* 
 * 1- SHOULD BY ONE COMPONENT SO WILL HANDLE WITH THAT.
 * 2- SHOULD BE N.OF NODES = N.OF EDGES (SIMPLE CYCLY --> by added only one edge to any tree, will be cycle).
 * 3 SHOULD BE CYCLE (once edges = nodes, and one component, it's guranteed that there is a cycle, so there is no need to detect).
 */

GRAPH adj;
vector<bool> vis;

void dfs(int i) {
       vis[i] = true;
       for(int ch: adj[i]) 
              if(!vis[ch]) dfs(ch);
}

// Just undirected, in this problem.
void addEdge(int from, int to) {
       adj[from].push_back(to);
       adj[to].push_back(from);
}

void testCase(void) {
       int n, m; cin >> n >> m;

       if(n != m) // check is a cycle can occures?
              return void(cout << "NO\n");

       adj.assign(n+5, {}); vis.assign(n+5, false);

       int u, v;
       while(m-- && cin >> u && cin >> v)
              addEdge(u, v);

       // number of connected components - Should be only one.
       int groups {};
       for(int i {1}; i <= n; ++i) 
              if(!vis[i])
                     dfs(i), ++groups;

       if(groups > 1) cout << "NO\n";

       // connected + (n = m) = cycled (simple one).
       else cout << "FHTAGN!\n";
}

int main(void) {
       ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

       testCase();
       return 0;
}
