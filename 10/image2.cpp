#include "image2.hpp"
#include <iostream>
#include <fstream>

/* Saves the image in the file filename. In a format that can be
    loaded by load(). Returns 0 on success, else a non-zero error
    code. */
int Image::save(const char *filename)
{
    std::ofstream file(filename, std::ios::out | std::ios::binary);
    if (file.is_open())
    {
        file << pixels;
    }
    else
    {
        std::cout << "File not open to writing.\n";
        return 1;
    }
    
}

/* Load the an image from the file filename, replacing the current
    image size and data. The file is in a format that was saved by
    save(). Returns 0 success, else a non-zero error code . */
int Image::load(const char *filename)
{
    std::ifstream file(filename, std::ios::out | std::ios::binary);
    file >> pixels;
}