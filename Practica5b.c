/*Programa que resuelve ecuaciones diferenciales ordinarias de primer orden por el metodo de Euler y Euler mejorado*/
/*Programa elaborado por Reyes Udasco Rachelle Nerie*/
 #include <stdio.h>
 #include <math.h>

int menu_funcion();
double opcion_funcion(int num, double x, double y);
void limites(double *x0, double *x1, double *y0, double *h);
void euler();
void euler_simple(double x0, double x1, double y0, double h, int funcion);
void eulermejorado();
void euler_mejorado(double x0, double x1, double y0, double h, int funcion);
void runge ();
void runge_kutta(double x0, double x1, double y0, double h, int funcion);

int main()
{
    int metodo;
    do{
        printf("\n\nIngrese el n\xA3mero de m\x82todo que desea utilizar: ");
        printf("\n [1] EULER ");
        printf("\n [2] EULER MEJORADO");
        printf("\n [3] RUNGE KUTTA 4to orden ");
        printf("\n [0] SALIR\n");
        scanf("%d",&metodo);
        getchar();

        switch(metodo) {
        case 1:
           euler();
        break;
        case 2:
           eulermejorado();
        break;
        case 3:
           runge();
        break;
        default:
            printf("\nIngrese otro n\xA3mero:\n");
            break;
        }
    }while(metodo>0);

    return 0;
}

int menu_funcion() {
    int funcion;

    printf("\n Elige la funci\xA2n que deseas utilizar ");
    printf("\n [1] -xy^2 \n");
    printf("\n [2] x+y \n");
    printf("\n [3] 1 -x +4y \n");
    printf("\n [4] 1/2y \n");
    printf("\n [5] y - x^2 +1\n");
    printf("\n [6] x+y^2 \n");
    printf("\n [7] 2xy \n");
    printf("\n [8] 2+x-y^2 \n");
    scanf("%d",&funcion);

    return funcion;
}


void limites(double *x0, double *x1, double *y0, double *h) {
        printf("\n Ingrese los l\xA1mites de x; ");
        printf("\n x0: ");
        scanf("%lf",x0);
        printf("\n x1: ");
        scanf("%lf",x1);
        printf("\n Ingrese el valor del y0: ");
        scanf("%lf",y0);
        printf("\n Ingrese el tama%co de paso: ",164);
        scanf("%lf",h);
}

double opcion_funcion(int num, double x, double y) {
    double resultado;

   switch(num) {
    case 1:
           resultado = -x*pow(y,2);
        break;
    case 2:
            resultado = x+y;
        break;
    case 3:
            resultado = 1 -x +4*y;
        break;
    case 4:
            resultado = (1/2)*y;
        break;
    case 5:
            resultado = y - pow(x,2) +1;
        break;
    case 6:
            resultado = x+ pow(y,2);
        break;
    case 7:
            resultado = 2*x*y;
        break;
    case 8:
            resultado = 2+x-pow(y,2);
        break;
    default:
            resultado = 0;
        break;
   }
   return resultado;
}

void imprimir_funcion(int funcion)
{
    switch(funcion) {
    case 1:
        printf("\n -xy^2\n");
        break;
    case 2:
         printf("\n x+y\n");
        break;
    case 3:
        printf("\n 1-x+4y \n");
        break;
    case 4:
        printf("\n (1/2)y\n");
        break;
    case 5:
        printf("\n y-x^2+1 \n");
        break;
    case 6:
        printf("\n x+y^2\n");
        break;
    case 7:
        printf("\n 2xy \n");
        break;
    case 8:
         printf("\n 2+x-y^2 \n");
    break;
    default:
        printf("\n No existe la función \n");
        break;
    }
}

void euler(){
    int funcion;
    double x0, x1, y0, h;

    funcion = menu_funcion();
    limites(&x0, &x1, &y0, &h);
    euler_simple(x0,x1,y0,h,funcion);
}

void eulermejorado(){
    int caso, funcion;
    double x0, x1, y0, h;

    funcion = menu_funcion();
    limites(&x0, &x1, &y0, &h);
    euler_mejorado(x0,x1,y0,h,funcion);

}

void runge(){
    int caso, funcion;
    double x0, x1, y0, h;

    funcion = menu_funcion();
    limites(&x0, &x1, &y0, &h);
    runge_kutta(x0,x1, y0, h, funcion);

}

void euler_simple(double x0, double x1, double y0, double h, int funcion) {
    double yn, x;
    int j=1;

    printf("\n EULER SIMPLE");
    printf("\n FUNCION");
    imprimir_funcion(funcion);

    yn = y0;

    for(x=x0; x<=x1; x+=h) {
        yn = yn + h* opcion_funcion(funcion,x,yn);
        printf("\n x%d = %.9f, y%d = %.9f\n", j,x,j,yn);
        j++;
    }
}

void euler_mejorado(double x0, double x1, double y0, double h, int funcion) {
    double func1,func2,y,yn, x;
    int j=1;

    printf("\n EULER MEJORADO");
    printf("\n FUNCION");
    imprimir_funcion(funcion);

    yn = y0;

    for(x=x0; x<=x1; x+=h) {

        func1 = opcion_funcion(funcion,x,yn);
        y = yn + h*func1;
        func2 = opcion_funcion(funcion,x+h,y);
        yn = yn + h*(func1+func2)/2;
        printf("\n x%d = %.9f, y%d = %.9f\n", j,x,j,yn);
        j++;
    }
}

void runge_kutta(double x0, double x1, double y0, double h, int funcion) {
    double k1,k2,k3,k4, y,yn, x;
    int j=1;

    printf("\n RUNGE KUTTA");
    printf("\n FUNCION");
    imprimir_funcion(funcion);

    yn = y0;

    for(x=x0; x<=x1+h; x+=h) {
        k1 = h* opcion_funcion(funcion,x,yn);
        k2 = h* opcion_funcion(funcion,x+h/2,yn+k1/2);
        k3 = h* opcion_funcion(funcion,x+h/2,yn+k2/2);
        k4 = h* opcion_funcion(funcion,x+h,yn+k3);
        yn = yn +(k1+2*k2+2*k3+k4)/6;
        printf("\n k1 = %.9f", k1);
        printf("\n k2 = %.9f", k2);
        printf("\n k3 = %.9f", k3);
        printf("\n k4 = %.9f", k4);
        printf("\n x%d = %.9f, y%d = %.9f\n", j,x,j,yn);
        j++;
    }
}
