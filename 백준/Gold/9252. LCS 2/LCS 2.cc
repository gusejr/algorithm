#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;
int LCS_dp[1001][1001] = { 0 };
vector<char> output_word;
string word1, word2;

void solve(int i, int j)
{
    if (LCS_dp[i][j] == 0) // 종료
    {
        return;
    }
    if (LCS_dp[i][j] == LCS_dp[i][j - 1]) // 위
    {
        solve(i, j - 1);
    }
    else if (LCS_dp[i][j] == LCS_dp[i - 1][j]) // 왼쪽
    {
        solve(i - 1, j);
    }
    else // 알파벳 저장
    {
        output_word.push_back(word1[i - 1]);
        solve(i - 1, j - 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int flag = 0;
    int before = 0;

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
    solve(word1.size(), word2.size());
    reverse(output_word.begin(), output_word.end());
    cout << LCS_dp[word1.size()][word2.size()] << '\n';
    for (int i = 0; i < output_word.size(); i++)
    {
        cout << output_word[i];
    }
}