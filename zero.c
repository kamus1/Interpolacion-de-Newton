/**
 * @file:  zero.c
 * @brief: Skeleton for zero finding
 */

#include "zero.h"
#include <math.h>
#include <stdio.h>
#include<unistd.h>
/*
Implementa el método de interpolación de newton
    Parameters
    ----------
    f : function
        Función de w de lambert
    x0 : float
        El primer punto inicial.
    x1 : float
        El segundo punto inicial.
    x2 : float
        El tercer punto inicial.
    err : float
        Error o tolerancia para la aproximación de la solución.

*/
double zero(double f(double), double x0, double x1, double x2,double err)
{
    //variables correspondientes a los valores de evaluar los puntos iniciales en f()
    double y0, y1, y2;

    //coeficientes del polinomio
    double a0, a1, a_intermedio, a2;

    //valor del xn, el valor que va entregando en polinomio de newton
    double xn; 

    //variable para calcular la diferencias entre los valores y comparar con el error
    double diferencia;
    do {
        //Evaluar valores de x en la función
        y0 = f(x0);
        y1 = f(x1);
        y2 = f(x2);

        //con los yn calcular los coeficientes del polinomio
        a0 = x0;
        a1 = (x1-x0)/(y1-y0);
        a_intermedio = (x2-x1)/(y2-y1);
        a2 = (a_intermedio- a1)/(y2-y0);

        //Usar estos valores para sacar el polinomio y calcular su valor donde y es 0
        xn = a0 + a1*(0-y0) + a2*(0-y0)*(0-y1);

        diferencia = fabs(xn - x0);
        if ( diferencia <= err) { 
            break; // Detiene el bucle si la diferencia es menor que la tolerancia o error
        }

        //Rotar los valores        
        x2 = x1;
        x1 = x0;
        x0 = xn;

        //para ir observando la precisión del método en cada iteración
        //printf("Valor: %.12lf\n", xn);
        //sleep(1);
    } while (1);
 
    return x0;
}
