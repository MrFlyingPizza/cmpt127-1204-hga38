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

    pixels[y][x] = colour;
    
    return 0;
}

int Image::get_pixel(unsigned int x, unsigned int y, uint8_t* colourp)
{
    if (x >= cols || y >= rows)
    {
        std::cerr << "Coordinate out of bounds!" << std::endl;
        return 1;
    }

    *colourp = pixels[y][x];

    return 0;
}

int Image::save(const char* filename)
{
    if (filename == NULL)
    {
        std::cerr << "Filename does not exist." << std::endl;
        return 2;
    }
    
    std::ofstream file(filename, std::ios::out | std::ios::binary);
    if (file.is_open())
    {
        for (unsigned int i = 0; i < rows; i++)
        {
            for (unsigned int j = 0; j < cols; j++)
            {
                file << pixels[i][j];
            }
            
        }
        file.close();
    }
    else
    {
        std::cout << "File not open to writing.\n";
        return 1;
    }
    return 0;
}

int Image::load(const char* filename)
{
    if (filename == NULL)
    {
        std::cerr << "Filename does not exist." << std::endl;
        return 2;
    }
    
    try
    {
        std::ifstream file(filename, std::ios::in | std::ios::binary);
        for (unsigned int i = 0; i < rows; i++)
        {
            for (unsigned int j = 0; j < cols; j++)
            {
                file >> pixels[i][j];
            }
            
        }
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cout << "failed to load image." << std::endl;
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}