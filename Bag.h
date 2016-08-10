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
	Bag(const Bag & toCopy);
	void add(T t) {
		bag.push_back(new Node(t));
	}

	unsigned int size() {
		return bag.size();
	}

	T getAt(unsigned int v) {
		return bag[v]->getData(); 
	}

	void putAt(unsigned int v, T d);

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

template<class T>
inline Bag<T>::Bag(const Bag & toCopy) : bag(toCopy.bag.size()) 
{
	for (std::size_t i = 0; i < bag.size(); i++) {
		bag[i] = new Node(*toCopy.bag[i]);
	}
}

template<class T>
inline void Bag<T>::putAt(unsigned int v, T d)
{
	bag[v] = new Node(d); 
}
