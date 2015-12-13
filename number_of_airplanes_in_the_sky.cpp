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
    struct  {
        bool operator() (const pair<int, char> &a, const pair<int, char> &b) {
            if (a.first == b.first) {
                return a.second == ']';
            }
            return a.first < b.first;
        }
    } cmp;
    
    
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        int len = airplanes.size();
        int max_airplane = 0;
        
        vector<pair<int, char>> array;
        
        for (auto &i : airplanes) {
            array.push_back(make_pair(i.start, '['));
            array.push_back(make_pair(i.end, ']'));
        }
        
        sort(array.begin(), array.end(), cmp);
        
        int cnt = 0;
        int rst = 0;
        for (auto &i: array) {
            if (i.second == '[') {
                cnt++;
            } else {
                cnt--;
            }
            
            rst = max(rst, cnt);
        }
        return rst;
    }
};