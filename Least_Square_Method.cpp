#include <bits/stdc++.h>
using namespace std;

struct Point {
    double a, b;
};

class LeastSquareMethod {
public:
    pair<double, double> findMandC(vector<Point> points) {
        int n = points.size();
        double x = 0, y = 0, xy = 0, xsq = 0;
        
        for (auto &it : points) {
            x += it.a;
            y += it.b;
            xy += it.a * it.b;
            xsq += it.a * it.a;
        }

        double a1 = (n * xy - x * y) / (n * xsq - x * x);
        double a0 = (y / n) - a1 * (x / n);

        return {a0, a1}; 
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].a >> points[i].b;
    }

    LeastSquareMethod curve;
    pair<double, double> ans = curve.findMandC(points);
    
    cout << "a0 = " << ans.first << " and a1 = " << ans.second << endl;

    return 0;
}