#include <iostream>
#include <list>
using namespace std;

void josephus(int n, int k) {
	list<int> survivors;
	for (int i = 0; i <= n; i++) survivors.push_back(i);
	list<int>::iterator kill = survivors.begin();
	while (n > 2) {
		// erase�� ���� ������ ���� ���� ��ȯ
		kill = survivors.erase(kill);
		if (kill == survivors.end()) kill = survivors.begin(); //end�� ������ ��� ������ ����Ŵ
		--n;
		for (int i = 0; i < k - 1; i++) {
			++kill;
			if (kill == survivors.end()) kill = survivors.begin();
		}
	}
	cout << survivors.front() << " " << survivors.back() << endl;
}