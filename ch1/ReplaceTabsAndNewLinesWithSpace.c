#include <stdio.h>

/* replace Tabs and NewLines with space */
main(){

    int c;

    while((c = getchar()) != EOF){
        if(c == '\t')
            c = ' ';
        if(c == '\n')
            c = ' ';
        putchar(c);
    } 
}
