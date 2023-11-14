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

    int T;
    int A, B;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        cout << "Case #" << i + 1 << ": " << A + B << '\n';
    }
}