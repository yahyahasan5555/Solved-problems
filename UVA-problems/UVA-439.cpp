// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=380
#include <bits/stdc++.h>

using namespace std;
using ll = long long;


vector<vector<int>> levels; 
vector<vector<bool>> vis;
int dx[] {-2, -1,  1,  2, 1, 2, -1, -2};
int dy[] {-1, -2, -2, -1, 2, 1,  2,  1};

bool valid(int x, int y) { // as 1-based index
       return x > 0 && x < 9 && y > 0 && y < 9;
}

void bfs(int start_x, int start_y) {
       queue<pair<int, int>> q;
       
       q.push({start_x, start_y});
       levels[start_x][start_y] = 0;
       vis[start_x][start_y] = true;

       while(!q.empty()) {
              int cur_x {q.front().first}, cur_y {q.front().second};
              q.pop();

              // it's neighbors are the 8 direction in dx, dy (above arrays):
              for(int i {}; i < 8; ++i) {
                     int x {cur_x + dx[i]}, y {cur_y + dy[i]};
                     if(valid(x, y) && !vis[x][y]) {
                            vis[x][y] = true;
                            levels[x][y] = levels[cur_x][cur_y] + 1;
                            q.push({x, y});
                     }
              }
       }
}

void testCase(void) {
       while(true) {   
              int dirs[4]; // (x1, y1), (x2, y2);
              for(int i {}; i < 4; ++i) {
                     char c;
                     if(!(cin >> c)) return;

                     if(i&1) dirs[i] = (c - '0');
                     else dirs[i] = (c - 'a')+1; // 1-based (char('a') - 'a' = 0) should add 1.
              }

              levels.assign(9, vector<int>(9, 0));
              vis.assign(9, vector<bool>(9, false));

              bfs(dirs[0], dirs[1]);
              printf("To get from %c%d to %c%d takes %d knight moves.\n", char(dirs[0]+'a'-1), dirs[1], char(dirs[2]+'a'-1), dirs[3], levels[dirs[2]][dirs[3]]);
       }
}

signed main () {        
       ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
       #ifndef ONLINE_JUDGE
              freopen("cpp.in", "rt", stdin);
       #endif
       
       
       testCase();
       return 0;
}
