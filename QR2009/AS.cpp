#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int> > flag(11, vector<int>(26));
vector<string> dict(26);

int main() {
    freopen("A-small-practice.in", "r", stdin);
    freopen("A-small-practice.out", "w", stdout);
    int L, D, N;
    cin >> L >> D >> N;
    for (int i = 0; i < D; ++i)
        cin >> dict[i];
    for (int i = 1; i <= N; ++i) {
        string str;
        cin >> str;
        int k = 0;
        for (int j = 0; j < L; ++j) {
            fill(flag[j].begin(), flag[j].end(), 0);
            if (islower(str[k])) {
                flag[j][str[k] - 'a'] = 1;
                ++k;
            } else {
                ++k;
                while (str[k] != ')') {
                    flag[j][str[k] - 'a'] = 1;
                    ++k;
                }
                ++k;
            }
        }
        int cnt = 0;
        for (int k = 0; k < D; ++k) {
            int j = 0;
            for (; j < L; ++j)
                if (flag[j][dict[k][j] - 'a'] != 1) break;
            if (j == L) ++cnt;
        }
        cout << "Case #" << i << ": " << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);
}
