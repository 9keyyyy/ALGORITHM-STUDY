// 2022-02-08
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, num;
	vector<int> arr;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++) 
		cout << arr[i] << '\n';
	// '\n' ��� endl ����� ��� �ð��ʰ�
	// endl�� ����Ҷ����� ���۸� ���
	return 0;
}
