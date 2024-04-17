#include <stdio.h>

/* progra to entab input;
 * replace all characters that are 'tab eligible' with a tab
 *
 * Exercise 1-21. Write a program entab that replaces strings 
 * of blanks by the minimum number of tabs and blanks to 
 * achieve the same spacing. Use the same tab stops as for detab. 
 * 
 * When either a tab or a single blank would suffice to reach 
 * a tab stop, which should be given preference?
*/

#define TABSTOP 4

main(){

    int c, i, pos;
    char queue[TABSTOP];

    pos = 0;

    while((c = getchar()) != EOF){
        if(c ==' '){
            queue[pos++] = ' ';

            if(pos > 3){
                putchar('\t');
                pos = 0;
            }
        }else{
            if(pos > 0){
                for(i = 0; i < pos; ++i){
                    putchar(queue[i]);
                }
                pos = 0;
            }
            putchar(c);
        }
    }
    return 0;
}
