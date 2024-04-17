#include <stdio.h>

/* split line with words on new line */
main(){
    int c;
    int prevc = 0;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\n' || c == '\t'){
            if(prevc != ' ' && prevc != '\n' && prevc != '\t'){
                putchar('\n');
            }
        }else{
            putchar(c);
        }
        prevc = c;
    }
}

