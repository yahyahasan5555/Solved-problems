// https://codeforces.com/problemset/problem/1106/D

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> res;

void bfs(int start) {
       // I wanna a min heap not max, so with multiply with -1 in push & pop
       priority_queue<int> q; 

       q.push(-start);
       vis[start] = true;

       while(!q.empty()) {
              int cur {-q.top()};
              q.pop();

              res.push_back(cur);
              for(int ch: adj[cur])
                     if(!vis[ch])
                            vis[ch] = true,
                            q.push(-ch);
       }
}

void testCase(void) {
       int n, m; cin >> n >> m;

       adj.resize(n+1), vis.resize(n+1);

       int u, v;
       while(m-- && cin >> u >> v)
              adj[u].push_back(v),
              adj[v].push_back(u);

       bfs(1);
       for(int i: res) cout << i << ' ';
       cout << endl;
}
       

signed main() {
       ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
       #ifndef ONLINE_JUDGE
              freopen("cpp.in", "rt", stdin);
       #endif

       testCase();
       return 0;
}