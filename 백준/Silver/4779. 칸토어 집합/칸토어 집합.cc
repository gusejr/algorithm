#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string solve(int N)
{
    string blank = "";
    if (N == 0)
    {
        return "-";
    }
    for (int i = 0; i < pow(3, N - 1); i++)
    {
        blank.append(" ");
    }
    return solve(N - 1) + blank + solve(N - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    while (1)
    {
        cin >> N;
        if (cin.eof())
        {
            break;
        }
        else
        {
           cout << solve(N) << '\n';
        }
    }
}