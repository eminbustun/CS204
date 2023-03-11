// Bulent Emin Ustun
// 27822


#include "ActivityBST.h"
#include <string>
#include <iostream>

using namespace std;


string fill_with_zeros(int num_zeros, const string& input){ 

	int zeros_to_add = num_zeros - input.length();

	if (zeros_to_add < 0) zeros_to_add = 0;
	return string(zeros_to_add, '0') + input;

}

string number_to_time(int number){

	return fill_with_zeros(2, to_string(number/100))+":" + fill_with_zeros(2,to_string(number%100)); // function from previous homework, 1345 -> 13:45
}


inline bool legal_time(int time) { // checks the legality of time
	if (time > 2359 || time < 0)
		return false;
	if (time % 100 > 59 || time / 100 > 23)
		return false;
	return true;
}



void ActivityBST::add(int time, const string& activity){ // add function 

	if (legal_time(time) == true){ // checks the time legality. It will not proceed if the time is not legal.
		tree_node* newnode = new tree_node(time, activity);
		tree_node* nextItem;

		if (root == NULL){
			root = newnode;

			newnode->parent = nullptr;
			newnode->right = nullptr;
			newnode->left = nullptr;
		}

		else{
			nextItem = root;

			while(nextItem){

				if (time < nextItem->time){

					if(nextItem->left){

						nextItem = nextItem->left; // go left node
					}

					else{

						nextItem->left = newnode;
						newnode->parent = nextItem; // parent node
						newnode->right = nullptr;
						newnode->left = nullptr;
						break;
					}
				}
				else if (time > nextItem->time){
					if(nextItem->right){
						nextItem = nextItem->right; // go right node
					}
					else{
						nextItem->right = newnode;
						newnode->parent = nextItem; // parent node
						newnode->right = nullptr;
						newnode->left = nullptr;
						break;
					}
				}

			}

		}



	}

}


ActivityBST::ActivityBST(){

	root = nullptr; // initializing the member function
}


void ActivityBST::deleteTree(tree_node* root) { // helper function of the destructor. Since we use memory from heap, we must delete it.

	if (root == nullptr) return;
	// Delete the nodes in the left subtree
	deleteTree(root->left);
	// Delete the nodes in the right subtree
	deleteTree(root->right);
	// Delete `root`
	delete root;
}



ActivityBST::~ActivityBST(){ // destructor.

	deleteTree(root);



}

void insertion(tree_node *&rt, int time, const string& activity){ // insertion to tree. it helps the copy function., mostly it is the same as add function



	tree_node* newnode = new tree_node(time, activity);
	tree_node* nextItem;

	if (rt == NULL){
		rt = newnode;
		newnode->parent = nullptr;
		newnode->right = nullptr;
		newnode->left = nullptr;
	}

	else{
		nextItem = rt;

		while(nextItem){

			if (time < nextItem->time){

				if(nextItem->left){

					nextItem = nextItem->left;
				}

				else{

					nextItem->left = newnode;
					newnode->parent = nextItem; // parent node
					newnode->right = nullptr;
					newnode->left = nullptr;
					break;
				}
			}
			else if (time > nextItem->time){
				if(nextItem->right){
					nextItem = nextItem->right;
				}
				else{
					nextItem->right = newnode;
					newnode->parent = nextItem; // parent node
					newnode->right = nullptr;
					newnode->left = nullptr;
					break;
				}
			}
			else if (time == nextItem->time){ // I add the first root node before this function, that's why, I must check it like this.
				break;
			}

		}

	}
}

void ActivityBST::PrintPostOrder(tree_node* traverse, tree_node* adder)const{ // add traverse's nodes to the adder tree.

	if (traverse){
		int time = traverse->time;
		string act = traverse->activity;

		insertion(adder, time, act);

		PrintPostOrder(traverse->left, adder);

		PrintPostOrder(traverse->right, adder);

	}


}



tree_node* ActivityBST::COPY(tree_node* tre) const{ // helper function of copy constructor. Since it will be deep copy, it must replicate all the nodes that it copies from.
													

	if (root == NULL){

		return NULL;

	}

	else {

		tree_node* temp = root;
		int tm = temp->time;
		string act = temp->activity;
		tree_node* newRoot = new tree_node(tm, act);

		PrintPostOrder(temp,newRoot);

		return newRoot;
	}



}



ActivityBST::ActivityBST(const ActivityBST &copy){ // copy constructor. // it it was a shallow copy, I would do; root = copy.root;

	tree_node* getter = copy.getNode();

	root = copy.COPY(getter);



}



void ActivityBST::PrintInOrder(tree_node* rOOt) const{ // helper function of operator<<.



	if(rOOt){


		PrintInOrder(rOOt->left);

		cout << "[" << number_to_time(rOOt->time) << "] - " << rOOt->activity << endl; 

		PrintInOrder(rOOt->right);



	}



}


tree_node* ActivityBST::getNode()const{ // getting the node.

	return root;
}


ostream& operator<<(ostream &COUT,const ActivityBST &tree){ // operator<<

	tree_node* traverser = tree.getNode(); 



	tree.PrintInOrder(traverser);




	return COUT; // returning the ostream.

}


const ActivityBST & ActivityBST::operator=(const ActivityBST &rhs){ // operator=

	if (this != &rhs){ 


		tree_node* t = rhs.getNode();

		root = (rhs.COPY(t)); 

	}

	return *this;
}


tree_node* ActivityBST::Glue(tree_node* traverse, tree_node* adder)const{ // helper function of operator+

	if (traverse){
		int time = traverse->time;
		string act = traverse->activity;

		insertion(adder, time, act);

		Glue(traverse->left, adder);

		Glue(traverse->right, adder);

	}

	return adder;

}




void ActivityBST::setNode(tree_node* set){ // setting the node

	root = set;

}

ActivityBST operator+(const ActivityBST& lhs,const ActivityBST& rhs){ // operator+

	ActivityBST result;

	tree_node* rightHand = lhs.COPY(lhs.getNode());

	tree_node* leftHand = rhs.COPY(rhs.getNode());

	tree_node* glueBoth = lhs.Glue(leftHand, rightHand); // glueing the lhs and rhs, and creating a new root from + operator.


	result.setNode(glueBoth);



	return result;



}



const ActivityBST & ActivityBST::operator+=(const ActivityBST &rhs){ // += operator, rhs will be constant but left hand side cannot be constant since a +=b ---> a = a + b


	this->root = Glue(rhs.root, this->root);

	return *this;
}