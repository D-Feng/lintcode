class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
     
    struct {
        bool operator() (const string& a, const string& b) {
            return b + a < a + b;
        }
    } cmp;
    
    string largestNumber(vector<int> &num) {
        // write your code here
        vector<string> strNum;
        
        for (auto &it : num) {
            strNum.push_back(to_string(it));
        }
        
        sort(strNum.begin(), strNum.end(), cmp);
        string result;
        
        for (auto &it : strNum) {
            
            result += it;
        }
        
        if (result.empty() || result[0] == '0') {
            return "0";
        }
        
        return result;
    }
};