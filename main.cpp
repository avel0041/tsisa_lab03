#include <iostream>
#include <ctime>
#include <cmath>
#include <locale>
#include <iomanip>

using namespace std;

double myfun(double x) {
    return cos(x)*tan(x);
}

double myfun_sin5x(double x) {
    return myfun(x) * sin(5 * x);
}

double Random(int a, int b)
{
    return a + (1.*rand()/RAND_MAX)*(b - a);
}

int main() {
    srand(time(0));
    const double a = -2;
    const double b = 0;
    const double Tmax = 10000;
    const double Tmin = 0.1;
    double N = 1;
    double xmin = Random(a, b);
    double Ti = Tmax;
    cout << "f(x) = cos(x)*tan(x):" << endl;
    cout << setw(3) << "N" << setw(10) << "T" <<
         setw(11) << "x" << setw(11) << "f(x)"<< endl;
    while (Ti > Tmin) {
        double xi = Random(a, b);
        if ((myfun(xi) - myfun(xmin)) <= 0) {
            xmin = xi;
        }
        else {
            double P = exp(-(myfun(xi) - myfun(xmin)) / Ti);
            if ((rand() % 100 / 100.) <= P) {
                xmin = xi;
            }
        }
    //    cout << setw(3) << N << setw(10) << Ti <<
     //       setw(11) << xmin << setw(11) << myfun(xmin)<< endl;
        cout << N << ";" << Ti <<
             ";" << xmin << ";" << myfun(xmin)<< endl;
        Ti = Ti * 0.95;
        N++;
    }
    cout << "X = "<<  xmin << endl;
    cout << "f(X) = " << myfun(xmin) << endl << endl;

    N = 1;
    xmin = Random(a, b);
    Ti = Tmax;
    cout << "F(x) = cos(x)*tan(x)*sin(5x):" << endl;
    cout << setw(3) << "N" << setw(10) << "T" <<
         setw(11) << "x" << setw(11) << "f(x)"<< endl;
    while (Ti > Tmin) {
        double xi = Random(a, b);
        if ((myfun_sin5x(xi) - myfun_sin5x(xmin)) <= 0) {
            xmin = xi;
        }
        else {
            double P = exp(-(myfun_sin5x(xi) - myfun_sin5x(xmin)) / Ti);
            if ((rand() % 100 / 100.) <= P) {
                xmin = xi;
            }
        }
        //cout << setw(3) << N << setw(10) << Ti <<
         //    setw(11) << xmin << setw(11) << myfun_sin5x(xmin)<< endl;
        cout << N << ";" << Ti <<
             ";" << xmin << ";" << myfun_sin5x(xmin)<< endl;
        Ti = Ti * 0.95;
        N++;
    }
    cout << "X = " << xmin << endl;
    cout << "F(X) = "<< myfun_sin5x(xmin);
}