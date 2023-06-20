#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<bool>> tree;
vector<string> number;

bool is_all_same_tree(int N, int row, int column)  // 해당 구역 일치 불일치 확인
{
    for (int i = row; i < row + N; i++)
    {
        for (int j = column; j < column + N; j++)
        {
            if (tree[row][column] != tree[i][j])
            {
                return false;  // 해당 사분면 모두 동일 숫자 아님
            }
        }
    }
    return true;  // 해당 사분면 모두 동일 숫자
}
void solve(int N, int row, int column)
{
    string str;
    if (is_all_same_tree(N, row, column))
    {
        if (tree[row][column] == true)
        {
            str = "1";
            number.push_back(str);
            return;
        }
        else
        {
            str = "0";
            number.push_back(str);
            return;
        }
    }
    else
    {
        str = "(";
        number.push_back(str);
        int half_area = N / 2;
        solve(half_area, row, column);   //1
        solve(half_area, row, column + half_area);  //2
        solve(half_area, row + half_area, column);  //3
        solve(half_area, row + half_area, column + half_area); //4
        str = ")";
        number.push_back(str);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    string tree_number;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        vector<bool> push_number;
        cin >> tree_number;
        for (int j = 0; j < N; j++)
        {
            if (tree_number[j] == '1')
            {
                push_number.push_back(true);
            }
            else
            {
                push_number.push_back(false);
            }
        }
        tree.push_back(push_number);
    }
    solve(N, 0, 0);
    for (int i = 0; i < number.size(); i++)
    {
        cout << number[i];
    }
}