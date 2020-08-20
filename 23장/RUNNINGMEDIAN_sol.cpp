#include <iostream>
#include <queue>
using namespace std;

/*
	�켱���� ť ��� (heap�� ����)
	�ִ���� ������ �� Max Heap, �ּҺ��� ������ �� Min Heap�̶�� ��
	Maxheap, Minheap ������ Maxheap���� �׻� �߰����� pop�� �� �ֵ��� ����
	Minheap���� �߰��� ���ĺ����� �� ����, Maxheap���� �߰��� �Ʒ��� �� ����
*/

struct RNG {
	int seed, a, b;
	RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
	int next() {
		int ret = seed;
		seed = ((seed * (long long)a) + b) % 20090711;
		return ret;
	}
};
int runningMedian(int n, RNG rng) {
	// �켱���� ť : < datatype, container type, ���ı��� >
	priority_queue<int, vector<int>, less<int>> maxHeap; // ū�ͺ��� pop
	priority_queue<int, vector<int>, greater<int>> minHeap; // �����ͺ��� pop
	int ret = 0;
	for (int cnt = 1; cnt <= n; ++cnt) {
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(rng.next());
		else
			minHeap.push(rng.next());
		if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop(); minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}
		ret = (ret + maxHeap.top()) % 20090711;
	}
	return ret;
}
/*
int runningMedian(int n, RNG rng) {
	Node *root = NULL;
	int ret = 0;
	for (int cnt = 1; cnt <= n; ++cnt) {
		root = insert(root, new Node(rng.next()));
		int median = kth(root, (cnt + 1) / 2)->key;
		ret = (ret + median) % 20090711;
		return ret;
	}
}
*/
