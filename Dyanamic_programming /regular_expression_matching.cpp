class Solution {
public:
    // bool isMatch(string s, string p) {
    //      if (p.empty()) {
    //         return s.empty();
    //     }

    //     bool firstMatch = (!s.empty() && (s[0] == p[0] || p[0] == '.'));

    //     if (p.length() >= 2 && p[1] == '*') {
    //         return (isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p)));
    //     } else {
    //         return firstMatch && isMatch(s.substr(1), p.substr(1));
    //     }
    // }
     bool helper(string s,string p,unordered_map<string, bool>& memo) {
        if (memo.count(s + "_" + p)) {
            return memo[s + "_" + p];
        }

        if (p.empty()) {
            return s.empty();
        }

        bool firstMatch = (!s.empty() && (s[0] == p[0] || p[0] == '.'));

        if (p.length() >= 2 && p[1] == '*') {
            bool result = helper(s, p.substr(2), memo) || (firstMatch && helper(s.substr(1), p, memo));
            memo[s + "_" + p] = result;
            return result;
        } else {
            bool result = firstMatch && helper(s.substr(1), p.substr(1), memo);
            memo[s + "_" + p] = result;
            return result;
        }
    }
      bool isMatch(string s, string p) {
        unordered_map<string, bool> memo;
        return helper(s, p, memo);
    }
    
};
