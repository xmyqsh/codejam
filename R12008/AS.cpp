#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr1(10);
vector<int> arr2(10);

int main() {
    freopen("A-small-practice.in", "r", stdin);
    freopen("A-small-practice.out", "w", stdout);
    int T, n;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> arr1[i];
        for (int i = 0; i < n; ++i)
            cin >> arr2[i];
        sort(arr1.begin(), arr1.begin() + n);
        sort(arr2.begin(), arr2.begin() + n);
        int ret = 0;
        for (int p = 0, q = n - 1; p < n; ++p, --q)
            ret += arr1[p] * arr2[q];
        cout << "Case #" << t << ": " << ret << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
