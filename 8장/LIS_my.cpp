#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
/*------------------------------------------------------------------------------------------

		< ���� ������ �˰��� >

	1. ������ ������ �ε����� �������� �� ���� �� �κм����� ���� ���ϱ�
		��� ȣ���� ���� ���� ���� ���� ������ ū ���� �׷��� ���� ��� �� 
		�� ū ���� ��ȯ�ϴ� �������� MaxLength �Լ� ����
	2. ������ ��ȸ�ϸ� ���� �� �κ� ���� ���̸� ���� �� ã�� ���

	memorization : ���� �ε����� max�� ĳ�ÿ� ����

	28ms

-------------------------------------------------------------------------------------------*/
int cache[500];
int seq[500];
// n �ε����� �������� ���� �� �κ� ������ ���� ���ϴ� �Լ�
int MaxLength(int n, int next, int size) {
	// base case
	if (next == size) return 1;
	int &ret = cache[n];
	if (ret != -1) return ret;
	int tmp = 0;
	// ���� ���� ���� ������ ū ���
	if (seq[n] < seq[next]) tmp = 1 + MaxLength(next, next + 1, size);
	// result
	return ret = max(tmp, MaxLength(n, next + 1, size));
}
// ��ü �������� ���� �� �κ� ������ ���� ã�� �Լ�
int FindMax(int size) {
	int Max = 0;
	for (int i = 0; i < size; i++) {
		int tmp = MaxLength(i, i + 1, size);
		if (tmp > Max) Max = tmp;
	}
	return Max;
}
int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> m;
		for (int j = 0; j < m; j++) cin >> seq[j];
		cout << FindMax(m) << endl;
	}
	return 0;
}