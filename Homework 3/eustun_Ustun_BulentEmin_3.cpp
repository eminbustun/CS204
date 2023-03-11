
// Bulent Emin Ustun

#include "activity_bst.h"

#include <iostream>

#include <string>

using namespace std;

// PROTOTYPES /////

bool time_check_for_add_activity(int time, const string &activity);

string fill_with_zeros(int num_zeros, const string& input);

string number_to_time(int number);

void finder (tree_node* root, int time);

int most_left_node (tree_node* root);

int most_right_node (tree_node* root);

///////////////////////////////////////////


void insertion(tree_node *&root, int time, const string& activity){ // insertion to tree


	if (time_check_for_add_activity(time, activity) == true){
		tree_node* newnode = new tree_node(time, activity);
		tree_node* nextItem;

		if (root == NULL){
			root = newnode;
			cout << "Added activity \'" << activity << "\' at " << number_to_time(time) << endl;
			newnode->parent == nullptr;
			newnode->right = nullptr;
			newnode->left = nullptr;
		}

		else{
			nextItem = root;

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
						cout << "Added activity \'" << activity << "\' at " << number_to_time(time) << endl;
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
						cout << "Added activity \'" << activity << "\' at " << number_to_time(time) << endl;
						break;
					}
				}
				
			}

		}



	}
}


bool time_check_for_add_activity(int time, const string &activity){ // time check for add activity. I seperate them according to their length

	string time_str = to_string(time);

	if (time_str.length() == 4){

		string hour_part = time_str.substr(0,2);

		string minute_part = time_str.substr(2);

		int hour = stoi(hour_part);

		int min = stoi(minute_part);

		if(hour >= 0 && hour <= 23){

			if(min >= 0 && min <= 59){
				return true;
			}
			else
			{
				cout << "ERROR! Could not add activity \'" << activity << "\' due to illegal time value" << endl;
				return false;
			}
		}
		else{
			cout << "ERROR! Could not add activity \'" << activity << "\' due to illegal time value" << endl;
			return false;
		}
	}
	else if (time_str.length() == 3){

		string hour_part = time_str.substr(0,1);

		string minute_part = time_str.substr(1);

		int hour = stoi(hour_part);

		int min = stoi(minute_part);

		if(hour >= 0 && hour <= 23){

			if(min >= 0 && min <= 59){
				return true;
			}
			else{
				cout << "ERROR! Could not add activity \'" << activity << "\' due to illegal time value" << endl;
				return false;
			}
		}
		else{
			cout << "ERROR! Could not add activity \'" << activity << "\' due to illegal time value" << endl;
			return false;
		}
	}

	else if(time_str.length() == 2){

		int time_int = stoi(time_str);

		if (time_int >= 0 && time_int <= 59){

			return true;

		}
		else{

			cout << "ERROR! Could not add activity \'" << activity << "\' due to illegal time value" << endl;
			return false;
		}

	}
	else if (time_str.length() == 1){

		int tm = stoi(time_str);

		if (tm >= 0 && tm <= 9){

			return true;
		}

		else {
			cout << "ERROR! Could not add activity \'" << activity << "\' due to illegal time value" << endl;
			return false;
		}
	}

	else {
		cout << "ERROR! Could not add activity \'" << activity << "\' due to illegal time value" << endl;
		return false;
	}

	return false;

}



bool time_check_for_print_activity(int time){ // time check for print activity. I seperate them according to their length

	string time_str = to_string(time);

	if (time_str.length() == 4){

		string hour_part = time_str.substr(0,2);

		string minute_part = time_str.substr(2);

		int hour = stoi(hour_part);

		int min = stoi(minute_part);

		if(hour >= 0 && hour <= 23){

			if(min >= 0 && min <= 59){
				return true;
			}
			else
			{
				cout << "ERROR! Could not add activity at specific time due to illegal time value" << endl;
				return false;
			}
		}
		else{
			cout << "ERROR! Could not add activity at specific time due to illegal time value" << endl;
			return false;
		}
	}
	else if (time_str.length() == 3){

		string hour_part = time_str.substr(0,1);

		string minute_part = time_str.substr(1);

		int hour = stoi(hour_part);

		int min = stoi(minute_part);

		if(hour >= 0 && hour <= 23){

			if(min >= 0 && min <= 59){
				return true;
			}
			else{
				cout <<  "ERROR! Could not add activity at specific time due to illegal time value" << endl;
				return false;
			}
		}
		else{
			cout <<  "ERROR! Could not add activity at specific time due to illegal time value" << endl;
			return false;
		}
	}

	else if(time_str.length() == 2){

		int time_int = stoi(time_str);

		if (time_int >= 0 && time_int <= 59){

			return true;

		}
		else{

			cout << "ERROR! Could not add activity at specific time due to illegal time value" << endl;
			return false;
		}
	}
	else if (time_str.length() == 1){

		int tm = stoi(time_str);

		if (tm >= 0 && tm <= 9){

			return true;
		}

		else {
			cout << "ERROR! Could not add activity at specific time due to illegal time value" << endl;
			return false;
		}
		return false;
	}

	else{
		cout << "ERROR! Could not add activity at specific time due to illegal time value" << endl;
		return false;
	}

	return false;
}


