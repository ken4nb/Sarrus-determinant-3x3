#include <iostream>
#include <complex>
#include <iomanip>

using namespace std;

complex<double> d;
complex<double> det_array[5];  // Using 1-based indexing
complex<double> determinant_matrix[3][4];

complex<double> calculate_determinant(int n, complex<double> matrix[3][4]) {
    switch (n) {
    case 1:
        return ((matrix[0][0] * matrix[1][1] * matrix[2][2]) 
              + (matrix[0][1] * matrix[1][2] * matrix[2][0])
              + (matrix[0][2] * matrix[1][0] * matrix[2][1]))
              - ((matrix[2][0] * matrix[1][1] * matrix[0][2])
              + (matrix[2][1] * matrix[1][2] * matrix[0][0])
              + (matrix[2][2] * matrix[1][0] * matrix[0][1]));
    case 2:
        return ((matrix[0][3] * matrix[1][1] * matrix[2][2])
              + (matrix[0][1] * matrix[1][2] * matrix[2][3])
              + (matrix[0][2] * matrix[1][3] * matrix[2][1]))
              - ((matrix[2][3] * matrix[1][1] * matrix[0][2])
              + (matrix[2][1] * matrix[1][2] * matrix[0][3])
              + (matrix[2][2] * matrix[1][3] * matrix[0][1]));
    case 3:
        return ((matrix[0][0] * matrix[1][3] * matrix[2][2])
              + (matrix[0][3] * matrix[1][2] * matrix[2][0])
              + (matrix[0][2] * matrix[1][0] * matrix[2][3]))
              - ((matrix[2][0] * matrix[1][3] * matrix[0][2])
              + (matrix[2][3] * matrix[1][2] * matrix[0][0])
              + (matrix[2][2] * matrix[1][0] * matrix[0][3]));
    case 4:
        return ((matrix[0][0] * matrix[1][1] * matrix[2][3])
              + (matrix[0][1] * matrix[1][3] * matrix[2][0])
              + (matrix[0][3] * matrix[1][0] * matrix[2][1]))
              - ((matrix[2][0] * matrix[1][1] * matrix[0][3])
              + (matrix[2][1] * matrix[1][3] * matrix[0][0])
              + (matrix[2][3] * matrix[1][0] * matrix[0][1]));
    default:
        return complex<double>(0, 0);
    }
}

void print_complex(complex<double> num) {
    if (num.real() == 0 && num.imag() == 0) {
        cout << "0";
        return;
    }
    if (num.real() != 0) {
        cout << num.real();
        if (num.imag() > 0) cout << " + ";
        if (num.imag() < 0) cout << " - ";
    }
    if (num.imag() != 0) {
        if (num.real() == 0 && num.imag() < 0) cout << "-";
        if (abs(num.imag()) == 1)
            cout << "i";
        else
            cout << abs(num.imag()) << "i";
    }
}

int main() {
    double real, imag;
    int row = 0;

    cout << "Enter 3x4 matrix elements (real imaginary):\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nRow " << i + 1 << ":\n";
        for (int j = 0; j < 4; j++) {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> real >> imag;
            determinant_matrix[i][j] = complex<double>(real, imag);
        }
    }

    cout << "\nCalculating determinants:\n";
    for (int i = 1; i <= 4; i++) {
        det_array[i] = calculate_determinant(i, determinant_matrix);
        cout << "D" << (i == 1 ? "" : to_string(i-1)) << " = ";
        print_complex(det_array[i]);
        cout << endl;
    }

    complex<double> denom_conj = conj(det_array[1]);
    double denom_norm = norm(det_array[1]);

    cout << "\nSolutions:\n";
    complex<double> x = (det_array[2] * denom_conj) / denom_norm;
    complex<double> y = (det_array[3] * denom_conj) / denom_norm;
    complex<double> z = (det_array[4] * denom_conj) / denom_norm;

    cout << "X = "; print_complex(x); cout << endl;
    cout << "Y = "; print_complex(y); cout << endl;
    cout << "Z = "; print_complex(z); cout << endl;

    return 0;
}
