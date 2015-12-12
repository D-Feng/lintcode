class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
     
     
    const int val_map[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
    
    int getNextHappy(int n) {
        int sum = 0;
        while (n != 0) {
                
            int bit = n % 10;
            n = n / 10;
            sum += val_map[bit];
        }
        return sum;
    }
    
    
    bool isHappy(int n) {
        // Write your code here
        set<int> m_set;
        
        while (n != 1) {
            auto it = m_set.find(n);
            if (it != m_set.end()) {
                return false;
            }
            m_set.insert(n);
            n = getNextHappy(n);
        }
        
        return true;
    }
};