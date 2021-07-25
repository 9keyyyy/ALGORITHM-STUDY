// �����ϴ� ���ǿ� ����
// ���� Ž��
#include <iostream>
#include <vector>
#define MAX 100
#define INF 987654321
using namespace std;

int n; // ������ ��
double dist[MAX][MAX]; // �� ���ð��� �Ÿ� �����ϴ� �迭
// path: ���ݱ��� ���� ���
// visited: �� ������ �湮 ����
// currendLength: ���ݱ��� ���� ��� ����
// ������ ���õ��� ��� �湮�ϴ� ��ε� �� ���� ª�� ���� ���̸� ��ȯ�ϴ� �Լ�
double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {
	// basecase: ��� ���ø� �� �湮���� ���� ���۵��÷� ���ư��� ����
	if (path.size() == n)
		return currentLength + dist[path[0]][path[path.back()]];
	double ret = INF;	// �ſ� ū ������ �ʱ�ȭ
	for (int next = 0; next < n; next++) {
		if (visited[next]) continue;
		int here = path.back();
		path.push_back(next);
		visited[next] = true;
		// ������ ��θ� ���ȣ���� ���� �ϼ��ϰ� ���� ª�� ����� ���� ����
		double cand = shortestPath(path, visited, currentLength + dist[here][next]);
		ret = min(ret, cand);
		visited[next] = false;
		path.pop_back();
	}
	return ret;
}

