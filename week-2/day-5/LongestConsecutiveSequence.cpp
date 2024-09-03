class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : nums) {
            if (seen.find(num - 1) != seen.end()) {
                continue;
            }

            int currentNum = num;
            int currentStreak = 1;

            while (seen.find(++currentNum) != seen.end()) {
                ++currentStreak;
            }

            longestStreak = std::max(longestStreak, currentStreak);
        }

        return longestStreak;
    }
};