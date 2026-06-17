#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<int>> GRAPH;

int n;
double d;
GRAPH adj;
vector<bool> vis;
vector<double> x, y;

void dfs(int i) {
       vis[i] = 1;
       for(int x: adj[i])
              if(!vis[x])
                     dfs(x);
}

void addEdge(int v, int u) {
       adj[u].push_back(v);
       adj[v].push_back(u);
}

void testCase(int t) {
       cin >> n >> d;
       
       adj.assign(n, {});
       vis.assign(n, false);
       x.assign(n, 0.0), y.assign(n, 0.0);

       for(int i {}; i < n; ++i) {
              cin >> x[i] >> y[i];
              
              // loop for revious nodes to check if there are any edges between:
              for(int j {i-1};  j >= 0; --j) {
                     // formula: distance between 2 points: sqrt((x1 - x2)^2 + (y1 - y2)^2).
                     double dis {(x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])};
                     if(dis <= d*d)
                            addEdge(i, j);
              }
       }

       // n.of disconnected nodes:
       int cnt {};
       for(int i {}; i < n; ++i)   
              if(!vis[i])
                     dfs(i), ++cnt;
       printf("Case %d: %d\n", t, cnt);
}

int main(void) {
       ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
       #ifndef ONLINE_JUDGE
              freopen("cpp.in", "rt", stdin);
       #endif

       int t; cin >> t;
       for(int t_case {1}; t_case <= t; ++t_case)
              testCase(t_case);

       return 0;
}