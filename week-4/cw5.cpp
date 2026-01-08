#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function to compute f(n)
double f(int n) {
    double sum = 0.0;

    for (int i = 1; i <= n; i++) {
        sum += 1.0 / (i * i);
    }

    return sqrt(6 * sum);
}

int main() {
    cout << "n\tf(n)" << endl;
    cout << "----------------" << endl;

    for (int n = 2; n <= 20; n += 2) {
        cout << n << "\t" << fixed << setprecision(5) << f(n) << endl;
    }

    return 0;
}
