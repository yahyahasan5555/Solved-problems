#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<int>> GRAPH;

/*
 * there are some pairs of students want to be in the same group,
 * but the group's size should be of three students, 
 * and also there are students can be in any group,
 * so: if the number of connected components greater that 3 --> can't split them --> -1.
 * else: if there is an individual student doesn't have any group, can add it, and so on:
 * SOOOOOO:
 */

int n, m;
GRAPH adj;
vector<bool> vis;

// will returns the n.of linked edges: (size of the group)
void dfs(int i, vector<int>& tmp) {
       vis[i] = true;
       tmp.push_back(i); // current student.

       for(int x: adj[i])
              if(!vis[x])
                     dfs(x, tmp);
}

void addEdge(int u, int v) {
       adj[u].push_back(v);
       adj[v].push_back(u);
}

void testCase(void) {
       int n, m; cin >> n >> m;
       
       adj.assign(n+1, {});
       vis.assign(n+1, false);

       int u,v;
       while(m-- && cin >> u && cin >> v)
              addEdge(u, v);

       vector<int> ones; // for individual students.
       vector<vector<int>> groups;

       // I can use the first index in the visited vector instead of this,
       // but for prevent confusing:
       bool good = true;
       for(int st {1}; st <= n; ++st) {
              if(!vis[st]) {
                     vector<int> tmp;
                     dfs(st, tmp);

                     int sz {(int)tmp.size()};
                     if(sz ==  1) // just one/individual student
                            ones.push_back(st);
                     else if(sz > 3) {
                            good = not good;
                            break;
                     } else groups.push_back(tmp);
              }      
       }      

       if(not good)
              return void(cout << "-1\n");
       // Else:
       // we will use 'good' var again:
       for(auto& vec: groups) {
              if((int)vec.size() < 3) {
                     while(vec.size() != 3 && !ones.empty()) {
                            vec.push_back(ones.back()); ones.pop_back();}

                     if((int) vec.size() < 3) {
                            good = false;
                            break;
                     }
              }      
       }

       if(not good || (int)ones.size()%3 != 0) 
              return void(cout << "-1\n");

       for(auto& vec: groups) {
              for(int st: vec) 
                     cout << st << ' ';
              cout << '\n';
       }

       for(int i {1}; i <= (int)ones.size(); ++i)
              cout << ones[i-1] << (i%3==0?'\n':' ');
}


int main(void) {
       ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
       #ifndef ONLINE_JUDGE
              freopen("cpp.in", "rt", stdin);
       #endif

       testCase();
       return 0;
}



/*
 * I can making three vectors --> for ones, twos, threes, 
 * if there is a size greater than three then -1.
 * if number of twos > number of ones then -1
 * if number of ones after fill twos vector % 3 != 0 then -1
 * else print groups.
 */