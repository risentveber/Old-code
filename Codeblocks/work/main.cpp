#include <iostream>
#include <list>
#include <stack>
#include <set>
#include <vector>
#include <deque>
#include <map>

using namespace std;
 template< class Type, template< class T, > class Container >
  class CrossReferences
  {
    Container< Type > mems;
    /* ... */
  };


int main()
{

  //CrossReferences< int, vector > cr1;
  CrossReferences< string, vector > cr2;
    return 0;
}
