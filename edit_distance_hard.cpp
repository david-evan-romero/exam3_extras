#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Assuming the platform template provides:
// class Solution { 
// public:
//     int minDistance(string word1, string word2) {
//         // Paste code here
//     }
// };

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        // DP table initialization
        // dp[i][j] = min ops to convert word1[0...i-1] to word2[0...j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        // Base cases: converting string to empty string requires length ops (deletions)
        for (int i = 0; i <= m; i++) dp[i][0] = i; // Delete all of word1
        for (int j = 0; j <= n; j++) dp[0][j] = j; // Insert all of word2

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    // Match: No operation needed, inherits cost from previous match.
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // Mismatch: Take the minimum cost of the three possible operations, plus 1 for the operation itself.
                    
                    // 1. Delete: dp[i-1][j] (delete word1[i-1])
                    // 2. Insert: dp[i][j-1] (insert character to match word2[j-1])
                    // 3. Replace: dp[i-1][j-1] (replace word1[i-1] with word2[j-1])
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        return dp[m][n];
    }
};
