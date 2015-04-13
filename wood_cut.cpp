class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int helper(vector<int> &L, int length) {
        
        int count = 0;
        for (int i = 0; i < L.size(); i++) {
            count += L[i] / length;
        }
        return count;
        
    }
    int woodCut(vector<int> L, int k) {
        // write your code here
        if (L.size() == 0) {
            return 0;
        }
        int max_length = 0;
        int len = L.size();
        for (int i = 0; i < len; i++) {
            if (L[i] > max_length) {
                max_length = L[i];
            }
        }
        
        int start = 1;
        int end = max_length;
        int mid;
        
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            int count = helper(L, mid);
            if (count == k) {
                start = mid;
            } else if (count > k) {
                start = mid;
            } else if (count < k) {
                end = mid;
            }
        }
        
        if (helper(L, end) >= k) {
            return end;
        }
        if (helper(L, start) >= k) {
            return start;
        }
        return 0;
    }
    

};
