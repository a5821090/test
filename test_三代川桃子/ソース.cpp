#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int n;
    const int MAX_PEOPLE = 100;
    int scores[MAX_PEOPLE][2];

    // �t�@�C�����J��
    ifstream file("test.txt");
    if (!file.is_open()) {
        cerr << "�t�@�C�����J���܂���ł���" << endl;
        return 1;
    }

    // 1�s�ڂ̐�����l���Ƃ���n�Ɋi�[����
    string line;
    if (!getline(file, line)) {
        cerr << "�t�@�C������̓��̓G���[" << endl;
        return 1;
    }
    n = stoi(line);

    // 2�s�ڈȍ~�̐�����score�z��Ɋi�[����
    for (int i = 0; i < n; i++) {
        if (!getline(file, line)) {
            cerr << "�t�@�C������̓��̓G���[" << endl;
            return 1;
        }
        istringstream iss(line);
        if (!(iss >> scores[i][0] >> scores[i][1])) {
            cerr << "�t�@�C������̓��̓G���[" << endl;
            return 1;
        }
    }

    // �t�@�C�������
    file.close();

    // �i�[���ꂽ�_����\������
    cout << "�e���k�̓_��:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": ���ԓ_=" << scores[i][0] << ", �����_=" << scores[i][1] << endl;
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
