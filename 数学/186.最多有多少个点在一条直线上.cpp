/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        int res = 0;
        for(int i = 0; i < points.size(); i++)
        {
            int duplicate = 1;
            for(int j = i + 1; j < points.size(); j++)
            {
                int cnt = 0;
                long long x1 = points[i].x, y1 = points[i].y;
                long long x2 = points[j].x, y2 = points[j].y;
                if(x1 == x2 && y1 == y2)
                {
                    duplicate++;
                    continue;
                }
                for(int k = 0; k < points.size(); k++)
                {
                    long long x3 = points[k].x, y3 = points[k].y;
                    if(x1*y2 + x2*y3 + x3*y1 - x3*y2 - x2*y1 - x1 * y3 == 0)
                        cnt++;
                }
                res = max(res, cnt);
            }
            res = max(res, duplicate);
        }
        return res;
    }
};
