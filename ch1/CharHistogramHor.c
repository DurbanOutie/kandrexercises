#include <stdio.h>

#define COUNT_CAP 256

/* Histogram of all characters */
main(){
    int c;
    int counts[COUNT_CAP];

    for(int i = 0; i < COUNT_CAP; ++i){
        counts[i] = 0;
    }

    while((c = getchar()) != EOF){
        ++counts[c & 0xFF];
    }


    for(int i = 0; i < COUNT_CAP; ++i){
        if(counts[i] > 0){
            printf("%4d %X-%c characters: ", counts[i], i, i);
            for(int j = 0; j < counts[i]; ++j){
               putchar('#'); 
            }
            putchar('\n');
        }
    }
}
