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

    vector<int> dice_number;
    int dice;
    for (int i = 0; i < 3; i++)
    {
        cin >> dice;
        dice_number.push_back(dice);
    }
    sort(dice_number.begin(), dice_number.end());
    if (dice_number[0] == dice_number[1])
    {
        if (dice_number[1] == dice_number[2])
        {
            cout << 10000 + dice_number[0] * 1000;
            return 0;
        }
        cout << 1000 + dice_number[0] * 100;
        return 0;
    }
    else if (dice_number[1] == dice_number[2])
    {
        cout << 1000 + dice_number[1] * 100;
    }
    else
    {
        cout << dice_number[2] * 100;
    }
}