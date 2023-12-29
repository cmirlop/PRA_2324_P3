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
		
		int h(std::string key){
			int acumulador=0;
			for(int x=0; x<key.length();x++){
				acumulador+=int(key.at(x));
			}
			return acumulador%max;
		}

	public:
		//Metodos heredados
		void insert(std::string key, V value) override{
			TableEntry<V> c(key,value);
			if(table[h(key)].search(key)!=-1){
				throw std::runtime_error("El elemento ya esta incluido");
			}else{
				table[h(key)].prepend(c);
			}
			n++;
		}
		V search(std::string key) override{
			
			V aux = table[h(key)].search(key); 
			
			

			if(aux==-1){
				throw std::runtime_error("No exite");
			}
			TableEntry<V> valor = table[h(key)].get(aux);
			return valor.value;
		}

		V remove(std::string key) override {
			V aux = table[h(key)].search(key); 
			if(aux==-1){
				throw std::runtime_error("No exite");
			}
			TableEntry<V> valor = table[h(key)].remove(aux);
			n--;
    			return valor.value;
		}

		int entries() override{
			return n;
		}

		//Metodos propios
		HashTable(int size){
			max = size;
			n=0;
			//table = new ListLinked<V>;
			//for(int x=0;x<size;x++){
				table = new ListLinked<TableEntry<V>>[size];
			//}
			
		
			
		}
		~HashTable(){
			max = 0;
			n = 0;
			delete[] table;
		}
		int capacity(){
			return max;
		}
		friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
			out << "HashTable( entries: " << th.n << " Capacidad: "<< th.max << ")"<<std::endl;
			for(int y=0; y< th.max; y++){
				out << "Modulo: " << y <<"[" <<std::endl;
				for(int x = 0; x < th.table[y].size(); x++){
					out << "(" << th.table[y].get(x) << ")" << std::endl;
				 
				}
				out << "]"<< std::endl;
			}
			//out << th.table;
			return out;
		}
		V operator[](std::string key){
			return search(key);
		}
};	
#endif
