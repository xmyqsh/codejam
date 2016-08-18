#include <iostream>
#include <string>

using namespace std;

void reverseWord(string& sentence, int i, int j) {
    while (i < j) swap(sentence[i++], sentence[j--]);
}

void reverseSentence(string& sentence) {
    int i = 0, j = -1;
    while (j != sentence.length()) {
        j = sentence.find_first_of(' ', i);
        if (j == string::npos) j = sentence.length();
        reverseWord(sentence, i, j - 1);
        i = j + 1;
    }
    reverseWord(sentence, 0, j - 1);
}

int main() {
    freopen("B-large-practice.in", "r", stdin);
    freopen("B-large-practice.out", "w", stdout);
    int N;
    string sentence;
    cin >> N;
    getline(cin, sentence);
    for (int i = 1; i <= N; ++i) {
        getline(cin, sentence);
        reverseSentence(sentence);
        cout << "Case #" << i << ": " << sentence << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
