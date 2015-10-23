/**
 * File: stack.c
 * @author: Simon Maurer (modifications)
 * @author: Robert I. Pitts <rip@cs.bu.edu> (initial file)
 *
 * This is an array implementation of a character stack.
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"

/* create a new stack */
stack_t* stack_create( size_t size ) {
    size_t i;
    stack_t *stack = NULL;

    if( size < 1 ) return NULL;

    /* Allocate the stack itself. */
    if( ( stack = malloc( sizeof( stack_t ) ) ) == NULL ) {
        return NULL;
    }

    /* Allocate pointers to the head nodes. */
    if( ( stack->contents = malloc( sizeof( void* ) * size ) ) == NULL ) {
        return NULL;
    }
    for( i = 0; i < size; i++ ) {
        stack->contents[i] = NULL;
    }

    stack->maxSize = size;
    stack->top = -1;  /* I.e., empty */

    return stack;
}

/* releas all allocated memory and initialize stack */
void stack_release( stack_t* stack )
{
    /* Get rid of array. */
    free(stack->contents);

    stack->contents = NULL;
    stack->maxSize = 0;
    stack->top = -1;  /* I.e., empty */
}

/* push an element on the stack */
void stack_push( stack_t* stack, void* element, size_t size )
{
    void* thisItem;

    if ( stack->top >= stack->maxSize - 1 ) {
        fprintf( stderr, "Can't push element on stack: stack is full.\n" );
        exit( 1 );  /* Exit, returning error code. */
    }
    if( ( thisItem = memcpy( malloc( size ), element, size ) ) == NULL ) {
        fprintf( stderr, "Can't push element no memory available.\n" );
        exit( 1 );  /* Exit, returning error code. */
    }

    /* Put information in array; update top. */
    stack->contents[ ++stack->top ] = thisItem;
}

/* pop an element from the stack */
void* stack_pop( stack_t* stack )
{
    if ( stack->top < 0 ) {
        fprintf( stderr, "Can't pop element from stack: stack is empty.\n" );
        exit( 1 );  /* Exit, returning error code. */
    }

    return stack->contents[ stack->top-- ];
}
