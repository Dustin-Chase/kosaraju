#pragma once
#include "stdafx.h"

template<class T>
class Bag {
private:
	class Node {
	private: 
		T data;
	public: 
		Node(T d) : data{d} {}
		T getData() { return data;  }
		friend std::ostream& operator<<(std::ostream& os, const Node & toPrint) {
			os << toPrint.getData(); 
			return os; 
		}
	};

	std::vector<Node *> bag; 

public: 
	Bag() : bag(0) {	}
	Bag(unsigned int sz) : bag(sz) { }
	void add(T t) {
		bag.push_back(new Node(t));
	}

	unsigned int size() {
		return bag.size();
	}

	T getAt(unsigned int v) {
		return bag[v]->getData(); 
	}

	friend std::ostream& operator<<(std::ostream& os, const Bag & toPrint) {
		for (auto it = toPrint.bag.begin(); it != toPrint.bag.end(); ++it) {
			os << (*it)->getData() << " ";
		}
		os << '\n';
		return os; 
	}
	

	~Bag() {
		for (unsigned int i = 0; i < bag.size(); ++i) {
			delete bag[i];
		}
	}

};


