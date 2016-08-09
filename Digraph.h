#pragma once
#ifndef __BAG_H_INCLUDED__
#define __BAG_H_INCLUDED__
#include "Bag.h"

class Digraph {
private:
	unsigned int V; 
	unsigned int E; 
	std::vector<Bag<int> *> adj;

public:
	Digraph();
	Digraph(unsigned int V);
	~Digraph();
	unsigned int numVert() { return V; }
	unsigned int numEdges() { return E; }
	
	//add edge with tail v and head w
	void addEdge(unsigned int v, unsigned int w);

	//return edge list (as adjacency list)
	std::vector<Bag<int> *> getEdges() const {
		return adj;
	}

	//return a new Digraph with edges reversed
	Digraph reverse();

	//print graph to stdout
	friend std::ostream& operator<<(std::ostream& os, const Digraph & dg);
	void operator=(const Digraph & right); 
};

#endif