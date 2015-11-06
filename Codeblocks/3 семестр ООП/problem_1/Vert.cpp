#include "Vert.h"


void Vert::set(unsigned v, unsigned id)
{
	ident = id;
	vert = v;
}

void Vert::add_edge(unsigned id, shared_ptr<TWord> & ptr)
{
	v_list[id] = ptr;
}

void Vert::del_edge(unsigned id)
{
	v_list.erase(id);
}

void Vert::del_name(unsigned id)
{
	strcpy(v_list[id]->word, EMPTY);
}

void Vert::rename(unsigned id, TWord & word)
{
	*v_list[id] = word;
}

shared_ptr<TWord> Vert::name_of(unsigned id)
{
	auto it = v_list.find(id);
	if (it == v_list.end())
		return nullptr;
	else
		return it->second;
}

ostream & operator << (ostream & out, Vert & vert)
{
	auto it = vert.v_list.begin();
	auto it_end = vert.v_list.end();
	out << vert.vert << endl;
	for(; it != it_end; ++it){
		out << " --> " <<(*vert.v_graph)[it->first].vert << '\t' << (it->second)->word << endl;
	}
	return out;
}

maptype Vert::begin()
{
	return v_list.begin();
}

maptype Vert::end()
{
	return v_list.end();
}
