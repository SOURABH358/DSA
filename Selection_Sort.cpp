#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
  //code here
  
  for(int i=0; i<n-1;i++)
  {
      int min_index=i;
      for(int j=i+1;j<n;j++)
  {
      if(arr[j]<arr[min_index])
      min_index=j;
      
  }
      int temp=arr[min_index];
  arr[min_index]=arr[i];
  arr[i]=temp;
  }
 
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// } Driver Code Ends
class Solution
{
    public:
    int select(int arr[], int i)
    {
        // code here such that selectionSort() sorts arr[]
    }
     
    void selectionSort(int arr[], int n)
    {
       //code here
    }
};


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
