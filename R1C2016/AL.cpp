#include <iostream>
#include <queue>

using namespace std;

struct node {
    int idx, val;
    node() {}
    node(int idx, int val) {
        this->idx = idx;
        this->val = val;
    }
};

struct cmp {
    bool operator()(node a, node b) {
        return a.val < b.val;
    }
};

priority_queue<node, vector<node>, cmp> pq;


int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T, N, Pi, total = 0;
    node n1, n2, n3;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ":";
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> Pi;
            total += Pi;
            pq.push(node(i, Pi));
        }
        while (!pq.empty()) {
            cout << " ";
            n1 = pq.top(); pq.pop();
            n2 = pq.top(); pq.pop();
            if ((pq.size() == 1 && n2.val == 1) || (n1.val - 1) * 2 > (total - 2)) {
                pq.push(n2);
                n1.val--;
                cout << (char)(n1.idx + 'A');
                if (n1.val > 0) {
                    n1.val--;
                    cout << (char)(n1.idx + 'A');
                }
                if (n1.val > 0) pq.push(n1);
            } else {
                n1.val--; n2.val--;
                cout << (char)(n1.idx + 'A') << (char)(n2.idx + 'A');
                if (n1.val > 0) pq.push(n1);
                if (n2.val > 0) pq.push(n2);
            }
        }
        cout << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
