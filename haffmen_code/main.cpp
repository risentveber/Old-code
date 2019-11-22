#include <iostream>
#include <fstream>
#include <map>
#include "Node.h"
#include <queue>
#include <utility>
#include <deque>

using namespace std;
Node* tree_maker(ifstream &input){
	int a;
	map<unsigned char, size_t> symbols;
	//size_t i = 0;
	while((a = input.get()) != -1){
		++symbols[a];
	}
	priority_queue<Node> tree_making;
	Node tmp;
	tmp.isLeaf = true;
	for(auto i = symbols.begin(); i != symbols.end(); ++i){
		tmp.symbol = i->first;
		tmp.frequency = i->second;
		tree_making.push(tmp);
	}
	Node first;
	Node second;
	Node result;
	while(true){
		first = tree_making.top();
		tree_making.pop();
		if(tree_making.empty()){
			Node *tree = new Node(first);
			if(!tree->isLeaf){
				tree->left->p = tree;
				tree->right->p = tree;
			}
			return tree;
		}else{
			second = tree_making.top();
			tree_making.pop();
			result.left = new Node(second);
			result.right = new Node(first);
			result.frequency = first.frequency + second.frequency;
			if (!second.isLeaf){
				result.left->left->p = result.left;
				result.left->right->p = result.left;
			}
			if (!first.isLeaf){
				result.right->left->p = result.right;
				result.right->right->p = result.right;
			}
			tree_making.push(result);
		}
	}
}

void mover(map<unsigned char, deque<bool>> &m, deque<bool> &tmp, Node* tree){
	if(tree->isLeaf){
		m[tree->symbol] = tmp;
		tmp.pop_back();
	}else{
		tmp.push_back(false);
		mover(m, tmp, tree->left);
		tmp.push_back(true);
		mover(m, tmp, tree->right);
		if(!tmp.empty())
			tmp.pop_back();
	}

}

map<unsigned char, deque<bool>> code(Node* tree){
	deque<bool> tmp;
	map<unsigned char, deque<bool>> result;
	mover(result, tmp, tree);
	return result;
}

int main(){
	ifstream input;
	ofstream output;
	input.open("input.txt",ios::binary);
	output.open("code.txt");
	Node *tree = tree_maker(input);
	map<unsigned char, deque<bool>> symbCode = code(tree);
	int a;
	unsigned char b = 0;
	unsigned char c;
	int pos = 8;
	deque<bool> tmp;
	input.close();
	size_t count_input = 0;
	input.open("input.txt");
	while((a = input.get()) != -1){
		++count_input;
		tmp = symbCode[a];
		for(auto i = tmp.begin(); i != tmp.end(); ++i){
			--pos;
			if (*i){
				c = 1 << pos;
				b = b | c;
			}
			if (pos == 0){
				output << b;
				b = 0;
				pos = 8;
			}
		}
	}
	if (pos != 8)
			output << b;
	else
		pos = 0;
	input.close();
	output.close();

	input.open("code.txt",ios::binary);
	output.open("decode.txt");
	bool flag = false;
	int cursor = 8;
	Node *node = tree;
	size_t count_output = 0;
	while((a = input.get()) != -1){
		++count_output;
		if(input.peek() == -1){
			while(cursor != 0 && cursor >= pos){
				if(node->isLeaf){
					output << node->symbol;
					node = tree;
				}else{
					--cursor;
					if((unsigned char)a & 1 << cursor)
						node = node->right;
					else
						node = node->left;
				}
			}
		}else{
			while(cursor != 0){
				if(node->isLeaf){
					output << node->symbol;
					node = tree;
				}else{
					--cursor;
					if((unsigned char)a & 1 << cursor)
						node = node->right;
					else
						node = node->left;
				}
			}
			cursor = 8;
		}

	}

	input.close();
	output.close();
	output.open("compression.txt",ios::binary);
	output << (count_output+0.0)/count_input << endl;
	output.close();
	//getchar();
	return 0;
}

