/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    priority_queue<int, vector<int>, greater<int>> q;
    static bool cmp(const Interval &a, const Interval &b)
    {
        return a.start < b.start;
    }
    static int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        sort(airplanes.begin(), airplanes.end(), cmp);
        int res = 0;
        for(int i = 0; i < airplanes.size(); i++)
        {
            while(q.size() > 0 && q.top() <= airplanes[i].start)
                q.pop();
            q.push(airplanes[i].end);
            res = max(res, q.size());
        }
        return res;
    }
};
