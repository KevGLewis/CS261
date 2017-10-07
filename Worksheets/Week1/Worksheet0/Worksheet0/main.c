//
//  main.c
//  Worksheet0
//
//  Created by Kevin Lewis on 4/12/17.
//  Copyright © 2017 Kevin Lewis. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;
    
    /*Set b to half its original value*/
    *b = *b / 2;
    
    /*Assign a+b to c*/
    c = *a + *b;
    
    /*Return c*/
    return c;
}

int main(int argc, const char * argv[]) {
    
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;
    
    /*Print the values of x, y and z*/
    printf("x = %d", x);
    printf("y = %d", y);
    printf("z = %d", z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int c = foo(&x, &y, z);
    
    /*Print the value returned by foo*/
    printf("foo = %d", c);
    
    /*Print the values of x, y and z again*/
    printf("x (post-foo) = %d", x);
    printf("y (post-foo) = %d", y);
    printf("z (post-foo) = %d", z);
    
    /*Is the return value different than the value of z?  Why?*/
    /*Yes, because in integer will drop off the decimal places*/
    return 0;

}
