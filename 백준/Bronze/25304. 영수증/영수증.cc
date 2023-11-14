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

    long long total_cost, total_count;
    long long piece_cost, bundle_count;
    long long compare = 0;
    cin >> total_cost >> total_count;
    for (int i = 0; i < total_count; i++)
    {
        cin >> piece_cost >> bundle_count;
        compare = compare + piece_cost * bundle_count;
    }
    if (total_cost == compare)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}