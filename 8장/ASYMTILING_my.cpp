#include <iostream>
#include <cstring>
using namespace std;
/*--------------------------------------------------------------------------------------------------

		< ���� ������ �˰��� >

	TILING2 �������� ��Ī�� �Ǵ� ����� ������ �� (�Լ��� sol �״�� ����ϰ� ���ο��� ó����)
	n�� ¦���϶� : (��ü �����) - (n/2 �簢�� �����) - (n/2-1 �簢�� �����)
	n�� Ȧ���϶� : (��ü �����) - (n/2 �簢�� �����)

	��ü ����� ���� 1000000007�� ������ ������ ����ϱ� ������, 
	���� ������ �Ǵ� ��� 1000000007�� �����ָ��

	0ms

---------------------------------------------------------------------------------------------------*/
const int MOD = 1000000007;
int cache[101];
int s;

int tiling(int width) {
	if (width <= 1) return 1;
	int &ret = cache[width];
	if (ret != -1) return ret;
	return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> s;

		if (s % 2 == 0) {
			int a = tiling(s) - tiling(s / 2) - tiling(s / 2 - 1);
			while (a < 0) a += MOD;
			cout << a << endl;
		}
		else {
			int a = tiling(s) - tiling(s / 2);
			if (a < 0) a += MOD;
			cout << a << endl;
		}
	}
	return 0;
}