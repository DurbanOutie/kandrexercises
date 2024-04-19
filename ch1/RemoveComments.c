
#include <stdio.h>

/* Exercise 1-23. Write a program to remove all comments 
 * from a C program. Don't forget to handle quoted strings 
 * and character constants properly. 
 *
 * C comments don't nest.
 */


#define OUT_COMMENT 0
#define IN_COMMENT  1
#define IN_BLOCK    2
#define IN_LINE     3



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
                if(c == '*'){ //ssss
                    state = IN_BLOCK;
                }else if(c == '/'){
                    state = IN_LINE;
                }else{
                    putchar(prevC);
                    putchar(c);
                    maybe = OUT_COMMENT;
                }
            }else if(maybe == OUT_COMMENT){
                if(c == '/'){ // First Comment Start Char
                    maybe = IN_COMMENT;
                }else{
                    putchar(c);
                }
            }
        }else if(state == IN_BLOCK){
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

        }else if(state == IN_LINE){






            if(c == '\n'){
                state = OUT_COMMENT;
                maybe = OUT_COMMENT;
                putchar(c);
            }else{

            }
        }

        prevC = c;

    }
}
