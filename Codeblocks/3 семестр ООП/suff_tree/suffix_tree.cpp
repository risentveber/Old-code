#include "suffix_tree.h"
///все индексы - с нулевого по строчкам
SuffixTree::SuffixTree(const wstring &str) : text(str)
{
    build();
}

void SuffixTree::build_from(const wstring &str)
{
    text = str;
    build();
}

int evolution(wstring s, int from_1, int to_1, int from_2, int to_2)
{
    int i;
    for(i = 0; i < to_1 && i < to_2 && s[from_1 + i] == s[from_2 + i]; i++){}
    return i;
}

void SuffixTree::build()
{
    vertexes.clear();
    vertexes.push_back(Suff_vrtx(0));

    int n = text.length();
    if (n == 0)
        return;
    vertexes.push_back(Suff_vrtx(1, 0));///элемент с инд 1 - лист с нулевым номером родитель - ноль default
    vertexes.back().set_from(0);
    vertexes[0].link(text[0], 1);

    int End = 1;
    int p;
    int tmp_from, tmp_to;
    int len;

    n = n - 1;
    int Ji_num = 1; ///номер ноды обозначающей последний созданный лист
    int Ji = 0;
    for (int i = 0; i < n; ++i){///выполнение i + 1 продления
        End++;
        p = vertexes[Ji_num].parent;
        for (Ji++; Ji <= i; Ji++){///выполняем пока не встретим 3 тип продления
            tmp_from = max(Ji, vertexes[Ji_num].from)
            tmp_to = vertexes[p].to + 1;
            ///проверяем можно ли пойти по ссылке по tmp_from - символу
            if
            if (Ji == i)
                break;
        }

    }

}


