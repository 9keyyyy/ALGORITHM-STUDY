#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
/*------------------------------------------------------------------------------------------

		< ���� ������ �˰��� >

	memorization ��� �����ؾ����� �������� �ʾƼ� ���� Ž���� �̿�
	���ڸ� 3, 4, 5 �ڸ��� ���� ��� ��� ����� ���� ���� ���̵��� �ջ�Ǵ� �� ���
		1. �ڸ��� 1 ~ 2 �� �� - case ���� ���� �ڸ����� �ѱ�� ��� �Լ� ȣ��
		2. �ڸ��� 3 ~ 4 �� �� - �ڸ��� 3, 4, 5 �� �� �� ���� ���� ���̵� ������ �� ã��
		3. �ڸ��� 5 �� �� - �ڸ��� 0 ���� ��� �Լ� ȣ���� ���ο� case �з��ϰԲ� ����

	... �ð��ʰ� ...

-------------------------------------------------------------------------------------------*/
//int cache[10000];
//int pi[10000];
string pi;
int s;

int levelSum(int n, int casenum, int order) {
//	int &sum = cache[n];
	int sum = 0;
	// base case
	if (n > s - 1) return sum = 0;
//	if (sum != -1) return sum;
	if (3 <= order && order <= 4) {	// �ڸ����� 3 ~ 4 �϶�
		if (casenum == 1) {	// case 1
			if (pi[n] == pi[n + 1]) 
				return sum = min(levelSum(n + 1, 1, order + 1), levelSum(n + 1, 0, 0));
			else return sum = levelSum(n + 1, 0, 0);
		}
		else if (casenum == 21) {	// case 2-1
			if (pi[n] + 1 == pi[n + 1]) 
				return sum = min(levelSum(n + 1, 21, order + 1), levelSum(n + 1, 0, 0));
			else return sum = levelSum(n + 1, 0, 0);
		}
		else if (casenum == 22) {	// case 2-2
			if (pi[n] - 1 == pi[n + 1]) 	
				return sum = min(levelSum(n + 1, 22, order + 1), levelSum(n + 1, 0, 0));
			else return sum = levelSum(n + 1, 0, 0);
		}
		else if (casenum == 3) {	// case 3
			if (pi[n + 1] == pi[n - 1])	
				return sum = min(levelSum(n + 1, 3, order + 1), levelSum(n + 1, 0, 0));
			else return sum = levelSum(n + 1, 0, 0);
		}
		else if (casenum == 4) {	// case 4
			if (pi[n] - pi[n + 1] == pi[n - 1] - pi[n]) 
				return sum = min(levelSum(n + 1, 4, order + 1), levelSum(n + 1, 0, 0));
			else return sum = levelSum(n + 1, 0, 0) ;
		}
		else if (casenum == 5)		// case 5
			return sum = min(levelSum(n + 1, 5, order + 1), levelSum(n + 1, 0, 0));
	}
	if (order == 5) {	// �ڸ��� 5 �� ��
		return sum = levelSum(n + 1, 0, 0);
	}
	else {	// �ڸ��� 1 ~ 2 �� ��
		if (n + 2 > s - 1) return sum = 1000000000; // �ڿ� ���� �ڸ����� ���
		if (pi[n] == pi[n + 1] && pi[n + 1] == pi[n + 2])	// case 1
			sum = 1 + levelSum(n + 2, 1, 3);
		else if (pi[n] + 1 == pi[n + 1] && pi[n + 1] + 1 == pi[n + 2])	// case 2-1
			sum = 2 + levelSum(n + 2, 21, 3);
		else if (pi[n] - 1 == pi[n + 1] && pi[n + 1] - 1 == pi[n + 2])	// case 2-2
			sum = 2 + levelSum(n + 2, 22, 3);
		else if (pi[n] == pi[n + 2])	// case 3
			sum = 4 + levelSum(n + 2, 3, 3);
		else if (pi[n] - pi[n + 1] == pi[n + 1] - pi[n + 2])	// case 4
			sum = 5 + levelSum(n + 2, 4, 3);
		else	// case 5
			return sum = 10 + levelSum(n + 2, 5, 3);
		return sum = min(sum, 10 + levelSum(n + 2, 5, 3));
	}
}
int main() {
	int n, in;
	cin >> n;
	for (int i = 0; i < n; i++) {
		//memset(cache, -1, sizeof(cache));
		cin >> pi;
		s = pi.size();
		cout << levelSum(0, 0, 0) << endl;
	}
	return 0;
}