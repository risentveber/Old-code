#include <stddef.h>

class Node{
public:
	Node();
	unsigned char symbol;
	size_t frequency;
	bool isLeaf;
	Node *p;
	Node *left;
	Node *right;
	friend bool operator < (const Node &, const Node &);
};

Node::Node(): isLeaf(false), p(NULL), left(NULL), right(NULL){}

bool operator < (const Node &a, const Node &b){
	return a.frequency > b.frequency;
}
