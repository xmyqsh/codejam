#include <iostream>
#include <vector>

using namespace std;

vector<int> digits(10, 0);
int N, T;

void calc(int& ret) {
    if (N == 0) return;
    int n = 1, cnt = 0, num, r;
    while (cnt < 10) {
        num = n * N;
        while (num) {
            r = num % 10;
            if (!digits[r]) {
                digits[r] = 1;
                ++cnt;
            }
            num /= 10;
        }
        ++n;
    }
    ret = (n - 1) * N;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        fill(digits.begin(), digits.end(), 0);
        cin >> N;
        int ret = -1;
        calc(ret);
        cout << "Case #" << t << ": ";
        if (ret == -1) cout << "INSOMNIA" << endl;
        else cout << ret << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
