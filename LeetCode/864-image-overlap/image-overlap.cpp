class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> v1;
        vector<pair<int, int>> v2;
        
        // Extract coordinates of all 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) v1.push_back({i, j});
                if (img2[i][j] == 1) v2.push_back({i, j});
            }
        }
        
        // 2D Array to count shift frequencies (offset by 30 to handle negatives)
        int count[60][60] = {0};
        int max_overlap = 0;
        
        // Find the translation vector for every pair using standard loops
        for (int i = 0; i < v1.size(); i++) {
            for (int j = 0; j < v2.size(); j++) {
                
                // Calculate the shift needed to make v1[i] overlap with v2[j]
                int dx = v2[j].first - v1[i].first + 30;
                int dy = v2[j].second - v1[i].second + 30;
                
                // Increment the frequency of this specific translation
                count[dx][dy]++;
                
                // Track the maximum overlap found so far
                if (count[dx][dy] > max_overlap) {
                    max_overlap = count[dx][dy];
                }
            }
        }
        
        return max_overlap;
    }
};