class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int sum = 0;

        for (const int num : nums) {
            sum = max(num, sum + num);
            result = max(result, sum);
        }

    return result;
    }
};