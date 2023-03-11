// Bulent Emin Ustun

// 27822


#include "sparse_matrix_2d_linked_list.h"
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;




// This function is reading the matrices.

row_node* read_matrix(const string& filename, int& num_rows, int& num_columns){

	string line, rows, cols;
	ifstream input;
	
	int line_counter = 0, number;
	input.open(filename);
	int FOR_HEAD = 0;
	
	cell_node* tail = new cell_node();
	cell_node* head = new cell_node();
	cell_node* for_temp = new cell_node();
	row_node* headROW = new row_node(); // Head pointer
	row_node* temp = new row_node();

	row_node* downRoad = new row_node();
	
	cell_node* cll = new cell_node();

	downRoad = nullptr;


	while(getline(input, line)){
		
		stringstream seperate(line);
		
		int column_number = 0;
		int counter = 0;
		 

		if(line_counter == 0){ 
				int space = line.find(' ');

				rows = line.substr(0, space); 
				cols = line.substr(space); 

				num_rows = stoi(rows);  // I found num_rows
				num_columns = stoi(cols); // I found num_columns
				
				
			}

		else if (line_counter > 0){ // These lines contains numbers that we will store in linkled list		

			while(seperate >> number){

			
				if(number != 0){
				
					temp->cell = new cell_node(); // I need to allocate a memory from a heap for every other nonzero element in the sparse matrix.
					
					temp->cell->column = column_number;temp->cell->value = number; // value of the cell // column num for cell
	
					if(FOR_HEAD == 0 && (temp->down == nullptr)){ // This if condition is needed because I appoint headROW to the temp.						


						headROW = temp; // It is the head pointer.

						
						FOR_HEAD++;
				
					}
											
					if(counter == 0){
						head = temp->cell; // The first head cell, will be the head of the cells
						head->left = nullptr; // There will be no left cells because head is the first cell.
						for_temp = head; // I appoint for_temp for head cell.
							if(num_columns == column_number + 1){  // If the column is finished....

							temp->cell->right = nullptr;
							tail = temp->cell;			
							}

					}
					
					else if(FOR_HEAD > 0){

						for_temp->right = temp->cell; // I connect nodes. 
						temp->cell->left = for_temp;   // 

						for_temp = temp->cell;
						if(num_columns == column_number + 1){ // If the column is finished....

							temp->cell->right = nullptr; 
							tail = temp->cell;
						}
					}

					counter++;					
					}

				column_number++;

				}								
			}	
						
			line_counter++;

			if(line_counter > 1 && line_counter < num_rows + 1){				
				
				row_node* downRoad = new row_node(); // new down node if the line is finished.
				temp->down = downRoad;

				temp = downRoad;			
				
			}		
			
		}			
							
	if(line_counter == num_rows + 1){ // If the rows finished, down node will be equal to nullptr.
		temp->down = nullptr;
		
	}
		
	row_node* tp = new row_node();

	tp = headROW;


	for(int j = 0; j < num_columns; j++){
	
		if(tp != nullptr){

			while( tp->cell != nullptr && tp->cell->left != nullptr){ // This function is needed because headrow is pointing the last column, with this for loop it points first column.
	
				tp->cell = tp->cell->left;
			
		
			}	
		
			tp = tp->down;
		}	
			
	}
	
	return headROW;
}

// This function is printing the matrices

void print_matrix(row_node* head, int num_rows, int num_columns){

	row_node* tpr = head; 
	cell_node* tprc = head->cell;
	

	for(int i = 0; i < num_rows; i++){

		for(int k = 0; k < num_columns; k++){

			if(tprc == nullptr ||tprc->column != k ){ 

				cout << 0 << " "; // If head->cell is nullptr or head->cell->column is not equal to k, print 0
			}
			else{

				cout << tprc->value << " ";
				tprc = tprc->right; // Go to the right cell.
			}
			
		}
		cout << endl;
		
		tpr = tpr->down;

		if(tpr != nullptr){
			tprc = tpr->cell;
		}
	}
	
}


// In this function, I add two matrices.

