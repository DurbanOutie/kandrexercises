
#include <stdio.h>

/* Exercise 1-23. Write a program to remove all comments 
 * from a C program. Don't forget to handle quoted strings 
 * and character constants properly. 
 *
 * C comments don't nest.
 */


#define OUT_COMMENT 0
#define IN_COMMENT  1



/*
 * This is also a comment
 */


int main(){

    int c, prevC;
    int state, maybe;

    /*
     * This is also a comment
     */

    state = OUT_COMMENT;
    maybe = OUT_COMMENT;
    prevC = 0;

    while((c = getchar()) != EOF){

        /*
         * This is also a comment
         */

        if(state == OUT_COMMENT){
            if(maybe == IN_COMMENT){
                if(c != '*'){ // Second Comment Start Char
                    putchar(prevC);
                    putchar(c);
                    maybe = OUT_COMMENT;
                }else{
                    state = IN_COMMENT;
                }
            }else if(maybe == OUT_COMMENT){
                if(c == '/'){ // First Comment Start Char
                    maybe = IN_COMMENT;
                }else{
                    putchar(c);
                }
            }
        }else if(state == IN_COMMENT){
            if(maybe == OUT_COMMENT){
                if(c != '/'){// Second Comment End Char
                    //putchar(prevC);
                    //putchat(c);
                    maybe = IN_COMMENT;
                }else{
                    state = OUT_COMMENT;
                }
            }else if(maybe == IN_COMMENT){
                if(c == '*'){ // First Comment End Char
                    maybe = OUT_COMMENT;
                }else{
                    //putchar(c);
                }
            }

        }

        prevC = c;

    }
}
