// ���� Ž��
// 4ms
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> word;
vector<string> matched;
string wildcard;
int C, N;

int ismatched(string cur, int cidx, int widx) {
	// basecase : wildcard�� ���� �ܾ��� ���ڰ� ��� ���� �������� ��
	if (widx == wildcard.length() && cidx == cur.length()) return 1;

	// wildcard�� ���� ���ڰ� '*'�϶�
	if (wildcard[widx] == '*') {	
		if (widx == wildcard.length() - 1) return 1;
		if (wildcard[widx + 1] == '*') return ismatched(cur, cidx, widx + 1);
		int ret = 0;
		for (int i = cidx; i < cur.length(); i++) {
			if (wildcard[widx + 1] == cur[i] || wildcard[widx + 1] == '?') { 
				ret = ismatched(cur, i + 1, widx + 2);
			}
			if (ret == 1) return 1;
		}
		return ret;
	}
	// wildcard�� ���� ���ڰ� '?'�̰ų� ���ĺ��� ��
	else if (wildcard[widx] == '?' || wildcard[widx] == cur[cidx]) {
		return ismatched(cur, cidx + 1, widx + 1);
	}
	else return 0;
}

int main() {
	string w;
	cin >> C;
	for (int i = 0; i < C; i++) {
		word.clear();
		matched.clear();
		cin >> wildcard;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> w;
			word.push_back(w);
		}
		for (int j = 0; j < word.size(); j++) 
			if (ismatched(word[j], 0, 0)) matched.push_back(word[j]);
		
		sort(matched.begin(), matched.end());
		for (int j = 0; j < matched.size(); j++)
			cout << matched[j] << endl;
	}
}