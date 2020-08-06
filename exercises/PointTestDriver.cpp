#include <iostream>
#include <iomanip>
#include "Point.hpp"

using namespace std;

int main()
{
    Point pt;

    cout << "Test case 1: Point after it has been instantiated." << endl;
    cout << "Expected result: Point is (0.0,0.0,0.0)." << endl;
    cout << setprecision(1) << fixed;
    cout << "**Actual result: Point is (" << (double) pt.getX() << ","
    << (double) pt.getY() << ","<< (double) pt.getZ() << ")" << endl;

    cout << "Testcase 2: Point after it has been set to (1.1,2.2,3.3)." << endl;
    pt.setX(1.1);
    pt.setY(2.2);
    pt.setZ(3.3);
    cout << "Expected result: Point is (1.1,2.2,3.3)" << endl;
    cout << "**Actual result: Point is (" << (double) pt.getX() << ","
    << (double) pt.getY() << "," << (double) pt.getZ() << ")";

    cout << "Done!" << endl;

    return 0;
}