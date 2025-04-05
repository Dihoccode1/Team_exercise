#include <bits/stdc++.h>
using namespace std;
void ScanArray2D(int **array2d, int &row, int &collum);
vector<int>sumofRows(int **array2d, int row, int collum);
vector<int>RowshaveMaxSum(int **array2d, int row, int collum);
int partition(int *a, int low, int high);
void quickSort(int *a, int low, int high);
int main ()
{
    return 0;
}
void ScanArray2D(int **array2d, int &row, int &collum)
{
    cin >> row >> collum;
    array2d = new int *[row];
    for (int i = 0; i < row; i++)
        array2d[i] = new int[collum];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < collum; j++)
            cin >> array2d[i][j];
}
vector<int>sumofRows(int **array2d, int row, int collum)
{
    vector<int>sum;
    for (int i = 0; i < row; i++)
    {
        int sumRow = 0;
        for (int j = 0; j < collum; j++)
            sumRow += array2d[i][j];
        sum.push_back(sumRow);
    }
    return sum;
}
vector<int>RowshaveMaxSum(int **array2d, int row, int collum)
{
    vector<int>sum = sumofRows(array2d, row, collum);
    vector<int>result;
    int maxSum = sum[0];
    for (int i = 1; i < row; i++)
        if (sum[i] > maxSum)
            maxSum = sum[i];
    for (int i = 0; i < row; i++)
        if (sum[i] == maxSum)
            result.push_back(i);
    return result;
}