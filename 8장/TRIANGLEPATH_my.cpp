#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
/*-----------------------------------------------------------------------------

		< ���� ������ �˰��� >

	JUMPGAME ������ ����� �˰���
	memorization : ��������� max�� ĳ�ÿ� ����

	44ms

-----------------------------------------------------------------------------*/
int cache[100][100];
int board[100][100];
int FindMax(int y, int x, int size) {
	if (y == size || x == size) return 0;
	int &ret = cache[y][x];
	if (ret != -1) return ret;
	return ret = max(board[y][x] + FindMax(y + 1, x + 1, size), board[y][x] + FindMax(y + 1, x, size));
}
int main() {
	int n, m, cnt;
	cin >> n;
	for (int i = 0; i < n; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> m;
		for (int j = 0; j < m; j++) {
			for (int k = 0; k <= j; k++) {
				cin >> board[j][k];
			}
		}
		cout << FindMax(0, 0, m) << endl;
	}
	return 0;
}