class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // isPal[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // Length 1
        for (int i = 0; i < n; i++) {
            isPal[i][i] = true;
        }

        // Length >= 2
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (len == 2 || isPal[i + 1][j - 1]) {
                        isPal[i][j] = true;
                    }
                }
            }
        }

        // dp[i] = maximum number of palindromes
        // using s[0...i-1]
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            // Don't use s[i-1]
            dp[i] = dp[i - 1];

            // Try every palindrome ending at i-1
            for (int j = 0; j < i; j++) {
                if (i - j >= k && isPal[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};