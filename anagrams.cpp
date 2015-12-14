class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        
        unordered_map<string, pair<string, bool>> map;
        vector<string> result;
        
        for (auto &i : strs) {
            string key = keyGen(i);
            if (map.find(key) != map.end()) {
                if (map[key].second == false) {
                    result.push_back(map[key].first);
                    map[key].second = true;
                }
                result.push_back(i);
            } else {
                map.insert(make_pair(key, make_pair(i, false)));
            }
        }
        return result;
        
    }
    
    string keyGen(string &str) {
        vector<int> count(26, 0);
        
        for (auto &i: str) {
            count[i -'a']++;
        }
        string result("");
        
        for (int i = 0; i < 26; i++) {
            result += to_string(count[i]);
            result.append("|");
        }
        
        return result;
    }
    

};