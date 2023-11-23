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
    int i, j, k;
    cin >> N >> M;
    int* bowl = (int*)calloc(N + 1, sizeof(int));
    for (int p = 0; p < M; p++)
    {
        cin >> i >> j >> k;
        for (int q = i; q <= j; q++)
        {
            bowl[q] = k;
        }
    }
    for (int p = 1; p <= N; p++)
    {
        cout << bowl[p] << " ";
    }
    free(bowl);
}