#include <iostream>
#include <vector>
#include <algorithm>
#include "cstdio"
using namespace std;


template<typename T>
void Do(T a)
{
    cout<<"Do<int>"<<endl;
}

template<>
void Do<int>(int a)
{
    cout<<"Do<> spec"<<endl;
}

void Do(int c)
{
    cout<<"Do()"<<endl;
}

int main()
{
    int a = 5;
    Do(a);
  return 0;
}