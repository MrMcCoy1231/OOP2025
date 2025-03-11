#pragma once
class Student
{
    const char* nume;
    int mate, english, history, medie;

public:
    void setname(const char* name);
    const char* getname();

    void setmath(int x);
    int getmath();

    void setenglish(int x);
    int getenglish();

    void sethistory(int x);
    int gethistory();

    double getmedie();
};

