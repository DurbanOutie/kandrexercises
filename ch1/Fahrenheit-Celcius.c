#include <stdio.h>

/* print Fahrenheit-Celcius table
 * for fahr = 0, 20, ..., 300 */

main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower =   0; /* lower limit if temperature scale */
    upper = 300; /* upper limit */
    step  =  20; /* step size */

    fahr = lower;

    printf("%s\t%10s", "Fahr", "Celsius\n");
    while (fahr <= upper) {
        celsius = (5.0/9.0f) * (fahr-32.0);

        printf("%3.0f\t%9.1f\n", fahr, celsius);
        fahr = fahr + step;

    }
}
