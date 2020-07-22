#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*---------------------------------------------------------------------------

	... �ð��ʰ� ...

	<  ������ �˰���  >
	�� �迭�� ���̵� �迭�� 2�躸�� �۾��������� ��� ������ ������ ���..
	�ɰ��� �迭�鿡�� sum�� ����� ��ͷ� ��� �ջ�...

	FENCE sol ���� �������� �غôµ�,
	��������� ó������ ��ȸ�ϴ� �Ŷ� �ٸ��� ����...

----------------------------------------------------------------------------*/


int AllHug(char *idol, char *fan, int left, int right) {
	int sum = 0, idolsize = strlen(idol);
	if (idolsize * 2 > (right - left + 1)) {
		for (int i = left; i <= right - idolsize + 1; i++) {
			int len = 0, flag = 0;
			for (int j = i; j < i + strlen(idol); j++) {
				if (idol[len++] == 'M' && fan[j] == 'M') {
					flag = 1;
				}
			}
			if (flag == 0) sum += 1;
		}
	}
	else {
		int mid = (right - left) / 2;
		sum += AllHug(idol, fan, left, mid) + AllHug(idol, fan, mid + 1, right);
		for (int i = mid + 1; i != mid + idolsize; i++) {
			int len = idolsize - 1, flag = 0;
			for (int j = i; j > i - strlen(idol); j--) {
				if (idol[len--] == 'M' && fan[j] == 'M') {
					flag = 1;
				}
			}
			if (flag == 0) sum += 1;
		}
	}
	return sum;
}

int main() {
	int n;
	char fan[200001], idol[200001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> idol;
		cin >> fan;
		cout << AllHug(idol, fan, 0, strlen(fan) - 1) << endl;
	}
	return 0;
}
