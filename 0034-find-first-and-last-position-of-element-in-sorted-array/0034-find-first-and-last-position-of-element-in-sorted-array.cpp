class Solution {
public:
    int findPosition(vector<int>& nums, int target, bool findFirst) {
        int start = 0;
        int end = nums.size() - 1;
        int res = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                res = mid;
                if (findFirst) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int firstPos = findPosition(nums, target, true);
        int lastPos = findPosition(nums, target, false);
        return {firstPos, lastPos};
    }
};
