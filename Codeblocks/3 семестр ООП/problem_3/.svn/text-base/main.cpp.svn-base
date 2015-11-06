#include "edge.h"

int main()
{
    ifstream input("input.txt");
    unsigned m, n;
    input >> n >> m;
    unsigned sum = 0;
    unsigned t;
    for(unsigned i = 0; i < n; ++i){
         input >> t;
        sum += t;
    }

     disjoint_sets<int> sets;


    vector<Edge> edges(m);
    for(unsigned i = 0; i < m; ++i){
        input >> edges[i];
        sets.make_set(edges[i].get_v1());
        sets.make_set(edges[i].get_v2());
    }

    unsigned tree_weight = 0;
    sort(edges.begin(), edges.end());

    for(auto it = edges.begin(); it != edges.end(); ++it)
        if (sets.find_set(it->get_v1()) != sets.find_set(it->get_v2())){
        //если ребро соединяет разные разбиения
            it->add();
            sets.union_sets(it->get_v1(), it->get_v2());
            tree_weight += it->get_w();
        }



    cout << "It costs: " << tree_weight*sum << endl;
    cout << "Tree weight: " << tree_weight << endl;
    cout << "Edges belong to MST are:" << endl;
    for(auto it = edges.begin(); it != edges.end(); ++it)
        if (it->in_tree()){
            cout << *it << endl;
        }

    return 0;
}
