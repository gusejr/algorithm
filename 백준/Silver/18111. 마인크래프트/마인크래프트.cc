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
    int use_sec = 128000000, use_height = 0, comp_height = 0;  // 출력할 초, 높이
    int min_block = 500, max_block = 1;
    int present_height = 0;
    vector<vector<int>> ground;
    cin >> N >> M >> B;
    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        for (int j = 0; j < M; j++)
        {
            cin >> ground_block;

            min_block = min(min_block, ground_block);
            max_block = max(max_block, ground_block);
            temp.push_back(ground_block);
        }
        ground.push_back(temp);
    }
    present_height = max_block;
    int p = max_block + 1;
    while (p != 0)  // 블럭의 최대 높이로 전체 루프 예정
    {
        int inventory = B;
        int count_height_f = 0, count_sec_f = 0;  // 채우기 fill
        int count_height_d = 0, count_sec_d = 0;  // 파내기 dig
        int spent_block = 0, spent_sec = 0;  //사용한 블럭 개수, sec
        if (max_block != present_height && present_height > -1)
        {
            for (int i = 0; i < N; i++)  // 행
            {
                for (int j = 0; j < M; j++)  // 열
                {
                    if (present_height <= ground[i][j])
                    {
                        count_height_d = count_height_d + (ground[i][j] - present_height); // 현재 높이까지 파내기
                    }
                }
            }
            count_sec_d = count_height_d * 2; // 파내기 시간
        }
        if (present_height > -1)
        {
            for (int i = 0; i < N; i++)  // 행
            {
                for (int j = 0; j < M; j++) // 열
                {
                    if (present_height >= ground[i][j])
                    {
                        count_height_f = count_height_f + (present_height - ground[i][j]); // 쌓기
                    }
                }
            }
            count_sec_f = count_height_f;  // 쌓기 시간
        }
        inventory = inventory + count_height_d;
        spent_block = count_height_f;  //쌓는데 사용한 블럭 개수
        spent_sec = count_sec_d + count_sec_f;  // 소모한 시간의 합
        if (spent_block <= inventory)  // 사용한 블럭의 개수가 인벤토리 개수보다 적을 때
        {
            if (spent_sec < use_sec)  // 최소 사용 시간
            {
                use_height = present_height;
                use_sec = spent_sec;
            }
            else if (spent_sec == use_sec)
            {
                if (use_height < present_height)
                {
                    use_height = present_height;
                    use_sec = spent_sec;
                }
            }
        }
        present_height = present_height - 1;
        p--;
    }
    cout << use_sec << " " << use_height;
}
