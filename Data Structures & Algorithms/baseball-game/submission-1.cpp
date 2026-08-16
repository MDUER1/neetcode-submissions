class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::vector<int> scores;

        for (const std::string operation : operations)
        {
            if (operation == "+")
            {
                int newScore{scores[scores.size() - 1] + scores[scores.size() - 2]};
                scores.push_back(newScore);
            }

            else if (operation == "D")
            {
                scores.push_back(scores.back() * 2);
            }

            else if (operation == "C")
            {
                scores.pop_back();
            }

            else
            {
                scores.push_back(std::stoi(operation));
            }
        }

        int total{0};

        for (int score : scores)
        {
            total += score;
        }
        
        return total;
    }
};