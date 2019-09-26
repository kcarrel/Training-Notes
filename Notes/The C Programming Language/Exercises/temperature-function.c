#include <stdio.h>

int celsius(int fahr);
/*print Fahrenheit-Celsius table for fahr = 0, 20, ...., 300 */
main()
{
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%d\t%d\n", fahr, celsius(fahr));
    return 0;

}

int celsius(int fahr)
{
    int value;
    value = 5 * (fahr-32) / 9;
    return value;
}