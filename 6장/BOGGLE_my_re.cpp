// 4ms
// �޸����̼� ���� (������ȹ��)
#include <iostream>
#include <string.h>

using namespace std;

char map[5][5];			// board
int memory[10][5][5];	// memorization
string word;
int N, M;

// ���� ��ġ���� �����¿�/�밢���� ���� ���ڰ� �ִ��� Ȯ���ϴ� �Լ�
// ��ȯ�� - 0 : ��������X, 1 : ��������O, 2 : �ܾ �����ǿ� ������
int IsFind(int cur, int x, int y) {
	int find = 0;
	
	// basecase
	if (word.length() == cur) return 1;		// �ܾ��� ������ ���ڿ� �������� ��
	if (memory[cur][x][y] == 1) return 0;	// �̹� �ش� ���� �����¿�/�밢������ ���� ���ڰ� ���� ���� Ȯ�εǾ��� ��

	// �ݺ����� ����� �����¿�/�밢�� Ȯ��
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if ((i == 0 && j == 0) || (x + i < 0) || (x + i > 4) || (y + j < 0) || (y + j > 4)) continue;
			if (word[cur] == map[x + i][y + j]) {			// ���� ���ڰ� ���� ���
				find = IsFind(cur + 1, x + i, y + j);		// �� ���� ���� Ȯ���� ���� ��� ȣ��

				// �ܾ �����ǿ� �������� Ȯ������ ��
				if (find == 1 && cur == word.length() - 1) return 2;	
				if (find == 2) return 2;								
			}
		}
	}
	if (find == 0) memory[cur][x][y] = 1;
	return find;
}

// �ش�Ǵ� �ܾ �����ǿ� �����ϴ��� Ȯ���ϴ� �Լ�
void IsinWord() { 
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			if (word[0] == map[x][y] ){
				if (IsFind(1, x, y) == 2) {
					cout << word << " " << "YES" << endl;
					return;
				}
			}
		}
	}
	cout << word << " " << "NO" << endl;
}

int main() {
	

	cin >> N;
	while (1) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> map[i][j];
			}
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			memset(memory, 0, sizeof(memory));
			cin >> word;
			IsinWord();
		}
		if ((--N) == 0) break;
	}
}




