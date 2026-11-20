#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int n = s.size();
        unordered_set se(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && se.count(s.substr(j, i - j)) > 0) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution *s = new Solution;
    vector<string> w = {"cats", "dog", "sand", "and", "cat"};
    string pa = "catsandog";
    bool f = s->wordBreak(pa, w);
    cout << f << '\n';

    return 0;
}
