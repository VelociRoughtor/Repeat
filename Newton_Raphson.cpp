#include <bits/stdc++.h>
using namespace std;

class NewtonRaphson {

private:
    double tolerance, x;
    double maxIteration;

public:
    NewtonRaphson(double mxItr, double tol) {
        tolerance = tol;
        maxIteration = mxItr;
        generateRandom();
    }

    double func(double x) {
        return x * x * x - 5 * x + 3; 
    }

    double funcPrime(double x) {
        return 3 * x * x - 5; 
    }

    void generateRandom() {
        srand(time(0));
        x = (rand() % 200 - 100) / 10.0; 
    }

    double findRoot() {
        cout << "Initial guess x = " << x << endl;
        double h = func(x) / funcPrime(x);
        int i = 0;
        
        while (fabs(h) > tolerance && i < maxIteration) {
            x = x - h;
            h = func(x) / funcPrime(x);
            i++;
            cout << "Iteration " << i << " value is " << x << endl;
        }
        return x;
    }
};

int main() {
    double tolerance = 1e-5;
    double maxIteration = 100;
    NewtonRaphson NR(maxIteration, tolerance);
    cout << "Root of the equation is " << NR.findRoot() << endl;

    return 0;
}