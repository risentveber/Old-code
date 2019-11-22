class Node{
public:
	Node();
	unsigned char symbol;
	size_t frequency;
	bool isLeaf;
	Node *p;
	Node *right;
	Node *left;
	friend bool operator < (const Node &, const Node &);
};

Node::Node(): p(NULL), left(NULL), right(NULL), isLeaf(false){}

bool operator < (const Node &a, const Node &b){
	return a.frequency > b.frequency;
}
