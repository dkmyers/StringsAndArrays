#include <stdio.h>
#include "StringsAndArrays.h"


int main()
{
    char firstString[stringMaxSize];
    fprintf_s(stdout, "Hello world!");
    getString(firstString);
    fprintf_s(stdout, firstString);
    bubbleSortString(firstString);
    fprintf_s(stdout, firstString);
    return 0;
}