string fill_with_zeros(int num_zeros, const string& input){

	int zeros_to_add = num_zeros - input.length();

	if (zeros_to_add < 0) zeros_to_add = 0;
	return string(zeros_to_add, '0') + input;

}

string number_to_time(int number){

	return fill_with_zeros(2, to_string(number/100))+":" + fill_with_zeros(2,to_string(number%100));
}


void add_activity(tree_node *&root, int time, const string &activity){ // add activity function

	insertion(root, time, activity);
}




tree_node compare(tree_node* node1, tree_node* node2, int time){ // comparing nodes according to their time. // this function implemented in print activity function

	if (node1->time > time && node2->time < time){

		return *node2;
	}

	else if (node1->time < time && node2->time > time){

		return *node1;
	}

	else {

		return *node1;
	}
}




bool print_activity_as_bool(tree_node* node, int time){ // this function implements print activity


	tree_node* traverse;

	traverse = node;

	tree_node* bef;
	bef = nullptr;

	tree_node* keeper;
	keeper = nullptr;

	while(traverse){

		if (time > traverse->time){

			keeper = traverse;

			if (traverse->right){
				traverse = traverse->right;
			}
			else{
				break;
			}
		}

		else if (time < traverse->time) {



			if (traverse->left){
				traverse = traverse->left;
				bef = traverse;
			}
			else{
				break;
			}
		}

		else if (time == traverse->time){
			cout << "Time: " << number_to_time(time) << ", Activity: " << traverse->activity << endl;
			return true;
			break;

		}





	}

	if (node == NULL){

		cout << "Time: " << number_to_time(time) << ", Activity: free" << endl;
		return false;

	}	


	if (time < most_left_node(node) && time >= 0){

		cout << "Time: " << number_to_time(time) << ", Activity: free" << endl;
		return true;
	}


	if (bef != nullptr && keeper != nullptr){

		*keeper = compare(bef, keeper, time);
	}

	else if (bef == nullptr && keeper != nullptr){

		*keeper = *keeper;

	}
	else if (bef != nullptr && keeper == nullptr){

		*keeper = *bef;


	}


	tree_node* temp;

	temp = node;


	if (keeper->right != NULL){

		cout << "Time: " << number_to_time(time) << ", Activity: " << keeper->activity << endl;

		return true;

	}

	else if (keeper->time != most_right_node(node) && keeper->right == NULL && keeper->parent && keeper->parent->right &&  keeper == keeper->parent->right){


		cout << "Time: " << number_to_time(time) << ", Activity: " << keeper->activity << endl;
		return true;
	}
	else if (keeper->right == NULL && keeper->parent && keeper->parent->left &&keeper == keeper->parent->left){




		cout << "Time: " << number_to_time(time) << ", Activity: " << keeper->activity << endl;
		return true;
	}

	else if (keeper->left == NULL && keeper->parent && keeper->parent->left && keeper == keeper->parent->left){


		cout << "Time: " << number_to_time(time) << ", Activity: " << keeper->activity << endl;
		return true;
	}

	else {
		cout << "Time: " << number_to_time(time) << ", Activity: " << keeper->activity << endl;
		return true;
	}

	return false;

}





void print_activity(tree_node *root, int time){ // print activity



	if(time_check_for_print_activity(time) == true){ // time check

		print_activity_as_bool(root, time);
		return;



	}
}	







void delete_tree(tree_node *root) { // delete function (recursive)

	if (root != NULL) {

		delete_tree(root->left);

		delete_tree(root->right);

		delete root;
	}
}



void print_all_activities(tree_node *root){ // I used DisplayInOrder function. This is a recursive function.

	if (root){

		print_all_activities(root->left);

		cout <<"[" << number_to_time(root->time) <<"]"<< " - " << root->activity << endl;


		print_all_activities(root->right);
	}

}








int most_right_node (tree_node* root){ // gives the rightest nodes time

	tree_node* temp;

	temp = root;

	while(temp->parent){

		temp = temp->parent;

	}


	while (temp->right){

		temp = temp->right;

	}
	return temp->time;

}



int most_left_node (tree_node* root){ // gives the rightest nodes time

	tree_node* temp;

	temp = root;

	while(temp->parent){

		temp = temp->parent;

	}


	while (temp->left){

		temp = temp->left;

	}
	return temp->time;

}



string act_giver(tree_node* root){ // gives the activity of a node.

	tree_node* temp;

	temp = root;


	return temp->activity;

}




