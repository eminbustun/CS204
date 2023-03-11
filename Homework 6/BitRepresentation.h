#ifndef BIT_REPRESANTATION_H
#define BIT_REPRESANTATION_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class BitRepresentation{

public:
	BitRepresentation(T number);
	BitRepresentation(vector<bool>);
	string getBinary();
	string getHexadecimal();
	void setBit(unsigned int location);
	void unsetBit(unsigned int location);
	bool isBitSet(unsigned int location);
	T getNumber();


private:
	T data;


};



#include "BitRepresentation.cpp"


#endif BIT_REPRESANTATION_H