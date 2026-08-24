
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (auto const& str : strs) {
            string sortedS = str;
            std::sort(sortedS.begin(), sortedS.end());
            res[sortedS].push_back(str);
        }

        std::vector<std::vector<std::string>> result;
        for (auto const& pairs : res) {
            result.push_back(pairs.second);
        }

        return result;
    }
};











































