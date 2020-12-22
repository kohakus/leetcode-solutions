// C++ solution.

// Method based on sort.
// Time complexity: O(NlogN), Space complexity: O(1).
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= i+1) {
                ans++;
            }
        }
        return ans;
    }
};

// Counting sort/Hash.
// Time complexity: O(N), Space complexity: O(N).
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        // a mapping: citation -> amount
        vector<int> buckets(n+1, 0);
        for (int citation : citations) {
            // citation > n is an exception, just treat it as citation == n
            if (citation > n) {
                buckets[n]++;
            } else {
                buckets[citation]++;
            }
        }

        int cnt = 0;
        for (int i = n; i >= 0; i--) {
            cnt += buckets[i];
            if (cnt >= i) {
                return i;
            }
        }
        return 0;
    }
};