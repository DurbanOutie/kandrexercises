/* Exercise 1-24. Write a program to check a C program 
 * for rudimentary syntax errors like unmatched parentheses, 
 * brackets and braces. 
 * Don't forget about quotes, both single and double, 
 * escape sequences, and comments. 
 *
 * (This program is hard if you do it in full generality.)
 */

#define OUT         0
#define IN_BLOCK_C  1
#define IN_LINE_C   2
#define IN_QUOTE    3
#define IN_D_QUOTE  4

#include <stdio.h>


int main(){
    int c, temp;
    int brace, bracket;
    int state;

    brace = 0;
    bracket = 0;

    state = OUT;

    while((c = getchar()) != EOF){

        if(state == OUT){
            // Check for ) and (
            if(c == '('){
                ++bracket;
            }
            if(c == ')'){
                if(bracket == 0){
                    printf("Missing (");
                    return 1;
                }
                --bracket;
            }
            // Check for } and {
            if(c == '{'){
                ++brace;
            }
            if(c == '}'){
                if(brace == 0){
                    printf("Missing {");
                    return 1;
                }
                --brace;
            }
            // Check for comments, quotes and double quotes.
            if(c == '/'){
                temp = c;
                c = getchar();
                if(c == '*'){
                    state = IN_BLOCK_C;
                }else if(c == '/'){
                    state = IN_LINE_C;
                }
            }else if(c == '\''){
                    state = IN_QUOTE;
            }else if(c == '"'){
                    state = IN_D_QUOTE;
            }

        }else if(state == IN_BLOCK_C){
            if(c == '*'){
                temp = c;
                c = getchar();
                if(c == '/'){
                    state = OUT;
                }
            }
        }else if(state == IN_LINE_C){
            if(c == '\n'){
                state = OUT;
            }
        }else if(state == IN_QUOTE){
            if(c == '\\'){
                temp = c;
                c = getchar();
                if(c == '\''){
                }
            }else if(c == '\''){
                state = OUT;
            }
        }else if(state == IN_D_QUOTE){
            if(c == '"'){
                state = OUT;
            }
        }
            
    }

    if(bracket > 0){
        printf("Missing )");
        return 1;
    }
    if(bracket < 0){
        printf("Missing (");
        return 1;
    }

    if(brace > 0){
        printf("Missing }");
        return 1;
    }
    if(brace < 0){
        printf("Missing {");
        return 1;
    }

    return 0;
}
