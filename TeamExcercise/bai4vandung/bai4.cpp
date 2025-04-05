#include <bits/stdc++.h>
using namespace std;

void printMatrix(int** Matrix, int row, int col);
bool Is_prime(int n);
int Max_prime_element(int** Matrix, int row, int col);
vector<int> Row_only_have_prime_element(int** Matrix, int row, int col);
void test1();
void test2();

int main() {
    test1();
    test2();
    return 0;
}

void printMatrix(int** Matrix, int row, int col) {
    cout << "Ma trận:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool Is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int Max_prime_element(int** Matrix, int row, int col) {
    int Max_element = -1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (Is_prime(Matrix[i][j]) && Matrix[i][j] > Max_element) {
                Max_element = Matrix[i][j];
            }
        }
    }
    return Max_element;
}

vector<int> Row_only_have_prime_element(int** Matrix, int row, int col) {
    vector<int> rows;
    for (int i = 0; i < row; i++) {
        bool allPrime = true;
        for (int j = 0; j < col; j++) {
            if (!Is_prime(Matrix[i][j])) {
                allPrime = false;
                break;
            }
        }
        if (allPrime) {
            rows.push_back(i);
        }
    }
    return rows;
}

void test1() {
    int row = 3, col = 3;
    int** Matrix = new int*[row];
    for (int i = 0; i < row; i++) {
        Matrix[i] = new int[col];
    }

    int testData[3][3] = {
        {2, 3, 5},
        {4, 6, 8},
        {11, 13, 17}
    };

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            Matrix[i][j] = testData[i][j];

    cout << "===== TEST 1 ====="<<endl;
    printMatrix(Matrix, row, col);
    cout << "Số nguyên tố lớn nhất: " << Max_prime_element(Matrix, row, col) << endl;

    vector<int> primeRows = Row_only_have_prime_element(Matrix, row, col);
    cout << "Các hàng chỉ chứa số nguyên tố: ";
    if (primeRows.empty()) cout << "Không có hàng nào.";
    else {
        for (int r : primeRows) cout << r << " ";
    }
    cout << endl;

    for (int i = 0; i < row; i++) delete[] Matrix[i];
    delete[] Matrix;
}

void test2() {
    int row = 4, col = 4;
    int** Matrix = new int*[row];
    for (int i = 0; i < row; i++) {
        Matrix[i] = new int[col];
    }

    int testData[4][4] = {
        {7, 11, 13, 17},
        {10, 12, 14, 16},
        {19, 23, 29, 31},
        {6, 9, 15, 21}
    };

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            Matrix[i][j] = testData[i][j];

    cout << "===== TEST 2 ====="<<endl;
    printMatrix(Matrix, row, col);
    cout << "Số nguyên tố lớn nhất: " << Max_prime_element(Matrix, row, col) << endl;

    vector<int> primeRows = Row_only_have_prime_element(Matrix, row, col);
    cout << "Các hàng chỉ chứa số nguyên tố: ";
    if (primeRows.empty()) cout << "Không có hàng nào.";
    else {
        for (int r : primeRows) cout << r << " ";
    }
    cout << endl;

    for (int i = 0; i < row; i++) delete[] Matrix[i];
    delete[] Matrix;
}
