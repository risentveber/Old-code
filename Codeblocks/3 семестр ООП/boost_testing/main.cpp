#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>
#include <list>

boost::test_tools::predicate_result validate_list(std::list<int>& L1)
{
  std::list<int>::iterator it1 = L1.begin( );
  for (; it1 != L1.end( ); ++it1)
   {
     if (*it1 <= 1) return false;
   }
  return true;
}

BOOST_AUTO_TEST_SUITE ( test )

BOOST_AUTO_TEST_CASE( test )
{
    std::list<int> list1(4, 2);
    BOOST_CHECK( validate_list(list1) );
}

BOOST_AUTO_TEST_SUITE_END( )
