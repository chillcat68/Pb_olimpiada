#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("covor.in");
ofstream g ("covor.out");

int n, k, v;

int main() {
    f >> n >> k >> v;

    int a1 = 3, r = 4;
    int sol = 1, i = 1;
    while(sol <= n) {
        sol = a1 * i + r * i * (i - 1) / 2 + 1;
        i++;
    }
    i -= 2;
    if (v == 1) {
        g << i << '\n';
        return 0;
    }

    int a, b, romb = 2;
    a = 1; b = 3;
    r = 1;
    while(romb <= i) {
        r += 2;
        a = b + 1;
        b = a + r;
        //cout << r << ' ' << a << ' ' << b << endl;
        if (a <= k && k <= b) {
            g << romb;
            return 0;
        }
        romb++;
    }

    romb--;

    r = r + 1;
    while(romb > 0) {
        r -= 2;
        a = b + 1;
        b = a + r;
        //cout << r << ' ' << a << ' ' << b << endl;
        if (a <= k && k <= b) {
            g << romb;
            return 0;
        }
        romb--;
    }

    g << 0;
    return 0;
}
