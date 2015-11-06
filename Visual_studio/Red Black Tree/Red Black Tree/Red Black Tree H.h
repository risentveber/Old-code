#include <cstdlib>

typedef enum{red, black} Color;

template <typename T>
class Node{
public:
	Color color;
	T key;
	Node<T> *left;
	Node<T> *right;
	Node<T> *p;
	//Node(){
	//	left = NULL;
	//	p = NULL;
	//	right = NULL;
	//};
	//virtual~Node(){
	//	delete left;
	//	delete right;
	//};
};



template <typename S>
class RBTree{
private:
	Node<S> *_root;
	Node<S> *_nil;//� ������ ������������� ������ ��������
	//int count;
	void _clear(Node<S> *x);//������� ��������� 
	void _leftRotate(Node<S> *x);
	void _rightRotate(Node<S> *y);
	void _insertFixup(Node<S> *z);
	void _removeFixup(Node<S> *z);
	Node<S> * _search(S key);//����� �� ������
	Node<S> * _predecessor(Node<S> *x);
	Node<S> * _successor(Node<S> *x);
	Node<S> * _min(Node<S> *x);
	Node<S> * _max(Node<S> *x);

public:
	RBTree();
	virtual~RBTree();
	void insert(S key);
	void remove(S key);
	bool search(S key);

};

