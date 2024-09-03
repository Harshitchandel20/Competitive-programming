class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        for (const int num : nums) {
            ++frequencyMap[num];
        }

        vector<list<int>> buckets(nums.size() + 1);

        for (const auto& [num, freq] : frequencyMap) {
            buckets[freq].push_back(num);
        }

        vector<int> topK;
        for (int i = buckets.size() - 1; i >= 0 && topK.size() < k; --i) {
            for (const int num : buckets[i]) {
                topK.push_back(num);
                if (topK.size() == k) {
                    break;
                }
            }
        }

        return topK;

    }
};