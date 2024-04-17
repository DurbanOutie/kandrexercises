#include <stdio.h>

#define LINE_CAP 1000
#define MIN_LINE 80

int getLine(char line[], int lim);

/* print out all lines that are greater than the MIN_LINE */
main(){

    int len;
    char line[LINE_CAP];

    while((len = getLine(line, LINE_CAP)) > 0){
        if(len > MIN_LINE)
            printf("%d - %s", len, line);
    }
    return 0;
}

/* getLine: read a line into s, return length */
int getLine(char s[], int lim){
    int c, i;

    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
