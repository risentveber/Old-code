#define BOOST_TEST_MODULE binomial_heap_test
#include <boost/test/included/unit_test.hpp>
#include "binomial_heap.hpp"
#include <iostream>
#include <set>

#define NUM 50

using namespace std;


string gen_str(unsigned n)
{
    string result;
    result.resize(n);
    for(unsigned i = 0; i < n; ++i)
        result[i] = 'A' + rand()/('A' - 'z');
    return result;
}

BOOST_AUTO_TEST_SUITE ( binomial_heap )

BOOST_AUTO_TEST_CASE( test_1 )
{
    srand(time(NULL));

    Binomial_heap<int> heap;
    for(int i = 999999; i >= 0; --i)
        heap.insert_item(i);

    for(int i = 0; i < 1000000; ++i){
        BOOST_CHECK(heap.minimum() == i);
        heap.extract_min();
    }
}


BOOST_AUTO_TEST_CASE( test_2 )
{
    Binomial_heap<string> heap;
    set<string> base;
    string tmp;
    for(unsigned i = 0; i <= 1000; ++i){
        tmp = gen_str(NUM);
        heap.insert_item(tmp);
        base.insert(tmp);
    }

    for(unsigned i = 0; i <= 1000; ++i){
        BOOST_CHECK(heap.minimum() == *base.begin());
        base.erase(base.begin());
        heap.extract_min();
    }
}

BOOST_AUTO_TEST_SUITE_END( )



//int main()
//{
//    srand(time(NULL));
//    cout << gen_str(100) << endl;
//    return 0;
//}
