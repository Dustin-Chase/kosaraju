#include "stdafx.h"
#include "Digraph.h"

Digraph::Digraph() : V{ 0 }, E{ 0 } { adj.push_back(new Bag<int>()); }
Digraph::Digraph(unsigned int V) : V{ V }, E{0} {
	for (unsigned int i = 0; i <= V; i++) {
		adj.push_back(new Bag<int>()); 
	}
}

Digraph::Digraph(const Digraph & toCopy) : E {toCopy.E}, V{toCopy.V}, adj(toCopy.adj.size()) {
	for (std::size_t i = 0; i < adj.size(); ++i) {
		adj[i] = new Bag<int>(*toCopy.adj[i]);
		for (std::size_t j = 0; j < adj[j]->size(); ++j) {
			adj[i]->putAt(j, toCopy.adj[i]->getAt(j));
		}
	}
	
}

Digraph::~Digraph()
{
	for (unsigned int i = 0; i < adj.size(); i++) {
		delete adj[i];
	}
}

void Digraph::addEdge(unsigned int v, unsigned int w)
{
	if (v >= adj.size()) throw std::invalid_argument("Digraph index out of range."); 
	adj[v]->add(w);
	E++;
}

Digraph Digraph::reverse()
{
	Digraph r(V);
	int i = 0;
	std::vector<Bag<int> *> list = this->getEdges();
	for (auto it = list.begin(); it != list.end(); ++it) {
		for (unsigned int j = 0; j < (*it)->size(); ++j) {
			r.addEdge((*it)->getAt(j), i);
		}
		i++;
	}
	return r;
}

void Digraph::operator=(const Digraph & right)
{
	V = right.V; 
	E = right.E; 
	adj = right.adj; 
}

std::ostream& operator<<(std::ostream& os, const Digraph & dg) {
	
	int i = 0; 
	std::vector<Bag<int> *> list = dg.getEdges(); 
	for (auto it = list.begin(); it != list.end(); ++it) {
		os << i << ": ";
		for (unsigned int j = 0; j < (*it)->size(); ++j) {
			os << (*it)->getAt(j) << " ";
		}
		i++; 
		os << '\n';
	}

	return os; 
}
