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

    string sentence;
    for (int i = 0; i < 100; i++)
    {
        getline(cin, sentence);
        cout << sentence << '\n';
    }
}