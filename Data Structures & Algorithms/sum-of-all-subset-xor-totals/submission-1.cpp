class Solution {
public:
    int backtrack(const vector<int>& nums, int index, int currentXOR)
    {
        if (index == nums.size()) //one past the last element = return here
        {
            return currentXOR;
        }
        // Completely explores the include branch first from include element 1
        int include = backtrack(
            nums,
            index + 1,
            currentXOR ^ nums[index]
        );
        // completely explores the exclude branch of element one
        int exclude = backtrack(
            nums,
            index + 1,
            currentXOR
        );

        return include + exclude;
    }

    int subsetXORSum(vector<int>& nums) {
        return backtrack(nums, 0, 0);
    }
};