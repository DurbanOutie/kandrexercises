#include <stdio.h>

/* program to detab input; 
 * replace all characters that move along to the next tab spot 
 * with blanks
 *
 * Exercise 1-20. Write a program detab that 
 * replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop. 
 *
 * Assume a fixed set of tab stops, say every n columns.
 * Should n be a variable or a symbolic parameter?
*/

#define TABSTOP 4

main(){
    int c, i;
    int count = 0;

    while((c = getchar()) != EOF){
        if(c == '\t'){
            for(i = 0; i < TABSTOP - count; ++i){
                putchar('#');
            }
            count = 0;
        }else{
            putchar(c);
            ++count;
            if(c =='\n' || count >= TABSTOP)
                count = 0;
        }
    }
    return 0;
}


