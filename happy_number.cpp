class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
     
     
    const int val_map[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
    bool isHappy(int n) {
        // Write your code here
        set<int> m_set;
        m_set.insert(n);
        int next = 0;
        
        while (true) {
            while (n != 0) {
                
                int bit = n % 10;
                n = n / 10;
                next += val_map[bit];
            }
            
            if (next == 1) {
                return true;
            }
            
            auto it = m_set.find(next);
            if (it != m_set.end() ) {
                return false;
            } else {
                m_set.insert(next);
            }
            
            n = next;
            next = 0;
        }
        
        return false;
    }
};