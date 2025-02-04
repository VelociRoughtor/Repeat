#include <bits/stdc++.h>
using namespace std;

class Simpson {
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
            if (i & 1) 
                res += 4 * func(x); 
            else 
                res += 2 * func(x);
        }
        res *= h / 3;
        return res;
    }
};

int main() {
    Simpson sp;
    int n;
    cin >> n;
    double a, b;
    cin >> a >> b;
    if (n & 1) {
        cout << "N has to be even" << endl;
        return 0;
    }
    cout << fixed << setprecision(6) << sp.findArea(n, a, b) << endl;  
    return 0;
}
