#include <iostream>
#include <cstring>
using namespace std;
/*------------------------------------------------------------------------------------------

		< ���� ������ �˰��� >
 
		�ڡ����		������� 2X5 ũ���� �簢���� ������
		������		�� ��ġ���� �����ؼ�,

	1) ������		2) ������
	   ������          ������

	   �� �ΰ��� ���� ���� �� �ִ� ����� �� �ջ�
	   1�� ��쿡�� ù��°���� ����° ĭ���� �ε��� �̵��ؼ� �Ȱ��� 1 & 2�� �ݺ�
	   2�� ��쿡�� ù��°���� �ι�° ĭ���� �ε��� �̵��ؼ� �Ȱ��� 1 & 2�� �ݺ�

	   �ε����� ù��°���� �� ���� �����ϸ� ��� �� +1

	memorization : ���� �ε��� ��ġ������ ��� �� ĳ�ÿ� ����

	4ms

-------------------------------------------------------------------------------------------*/
int cache[2][100];
int s; 

int CountRec(int y, int x, int rec[][100]) {
	int sum = 0, tmprec[2][100];
	if (x > s - 1) return 0;	// base case

	int &ret = cache[y][x];			// memorization
	if (ret != -1) return ret;	

	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < s; j++) 
			tmprec[i][j] = rec[i][j];	
	if (rec[y + 1][x] == 0) { // case 1
		tmprec[y][x] = tmprec[y + 1][x] = 1;
		if (x == s - 1) sum = 1;
		else sum = CountRec(y, x + 1, tmprec);
	}
	if (x + 1 < s) {					// case 2
		if (rec[y][x + 1] == 0) {
			rec[y][x] = rec[y][x + 1] = 1;
			if (x + 1 == s - 1)	return ret = (sum + 1) % 1000000007;
			else sum += CountRec(y, x + 2, rec);
		}
	}
	return ret = sum % 1000000007;
}

int main() {
	int n, rec[2][100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		memset(cache, -1, sizeof(cache));
		memset(rec, 0, sizeof(rec));
		cin >> s;
		cout << CountRec(0, 0, rec) << endl;
	}
	return 0;
}