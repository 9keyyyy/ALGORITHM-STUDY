#include <iostream>
using namespace std;



// Ʈ���� ��带 ǥ���ϴ� ��ü ����
typedef int KeyType;
struct Node {
	KeyType key; // ��忡 ����� ����
	int priority, size; // �켱����, ����Ʈ�� ũ��
	Node *left, *right; // �� �ڽĳ�� ������
	// ���� �켱���� ����, �� �� ���� �ʱ�ȭ
	Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL){}
	void setLeft(Node *newLeft) { left = newLeft; calcSize(); }
	void setRight(Node *newRight) { right = newRight; calcSize(); }
	// size ����
	void calcSize() {
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
};



// Ʈ������ ��� �߰��� Ʈ�� �ɰ��� ���� ����
typedef pair<Node*, Node*> NodePair;
// root�� ��Ʈ�� �ϴ� Ʈ���� key �̸��� ���� �̻��� ���� ���� �ΰ��� Ʈ������ �и�
NodePair split(Node *root, KeyType key) {
	if (root == NULL) return NodePair(NULL, NULL);
	if (root->key < key) { // root�� key �̸��̸� ������ ����Ʈ�� �ɰ�
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}
	// root�� key�̻��̸� ���� ����Ʈ�� �ɰ�
	NodePair ls = split(root->left, key);
	root->setLeft(ls.second);
	return NodePair(ls.first, root);
}
// root�� ��Ʈ�� �ϴ� Ʈ���� �� ��带 �����ѵ� ��� Ʈ���� ��Ʈ ��ȯ
Node* insert(Node* root, Node *node) {
	if (root == NULL) return node;
	if (root->priority < node->priority) {
		NodePair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	else if (node->key < root->key)
		root->setLeft(insert(root->left, node));
	else
		root->setRight(insert(root->right, node));
	return root;
}
// root = insert(root, new Node(value)); -> Ʈ���� ���ο� �� value �߰�



// ����� ������ ��ġ�� ������ ����
Node* merge(Node *a, Node *b) {
	if (a == NULL) return b;
	if (b == NULL) return a;
	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}
	a->setRight(merge(a->right, b));
	return a;
}
Node *erase(Node* root, KeyType key) {
	if (root == NULL) return root;
	if (root->key == key) {
		Node *ret = merge(root->left, root->right);
		delete root;
		return ret;
	}
	if (key < root->key)
		root->setLeft(erase(root->left, key));
	else
		root->setRight(erase(root->right, key));
	return root;
}




// k��° ���� ã��
// ���� ����Ʈ�� ũ�� l�̶�� �Ҷ�,
// k<=l : k��° ���� ���� ����Ʈ���� ��������
// k=l+1 : ��Ʈ�� k��° ���
// k>l+1 : k��° ���� ������ ����Ʈ������ k-l-1��° ���
Node* kth(Node *root, int k) {
	int leftSize = 0;
	if (root->left != NULL) leftSize = root->left->size;
	if (k <= leftSize) return kth(root->left, k);
	if (k == leftSize + 1) return root;
	return kth(root->right, k - leftSize - 1);
}




// Ʈ������ X���� ���� ������ �� ã�� �˰���
int countLessThan(Node *root, KeyType key) {
	if (root == NULL) return 0;
	if (root->key >= key)
		return countLessThan(root->left, key);
	int ls = (root->left ? root->left->size : 0);
	return ls + 1 + countLessThan(root->right, key);
}
int main() {
	return 0;
}