#include <iostream>
#include <ctime>
using namespace std;
/*
 */
void mergesort(int n, int * S);
void merge(int h, int m, int * U, int * V, int * S);
void printArr(size_t n, int * input);
int * createArray(int size);

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    int * S = createArray(8);
    printArr(8, S);
    mergesort(8, S);
    printArr(8, S);
    return 0;
}
int * createArray(int size)
{
    int* arr = new int[size];
    for(int i = 0; i<size; i++)
    {
            int random_int= (rand() % 100) +1;
            arr[i]=random_int;
    }
    return arr;
}
void printArr(size_t n, int * input){
    cout<<endl;
    for(unsigned int i = 0; i<n; ++i){
        cout<<input[i]<<" ";
    }
    cout<<endl;
}

void mergesort(int n, int * S){
    if(n>1){
        const int h = n/2, m = n - h;
        int* U = new int[h];
        int* V = new int[m];
        for(int i = 0; i < h; ++i)
            U[i]=S[i];
        for(int i = h; i < n; ++i)
            V[i]=S[i];
        mergesort(h, U);
        mergesort(m, V);
        merge(h, m, U, V, S);
        //delete[]U;
        //delete[]V;
    }
}

void merge(int h, int m, int * U, int * V, int * S){
    int i=1, j=1, k=1;
    while(i<=h && j<= m){
        if(U[i] < V[j]){
            S[k] = U[i];
            i++;
        }else{
            S[k] = V[j];
            j++;
        }
        k++;
    }
    if(i>h){
        for(int ii=j; ii<=m; ++i, ++k){
            S[k]=V[ii];
        }
    }else{
        for(int ii=i; ii<=h; ++i, ++k){
            S[k]=U[ii];
        }
    }
}
