#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
};

class Newton_DDI {
public:
    double findValue(vector<point>& points, double value) {
        int n = points.size();
        vector<vector<double>> dd(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++) {
            dd[i][0] = points[i].y;
        }
        for (int j = 1; j < n; j++) {
            for (int i = 0; i + j < n; i++) {
                dd[i][j] = (dd[i + 1][j - 1] - dd[i][j - 1]) / (points[i + j].x - points[i].x);
            }
        }

        double u = (value - points[0].x) / (points[1].x - points[0].x);
        double res = dd[0][0];
        double term = 1;
        for (int i = 1; i < n; i++) {
            term *= (value - points[i - 1].x);
            res += term * dd[0][i];
        }

        return res;
    }
};

int main() {
    Newton_DDI nf;
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
