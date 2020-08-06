#include <stdlib.h>
#include "Point.hpp"

class Points {

private:
    // amount of points stored in array
    size_t len;

    // pointer to points array
    Point* points;

    // reversed memory in point array
    size_t reserved;

public:
    
    // Default constructor
    Points();

    // Destructor
    ~Points();

    // getters
    size_t get_len() const; // get array len
    size_t get_reserve_size() const; // get reserved
    Point* get_points() const; // get points pointer

    // having setters doesnt make sense
    // so I didn't put them.

    // initalize empty array (im not sure if 
    // this is supposed to be the constructor)
    void point_array_init();

    // reset point array
    void point_array_reset();

    // append point to end of array
    int point_array_append(Point p);

    // remove point from the array
    int point_array_remove(unsigned int i);
};

// Default constructor
Points::Points()
: len(0), points(nullptr), reserved(0)
{ }

// Destructor
Points::~Points()
{
    if (points != nullptr) delete[] points; // free space for the array
}

size_t Points::get_len() const
{
    return len;
}

size_t Points::get_reserve_size() const
{
    return reserved;
}

Point* Points::get_points() const
{
    return points;
}
