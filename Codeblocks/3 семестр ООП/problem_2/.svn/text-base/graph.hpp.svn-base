#include "help_clases.h"
#include <set>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;


class Graph
{
public:
	double average();
	void projects(istream &);
private:
	unsigned M, N;
	vector<Vertex> vertices;
	vector<vector<Edge>> matrix;
	
	void print_info(unsigned, double);
	void print(ostream & ,unsigned i);
	void read_project(istream & input, set<pair<unsigned, unsigned>> &);
	void relax(unsigned, list<Edge>::iterator &, set<pair<unsigned, unsigned>> &);

	friend istream & operator >> (istream &, Graph &);
	friend ostream & operator << (ostream &, Graph &);
};


istream & operator >> (istream & input, Graph & graph)
{
	string s;
	istringstream instr;
	//unsigned count;
	unsigned v1, v2, N, M, dist;

	input >> N >> M;
	//init graph
	graph.N = N;
	graph.M = M;
	graph.matrix.clear();
	graph.matrix.resize(N + 1);
	graph.vertices.resize(N + 1);
	for (unsigned i = 0; i <= N; ++i){
		graph.matrix[i].resize(N + 1);
		graph.matrix[i][i].weight = 0;
	}

	
	for(unsigned i = 1; i <= M; ++i){//i - name of current line
		input >> ws;
		getline(input, s);
		instr.str(s);
		/*count = 0;
		instr >> count;
		if (count == 0)
			continue;*/
		instr >> v2;
		while( instr >> dist ){
			v1 = v2;
			instr >> v2;
			graph.matrix[v1][v2].id = v2;
			graph.matrix[v1][v2].line = i;
			graph.matrix[v1][v2].weight = dist;
			graph.matrix[v2][v1].id = v1;
			graph.matrix[v2][v1].line = i;
			graph.matrix[v2][v1].weight = dist;
			if (v1 != v2){
				graph.vertices[v1].edges.push_back(graph.matrix[v1][v2]);
				graph.vertices[v2].edges.push_back(graph.matrix[v2][v1]);
			}
		}
		instr.clear();
	}

	return input;
};

ostream & operator << (ostream & output, Graph & graph)
{
	for(unsigned i = 0; i <= graph.N; ++i){
		for(unsigned j = 0; j <= graph.N; ++j){
			if( graph.matrix[i][j].weight == UINT_MAX)
				output << ' ';
			else {
			output << graph.matrix[i][j].weight;
			}
		}
		output << endl;
	}
	return output;
}

double Graph::average(){
	//инициализация матриц для динамического поиска кратчайших путей
	vector<vector<D>> first, last;
	last.resize(N + 1);
	for(unsigned i = 0; i <= N; ++i)
		last[i].resize(N + 1);
	for(unsigned i = 0; i <= N; ++i)
		for(unsigned j = 0; j <= N; ++j){
			last[i][j].d = matrix[i][j].weight;
			last[i][j].left = last[i][j].right = matrix[i][j].line;
		}
	first = last;
	D left, right;

	for(unsigned k = 1; k <= N; ++k){
		swap(first, last);
		for(unsigned i = 1; i <= N; ++i)
			for(unsigned j = 1; j <= N; ++j){
				if ((left = first[i][k]).d == UINT_MAX || (right = first[k][j]).d == UINT_MAX) 
					last[i][j] = first[i][j];//no changes
				else if (left + right < first[i][j])
					last[i][j] = left + right;
				else
					last[i][j] = first[i][j];//no changes even if ==
			}
	}
	double result = 0;
	for(unsigned i = 1; i <= N; ++i)
		for(unsigned j = 1; j <= N; ++j)
			if (i != j)
				result +=  last[i][j].d;

	result += ((escalator << 1) + pause)*N*(N - 1);
	result /= N*N;
	return result;
	//for(unsigned i = 0; i <= N; ++i){
	//	for(unsigned j = 0; j <= N; ++j){
	//		if( last[i][j].d == UINT_MAX)
	//			cout << setw(3) << ' ';
	//		else {
	//		cout << setw(3) << last[i][j].d;
	//		}
	//	}
	//	cout << endl;
	//}
	//

}

