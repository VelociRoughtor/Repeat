#include<bits/stdc++.h>
using namespace std;

class FalsePosition{
private:
    double tolerance, a, b;
    int maxIteration;

public:
    FalsePosition(int mxItr, double tol) {
        tolerance = tol;
        maxIteration = mxItr;
        generateRandom();
    }

    double func(double x) {
        return x * x * x - 5 * x + 3;
    }

    void generateRandom() {
        srand(time(0));
        do {
            a = (rand() % 200 - 100) / 10.0;
            b = (rand() % 200 - 100) / 10.0;
        } while (func(a) * func(b) > 0);
    }

    double findRoot() {
        if (a > b) swap(a, b);
        cout << "Initial guess a = " << a << " b = " << b << endl;
        
        double c = (a * func(b) - b * func(a)) / (func(b) - func(a));  
        int i = 0;
        while (fabs(a - b) >= tolerance && i < maxIteration) {
            c = (a * func(b) - b * func(a)) / (func(b) - func(a));  
            if (fabs(func(c)) < tolerance) {
                return c;
            } else if (func(a) * func(c) < 0) {
                b = c;
            } else {
                a = c;
            }
            i++;
            cout << "Iteration " << i << " value is " << c << endl;
        }
        return c;
    }
};

int main() {
    double tolerance = 1e-5;
    int maxIteration = 100;
    FalsePosition FP(maxIteration, tolerance);
    cout << "Root of the equation is " << FP.findRoot() << endl;
    return 0;
}
