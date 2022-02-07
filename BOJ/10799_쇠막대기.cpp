// 2022-02-08 BOJ 10799
// stack
// ��Ģ ã��
#include <iostream>
#include <stack>
using namespace std;

int main() {
	string str;
	stack<int> st;
	int num = 0;
	
	cin >> str;
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') 
			st.push(str[i]);
		// ')' �� ��
		else {	
			// ������ '('�� �־��ٸ� �������� ������ '('�� ������ ������ ������
			if (str[i-1] == '(') {	
				st.pop();
				num += st.size();
			}
			// ������ ')'�� �־��ٸ� ���� ���� -> ���������� ���� �κ� +1
			else {					
				st.pop();
				num++;
			}
		}
	}
	cout << num;
	return 0;
}