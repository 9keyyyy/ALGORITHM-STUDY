#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

/*------------------------------------------------------------------------------------------

		< ���� ������ �˰��� >

	memorization ����غ��� ������ ��� ����ؾ��� �� ���� �ȿͼ�,
	���� Ž�� ������� ��� ��� ���غ�

	���ϵ� ī�� ���Ͽ��� '*'�� ������ �� �߻� ������ ���� ����� ���� �ֱ� ������,
	 -> �ݺ����� ��� ȣ���� ���� �� ���� ���� ������ ��� ��� ��
	 -> ���ڿ��� ������ ��� �ݺ��� ����

	4ms

-------------------------------------------------------------------------------------------*/

int Check(char *card, char *name) {
	int ret = 0;
	// base case : ���ϵ�ī�� ���ϰ� ���ϸ� ���ڿ��� ��� ������ ��
	if (*card == '\0'&&*name == '\0') return 1;
	
	// 1. (���ϵ� ī�� ���� = ���ϸ�) Ȥ�� (���ϵ� ī�� ���� = '?') �� ��
	if (*card == *name || *card == '?') return ret = Check(++card, ++name);
	// 2. (���ϵ� ī�� ���� = '*') �� ��
	if (*card == '*') {
		while (*card == '*') ++card;
		if (*card == '\0') return 1;
		// ����� ���� �ɶ����� ��� ��츦 ���غ���, ���ϸ��� ���ڿ� ���� �������� ���� �ݺ��� Ż�� 
		while (ret != 1) {
			while (*name != *card) {
				if (*name == '\0') return -1;
				if (*card == '?') break;
				++name;
			}
			// �� ���� �ȳ����� ���� �����, ������ ���� �ε��� �� ���ϸ� ���ڿ� �ε��� (+1) �� �ּ� ���
			char *tmpcard = card, *tmpname = name + 1;
			// ������ '*' �������ڿ� ���� ���ϸ� ���ڰ� ���ٸ�, ��ͷ� ���� ���� ���� �Ѱ���
			ret = Check(++card, ++name);
			if (*name == '\0') break;
			card = tmpcard; name = tmpname;
		}
		return ret;
	}

	if (*card == '\0' || *name == '\0') return -1;
}
int main() {
	int n, m, cnt;
	char in[101], name[101], res[101][101];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		cin >> in;
		cin >> m;
		char tmp[101];
		strcpy(tmp, in);
		for (int j = 0; j < m; j++) {
			strcpy(in, tmp);
			cin >> name;
			if (Check(in, name) == 1) { 
				strcpy(res[cnt++], name); 
			}

		}
		// ����
		for (int j = 0; j < cnt; j++) {
			for (int k = j+1; k < cnt; k++) {
				if (strcmp(res[j], res[k]) > 0) {
					strcpy(tmp, res[j]);
					strcpy(res[j], res[k]);
					strcpy(res[k], tmp);
				}
			}
		}
		for (int j = 0; j < cnt; j++)
			cout << res[j] << endl;
	}
	return 0;
}