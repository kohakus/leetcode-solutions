// C++ solution.

// simple method with loop
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) { return false; }
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

// use log property
class Solution {
public:
    bool isPowerOfThree(int n) {
        return std::fmod(std::log10(n) / std::log10(3), 1) == 0;
    }
};

// cheating
class Solution {
public:
    int const max3_power_int32 = 1162261467; // 3^19, 3^20 = 3486784401 > MaxInt32
    int const max_int32 = 2147483647; // 2^31 - 1

    bool isPowerOfThree(int n) {
        if (n <= 0 || n > max3_power_int32) { return false; }
        return max3_power_int32 % n == 0;
    }
};