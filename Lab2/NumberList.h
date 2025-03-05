#pragma once
class NumberList
{
    int numbers[10];
    int count;
    const char* nume;
    int mate, english, history, medie;
public:
    void Init();          // count will be 0
    bool Add(int x);      // adds X to the numbers list and increase the data member count.
                          // if count is bigger or equal to 10, the function will return false
    void Sort();          // will sort the numbers vector
    void Print();         // will print the current vector

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


