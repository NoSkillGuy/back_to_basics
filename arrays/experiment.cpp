#include <iostream>
using namespace std;

int temp(int arr[]){
	return -1;
}

int main(){
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int sizeofarray =  sizeof(arr)/sizeof(arr[0]);
	cout << sizeofarray;
}