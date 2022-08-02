#pragma once
#define stringMaxSize 255
#include <stdio.h>
#include <string.h>
int getString(char* retString);
void bubbleSortString(char* givenString);
int compChar(char val1, char val2);
void swapChars(char* givenString, int index1, int index2);

//Functions related to linked lists
struct link {
	char val;
	struct link* nextLink;
};

struct link* create_link(char givenVal);
void destroy_linked_list(struct link** headRef);
void printList(struct link* head);

void insertAtEndOfList(struct link* head, struct link* givenLink);
void insertAtEndOfList_ByValue(struct link* head, char givenVal);
void insertAtStartOfList(struct link* head, struct link* givenLink);
void insertAtStartOfList_ByValue(struct link* head, char givenVal);

//Takes input from stdin, which is the command console by default
	//Stores result in retString. Can hold spaces and special characters
int getString(char* retString) {
	fgets(retString, stringMaxSize, stdin);
	return 0;
}

//Compares two characters
	//Returns:
		// 1 if val1 > val2, 
		// -1 if val1 < val2, 
		// 0 if val1 == val2	
int compChar(char val1, char val2) {
	if (val1 < val2) {
		return -1;
	}else if (val1 > val2) {
		return 1;
	}else
		return 0;
}


//given a string and two indices, swaps their position
void swapChars(char* givenString, int index1, int index2) {
	char placeholder = givenString[index1];
	printf("Swapping %c and %c\n", givenString[index1], givenString[index2]);
	givenString[index1] = givenString[index2];
	givenString[index2] = placeholder;

}

//given a string, bubbleSorts the same string in alphabetical order (lowest-to-highest) and returns it in retString
	//Iterates through givenString, finding lowest value in string
	//Swaps the lowest value's placement in givenString with character at givenString[j]. j defaults to 0
	//Increments j, so next iteration ignores the previously-placed letter and finds the next lowest character instead
void bubbleSortString(char* givenString) {
	unsigned int givenStringLength = strlen(givenString);
	if (givenStringLength <= 1) {
		//already sorted
		return;
	}

	//Holds index of currently-lowest character
	unsigned int minCharIndex;
	
	//flag is set when characters are swapped
	int flag = 0;
	

	//string index is the point that comparisons start; everything before index is assumed to be sorted already
	unsigned int stringIndex = 0;

	//Go through each letter in givenString
	for (unsigned int j = 0; j < givenStringLength; j++) {
		//minCharIndex is reset to the jth place by default
		minCharIndex = j;

		//for k, from j to end-of-string, check if givenString[j] < givenString[k]
			//if so, change minCharIndex to index k
		for (unsigned int k = j; k < givenStringLength; k++) {
			printf("j: %d | k: %d | minCharIndex: %d | minCharValue: %c \n", j, k, minCharIndex, givenString[minCharIndex]);
			//compare the kth letter to the currently-held minimum-value character
			if (givenString[k] < givenString[minCharIndex]) {
				printf("| flag set to %d |", flag);
				flag = 1;
				minCharIndex = k;
			}
		}//end comparison loop
		//Outside of comparison loop, so minCharIndex holds index of lowest-valued character from j to end
			//swap that character's position with j
		if (flag == 1) {
			swapChars(givenString, minCharIndex, j);
			flag = 0;
		}
	}//end iteration for loop
}

void printList(struct link* head) {
	struct link* index = head;
	while (index) {
		fprintf_s(stdout, "%c", index->val);
		if (index->nextLink != NULL) {
			index = index->nextLink;
		}
		else {
			break;
		}
	}
	fprintf_s(stdout, "\n");
}

void insertAtEndOfList(struct link* head, struct link* givenLink) {
	struct link* index = head;

	while (index->nextLink != NULL) {
		index = index->nextLink;
	}
	//now index->nextLink is NULL, so placing new link there
	index->nextLink = givenLink;
}

void insertAtEndOfList_ByValue(struct link* head, char givenVal) {
	insertAtEndOfList(head, create_link(givenVal));
}

//automates link creation
struct link* create_link(char givenVal) {
	//allocate memory for new node
	struct link* newNode = (struct link*)malloc(sizeof(struct link));
	if (newNode) {
		newNode->val = givenVal;
		newNode->nextLink = NULL;
	}

	return newNode;
}


void destroy_linked_list(struct link** headRef) {
	struct link* index = *headRef;
	struct link* nextIndexHolder;
	//go through link, freeing 
	while(index != NULL){
		//save the next node's address
		nextIndexHolder = index->nextLink;
		//delete current node
		free(index);
		//set current node to the saved node's address
		index = nextIndexHolder;
	}
	//then manually set head node to NULL
	*headRef = NULL;
}