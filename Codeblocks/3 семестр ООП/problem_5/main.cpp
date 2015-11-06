#include "segment_tree.hpp"
#include <algorithm>
#include <functional>
#include <bitset>
#include <string>
#include <unordered_map>
#include <fstream>

const size_t size_of_bits = 5;

typedef bitset<size_of_bits> Bit;

int main()
{
    ifstream file("input.txt");
    size_t n;
    file >> n;
    unordered_map<string, Bit> name_in_desc;

    string name, val;

    for(size_t i = 0; i < n; ++i){
        file >> name >> val;
        name_in_desc[name] = Bit(val);
    }

    vector<Bit> desc(n);
    unordered_map<string, size_t> name_in_num;

    for(size_t i = 0; i < n; ++i){
        file >> name;
        desc[i] = name_in_desc[name];
        name_in_num[name] = i;
    }

    auto func_and = [](const Bit &l, const Bit &r)->Bit const
    {
        return (l & r);
    };

    Bit default_and;
    default_and.set();

    auto func_or = [](const Bit &l, const Bit &r)->bool
    {
        return (l | r);
    };

    Bit default_or;//по умолчанию - все биты равны нулям

    SegmentTree<Bit, decltype(func_and)> tree_and(desc.begin(), desc.end(), func_and, default_and);
    SegmentTree<Bit, decltype(func_or)> tree_or(desc.begin(), desc.end(), func_or, default_or);

    string name2, subset;
    Bit r_or, r_and, tmp;
    cout << "if you want to quit enter exit" << endl;

    do {
        cin >> name;
        if (name == "!subset"){
            cin >> subset;
            tmp = Bit(subset);
            cin >> name;
            cin >> name2;
            r_and = tree_and(name_in_num[name], name_in_num[name2]);
            r_and &= tmp;
            r_or = tree_or(name_in_num[name], name_in_num[name2]);
            r_or &= tmp;
            cout << "and = " << r_and << endl;
            cout << "or = " << r_or << endl;
            if (r_or.count()) //если делитель не ноль
                cout << r_and.count()/(double)r_or.count() << endl;
            else
                cout << "infinity" << endl;
        } else if (name != "exit"){
            cin >> name2;
            r_and = tree_and(name_in_num[name], name_in_num[name2]);
            r_or = tree_or(name_in_num[name], name_in_num[name2]);
            cout << "and = " << r_and << endl;
            cout << "or = " << r_or << endl;
            if (r_or.count()) //если делитель не ноль
                cout << r_and.count()/(double)r_or.count() << endl;
            else
                cout << "infinity" << endl;
        }


    } while (name != "exit");

    return 0;
}
