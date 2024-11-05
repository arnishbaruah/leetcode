class Solution {
public:
    bool possible(vector<int> &bloomDay, int day, int m, int k) {
        int n = bloomDay.size();
        int cnt = 0;
        int noOfB = 0;

        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                cnt++;
                if (cnt == k) {
                    noOfB++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return noOfB >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = (long long)m * k;
        int n = bloomDay.size();
        
        if (val > n) return -1;

        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());

        int low = mini, high = maxi;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, m, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
