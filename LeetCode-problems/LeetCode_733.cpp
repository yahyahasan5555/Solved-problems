// https://leetcode.com/problems/flood-fill/

#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> GRAPH;

class Solution {
private:
	vector<int> dx {-1, 1, 0, 0}, dy {0, 0, 1, -1};
       int original_color {-1};
public:
	vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int color) {
              setOriginalColor(image[sr][sc]);
		dfs(sr, sc, color, image);

              return image;
	}

	void dfs(int r, int c, int color, GRAPH& img) {
		if(!valid(r, c, color, img))
			return;
                     
		img[r][c] = color;
              // Jump to 4 neighbours:
		for(int i {}; i < 4; ++i)
			dfs(r+dx[i], c+dy[i], color, img);
	}

	bool valid(int i, int j, int color, GRAPH& img) {
		return i >= 0 && j >= 0 && 
                     // there is no need to check wether there is a columns or no,
		       // because it's guranteed that m(n.of cols) >= 1.
			i < int(img.size()) && j < int(img.front().size()) && 
			img[i][j] != color && 
                     img[i][j] == original_color;
	}

       void setOriginalColor(int new_color) {
              this->original_color = new_color;
       }
};

int main() {
       vector<vector<int>> img {{1,1,1},{1,1,0},{1,0,1}};
       img = Solution().floodFill(img, 1, 1, 2);
       for(auto& vec: img) {
              for(int x: vec) cout << x << ' ';
              cout << '\n';
       }

       return 0;
}
