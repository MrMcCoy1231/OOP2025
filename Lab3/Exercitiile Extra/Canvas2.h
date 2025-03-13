#pragma once
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
class Canvas2 {
    
    int lines, columns;
    char** mat;
public:
    // contructor will call the clear method
    Canvas2(int lines, int columns);

    // set the character at the position x and y to value
    void set_pixel(int x, int y, char value);

    // tuples of x, y, value
    void set_pixels(int count, ...);

    void clear();
    void print() const;
};


