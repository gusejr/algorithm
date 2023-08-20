#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;
int dp[201][201] = { 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= K; i++)
    {
        dp[1][i] = i;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            for (int t = 0; t <= j; t++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][t]) % 1000000000;
            }
        }
    }
    cout << dp[N][K] % 1000000000;
}