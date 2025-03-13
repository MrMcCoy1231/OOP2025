#include "Canvas.h"
#include <iostream>
#include <cmath>

using namespace std;

Canvas::Canvas(int height, int width) {
    this->height = height;
    this->width = width;

    mat = new char* [height];
    for (int i = 0; i < height; i++) {
        mat[i] = new char[width];
        for (int j = 0; j < width; j++)  
            mat[i][j] = ' ';
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if ((i - x) * (i - x) + (j - y) * (j - y) == ray * ray)
                mat[i][j] = ch;  
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
                mat[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top; i <= bottom; i++) {
        if (i >= 0 && i < height) {
            if (left >= 0 && left < width) mat[i][left] = ch;
            if (right >= 0 && right < width) mat[i][right] = ch;
        }
    }
    for (int j = left; j <= right; j++) {
        if (j >= 0 && j < width) {
            if (top >= 0 && top < height) mat[top][j] = ch;
            if (bottom >= 0 && bottom < height) mat[bottom][j] = ch;
        }
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top; i <= bottom; i++)
        for (int j = left; j <= right; j++)
            if (i >= 0 && i < height && j >= 0 && j < width)
                mat[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < width && y >= 0 && y < height)
        mat[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2 - x1), sx = (x1 < x2) ? 1 : -1;
    int dy = -abs(y2 - y1), sy = (y1 < y2) ? 1 : -1;
    int error = dx + dy;

    while (true) {
        if (x1 >= 0 && x1 < width && y1 >= 0 && y1 < height)
            mat[y1][x1] = ch;

        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * error;
        if (e2 >= dy) { error += dy; x1 += sx; }
        if (e2 <= dx) { error += dx; y1 += sy; }
    }
}

void Canvas::Print() {
    for (int i = 0; i < height; i++) {  
        for (int j = 0; j < width; j++)
            cout << mat[i][j];
        cout << '\n';
    }
}

void Canvas::Clear() {
    for (int i = 0; i < height; i++)  
        for (int j = 0; j < width; j++)
            mat[i][j] = ' ';
}
