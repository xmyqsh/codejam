#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node {
    int h, cnt;
    string str;
    node() {
        this->h = 0;
        this->cnt = 0;
        this->str = "";
    }
};

vector<node> mp(10);
vector<int> charCnt(30, 0);

bool doubleCheck(const vector<int>& path) {
    vector<int> copyCharCnt(charCnt);
    for (int i = 0; i < path.size(); ++i) {
        string str = mp[path[i]].str;
        for (int j = 0; j < str.length(); ++j) {
            copyCharCnt[str[j] - 'A']--;
        }
    }
    for (int i = 0; i < 26; ++i)
        if (copyCharCnt[i] != 0)
            return false;
    return true;
}

void printPath(const vector<int>& path) {
    for (int i = 0; i < path.size(); ++i)
        cout << path[i];
}

void dfs(vector<int>& path, int curCnt, int curH, int targetCnt, int targetH, int curI, bool& flag) {
    if (flag) return;
    if (curCnt > targetCnt) return;
    if (curCnt == targetCnt) {
        if (curH != targetH) return;
        if (doubleCheck(path)) {
            flag = true;
            printPath(path);
            return;
        }
    }
    for (int i = curI; i < 10; ++i) {
        path.push_back(i);
        dfs(path, curCnt + mp[i].cnt, curH + mp[i].h, targetCnt, targetH, i, flag);
        path.pop_back();
    }
}

void numHash(const string& str, int num) {
    mp[num].h = 0;
    for (int i = 0; i < str.length(); ++i)
        mp[num].h += str[i] - 'A';
    mp[num].cnt = str.length();
    mp[num].str = str;
}

void strHash(const string& str, int& h, int& cnt) {
    h = 0;
    fill(charCnt.begin(), charCnt.end(), 0);
    for (int i = 0; i < str.length(); ++i) {
        h += str[i] - 'A';
        charCnt[str[i] - 'A']++;
    }
    cnt = str.length();
}

void preProc() {
    string str;
    str = "ZERO";
    numHash(str, 0);
    str = "ONE";
    numHash(str, 1);
    str = "TWO";
    numHash(str, 2);
    str = "THREE";
    numHash(str, 3);
    str = "FOUR";
    numHash(str, 4);
    str = "FIVE";
    numHash(str, 5);
    str = "SIX";
    numHash(str, 6);
    str = "SEVEN";
    numHash(str, 7);
    str = "EIGHT";
    numHash(str, 8);
    str = "NINE";
    numHash(str, 9);
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    vector<int> path;
    preProc();
    int T, h, cnt;
    cin >> T;
    string str;
    for (int t = 1; t <= T; ++t) {
        cin >> str;
        strHash(str, h, cnt);
        cout << "Case #" << t << ": ";
        path.clear();
        bool flag = false;
        dfs(path, 0, 0, cnt, h, 0, flag);
        cout << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
