#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj; // ���� ���
vector<string> graph[26][26]; // i�ν����� j�� �P���� �ܾ� ���
vector<int> indegree, outdegree;  // i�� �����ϴ� �ܾ� ��, ������ �ܾ� ��

// �Է� �׷����� ��ȯ
void makeGraph(const vector<string> &words) {
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			graph[i][j].clear();
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	indegree = outdegree = vector<int>(26, 0);
	for (int i = 0; i < words.size(); ++i) {
		int a = words[i][0] - 'a';
		int b = words[i][words[i].size() - 1] - 'a';
		graph[a][b].push_back(words[i]);
		adj[a][b]++;
		outdegree[a]++;
		indegree[b]++;
	}
}






// ���� �׷������� ���Ϸ� ��Ŷ/Ʈ���� ã��

// ���� �׷����� ������� adj�� �־��� �� ���Ϸ� ��Ŷ Ȥ�� Ʈ���� ���
void getEulerCircuit(int here, vector<int> &circuit) {
	for (int there = 0; there < adj[here].size(); ++there)
		while (adj[here][there] > 0) {
			adj[here][there]--;
			adj[there][here]--;
			getEulerCircuit(there, circuit);
		}
	circuit.push_back(here);
}
// ���� �׷����� ���Ϸ� Ʈ�����̳� ��Ŷ ��ȯ
vector<int> getEulerTrailOrCircit() {
	vector<int> circuit;
	// ���� Ʈ���� ã��
	for (int i = 0; i < 26; i++)
		if (outdegree[i] == indegree[i] + 1) {
			getEulerCircuit(i, circuit);
			return circuit;
		}
	// Ʈ������ �ƴ� ��� ��Ŷ
	for (int i = 0; i < 26; i++)
		if (outdegree[i]) {
			getEulerCircuit(i, circuit);
			return circuit;
		}
	// ��� ������ ��� �� �迭 ��ȯ
	return circuit;
}






// ������ ���Ϸ� Ʈ���Ϸ� �ٲ� �ذ��ϴ� �˰���

// ���� �׷����� ���Ϸ� ��Ŷ/Ʈ���� ���翩�� Ȯ��
bool checkEuler() {
	int plus1 = 0, minus1 = 0;
	for (int i = 0; i < 26; ++i) {
		int delta = outdegree[i] - indegree[i];
		if (delta < -1 || 1 < delta) return false;
		if (delta == 1) plus1++;
		if (delta == -1) minus1++;
	}
	return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}

string solve(const vector<string>& words) {
	makeGraph(words);
	if (!checkEuler()) return "IMPOSSIBLE";
	vector<int> circuit = getEulerTrailOrCircit();
	if(circuit.size()!=words.size()) return  "IMPOSSIBLE";

	reverse(circuit.begin(), circuit.end());
	string ret;
	for (int i = 0; i < circuit.size(); i++) {
		int a = circuit[i - 1], b = circuit[i];
		if (ret.size()) ret += " ";
		ret += graph[a][b].back();
		graph[a][b].pop_back();
	}
	return ret;
}