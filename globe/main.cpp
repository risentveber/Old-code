#include <iostream>
#include <string>
#include <vector>

using namespace std;


class tmpl_element
{
    public:
        string elem_str;
};

vector<tmpl_element> get_tmpl_elem(string &str)
{
    vector<tmpl_element> blocks;
    tmpl_element tmp_block;
    bool pc_is_D = false;
    for (unsigned i = 0; i < str.size(); ++i){
        while (str[i] == '*'){
            ++i;
            pc_is_D = true;
        }

        tmp_block.elem_str = "";

        while (str[i] != '*' && str[i] != '\0'){
            pc_is_D = false;
            tmp_block.elem_str += str[i];
            ++i;
        }

        if (!pc_is_D){
            blocks.push_back(tmp_block);
        }
    }
    return blocks;
}

int finder(tmpl_element &e, unsigned p, string &str)
{
    unsigned k;
    unsigned prev;
    for(unsigned i = p; i < str.size(); ++i){
        prev = i;
        k = 0;
        while (str[i] == e.elem_str[k] && e.elem_str[k] != '\0'){
            ++i;
            ++k;
        }
        if (e.elem_str[k] == '\0')
            return i;
        else
            i = prev;
    }
    return -1;
}

bool find_in_str(string &str, vector<tmpl_element> &elems)
{
    auto it = elems.begin();//текущее положение не найденной части
    int p = 0;//начиная с какой позиции выполнять поиск

    while (it != elems.end()){
        p = finder(*it, p, str);
        if (p == -1)
            return false;
        ++it;
    }

    return true;
}


int main()
{
    string str, tmpl;
    cout << "Пожалуйста введите шаблон" << endl;
    cin >> tmpl;
    cout << "Пожалуйста введите строку для поиска" << endl;
    cin >> str;
    //возможная проверка корректности ввода
    vector<tmpl_element> data = get_tmpl_elem(tmpl);
    if (find_in_str(str, data))
        cout << "Yes"<< endl;
    else
        cout << "No" << endl;

    return 0;
}

