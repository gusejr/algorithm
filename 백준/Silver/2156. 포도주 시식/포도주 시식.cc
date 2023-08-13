#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;
int quantity[10001] = { 0 };
int max_dp[10001] = { 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    int wine;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> wine;
        quantity[i] = wine;
    }
    max_dp[1] = quantity[1];
    max_dp[2] = max_dp[1] + quantity[2];
    for (int i = 3; i <= N; i++)
    {
        max_dp[i] = max(max_dp[i - 2] + quantity[i], max(max_dp[i - 1], max_dp[i - 3] + quantity[i - 1] + quantity[i]));
    }
    cout << max_dp[N];
}