#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> iterms(101);
unordered_map<int, int> mp;

int main() {
    freopen("A-small-practice.in", "r", stdin);
    freopen("A-small-practice.out", "w", stdout);
    int N, C, I;
    cin >> N;
    for (int t = 1; t <= N; ++t) {
        mp.clear();
        cin >> C >> I;
        for (int i = 0; i < I; ++i) {
            cin >> iterms[i];
            mp[iterms[i]] = i;
        }
        int i = 0;
        for (; i < I; ++i) if (mp.count(C - iterms[i])) break;
        cout << "Case #" << t << ": " << i + 1 << " " << mp[C - iterms[i]] + 1 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
