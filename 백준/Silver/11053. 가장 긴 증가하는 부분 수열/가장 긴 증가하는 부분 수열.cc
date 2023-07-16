#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;
int dp[1001] = { 0 };
int arr[1001] = { 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int number;
        cin >> number;
        arr[i] = number;
    }
    for (int i = 1; i <= N; i++)
    {
        dp[i] = 1;
        for (int j = 1; j <= i; j++)
        {
            if (arr[j] < arr[i])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    int max_value = 0;
    for (int i = 1; i <= N; i++)
    {
        max_value = max(max_value, dp[i]);
    }
    cout << max_value;
}