#include <iostream>
#include "Canvas.h"
int main()
{
    Canvas c(20, 10);

    c.DrawLine(2, 3, 20, 10, '*');
    c.Print();

    
	
	return 0;

}