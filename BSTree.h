#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> 
class BSTree {
    private:
        int elem;
	BSNode<T> *root;
	BSNode<T>* search(BSNode<T>* n, T e)const {
		if(n == nullptr){
			throw std::runtime_error("Elemento no existente");
			return nullptr;
		}else if(n->elem > e ){
			return search(n->left,e);
		}else if(n->elem < e){
			return search(n->right,e);
		}
		return n;
	}
	BSNode<T>* insert(BSNode<T>* n, T e){
		if( n==nullptr){
			elem++;
			return new BSNode<T>(e);
		}else if(n->elem == e ){
			throw std::runtime_error("El elemento ya se encuentra");
		}else if(n->elem < e){
			n->right = insert(n->right,e);
		}else if(n->elem > e){
			n->left = insert(n->left,e);
		}
		return n;
	}
	BSNode<T>* remove(BSNode<T>* n, T e){
		if(n==nullptr){
			throw std::runtime_error("No se encuentra el elemento");
		}else if(e < n->elem){
			n->left = remove(n->left,e);
		}else if(e > n->elem){
			n->right = remove(n->right,e);
		}else{
			if(n->left != nullptr && n->right != nullptr){
				n->elem = max(n->left);
				n->left = remove_max(n->left);
			}else{
				
				if(n->left != nullptr ){
					n = n->left;
				}else{
					n = n->right;
				}
				elem --;
				
			}
		}
		return n;
	}
	T max(BSNode<T>* n)const {
		if(n ==nullptr){
			throw std::runtime_error("El elemento no se encuentra");
		}else if(n->right != nullptr){
			return max(n->right);
			
		}
		return n->elem;
	}
	BSNode<T>* remove_max(BSNode<T>* n){
		if(n->right == nullptr){
			BSNode<T>*aux = n->left;
			delete n;
			elem--;
			return aux;
		}
		n->right = remove_max(n->right);
		return n;
	}
	void delete_cascade(BSNode<T>* n){
		if( n==nullptr){
		}else if(n->left!=nullptr && n->right!=nullptr){
			delete_cascade(n->left);
			delete_cascade(n->right);
		}else if(n->left == nullptr && n->right !=nullptr){
			delete_cascade(n->right);
		}else if(n->left!=nullptr && n->right == nullptr){
			delete_cascade(n->left);
		}
		elem--;
		return delete n;
	}
	void print_inorden(std::ostream &out, BSNode<T>* n)const{
		
		if(n!=nullptr){
			print_inorden(out,n->left);
			out <<" "<< n->elem << " ";
			print_inorden(out,n->right);
		}	
		
	}
    public:
        BSTree(){
		elem = 0;
		root = nullptr;
		
		
	}
	int size(){
		return elem;
	}
	T search(T e) const{
		BSNode<T>* aux = search(root,e);
		return aux->elem;
	}
	T operator[](T e) const{
		return search(e);
	}
	friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
		bst.print_inorden(out,bst.root);
		return out;
	}
	void insert(T e){
		root = insert(root, e);
	}
	void remove(T e){
		root = remove(root,e);
	}
	~BSTree(){
		delete_cascade(root);
	}
    
};

#endif
