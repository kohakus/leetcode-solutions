// C++ solution.

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        if (n < 3 || n > 12) { return ans; }
        search(s, "", ans, 0);
        return ans;
    }

    void search(string cur_s, string cur_ip, vector<string>& ans, int cnt) {
        if (cnt == 3 && validSubIP(cur_s)) {
            ans.push_back(cur_ip + cur_s);
            return;
        }
        for (int i = 1; i < 4 && i < cur_s.size(); i++) {
            string sub_ip = cur_s.substr(0, i);
            if (validSubIP(sub_ip)) {
                search(cur_s.substr(i), cur_ip + sub_ip + ".", ans, cnt+1);
            }
        }
    }

    bool validSubIP(string& sub_ip) {
        if (sub_ip.size() > 3) { return false; }
        if (sub_ip[0] == '0') {
            return sub_ip == "0";
        } else {
            int num = stoi(sub_ip);
            return (num > 0 && num <= 255);
        }
    }
};