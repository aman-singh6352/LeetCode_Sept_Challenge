class Solution {
    public:
        bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
            int nx, ny;
            if(x1 >= xCenter) nx = x1;
            else nx = min(x2, xCenter);
            if(y1 >= yCenter) ny = y1;
            else ny = min(y2, yCenter);
            long long dx = nx-xCenter, dy = ny-yCenter;
            return (dx*dx + dy*dy) <= (radius*radius);
        }
    };

/* ---------------------------------------- JAVA CODE --------------------------------*/
class Solution {
    public boolean checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nx, ny;
        if(x1 >= xCenter) nx = x1;
        else nx = Math.min(x2, xCenter);
        if(y1 >= yCenter) ny = y1;
        else ny = Math.min(y2, yCenter);
        long dx = nx-xCenter, dy = ny-yCenter;
        return (dx*dx + dy*dy) <= (radius*radius);
    }
}