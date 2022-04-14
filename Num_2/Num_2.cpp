// Mykola Vasyclhuk Lab 2;
// Variant 1
#include <iostream> 
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void SLAU();

void methodGauss() {
    double x[5];
    double a[6][6] = { {0,0,0,0,0,0}, 
                        {0,7,2,3,0,20}, 
                        {0,0,3,2,6,36}, 
                        {0,2,5,1,0,15}, 
                        {0,0,1,4,2,22} };
    int n = 4;


    double roots[4] = { 1,2,3,4 };
    cout << "Root x1: " << roots[0] << endl;
    cout << "Root x2: " << roots[1] << endl;
    cout << "Root x3: " << roots[2] << endl;
    cout << "Root x4: " << roots[3] << endl << endl;
    
    cout << "Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            cout << a[i][j] << "\t";
            if (j == n) {
                cout << "| ";
            }
        };
        cout << "\n";
    };

    double m;
    cout << setprecision(5);
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            m = a[j][i] / a[i][i];

            for (int k = 1; k <= n + 1; k++)
            {
                a[j][k] = a[j][k] - m * a[i][k];
            };
        };
        cout << endl;
        cout << "Step: " << i << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n + 1; j++) {
                cout << a[i][j] << "\t";
                if (j == n) {
                    cout << "| ";
                }
            };
            cout << "\n";
        };
    };

    x[n] = a[n][n + 1] / a[n][n];

    for (int i = n - 1; i >= 1; i--)
    {
        x[i] = a[i][n + 1];
        for (int j = i + 1; j <= n; j++)
        {
            x[i] = x[i] - a[i][j] * x[j];
        };
        x[i] = x[i] / a[i][i];
    };

    cout << endl << "Roots: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "x" << i << ": " << x[i] << endl;
    };
}

void determinant() {
    double a[5][5] = { {0,0,0,0,0},
                        {0,7,2,3,0},
                        {0,0,3,2,6},
                        {0,2,5,1,0},
                        {0,0,1,4,2} };
    int n = 4;

    cout << "Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << "\t";
        };
        cout << "\n";
    };

    int root_det = 620;
    cout << "Determinant: " << root_det << endl;
  

    double m;
    cout << setprecision(5);
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            m = a[j][i] / a[i][i];

            for (int k = 1; k <= n + 1; k++)
            {
                a[j][k] = a[j][k] - m * a[i][k];
            };
        };
        cout << endl;
        cout << "Step: " << i << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << a[i][j] << "\t";
            };
            cout << "\n";
        };
    };

    double det = 1;
    for (int i = 1; i <= n; i++) {
        det *= a[i][i];
    }
    cout << endl;
    cout << "Calculated determinant: " << det << endl;


}

void InverseMatrix() {
    double a[12][12] = { {0,0,0,0,0,0,0,0},
                        {0,7,2,3,0},
                        {0,0,3,2,6},
                        {0,2,5,1,0},
                        {0,0,1,4,2} };
    int n = 4;

    cout << "Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << "\t";
        };
        cout << "\n";
    };

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                a[i][j + n] = 1;
            }
            else
            {
                a[i][j + n] = 0;
            }
        };
    };

    cout << endl;
    cout << setprecision(3);
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {

            cout << a[i][j] << "\t";
            if (j == n) {
                cout << "| ";
            }
        };
        cout << "\n";
        if (i == n) { break; }
    };

    double m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                m = a[j][i] / a[i][i];
                for (int k = 1; k <= 2 * n; k++)
                {
                    a[j][k] = a[j][k] - m * a[i][k];
                };
            }
        };
    };
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = n + 1; j <= 2 * n; j++)
        {
            a[i][j] = a[i][j] / a[i][i];
        };
    };

    cout << endl;
    cout << setprecision(3);
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {

            if (a[i][j] == -0) { a[i][j] = 0; }

            cout << a[i][j] << "\t";
            if (j == n) {
                cout << "| ";
            }
        };
        cout << "\n";
        if (i == n) { break; }
    };
    

    cout << setprecision(3);
    cout << endl << "Inverse matrix:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n + 1; j <= 2 * n; j++)
        {
            if (a[i][j] == -0) { a[i][j] = 0; }

            cout << a[i][j] << "\t";
        };
        cout << endl;
    };
}

void algo_Gauss() {
    while (true) {
        cout << "Choose (undefined symbol = back to main menu):\n(1) Gauss method;\n(2) Search for a determinant;\n(3) Inverse matrix\n";
        int i;
        cin >> i;
        if (i == 1) {
            methodGauss();
            algo_Gauss();
            break;
        }
        else if (i == 2) {
            determinant();
            algo_Gauss();
            break;
        }
        else if (i == 3) {
            InverseMatrix();
            algo_Gauss();
            break;
        }
        else { SLAU(); };
    }
}
/////


