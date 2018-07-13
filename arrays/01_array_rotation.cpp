#include <iostream>
using namespace std;

void rotate_array_method1(int arr[], int no_of_elements_to_rotate, int arr_size, int temp_arr[])
{
	for(int i = 0; i < arr_size - no_of_elements_to_rotate; i++)
	{
		temp_arr[i] = arr[i+no_of_elements_to_rotate];
	}
	int k = 0;
	for(int i = arr_size - no_of_elements_to_rotate; i < arr_size; i++)
	{
		temp_arr[i] = arr[k];
		k++;
	}
}

void rotate_array_method2(int arr[], int no_of_elements_to_rotate, int arr_size)
{
	// Move one by one
	while (no_of_elements_to_rotate-- > 0)
	{
		int temp = arr[0];
		for(int i = 0; i < arr_size-1; i++)
		{
			arr[i] = arr[i+1];
		}
		arr[arr_size-1] = temp;
	}
}

int find_gcd(int n1, int n2)
{
	while(n1 != n2 || n1 != 0 || n2 != 0)
	{
		if(n1>n2)
		{
			n1 = n1%n2;
			if(n1 == 0)
			{
				return n2;
			}
		}
		else
		{
			n2 = n2%n1;
			if(n2==0)
			{
				return n1;
			}
		}
	}
	return n1;
}

void rotate_array_method3(int arr[], int no_of_elements_to_rotate, int arr_size)
{
	// Juggling Algorithm
	int gcd_of_two_numbers = find_gcd(no_of_elements_to_rotate, arr_size);
	int no_of_loops = no_of_elements_to_rotate/gcd_of_two_numbers;
	while(no_of_loops-- > 0)
	{
		int j = 0;
		int l = gcd_of_two_numbers;
		while(l-- > 0)
		{
			int k = j;
			int temp = arr[k];
			while(k+gcd_of_two_numbers< arr_size)
			{
				arr[k] = arr[k+gcd_of_two_numbers];
				k += gcd_of_two_numbers;
			}
			arr[k] = temp;
			j++;
		}
	}
}

void reverse_arr( int arr[], int from_position, int to_position)
{
	if ((to_position - from_position+1) % 2 == 0)
	{
		to_position -= 1;
		while(to_position > from_position)
		{
			int temp = arr[from_position];
			arr[from_position] = arr[to_position];
			arr[to_position] = temp;
			from_position += 1;
			to_position -= 1;
		}
	}
	else
	{
		while(from_position < to_position)
		{
			int temp = arr[from_position];
			arr[from_position] = arr[to_position];
			arr[to_position] = temp;
			from_position += 1;
			to_position -= 1;
		}
	}
}

void rotate_array_method4(int arr[], int no_of_elements_to_rotate, int arr_size)
{
	// Reversal Algorithm
	reverse_arr(arr, 0, no_of_elements_to_rotate);
	cout << "\n METHOD4 \n";
	for(int i =0; i < 12; i++)
	{
		cout << arr[i] << ",";
	}	
	reverse_arr(arr, no_of_elements_to_rotate+1, arr_size);
	cout << "\n METHOD4 \n";
	for(int i =0; i < 12; i++)
	{
		cout << arr[i] << ",";
	}	
	reverse_arr(arr, 0, arr_size);
	cout << "\n METHOD4 \n";
	for(int i =0; i < 12; i++)
	{
		cout << arr[i] << ",";
	}	
}

void block_swap(int arr[], int from1, int to1, int from2, int to2)
{
	while(from1 != to1)
	{
		int temp = arr[from1];
		arr[from1] = arr[from2];
		arr[from2] = temp;
		from1++;
		from2++;
	}
}

void rotate_array_method5(int arr[], int no_of_elements_to_rotate, int arr_size)
{
	// Block Swap Algorithm

}


int main()
{
	int arr[10], arr1[10];
	cout << "INPUT\n";
	for(int i = 0; i < 10; i++ )
	{
		arr[i] = i + 1;
		arr1[i] = i + 1;
		cout << arr[i];
	}
	int output_arr[10];
	cout << "\nMETHOD1 OUTPUT \n";
	rotate_array_method1(arr, 2, 10, output_arr);
	for(int i = 0; i < 10; i++ )
	{
		cout << output_arr[i];
	}
	cout << "\n METHOD2 OUTPUT\n";
	rotate_array_method2(arr, 2, 10);
	for(int i =0; i < 10; i++)
	{
		cout << arr[i];
	}
	cout << "\n Method3 \n";
	int arr2[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
	rotate_array_method3(arr2, 4, 12);
	for(int i =0; i < 12; i++)
	{
		cout << arr2[i] << ",";
	}

	int arr3[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
	rotate_array_method4(arr3, 4, 12);
	cout << "\n METHOD4 \n";
	for(int i =0; i < 12; i++)
	{
		cout << arr3[i] << ",";
	}	
	return 0;
}