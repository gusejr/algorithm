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

    vector<string> words;
    string sentence;
    int time;
    cin >> time;
    for (int i = 0; i < time; i++)
    {
        int size;
        cin >> sentence;
        size = sentence.size();
        cout << sentence[size - size] << sentence[size - 1] << '\n';
    }
}