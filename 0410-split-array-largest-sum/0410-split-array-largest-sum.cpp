class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long maxSum) {
        int subarrays = 1;
        long long currSum = 0;

        for (int num : nums) {
            if (currSum + num <= maxSum) {
                currSum += num;
            } else {
                subarrays++;
                currSum = num;

                if (subarrays > k)
                    return false;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = 0;

        for (int num : nums)
            high += num;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return (int)low;
    }
};