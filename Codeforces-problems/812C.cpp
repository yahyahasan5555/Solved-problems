// https://codeforces.com/problemset/problem/812/c
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

int n, cost;
vector<int> vec;

int calc_cost(int idx, int k) {
       return vec[idx] + idx * k;
}

// returns -1 if can't collect 'k' numbers.
// else: returns the sum of min k vals.
int can(int k) {
       vector<int> tmp(vec); // Use Copy Constructor
       for(int i {1}; i <= n; ++i)
              tmp[i] = calc_cost(i, k);

       sort(tmp.begin(), tmp.end());

       int t_cost {};
       for(int i {1}; i <= k; ++i)
              if(t_cost + tmp[i] <= cost) t_cost += tmp[i];
              else return -1; 

       return t_cost;
}

void testCase(void) {
       cin >> n >> cost;
       vec.resize(n+1);
       for(int i {1}; i <= n; ++i) cin >> vec[i];

       int l {1}, r {n}, ans {-1}, mid;
       while(l <= r) {
              mid = l + (r-l)/2;

              if(can(mid) != -1)
                     ans = mid, l = mid + 1;
              else r = mid - 1;
       }

       if(ans == -1) return void(cout << "0 0\n");
       else printf("%lld %lld\n", ans, can(ans));
}


signed main() {
       ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
       #ifndef ONLINE_JUDGE
              freopen("cpp.in", "rt", stdin);
       #endif

       // int t; cin >> t; while(t--)
       testCase();
       return 0;
}