void Graph::projects(istream & input)
{
	double current_time;
	double best_diff = DBL_MAX;
	unsigned best_project;
	set<pair<unsigned, unsigned>> priority; 
	
	unsigned u;
	unsigned counter;
	set<pair<unsigned, unsigned>>::iterator  it;
	list<Edge>::iterator end_l;
	double average_time = average();
	cout << "average time before " << average_time << endl;
	cout << "****************************************" << endl;
	cout << "PROJECTS" << endl;
	
	input >> counter;
	for(unsigned c = 1; c <= counter; ++c){		

		read_project(input, priority);

		while ( !priority.empty() ){
			it = priority.begin();
			u = it->second;//текущая вершина
			priority.erase(it);
			if (vertices[u].d == UINT_MAX)//закончились достижимые вершины
				break;
			end_l = vertices[u].edges.end();
			for(auto n = vertices[u].edges.begin(); n != end_l; ++n)//n - ребро
				relax(u, n, priority);
		}
		current_time = 0;
		for (unsigned i = 1; i <= N; ++i)
			current_time += vertices[i].d;
		current_time += ((escalator << 1) + pause)*N;
		current_time /= N + 1;
		if (best_diff > abs(average_time - current_time)){
			best_diff = abs(average_time - current_time);
			best_project = c;
		}
		
		print_info(c, current_time);
	}
	cout << "****************************************" << endl;
	cout << endl;
	cout << "the best project is " << best_project << endl;
	
}

void Graph::print(ostream & output, unsigned i)
{
	vector<unsigned> path;
	while (i != 0){
		path.push_back(i);
		i = vertices[i].p;
	}
	for(auto it = path.rbegin(); it != path.rend(); ++it)
		output << *it << ' ' ;
	//cout << endl;
}

void Graph::print_info(unsigned c, double current_time)
{
		cout << "****************************************" << endl;
		cout << "project " << c << endl;
		cout << "________________________________________" << endl;
		cout << "average_time " << current_time << endl;
		cout << endl;
		/*cout << "times"<< endl;
		for (unsigned i = 1; i <= N; ++i)
			cout << i << "   " << vertices[i].d << endl;
		cout << endl;*/
	
		vector<pair<unsigned, unsigned>> time_val;
		for (unsigned i = 1; i <= N; ++i){
			time_val.push_back(make_pair(vertices[i].d, i));
		}
		sort(time_val.begin(), time_val.end());
		unsigned d = time_val.begin()->first;
		for(auto j = time_val.begin(); j != time_val.end() && j->first == d; ++j){
			cout << "nearest " << j->second << " path: 0 ";
			print(cout, j->second);
			cout << endl;
		}
		cout << endl;
		d = time_val.rbegin()->first;
		for(auto j = time_val.rbegin(); j != time_val.rend() && j->first == d; ++j){
			cout << "farthest " << j->second << " path: 0 ";
			print(cout, j->second);
			cout << endl;
		}
		cout << endl;
		cout << "median " << time_val[(N >> 1) + N % 2 - 1].second << " path: 0 ";
		print(cout, time_val[(N >> 1) + N % 2 - 1].second);
		cout << endl;

}

void Graph::read_project(istream & input, set<pair<unsigned, unsigned>> & priority)
{
	Edge temp;
	unsigned lines, time, inv;
	priority.clear();
	input >> lines;
		vertices[0].edges.clear();
		for(unsigned l = 0; l < lines; ++l){
				input >> inv >> time;
				temp.line = 0;
				temp.id = inv;
				temp.weight = time;
				vertices[0].edges.push_back(temp);
		};
		vertices[0].d = 0;
		vertices[0].line = 0;// name of this line
		priority.insert(make_pair(0, 0));
		for(unsigned i = 1; i <= N; ++i){
			vertices[i].d = UINT_MAX;
			vertices[i].p = UINT_MAX;
			priority.insert(make_pair(UINT_MAX, i));
		}
}

void Graph::relax(unsigned u, list<Edge>::iterator & n, set<pair<unsigned, unsigned>> & priority){
	if (vertices[n->id].p == UINT_MAX){//вершина была недостижима
		vertices[n->id].d = n->weight + vertices[u].d;
		//проверка условия
		if (vertices[u].line != n->line)
			vertices[n->id].d += pause + transition;
		vertices[n->id].line = n->line;
		vertices[n->id].p = u;
		priority.erase(make_pair(UINT_MAX, n->id));
		priority.insert(make_pair(vertices[n->id].d, n->id));
		//достигаем по этому ребру
	} else //достижима
		if (vertices[n->id].line != n->line){
			if (vertices[n->id].d > vertices[u].d + pause + transition + n->weight){
				priority.erase(make_pair(vertices[n->id].d, n->id));
				vertices[n->id].d = vertices[u].d + pause + transition + n->weight;
				vertices[n->id].p = u;
				vertices[n->id].line = n->line;
				priority.insert(make_pair(vertices[n->id].d, n->id));
			}
		}else if (vertices[n->id].d > vertices[u].d + n->weight){
			priority.erase(make_pair(vertices[n->id].d, n->id));
			vertices[n->id].d = vertices[u].d + n->weight;
			vertices[n->id].p = u;
			priority.insert(make_pair(vertices[n->id].d, n->id));
		}

}