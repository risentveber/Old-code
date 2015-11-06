#define DYNAMIC_LINK
#include <boost/program_options.hpp>
#include <ctime>
#include "experemental_graph.h"

using namespace std;
namespace po = boost::program_options;

const size_t ERROR_IN_COMMAND_LINE = 1;
const size_t SUCCESS = 0;

int main(int argc, char** argv)
{
    unsigned n = 100;
    unsigned w = 10;
    double p = 0.5;
    unsigned i = 100;

    po::options_description desc("Options");
    desc.add_options()
        ("help,h", "Print help messages")
        ("n,n", po::value<unsigned>(&n), "the number of verticies (default 100)")
        ("p,p", po::value<double>(&p), "the probability of edge (default 0.5)")
        ("w,w", po::value<unsigned>(&w), "the max flow of edge (default 100)")
        ("i,i", po::value<unsigned>(&i), "the number of experiments (default 100)");
    po::variables_map vm;

    try
    {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        if ( vm.count("help")  )
        {
            cout << "Basic Command Line Parameter App" << endl;
            cout << desc << endl;
            return SUCCESS;
        }
        po::notify(vm);
    }
    catch(po::error& e)
    {
        cerr << "ERROR: " << e.what() << endl << endl;
        cerr << desc << endl;
        return ERROR_IN_COMMAND_LINE;
    }


    {//проверка корректности данных
        if (n < 2u){
            cerr << "n is less than 2, the default value has set" << endl;
            n = 100;
        }

        if (w == 0u){
            cerr << "w is equal 0, the default value has set" << endl;
            w = 100;
        }

        if (i == 0u){
            cerr << "i is equal 0, the default value has set" << endl;
            i = 100;
        }

        if (p <= 0 || p > 1){
            cerr << "p isn't in (0; 1], the default value has set" << endl;
            p = 0.5;
        }

    }

    clock_t t = clock();

    Exp_grahp graph(n, w, p);

    cout << graph.research(i) << endl;

    t = clock() - t;
    cout << "Время эксперимента " << t/(double)CLOCKS_PER_SEC << endl;

    return SUCCESS;
}