row_node* add_matrices(row_node* left, row_node* right, int num_rows, int num_columns){
	
	
	cell_node* for_temp = new cell_node();
	row_node* left_head = left;
	row_node* right_head = right;
	cell_node* head = new cell_node();
	cell_node* left_headCELL = left->cell;
	cell_node* right_headCELL = right->cell;
	
	
	
	row_node* resulting_matrix = new row_node();

	row_node* headER = resulting_matrix;

	cell_node* store_cell = resulting_matrix->cell;
	row_node* ss = new row_node();
	
	for(int i = 0; i < num_rows; i++){ // Iteratig for every row.
		int counter = 0;
		for(int j = 0; j < num_columns; j++){
			
			

			if((left_headCELL == nullptr ||left_headCELL->column != j) && (right_headCELL->column == j)){ // If left head node has no cell or its column is not equal to j
																										  // resulting matrix will have the right head cell value and its column.
				resulting_matrix->cell = new cell_node();
				resulting_matrix->cell->value = right_headCELL->value;
				
				right_headCELL = right_headCELL->right; // go the right cell in right head node.
				resulting_matrix->cell->column = j;
				

			}

			if((right_headCELL == nullptr ||right_headCELL->column != j) && (left_headCELL->column == j)){ // If right head node has no cell or its column is not equal to j
																										  // resulting matrix will have the left head cell value and its column number.
				resulting_matrix->cell = new cell_node();
				resulting_matrix->cell->value = left_headCELL->value;
				left_headCELL = left_headCELL->right; // go to the right cell in the left head node.
				resulting_matrix->cell->column = j;
				
			}

			else if((right_headCELL == nullptr ||right_headCELL->column != j) && (left_headCELL == nullptr ||left_headCELL->column != j)){ // If both cells are equal to null or their column number is not equal to j
																																		   // we change nothing and both matrices will not go to the right because their column number is not equal to j.

				

			}

			else if((left_headCELL->column == j) && (right_headCELL->column == j)){ // If both cells have the column numbers equal to the j, the reaulting matrices cell will be qual to addition of their values.

				if(left_headCELL->value + right_headCELL->value != 0){ // If this addition is equal to 0, then we cannot store this in the matrix.
					resulting_matrix->cell = new cell_node();
					resulting_matrix->cell->value = left_headCELL->value + right_headCELL->value;
					resulting_matrix->cell->column = j;
				
					if(left_headCELL->right != nullptr && right_headCELL->right != nullptr){ // If both matrices have right cells...
						left_headCELL = left_headCELL->right;
						right_headCELL = right_headCELL->right;
					}
				}
			}

			if(resulting_matrix->cell != nullptr && resulting_matrix->cell->column == j){ // If resulting matrix->cell is not equal to nullptr and it's cell column number is equal to j...


				if(counter == 0){ // I iterate counter if the cell->value is not equal to 0

					head = resulting_matrix->cell; // firs cell of a row will be the head.
					head->left = nullptr; // there can be no left cell because head cell is the first cell of this row.
					for_temp = head; // keeping the cell value in a different cell_node pointer because I will need it when I connect cells.
				


					resulting_matrix->cell->right = nullptr; // For not confusing me, I append right of the first cell to the nullptr. (It changes when counter > 0).
								
						
				}
				if(counter > 0){ // If there are another cell whose value is not equal to 0...

					for_temp->right = resulting_matrix->cell; // Like I said on the top, that's why I kept the for_temp pointer. Now, head's right is eqaul to new cell.
					resulting_matrix->cell->left = for_temp; // I appoint the new cell's left to the head.

				

					for_temp = resulting_matrix->cell; // This is the new for temp for another new cells. Because whenever we get a new cell value they must form a connection betwwen the right and the left cells.
				}
				

			
				counter++; // counter is increasing if we have a value other than 0 and column number equals to j.
			}
		}

		if(left_head->down != nullptr && right_head->down != nullptr){ // If matrices that are add have down rows, proceed...
			left_head = left_head->down;
			left_headCELL = left_head->cell;
			right_head = right_head->down;
			right_headCELL = right_head->cell;

			row_node* downRoad = new row_node(); // new row_node for down row.
			resulting_matrix->down = downRoad;  // (connection)

			resulting_matrix = downRoad; // I appoint new down row node to the current resulting matrix, with this I do not need to create another loop.
			
		}
		

	}

	row_node* tp = new row_node();

	tp = headER; // For not losing the head pointer.

	for(int j = 0; j < num_columns; j++){ // My head pointer is pointing to the first node but it is not pointing to the first column, so that's why I added this for loop.
	
		if(tp != nullptr){ 


			while( tp->cell != nullptr && tp->cell->left != nullptr){ 

		
		
				tp->cell = tp->cell->left; 
		
	
		
			}	
		
			tp = tp->down;
		}	
			
	}

	return headER; 
	
}


// In delete_matrix function, firstly I delete all the cells of the first row, then I go for second row, and do the same until there is no row to be deleted.

void delete_matrix(row_node* head){ 

	row_node* ptr = new row_node();

	cell_node* cll = new cell_node();

	while (head){ // If head exists...


		while(head->cell){ // if head->cell exists

			cll = head->cell->right; // I appoint head->cell->right to cll because if I delete the head->cell without appointing the right, I cannot reach the right cell.
			delete head->cell;
			head->cell = cll; // new head->cell

		}

		ptr = head->down; // when I delete the first row, I go for another row
		delete head; 
		head = ptr; // new head node is the head->down node.

	}



}



