#include <stdio.h>

/* Exercise 1-23. Write a program to remove all comments 
 * from a C program. Don't forget to handle quoted strings 
 * and character constants properly. 
 */
// C comments don't nest.
 


#define OUT_COMMENT 0
#define IN_COMMENT  1
#define IN_BLOCK    2
#define IN_LINE     3

int main(){

    int c, prevC;
    int state, maybe;

    state = OUT_COMMENT;
    maybe = OUT_COMMENT;
    prevC = 0;

    while((c = getchar()) != EOF){
        if(state == OUT_COMMENT){
            if(maybe == IN_COMMENT){
                if(c == '*'){
                    state = IN_BLOCK;
                }else if(c == '/'){
                    state = IN_LINE;
                }else{
                    putchar(prevC);
                    putchar(c);
                    maybe = OUT_COMMENT;
                }
            }else if(maybe == OUT_COMMENT){
                if(c == '/'){
                    maybe = IN_COMMENT;
                }else{
                    putchar(c);
                }
            }
        }else if(state == IN_BLOCK){
            if(maybe == OUT_COMMENT){
                if(c != '/'){
                    maybe = IN_COMMENT;
                }else{
                    state = OUT_COMMENT;
                }
            }else if(maybe == IN_COMMENT){
                if(c == '*'){
                    maybe = OUT_COMMENT;
                }else{
                }
            }
        }else if(state == IN_LINE){
            if(c == '\n'){
                state = OUT_COMMENT;
                maybe = OUT_COMMENT;
                putchar(c);
            }
        }
        prevC = c;
    }
}
