#include <stdio.h>
#include <math.h>
int main()
{
    // R：100kΩ、51kΩ、10 kΩ、5.1 kΩ、2 kΩ、1 kΩ、200Ω/2W、20Ω/5W、100Ω/2W
    // C：2uF、1uF、0.47uF
    int i1;
    int i2;
    double R[] = {100e3, 51e3, 10e3, 5.1e3, 2e3, 1e3, 200.0, 20.0, 100.0};
    double C[] = {2e-6, 1e-6, 0.47e-6};
    double chosen = 0.0, Qmax = 0;
    for (i1 = 0; i1 < 3; i1++)
    {
        for (i2 = 0; i2 < 9; i2++)
        {
            double Q = ((sqrt(10.0) / (double)50) * (sqrt(1 / C[i1]))) / (R[i2] + (double)8);
            if (Q > Qmax && Q < 3.0)
            {
                Qmax = Q;
                chosen = i2;
            }
        }
        if (Qmax > 1)
            printf("the chosen is %f", chosen);
        else
            printf("    NO   ");
        Qmax = 0;
    }
    return 0;
}