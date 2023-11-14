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

    int num_of_time;
    int A, B;
    cin >> num_of_time;
    for (int i = 0; i < num_of_time; i++)
    {
        cin >> A >> B;
        cout << A + B << '\n';
    }
}