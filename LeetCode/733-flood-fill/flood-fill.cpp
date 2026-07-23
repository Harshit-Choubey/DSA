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
        
        // Queue to store the coordinates of the pixels to process
        queue<pair<int, int>> q;
        
        // Start with the initial pixel
        q.push({sr, sc});
        image[sr][sc] = color; // Change color immediately when adding to queue
        
        // Directions for Up, Down, Left, Right
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Process the queue
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            // Check all 4 neighboring pixels
            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;
                
                // If neighbor is within bounds AND has the original color
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == original_color) {
                    image[nr][nc] = color; // Paint it
                    q.push({nr, nc});      // Add to queue to check its neighbors later
                }
            }
        }
        
        return image;
    }
};