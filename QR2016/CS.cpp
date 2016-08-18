#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
#define ULL unsigned long long

vector<int> bin(18);
vector<ULL> factors(11);
int T, N, J;

int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
int aSize = 12;

ULL mod_mul(ULL a, ULL b, ULL n) {
    ULL ret = 0;
    while (b) {
        if (b & 1) ret = (ret + a) % n;
        b >>= 1;
        a = (a + a) % n;
    }
    return ret;
}

ULL mod_exp(ULL a, ULL b, ULL n) {
    ULL ret = 1;
    while (b) {
        if (b & 1) ret = mod_mul(ret, a, n);
        b >>= 1;
        a = mod_mul(a, a, n);
    }
    return ret;
}

bool MR(ULL n) {
    if (n <= 2) {
        if (n == 2) return true;
        return false;
    }
    if (!(n % 2)) return false;
    ULL u = n - 1;
    while (!(u % 2)) u /= 2;
    for (int i = 0; i < aSize; ++i) {
        if (a[i] >= n) continue;
        ULL x = mod_exp(a[i], u, n);
        while (u < n) {
            ULL y = mod_exp(x, 2, n);
            if (y == 1 && x != 1 && x != n - 1) return false;
            x = y;
            u *= 2;
        }
        if (x != 1) return false;
    }
    return true;
}

void binPlusOne() {
    int carry = 1;
    for (int i = N - 2; carry && i > 0; --i) {
        int sum = bin[i] + carry;
        bin[i] = sum % 2;
        carry = sum / 2;
    }
}

ULL bin2Num(int base) {
    ULL ret = 0;
    for (int i = 0; i < N; ++i) {
        ret = ret * base + bin[i];
    }
    return ret;
}

ULL findFactor(ULL num) {
    ULL i = 2;
    while (num % i) ++i;
    return i;
}

void printOneRet() {
    for (int i = 0; i < N; ++i)
        cout << bin[i];
    cout << " ";
    for (int b = 2; b < 10; ++b)
        cout << factors[b] << " ";
    cout << factors[10] << endl;
}

void calc() {
    fill(bin.begin(), bin.begin() + N, 0);
    bin[0] = 1;
    bin[N - 1] = 1;
    for (int i = 0; i < J; ) {
        int cnt = 0;
        for (int b = 2; b <= 10; ++b) {
            ULL num = bin2Num(b);
            if (MR(num)) break;
            ++cnt;
            factors[b] = findFactor(num);
        }
        if (cnt == 9) {
            ++i;
            printOneRet();
        }
        binPlusOne();
    }
}

int main() {
    freopen("C-small-attempt2.in", "r", stdin);
    freopen("C-small-attempt2.out", "w", stdout);
    cin >> T >> N >> J;
    cout << "Case #1:" << endl;
    calc();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
