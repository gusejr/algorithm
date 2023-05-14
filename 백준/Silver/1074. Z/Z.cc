#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int order_count = 0;
int board_size; // N^2 보드 크기
int r, c;  // 행 열

int divide(int board_side, int com_r, int com_c)
{
    if (board_side == 1)
    {
        return 1;
    }
    int half_side = board_side / 2;
    if (com_r < half_side && com_c < half_side)  // 1 사분면
    {
        return divide(half_side, com_r, com_c);
    }
    else if (com_r < half_side && com_c >= half_side)  // 2 사분면
    {
        order_count = order_count + (board_side * board_side / 4);
        return divide(half_side, com_r, com_c - half_side);
    }
    else if (com_r >= half_side && com_c < half_side)  // 3 사분면
    {
        order_count = order_count + (board_side * board_side / 4) * 2;
        return divide(half_side, com_r - half_side, com_c);
    }
    else if (com_r >= half_side && com_c >= half_side)  // 4 사분면
    {
        order_count = order_count + (board_side * board_side / 4) * 3;
        return divide(half_side, com_r - half_side, com_c - half_side);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    
    cin >> N >> r >> c;
    board_size = pow(2, N);
    divide(board_size, r, c);
    cout << order_count;
}