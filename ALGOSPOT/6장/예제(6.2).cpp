#include <iostream>
#include <vector>
using namespace std;
/********************************************/
// 1���� n���� ���� ��ȯ�ϴ� �Լ�

// ����͹���
int sum(int n) {
	int ret = 0;
	for (int i = 0; i <= n; i++) ret += i;
	return ret;
}
// ��͹���
int recursiveSum(int n) {
	if (n == 1) return 1;
	return n + recursiveSum(n - 1);
}
/********************************************/
// ��ø �ݺ��� ��ü�ϱ�

// ����� - 0���� ���ʴ�� ��ȣ �Ű��� n���� ���� �� �װ��� ���� ��� ��� ���
void selectFour(int n) {
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				for (int l = k + 1; l < n; l++)
					cout << i << " " << j << " " << k << " " << l << endl;
}
// ��� - n���� ���� �� m���� ���� ��� ������ ã�� �˰���
// n : ��ü ������ ��, picked : ���ݱ��� �� ���ҵ��� ��ȣ, toPick : �� �����ϴ� ������ ��
void pick(int n, vector<int>& picked, int toPick) {
	// basecase
	if (toPick == 0) {
		for (int i = 0; i < picked.size(); i++) cout << picked[i] << " ";
	}

	// ���� �ִ� ���� ���� ��ȣ ���
	int smallest = picked.empty() ? 0 : picked.back() + 1;

	// ���� ��
	for (int next = smallest; next < n; next++) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}
/********************************************/
int main() {
	vector<int> picked;
	pick(4, picked, 2);
}