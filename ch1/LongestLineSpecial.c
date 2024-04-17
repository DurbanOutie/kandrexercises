#include <stdio.h>

#define MAX_LINE 1000   /* maximum input line length */

int max;                /* maximum length seen so far */
char line[MAX_LINE];    /* current input line */
char longest[MAX_LINE]; /* longest line saved here */

int getLine(void);
void copy(void);

/* print the longest input line */
main(){
    int len;                /* current line length */
    extern int max;
    extern char longest[];

    max = 0;
    while((len = getLine()) > 0)
        if(len > max){
            max = len;
            copy();
        }
    if(max > 0) /* there was a line */
        printf("%s", longest);
    return 0;
}

/* getLine: specialized version;read a line into s, return length */
int getLine(void){

    int c, i;
    extern char line[];

    for(i = 0; i < MAX_LINE-1 
            && (c = getchar()) != EOF 
            && c != '\n'; ++i)
        line[i] = c;
    if(c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: specialized version; copy 'from' into 'to'; assume 'to' is big enough */
void copy(void){
    int i;
    extern char line[], longest[];
    i = 0;
    while((longest[i] = line[i]) != '\0')
        ++i;
}




