#include<bits/stdc++.h>
using namespace std;

class GaussElimination {
public:
    void swapRow(vector<vector<double>>& mat, int i, int j) {
        int N = mat.size();
        for (int k = 0; k <= N; k++) {
            swap(mat[i][k], mat[j][k]);
        }
    }

    int forwardElimination(vector<vector<double>>& mat) {
        int N = mat.size();
        for (int k = 0; k < N; k++) {
            double v_max = mat[k][k];
            int i_max = k;
            for (int i = k + 1; i < N; i++) {
                if (abs(mat[i][k]) > v_max) {
                    v_max = mat[i][k];
                    i_max = i;
                }
            }

            if (abs(mat[k][i_max]) < 1e-9) {
                return k;  
            }

            if (i_max != k) {
                swapRow(mat, i_max, k); 
            }

            for (int i = k + 1; i < N; i++) {
                double factor = mat[i][k] / mat[k][k];
                for (int j = k + 1; j <= N; j++) {
                    mat[i][j] -= mat[k][j] * factor;
                }
                mat[i][k] = 0;
            }
        }
        return -1;  
    }

    vector<double> backSubstitution(vector<vector<double>>& mat) {
        int N = mat.size();
        vector<double> x(N);
        for (int i = N - 1; i >= 0; i--) {
            x[i] = mat[i][N];
            for (int j = i + 1; j < N; j++) {
                x[i] -= mat[i][j] * x[j];
            }
            x[i] /= mat[i][i];  
        }
        return x;
    }

    vector<double> gauss(vector<vector<double>>& mat) {
        int N = mat.size();
        int flag = forwardElimination(mat);

        if (flag != -1) {
            if (abs(mat[flag][N]) > 1e-9) {
                cout << "Inconsistent system\n";  
            } else {
                cout << "Infinite solutions\n";  
            }
            return {};  
        }
        return backSubstitution(mat);
    }
};

int main() {
    GaussElimination formula;
    int N;
    cin >> N;
    vector<vector<double>> mat(N, vector<double>(N + 1));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            cin >> mat[i][j];
        }
    }

    vector<double> x = formula.gauss(mat);

    if (!x.empty()) {
        cout << fixed << setprecision(6);
        for (auto it : x) {
            cout << it << endl;
        }
    }

    return 0;
}