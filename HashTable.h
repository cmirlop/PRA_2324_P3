#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../../Practica1/PRA_2324_P1/listLinked.h"

template <typename V>
class HashTable: public Dict<V>{
	private:
		int n;
		int max;
		ListLinked<TableEntry<V>>* table;
		
		int h(std:string key){
			int acumulador=0;
			for(int x=0; x<key.length();x++){
				acumulador+=int(key.at(x));
			}
			return acumulador%max;
		}

	public:
		//Metodos heredados
		void insert(std::string key, V value) override{
			if(search(key)){
				throw std::runtime_erro("El elemento ya esta incluido");
			}else{
				TableEntry c(key,value)
				table->insert(h(key));
			}
		}
		V search(std::string key) override{
			V aux = table->search(key);
			if(aux==NULL){
				throw std::runtime_error("No exite");
			}
			return aux;
		}
		V remove(std::string key) override{
			V aux = table->remove(key);
			if(aux == NULL){
				throw std::runtime_error("no existe");
			}
			return aux;
		}
		int entries() override{
			return n;
		}

		//Metodos propios
		HashTable(int size){
			table = new ListLinked<TableEntry<V>>;
			max =  size;
			n = 0;
		}
		~HasTable(){
			max = 0;
			n = 0;
			delete table;
		}
		int capacity(){
			return max;
		}
		friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
			for(int x = 0; x < n; x++){
				out << "(" << th.table -> data << ")" << std::endl;
				th.table = th.table->next; 
			}
			return out;
		}
		V operator[](std::string key){
			return search(key);
		}
};	
#endif
