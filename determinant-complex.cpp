#include <iostream>
#include <complex>
#include <iomanip>
#include <cstdlib>

using namespace std;

complex<double> d;
complex<double> det_array[4];
complex<double> detr[3][4];
bool hasZeroReal = false, hasZeroImag = false;

complex<double> determinant(int n, complex<double> det[3][4]);

int main() {
    complex<double> equation1[4], equation2[4], equation3[4];
    int k = 0;
    double real, imag;

    cout << "Enter equations for determinant:\n";
    cout << "First equation:\n";
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". term (real, imaginary): ";
        cin >> real >> imag;
        equation1[i] = complex<double>(real, imag);
        detr[k][i] = equation1[i];
    }
    k++;

    cout << "Second equation:\n";
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". term (real, imaginary): ";
        cin >> real >> imag;
        equation2[i] = complex<double>(real, imag);
        detr[k][i] = equation2[i];
    }
    k++;

    cout << "Third equation:\n";
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". term (real, imaginary): ";
        cin >> real >> imag;
        equation3[i] = complex<double>(real, imag);
        detr[k][i] = equation3[i];
    }

    cout << "******************\n";
    for (int i = 1; i <= 4; i++) {
        complex<double> result = determinant(i, detr);
        if (result.real() == 0) {
            hasZeroReal = true;
        } else if (result.imag() == 0) {
            hasZeroImag = true;
        }
        cout << "D" << (i == 1 ? "" : to_string(i-1)) << " = ";
        if (result.real() == 0) {
            if (result.imag() == 0) {
                cout << "0";
            } else {
                cout << (result.imag() > 0 ? "" : "-") 
                     << (abs(result.imag()) == 1 ? "i" : to_string(abs(result.imag())) + "i");
            }
        } else {
            cout << result.real();
            if (result.imag() != 0) {
                cout << (result.imag() > 0 ? " + " : " - ")
                     << (abs(result.imag()) == 1 ? "i" : to_string(abs(result.imag())) + "i");
            }
        }
        cout << "\n";
          
        det_array[i] = result;
    }

    double rationalization = norm(det_array[1]);  // |z|² = a² + b²
    
    complex<double> x = (det_array[2] * conj(det_array[1])) / rationalization;
    complex<double> y = (det_array[3] * conj(det_array[1])) / rationalization;
    complex<double> z = (det_array[4] * conj(det_array[1])) / rationalization;

    cout << fixed << setprecision(3);
    
    cout << "X = " << x.real() << (x.imag() >= 0 ? " + " : " - ") << abs(x.imag()) << "i\n";
    cout << "Y = " << y.real() << (y.imag() >= 0 ? " + " : " - ") << abs(y.imag()) << "i\n";
    cout << "Z = " << z.real() << (z.imag() >= 0 ? " + " : " - ") << abs(z.imag()) << "i\n";
    cout << "******************\n";
    
    return 0;
}

complex<double> determinant(int n, complex<double> det[3][4]) {
    d = complex<double>(0, 0);
    switch (n)
    {
        case 1:
    d = ((det[0][0] * det[1][1] * det[2][2]) 
        + (det[0][1] * det[1][2] * det[2][0]) 
        + (det[0][2] * det[1][0] * det[2][1])) 
        - ((det[2][0] * det[1][1] * det[0][2]) 
        + (det[2][1] * det[1][2] * det[0][0]) 
        + (det[2][2] * det[1][0] * det[0][1]));
        det_array[n] = d;
        break;
    case 2:
    d = ((det[0][3] * det[1][1] * det[2][2]) 
        + (det[0][1] * det[1][2] * det[2][3]) 
        + (det[0][2] * det[1][3] * det[2][1])) 
        - ((det[2][3] * det[1][1] * det[0][2]) 
        + (det[2][1] * det[1][2] * det[0][3]) 
        + (det[2][2] * det[1][3] * det[0][1]));
        det_array[n] = d;
        break;
    case 3:
    d = ((det[0][0] * det[1][3] * det[2][2]) 
        + (det[0][3] * det[1][2] * det[2][0]) 
        + (det[0][2] * det[1][0] * det[2][3])) 
        - ((det[2][0] * det[1][3] * det[0][2]) 
        + (det[2][3] * det[1][2] * det[0][0]) 
        + (det[2][2] * det[1][0] * det[0][3]));
        det_array[n] = d;
        break;
    case 4:
     d = ((det[0][0] * det[1][1] * det[2][3]) 
        + (det[0][1] * det[1][3] * det[2][0]) 
        + (det[0][3] * det[1][0] * det[2][1])) 
        - ((det[2][0] * det[1][1] * det[0][3]) 
        + (det[2][1] * det[1][3] * det[0][0]) 
        + (det[2][3] * det[1][0] * det[0][1]));
        det_array[n] = d;
        break;
    default:
        break;
    }
    return d;
}
