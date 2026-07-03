class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    int n = s.size();
    vector<bool> dp(n + 1, false);

    dp[0] = true;

    for (int j = 1; j <= n; j++) {

        for (int k = 0; k < j; k++) {

            if (dp[k] && dict.count(s.substr(k, j - k))) {
                dp[j] = true;
                break;
            }
        }
    }

    return dp[n];
    }
};
