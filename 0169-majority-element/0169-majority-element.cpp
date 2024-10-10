class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        int verify_count = 0;
        for (int num : nums) {
            if (num == candidate) {
                verify_count++;
            }
        }

        if (verify_count > nums.size() / 2) {
            return candidate;
        } else {
            return -1;
        }
    }
};
