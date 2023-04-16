#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int resign;
int pay_max = 0;
vector<pair<int, int>> counsel;

void solve(int day, int total_pay)
{   
    if (day <= resign)
    {
        pay_max = max(pay_max, total_pay);
    }
    if (day >= resign)
    {
        return;
    }
    solve(day + 1, total_pay);
    solve(counsel[day].first + day, counsel[day].second + total_pay);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int time;
    int pay;
    cin >> resign;
    for (int i = 0; i < resign; i++)
    {
        cin >> time >> pay;
        counsel.push_back(make_pair(time, pay));
    }
    solve(0, 0);
    cout << pay_max;
}