#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BinaryNode
{
public:
	int data;
	BinaryNode* left;
	BinaryNode* right;

	BinaryNode(int val = 0, BinaryNode* L = NULL, BinaryNode* R = NULL) : data(val), left(L), right(R) {}
	~BinaryNode() {}

	void setData(int val) {
		data = val;
	}

	void setLeft(BinaryNode* L) {
		left = L;
	}

	void setRight(BinaryNode* R) {
		right = R;
	}

	int getData() {
		return data;
	}

	BinaryNode* getLeft() {
		return left;
	}

	BinaryNode* getRight() {
		return right;
	}
};

class BinaryTree
{
public:
	BinaryNode* root;

	BinaryTree() : root(NULL) {}
	~BinaryTree() {}

	void setRoot(BinaryNode* node) {
		root = node;
	}

	BinaryNode* getRoot() {
		return root;
	}

	//Traversal
	void preorder(BinaryNode* node);
	void inorder(BinaryNode* node);
	void postorder(BinaryNode* node);
};

void BinaryTree::preorder(BinaryNode* node) {
	if (node != NULL) {
		cout << (char)node->getData();
		if (node->getLeft() != NULL) {
			preorder(node->getLeft());
		}
		if (node->getRight() != NULL) {
			preorder(node->getRight());
		}
	}
}
void BinaryTree::inorder(BinaryNode* node) {
	if (node != NULL) {
		if (node->getLeft() != NULL) {
			inorder(node->getLeft());
		}
		cout << (char)node->getData();
		if (node->getRight() != NULL) {
			inorder(node->getRight());
		}
	}
}
void BinaryTree::postorder(BinaryNode* node) {
	if (node != NULL) {
		if (node->getLeft() != NULL) {
			postorder(node->getLeft());
		}
		if (node->getRight() != NULL) {
			postorder(node->getRight());
		}
		cout << (char)node->getData();
	}
}


int main()
{
	int N; //노드 개수
	char p, left, right; //트리 루트,왼쪽,오른쪽 노드
	vector<BinaryNode*> node; //벡터에 A~G문자의 노드객체를 넣어두고 꺼내쓸 예정
	BinaryTree* tree;

	cin >> N;
	node.resize(N);

	//BinaryNode 생성
	for (int i = 0; i < N; i++)
	{
		//아스키값을 이용해 'A' 부터 'A' + (N-1)까지 차례로 문자 생성
		//즉, 벡터에 미리 A~G 까지 문자를 넣어둠
		//'A'의 아스키값 = 65
		//'A' + i 의 연산은 숫자로 계산되지만 다시 문자로 변환됨
		node[i] = new BinaryNode('A' + i); //문자데이터를 포함하는 노드객체를 생성해서 차례로 벡터에 저장
	}

	//노드 간 링크 연결
	for (int j = 0; j < N; j++)
	{
		cin >> p >> left >> right; //부모, 왼쪽 자식, 오른쪽 자식
		
		//'A'를 기준으로 인덱스를 맞추어 벡터에서 노드객체를 찾음
		// p-'A'를 계산 후 벡터에서 해당 인덱스값을 찾으면 문자 p인 노드객체
		if (left != '.') {
			node[p - 'A']->setLeft(node[left - 'A']);
		}
		if (right != '.') {
			node[p - 'A']->setRight(node[right - 'A']);
		}
	}

	//BinaryTree 생성
	tree = new BinaryTree(); //객체 생성 후 tree포인터에 저장
	tree->setRoot(node[0]); //루트노드는 A문자 노드객체

	//BinaryTree Traversal
	BinaryNode* root = tree->getRoot(); //트리 순회를 루트노드에서 시작-> 루트 노드를 가져와 root포인터에 저장

	//각각 포인터 tree가 가리키고 있는 BinaryTree객체의 멤버함수에 접근
	tree->preorder(root);
	cout << endl; //순회 결과끼리 구분하기 위해 endl로 출력 버퍼 비우고, 줄바꿈 추가
	
	tree->inorder(root);
	cout << endl;

	tree->postorder(root);
	cout << endl;

	return 0;

}