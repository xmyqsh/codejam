#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int T, h, cnt;
    cin >> T;
    string str1, str2;
    for (int t = 1; t <= T; ++t) {
        cin >> str1 >> str2;
        int flag = 0;
        for (int i = 0; i < str1.length(); ++i) {
            if (flag == 1) {
                if (str1[i] == '?') str1[i] = '9';
                if (str2[i] == '?') str2[i] = '0';
            } else if (flag == -1) {
                if (str1[i] == '?') str1[i] = '0';
                if (str2[i] == '?') str2[i] = '9';
            } else { // flag == 0
                if (str1[i] == '?' && str2[i] == '?') {
                    str1[i] = '0';
                    str2[i] = '0';
                } else if (str1[i] == '?') {
                    str1[i] = str2[i];
                } else if (str2[i] == '?') {
                    str2[i] = str1[i];
                } else if (str1[i] < str2[i]) {
                    flag = 1;
                } else if (str1[i] > str2[i]) {
                    flag = -1;
                } else {
                    // str1[i] == str2[i]
                    // do nothing
                }
            }
        }
        cout << "Case #" << t << ": ";
        cout << str1 << " " << str2 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
