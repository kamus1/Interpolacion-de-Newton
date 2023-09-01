#include <stdio.h>
#include <math.h>
#include "zero.h"

//Benjamin Camus 
//202173072-9

//función en la que se guarda la función que queremos interpolar
double f(double w) {
    return w * exp(w) - 6;
}

int main() {
    //llamamos a la función entregándole los valores iniciales
    double w = zero(f, 1.0, 2.0, 3.0, 1e-5);
    printf("Valor de w: %.5lf\n", w);
    return 0;
}
