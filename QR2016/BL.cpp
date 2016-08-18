#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int T;
string input;
vector<int> S(101);

void flip(int e) {
    for (int i = 0; i < e; ++i) {
        if (S[i] == 1) S[i] = 0;
        else S[i] = 1;
    }
}

void calc(int& ret, int e) {
    int i = 0;
    while (i < e && S[i] == 1) ++i;
    if (i > 0) {
        flip(i);
        ++ret;
    }
    reverse(S.begin(), S.begin() + e);
    flip(e);
    ++ret;
    i = e - 1;
    while (i >= 0 && S[i] == 1) --i;
    if (i < 0) return;
    calc(ret, i + 1);
}

int main() {
    freopen("B-Large.in", "r", stdin);
    freopen("B-Large.out", "w", stdout);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> input;
        int i = input.length() - 1;
        while (i >= 0 && input[i] == '+') --i;
        if (i < 0) {
            cout << "Case #" << t << ": " << 0 << endl;
            continue;
        }
        for (int j = 0; j <= i; ++j) {
            if (input[j] == '+') S[j] = 1;
            else S[j] = 0;
        }
        int ret = 0;
        calc(ret, i + 1);
        cout << "Case #" << t << ": " << ret << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
