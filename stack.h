/**
 * File: stack.h
 * @author: Simon Maurer (modifications)
 * @author: Robert I. Pitts <rip@cs.bu.edu> (initial file)
 *
 * This is the interface for a stack of characters.
 * */

#ifndef _STACK_H
#define _STACK_H

#include <stdlib.h> // size_t

typedef struct {
  void **contents;  // content of the stack
  int top;          // array index of the element at the top of the stack
  int maxSize;      // size of the stack
} stack_t;

/**
 * Create a new stack
 *
 * @param size_t: size of the stack
 * @return stack_t* pointer to the stack
 * */
stack_t* stack_create( size_t );

/**
 * Releas all allocated memory and initialize stack
 *
 * @param stack_t*: pointer to the stack
 * */
void stack_release( stack_t* );

/**
 * Push an element on the stack
 *
 * @param stack_t*: pointer to the stack
 * @param void*:    pointer to the element that will be pushed on the stack
 * @param size_t:   size of the elemnet to be pushed on the stack
 * */
void stack_push( stack_t*, void*, size_t );

/**
 * Pop an element from the stack
 *
 * @param stack_t*: pointer to the stack
 * @return void*:   pointer to the element popped from the stack
 * */
void* stack_pop( stack_t* );

#endif  /* not defined _STACK_H */
