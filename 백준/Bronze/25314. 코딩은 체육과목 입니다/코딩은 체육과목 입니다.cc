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

    int N, num_of_time;
    cin >> N;
    num_of_time = N / 4;
    for (int i = 0; i < num_of_time; i++)
    {
        cout << "long ";
    }
    cout << "int";
}