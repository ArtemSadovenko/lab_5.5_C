#include <iostream>
#include <math.h>

using namespace std;

int tsize(int n);
int stupid_dobutok(int ab, int cd, int &ty);
int max(int a, int b);

int main() {
    int a, b, c, d, r, s, lvl = 0;

    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    cout << "d = "; cin >> d;

    r = stupid_dobutok(a, c, lvl) - stupid_dobutok(b, d, lvl);
    s = stupid_dobutok(a, d, lvl) + stupid_dobutok(c, b, lvl);

    cout << "(" << a << " + " << b << "i)" << "(" << c << " + " << d << "i) = "
        << r << " + " << s << "i\n";

    cout << "lvl = " << lvl << endl;
    cout << "deep = " << lvl + 1 << endl;
}

int tsize(int n){
    int tt = 0;
    while (n > 0){
        n /= 10;
        tt++;
    }
    return tt;
}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int stupid_dobutok(int ab, int cd, int& ty){
    if (ab < 10 && cd < 10)
        return ab * cd;
    ty += 1;

    int size = max(tsize(ab), tsize(cd));

    int n = (size / 2.0);
    int p = pow(10, n);
    int a = (ab / p);
    int b = ab % p;
    int c = (cd / p);
    int d = cd % p;
    
    int d0 = stupid_dobutok(a, c, ty);
    int d1 = stupid_dobutok(b, d, ty);
    int d2 = stupid_dobutok(a + b, c + d, ty) - d0 - d1;

    return (pow(10 , 2 * n) * d0 + pow(10 , n) * d2 + d1);
}