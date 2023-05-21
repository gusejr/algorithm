#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> paper;
int minus_paper = 0, zero_paper = 0, one_paper = 0;

void solve(int area, int row, int column)  // 한 변의 길이, 해당 구역의 첫번째 행, 해당 구역의 첫번째 열
{// 해당 구역의 종이가 모두 같은지 확인
    int count_minus_one = 0, count_zero = 0, count_one = 0;
    int count = 0;
    for (int i = row; i < row + area; i++)
    {
        for (int j = column; j < column + area; j++)
        {
            if (paper[i][j] == -1)
            {
                count_minus_one++;
            }
            else if (paper[i][j] == 0)
            {
                count_zero++;
            }
            else
            {
                count_one++;
            }
        }
    }
    if (area * area == count_minus_one || area * area == count_zero || area * area == count_one)
    {// 해당 구역의 숫자가 모두 같을 경우
        minus_paper += count_minus_one / (area * area);
        zero_paper += count_zero / (area * area);
        one_paper += count_one / (area * area);
        return;
    }
    int plus = area / 3;
    solve(area / 3, row, column);
    solve(area / 3, row, column + plus);
    solve(area / 3, row, column + plus * 2);

    solve(area / 3, row + plus, column);
    solve(area / 3, row + plus, column + plus);
    solve(area / 3, row + plus, column + plus * 2);

    solve(area / 3, row + plus * 2, column);
    solve(area / 3, row + plus * 2, column + plus);
    solve(area / 3, row + plus * 2, column + plus * 2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    int piece_of_paper;
    cin >> N;    
    for (int i = 0; i < N; i++)
    {
        vector<int> v;
        for (int j = 0; j < N; j++)
        {
            cin >> piece_of_paper;
            v.push_back(piece_of_paper);
        }
        paper.push_back(v);
    }
    solve(N, 0, 0);
    cout << minus_paper << '\n';
    cout << zero_paper << '\n';
    cout << one_paper << '\n';
}