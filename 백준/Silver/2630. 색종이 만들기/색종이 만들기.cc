#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int total_count[3] = { 0 };
vector<vector<int>> color_paper;

bool is_all_same_paper(int area, int row, int column)  // 종이 같은지 확인
{
    for (int i = row; i < row + area; i++)
    {
        for (int j = column; j < column + area; j++)
        {
            if (color_paper[row][column] != color_paper[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
void solve(int area, int row, int column)
{
    if (is_all_same_paper(area, row, column))  // 종이 모두 같을 때
    {
        total_count[color_paper[row][column] + 1]++;
        return;
    }
    int half_area = area / 2;
    solve(half_area, row, column);   //1
    solve(half_area, row, column + half_area);  //2
    solve(half_area, row + half_area, column);  //3
    solve(half_area, row + half_area, column + half_area); //4
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    int color;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        vector<int> v;
        for (int j = 0; j < N; j++)
        {
            cin >> color;
            v.push_back(color);
        }
        color_paper.push_back(v);
    }
    solve(N, 0, 0);
    
    cout << total_count[1] << '\n';
    cout << total_count[2] << '\n';
}