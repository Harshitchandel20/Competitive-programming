class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result{-1, -1};
        
        auto lower = lower_bound(nums.begin(), nums.end(), target);

        if (lower == nums.end() || *lower != target) {
            return result;
        }
        
        auto upper = upper_bound(nums.begin(), nums.end(), target);

        result[0] = lower - nums.begin();
        result[1] = upper - nums.begin() - 1;
        
        return result;
    }
};