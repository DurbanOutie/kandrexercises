/* Exercise 2-1. 
 * Write a program to determine the ranges 
 * of char, short, int, and long variables, 
 * both signed and unsigned, 
 * by printing appropriate values from 
 * standard headers and by direct computation. 
 * Harder if you compute them: 
 * determine the ranges of the various 
 * floating-point types.
 */

#include <stdio.h>
#include <limits.h>

int main(){
    printf("char\n----\nMin: %d\nMax: %d\n----\n", SCHAR_MIN, SCHAR_MAX);
    printf("short\n----\nMin: %d\nMax: %d\n----\n", SHRT_MIN, SHRT_MAX);
    printf("u-short\n----\nMin: %d\nMax: %d\n----\n", 0, USHRT_MAX);
    printf("int\n----\nMin: %d\nMax: %d\n----\n", INT_MIN, INT_MAX);
    printf("u-int\n----\nMin: %d\nMax: %u\n----\n", 0, UINT_MAX);
    printf("long\n----\nMin: %ld\nMax: %ld\n----\n", LONG_MIN, LONG_MAX);
    printf("u-long\n----\nMin: %d\nMax: %lu\n----\n", 0, ULONG_MAX);
    return 0;
}



