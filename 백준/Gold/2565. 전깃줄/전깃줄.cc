#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;
int dp[101] = { 0 }; // 개수 저장
vector<pair<int, int>> arr;  // 연결된 전깃줄 저장

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;  // 100

    cin >> N;
    arr.push_back(make_pair(0, 0));
    for (int i = 1; i <= N; i++)
    {
        int line_num1, line_num2;
        cin >> line_num1 >> line_num2;
        arr.push_back(make_pair(line_num1, line_num2));
    }
    sort(arr.begin(), arr.end());
    for (int i = 1; i <= N; i++)
    {
        int max_value = 0;
        for (int j = 1; j <= i; j++)
        {
            if (arr[j].first < arr[i].first && arr[j].second < arr[i].second)
            {
                max_value = max(max_value, dp[j]);
            }
        }
        dp[i] = max_value + 1;
    }
    int max_dp = 0;
    for (int i = 1; i <= N; i++)
    {
        max_dp = max(dp[i], max_dp);
    }
    cout << N - max_dp;
}