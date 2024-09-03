class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;

        unordered_map<char, int> pCount, sCount;
        for (char c : p) {
            ++pCount[c];
        }

        int pLength = p.size();
        for (int i = 0; i < s.size(); ++i) {
            ++sCount[s[i]];

            if (i >= pLength) {
                if (--sCount[s[i - pLength]] == 0) {
                    sCount.erase(s[i - pLength]);
                }
            }

            if (sCount == pCount) {
                result.push_back(i - pLength + 1);
            }
        }

        return result;
    }
};