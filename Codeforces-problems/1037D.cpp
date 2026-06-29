// https://codeforces.com/problemset/problem/1037/D

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<int> res_order;
vector<bool> vis;

void bfs(int start) {
       queue<int> q;

       q.push(start);
       vis[start] = true;

       while(!q.empty()) {
              int cur {q.front()};
              res_order.push_back(cur);
              q.pop();

              for(int child: adj[cur]) 
                     if(!vis[child])
                            vis[child] = true,
                            q.push(child);
       }
}

//-------
vector<int> his_order, idx;

bool cmp(const int val1, const int  val2) {
       return idx[val1] < idx[val2];
}

void testCase(void) {
       int n; cin >> n;

       adj.resize(n+1);
       vis.resize(n+1);

       int edges {n-1}, u, v;
       while(edges-- && cin >> u >> v)
              adj[u].push_back(v),
              adj[v].push_back(u);

 
       his_order.resize(n+1);
       idx.resize(n+1);
       for(int i {1}; i <= n; ++i) cin >> his_order[i], idx[his_order[i]] = i;


       for(auto& vec: adj)
              sort(vec.begin(), vec.end(), cmp);

       res_order.push_back(0); // 1-based index and his_order begine with an empty cell (0)
       bfs(1);
       cout << (res_order == his_order ? "YES" : "NO") << '\n';
}
       

signed main() {
       ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
       #ifndef ONLINE_JUDGE
              freopen("cpp.in", "rt", stdin);
       #endif

       testCase();
       return 0;
}