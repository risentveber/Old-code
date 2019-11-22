#include "Graph.h"
#include <algorithm>

unsigned Graph::get_id(unsigned v)
{
	unsigned id = conform[v];
	if (id)
		return id;
	else{
		id = vertices.size();
		vertices.push_back(Vert(v, id, &vertices));
		return (conform[v] = id);
	}
}

void Graph::add_edge(unsigned v1, unsigned v2)
{
	unsigned id1 = get_id(v1);
	unsigned id2 = get_id(v2);
	auto ptr = vertices[id1].name_of(id2);
	if (ptr)//����� ����������
		return;
	else if (ptr = vertices[id2].name_of(id1))//���������� ��������
		vertices[id1].add_edge(id2, ptr);
	else{//��� ������ ����� ����� ���������
		ptr = shared_ptr<string>(new string);
		*ptr = EMPTY;
		vertices[id1].add_edge(id2, ptr);
	}
}

void Graph::del_edge(unsigned v1, unsigned v2)
{
	unsigned id1 = get_id(v1);
	unsigned id2 = get_id(v2);
	auto ptr = vertices[id1].name_of(id2);
	if (ptr){//����� ����������
		vertices[id1].del_edge(id2);
	}else//�� ����������
		return;
}

void Graph::rename(unsigned v1, unsigned v2, char* word)
{
	unsigned id1 = get_id(v1);
	unsigned id2 = get_id(v2);
	auto ptr = vertices[id1].name_of(id2);
	if (ptr){//����� ����������
		*ptr = word;
		return;
	}else if (ptr = vertices[id2].name_of(id1)){//���������� ��������
		*ptr = word;
		vertices[id1].add_edge(id2, ptr);
		return;
	}else{//��� ������ ����� ����� ���������
		ptr = shared_ptr<string>(new string);
		*ptr = word;
		vertices[id1].add_edge(id2, ptr);
	}
}

void Graph::del_name(unsigned v1, unsigned v2)
{
	unsigned id1 = get_id(v1);
	unsigned id2 = get_id(v2);
	auto ptr = vertices[id1].name_of(id2);
	if (ptr){//����� ����������
		*ptr = EMPTY;
		return;
	}else if (ptr = vertices[id2].name_of(id1)){//���������� ��������
		*ptr = EMPTY;
		vertices[id1].add_edge(id2, ptr);
		return;
	}else{//��� ������ ����� ����� ���������
		ptr = shared_ptr<string>(new string);
		*ptr = EMPTY;
		vertices[id1].add_edge(id2, ptr);
	}
}

ostream & operator << (ostream & out, Graph graph)
{
	auto it = graph.vertices.begin();
	++it;//������� ������� ���� �� ���������
	auto it_end = graph.vertices.end();
	for(; it != it_end; ++it){
		out << *it;
	}

	return out;
}

void print_string(shared_ptr<string> a)
{
	cout << *a << endl;
}

void Graph::search_components()
{
	stack<unsigned> algo;
	stack<unsigned>DFS;
	stack<maptype>DFS_it;
	unsigned count = vertices.size();
	vector<int> index(count, -1);
	vector<int> low_index(count, count + 1);
	vector<bool> used(count, false);
	unsigned not = 1;
	unsigned n = 1;
	unsigned time = 0;
	vector<unsigned> component(count);
	unsigned low_c = 1;
	

	while (not < count){//���� �� ��� ������� ������
		if (index[not] == -1){
			index[not] = time;
			low_index[not] = time++;
			algo.push(not);
			auto it = vertices[not].begin();
			DFS.push(not);
			DFS_it.push(it);
			while(DFS.size() != 0){
				while ((it = DFS_it.top()) != vertices[DFS.top()].end()){
					n = it->first;
					if (index[n] == -1){//������� �����
						index[n] = time;
						low_index[n] = time++;
						DFS_it.top()++;
						DFS.push(n);
						algo.push(n);
						DFS_it.push(vertices[n].begin());
					}else{//������� - �����
						if (low_index[DFS.top()] > low_index[n] && !used[n])
							low_index[DFS.top()] = low_index[n];
						DFS_it.top()++;
					}
				}
				n = DFS.top();
				DFS.pop();
				DFS_it.pop();
				unsigned k;
				if (index[n] == low_index[n]){
					while ((k = algo.top() )!= n){
						algo.pop();
						component[k] = low_c;
						used[k] = true;
					}
					algo.pop();
					used[n] = true;
					component[n] = low_c++;
				}else{ //�������� ������
					k = DFS.top();
					if (low_index[k] > low_index[n])
						low_index[k] = low_index[n];
				}
				
			}
		} else
			++not;
	}
	vector<shared_ptr<string>> current;
	vector<shared_ptr<string>> others;
	for(unsigned i = 1; i < low_c; ++i){//��� ������ ��������� ���������� �������
		for(unsigned k = 1; k < count; ++k){
			if (component[k] == i){
				cout << vertices[k].my_name() << ' ';
				unordered_map<unsigned, shared_ptr<string>> & edges = vertices[k].get_list();
				auto it = edges.begin();
				auto it_end = edges.end();
				for( ; it != it_end; ++it){
					if (component[it->first] == i)
						current.push_back(it->second);
					else 
						others.push_back(it->second);
				}
			}
		}
		cout << endl;
		for_each(current.begin(), current.end(), print_string);
		current.clear();
	}
	if (!others.empty()){
		cout << "others edeges:" << endl;
		for_each(others.begin(), others.end(), print_string);
	}	

}
