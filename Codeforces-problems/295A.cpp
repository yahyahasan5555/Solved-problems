#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using GRAPH = vector<vector<int>>;


void testCase(void) {
       int n, op, q; cin >> n >> op >> q;

       vector<ll> vec(n+2);
       for(int i {1}; i <= n; ++i) 
              cin >> vec[i];

       vector<vector<int>> ops (op+2, vector<int>(6));
       for(int i {1}; i <= op; ++i)
              cin >> ops[i][1] >> ops[i][2] >> ops[i][3]; // from, to, cost                     
       
       int l, r;
       vector<int> partial_op(op+2);
       while(q-- && cin >> l >> r) 
              ++partial_op[l], --partial_op[r+1];

       // prefix sum on our parial operations array:
       for(int i {1}; i <= op; ++i)
              partial_op[i] += partial_op[i-1];
       
       vector<ll> diff(n+2);
       for(int i {1}; i <= op; ++i) {
              ll adds = 1LL * ops[i][3] * partial_op[i];
              
              diff[ops[i][1]] += adds, 
              diff[ops[i][2] + 1] -= adds;
       }

       for(int i {1}; i <= n; ++i) 
              diff[i] += diff[i-1];
       

       for(int i {1}; i <= n; ++i) 
             cout << vec[i]+diff[i] << ' ';
}

signed main() {
       ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
       #ifndef ONLINE_JUDGE
              freopen("cpp.in", "rt", stdin);
       #endif
       
       testCase();
       return 0;
}