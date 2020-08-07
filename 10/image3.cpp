#include "image3.hpp"
#include <iostream>
#include <fstream>
#include <exception>

Image::Image()
: cols(0), rows(0), pixels(NULL)
{ }

Image::~Image()
{
    for (unsigned int i = 0; i < rows; i++)
        delete[] pixels[i];

    delete[] pixels;
}

int Image::resize(unsigned int width, unsigned int height, uint8_t fillcolour)
{
    // create an array of row pointer
    try
    {
        pixels = new uint8_t*[height];

        for (unsigned int i = 0; i < height; i++)
        {
            pixels[i] = new uint8_t[width];
        }

    }
    catch(const std::bad_alloc& e)
    {
        std::cout << "Failed memory allocation." << std::endl;
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    for (unsigned int i = 0; i < height; i++)
    {
        for (unsigned int j = 0; j < width; j++)
        {
            pixels[i][j] = fillcolour;
        }
        
    }
    return 0;
}

int Image::set_pixel(unsigned int x, unsigned int y, uint8_t colour)
{
    if (x >= cols || y >= rows)
    {
        std::cerr << "Coordinate out of bounds!" << std::endl;
        return 1;
    }

    
    
    return 0;
}