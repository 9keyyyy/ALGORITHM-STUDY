#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
/*-------------------------------------------------------------------------------------------------------------------------------------

		< ���� ������ �˰��� >

	C++ STL queue �̿�
	queue�� ���� ���� K �̸��� �ǵ��� �κм��� ����
	���� ���� K �̻��� ��
	1. ���� ���� K���� Ŭ ��: queue ���Ҹ� pop�ؼ� ���� K ���� �۰� �����, �� �������� ���� K�� �Ǵ� ��� total �� +1
	2. ���� ���� K�� ��: total �� +1 �ϰ�, ���� ���� queue ���Ҹ� pop�ؼ� ���� K���� �۾������� ����

	���� �������� ���� �߻� (pow ����X) ---> �� �״�� ������ �ȵǰ� ���� ���� �� ���� ��������,,,

	4140ms

--------------------------------------------------------------------------------------------------------------------------------------*/
// int A[50000000];
struct RNG {
	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};
int SumK(int n, int K) {
	int sum = 0, total = 0;
	queue<int> q;
	RNG rng;
	for (int i = 0; i < n; i++) {
		//sum += A[i];
		//q.push(A[i]);
		int A = rng.next();
		sum += A;
		q.push(A);
		if (sum >= K) {
			if (sum == K) total += 1;
			while (sum >= K) {
				sum -= q.front();
				q.pop();
				if (sum == K) total += 1;
			}
		}
	}
	return total;
}
int main() {
	int n, K, N, a = pow(2, 32);
//	A[0] = 1983;
//	for (int i = 1; i < 50000000; i++)
//		A[i] = (A[i - 1] * 214013 + 2531011) % a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> K >> N;
		cout << SumK(N, K) << endl;

	}
	return 0;
}