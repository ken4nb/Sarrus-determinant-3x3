#include <iostream>
#include <complex>
#include <iomanip>
#include <cstdlib>

using namespace std;

complex<double> d;
complex<double> det_niz[4];
complex<double> detr[3][4];
bool jedinka = false, jedinka2 = false;

complex<double> determinanta(int n, complex<double> det[3][4]);

int main() {
    complex<double> jednacina1[4], jednacina2[4], jednacina3[4];
    int k = 0;
    double real, imag;

    cout << "Unesite jednacine za determinantu:\n";
    cout << "Prva jednacina:\n";
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". clan (realni, imaginarni): ";
        cin >> real >> imag;
        jednacina1[i] = complex<double>(real, imag);
        detr[k][i] = jednacina1[i];
    }
    k++;

    cout << "Druga jednacina:\n";
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". clan (realni, imaginarni): ";
        cin >> real >> imag;
        jednacina2[i] = complex<double>(real, imag);
        detr[k][i] = jednacina2[i];
    }
    k++;

    cout << "Treca jednacina:\n";
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". clan (realni, imaginarni): ";
        cin >> real >> imag;
        jednacina3[i] = complex<double>(real, imag);
        detr[k][i] = jednacina3[i];
    }

    cout << "******************\n";
    for (int i = 1; i <= 4; i++) {
        complex<double> rezultat = determinanta(i, detr);
        if (rezultat.real() == 0) {
            jedinka = true;
        } else if (rezultat.imag() == 0) {
            jedinka2 = true;
        }
        cout << "D" << (i == 1 ? "" : to_string(i-1)) << " = ";
        if (rezultat.real() == 0) {
            if (rezultat.imag() == 0) {
                cout << "0";
            } else {
                cout << (rezultat.imag() > 0 ? "" : "-") 
                     << (abs(rezultat.imag()) == 1 ? "i" : to_string(abs(rezultat.imag())) + "i");
            }
        } else {
            cout << rezultat.real();
            if (rezultat.imag() != 0) {
                cout << (rezultat.imag() > 0 ? " + " : " - ")
                     << (abs(rezultat.imag()) == 1 ? "i" : to_string(abs(rezultat.imag())) + "i");
            }
        }
        cout << "\n";
          
        det_niz[i] = rezultat;
    }

    double racionalisanje = norm(det_niz[1]);  // |z|² = a² + b²
    
    complex<double> x = (det_niz[2] * conj(det_niz[1])) / racionalisanje;
    complex<double> y = (det_niz[3] * conj(det_niz[1])) / racionalisanje;
    complex<double> z = (det_niz[4] * conj(det_niz[1])) / racionalisanje;

    cout << fixed << setprecision(3);
    
    cout << "X = " << x.real() << (x.imag() >= 0 ? " + " : " - ") << abs(x.imag()) << "i\n";
    cout << "Y = " << y.real() << (y.imag() >= 0 ? " + " : " - ") << abs(y.imag()) << "i\n";
    cout << "Z = " << z.real() << (z.imag() >= 0 ? " + " : " - ") << abs(z.imag()) << "i\n";
    cout << "******************\n";
    
    return 0;
}

complex<double> determinanta(int n, complex<double> det[3][4]) {
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
        det_niz[n] = d;
        break;
    case 2:
    d = ((det[0][3] * det[1][1] * det[2][2]) 
        + (det[0][1] * det[1][2] * det[2][3]) 
        + (det[0][2] * det[1][3] * det[2][1])) 
        - ((det[2][3] * det[1][1] * det[0][2]) 
        + (det[2][1] * det[1][2] * det[0][3]) 
        + (det[2][2] * det[1][3] * det[0][1]));
        det_niz[n] = d;
        break;
    case 3:
    d = ((det[0][0] * det[1][3] * det[2][2]) 
        + (det[0][3] * det[1][2] * det[2][0]) 
        + (det[0][2] * det[1][0] * det[2][3])) 
        - ((det[2][0] * det[1][3] * det[0][2]) 
        + (det[2][3] * det[1][2] * det[0][0]) 
        + (det[2][2] * det[1][0] * det[0][3]));
        det_niz[n] = d;
        break;
    case 4:
     d = ((det[0][0] * det[1][1] * det[2][3]) 
        + (det[0][1] * det[1][3] * det[2][0]) 
        + (det[0][3] * det[1][0] * det[2][1])) 
        - ((det[2][0] * det[1][1] * det[0][3]) 
        + (det[2][1] * det[1][3] * det[0][0]) 
        + (det[2][3] * det[1][0] * det[0][1]));
        det_niz[n] = d;
        break;
    default:
        break;
    }
    return d;
}