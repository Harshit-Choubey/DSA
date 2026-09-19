class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {
        
        int x = min(max(xCenter, x1), x2);
        int y = min(max(yCenter, y1), y2);

        int dx = xCenter - x;
        int dy = yCenter - y;

        return dx * dx + dy * dy <= radius * radius;
    }
};