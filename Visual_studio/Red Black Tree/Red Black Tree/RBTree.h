#include "Red Black Tree H.h"

template<typename S>
void RBTree<S>::_clear(Node<S> *x){
	if (x->left != _nil)
		_clear(x->left);
	if (x->right != _nil)
		_clear(x->right);
	delete x;
	//x = _nil;
}

template<typename S>
RBTree<S>::RBTree(){
	_nil = new Node<S>;
	_nil->color = black;
	_root = _nil;
}

template<typename S>
RBTree<S>::~RBTree(){
	if (_root != _nil)
		_clear(_root);
	delete _nil;
}


template<typename S>
void RBTree<S>::_leftRotate(Node<S> *x){//x->right != _nil
	Node<S> *y = x->right;
	x->right = y->left;
	if (y->left != _nil)
		y->left->p = x;
	y->p = x->p;
	if (x->p == _nil)
		_root = y;
	else
		if (x == x->p->left)
			x->p->left = y;
		else
			x->p->right = y;
	y->left = x;
	x->p = y;
}

template<typename S>
void RBTree<S>::_rightRotate(Node<S> *x){//x->right != _nil
	Node<S> *y = x->left;
	x->left = y->right;
	if (y->right != _nil)
		y->right->p = x;
	y->p = x->p;
	if (x->p == _nil)
		_root = y;
	else
		if (x == x->p->right)
			x->p->right = y;
		else
			x->p->left = y;
	y->right = x;
	x->p = y;
}

//template<typename S>
//void RBTree<S>::_rightRotate(Node<S> *y){//y->left != _nil
//	Node<S> *x = y->left;
//	y->left = x->right;
//	if (x->right != _nil)
//		x->right->p = y;
//	x->p = y->p;
//	if (y->p == _nil)
//		_root = x;
//	else
//		if (y == y->p->right)
//			y->p->right = x;
//		else
//			y->p->left = x;
//	x->right = y;
//	y->p = x;
//}

template<typename S>
void RBTree<S>::insert(S key){
	Node<S> *z = new Node<S>;
	z->key = key;
	z->left = _nil;
	z->right = _nil;
	z->color = red;

	Node<S> *y = _nil;
	Node<S> *x = _root;
	while (x != _nil){
		y = x;
		if (z->key < y->key)//требуется компоратор
			x = x->left;
		else
			x = x->right;
	}
	z->p = y;
	if (y == _nil)
		_root = z;
	else
		if (z->key < y->key)
			y->left = z;
		else
			y->right = z;
	
	_insertFixup(z);
}

template<typename S>
void RBTree<S>::_insertFixup(Node<S> *z){
	Node<S> * y;
	while (z->p->color == red){//если идут подряд две красных вершины z и z->p
		if (z->p == z->p->p->left){//если z - левый потомок
			y = z->p->p->right;//y указывает на дядю(правого) z
			if (y->color == red){//дядя - красный
				z->p->color = black;
				y->color = black;
				z->p->p->color = red;
				z = z->p->p;
			}else{//дядя - черный
				if( z == z->p->right){
					z = z->p; 
					_leftRotate(z);//вытягиваем влево
				};
				z->p->color = black;
				z->p->p->color = red;
				_rightRotate(z->p->p);
			}
		}else{//если z - правый потомок
			y = z->p->p->left;//y указывает на дядю(левого) z
			if (y->color == red){//дядя - красный
				z->p->color = black;
				y->color = black;
				z->p->p->color = red;
				z = z->p->p;
			}else{//дядя - черный
				if( z == z->p->left){
					z = z->p;
					_rightRotate(z);//вытягиваем вправо
				};
				z->p->color = black;
				z->p->p->color = red;
				_leftRotate(z->p->p);
			}
		}
	}
	_root->color = black;
}

template<typename S>
Node<S> * RBTree<S>::_search(S key){
	Node<S> *y = _root;
	while ((y != _nil)&&(key != y->key)){
		if (key < y->key)
			y = y->left;
		else
			y = y->right;
	}
	return y;
}

template<typename S>
Node<S> * RBTree<S>::_min(Node<S> *x){
	if (x == _nil)
		return _nil;
	while (x->left != _nil)
		x = x->left;
	return x;
}

template<typename S>
Node<S> * RBTree<S>::_max(Node<S> *x){
	if (x == _nil)
		return _nil;
	while (x->right != _nil)
		x = x->right;
	return x;
}

template<typename S>
Node<S> * RBTree<S>::_successor(Node<S> *x){
	if (x->right != _nil)
		return _min(x->right);
	Node<S> *y = x->p;
	while ((y != _nil) && (x == y->right)){
		x = y;
		y = y->p;
	}
	return y;
}

template<typename S>
Node<S> * RBTree<S>::_predecessor(Node<S> *x){
	if (x->left != _nil)
		return _max(x->left);
	Node<S> *y = x->p;
	while ((y != _nil) && (x == y->left)){
		x = y;
		y = y->p;
	}
	return y;
}



template<typename S>
void RBTree<S>::remove(S key){
	Node<S> *z = _search(key);
	Node<S> *y;
	Node<S> *x;
	if (z != _nil){
		if ((z->left == _nil) || (z->right == _nil))
			y = z;
		else
			y = _successor(z);
		if (y->left != _nil)
			x = y->left;
		else
			x = y->right;
		x->p = y->p;
		if (y->p == _nil)
			_root = x;
		else
			if (y == y->p->left)
				y->p->left = x;
			else
				y->p->right = x;
		if (y != z)
			z->key = y->key;
		if (y->color == black)
			_removeFixup(x);
		delete y;///ssssssssss
	}
}

template<typename S>
void RBTree<S>::_removeFixup(Node<S> *x){
	Node<S> *w;
	while ((x != _root) && (x->color == black))
		if (x == x->p->left){
			w = x->p->right;
			if (w->color == red){
				w->color = black;
				x->p->color = red;
				_leftRotate(x->p);
				w = x->p->right;
			}
			if ((w->left->color == black) && (w->right->color == black)){
				w->color = red;
				x = x->p;
			}else{
				if (w->right->color == black){
					w->left->color = black;
					w->color = red;
					_rightRotate(w);
					w = x->p->right;
				}
				w->color = x->p->color;
				x->p->color = black;
				w->right->color = black;
				_leftRotate(x->p);
				x = _root;
			}
		}else{
			w = x->p->left;
			if (w->color == red){
				w->color = black;
				x->p->color = red;
				_rightRotate(x->p);
				w = x->p->left;
			}
			if ((w->right->color == black) && (w->left->color == black)){
				w->color = red;
				x = x->p;
			}else{
				if (w->left->color == black){
					w->right->color = black;
					w->color = red;
					_leftRotate(w);
					w = x->p->left;
				}
				w->color = x->p->color;
				x->p->color = black;
				w->left->color = black;
				_rightRotate(x->p);
				x = _root;
			}
		}
	x->color = black;
}


template<typename S>
bool RBTree<S>::search(S key){
	return _nil != _search(key);
}

