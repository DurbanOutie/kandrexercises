#include <stdio.h>

#define MAX_CAP 1000            /* max cap for a line */

int reverse(char s[], int max);

/* read input and reverse 1 line at a time */
main(){
    int len;
    char line[MAX_CAP];

    while((len = reverse(line, MAX_CAP)) > 0)
            printf("%d - %s", len, line); 
    return 0;
}

/* reverse: reverse a string and return the length */
int reverse(char s[], int max){
    int c, i, j;

    for(i = 0; i < max -1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    for(j = 0; j < i/2; ++j){
        int tmp = s[i - 1 - j];
        s[i - 1 - j] = s[j];
        s[j] = tmp;
    }

    if(c == '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}
