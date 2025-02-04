#include<bits/stdc++.h>
using namespace std;

class Euler{
private:
    double func(double x, double y) {
        return x + y;
    }

public:
    double findValue(double a, double b, double h, double value) {
        while(a < value) {
            b += h * func(a, b);
            a += h;
        }
        return b;
    }

};

int main(){
    double x0, y0, h, value;
    cin >> x0 >> y0 >> h >> value;
    Euler el;
    cout << el.findValue(x0, y0, h, value) << endl;
    return 0;
}