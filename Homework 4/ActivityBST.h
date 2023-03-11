// Bulent Emin Ustun
// 27822

// I started the code with header guards.
#ifndef ACTIVITY_H_  
#define ACTIVITY_H_

#include<string>
#include<iostream>

using namespace std;

struct tree_node{ 
	int time;
	string activity;
	tree_node* right;
	tree_node* left;
	tree_node* parent;

	tree_node(int t, const string& a): time(t), activity(a),
		right(nullptr), left(nullptr), parent(nullptr){}
};

class ActivityBST{

public:

	ActivityBST(); // constructor


	~ActivityBST(); // destructor


	ActivityBST(const ActivityBST &); // copy constructor


	void deleteTree(tree_node* rt); // destructor helper


	void setNode(tree_node* rOOt); // setting the node


	void add(int time, const string& activity); // add function


	void PrintInOrder(tree_node* rOOt) const; // helper of << operator
	

	tree_node* getNode() const; // getting the root
	

	void PrintPostOrder(tree_node* traverse,tree_node* adder)const; // Insert a root from a different root in post order.


	tree_node* COPY(tree_node* tre) const; // helper function of copy constructor


	tree_node* Glue(tree_node* traverse,tree_node* adder) const; // helper function for operator+
	

	const ActivityBST& operator=(const ActivityBST &); 
	

	friend ostream& operator<<(ostream& COUT, const ActivityBST & tree); // declaration of operator <<
	
	
	friend ActivityBST operator+(const ActivityBST& lhs,const ActivityBST& rhs);


	const ActivityBST& operator +=(const ActivityBST& rhs); 

private:

	tree_node* root; // member function

};
#endif