/* Exercise 2-2. Write a loop equivalent to the for loop 
 * in getline without using && or ||.
 */

#include <stdio.h>

#define MAX_LEN 1024

int getLine(char line[], int max);

int main(){
    int len;
    char line[MAX_LEN];

    while((len = getLine(line, MAX_LEN)) > 0){
        printf("%s", line);
    }
    return 0;
}

int getLine(char line[], int max){
    int c, i;

    //for(i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n';++i){
    for(i = 0; i < max - 1;++i){
        if((c = getchar()) != EOF)
            if(c != '\n') 
                line[i] = c;
            else
                break;
        else
            break;
    }
    if(c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;

}

