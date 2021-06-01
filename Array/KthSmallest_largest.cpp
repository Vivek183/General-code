#include <bits/stdc++.h>
using namespace std; 
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
	int pivot = arr[high] ; 
	int i = low-1 ; 
	 //  less than high will reach till second last element bcoz last element is pivot itself 
	for(int j = low ; j < high ; j++)
	{
		if(arr[j] < pivot)
		{
			i++ ; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


int quickSort(int arr[], int low , int high , int k )
{
 	if (k > 0 && k <= high - low + 1) {
 		int pos = partition(arr, low, high);

 		if(pos-low == k-1)
 			return arr[pos];

 		if(pos - low > k - 1) // If position is more, recur for left subarray
            return quickSort(arr, low, pos - 1, k);
 
        // Else recur for right subarray
        return quickSort(arr, pos + 1, high, k - pos + low - 1);

 	}

// if k is outside that condition 
 	return INT_MAX;

}


void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main()
{
	int arr[] = {10, 7, 8, 9, 1, 5};
	int k = 3 ; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = quickSort(arr, 0, n - 1 , k );
    cout << "Sorted array: \n";
    cout << ans << endl; 
    printArray(arr, n);
    
	return 0;
}