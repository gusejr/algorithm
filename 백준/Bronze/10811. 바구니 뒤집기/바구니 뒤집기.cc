#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    int i, j;
    vector<int> bowl;
    cin >> N >> M;
    for (int p = 1; p <= N; p++)
    {
        bowl.push_back(p);
    }
    for (int p = 0; p < M; p++)
    {
        cin >> i >> j;
        reverse(bowl.begin() + i - 1, bowl.begin() + j);
    }
    for (int p = 0; p < N; p++)
    {
        cout << bowl[p] << ' ';
    }
}