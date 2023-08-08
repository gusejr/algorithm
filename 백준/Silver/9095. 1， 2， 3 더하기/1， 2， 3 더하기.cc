#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N;
    
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        int dp[12] = { 0 };
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int j = 4; j <= N; j++)
        {
            dp[j] = dp[j - 3] + dp[j - 2] + dp[j - 1];
        }
        cout << dp[N] << '\n';
    }
}