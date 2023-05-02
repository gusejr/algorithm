#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<pair<int, int>> printer;
    int print_time; // 케이스 입력 횟수
    int documents, location; // 문서 장 수, 문서 위치 
    int important; // 문서 중요도
    cin >> print_time;
    for (int i = 0; i < print_time; i++)
    {
        int order = 0; // 원하는 문서가 출력 될 순서
        printer.clear();
        cin >> documents >> location;
        for (int j = 0; j < documents; j++)
        {
            cin >> important;
            printer.push_back(make_pair(j, important));
        }
        while (documents != 0)
        {
            int max_imp = 0;
            for (int i = 0; i < printer.size(); i++)
            {
                max_imp = max(max_imp, printer[i].second); // 가장 큰거 찾기
            }
            for (int k = 0; k < documents; k++)
            {
                if (documents == 1)
                {
                    break;
                }
                if (max_imp != printer[0].second)
                {
                    printer.push_back(printer[0]);
                    printer.erase(printer.begin());
                }
            }
            order++;
            if (location == printer[0].first)  // 원하는 문서 위치 확인
            {
                cout << order << '\n';
                printer.erase(printer.begin());
                break;
            }
            else
            {
                printer.erase(printer.begin());
                documents = documents - 1;
            }
        }
    }
}