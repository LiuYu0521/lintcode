/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        vector<Interval> res = intervals;
        int i = 0, overlap = 0, n = res.size();
        while(i < n)
        {
            if(newInterval.end < res[i].start)
                break;
            else if(newInterval.start > res[i].end)
            {}
            else
            {
                newInterval.start = min(newInterval.start, res[i].start);
                newInterval.end = max(newInterval.end, res[i].end);
                overlap++;
            }
            i++;
        }
        if(overlap > 0)
            res.erase(res.begin() + i - overlap, res.begin() + i);
        res.insert(res.begin() + i - overlap, newInterval);
        return res;
    }
};