void finder (tree_node* root, int time){ // helper function of print activity and duration function.




	static bool status = false;
	


	if (root){

		static string str;
		finder(root->left, time);

		if (time == root->time){

			cout << "Time period: ["<< number_to_time(root->time) << " - ";
			status = true;
			str = act_giver(root);
			if (most_right_node(root) == time){

				cout << number_to_time(0) << "]:" << root->activity << endl;
				status = false;



			}
			

		}

		else if (status == true && time < root->time){

			cout << number_to_time(root->time) <<"]: " << str << endl;
			status = false;

		}




		finder(root->right, time);



	}





}



void print_activity_and_duration(tree_node *root, int time){



	if(time_check_for_print_activity(time) == true){

		if (root == NULL){

			cout << "Time period: [" << number_to_time(0) << " - " << number_to_time(0) << "]: free" << endl;
			return;
		}


		if(root->left == nullptr && root->right == nullptr && root->time == 0){

			cout <<"Time period: ["<< number_to_time(root->time) << " - "<< number_to_time(0) <<"]: " <<  root->activity << endl;
			return;

		}


		tree_node* rt;
		rt = root;


		while (rt->left){

			rt = rt->left;

		}

		if (time < rt->time){

			cout << "Time period: ["<<number_to_time(0) <<" - "<< number_to_time(rt->time) << "]: "<< "free" << endl;
			return;

		}


		tree_node* temp;

		temp = root;


		while (temp){


			if(time == temp->time){

				finder(root, time);
				break;
			}

			else if (time < temp->time){

				if(temp->left && temp->left->right){


					if (time < temp->time && time > temp->left->right->time){

						cout <<"Time period: ["<< number_to_time(temp->left->right->time) << " - "<< number_to_time(temp->time)<<"]: " <<temp->left->right->activity  << endl;
						break;

					}
				}

				else if (temp->left){

					if (time < temp->time && time > temp->left->time){

						cout << "Time period: ["<< number_to_time(temp->left->time) << " - " << number_to_time(temp->time) <<"]: " << temp->left->activity << endl;
						break;

					}

				}



				temp = temp->left;
			}

			else if (time > temp->time) {

				if(temp->right && temp->right->left){


					if (time > temp->time && time < temp->right->left->time){

						cout << "Time period: ["<<  number_to_time(temp->time) << " - " <<  number_to_time(temp->right->left->time) << "]: " << temp->activity << endl;
						break;

					}
				}

				else if (temp->right){

					if (time > temp->time && time < temp->right->time){
						cout << "Time period: ["<<  number_to_time(temp->time) << " - " <<  number_to_time(temp->right->time) << "]: " << temp->activity << endl;
						break;

					}

				}



				temp = temp->right;

			}

			if ((temp->right == NULL) && (temp->parent && temp->time > temp->parent->time) && (time > temp->time)){ cout << "Time period: ["<< number_to_time(temp-> time) << " - " << number_to_time(0) <<"]: " << temp->activity  << endl;break;}
		}




	}



}





bool is_ZERO (tree_node* root){ // this function checks if the tree node includes node->time == 0.

	if (root){

		is_ZERO(root->left);


		if (root->time == 0){

			return false;
		}
		else {

			return true;
		}


		is_ZERO(root->right);
	}


}



/////////////////// gloabal bools ///////////////

bool status = true;
bool is_null = false;
bool freeBOOL = true;

bool mode = true;


/////////////////// gloabal bools ///////////////

void print_single_activity(tree_node *root, const string &activity){ 

	static string act;

	


	if (root){
		
		is_null = true;

		print_single_activity(root->left, activity);



		if (is_ZERO(root) == true && freeBOOL == true && activity == "free"){

			if (is_ZERO(root) == true && root->activity == activity){
				cout <<"Time period: [" << number_to_time(0) <<" - " << number_to_time(0) << "]: " << root->activity << endl;
				
				freeBOOL = false;
				return;
				
			}

			else {

				cout <<"Time period: [" << number_to_time(0) <<" - " << number_to_time(most_left_node(root)) << "]: free" << endl;
				freeBOOL = false;
				return;
				
			}

		}


		if (mode && root->activity == activity){

			if (root->time == most_right_node(root)){

				//cout << "Time period: [" << number_to_time(root-> time) << " - " << number_to_time(0) <<"]: " << root->activity << endl;
				
			}
			

			else {
				cout <<  "Time period: [" << number_to_time(root-> time) << " - ";
				act = root->activity;
				status = false;
				mode = false;
			}
		}

		

		else if (mode == false && status == false /*&& root->activity != activity*/){
			cout << number_to_time(root-> time)<<"]: "<< act << endl;
			status = true;
			mode = true;
			


		}

		if(root->time == most_right_node(root)){

			if (root->activity == activity){
				cout << "Time period: [" << number_to_time(root-> time) << " - " << number_to_time(0) <<"]: " << root->activity << endl;
				
			}

			freeBOOL = true;
			mode = true;
		}



		print_single_activity(root->right, activity);
		
	}

	

	else if (is_null == false && root == nullptr){

		cout <<"Time period: [" << number_to_time(0) <<" - " << number_to_time(0) << "]: free" << endl;
		
	}

	
}