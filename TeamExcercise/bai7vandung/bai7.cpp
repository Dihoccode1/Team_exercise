#include <bits/stdc++.h>
using namespace std;
void ReadArray(int* &array ,int &size);
void SwapEvennumandOddnum(int* &nums ,int size);
void PrintArray(int* array ,int size);
void test1() {
    int* array = new int[5]{1, 2, 3, 4, 5};
    int size = 5;
    SwapEvennumandOddnum(array, size);
    PrintArray(array, size);
    delete[] array;
}

void test2() {
    int* array = new int[10]{10, 21, 32, 43, 54, 65, 76, 87, 98, 109};
    int size = 10;
    SwapEvennumandOddnum(array, size);
    PrintArray(array, size);
    delete[] array;
}

void test3() {
    int* array = new int[8]{15, 14, 13, 12, 11, 10, 9, 8};
    int size = 8;
    SwapEvennumandOddnum(array, size);
    PrintArray(array, size);
    delete[] array;
}

void test4() {
    int* array = new int[7]{7, 14, 21, 28, 35, 42, 49};
    int size = 7;
    SwapEvennumandOddnum(array, size);
    PrintArray(array, size);
    delete[] array;
}

int main() {
    test1();
    cout << endl;
    test2();
    cout << endl;
    test3();
    cout << endl;
    test4();
    cout << endl;
    return 0;
}
void ReadArray(int* &array ,int &size)
{
    cout << "Nhap so phan tu cua mang: ";
    cin >> size;
    array = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> array[i];
    }
}
void PrintArray(int* array ,int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}
void SwapEvennumandOddnum(int* &nums ,int size)
{
      int left = 0, right = size - 1;
    while(left < right) {
        if(nums[left] % 2 > nums[right] % 2)
            swap(nums[left], nums[right]);
     
        if(nums[left] % 2 == 0)
            left++;

        if(nums[right] % 2 == 1)
            right--;
    }
}