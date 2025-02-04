#include<bits/stdc++.h>
using namespace std;

class GaussJordan {
public:
    void swapRow(vector<vector<double>>& mat, int i, int j) {
        int N = mat.size();
        for (int k = 0; k <= N; k++) {
            swap(mat[i][k], mat[j][k]);
        }
    }

    int echelon(vector<vector<double>>& mat) {
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
            if (abs(mat[k][i_max]) < 1e-9) return k;
            if (i_max != k)
                swapRow(mat, i_max, k);
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

    void normal(vector<vector<double>>& mat) {
        int N = mat.size();
        for (int k = 0; k < N; k++) {
            double pivot = mat[k][k];
            if (abs(pivot) < 1e-9) continue;
            for (int j = k; j <= N; j++) {
                mat[k][j] /= pivot;
            }
            for (int i = 0; i < N; i++) {
                if (i == k) continue;
                double factor = mat[i][k];
                for (int j = k; j <= N; j++) {
                    mat[i][j] -= mat[k][j] * factor;
                }
            }
        }
    }

    bool gauss(vector<vector<double>>& mat) {
        int N = mat.size();
        int flag = echelon(mat);
        if (flag != -1) {
            if (abs(mat[flag][N]) > 1e-9) cout << "Inconsistent system\n";
            else cout << "Infinite solutions\n";
            return false;
        }
        normal(mat);
        return true;
    }
};

int main() {
    GaussJordan formula;
    int N;
    cin >> N;
    vector<vector<double>> mat(N, vector<double>(N + 1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            cin >> mat[i][j];
        }
    }
    bool exist = formula.gauss(mat);
    cout << fixed << setprecision(6);
    if (exist) {
        for (int i = 0; i < N; i++) {
            cout << mat[i][N] << endl;
        }
    }
    return 0;
}