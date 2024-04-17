#include <stdio.h>

int power(int m, int n);

/* test power function */
main(){
    int i;

    for(i = 0; i < 10; ++i)
        printf("%d %3d %6d\n", i, power(2, i), power(-3, i));
    return 0;
}

/* power: Raise base to n-th power; n >= 0 */
int power(int base, int n){
    int i, p;
    p = 1;
    for(i = 1; i <=n; ++i)
        p = p * base;
    return p;
}

/* power: Raise base to n-th power; n >= 0; version 2
 *
 * n is passed by value, and so can be mutated without
 * affecting the original value when this function was
 * called.
 *
 */

int power(int base, int n){
    int p;
    for(p = 1; n > 0; --n)
        p = p*base;
    return p;
}


