#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;
int dp[1001][4] = { 0 };
int pay[1001][4] = { 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    int cost;
    
    cin >> N;
    
    for (int i = 1; i <= N; i++) // 비용 넣기
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> cost;
            pay[i][j] = cost;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + pay[i][0];  // 빨간색 선택 했을 때
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + pay[i][1];  // 초록색 선택 했을 때
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + pay[i][2];  // 파란색 선택 했을 때
    }
    cout << min(dp[N][0], min(dp[N][1], dp[N][2]));
}