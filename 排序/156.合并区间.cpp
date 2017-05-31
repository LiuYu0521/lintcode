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
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    static bool cmp(const Interval &a, const Interval &b)
    {
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        if(intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> vt;
        vt.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++)
        {
            if(vt[vt.size() -1].end >= intervals[i].start)
            {
                vt[vt.size() -1].end = max(vt[vt.size() -1].end, intervals[i].end);
            }
            else
            {
                vt.push_back(intervals[i]);
            }
        }
        return vt;
    }
};
