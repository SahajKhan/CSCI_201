#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class TBD> 
class TArray {
private:
	TBD *myArray;
	int size;
public:
	TArray(int size = 0) {
		if (size < 0) {
			throw invalid_argument("invalid size");
		}
		myArray = new TBD[size];
		this->size = size;
	}
	~TArray() {
		delete[] myArray;
	}
	void set(TBD value, int index) {
		if (index < 0 || index >= size) {
			throw invalid_argument("out of range");
		}
		myArray[index] = value;
	}
	TBD get(int index) {
		if (index < 0 || index >= size) {
			throw invalid_argument("out of range");
		}
		return myArray[index];
	}
	int getSize() {
		return size;
	}
	void push_back(TBD value) {
		size++;
		~myArray();
		myArray = new TBD[size];
		*myArray[size-1] = value;
	}

};