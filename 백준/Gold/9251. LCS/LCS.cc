#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;
int LCS_dp[1001][1001] = { 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string word1, word2;
    cin >> word1 >> word2;
    for (int i = 1; i <= word1.size(); i++)
    {
        for (int j = 1; j <= word2.size(); j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                LCS_dp[i][j] = LCS_dp[i - 1][j - 1] + 1;
            }
            else
            {
                LCS_dp[i][j] = max(LCS_dp[i - 1][j], LCS_dp[i][j - 1]);
            }
        }
    }
    cout << LCS_dp[word1.size()][word2.size()];
}