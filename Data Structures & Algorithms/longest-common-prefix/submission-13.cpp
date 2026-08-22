class Solution {
public:
string longestCommonPrefix(vector<string>& strs) {
    for (int i{0}; i < strs[0].size(); ++i) {
        std::unordered_set<char> s;

        for (int j{0}; j < strs.size(); ++j) {
            if (i >= strs[j].size())
                return strs[0].substr(0, i);

            s.insert(strs[j][i]);
        }

        if (s.size() > 1)
            return strs[0].substr(0, i);
    }

    return strs[0];
}
};