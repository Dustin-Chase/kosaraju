#pragma once
#include "stdafx.h"
#include "Digraph.h"
#include "Bag.h"

int main() {
	//test Bag functions
	Bag<int> bag;
	bag.add(1);
	bag.add(2);
	bag.add(3);

	std::cout << "Bag size is " << bag.size() << '\n'; 
	std::cout << "Bag contents are " << bag << '\n';
	
	//Test Digraph functions
	Digraph dg(3);
	dg.addEdge(1, 2);
	dg.addEdge(1, 3);

	dg.addEdge(2, 3);
	
	dg.addEdge(3, 1);
	std::cout << "Original graph is \n"; 
	std::cout << dg; 
	
	std::cout << "Graph reversed is \n";
	Digraph rev = dg.reverse(); 

	std::cout << rev; 

	
}