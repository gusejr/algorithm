#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    map<string, int> poketmon_books_number;
    vector<pair<string, int>> poketmon_books_name;
    int N, M; // N : 총 입력 개수, M : 맞춰야 하는 입력 개수
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string poketmon_name;
        cin >> poketmon_name;
        poketmon_books_name.push_back(make_pair(poketmon_name, i + 1));
        poketmon_books_number.insert(make_pair(poketmon_name, i + 1));
    }
    for (int i = 0; i < M; i++)
    {
        string find_name;
        cin >> find_name;
        if (atoi(find_name.c_str()) == 0)// 해당 포켓몬 번호 출력
        {
            cout << poketmon_books_number[find_name] << '\n';
        }
        else  // 해당 포켓몬 이름 출력
        {
            int number = atoi(find_name.c_str());
            cout << poketmon_books_name[number - 1].first << '\n';
        }
    }
    
}