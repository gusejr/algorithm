#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool sort_num(const pair<int, int> a, const pair<int, int> b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	return a.first > b.first;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, median = 0, mode = 0, range = 0; // 산술평균, 중앙값, 최빈값, 법위
	double arithmetic_mean = 0, number; // N 홀수 입력, number -> -4000 ~ 4000
	vector<int> save, count_num(8001, 0);
	vector<pair<int, int>> save_mode;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> number;
		save.push_back(number);
	}
	sort(save.begin(), save.end());
	double total = 0;
	for (int i = 0; i < N; i++)
	{
		total = total + save[i];
		count_num[save[i] + 4000]++; // 동일한 숫자 카운트
	}
	arithmetic_mean = round(total / save.size());  // 산술평균
	if (arithmetic_mean == -0)
	{
		arithmetic_mean = abs(arithmetic_mean);
	}
	if (N != 1)  // 중앙값
	{
		median = N /2;
		median = save[median];
	}
	else
	{
		median = save[0];
	}
	int max_count = 0, max_count_num = 0;
	for (int i = 0; i < 8001; i++)
	{
		if (count_num[i] != 0)
		{
			save_mode.push_back(make_pair(count_num[i], i)); // 동일한 수 카운트 값, i 값
		}
	}
	sort(save_mode.begin(), save_mode.end(), sort_num);
	if (N == 1)
	{
		mode = save_mode[0].second - 4000;
	}
	else if (save_mode[0].first == save_mode[1].first)
	{
		mode = save_mode[1].second - 4000;
	}
	else
	{
		mode = save_mode[0].second - 4000;
	}
	if (N != 1)
	{
		range = save[N - 1] - save[0];  // 범위
	}
	else
	{
		range = 0;
	}
	cout << arithmetic_mean << '\n' << median << '\n'<< mode << '\n' << abs(range);  // 산술평균 중앙값 최빈값 범위
}