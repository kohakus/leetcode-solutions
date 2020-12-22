// C++ solution.

// utilize hash table
class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> hash;
        while (n != 1) {
            if (hash.find(n) != hash.end()) {
                return false;
            } else {
                hash.insert(n);
            }
            n = helper(n);
        }
        return true;
    }

    int helper(int n) {
        int ans = 0;
        while (n) {
            int tmp = n % 10;
            ans += tmp * tmp;
            n /= 10;
        }
        return ans;
    }
};


// math
class Solution {
public:
    bool isHappy(int n) {
        while (n != 1 && n!= 4) {
            int next = 0;
            while (n) {
                int tmp = n % 10;
                next += tmp * tmp;
                n /= 10;
            }
            n = next;
        }
        return n == 1;
    }
};


// floyd cycle detection
class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = helper(slow);
            fast = helper(fast);
            fast = helper(fast);
        } while (slow != fast);

        return slow == 1;
    }

    int helper(int n) {
        int ans = 0;
        while (n) {
            int tmp = n % 10;
            ans += tmp * tmp;
            n /= 10;
        }
        return ans;
    }
};