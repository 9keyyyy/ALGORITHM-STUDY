#include <iostream>
#include <algorithm>
using namespace std;

/*---------------------------------------------------------------------------------------------

	<	��ü���� �˰���	>
 1. ���� �迭 ��ġ���� ���������� �����ϸ鼭 ���� ũ�Ⱑ ���� ���뺸�� ���� ��찡 ���ö����� ����
 2. �Ȱ��� ������� �������� ����
 3. ���� ���� ���� ���� ���� �迭���� index +1 �� �Լ��� ���� �� ���ؼ� ū ������ ����

----------------------------------------------------------------------------------------------*/
int MaxSize(int *N, int size, int cur) {	// size : �Է¹��� ������, cur : ���� ��ġ
	int *p, area = 0;
	// base case : �Է¹��� size��ŭ �Լ��� �� ������ ��
	if (size == cur) return 0;
	for (p = N; p < N+size-cur; p++) {	// �迭�� ������ ������ ����
		if (*p >= *N) area += *N;
		else break;
	}
	if (cur != 0) {
		for (p = N-1; p >= N - cur; p--) {	// �迭�� ���� ������ ����
			if (*p >= *N) area += *N;
			else break;
		}
	}
	return max(area, MaxSize(++N, size, ++cur));	// ũ�� ��
}
int main() {
	int N[20000], n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++)
			cin >> N[j];
		int area = MaxSize(N, m, 0);
		cout << area << endl;
	}
	return 0;
}