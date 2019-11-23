#include <queue>

#include "experemental_graph.h"

bool Exp_grahp::edge_exists()
{
    return (rand()/((double)RAND_MAX) < p);
}

bool Exp_grahp::edge_direction()
{
    return (rand()/((double)RAND_MAX) < 0.5);
}

Exp_grahp::Exp_grahp(unsigned new_n, unsigned new_w, double new_p) :
    n(new_n), w(new_w), p(new_p)
{
    srand(time(NULL));
    vertices.resize(n);
    edges.resize(n);
    for (auto it = edges.begin(); it != edges.end(); ++it)
        it->resize(n);
}

void Exp_grahp::random_initialization()
{
    Edge tmp;
    for(unsigned i = 0; i < n; ++i)
        for(unsigned j = 0; j < n; ++j)
            edges[i][j] = tmp;

    for(unsigned i = 0; i < n; ++i)
        for(unsigned j = i + 1; j < n; ++j)
            if (edge_exists()){
                //if (edge_direction()){
                    edges[i][j].c = rand_cap();
                    edges[i][j].in_graph = true;
                //}else{
                    edges[j][i].c = rand_cap();
                    edges[j][i].in_graph = true;
                //}
            }
}

Exp_grahp::Exp_result Exp_grahp::research(unsigned k)
{
    unsigned tmp_flow;
    unsigned ignored = 0;
    double average_flow;
    unsigned long long sum_flow = 0;

    for(unsigned i = 0; i < k; ++i){
        tmp_flow = max_flow();
        if (tmp_flow)
            sum_flow += tmp_flow;
        else
            ++ignored;
    }

    if (sum_flow)
        average_flow = sum_flow/(double)(k - ignored);
    else
        average_flow = 0;

    return Exp_result(k, ignored, average_flow);
}

unsigned Exp_grahp::max_flow()
{
    random_initialization();
    unsigned path_c;
    unsigned flow = 0;
    unsigned tmp, next;
    while (augmenting_path())
    {
        path_c = path_capacity();
        flow += path_c;

        next = SINK;
        tmp = SINK;
        while (tmp != SOURCE){
            tmp = vertices[next].parent;
            if (edges[tmp][next].in_graph){
                edges[tmp][next].flow += path_c;
                edges[tmp][next].c -= path_c;
                edges[next][tmp].c += path_c;
            }else{
                edges[next][tmp].flow -= path_c;
                edges[next][tmp].c += path_c;
                edges[tmp][next].c -= path_c;
            }
            next = tmp;
        }
    }
    return flow;
}

unsigned Exp_grahp::rand_cap()
{
    return 1 + rand() % w;
}

void Exp_grahp::clear_vertices()
{
    for(unsigned i = 0; i < n; ++i){
        vertices[i].used = false;
    }
}

bool Exp_grahp::augmenting_path()
{
    clear_vertices();
    queue<unsigned> alg_queue;
    alg_queue.push(SOURCE);
    vertices[SOURCE].used = true;
    unsigned tmp;
    while (!alg_queue.empty()){
        tmp = alg_queue.front();
        alg_queue.pop();
        for(unsigned i = 0; i < n; ++i)
            if (edges[tmp][i].c && !(vertices[i].used)){
                vertices[i].used = true;
                vertices[i].parent = tmp;
                if (i == SINK)
                    return true;
                alg_queue.push(i);
            }
    }

    return false;
}

unsigned Exp_grahp::path_capacity()
{
    unsigned min_c = w;
    unsigned next = SINK;
    unsigned tmp = SINK;
    while (tmp != SOURCE){
        tmp = vertices[next].parent;
        if (edges[tmp][next].c < min_c)
            min_c = edges[tmp][next].c;
        next = tmp;
    }
    return min_c;
}



