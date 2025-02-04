#include<bits/stdc++.h>
using namespace std;

const double dif = 1e-6;

class Secant {

private:
    double tolerance, x0, x1;
    double maxIteration;

public:
    Secant(double mxIter, double tol, double initialX0, double initialX1) {
        tolerance = tol;
        maxIteration = mxIter;
        x0 = initialX0;
        x1 = initialX1;
    }

    double func(double x) {
        return x * x * x - 5 * x + 3; 
    }

    double findRoot() {
        cout << "Initial guesses x0 = " << x0 << ", x1 = " << x1 << endl;
        double x2 = 0;
        int i = 0;

        while (fabs(x1 - x0) >= tolerance && i < maxIteration) {
            x2 = x1 - (func(x1) * (x1 - x0)) / (func(x1) - func(x0));
            x0 = x1;
            x1 = x2;
            i++;
            cout << "Iteration " << i << " value is " << x2 << endl;
        }
        return x2;
    }
};

int main() {
    double tolerance = 1e-5;
    double maxIteration = 10;
    
    double x0, x1;
    cout << "Enter initial guess x0: ";
    cin >> x0;
    cout << "Enter initial guess x1: ";
    cin >> x1;

    Secant S(maxIteration, tolerance, x0, x1); 
    cout << "The root of the equation is : " << S.findRoot() << endl;

    return 0;
}