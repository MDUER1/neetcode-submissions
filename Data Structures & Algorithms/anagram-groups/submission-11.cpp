
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        for (auto const& s : strs) {
            std::vector<int> count(26, 0);
            for (char const& c : s) {
                count[c - 'a']++;
            }
            
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]);
            }

            res[key].push_back(s);
        }
        std::vector<std::vector<std::string>> result;
        for (auto const& pairs : res) {
            result.push_back(pairs.second);
        }

        return result;
    }
};











































