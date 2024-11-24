#include <iostream>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
struct Circle {
    double x, y, r;
};
 
bool inCircle(double x, double y, Circle cur) {
    return (pow(x - cur.x, 2) + pow(y - cur.y, 2) <= pow(cur.r, 2));
}
 
int main() {
    Circle circles[3];
    double num = 1000000; 
    double counter = 0;
    
    for (int i = 0; i < 3; ++i) {
        cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }
    
    double x_min = fmin(fmin(circles[0].x - circles[0].r, circles[1].x - circles[1].r), circles[2].x - circles[2].r);
    double x_max = fmin(fmin(circles[0].x + circles[0].r, circles[1].x + circles[1].r), circles[2].x + circles[2].r);
    double y_min = fmin(fmin(circles[0].y - circles[0].r, circles[1].y - circles[1].r), circles[2].y - circles[2].r);
    double y_max = fmin(fmin(circles[0].y + circles[0].r, circles[1].y + circles[1].r), circles[2].y + circles[2].r);
    double area = (x_max - x_min) * (y_max - y_min);

 
    for (int i = 0; i < num; ++i) {
        double x = x_min + static_cast<double>(rand()) / RAND_MAX * (x_max - x_min);
        double y = y_min + static_cast<double>(rand()) / RAND_MAX * (y_max - y_min);
        
        if (inCircle(x, y, circles[0]) && inCircle(x, y, circles[1]) && inCircle(x, y, circles[2])) {
            counter++;
        }
    }
    
    double s = counter / num * area;
    cout  << setprecision(10) << s;
 
    return 0;
}