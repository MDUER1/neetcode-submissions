class Solution {
public:
    bool isAnagram(string s, string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        for (int i{}; i < std::max(s.size(), t.size()); ++i) {
            if (s[i] != t[i]) {
                return false;
            }
        }

        return true;
    }
};