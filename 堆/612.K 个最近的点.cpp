/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
Point originPoint;
int getDistance(Point &a, Point &b)
{
    return (a.x-b.x) * (a.x-b.x) + (a.y - b.y) * (a.y - b.y);
}
struct cmp
{
    bool operator () (Point &a, Point &b)
    {
        int d_a = getDistance(a, originPoint);
        int d_b = getDistance(b, originPoint);
        if(d_a != d_b)
            return d_a < d_b;
        else if(a.x != b.x)
            return a.x < b.x;
        else
            return a.y < b.y;
    }
};
class Solution {
public:
    /**
     * @param points a list of points
     * @param origin a point
     * @param k an integer
     * @return the k closest points
     */
    vector<Point> kClosest(vector<Point>& points, Point& origin, int k) {
        // Write your code here
        priority_queue<Point, vector<Point>, cmp> q;
        originPoint = origin;
        for(Point p : points)
        {
            q.push(p);
            if(q.size() > k)
                q.pop();
        }
        vector<Point> res;
        while(!q.empty())
        {
            res.push_back(q.top());
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
