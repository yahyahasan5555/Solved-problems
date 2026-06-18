#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MAX {500};

int n, m, k;
string matrix[MAX];
bool vis[MAX][MAX];

bool valid(int, int);

void dfs(int r, int c) {
       if(!k) return;
       vis[r][c] = true;

       int dx[] {1, -1, 0, 0};
       int dy[] {0, 0, -1, 1};
       for(int i {}; i < 4; ++i) {
              int x {r + dx[i]}, y {c + dy[i]};
              if(valid(x, y)) 
                     dfs(x, y);
       }

       if(k) matrix[r][c] = 'X', --k;
}

bool valid(int row, int col) {
       return row >= 0 && row < n && 
              col >= 0 && col < m && 
              !vis[row][col] && 
              matrix[row][col] != '#';
}

void testCase(void) {
       cin >> n >> m >> k;
       for(int i {}; i < n; ++i) 
              cin >> matrix[i];

       // Search for the first 'dot', for start dfs at it.
       bool found_dot {false};
       for(int row {}; row < n; ++row) {
              for(int col {}; col < m; ++col) {
                     if(matrix[row][col] == '.') {
                            dfs(row, col);

                            found_dot = true;
                            break;
                     }
              } if(found_dot) break;
       }

       for(int row {}; row < n; ++row) 
              cout << matrix[row] << '\n';
}

int main () {        
       ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
       #ifndef ONLINE_JUDGE
              freopen("cpp.in", "rt", stdin);
       #endif

       testCase();
       return 0;
}