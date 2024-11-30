class Solution {
public:
    void generateSubsets(int index, vector<int>& nums, vector<int>& currentSubset, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(currentSubset);
            return;
        }

        currentSubset.push_back(nums[index]);
        generateSubsets(index + 1, nums, currentSubset, result);

        currentSubset.pop_back();
        generateSubsets(index + 1, nums, currentSubset, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        generateSubsets(0, nums, currentSubset, result);
        return result;
    }
};