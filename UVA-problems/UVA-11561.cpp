#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//  I can pass them by refrence, but this is easy/
int rows, cols;
vector<vector<char>> arr;
vector<vector<bool>> vis;

int dx[] {-1, 1, 0, 0};
int dy[] {0, 0, 1, -1};

bool valid(int x, int y) {
       return x >= 0 && y >= 0 && x < rows && y < cols;
}

bool safe(int x, int y) {
       // It's guranteed that [x][y] valid.
       if(arr[x][y] == 'T') return false;

       for(int i {}; i < 4; ++i)
              if(valid(dx[i]+x, dy[i]+y) && arr[dx[i]+x][dy[i]+y] == 'T')
                     return false;

       return true;
}

int get_gold(int x, int y) {
       vis[x][y] = true;
       int cnt {};
       if(arr[x][y] == 'G') ++cnt;

       if(!safe(x, y)) return cnt;

       for(int i {}; i < 4; ++i)
              if(valid(dx[i]+x, dy[i]+y) && !vis[dx[i]+x][dy[i]+y] && arr[dx[i]+x][dy[i]+y] != '#')
                     cnt += get_gold(dx[i]+x, dy[i]+y);
       return cnt;
}

bool testCase() {
       if(!(cin >> cols && cin >> rows)) return false;
       arr.assign(rows, vector<char>(cols));
       vis.assign(rows, vector<bool>(cols, false));
 
       int px, py;
       for(int r {}; r < rows; ++r) {
              for(int c {}; c < cols; ++c) {
                     cin >> arr[r][c];
                     if(arr[r][c] == 'P') px = r, py = c;
              }
       }
       
       cout << get_gold(px, py) << '\n';
       return true;
}

int main () {        
       ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
       #ifndef ONLINE_JUDGE
              freopen("cpp.in", "rt", stdin);
       #endif

       while(testCase());
       return 0;
}
