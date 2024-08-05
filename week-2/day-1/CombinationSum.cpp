class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);
        dp[0] = {{}};

        for (int num : candidates) {
            for (int i = num; i <= target; ++i) {
                for (auto& comb : dp[i - num]) {
                    dp[i].push_back(comb);
                    dp[i].back().push_back(num);
                }
            }
        }

        return dp[target];
    }
};