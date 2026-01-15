
/*
    MADE BY AKSHAT
    GAUSSIAN-ELIMINATION METHOD TO SOLVE ANY SYSTEM OF n LINEAR EQUATIONS WITH n VARIABLES
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of variables: ";
    cin >> n;

    double matrix[n][n+1];

    cout << "Enter augmented matrix [A|b] below\n\n";
    for(int i=0;i<n;i++){for (int j=0;j<=n;j++){cin >> matrix[i][j]; }}

    // Gaussian Elimination
    for(int i=0;i<n;i++){

        // Pivot handling
        if(matrix[i][i] == 0){
            for(int k=i+1;k<n;k++) if(matrix[k][i] != 0){for(int j=0;j<=n;j++)swap(matrix[i][j], matrix[k][j]);break;}
        }

        if(matrix[i][i] == 0) continue;

        double pivot = matrix[i][i];

        // normalize pivot row
        for(int j=0;j<=n;j++)
            matrix[i][j] /= pivot;

        // eliminate below
        for(int k=i+1;k<n;k++){
            double factor = matrix[k][i];
            for(int j=0;j<=n;j++){ matrix[k][j] -= factor*matrix[i][j]; }}}

    // no solution or infinite solution
    int rank = 0;
    bool noSolution = false;

    for(int i=0;i<n;i++){
        bool allZero = true;
        for(int j=0;j<n;j++){ if(matrix[i][j] != 0){ allZero = false; break;}}

        if(allZero&&matrix[i][n] != 0){ noSolution = true;}
        if(!allZero) rank++;
    }

    if(noSolution){ cout<<"\n\033[31mNo solution exists.\033[0m\n"; return 0; }

    if(rank < n){ cout<<"\n\033[31mInfinite solutions exist.\033[0m\n"; return 0; }

    // back-substitution
    double x[n];

    for(int i=n-1;i>=0;i--){
        x[i] = matrix[i][n]; for(int j=i+1;j<n;j++){ x[i] -= matrix[i][j]*x[j]; }}

    cout<<"\nSolutions:\n";
    for(int i=0;i<n;i++){cout<<"x"<<i+1<<" = "<<x[i]<<endl;}
    return 0;
}
