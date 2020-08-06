#include <iostream>
using namespace std;
/*--------------------------------------------------------------------------------------------

		< ���� ������ �˰��� >

	���Ḯ��Ʈ�� ����
	MakeCircle : ���� ���Ḯ��Ʈ ������ִ� �Լ�
	DeleteNode : 2�� ���������� Ư�� ���κ��� K��° ������ ��� �����ϴ� �Լ�

	44ms

---------------------------------------------------------------------------------------------*/
typedef struct node {
	int elem;
	struct node *next;
	struct node *prev;
}NODE;
NODE *getnode(int elem) {
	NODE *p = (NODE *)malloc(sizeof(NODE));
	p->elem = elem;
	p->next = NULL;
	p->prev = NULL;
	return p;
}
NODE* MakeCircle(NODE *q, int n) {
	NODE *tmp = q;
	for (int i = 2; i <= n; i++) {
		NODE *p = getnode(i);
		q->next = p;
		p->prev = q;
		q = q->next;
	}
	q->next = tmp;
	tmp->prev = q;
	return tmp;
}
NODE* DeleteNode(NODE *q, int n, int k) {
	NODE *p, *tmp;
	for (int i = n; i > 2; i--) {
		tmp = q; p = q->next;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		for (int j = 0; j != k - 1; j++) p = p->next;
		free(tmp);
		q = p;
	}
	return q;
}
int main() {
	int n, N, K;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> N >> K;
		NODE *p = getnode(1);
		p = MakeCircle(p, N);
		p = DeleteNode(p, N, K);
		if (p->elem < p->next->elem) cout << p->elem << " " << p->next->elem << endl;
		else cout << p->next->elem << " " << p->elem << endl;
		free(p->next); free(p);
	}
	return 0;
}