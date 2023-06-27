#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string word;
    int word_pos;
    cin >> word >> word_pos;
    cout << word[word_pos - 1];
}