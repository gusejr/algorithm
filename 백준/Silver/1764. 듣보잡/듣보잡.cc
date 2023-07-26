#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;
vector<string> all_name;
vector<string> find_name;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    string name;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> name;
        all_name.push_back(name);
    }
    for (int i = 0; i < M; i++)
    {
        cin >> name;
        all_name.push_back(name);
    }
    sort(all_name.begin(), all_name.end());
    for (int i = 0; i < all_name.size(); i++)
    {
        if (i + 1 < all_name.size())
        {
            if (all_name[i] == all_name[i + 1])
            {
                find_name.push_back(all_name[i]);
            }
        }
    }
    cout << find_name.size() << '\n';
    for (int i = 0; i < find_name.size(); i++)
    {
        cout << find_name[i] << '\n';
    }
}