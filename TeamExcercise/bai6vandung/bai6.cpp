#include <bits/stdc++.h>
using namespace std; 
void readArray(int* &a, int &n);
void printArray(int* a, int n);
void swap(int &a, int &b);
void SortEvenOddKeepZero(int* &array, int n);
int main()
{
    int *Array;
    int n;
    readArray(Array, n);
    cout << "Mang ban dau la: ";
    printArray(Array, n);
    SortEvenOddKeepZero(Array, n);
    cout << "\nMang sau khi sap xep la: ";
    printArray(Array, n);
    delete[] Array;
    return 0;
}
void readArray(int* &a, int &n)
{
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void printArray(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void SortEvenOddKeepZero(int* &array, int n){
    vector<int> evenindex, oddindex;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == 0)
        {
            continue;
        }
        if (array[i] % 2 == 0)
        {
            evenindex.push_back(i);
        }
        else
        {
            oddindex.push_back(i);
        }
    }
    for(int i=0;i<evenindex.size()-1;i++){
        for(int j=0;i<evenindex.size()-i-1;i++)
        {
            if(array[evenindex[j]]>array[evenindex[j+1]])
            {
                swap(array[evenindex[j]],array[evenindex[j+1]]);
            }
        }
    }
    for(int i=0;i<oddindex.size()-1;i++){
        for(int j=0;i<oddindex.size()-i-1;i++)
        {
            if(array[oddindex[j]]>array[oddindex[j+1]])
            {
                swap(array[oddindex[j]],array[oddindex[j+1]]);
            }
        }
    }
}