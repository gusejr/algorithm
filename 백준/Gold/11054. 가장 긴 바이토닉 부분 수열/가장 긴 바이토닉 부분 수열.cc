#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;
int dp1[1001] = { 0 };
int dp2[1001] = { 0 };
int number[1001] = { 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int input_num;
        cin >> input_num;
        number[i] = input_num;
        dp1[i] = 1;
        dp2[i] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (number[j] < number[i])
            {
                dp1[i] = max(dp1[j] + 1, dp1[i]);
            }
        }
    }
    for (int i = N; i >= 1; i--)
    {
        for (int j = N; j >= i; j--)
        {
            if (number[i] > number[j])
            {
                dp2[i] = max(dp2[j] + 1, dp2[i]);
            }
        }
    }
    int max_cost = 0;
    for (int i = 1; i <= N; i++)
    {
        max_cost = max(dp1[i] + dp2[i] - 1, max_cost);
    }
    cout << max_cost;
}