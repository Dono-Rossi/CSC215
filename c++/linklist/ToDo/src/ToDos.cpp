#include <iostream>
#include <string>
#include "ToDos.h"
using namespace std;

ToDo::ToDo()
{
    title = "I'm a ToDo";    
}

string ToDo::to_string() const
{
    return title; 
}
