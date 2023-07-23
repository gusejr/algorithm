#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;
long long dp[101][11] = { 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    long long answer = 0;
    cin >> N;
    for (int i = 0; i <= 9; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = dp[i - 1][1];
        for (int j = 1; j <= 9; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        answer = answer + dp[N][i] % 1000000000;
    }
    cout << answer % 1000000000;
}