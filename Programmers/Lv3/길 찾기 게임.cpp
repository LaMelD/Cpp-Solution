#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vpreorder;
vector<int> vpostorder;

struct info
{
	int x = 0;
	int y = 0;
	int val = 0;
};

class Node
{
private :
	info val;
	Node* leftChild;
	Node* rightChild;
public :
	Node()
	{
		this->val;
		this->leftChild = nullptr;
		this->rightChild = nullptr;
	}
	Node(info rt)
	{
		this->val = rt;
		this->leftChild = nullptr;
		this->rightChild = nullptr;
	}
	int getValue() { return this->val.val; }
	Node* getRightChild() { return this->rightChild; }
	Node* getLeftChild() { return this->leftChild; }

	void push(info input)
	{
		//오른쪽으로 간다
		if (this->val.x < input.x)
		{
			if (this->getRightChild() == nullptr)
			{
				this->rightChild = new Node(input);
			}
			else
			{
				this->getRightChild()->push(input);
			}
		}
		//왼쪽으로 간다
		else if (input.x < this->val.x)
		{
			if (this->getLeftChild() == nullptr)
			{
				this->leftChild = new Node(input);
			}
			else
			{
				this->getLeftChild()->push(input);
			}
		}
	}
};

class Tree
{
private :
	Node* root;
	int depth;
private :
	void preorder(Node*);
	void postorder(Node*);
public :
	Tree(info rt)
	{
		this->root = new Node(rt);
		this->depth = 1;
	}
	
	void push(info);
	void preorder() { this->preorder(root); };
	void postorder() { this->postorder(root); };
};
void Tree::push(info input)
{
	this->root->push(input);
}
void Tree::preorder(Node* ptr)
{
	if (ptr == nullptr) return;
	vpreorder.push_back(ptr->getValue());
	preorder(ptr->getLeftChild());
	preorder(ptr->getRightChild());
}
void Tree::postorder(Node* ptr) 
{
	if (ptr == nullptr) return;
	postorder(ptr->getLeftChild());
	postorder(ptr->getRightChild());
	vpostorder.push_back(ptr->getValue());
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
	vector<vector<int>> answer;

	vpreorder.clear();
	vpostorder.clear();

	vector<info> nodes(nodeinfo.size());

	for (int i = 0; i < nodeinfo.size(); i++)
	{
		nodes[i].x = nodeinfo[i][0];
		nodes[i].y = nodeinfo[i][1];
		nodes[i].val = i + 1;
	}

	sort(nodes.begin(), nodes.end(), [](info a, info b)
		{
			if (a.y == b.y)
			{
				return a.x < b.x;
			}
			return b.y < a.y;
		});

	Tree* tree = new Tree(nodes[0]);

	for (int i = 1; i < nodeinfo.size(); i++)
	{
		tree->push(nodes[i]);
	}

	tree->preorder();
	tree->postorder();

	answer.push_back(vpreorder);
	answer.push_back(vpostorder);

	return answer;
}

int main()
{
	vector<vector<int>> result = solution({ {5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2} });

	return 0;
}
