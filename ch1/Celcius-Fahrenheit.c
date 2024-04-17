#include <stdio.h>

main(){
    float fahr, celsius;
    float lower ,upper, step;

    lower =     0;
    upper =   200;
    step  =    20;

    fahr = lower;
    printf("%s\t%10s\n", "Celsius", "Fahr\n");
    while(celsius <= upper){
        fahr= ((9.0/5.0)*celsius)+32.0; 

        printf("%3.0f\t%9.1f\n", celsius, fahr);
        celsius = celsius + step;

    }

}
