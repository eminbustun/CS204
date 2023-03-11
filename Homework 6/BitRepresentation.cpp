#include "BitRepresentation.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;



template <typename T>
T BitRepresentation<T>::getNumber(){

	return data;

}

template <typename T>
BitRepresentation<T>::BitRepresentation(T number){

	data = number;

	

}

template <typename T>
BitRepresentation<T>::BitRepresentation(vector<bool> nums){

	T result;

	if (nums.size() > (sizeof(T) * 8)){

		for (int i = 0; i < (nums.size() - sizeof(T) * 8); i++){

			nums.erase(nums.begin());
		}

		reverse(nums.begin(), nums.end());
		
		for (int k = 0; i < nums.size(); i++){

			result += (2**i * nums[i]);


		}


	}

	else if (nums.size() < (sizeof(T) * 8)){

		for (int i = 0; i < (sizeof(T) * 8 - nums.size()); i++){

			nums.insert(0,false);
		}

		reverse(nums.begin(), nums.end());
		
		for (int k = 0; i < nums.size(); i++){

			result += (2**i * nums[i]);


		}


	}

	else {

		reverse(nums.begin(), nums.end());
		
		for (int k = 0; i < nums.size(); i++){

			if (nums[nums.size() - 1] == 1){


				result += -(2**i * nums[i]);

			}
			else{
				result += (2**i * nums[i]);

			}
			

		}


	}

	data = result;

}

template <typename T>
string BitRepresentation<T>::getBinary(){

	string result = "";

	T bir = 1;

	for (int i = sizeof(T) * 8 - 1; i >= 0; i--){

		if (data & (bir << 1)){

			result.append("1")

		}
		else{

			result.append("0");
		}

	}

	return result;
	

}


template <typename T>
string BitRepresentation<T>::getHexadecimal(){

	string result = "";




	return result;
}


template <typename T>
void BitRepresentation<T>::setBit(unsigned int location){


	if (sizeof(T)*8 < location){
		return;
	}

	data = data | (1 << location);

}


template <typename T>
void BitRepresentation<T>::unsetBit(unsigned int location){

	if (sizeof(T)*8 < location){
		return;
	}

	T num = ~1 + 1;

	num = num ^ (1<< location);

	data = data & num;

}


template <typename T>
bool BitRepresentation<T>::isBitSet(unsigned int location){

	if (sizeof(T)*8 < location){
		return false;
	}

	else if (data & (1 << location)){
		return true;

	}

	else {

		return false;
	}

}