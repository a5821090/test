#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int n;
    const int MAX_PEOPLE = 100;
    int scores[MAX_PEOPLE][2];

    // ファイルを開く
    ifstream file("test.txt");
    if (!file.is_open()) {
        cerr << "ファイルを開けませんでした" << endl;
        return 1;
    }

    // 1行目の数字を人数としてnに格納する
    string line;
    if (!getline(file, line)) {
        cerr << "ファイルからの入力エラー" << endl;
        return 1;
    }
    n = stoi(line);

    // 2行目以降の数字をscore配列に格納する
    for (int i = 0; i < n; i++) {
        if (!getline(file, line)) {
            cerr << "ファイルからの入力エラー" << endl;
            return 1;
        }
        istringstream iss(line);
        if (!(iss >> scores[i][0] >> scores[i][1])) {
            cerr << "ファイルからの入力エラー" << endl;
            return 1;
        }
    }

    // ファイルを閉じる
    file.close();

    // 格納された点数を表示する
    cout << "各生徒の点数:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": 中間点=" << scores[i][0] << ", 期末点=" << scores[i][1] << endl;
    }

    for (int j = 0; j < n; j++) {
        if ((scores[j][0] + scores[j][1] <= 100) && (scores[j][1] <= 60)) {
            printf("fail\n");
        }
        else if ((scores[j][0] + scores[j][1] <= 100) || (scores[j][1] <= 60)) {
            printf("reexamination\n");
        }
        else {
            printf("pass\n");
        }
    }

    return 0;
}
