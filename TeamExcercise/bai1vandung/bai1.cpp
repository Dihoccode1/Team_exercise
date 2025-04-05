#include <bits/stdc++.h>
using namespace std;

vector<int> indexofMaxelement(int *array, int size);
void readinput(int* &array, int &size);
int sumofDigits(int n);
void Bubblesort(int* &array, int size);
bool isPrime(int n);
void removePrimeelement(int* &array, int &size);
void printArray(int* array, int size);
void test1();
void test2();

int main() {
    test1();
    test2();
    return 0;
}

void readinput(int* &array, int &size) {
    array = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
}

vector<int> indexofMaxelement(int *array, int size) {
    vector<int> index;
    int max_element = array[0];

    for (int i = 1; i < size; i++) {
        if (max_element < array[i]) {
            max_element = array[i];
            index.clear();
            index.push_back(i);
        } else if (max_element == array[i]) {
            index.push_back(i);
        }
    }
    return index;
}

int sumofDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void Bubblesort(int* &array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (sumofDigits(array[j]) > sumofDigits(array[j + 1])) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i<=sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void removePrimeelement(int* &array, int &size) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (!isPrime(array[i])) {
            array[j] = array[i];
            j++;
        }
    }
    size = j;
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void test1() {
    cout << "========== TEST 1 =========="<<endl;
    int size = 10;
    int* arr = new int[size] {2, 18, 7, 33, 11, 100, 25, 15, 17, 40};

    cout << "Mảng ban đầu: ";
    printArray(arr, size);

    vector<int> maxIndexes = indexofMaxelement(arr, size);
    cout << "Vị trí phần tử lớn nhất: ";
    for (int idx : maxIndexes) cout << idx << " ";
    cout << endl;

    removePrimeelement(arr, size);
    cout << "Mảng sau khi xóa số nguyên tố: ";
    printArray(arr, size);

    Bubblesort(arr, size);
    cout << "Mảng sau khi sắp xếp theo tổng chữ số: ";
    printArray(arr, size);

    delete[] arr;
}

void test2() {
    cout << "========== TEST 2 =========="<<endl;
    int size = 8;
    int* arr = new int[size] {13, 27, 89, 45, 90, 5, 111, 24};

    cout << "Mảng ban đầu: ";
    printArray(arr, size);

    vector<int> maxIndexes = indexofMaxelement(arr, size);
    cout << "Vị trí phần tử lớn nhất: ";
    for(int i=0;i<maxIndexes.size();i++)
        cout<<maxIndexes[i]<<" ";
    cout << endl;

    removePrimeelement(arr, size);
    cout << "Mảng sau khi xóa số nguyên tố: ";
    printArray(arr, size);

    Bubblesort(arr, size);
    cout << "Mảng sau khi sắp xếp theo tổng chữ số: ";
    printArray(arr, size);

    delete[] arr;
}
