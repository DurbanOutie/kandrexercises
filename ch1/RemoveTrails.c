#include <stdio.h>
#define MAX_CAP 1000                /* max cap of line */

int getLine(char line[], int max);

/* remove trailing blanks and tabs and delete blank lines */
main(){
    int len;                    /* length of a line */
    char line[MAX_CAP];         /* array of characters making up line */

    printf("Not Working\n");

    while((len = getLine(line, MAX_CAP)) > 0)
        if(len > 1)
        printf("%d - %s", len, line);

    return 0;
}

/* getLine: puts characters into line until newline or EOF; returns length */
int getLine(char line[], int max){
    int c, i, j;
    for(i = 0; i < max -1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    
    if(c == '\n'){
        int k = i;
        for(j = k; j > 0; --j)
            if(line[j] == ' ' || line[j] == '\t'){
                line[k--] == '\0';
                --i;
            }
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}    

