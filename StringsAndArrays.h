#pragma once
#define stringMaxSize 255
#include <stdio.h>
#include <string.h>
int getString(char* retString);
int bubbleSortString(char* givenString, char* retString);



int getString(char* retString) {
	fgets(retString, stringMaxSize, stdin);
	return 0;
}

//given a string, resorts the same string in alphabetical order and returns it
int bubbleSortString(char* givenString, char* retString) {
	int givenStringLength = strlen(givenString);
	
	for (int j = 0; j < givenStringLength; j++) {

	}
	return givenStringLength;
}