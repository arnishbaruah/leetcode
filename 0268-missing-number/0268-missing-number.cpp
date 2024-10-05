class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int totalSum = (N * (N + 1)) / 2;
        int arraySum = 0;
        for (int i = 0; i < N; i++) {
            arraySum += nums[i];
        }
        return totalSum - arraySum;
    }
};
