#include <bits/stdc++.h>
using namespace std;

struct Term {
    double coefficient;
    int exponent;
};

struct Polynomial {
    int degree;
    Term *terms;

    Polynomial(int degree) {
        this->degree = degree;
        terms = new Term[degree];
    }

    ~Polynomial() {
        delete[] terms;
    }
};

void readPolynomial(Polynomial &poly) {
    cout << "Nhập bậc của đa thức: ";
    cin >> poly.degree;
    delete[] poly.terms;
    poly.terms = new Term[poly.degree];

    for (int i = 0; i < poly.degree; i++) {
        cout << "Nhập hệ số: ";
        cin >> poly.terms[i].coefficient;
        cout << "Nhập bậc của biến số: ";
        cin >> poly.terms[i].exponent;
    }
}

void sortPolynomialTermsByDegree(Polynomial &poly) {
    for (int i = 0; i < poly.degree - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < poly.degree; j++) {
            if (poly.terms[j].exponent < poly.terms[minIndex].exponent) {
                minIndex = j;
            }
        }
        swap(poly.terms[i], poly.terms[minIndex]);
    }
}

void printPolynomial(const Polynomial &poly) {
    for (int i = 0; i < poly.degree; i++) {
        if (i > 0 && poly.terms[i].coefficient > 0) {
            cout << " + ";
        } else if (poly.terms[i].coefficient < 0) {
            cout << " - ";
        }

        cout << abs(poly.terms[i].coefficient);

        if (poly.terms[i].exponent > 0) {
            cout << "x";
            if (poly.terms[i].exponent > 1) {
                cout << "^" << poly.terms[i].exponent;
            }
        }
    }
    cout << endl;
}

void test1() {
    cout << "Chạy Test 1: Nhập và xuất đa thức" << endl;
    Polynomial poly(3);
    poly.terms[0] = {3, 4};
    poly.terms[1] = {-5, 3};
    poly.terms[2] = {2, 2};

    cout << "Trước khi sắp xếp: ";
    printPolynomial(poly);

    sortPolynomialTermsByDegree(poly);

    cout << "Sau khi sắp xếp: ";
    printPolynomial(poly);
}

void test2() {
    cout << "Chạy Test 2: Kiểm tra sắp xếp số hạng theo bậc tăng dần" << endl;
    Polynomial poly(4);
    poly.terms[0] = {3, 4};
    poly.terms[1] = {-5, 3};
    poly.terms[2] = {2, 2};
    poly.terms[3] = {7, 0};

    cout << "Trước khi sắp xếp: ";
    printPolynomial(poly);

    sortPolynomialTermsByDegree(poly);

    cout << "Sau khi sắp xếp: ";
    printPolynomial(poly);
}

int main() {
    test1();
    test2();
    return 0;
}
