#include <iostream>
#include <vector>
using namespace std;

// ���� ä���� ĭ���� �����ǥ (�־��� ĭ�� ���� �� �ִ� �װ��� ���)
const int coverType[4][3][2] = {
	{{0, 0}, {1, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}}
};

// vector<int> : �ڵ����� �޸𸮰� �Ҵ�Ǵ� 1���� �迭 template
// vector<vector<int>> : 2���� �迭
bool set(int board[][20], int y, int x, int type, int delta, int H, int W) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
			ok = false;
		}
			
		else if ((board[ny][nx] += delta) > 1) {
			ok = false;
		}
			
	}
	return ok;
}

int cover(int board[][20], int H, int W) {
	int y = -1, x = -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				//printf("[%d %d]", y, x);
				break;
			}
		}
		if (y != -1) break;
	}
	if (y == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; type++) {
		if (set(board, y, x, type, 1, H, W)) {
			ret += cover(board, H, W);
		}
		/*
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				cout << board[i][j];
			}
			cout << endl;
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cout << board[i][j];
			}
			cout << endl;
		}
		*/
		
		set(board, y, x, type, -1, H, W);
	}
	return ret;
}
int main() {

	int m, cnt = 0, H, W;
	char in;
	int board[50][20];

	cin >> m;
	while (1) {
		if (m == cnt) break;
		cin >> H >> W;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> in;
				if (in == '.') board[i][j] = 0;
				else if (in == '#') board[i][j] = 1;
			}
		}
		/*
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cout << board[i][j];
			}
			cout << endl;
		}
		*/
		
		cout << cover(board, H, W) << endl;
		
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 20; j++) {
				board[i][j] = 0;
			}
		}
		cnt++;
	}
	return 0;
}