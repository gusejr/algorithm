#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;
vector<int> score;  // 입력된 점수 저장 벡터
vector<int> dp; // 최댓값 점수 저장

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int stairs, sc; // 계단 개수, 점수

    cin >> stairs;
    score = vector<int>(stairs + 1, 0);
    for (int i = 1; i <= stairs; i++)  // 점수 입력
    {
        cin >> sc;
        score[i] = sc;
    }
    dp = vector<int>(stairs + 1, 0);
    dp[0] = 0;
    dp[1] = score[1];
    dp[2] = dp[1] + score[2];
    for (int i = 3; i <= stairs; i++)
    {
        dp[i] = max(dp[i - 3] + score[i - 1] + score[i], dp[i - 2] + score[i]);
    }
    cout << dp[stairs];
}