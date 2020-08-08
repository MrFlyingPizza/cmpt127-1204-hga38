#include "image2.hpp"
#include <iostream>
#include <fstream>
#include <exception>

Image::Image() : cols(0), rows(0), pixels(NULL)
{
}

Image::~Image()
{
    //std::cout << "Destructor called @ " << &(this->pixels) << std::endl;
    delete[] pixels;
    //std::cout << "Good" << std::endl;
}

/* Changes the size of an image, allocating memory as necessary, and
    setting all pixels to fillcolour. Returns 0 on success, or a
    non-zero error code.*/
int Image::resize(unsigned int width, unsigned int height, uint8_t fillcolour)
{
    if (pixels != NULL) delete[] this->pixels;
    this->pixels = new uint8_t[width*height];

    for (unsigned int i = 0; i < width*height; i++)
        pixels[i] = fillcolour;
    
    this->cols = width;
    this->rows = height;

    return 0;
}

/* Sets the colour of the pixel at (x,y) to colour. Returns 0 on
    success, else a non-zero error code. If (x,y) is not a valid
    pixel, the call fails and the image does not change.*/
int Image::set_pixel(unsigned int x, unsigned int y, uint8_t colour)
{
    if (x >= cols || y >= rows)
    {
        std::cerr << "Pixel target out of bounds.\n";
        return 1;
    }
    
    try
    {
        pixels[y * cols + x] = colour;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 2;
    }
    return 0;
}

/* Gets the colour of the pixel at (x,y) and stores at the address
    pointed to by colourp. Returns 0 on success, else a non-zero error
    code. */
int Image::get_pixel(unsigned int x, unsigned int y, uint8_t *colourp)
{
    if (colourp == NULL)
    {
        std::cerr << "NULL colour pointer." << std::endl;
        return 3;
    }

    if (x >= cols || y >= rows)
    {
        std::cerr << "Pixel target out of bounds.\n";
        return 1;
    }

    try
    {
        *colourp = pixels[y * cols + x];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 2;
    }
    return 0;
}

/* Saves the image in the file filename. In a format that can be
    loaded by load(). Returns 0 on success, else a non-zero error
    code. */
int Image::save(const char *filename)
{
    if (filename == NULL)
    {
        return 2;
    }
    
    std::ofstream file(filename, std::ios::out | std::ios::binary);
    if (file.is_open())
    {
        file.write((char*) &rows, sizeof(unsigned int));
        file.write((char*) &cols, sizeof(unsigned int));
        file.write((char*) &pixels, sizeof(uint8_t) * cols * rows);

        file.close();
    }
    else
    {
        std::cout << "File not open to writing.\n";
        return 1;
    }
    return 0;
}

/* Load the an image from the file filename, replacing the current
    image size and data. The file is in a format that was saved by
    save(). Returns 0 success, else a non-zero error code . */
int Image::load(const char *filename)
{
    if (filename == NULL)
    {
        return 2;
    }
    
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (file.is_open())
    {
        file.read((char*) &rows, sizeof(unsigned int));
        file.read((char*) &cols, sizeof(unsigned int));
        resize(cols, rows, 0);
        file.read((char*) &pixels, sizeof(uint8_t)*cols*rows);
        
        file.close();
    }
    else
    {
        std::cout << "File not open to writing.\n";
        return 1;
    }
    return 0;
}