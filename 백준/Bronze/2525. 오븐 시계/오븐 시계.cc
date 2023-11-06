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

    int hour, minute;
    int spend_time;
    int remain_hour, remain_minute;
    cin >> hour >> minute;
    cin >> spend_time;

    remain_hour = spend_time / 60;  // 남는 시
    remain_minute = spend_time % 60; // 남는 분
    hour = hour + remain_hour;
    minute = minute + remain_minute;
    if (minute > 59) // 분 초과
    {
        hour = hour + (minute / 60);
        minute = minute % 60;
    }
    if (hour > 23) // 시 초과
    {
        hour = hour % 24;
    }
    cout << hour << ' '<< minute << '\n';
}