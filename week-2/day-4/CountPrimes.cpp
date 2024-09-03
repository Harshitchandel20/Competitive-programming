class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        vector<bool> isNotPrime(n, false);
        int count = 0;
        
        for (int i = 2; i < n; ++i) {
            if (!isNotPrime[i]) {  // i is prime
                ++count;
                for (int k = 2; k * i < n; ++k) {
                    isNotPrime[k * i] = true;
                }
            }
        }
        
        return count;
    }
};
