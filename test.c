/**
 * File: test.c
 * @author: Simon Maurer (modifications)
 * @author: Robert I. Pitts <rip@cs.bu.edu> (initial file)
 *
 * This program tests the "stack of characters" module.
 * */

#include <stdio.h>
#include "stack.h"

int main( void )
{
    typedef struct {
        char *name;
        int scope;
    } myEntry;

    myEntry e;
    myEntry *res;

    stack_t *stack = stack_create( 1024 );

    e.name = "hanuele";
    e.scope = 5;
    stack_push( stack, &e, sizeof(e) );
    res = (myEntry*)stack_pop( stack );
    printf( "%s, %d\n", res->name, res->scope );

    e.name = "wotuele";
    e.scope = 4;
    stack_push( stack, &e, sizeof(e) );
    e.name = "hetuele";
    e.scope = 3;
    stack_push( stack, &e, sizeof(e) );
    res = (myEntry*)stack_pop( stack );
    printf( "%s, %d\n", res->name, res->scope );
    res = (myEntry*)stack_pop( stack );
    printf( "%s, %d\n", res->name, res->scope );

    stack_release( stack );

    return 0;
}
