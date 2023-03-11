

// Bulent Emin Ustun 27822

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>


using namespace std;




void Print(const vector<vector<int> > & mat) // This function print the matrices with a good shape(space between the elements of the matrix).
{
    for (unsigned int j=0; j < mat.size(); j++)
    {   
		for (unsigned int k=0; k < mat[0].size(); k++)
        {   

			cout << setw(5) << mat[j][k];
        }
        cout << endl;
    }
}



void Matrix_Multiplication(vector<vector<int>> & matLHS, vector<vector<int>> & matRHS ,vector<vector<int>> & matRES){
	int addition_of_MINUSs;
	
	vector<int> results;
	vector<int> minus;
	vector<int> temp;
	vector<vector<int>> RHS_coefficient;
	vector<int> results_of_minuses;
	vector<vector<int>> DEPO;
	for (unsigned int j=0; j < matLHS.size(); j++){  
		int minus1_NUMBER = 0;
		int result = 0;
		for(unsigned int q = 0; q < matRHS.size(); q++){

			if (matLHS[j][q] != -1){
				result +=  matLHS[j][q] * matRHS[q][0];

			}
			else if (matLHS[j][q] == -1){ // When matLHS[j][q] is equals to -1.
				vector<int> coefficient;
				temp.push_back(j); 
				temp.push_back(q); 
				//temp.push_back(matLHS[j][q]);
				DEPO.push_back(temp);
				coefficient.push_back(matRHS[q][0]);
				RHS_coefficient.push_back(coefficient);
				
				

				minus1_NUMBER++;
				
				
			}

			bool hard = true;

			while((q == matRES.size() -1) && hard) {

				cout << minus1_NUMBER << endl;
				
				

				
				hard = false;


			}
			temp.clear();
			
			
		}

		minus.push_back(minus1_NUMBER);
		results.push_back(result);
		//cout << result << endl;
		
    }

	cout << endl << endl;

	for(unsigned int o = 0; o < results.size(); o++){ // This gives the addition of minuses.

		addition_of_MINUSs = matRES[o][0] - results[o];
		results_of_minuses.push_back(addition_of_MINUSs);
		cout << addition_of_MINUSs << endl;

		
		
		
	}





	cout << endl << endl;

	



	//Print(DEPO);

	cout << endl << endl;

	
	}

	// Input check for LHS MATRIX
int Input_Check_FOR_LHS_MATRIX(ifstream &input, ofstream &out, vector<vector<int>> & MATRIX_LHS){ // This function is checking the LEFT HAND SIDE (LHS) matrix if its implemented correctly.

	vector <int> vec_for_lhs;
	string lines, rows, columns;
	int line_counter =  0, num_rows, num_columns, number, word_counter = 0;

	while(getline(input, lines)){
		
			stringstream seperateWords(lines);

			if(line_counter == 0){
				int space = lines.find(' ');

				rows = lines.substr(0, space); /* I turned strings to integers */
				columns = lines.substr(space); 

				num_rows = stoi(rows);
				num_columns = stoi(columns);
				
			}

			else if (line_counter > 0){

				//cout << lines << endl;

				while (seperateWords >> number){ /* I found the number of columns and checked them. */
				
					if ((number >= 1 && number <= 9) || number == -1){
					

						word_counter++;

						vec_for_lhs.push_back(number);
						
					}
					else{
						out << "Error" << endl;
						//cout << "Error" << endl;
						return 0;
					}
				}

				
				if(word_counter != num_columns){
					out << "Error" << endl;
					//cout << "Error" << endl;
					return 0;
				}
				word_counter= 0;
				MATRIX_LHS.push_back(vec_for_lhs);
				vec_for_lhs.clear();
			}
			
			line_counter++;
			
		}
		

		if(line_counter != num_rows + 1){ // IT IS CHECKING ROW NUMBER.. NOW WE SHOULD FIND THE COLUMN NUMBER
			out << "Error" << endl;
			//cout << "Error" << endl;
			return 0;
		}
		return 1;

}

// Input check for RHS MATRIX

