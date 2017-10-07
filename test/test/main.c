//
//  main.c
//  test
//
//  Created by Kevin Lewis on 4/15/17.
//  Copyright © 2017 Kevin Lewis. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>

struct link {
    TYPE value;
    struct link * next;
};

struct linkedListStack {
    struct link *firstLink;
}

void linkedListStackInit (struct linkedListStack * s)
{ s->firstLink = 0; }

void linkedListStackFree (struct linkedListStack *s)
{ while (! linkedListStackIsEmpty(s)) linkedListStackPop(s); }

void linkedListStackPush (struct linkedListStack *s, TYPE d) {
    struct link * newLink = (struct link *) malloc(sizeof(struct link));
    assert (newLink != 0);
    
    /* Fix me */
    
    newLink->next = s->firstLink;
    s->firstLink = newLink;
    
    
}


int main(int argc, const char * argv[]) {
    
    /*Print the new word*/
    printf("Hello World");
    
    return 0;
}
