#include<bits/stdc++.h>
using namespace std;

class Bisection{
private:
    double tolerance, a, b;
    int maxIterations;

    double func(double x) {
        return x * x * x * x - x - 10;
    }

public:
    Bisection(int mxIter, double tol) {
        tolerance = tol;
        maxIterations = mxIter;
        generateRandom();
    }

    void generateRandom() {
        srand(time(0));
        do {
            a = ((rand() % 200) - 100) / 10.0;
            b = ((rand() % 200) - 100) / 10.0;
        }while(func(a) * func(b) > 0);
    }

    double findRoot() {
        cout << "Initial guess a = " << a << " and b = " << b << endl;
        if (a > b) swap(a, b);
        double c = a;
        int i = 0;
        while (fabs(a - b) >= tolerance && i < maxIterations) {
            c = (a + b) / 2;
            if (fabs(func(c)) < tolerance) 
                return c;
            else if (func(c) * func(a) > 0) 
                a = c;
            else 
                b = c;
            i++;
            cout << "Iteration " << i << "value is " << c << endl;
        }

        return c;
    }
};

int main(){
    double tolerance = 1e-3;
    int maxIterations = 100;
    Bisection bi(maxIterations, tolerance);
    cout << bi.findRoot() << endl;
    return 0;
}