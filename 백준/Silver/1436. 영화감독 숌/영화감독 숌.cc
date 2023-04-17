#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    int count = 0;
    string num;
    cin >> N;
    for (int i = 666; i <= 6669999; i++)
    {
        num = to_string(i);
        if (num.find("666") != string::npos)
        {
            count++;
        }
        else
        {
            continue;
        }
        if (count == N)
        {
            cout << i;
            break;
        }
    }
}