///////////////////////////PROBLEM STATEMENT/////////////////////////////
// Reverse an Array in groups of given size 
// Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8, 9], K = 3 
// Output: 3, 2, 1, 6, 5, 4, 9, 8, 7

// Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8], K = 5 
// Output: 5, 4, 3, 2, 1, 8, 7, 6

// Input: arr[] = [1, 2, 3, 4, 5, 6], K = 1 
// Output: 1, 2, 3, 4, 5, 6

// Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8], K = 10 
// Output: 8, 7, 6, 5, 4, 3, 2, 1

/////////////////////////////SOLUTION START/////////////////////////////
// ALGO - Selection Sort

#include <iostream>
using namespace std;


void reverse(int arr[], int n, int k)
{
	for (int i = 0; i < n; i += k)
	{
		int left = i;

		// to handle case when k is not multiple of n
		int right = min(i + k - 1, n - 1);

		// reverse the sub-array [left, right]
		while (left < right)
			swap(arr[left++], arr[right--]);

	}
}

// Driver code
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int k = 3;

	int n = sizeof(arr) / sizeof(arr[0]);

	reverse(arr, n, k);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}
