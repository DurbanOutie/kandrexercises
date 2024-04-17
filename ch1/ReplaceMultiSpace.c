#include <stdio.h>

/* Checks if next character and character before it are both space, if
 * true, then dont print the next character */
main(){
    int c;
    int prevC = 0;
    while((c = getchar()) != EOF){
        if(prevC == ' '){
            if(c != ' ')
                putchar(c);
        }else{
            putchar(c);
        }
        prevC = c;
    }
}
