/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
    
    int isBal = 0; // holds the "state" Balanced vs Unbalanced
    
    DynArr *holder; // Will hold the parenthesis.
    
    holder = newDynArr(8); // We'll start out with size 8.
    
    char charIn = nextChar(s);
    
    // Scan through the string to get the (), {}, or [];
    
    while (charIn != '\0'){
        
        if(charIn == '(' || charIn == '{' || charIn == '['){
            pushDynArr(holder, charIn);
        }
        
        if(charIn == ')' || charIn == '}' || charIn == ']'){
            // check if the dynamic array is empty (will be unbalanced then)
            if(isEmptyDynArr(holder)){
                return isBal;
            }
            
            // Check if the character matches the top of the stack (closed parenthesis)
            else if(charIn == topDynArr(holder)) {
                
                // If the value matches, then pop the stack.
                popDynArr(holder);
            }
            
            // If the values don't match, the string is not balanced.
            else{
                return isBal;
            }
        }
        
        // Move on to the next character in the string.
        charIn = nextChar(s);
        
    }
    
    // Check if the are any remaining (, {, or [ in the holder array
    // if so, the array is not balanced.
    
    if (isEmptyDynArr(holder)){
        isBal = 1;
    }
    
	return isBal;
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

