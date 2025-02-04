#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
};

class Newton_Forward {
public:
    double findValue(vector<point>& points, double value) {
        int n = points.size();
        vector<vector<double>> y(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++) {
            y[i][0] = points[i].y;
        }
        for (int j = 1; j < n; j++) {
            for (int i = 0; i + j < n; i++) {
                y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
            }
        }

        double u = (value - points[0].x) / (points[1].x - points[0].x);
        double res = y[0][0];

        double U = 1;
        double F = 1;  
        for (int i = 1; i < n; i++) {
            U *= (u - (i - 1));  
            F *= i;            
            res += (U * y[0][i]) / F;
        }

        return res;
    }
};

int main() {
    Newton_Forward nf;
    int n;
    cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    double value;
    cin >> value;

    cout << fixed << setprecision(6) << nf.findValue(points, value) << endl;
    return 0;
}
