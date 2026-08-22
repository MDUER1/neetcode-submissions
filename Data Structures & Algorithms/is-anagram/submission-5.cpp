class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        std::unordered_map<char, int> orderS;
        std::unordered_map<char, int> orderT;

        for (int i{}; i < t.size(); ++i) {
            orderS[s[i]]++;
            orderT[t[i]]++;
        }

        return orderS == orderT;
    }
};









