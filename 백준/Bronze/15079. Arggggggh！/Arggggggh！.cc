#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; 
    double r=sin(45*M_PI/180), x, y;
    cin >> n >> x >> y;

    for (int i = 0; i < n; ++i) {
        string dir;
        int dst;
        cin >> dir >> dst;

        if (dir == "N")
            y += dst;
        else if (dir == "NE") {
            x += dst*r;
            y += dst*r;
        }
        else if (dir == "E")
            x += dst;
        else if (dir == "SE") {
            x += dst*r;
            y -= dst*r;
        }
        else if (dir == "S")
            y -= dst;
        else if (dir == "SW") {
            x -= dst*r;
            y -= dst*r;
        }
        else if (dir == "W")
            x -= dst;
        else if (dir == "NW") {
            x -= dst*r;
            y += dst*r;
        }
    }

    cout << fixed << setprecision(8) << x << " " << y << endl;

    return 0;
}
