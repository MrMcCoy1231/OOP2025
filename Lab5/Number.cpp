#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;

int DetectareBaza(const char* b)
{
    int max_val = 0;

    for (int i = 0; b[i] != '\0'; i++)
    {
        if (b[i] >= '0' && b[i] <= '9')
        {
            max_val = max(max_val, b[i] - '0');
        }
        else
            if (b[i] >= 'A' && b[i] <= 'Z')
            {
                max_val = max(max_val, b[i] - 'A' + 10);
            }
            else
                if (b[i] >= 'a' && b[i] <= 'z')
                {
                    max_val = max(max_val, b[i] - 'a' + 10);
                }
                else
                {
                    return -1;
                }
    }

    return max_val + 1;
}

Number::Number(const char* value, int base)
{
    if (value == nullptr)
    {
        this->nr = new char[2];
        strcpy(this->nr, "0");
    }
    else
    {
        this->nr = new char[strlen(value) + 1];
        strcpy(this->nr, value);
    }
    this->baza = base;
}

Number::~Number()
{
    delete[] this->nr;
}


Number::Number(const Number& x)
{
    this->baza = x.baza;

    this->nr = new char[strlen(x.nr) + 1];

    strcpy(this->nr, x.nr);
}

Number::Number(Number&& x) noexcept
{
    this->baza = x.baza;
    this->nr = x.nr;

    x.nr = nullptr;
    x.baza = 0;
}

void Number::SwitchBase(int newBase)
{
    int nr10 = strtol(this->nr, NULL, baza);

    char newNr[50];
    int i = 0;

    if (nr10 == 0)
    {
        strcpy(this->nr, "0");
        this->baza = newBase;
        return;
    }

    while (nr10 > 0)
    {
        int rest = nr10 % newBase;

        if (rest < 10)
        {
            newNr[i++] = rest + '0';
        }
        else
        {
            newNr[i++] = rest - 10 + 'A';
        }

        nr10 /= newBase;
    }

    newNr[i] = '\0';

    for (int k = 0, j = i - 1; k < j; k++, j--)
    {
        swap(newNr[k], newNr[j]);
    }

    strcpy(this->nr, newNr);
    this->baza = newBase;
}

void Number::Print()
{
    cout << this->nr;
}

int Number::GetDigitsCount()
{
    return strlen(this->nr);
}

int Number::GetBase()
{
    return this->baza;
}

Number operator+(const Number& a, const Number& b)
{
    Number c(nullptr, max(a.baza, b.baza));

    int x = strtol(a.nr, NULL, a.baza);
    int y = strtol(b.nr, NULL, b.baza);

    int nr10 = x + y;

    char newNr[50];
    int i = 0;

    if (nr10 == 0)
    {
        strcpy(c.nr, "0");

        return c;
    }

    while (nr10 > 0)
    {
        int rest = nr10 % max(a.baza, b.baza);

        if (rest < 10)
        {
            newNr[i++] = rest + '0';
        }
        else
        {
            newNr[i++] = rest - 10 + 'A';
        }

        nr10 /= max(a.baza, b.baza);
    }

    newNr[i] = '\0';

    for (int k = 0, j = i - 1; k < j; k++, j--)
    {
        swap(newNr[k], newNr[j]);
    }

    c.nr = new char[strlen(newNr) + 1];
    strcpy(c.nr, newNr);

    return c;
}

Number operator-(const Number& a, const Number& b)
{
    Number c(nullptr, max(a.baza, b.baza));

    int x = strtol(a.nr, NULL, a.baza);
    int y = strtol(b.nr, NULL, b.baza);

    int nr10 = x - y;

    char newNr[50];
    int i = 0;

    if (nr10 == 0)
    {
        strcpy(c.nr, "0");

        return c;
    }

    while (nr10 > 0)
    {
        int rest = nr10 % max(a.baza, b.baza);

        if (rest < 10)
        {
            newNr[i++] = rest + '0';
        }
        else
        {
            newNr[i++] = rest - 10 + 'A';
        }

        nr10 /= max(a.baza, b.baza);
    }

    newNr[i] = '\0';

    for (int k = 0, j = i - 1; k < j; k++, j--)
    {
        swap(newNr[k], newNr[j]);
    }

    c.nr = new char[strlen(newNr) + 1];
    strcpy(c.nr, newNr);

    return c;
}

void Number :: operator=(const Number& b)
{
    if (b.nr == nullptr)
    {
        delete[] this->nr;
        this->nr = new char[2];
        this->nr = nullptr;
        this->baza = 0;

    }
    else
    {   
		delete[] this->nr;
		this->nr = new char[strlen(b.nr) + 1];
		strcpy(this->nr, b.nr);

        this->baza = b.baza;
    }


}


void Number::operator=(const char* b)
{
    if (b == nullptr)
    {
        delete[] this->nr;
        this->nr = new char[2];
        strcpy(nr, "0");
        this->baza = 10;
       
    }
    else
    {
        delete[] this->nr;
        this->nr = new char[strlen(b) + 1];
        strcpy(this->nr, b);
        this->baza = DetectareBaza(b);
    }
    
}

void Number :: operator=(int b)
{
    sprintf(this->nr, "%d", b);
    this->baza = 10;

}

Number operator+=(Number& a, const Number& b)
{
    a = a + b;
    return a;
}

Number operator-=(Number& a, const Number& b)
{
    a = a - b;
    return a;
}

Number& Number::operator--() //prefix
{
    if (this->nr == nullptr || strlen(this->nr) == 0)
        return *this;

    for (int i = 1; i < strlen(this->nr); i++)
        this->nr[i - 1] = this->nr[i];
    this->nr[strlen(this->nr) - 1] = '\0';
    return *this;
}

Number Number::operator--(int) //postfix
{
    if (this->nr == nullptr || strlen(this->nr) == 0)
        return *this;

    this->nr[strlen(this->nr) - 1] = '\0';
    return *this;
}

char& Number::operator[](int index)
{
    return this->nr[index];
}

bool operator<(const Number& a, const Number& b)
{
    int x = strtol(a.nr, NULL, a.baza);
    int y = strtol(b.nr, NULL, b.baza);

    return x < y;
}

bool operator>(const Number& a, const Number& b)
{
    int x = strtol(a.nr, NULL, a.baza);
    int y = strtol(b.nr, NULL, b.baza);

    return x > y;
}

bool operator<=(const Number& a, const Number& b)
{
    int x = strtol(a.nr, NULL, a.baza);
    int y = strtol(b.nr, NULL, b.baza);

    return x <= y;
}

bool operator>=(const Number& a, const Number& b)
{
    int x = strtol(a.nr, NULL, a.baza);
    int y = strtol(b.nr, NULL, b.baza);

    return x >= y;
}

bool operator==(const Number& a, const Number& b)
{
    int x = strtol(a.nr, NULL, a.baza);
    int y = strtol(b.nr, NULL, b.baza);

    return x == y;
}

bool operator!=(const Number& a, const Number& b)
{
    int x = strtol(a.nr, NULL, a.baza);
    int y = strtol(b.nr, NULL, b.baza);

    return x != y;
}
