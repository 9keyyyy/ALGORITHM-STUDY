// ����Ž��
// 0 ms
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int card[100];

// M���� ũ�� �����鼭 M�� �� ����� �� ��ȯ�ϴ� �Լ�
int CompareNum(int a, int b) {
	if (a <= M && a > b)
		return a;
	else return b;
}

// �������� ���Ϸ��� ���� ã�� �Լ�
// max : ���Ϸ��� ��, Picked : ���ݱ��� �� ī����� �ε���, toPick : �� �����ϴ� ������ ��
int findMax(vector<int> &Picked, int toPick, int max) {
	// basecase
	if (toPick == 0)
		return CompareNum(card[Picked[0]] + card[Picked[1]] + card[Picked[2]], max);

	// �� �� �ִ� ���� ���� �ε��� ���
	int first = Picked.empty() ? 0 : Picked.back() + 1;

	// ī�� ����
	for (int next = first; next < N; next++) {
		Picked.push_back(next);
		max = findMax(Picked, toPick - 1, max);
		Picked.pop_back();
	}
	return max;
}
int main() {
	vector<int> Picked;
	int max = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> card[i];
	cout << findMax(Picked, 3, max);

}