#include <iostream>

using namespace std;

// Given a sorted array. we need to search an element. 

int binary_search(int arr[], int element_to_find)
{	
	int first_position = 0;
	int last_position = sizeof(arr)/sizeof(arr[0]) -1;
	cout << "Size of array is " << last_position << "\n";
	bool element_not_found = true;
	while(element_not_found)
	{
		
		int middle_position = (first_position + last_position)/2;
		int middle_position_value = arr[middle_position];
		cout << "First Postion " << first_position << " Current Position " << middle_position << " 	Last Postition " << last_position << "\n";
		if(middle_position_value < element_to_find)
		{
			first_position = middle_position;
		}
		else if (middle_position_value > element_to_find)
		{
			last_position = middle_position;
		}
		else
		{
			element_not_found = false;
			return middle_position;
		}
		if(last_position == first_position + 1){
			return -1;
		}
	}
	return -1;
}

int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int element_to_find = 9;
	int return_value = binary_search(arr, element_to_find);
	cout << return_value;
}