#include <iostream>
#include <cstring>
using namespace std;

/*------------------------------------------------------------------------------------------
							
								<	��ü���� �˰���   >

  �Է°��� ���� Ʈ�� ���� -> Ʈ�� ��ȸ�ϸ鼭 ���ḵũ�� �ٲپ� ���Ϲ��� -> Ʈ�� ��ȸ -> ��!

  * ����
	- Ʈ���� ���Ḯ��Ʈ�� ����� ����
	- 'x'��� �Ʒ����� �ڽ� ��尡 �ִٴ� Ư¡
	  !!! 'x'����� ��� �ڽ��� 4�� -> �ϳ��� child�� �ϰ� �������� sibling���� ���� !!!
	- ����� n���� 'x'����� �ڽ� ���� -> 4�� �Ǿ��� �� ���� sibling���� �̵�

 -------------------------------------------------------------------------------------------*/

// Ʈ���� ���
typedef struct node {		
	char color;
	int n;
	struct node *child;
	struct node *parent;
	struct node *sibling;
}NODE;

// ��� ����
NODE *getnode(char color) {
	NODE *p = (NODE *)malloc(sizeof(NODE));
	p->color = color;
	p->child = NULL;
	p->parent = NULL;
	p->sibling = NULL;
	return p;
}

// Ʈ�� ���� 
// �������� 'x'��带 �������� �̷����
void MakeTree(char *q, NODE *t) {
	// base case : ���ڿ� ��
	if (*q == '\0') return;	
	// �ڽ��� 4���� �Ǹ� �θ���� �̵�
	else if (t->n == 4) MakeTree(q, t->parent);
	// ���ڰ� 'x'�� ��
	else if (*q == 'x') {
		NODE *p = getnode('x');
		// ù��° �ڽ��� ��� : child
		if (t->n == 0) t->child = p;
		// �� ���� ��� : child���� sibling���� ����
		// ���� ������ sibling�� �������� ����
		else {
			NODE *r = t->child;	
			while (r->sibling != NULL) {
				r = r->sibling;
			}
			r->sibling = p;
		}		
		p->n = 0;			// �ڽĳ��(���� ������ ���)�� �ڽ��� 0
		p->parent = t;
		t->n += 1;			// �θ����� �ڽ� +1
		MakeTree(++q, p);	// �ڽĳ��(���� ������ ���)�� �Ѱ���
	}
	// ���ڰ� 'w' or 'b'�� ��
	else if (*q == 'w' || *q == 'b') {
		NODE *p = getnode(*q);
		if (t->n == 0) t->child = p;
		else {
			NODE *r = t->child;
			while (r->sibling != NULL) {
				r = r->sibling;
			}
			r->sibling = p;
		}
		p->parent = t;
		t->n += 1;
		MakeTree(++q, t);	// �θ���� �Ѱ���
	}
}

// Ʈ�� ��ȸ
// ��ü sibling�� ��ȸ�ϸ鼭, 'x'����� ��� child ���� �Ѱ� ��� ȣ��
void TraverseTree(NODE *t) {
	while (t != NULL) {
		cout << t->color;
		if (t->color == 'x') {
			TraverseTree(t->child);
		}
		t = t->sibling;
	}	
}

// �׸� ���� ����( 12, 34 ��ġ ���� )
// Ʈ�� ��ȸ�� ������ ��� -> ���ḵũ ����
void ReverseTree(NODE *t) {
	while (t != NULL) {
		if (t->color == 'x') {
			NODE *pchild = t->child;
			t->child = t->child->sibling->sibling;
			pchild->sibling->sibling = NULL;
			t->child->sibling->sibling = pchild;
			ReverseTree(t->child);
		}
		t = t->sibling;
	}
}
int main() {
	int n;
	char s[1001];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (strcmp(s, "w") == 0 || strcmp(s, "b") == 0) cout << s << endl;
		else {
			NODE *root = NULL;
			NODE *t = getnode('x');
			t->n = 0;
			root = t;
			MakeTree(s+1, t);
			ReverseTree(root);
			TraverseTree(root);
			cout << endl;
		}
	}
	return 0;
}