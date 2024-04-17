/* Exercise 1-22. Write a program to ''fold'' long input lines into 
 * two or more shorter lines after the last non-blank character that 
 * occurs before the n-th column of input. Make sure your program 
 * does something intelligent with very long lines, 
 * and if there are no blanks or tabs before the specified column.
 */

/************************************************************************/

#include <stdio.h>

#define MAXLINE 1000    /* The max a line can have between newlines */
#define MAX_COL 50       /* Max width of the view port, lines will
                          Wrap here
                         */ 
int getLine(char line[], int lim);
void copyPos(char to[], char from[], int start, int end);


int main(){

    char line[MAXLINE];
    char out[MAXLINE];
    int len;
    int i, k;

    int start, end;


    while((len = getLine(line, MAXLINE)) > 0){
        start = 0;
        end = start + MAX_COL;

        if (end > len)
            end = len;
        
        while(start < end && end <= len){

            k = end;
            if(len - start > MAX_COL)
                for(i = start; i < k; ++i)
                    if(line[i] == ' ')
                        end = i+1;

            copyPos(out, line, start, end);
            printf("%s", out);

            start = end;
            if(start + MAX_COL < len){
                end = start + MAX_COL;
            }else{
                end = len;
            }
        }
    }

    return 0;
}

/* getLine: read a line into line, return length */
int getLine(char line[], int lim){
    int c, i;
    for(i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if(c =='\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}
   
void copyPos(char to[], char from[], int start, int end){
    int i, j = 0;
    for(i = start; i < end && (to[j] = from[i]) != '\0'; ++i, ++j)
        ;
    if(i == end)
        to[j++] = '\n';
    to[j] = '\0';
}
