#include <stdio.h>
#include "StringsAndArrays.h"


int main()
{
    char firstString[stringMaxSize];
    fprintf_s(stdout, "Hello world!");
    getString(firstString);
    fprintf_s(stdout, "%s", firstString);
    fprintf_s(stdout, "%d", bubbleSortString(firstString, firstString));
    return 0;
}