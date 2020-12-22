// C++ solution.

// C(n,0) = 1; C(n,n) = 1;
// C(n,k) = (n-k+1)/k * C(n,k-1), 1 <= k <= n;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int n = 0; n < numRows; n++) {
            vector<int> birow(n+1);
            birow[0] = 1;
            for (int k = 1; k <= n; k++) {
                birow[k] = (n-k+1) * birow[k-1] / k;
            }
            ans.push_back(birow);
        }
        return ans;
    }
};