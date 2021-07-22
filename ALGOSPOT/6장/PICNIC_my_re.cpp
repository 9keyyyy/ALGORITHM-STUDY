// ���� Ž��
// 4ms
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int C, N, M;
int isPair[10];			// �л��� ���õǾ����� ���θ� ��Ÿ�� (0 : ����X, 1 : ����O)
int isFriend[45][2];	// �Է¹��� ģ�� pair���� �迭
int sum = 0;

// n : �� ģ�� pair ��, picked : ���ݱ��� ���õ� ģ��pair(isFriend)�� �ε���, toPick : �� ���� �� ģ��pair�� ��
void pickPair(int n, vector<int>& picked, int toPick) {	
	// basecase
	if (toPick == 0) sum++;

	// ���� ���� �ε������� ����
	int smallest = picked.empty() ? 0 : picked.back() + 1;

	// ģ�� pair ����
	for (int next = smallest; next < n; next++) {
		// �� ���� ģ��pair�� ��� ���õ��� �ʾ��� ��쿡�� ������
		if (isPair[isFriend[next][0]] == 0 && isPair[isFriend[next][1]] == 0) {
			isPair[isFriend[next][0]] = 1; isPair[isFriend[next][1]] = 1;
			picked.push_back(next);
			pickPair(n, picked, toPick - 1);
			isPair[isFriend[picked.back()][0]] = 0; isPair[isFriend[picked.back()][1]] = 0;
			picked.pop_back();
		}
	}
}

int main() {
	vector<int> picked;

	cin >> C; 
	for (int i = 0; i < C; i++) {
		cin >> N >> M;
		memset(isFriend, 0, sizeof(isFriend));
		memset(isPair, 0, sizeof(isPair));
		sum = 0;
		for (int j = 0; j < M; j++)
			cin >> isFriend[j][0] >> isFriend[j][1];
		pickPair(M, picked, N/2);
		cout << sum << endl;
	}
}