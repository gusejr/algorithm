#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
vector<int> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, min_time = 0;
    cin >> N;
    dp = vector<int>(N + 1, INT_MAX);

    dp[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        if (i % 3 == 0)
        {
            dp[i] = min(dp[i / 3] + 1, min(dp[i - 1] + 1, dp[i]));
        }
        if (i % 2 == 0)
        {
            dp[i] = min(dp[i / 2] + 1, min(dp[i - 1] + 1, dp[i]));
        }

        dp[i] = min(dp[i - 1] + 1, dp[i]);
    }
    cout << dp[N];
}