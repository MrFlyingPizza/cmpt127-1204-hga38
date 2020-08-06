// Point.hpp
// By Richard (Han) Gao
// Aug 3 2020

class Point {

private:
    // points of 3D coordinates
    double x;
    double y;
    double z;

public:

    // default constructor
    Point();

    // getters
    double getX() const;
    double getY() const;
    double getZ() const;

    // setters
    void setX(double someX);
    void setY(double someY);
    void setZ(double someZ);
};

// default constructor
Point::Point()
: x(0.0), y(0.0), z(0.0)
{ }

// get X
double Point::getX() const
{
    return x;
}

// get Y
double Point::getY() const
{
    return y;
}

// get Z
double Point::getZ() const
{
    return z;
}

// set X
void Point::setX(double someX)
{
    this->x = someX;
}

// set y
void Point::setY(double someY)
{
    this->y = someY;
}

// set z
void Point::setZ(double someZ)
{
    this->z = someZ;
}
