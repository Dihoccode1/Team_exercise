#include <bits/stdc++.h>
using namespace std;

void input_data(int* &array, int &size);
void output_data(int* array, int size);
void Merge(int* array, int* B, int left, int mid, int right);
void MergeSort(int* array, int* B, int left, int right);
void find_permutation(int* B, int size, int* A);

int main()
{
    int *A, N;
    input_data(A, N);

    int *B = new int[N]();
    MergeSort(A, B, 0, N - 1);

    output_data(B, N);

    int* A_reconstructed = new int[N];
    find_permutation(B, N, A_reconstructed);
    output_data(A_reconstructed, N);

    delete[] A;
    delete[] B;
    delete[] A_reconstructed;
    return 0;
}

void input_data(int* &array, int &size)
{
    cin >> size;
    array = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
}

void output_data(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void Merge(int* array, int* B, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++) L[i] = array[left + i];
    for (int i = 0; i < n2; i++) R[i] = array[mid + 1 + i];

    int i = 0, j = 0, k = left, count = 0;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            B[L[i] - 1] += count;
            i++;
        }
        else
        {
            array[k] = R[j];
            count++;
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        B[L[i] - 1] += count;
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int* array, int* B, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSort(array, B, left, mid);
        MergeSort(array, B, mid + 1, right);
        Merge(array, B, left, mid, right);
    }
}

void find_permutation(int* B, int size, int* A)
{
    vector<int> remaining;
    for (int i = 1; i <= size; i++)
        remaining.push_back(i);
    
    for (int i = 0; i < size; i++)
    {
        A[i] = remaining[B[i]];
        remaining.erase(remaining.begin() + B[i]);
    }
}
