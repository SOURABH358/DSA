#include <iostream>
using namespace std;
void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int temparr[r+1];
         int l1=l;
         int m1=m+1;
         int i = l;
         while(l1<=m && m1<=r)
         {
             if (arr[l1]<=arr[m1])
             {
                 temparr[i]= arr[l1];
                 l1++;
             }
             else 
             {
                 temparr[i]=arr[m1];
                 m1++;
             }
             i++;
             
         }
         while(l1<=m)
         {
             temparr[i]=arr[l1];
             i++;
             l1++;
         }
         while(m1<=r)
         {
             temparr[i]=arr[m1];
             i++;
             m1++;
         }
         for (int j = l ; j<=r; j++)
         {
             arr[j]=temparr[j];
         }
    }
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if (r<=l) 
        return ;
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1,r);
        merge(arr, l, m, r);
    }
    void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}
 
// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}