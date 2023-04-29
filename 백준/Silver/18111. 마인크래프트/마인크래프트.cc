#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M, B;  // 세로 가로 인벤토리
    int ground_block = 0;
    int use_sec = 128000000, use_height = 0;  // 출력할 초, 높이
    int max_block = 1;
    int present_height = 0;
    vector<vector<int>> ground;
    cin >> N >> M >> B;
    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        for (int j = 0; j < M; j++)
        {
            cin >> ground_block;
            max_block = max(max_block, ground_block);
            temp.push_back(ground_block);
        }
        ground.push_back(temp);
    }
    for (int present_height = max_block; present_height >= 0; present_height--)
    {
        int fill_block = 0;  // 채우기 fill
        int count_height_d = 0;  // 파내기 dig
        for (int i = 0; i < N; i++)  // 행
        {
            for (int j = 0; j < M; j++)  // 열
            {
                if (present_height < ground[i][j])
                {
                    count_height_d = count_height_d + (ground[i][j] - present_height); // 현재 높이까지 파내기
                }
                else if (present_height > ground[i][j])
                {
                    fill_block = fill_block + (present_height - ground[i][j]); // 쌓기
                }
            }
        }
        int inventory = B + count_height_d;  // 파낸 블럭 인벤토리에 넣기
        int spent_sec = (count_height_d * 2) + fill_block;  // 소모한 시간의 합, 파내기 시간 + 쌓기 시간
        if (fill_block <= inventory)  // 사용한 블럭의 개수가 인벤토리 개수보다 적을 때
        {
            if (spent_sec < use_sec)
            {
                use_height = present_height;
                use_sec = spent_sec;
            }
        }
    }
    cout << use_sec << " " << use_height;
}
