#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;
// 1차원 배열
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int std_num[31] = { 0 };
    int N;
    for (int i = 1; i <= 28; i++)
    {
        cin >> N;
        std_num[N] = 1;
    }
    for (int i = 1; i <= 30; i++)
    {
        if (std_num[i] == 0)
        {
            cout << i << '\n';
        }
    }
}