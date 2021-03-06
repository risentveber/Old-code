#include "base_of_string.hpp"
#include <fstream>
#include <boost/filesystem.hpp>


using namespace std;

void Base_of_string::add(wstring &word_base)
{
    Word cur_word;
    cur_word.name = word_base;

    word_base.resize(word_base.length() - 2);//усечение окончания

    wstring tmp;

    tmp = L' ' + word_base + L"ой" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"ый" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"ий" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"ое" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"ее" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"ая" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"яя" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"ые" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"ие" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"ого" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"ых" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"их" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"ому" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"ым" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"им" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"ую" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"юю" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"ою" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"ыми" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"ими" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"ом" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));
    tmp = L' ' + word_base + L"ий" + L' ';
    cur_word.num.push_back(tree.add_string(tmp));

    words.push_back(cur_word);

}

void Base_of_string::clear()
{
    words.clear();
    tree.clear();
}

void Base_of_string::analyse()
{
    //подсчет
    tree.find_in(all_text);

    //вывод результатов
    long long unsigned result, tmp;
    for (auto it = words.begin(); it != words.end(); ++it){
        result = 0;

        for (auto k = it->num.begin(); k != it->num.end(); ++k){
            tmp = tree.count_of_word(*k);
            result += tmp;
            if (tmp)
                wcout << tree.word(*k) << " : " << tmp << endl;
        }
        wcout << L"Всего вхождений слова \"" << it->name << L"\" : " << result << endl;
    }
}

void Base_of_string::add_files(const wstring &encode, const vector<wstring> &files)
{
    locale loc;
    if (encode == L"utf8")
        loc = locale("ru_RU.UTF-8");
    else
        loc = locale("ru_RU.CP1251");

    wstring str;
    for (auto it = files.begin(); it != files.end(); ++it){

        boost::filesystem::wifstream input(*it);
        input.imbue(loc);

        getline(input, str);
        while (input){
            if (str != L"" ){
                preprss(str, loc);
                all_text += str;
            }
            getline(input, str);
        }
        input.close();

    }
}
