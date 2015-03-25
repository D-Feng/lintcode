class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
    	// f[i][v] is first i elements, with A[i] changed to v, minimum cost
    	// f[i][v] = min (f[i - 1][ v - target ... v + target ])
    	// f[0][j] = 0
    	int len = A.size();
    	if (len <= 1) {
    		return 0;
    	}
    	vector<vector<int>> f(len + 1, vector<int>(101, -1));
    	for (int i = 0; i < 101; i++) {
    		f[0][i] = 0;
    	}

    	for (int i = 1; i <= len; i++) {
    		for (int j = 1; j < 101; j++) {
    			for (int k = j - target; k <= j + target; k++) {
    				if ( 1 <= k && k <= 100 ) {
    					if (f[i][j] < 0 || f[i][j] > f[i - 1][k] + abs(j - A[i - 1])) {
    						f[i][j] = f[i - 1][k] + abs(j - A[i - 1]);
    					}
    				}

    			}
    		}
    	}
    	int minimum_cost = f[len][1];
    	for (int i = 2; i < 101; i++) {
    		minimum_cost = f[len][i] < minimum_cost ? f[len][i] : minimum_cost;
    	}
    	return minimum_cost;

    }
};
