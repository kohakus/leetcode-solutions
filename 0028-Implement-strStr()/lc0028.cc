// C++ solution.

// naive search O(NM)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) { return -1; }
        int psize = needle.size();
        for (int i = 0; i <= haystack.size()-psize; i++) {
            if (!haystack.compare(i, psize, needle)) {
                return i;
            }
        }
        return -1;
    }
};

// use std::string::find method
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) { return -1; }
        string::size_type pos = haystack.find(needle);
        return pos == string::npos ? -1 : pos;
    }
};

// KMP algorithm O(M + N)
class Solution {
public:
    int strStr(string haystack, string needle) {
        string::size_type n = haystack.size();
        string::size_type m = needle.size();
        if (n < m) { return -1; }
        if (!m) { return 0; }

        // KMP preprocessing
        vector<int> jmparr(m, 0);
        failure(needle, jmparr);

        int pos = 0;
        for (int i = 0; i < n; i++) {
            while (pos && haystack[i] != needle[pos]) {
                pos = jmparr[pos];
            }
            if (haystack[i] == needle[pos]) { pos++; }
            if (pos == m) { return i-m+1; }
        }
        return -1;
    }
private:
    void failure(const string& p, vector<int>& jmparr) {
        string::size_type m = p.size();
        for (int i = 1; i < m; i++) {
            int prepos = jmparr[i];
            while (prepos && p[prepos] != p[i]) {
                prepos = jmparr[prepos];
            }
            if (i+1 < m) {
                jmparr[i+1] = (p[prepos] == p[i]) ? (prepos+1) : 0;
            }
        }
    }
};