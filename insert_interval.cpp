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
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        if (intervals.empty()) {
            return vector<Interval> (1, newInterval);    
        }
        
        vector<Interval> smaller_part;
        vector<Interval> bigger_part;
        
        for (auto it = intervals.begin(); it != intervals.end(); it++) {
            if (it->end < newInterval.start) {
                smaller_part.push_back(*it);
            } else if (it->start > newInterval.end) {
                bigger_part.push_back(*it);
            } else {
                newInterval.start = min(it->start, newInterval.start);
                newInterval.end = max(it->end, newInterval.end);
            }
        }
        
        smaller_part.push_back(newInterval);
        
        bigger_part.insert(bigger_part.begin(), smaller_part.begin(), smaller_part.end());
        return bigger_part;
    }
};
