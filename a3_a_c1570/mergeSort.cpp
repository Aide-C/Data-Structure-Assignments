#include <iostream>
using namespace std;

// Merges two sorted subarrays of A[].
// First sorted subarray is A[l..m].
// Second sorted subarray is A[m+1..r].
// You might want to call this function in function mergeSort().
void merge(int A[], int l, int m, int r)
{
    int nL = m - l + 1;
    int nR = r - m;

    int L[nL];
    int R[nR];

    for (int a = 0; a < nL; ++a){
        L[a] = A[l + a];
    }

    for (int b = 0; b < nR; ++b){
        R[b] = A[m + 1 + b];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < nL && j < nR){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
            k++;
        }else{
            A[k] = R[j];
            j++;
            k++;
        }
    }

    while (i < nL){
        A[k] = L[i];
        ++i;
        ++k;
    }

    while (j < nR){
        A[k] = R[j];
        ++j;
        ++k;
    }
}

// using mergeSort to sort sub-array A[l..r]
// l is for left index and r is right index of the
// sub-array of A[] to be sorted
void mergeSort(int A[], int l, int r)
{
    if (l == r){
        return;
    }else{
        int mid = (l + r) / 2;
        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, r);
        merge(A, l, mid, r);
    }
}


int main()
{
    cout << "Please enter the length (number of elements) of the input array: ";
	int n;
	cin >> n;

	if(n <= 0) {
		cout << "Illegal input array length!" << endl;
		return 0;
	}

	int* A = new int [n];

	cout << "Please enter each element in the array" << endl;
	cout << "(each element must be an integer within the range of int type)." << endl;
	for(int i=0; i<n; i++) {
		cout << "A[" << i << "] = ";
		cin >> A[i];
	}

    cout << "Given array A[] is: ";
	for(int i=0; i<n-1; i++)
		cout << A[i] << ",";
	cout << A[n-1] << endl;


    mergeSort(A, 0, n-1);

    cout << "After mergeSort, sorted array A[] is: ";
	for(int i=0; i<n-1; i++)
		cout << A[i] << ",";
	cout << A[n-1] << endl;


	delete [] A;
    return 0;
}
