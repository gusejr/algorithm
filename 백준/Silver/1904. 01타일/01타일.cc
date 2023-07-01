#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <cmath>
using namespace std;
vector<int> dp; // 길이가 N인 모든 2진 수열의 개수를 15746으로 나눈 나머지

int solve(int N) // 길이가 N인 모든 2진 수열의 개수를 15746으로 나눈 나머지
{
    if (dp[N] != INT_MAX)
    {
        return dp[N];
    }

    dp[N] = (solve(N - 2) + solve(N - 1)) % 15746;
    return dp[N];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    dp = vector<int>(N + 1, INT_MAX);
    
    dp[1] = 1;
    dp[2] = 2;
    cout << solve(N);
}