//
//  main.c
//  Worksheet_Test
//
//  Created by Kevin Lewis on 4/24/17.
//  Copyright © 2017 Kevin Lewis. All rights reserved.
//

#include <stdio.h>

struct dLink {
    TYPE value;
    struct dLink * next;
    struct dLink * prev;
};

struct linkedList {
    struct dLink * frontSentinel;
    struct dLink * backSentinel;
    int size;
};

/* the following functions were written in earlier lessons */
void linkedlistInit (struct linkedList *lst);
void linkedListFree (struct linkedList *lst);
void _addLink (struct linkedList * lst, struct dLink * lnk, TYPE e);
void _removeLink (struct linkedList * lst, struct dLink * lnk);

void linkedListAdd (struct linkedList * lst, TYPE e)
{ _addLink(lst, lst->frontSentinel->next, e); }

/* you must write the following */

int linkedListContains (struct linkedList *lst, TYPE e) {
    
    int containsBool = 0;
    
    for( struct dLink *itr = lst->frontSentinel->next; itr != lst->backSentinel; itr = itr->next){
        if(itr->value == e){
            containsBool = 1;
            break;
        }
    }
    return containsBool;
}








int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
