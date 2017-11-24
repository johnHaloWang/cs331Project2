#include <iostream>
#include <ctime>
using namespace std;

/**
 *
 * Title
 * Purpose:
 *
 * @author Chi-Wei (John) Wang
 * @version 1.0 11/24/2017
 */

void mergesort(int n, int * S);
void merge(int h, int m, int * U, int * V, int * S);
void printArr(size_t n, int * input);
int * createArray(int n);
void partition(int index, int high, int& pivotpoint, int * S);
void swap(int index1, int index2, int * S);
void quicksort_recursive(int low, int high, int * S);

int main(int argc, char *argv[])
{
    srand((unsigned)time(0));
    cout << "Hello World!" << endl;
    int * S = createArray(8);

    printArr(8, S);
    //mergesort(8, S);
    quicksort_recursive(0, 7, S);
    cout<<"final"<<endl;
    printArr(8, S);
    return 0;
}
/* utility function list */

/**
 * take a input of size n to generate integer array
 *
 * @param int size: represent a size of array wish to create
 *
 * @return int array in size n, which populuated with random generated integers
 */
int * createArray(int n)
{
    int* arr = new int[n];
    for(int i = 0; i<n; i++)
    {
            int random_int= (rand() % 100) +1;
            arr[i]=random_int;
    }
    return arr;
}
/**
 * take the size_t n and the input array to print out the array content
 *
 * @param 1 size_t n --  the size of input integer array
 *
 * @param 2 int * input --  integer * pointer, which point to an integer array
 *
 * @return -- none
 *
 * @output -- printing the input array on the shell
 */
void printArr(size_t n, int * input){
    //cout<<endl;
    for(unsigned int i = 0; i<n; ++i){
        cout<<input[i]<<" ";
    }
    cout<<endl;
}
/**
 * take the two index, index1 and index2 to swap the array content
 *
 * @param 1 int index1 --  the index of first item in the array
 *
 * @param 2 int index2 --  the index of second item in the array
 *
 * @param 3 int * S -- the integer pointer pointing to the S integer array for swapping
 *
 * @return -- none
 *
 */
void swap(int index1, int index2, int * S){
    int temp = S[index1];
    S[index1]=S[index2];
    S[index2]=temp;
}

/**
 * USING FOR QUICKSORT RECURSIVELY
 * Partition the array S for quicksort
 * take the three indices, low, high, pivotpoint (passing by reference), and integer pointer (pointing to an integer array)
 * to partition and sort the integer array in non-decreasing order.
 * The function will update the pivotpoint index to the item of pivotitem.
 *
 * @param 1 int low --  the index of starting partition point in the array
 *
 * @param 2 int high --  the index of ending partition point in the array
 *
 * @param 3 int pivopoint --  the index of pivotpoint for update in the array
 *
 * @param 3 int * S -- the integer pointer pointing to the S integer sub-array for partition
 *
 * @return -- none
 *
 * @outputs -- pivotpoint, the pivot point for the subarray indexed from low to high
 */

void partition(int low, int high, int& pivotpoint, int * S){
    int i, j;
    //choose the first item for piovoitem
    int pivotitem = S[low];
    j = low;
    for(i = low+1; i <= high; i++){
        if(S[i] < pivotitem){
            j++;
            swap(i, j, S);
        }
    }
    pivotpoint = j;
    //put pivotitem at pivotpoint
    swap(low, pivotpoint, S);
}


/**
 * USING FOR MERGESORT
 * take the size of first integer array (h), the size of second integer array (m),
 * first integer pointer (U) pointing to first integer array,
 * second integer pointer (V) pointing to second integer array,
 * integer pointer (S) pointing to the merge result based the sorting U, V in non-decreasing order
 *
 *
 * @param 1 int h --  the size of the U array
 *
 * @param 2 int m -- the size of the V array
 *
 * @param 3 int * U -- integer pointer pointing to first integer array
 *
 * @param 3 int * V -- integer pointer pointing to second integer array
 *
 * @param 3 int * S -- integer pointer pointing to an integer array for storing merge result
 *
 * @return -- none
 */
void merge(int h, int m, int * U, int * V, int * S){
    int i=0, j=0, k=0;
    while(i<h && j<m){
        if(U[i] < V[j]){
            S[k] = U[i];
            i++;
        }else{
            S[k] = V[j];
            j++;
        }
        k++;
    }
    if(i>h-1){
        //copdy V[j] to V[m-1] to S[K] to S[h+m]
        for(int jj=j; jj<m; ++k, ++jj){
            S[k]=V[jj];
        }
    }else{
        //copdy U[i] to V[h-1] to S[K] to S[h+m]
        for(int ii=i; ii<h; ++k, ++ii){
            S[k]=U[ii];
        }
    }
}

/* Algorithm 1 -- mergesort */
/**
 * take the size of array (n), and integer pointer S pointing to an integer array
 * to conduct mergesort
 *
 * @param 1 int n --  the size of the array
 *
 * @param 2 int * S -- the integer pointer pointing to the integer array
 *
 * @return -- none
 */

void mergesort(int n, int * S){
    if(n>1){
        const int h = n/2, m = n - h;
        int* U = new int[h];
        int* V = new int[m];
        //copy S array's content from i to h-1 to U array
        for(int i = 0; i < h; ++i){
            U[i]=S[i];
        }
        //copy S array's content from h to n-1 to V array
        for(int i = h, j = 0; i <n; ++i, ++j){
            V[j]=S[i];
        }
        mergesort(h, U);
        mergesort(m, V);
        //merge arrays U and V into S
        merge(h, m, U, V, S);
        //clear the memory of U and V
        delete[]U;
        delete[]V;
    }
}
//Algorithm 2 -- quicksort iteratively
/**
 * Select-kth 2 will implement the Algorithm 2
 * using the partition procedure of Quicksort iteratively
*/



//Algorithm 3 -- quicksort recursively
/**
 * Select-kth 3 will implement the Algorithm 3 Quicksort recursively
 * */

void quicksort_recursive(int low, int high, int * S){
    int pivotpoint;
    if(high > low){
        partition(low, high, pivotpoint, S);
        quicksort_recursive(low, pivotpoint - 1, S);
        quicksort_recursive(pivotpoint + 1, high, S);
    }

}






















