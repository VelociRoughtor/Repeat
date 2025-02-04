#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
};

class Lagrange {
public:
    double findValue(vector<point>& points, double value) {
        int n = points.size();
        vector<vector<double>> y(n, vector<double>(n, 0));
        double res = 0;
        for (int i = 0; i < n; i++) {
            double num = 1, den = 1;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    num *= (value - points[j].x);
                    den *= (points[i].x - points[j].x);
                }
            }
            res += num * points[i].y / den;
        }
        return res;
    }
};

int main() {
    Lagrange lg;
    int n;
    cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    double value;
    cin >> value;

    cout << fixed << setprecision(6) << lg.findValue(points, value) << endl;
    return 0;
}
