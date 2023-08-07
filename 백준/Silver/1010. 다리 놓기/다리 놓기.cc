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

    int T;
    int west_point, east_point;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int dp[31][31] = { 0 };
        cin >> west_point >> east_point;
        for (int j = 1; j <= east_point; j++)
        {
            dp[1][j] = dp[1][j - 1] + 1;
        }
        for (int j = 2; j <= west_point; j++)
        {
            for (int k = 1; k <= east_point; k++)
            {
                dp[j][k] = dp[j][k - 1] + dp[j - 1][k - 1];
            }
        }
        cout << dp[west_point][east_point] << '\n';
    }
}