#include <stdio.h>

/* Histogram of word lengths horizantally displayed */
main(){
    int c, i, j, count;
    int counts[20];

    count = 0;

    for(i = 0; i < 20; ++i)
        counts[i] = 0;
    

    while((c = getchar()) != EOF){
        if(c != ' ' && c != '\n' && c!= '\t'){
            ++count;
        }else{
            if(count > 0){
                ++counts[count];
                count = 0;
            }
        }

    }

    for(i = 0; i < 20; ++i){
        printf("%2d %2d Letter Words: ", counts[i], i);
        for(j = 0; j < counts[i]; ++j)
            putchar('#');
        putchar('\n');
    }


}
