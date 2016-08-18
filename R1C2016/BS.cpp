#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int maxn = 8;
vector<vector<int> > mp(maxn, vector<int>(maxn, 0));
vector<vector<int> > ans;

void search(vector<vector<int> > & ans, vector<int> & temp, int n, int last, int step, int k) {
	if (step == k) {
		ans.push_back(temp);
		return;
	}
	for (int i = last + 1; i <= n; ++i) {
		temp.push_back(i);
		search(ans, temp, n, i, step + 1, k);
		temp.pop_back();
	}
}

void combine(int n, int k) {
	vector<int> temp;
	search(ans, temp, n, 0, 0, k);
}

void initMp(int N) {
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            mp[i][j] = 0;
}

int main() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    int T, B, M, cnt;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        cin >> B >> M;
        if (pow(2, B - 2) < M) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        cout << "POSSIBLE" << endl;
        initMp(B);
        cnt = 0;
        for (int i = 0; i <= B - 2 && cnt < M; ++i) {
            ans.clear();
            combine(B - 2, i);
            //cnt += ans.size();
            for (int j = 0; cnt < M && j < ans.size(); ++j) {
                if (ans[j].empty()) {
                    mp[1][B] = 1;
                    ++cnt;
                    continue;
                }
                int from = 1, to;
                for (int k = 0; k < ans[j].size(); ++k) {
                    to = ans[j][k] + 1;
                    mp[from][to] = 1;
                    from = to;
                }
                mp[from][B] = 1;
                ++cnt;
            }
        }
        for (int i = 1; i <= B; ++i) {
            for (int j = 1; j < B; ++j) cout << mp[i][j];
            cout << mp[i][B] << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
