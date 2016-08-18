#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> iterms(4001);

int main() {
    freopen("A-large-practice.in", "r", stdin);
    freopen("A-large-practice.out", "w", stdout);
    int N, C, I;
    cin >> N;
    for (int t = 1; t <= N; ++t) {
        unordered_map<int, int> mp;
        cin >> C >> I;
        for (int i = 0; i < I; ++i) {
            cin >> iterms[i];
            mp[iterms[i]] = i;
        }
        int i = 0;
        for (; i < I; ++i) {
            if (mp.count(C - iterms[i]) && i != mp[C - iterms[i]]) break;
        }
        cout << "Case #" << t << ": " << i + 1 << " " << mp[C - iterms[i]] + 1 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
