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
    int N, K;
    queue<int> q;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }
    int count = 0;
    cout << '<';
    while (1)
    {
        count++;
        if (count != K)
        {
            q.push(q.front());
            q.pop();
        }
        else if (count == K)
        {
            cout << q.front();
            q.pop();
            if (q.empty() == 0)
            {
                cout << ", ";
            }
            else
            {
                break;
            }
            count = 0;
        }
    }
    cout << '>';
}