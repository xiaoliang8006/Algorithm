#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <utility>
#include <cstdlib>
#include<cstdio>
using namespace std;
 
 
class DynamicArray {
 
public:
	DynamicArray();
	DynamicArray(int initSize);
	DynamicArray(const DynamicArray &original);
	~DynamicArray();
 
	void insert(int position, int value); 
	int get(int position);  
 
	int getSize();
	void resize(int newSize);
 
	int &operator[](int index);
	bool operator==(DynamicArray);
	bool operator!=(DynamicArray);
 
	int size;  
	int *array;
 
};
 
DynamicArray::DynamicArray() {

}
 
DynamicArray::DynamicArray(int initSize) {
	size = initSize;
	array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = 0; // Fill with zeroes
	}
}
 
DynamicArray::DynamicArray(const DynamicArray &original) {
	size  = original.size;
	array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = original.array[i];
	}
}
 
DynamicArray::~DynamicArray() {
	delete[] array;
}
 
 
void DynamicArray::insert(int position, int value) {
	array[position] = value;
}
 
int DynamicArray::get(int position) {
	return array[position];
}
 
int DynamicArray::getSize() {
	return size;
}
 
void DynamicArray::resize(int newSize) {
	int *temp;
	temp = new int[newSize];
	for (int i = 0; i < (newSize); i++) {
		temp[i] = array[i];
	}
	delete[] array;
	array = temp;
	size = newSize;
}
 
bool DynamicArray::operator==(DynamicArray a)  {
	if (a.size != size) return false;
 
	for (int i = 0; i < (a.size); i++) {
		if (a[i] != array[i]) return false;
	}
}
 
bool DynamicArray::operator!=(DynamicArray a)  {
	if (a.size != size) return true;
 
	for (int i = 0; i < (a.size); i++) {
		if (a[i] != array[i]) return true;
	}
}
 
int &DynamicArray::operator[](int index) {
	if ((index - 1) > size) {
		resize(index + 1);
	}
	return array[index]; // returned as a reference
}
 
 
 
int main(int argc, char **argv) {
 
	DynamicArray array = DynamicArray(2);
	array.insert(1, 7);
	array.insert(2, 5);
	array.insert(3, 8);
	array.insert(4, 8);

 

	for(int i=1;i<=array.getSize();i++)
		cout<<array[i]<<" ";
	return 0;
}
