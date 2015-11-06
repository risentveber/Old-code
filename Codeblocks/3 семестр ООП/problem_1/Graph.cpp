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
	if (ptr)//ðåáðî ñóùåñòâóåò
		return;
	else if (ptr = vertices[id2].name_of(id1))//ñóùåñòâóåò îáðàòíîå
		vertices[id1].add_edge(id2, ptr);
	else{//ýòî ïåðâîå ðåáðî ìåæäó âåðøèíàìè
		ptr = shared_ptr<TWord>(new TWord);
		vertices[id1].add_edge(id2, ptr);
	}
}

void Graph::del_edge(unsigned v1, unsigned v2)
{
	unsigned id1 = get_id(v1);
	unsigned id2 = get_id(v2);
	auto ptr = vertices[id1].name_of(id2);
	if (ptr){//ðåáðî ñóùåñòâóåò
		vertices[id1].del_edge(id2);
	}else//íå ñóùåñòâóåò
		return;
}

void Graph::rename(unsigned v1, unsigned v2, shared_ptr<TWord>& wptr)
{
	unsigned id1 = get_id(v1);
	unsigned id2 = get_id(v2);
	auto ptr = vertices[id1].name_of(id2);
	if (ptr){//ðåáðî ñóùåñòâóåò
		ptr = wptr;
		return;
	}else if (ptr = vertices[id2].name_of(id1)){//ñóùåñòâóåò îáðàòíîå
		ptr = wptr;
		vertices[id1].add_edge(id2, ptr);
		return;
	}else{//ýòî ïåðâîå ðåáðî ìåæäó âåðøèíàìè
		ptr = wptr;
		vertices[id1].add_edge(id2, ptr);
	}
}

void Graph::del_name(unsigned v1, unsigned v2)
{
	unsigned id1 = get_id(v1);
	unsigned id2 = get_id(v2);
	auto ptr = vertices[id1].name_of(id2);
	if (ptr){//ðåáðî ñóùåñòâóåò
		strcpy(ptr->word, EMPTY);
		return;
	}else if (ptr = vertices[id2].name_of(id1)){//ñóùåñòâóåò îáðàòíîå
		strcpy(ptr->word, EMPTY);
		vertices[id1].add_edge(id2, ptr);
		return;
	}else{//ýòî ïåðâîå ðåáðî ìåæäó âåðøèíàìè
		ptr = shared_ptr<TWord>(new TWord);
		vertices[id1].add_edge(id2, ptr);
	}
}

ostream & operator << (ostream & out, Graph & graph)
{
	auto it = graph.vertices.begin();
	++it;//íóëåâîé ýëåìåíò ïóñò ïî óìîë÷àíèþ
	auto it_end = graph.vertices.end();
	for(; it != it_end; ++it){
		out << *it;
	}

	return out;
}

void print_string(shared_ptr<TWord> & a)
{
	cout << a->word << endl;
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
	unsigned int not_ = 1;
	unsigned n = 1;
	unsigned time = 0;
	vector<unsigned> component(count);
	unsigned low_c = 1;


	while (not_ < count){//ïîêà íå âñå âåðøèíû îáîøëè
		if (index[not_] == -1){
			index[not_] = time;
			low_index[not_] = time++;
			algo.push(not_);
			auto it = vertices[not_].begin();
			DFS.push(not_);
			DFS_it.push(it);
			while(DFS.size() != 0){
				while ((it = DFS_it.top()) != vertices[DFS.top()].end()){
					n = it->first;
					if (index[n] == -1){//âåðøèíà áåëàÿ
						index[n] = time;
						low_index[n] = time++;
						DFS_it.top()++;
						DFS.push(n);
						algo.push(n);
						DFS_it.push(vertices[n].begin());
					}else{//âåðøèíà - ñåðàÿ
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
				}else{ //ñîîáùàåì íàâåðõ
					k = DFS.top();
					if (low_index[k] > low_index[n])
						low_index[k] = low_index[n];
				}

			}
		} else
			++not_;
	}
	vector<shared_ptr<TWord>> current;
	vector<shared_ptr<TWord>> others;
	for(unsigned i = 1; i < low_c; ++i){//âñå ñèëüíî ñâÿçàííûå êîìïîíåíòû âûâîäèì
		for(unsigned k = 1; k < count; ++k){
			if (component[k] == i){
				cout << vertices[k].my_name() << ' ';
				unordered_map<unsigned, shared_ptr<TWord>> & edges = vertices[k].get_list();
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
