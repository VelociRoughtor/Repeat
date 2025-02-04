#include <bits/stdc++.h>
using namespace std;

class Trapezoid {
private:
    double func(double x) {
        return 1.0 / (1 + x);  
    }

public:
    double findArea(int n, double a, double b) {
        double h = (b - a) / n;
        double res = func(a) + func(b);
        double x = a;
        for (int i = 1; i < n; i++) {  
            x += h;
            res += 2 * func(x);  
        }
        res *= h / 2;
        return res;
    }
};

int main() {
    Trapezoid tp;
    int n;
    cin >> n;
    double a, b;
    cin >> a >> b;
    cout << fixed << setprecision(6) << tp.findArea(n, a, b) << endl;  
    return 0;
}
