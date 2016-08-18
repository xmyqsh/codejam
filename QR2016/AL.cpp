#include <iostream>
#include <vector>

using namespace std;
#define LL long long

vector<int> digits(10, 0);
int N, T;

void calc(LL& ret) {
    if (N == 0) return;
    LL n = 1, num;
    int cnt = 0, r;
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
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        fill(digits.begin(), digits.end(), 0);
        cin >> N;
        LL ret = -1;
        calc(ret);
        cout << "Case #" << t << ": ";
        if (ret == -1) cout << "INSOMNIA" << endl;
        else cout << ret << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
