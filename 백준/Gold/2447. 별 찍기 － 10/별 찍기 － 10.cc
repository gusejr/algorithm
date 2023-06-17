#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<bool>> star;

void solve(int N, int start_blank, int end_blank)
{
    if (start_blank != 0 && end_blank < end_blank + N)
    {
        for (int i = start_blank; i < start_blank + N; i++)
        {
            for (int j = end_blank; j < end_blank + N; j++)
            {
                star[i][j] = false;
            }
        }
    }
    if (N == 0)
    {
        return;
    }
    if (end_blank + (N * 2) >= star.size() && start_blank + (N * 2) >= star.size())
    {
        solve(N / 3, N / 3, N / 3);
    }
    else if (end_blank + (N * 2) >= star.size())
    {
        start_blank = start_blank + (N + (N * 2));
        end_blank = N;
        solve(N, start_blank, end_blank);
    }
    else if(end_blank + (N * 2) < star.size())
    {
        end_blank = end_blank + (N + (N * 2));
        solve(N, start_blank, end_blank);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;

    cin >> N;
    star = vector<vector<bool>>(N, vector<bool>(N, true));
    solve(N, 0, 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (star[i][j] == true)
            {
                cout << '*';
            }
            else
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }
}