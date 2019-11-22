#include "experemental_graph.h"


Exp_grahp::Exp_result::Exp_result(unsigned k, unsigned i, double avg):
    ignored(i), all(k), average_flow(avg)
{
}

ostream& operator << (ostream& output, const Exp_grahp::Exp_result& g)
{
    output << "Из "<< g.all << " экспериметов " << g.ignored << " не учтено" << endl;
    output << "Средний поток " << g.average_flow;
    return output;
}
