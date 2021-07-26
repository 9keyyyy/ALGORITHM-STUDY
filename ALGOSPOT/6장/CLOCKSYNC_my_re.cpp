// ���� Ž��
// 1736ms
#include <iostream>
#include <string.h>
using namespace std;

int Switch[10][16] = {
	{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
	{1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
	{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};
int Clock[16];

// ��� �ð��� �ð��� 12������ Ȯ���ϴ� �Լ�
int isAllTwelve() {
	for (int i = 0; i < 16; i++) {
		if (Clock[i] != 12) return 0;
	}
	return 1;
}

int findtwelve(int n, int ret) {
	// basecase
	if (isAllTwelve()) return ret;
	if (n == 10) return -1;			// ����ġ�� 10�������� ����

	// �� ����ġ �� 0-3�� ������ ��� ����
	for (int num = 0; num < 4; num++) {
		for (int j = 0; j < 16; j++) {
			Clock[j] += 3 * Switch[n][j] * num;
			if (Clock[j] > 12) Clock[j] -= 12;
		}

		int res = findtwelve(n + 1, ret + num);
		if (res != -1) return res;

		for (int j = 0; j < 16; j++) {
			Clock[j] -= 3 * Switch[n][j] * num;
			if (Clock[j] < 3) Clock[j] += 12;
		}
	}
	return -1;
}

int main() {
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < 16; j++) cin >> Clock[j];
		cout << findtwelve(0, 0) << endl;
	}
}