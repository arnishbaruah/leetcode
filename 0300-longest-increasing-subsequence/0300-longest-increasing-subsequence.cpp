class Solution {
private:
    int getAns(vector<int>& nums, int ind, int prev_index, vector<vector<int>>& dp) {
        if (ind == nums.size())
            return 0;
        
        if (dp[ind][prev_index + 1] != -1)
            return dp[ind][prev_index + 1];
        
        int notTake = getAns(nums, ind + 1, prev_index, dp);
        
        int take = 0;
        if (prev_index == -1 || nums[ind] > nums[prev_index]) {
            take = 1 + getAns(nums, ind + 1, ind, dp);
        }
        
        return dp[ind][prev_index + 1] = max(notTake, take);
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return getAns(nums, 0, -1, dp);
    }
};
