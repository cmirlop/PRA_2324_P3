#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
	BSTree<TableEntry<V>>* tree;

    public:
        BSTreeDict(){
		tree = new BSTree<TableEntry<V>>;
	}
	~BSTreeDict(){
		delete tree;
	}
	friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
		out << bs.tree;
		return out;
	}        
	V operator[](std::string key){
		return tree->search(key);
	}
	
	//Metodos heredados
	virtual void insert(std::string key, V value) override{
		TableEntry<V>* aux(key,value);
		tree -> insert(aux);	
	}
	virtual V search(std::string key) override{
		return tree -> search(key);
	}
	virtual V remove(std::string key)override{
		return tree->remove(key);
	}
	virtual int entrie() override{
		return tree->size();
	}
};

#endif
