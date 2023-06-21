#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int C;
    set <int> make_set;
    cin >> C;
    for (int i = 0; i < C; i++)
    {
        string sign;
        int number;
        cin >> sign;
        if (sign == "all")
        {
            for (int j = 1; j <= 20; j++)
            {
                make_set.insert(j);
            }
        }
        else if (sign == "empty")
        {
            make_set.clear();
        }
        else
        {
            cin >> number;
        }
        if (sign == "add")
        {
            make_set.insert(number);
        }
        else if (sign == "remove")
        {
            make_set.erase(number);
        }
        else if (sign == "check")
        {
            if (make_set.find(number) == make_set.end())
            {
                cout << "0" << '\n';  // 없을 때
            }
            else
            {
                cout << "1" << '\n';  // 있을 때
            }
        }
        else if (sign == "toggle")
        {
            if (make_set.find(number) == make_set.end())
            {
                make_set.insert(number);
            }
            else
            {
                make_set.erase(number);
            }
        }
    }
}