int Input_Check_FOR_RHS_MATRIX(ifstream &input, ofstream &out, vector<vector<int>> & MATRIX_RHS){ // This function is checking the RIGHT HAND SIDE (RHS) matrix if its implemented correctly.

	vector <int> vec_for_rhs;
	string lines, rows, columns;
	int line_counter =  0, num_rows, num_columns, number, word_counter = 0;

	while(getline(input, lines)){
			stringstream seperateWordsRHS(lines);
			if(line_counter == 0){
				int space = lines.find(' ');

				rows = lines.substr(0, space); /* I turned strings to integers */
				columns = lines.substr(space); 

				num_rows = stoi(rows);
				num_columns = stoi(columns);
				
				if(num_columns != 1){
					out << "Error" << endl;
					//cout << "Error" << endl;
					return 0;
				}

			}
			else if(line_counter > 0){

				
				while (seperateWordsRHS >> number){ /* I found the number of columns and checked them. */
				
					if ((number >= 1 && number <= 9)){
					

						word_counter++;
						vec_for_rhs.push_back(number);
					}
					else{
						out << "Error" << endl;
						//cout << "Error" << endl;
						return 0;
					}
				}
				if(word_counter != num_columns){
					out << "Error" << endl;
					//cout << "Error" << endl;
					return 0;
				}
				word_counter= 0;
				MATRIX_RHS.push_back(vec_for_rhs);
				vec_for_rhs.clear();
			}

			line_counter++;
			}

	if(line_counter != num_rows + 1){ // IT IS CHECKING ROW NUMBER.. NOW WE SHOULD FIND THE COLUMN NUMBER
			out << "Error" << endl;
			//cout << "Error" << endl;
			return 0;
		}
	return 1;

}

// Input check for RES MATRIX

int Input_Check_FOR_RES_MATRIX(ifstream &input, ofstream &out, vector<vector<int>> & MATRIX_RES){ // This function is checking the RESULT (RES) matrix if its implemented correctly.

	vector <int> vec_for_res;
	string lines, rows, columns;
	int line_counter =  0, num_rows, num_columns, number, word_counter = 0;

	while(getline(input, lines)){
		stringstream seperateWordsRES(lines);
		if(line_counter == 0){
			int space = lines.find(' ');

				rows = lines.substr(0, space); /* I turned strings to integers */
				columns = lines.substr(space); 

				num_rows = stoi(rows);
				num_columns = stoi(columns);
				
				if(num_columns != 1){
					out << "Error" << endl;
					//cout << "Error" << endl;
					return 0;
				}

			}
			else if(line_counter > 0){

				
				while (seperateWordsRES >> number){ /* I found the number of columns and checked them. */
				
					if (number > 0){
					

						word_counter++;
						vec_for_res.push_back(number);
					}
					else{
						out << "Error" << endl;
						//cout << "Error" << endl;
						return 0;
					}
				}
				if(word_counter != num_columns){
					out << "Error" << endl;
					//cout << "Error" << endl;
					return 0;
				}
				word_counter= 0;
				MATRIX_RES.push_back(vec_for_res);
				vec_for_res.clear();
			}

			line_counter++;
			}

	if(line_counter != num_rows + 1){ // IT IS CHECKING ROW NUMBER.. NOW WE SHOULD FIND THE COLUMN NUMBER

			out << "Error" << endl;
			//cout << "Error" << endl;
			return 0;
		}
	return 1;

}





int main(){

	string lhs_file, rhs_file, res_file, output;
	ifstream lhs_input, rhs_input, res_input;
	
	ofstream out;
	

	
	
	vector <vector<int>>MATRIX_LHS;
	vector <vector<int>>MATRIX_RHS;
	vector <vector<int>>MATRIX_RES;

	cout << "Enter LHS matrix filename: ";
	cin >> lhs_file;
	lhs_input.open(lhs_file.c_str());
	

	cout << "Enter RHS matrix filename: ";
	cin >> rhs_file;
	rhs_input.open(rhs_file.c_str());


	cout << "Enter RES filename: ";
	cin >> res_file;
	res_input.open(res_file.c_str());


	cout << "Enter output filename: ";
	cin >> output;
	out.open(output.c_str());
	

	if (lhs_input.fail() || rhs_input.fail() || res_input.fail()){
	
		out << "Error" << endl;
		//cout << "Error" << endl;
	}

	
	else{
		

		//Input_Check_FOR_LHS_MATRIX(lhs_input, out, MATRIX_LHS);
		
		int result = Input_Check_FOR_LHS_MATRIX(lhs_input, out, MATRIX_LHS);

		if (result == 0){
		
			return 0;
		}

		
		//Input_Check_FOR_RHS_MATRIX(rhs_input, out, MATRIX_RHS);

		result = Input_Check_FOR_RHS_MATRIX(rhs_input, out, MATRIX_RHS);

		if (result == 0){
		
			return 0;
		}

		
		//Input_Check_FOR_RES_MATRIX(res_input, out, MATRIX_RES);

		result = Input_Check_FOR_RES_MATRIX(res_input, out, MATRIX_RES);

		if (result == 0){
		
			return 0;
		}
		

		

		Print(MATRIX_LHS);
		cout << endl;
		cout << endl;


		Print(MATRIX_RHS);

		cout << endl;
		cout << endl;

		Print(MATRIX_RES);

		cout << endl;
		cout << endl;


		Matrix_Multiplication(MATRIX_LHS, MATRIX_RHS, MATRIX_RES);

		
		lhs_input.close();
		rhs_input.close();
		res_input.close();
		out.close();




		

		

		}

	
	return 0;
}