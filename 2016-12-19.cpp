#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>

using namespace std;


typedef int T;
struct BinaryNode{
  T data; //store data 
  BinaryNode *left, *right;
  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode* r=NULL):data(d), left(l), right(r) {};
};

void insert (BinaryNode *  & root, int t) {

	if (root == NULL) root = new BinaryNode (t);
	else {
		if (t < root -> data) insert (root -> left, t);
		else if (t > root -> data) insert (root -> right, t);
	}
}

int height (BinaryNode * root) {
	if (root == NULL) return -1;
	else return (max(height (root -> left), height(root -> right)) + 1);
}

int max (int a, int b) {
	if (a >= b) return a;
	else return b;
}

int depth (const BinaryNode * root, BinaryNode * bn) {
//	cout << "check !" << endl;
	if (root -> data == bn -> data && root -> left == bn -> left && root -> right == bn -> right) {
//		cout << "root == bn !" << endl;
		return 0;
	}
	else {
//		cout << "aaaaaaaaaaaaaaaaa" << endl;
		if (bn -> data < root -> data) {
//			cout << "bn -> data < root -> data !" << endl;
			return depth (root -> left, bn) + 1;
		}
		else if (bn -> data > root -> data) {
//			cout << "bn -> data > root -> data !" << endl;
			return depth (root -> right, bn) + 1;
		} 
	}
}

static int sum = 0;

void add (const BinaryNode* root, BinaryNode * current, int & sum) {
	if (current -> left == NULL && current -> right == NULL) return;
	else {
		sum += depth (root, current);
//		cout << sum << endl;
		if (current -> left == NULL) {
			add (root, current -> right, sum);
		}
		else if (current -> right == NULL) {
			add (root, current -> left, sum);
		}
		else {
			add (root, current -> left, sum);
			add (root, current -> right, sum);
		}
	}
}

int internalPL (const BinaryNode* root) {
	if (root == NULL) sum = 0;
	else {
		BinaryNode * root_copy = new BinaryNode (root -> data, root -> left, root -> right);
//		cout << "cccc" << root_copy -> data << endl;
		add (root, root_copy, sum);
	}
	return sum;
}

int main () {
	int n;
	cin >> n;

	BinaryNode * root = NULL;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		insert (root, temp);
	}
	cout << internalPL (root);
}
