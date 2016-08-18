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
vector<int> K;
/*
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
*/

bool doubleCheck(const vector<int>& copyCharCnt) {
    for (int i = 0; i < 26; ++i)
        if (copyCharCnt[i] != 0)
            return false;
    return true;
}

void printPath(const vector<int>& path) {
    vector<int> copyPath(path);
    sort(copyPath.begin(), copyPath.end());
    for (int i = 0; i < copyPath.size(); ++i)
        cout << copyPath[i];
}

void dfs(vector<int> copyCharCnt, vector<int>& path, int curCnt, int curH, int targetCnt, int targetH, int curI, bool& flag) {
    if (flag) return;
    for (int i = 0; i < 26; ++i) {
        if (copyCharCnt[i] < 0)
            return;
    }
    if (curCnt > targetCnt) return;
    if (curCnt == targetCnt) {
        if (curH != targetH) return;
        if (doubleCheck(copyCharCnt)) {
            flag = true;
            printPath(path);
            return;
        }
    }
    for (int k = curI, i = K[k]; k < 10; ++k, i = K[k]) {
        path.push_back(i);
        string str = mp[i].str;
        for (int j = 0; j < str.length(); ++j)
            copyCharCnt[str[j] - 'A']--;
        dfs(copyCharCnt, path, curCnt + mp[i].cnt, curH + mp[i].h, targetCnt, targetH, k, flag);
        for (int j = 0; j < str.length(); ++j)
            copyCharCnt[str[j] - 'A']++;
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

    K.push_back(8);
    K.push_back(3);
    K.push_back(0);
    K.push_back(4);
    K.push_back(6);
    K.push_back(2);
    K.push_back(5);
    K.push_back(7);
    K.push_back(9);
    K.push_back(1);
    K.push_back(10);
}

int main() {
    freopen("A-large-practice.in", "r", stdin);
    freopen("A-large-practice.out", "w", stdout);
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
        dfs(charCnt, path, 0, 0, cnt, h, 0, flag);
        cout << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