void algo_Tridiagonal() {
    double a[3][3] = { {1, 2, 0},
                       {2, 2, 3},
                       {0, 3, 2} };
    double f[3] = { 5, 
                    15, 
                    12 };
    int dim = 3;

    double alfa[3] = {};
    double beta[3] = {};
    double z[3] = {};
    double x[4] = {};

    double roots[3] = { 1,2,3 };

    cout << "Matrix:\n";
    for (int i = 0; i <= dim - 1; i++)
    {
        for (int j = 0; j <= dim - 1; j++)
        {
            cout << a[i][j] << " ";
        };  
        cout << "|" << f[i] << endl;
    };

    cout << "Root x1: " << roots[0] << endl;
    cout << "Root x2: " << roots[1] << endl;
    cout << "Root x3: " << roots[2] << endl << endl;

    cout << "Let's start calculating the coefficients alpha and beta, zet will also be displayed\n";
    alfa[0] = a[0][1] / -a[0][0]; // 2 / (-1) = -2;
    beta[0] = -f[0] / -a[0][0];// -5 / -1 = 5;

    cout << "Iteration: 1" << endl;
    cout << "alfa1" <<": " << alfa[0] << endl;
    cout << "beta1" <<": " << beta[0] << endl;

    for (int i = 1; i <= dim-1; i++) {
        z[i] = -a[i][i] - a[i][i - 1] * alfa[i - 1];
        alfa[i] = a[i][i + 1] / z[i]; // 1.5, 0
        beta[i] = (-f[i] + a[i][i - 1] * beta[i - 1]) / z[i];// -2.5, 3
        if (i == dim - 1) {
            alfa[i] = 0;
        }
        cout << "Iteration: " << i+1 << endl;
        cout << "alfa" << i+1 << ": " << alfa[i] << endl;
        cout << "beta" << i+1 << ": " << beta[i] << endl;
        cout << "z" << i+1 << ": " << z[i] << endl;
    };

    cout << endl;
    x[dim - 1] = beta[dim - 1];
    for (int i = 1; i >= 0; i--) {
        x[i] = alfa[i] * x[i + 1] + beta[i];
    };

    cout << "Calculated roots:\n";
    for (int i = 0; i < dim; i++) {
        cout.precision(15);
        cout << "x" << i + 1 << ": " << x[i] << endl;
    };
}
/////




void algo_Seidel() {
    double eps;
    cout << "You can enter precision (10^-3 = 1e-3):\n";
    cin >> eps;


    double x1[100] = {};
    double x2[100] = {};
    double x3[100] = {};
    double x4[100] = {};
    double a[4][4] = { {4, 0, 1, 0},
                       {0, 3, 0, 2},
                       {1, 0, 5, 1},
                       {0, 2, 1, 4} };
    double b[4] = { 7, 
                    14, 
                    20, 
                    23 };
    double dim = 4;
    /*
    x1[0] = b[0] / a[0][0];
    x2[0] = b[1] / a[1][1];
    x3[0] = b[2] / a[2][2];
    x4[0] = b[3] / a[3][3];
    */
    /*
    x1[0] = b[0];
    x2[0] = b[1];
    x3[0] = b[2];
    x4[0] = b[3];
    */
    ///*
    x1[0] = 0;
    x2[0] = 0;
    x3[0] = 0;
    x4[0] = 0;
    //*/

    cout << "Matrix:\n";
    for (int i = 0; i <= dim - 1; i++)
    {
        for (int j = 0; j <= dim - 1; j++)
        {
            cout << a[i][j] << " ";
        };
        cout << "|" << b[i] << endl;
    };

    cout << "Starting x1_0: " << x1[0] << endl;
    cout << "Starting x2_0: " << x2[0] << endl;
    cout << "Starting x3_0: " << x3[0] << endl;
    cout << "Starting x4_0: " << x4[0] << endl;

    cout << "Answers:\nx1 = 1\nx2 = 2\nx3 = 3\nx4 = 4\n\n";

    int i = 1;
    while(true) {
        x1[i] = (b[0] - x3[i - 1]) / a[0][0];
        x2[i] = (b[1] - 2 * x4[i - 1]) / a[1][1];
        x3[i] = (b[2] - x1[i] - x4[i - 1]) / a[2][2];
        x4[i] = (b[3] - 2 * x2[i] - x3[i]) / a[3][3];

        cout << "Iteration:" << i << endl;
        cout.precision(15);
        cout << "x1: " << x1[i] << endl;
        cout << "x2: " << x2[i] << endl;
        cout << "x3: " << x3[i] << endl;
        cout << "x4: " << x4[i] << endl;

        if ((abs(x1[i] - x1[i - 1]) <= eps) && (abs(x2[i] - x2[i - 1]) <= eps) && (abs(x3[i] - x3[i - 1]) <= eps) && (abs(x4[i] - x4[i - 1]) <= eps)) 
        { break; }

        i++;
    }

}
void SLAU()
{
    while (true) {
        cout << "Choose (undefined symbol = exit):\n(1) Gauss, determinant, inverse matrix;\n(2) Tridiagonal matrix algorithm\n(3) Seidel algorithm\n";
        int i;
        cin >> i;
        if (i == 1) {
            algo_Gauss();
            SLAU();
            break;
        }
        else if (i == 2) {
            algo_Tridiagonal();
            SLAU();
            break;
        }
        else if (i == 3) {
            algo_Seidel();
            SLAU();
            break;
        }
        else { break; };
    }
}

int main() {
    SLAU();
	return 0;
}