#include <stdio.h>

/* Count blank " ", Tabs "\t" and newlines "\n" */

main(){
    int c, blank, tab, newLine;
    c = blank = tab = newLine = 0;

    while((c = getchar()) !=EOF){
        if(c == ' ')
            ++blank;
        if(c == '\t')
            ++tab;
        if(c == '\n')
            ++newLine;
    }
    printf("blank:%d\ntab:%d\nnewline:%d\n", blank, tab, newLine);
    
}
