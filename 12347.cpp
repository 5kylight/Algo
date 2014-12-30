#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <time.h>
using namespace std; 
template <class T>
class BSTree{
	

	struct Node{
		T val;
		unique_ptr<Node> left;
		unique_ptr<Node> right;
		Node(const T & value):val(value),left(nullptr),right(nullptr){}
	};


public:
	BSTree();
	BSTree(T val);
	~BSTree();
	void insert(const T & val);
	void postOrder();
private:
	unique_ptr<Node> root;
	void postOrder(const unique_ptr<Node> &p);
	void insert(const T & val, const unique_ptr<Node> & point);

};

template <class T>
BSTree<T>::BSTree():root(nullptr){}

template <class T>
BSTree<T>::BSTree(T val){
	root = unique_ptr<Node> (new Node(val));
	
}
template <class T>
void BSTree<T>::insert(const T & val, const unique_ptr<Node> & point )
{

		unique_ptr<Node> p(new Node(val));
		
			if(point -> val > val ){
				if(point-> left == nullptr){
					point-> left = move(p);
				}
				else {
					insert(val, point->left);
				}
			}
			else {
				if(point -> right == nullptr){
					point->right = move(p);
				}
				else {
					insert(val,point->right);
				}
			}
		
}


template <class T>
void BSTree<T>::insert(const T & val){
	if(root == nullptr){
		unique_ptr<Node> p(new Node(val));
		root = move(p);
	} else {
	insert(val,root);
	}
}



template <class T>
BSTree<T>::~BSTree(){} 



template <class T>
void BSTree<T>::postOrder(){
	postOrder(root);
}

template <class T>
void BSTree<T>::postOrder(const unique_ptr<Node> &p){
	
	if(p->left)postOrder(p-> left);
	if(p->right)postOrder(p-> right);
	printf("%d\n",(p -> val));

}
int main(){

	
	BSTree<int> tree;


	string line;

	vector< vector<int> > data; 


 	while(getline(cin, line )){
 
 		 	istringstream is (line);
 		data.push_back( 
 			vector<int>( 
 				istream_iterator<int>(is), istream_iterator<int>() ));


 	}


 		for ( vector<int> i : data){
 		tree.insert(i[0]);
 	}

	
	tree.postOrder();
	
}