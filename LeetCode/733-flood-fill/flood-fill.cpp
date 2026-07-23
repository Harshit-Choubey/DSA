#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original_color = image[sr][sc];
        
        // If the new color is the same as the original, do nothing to avoid infinite loops
        if (original_color == color) {
            return image;
        }
        
        int m = image.size();
        int n = image[0].size();
        
        queue<pair<int, int>> q;
        
        q.push({sr, sc});
        image[sr][sc] = color;         
        
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            

            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;
                

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == original_color) {
                    image[nr][nc] = color; 
                    q.push({nr, nc});  
                }
            }
        }
        
        return image;
    }
};