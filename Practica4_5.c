/*Programa que resuelva el metodo de Simpson 1/3 simple y multiple; metodo Simpson 3/8*/

 #include <stdio.h>
 #include <math.h>

double opcion_funcion(int, double);
void trapecio_simple(double, double, int);
void imprimir_funcion(int);
void trapecio_aplicacionMult(double, double, int, int);
void trapecio();
void simpson();
void simpson_simple1_3(double, double, int);
void simpson_aplicacionMult1_3(double, double, int, int);
void simpson_simple3_8(double, double, int);
int menu_funcion();
void bibliografia();

int main()
{
    int metodo;

    do{
        printf("\n\nIngrese el n\xA3mero de m\x82todo que desea utilizar: ");
        printf("\n [1] TRAPECIO ");
        printf("\n [2] SIMPSON ");
        printf("\n [3] BIBLIOGRAFIAS");
        printf("\n [0] SALIR\n");
        scanf("%d",&metodo);
        getchar();

        switch(metodo) {
        case 1:
           trapecio();
            break;
        case 2:
           simpson();
            break;
        case 3:
            bibliografia();
            break;
        default:
            printf("\nIngrese otro n\xA3mero:\n");
            break;
        }

    }while(metodo>0);

    return 0;
}

void bibliografia() {
    printf("\n Bibliografia de las funciones 5 y 6 del m\x82todo Trapecio");
    printf("\n Chapra, S. & Canale R. (2011). F\xA2rmulas de Integraci\xA2n de Newton Cort\x82s. En M\x82todos Num\x82ricos para Ingenieros(p. 572). M\x82xico, D.F: McGrawHill.\n");
}

int menu_funcion() {
    int funcion;

    printf("\n Elige la funci\xA2n que deseas utilizar ");
    printf("\n [1] 0.2 + 25x - 200x^2 + 675x^3+ - 900x^4 + 400x^5 \n");
    printf("\n [2] e^x \n");
    printf("\n [3] 1/(1+x^2) \n");
    printf("\n [4] logx \n");
    printf("\n [5] 1-e^-x \n");
    printf("\n [6] 5+3cosx \n");
    scanf("%d",&funcion);

    return funcion;
}
void limites(double *a, double *b, int comparacion) {

    if(comparacion == 1) {
        do {
            printf("\n Ingrese los l\xA1mites ");
            printf("\n a: ");
            scanf("%lf",a);
            printf("\n b: ");
            scanf("%lf",b);
            if(*b<*a) {
                printf("\nIngrese l\xA1mites en los cuales b es mayor que a");
            }
        }while(*b<*a);
    }
    else {
        printf("\n Ingrese los l\xA1mites ");
        printf("\n a: ");
        scanf("%lf",a);
        printf("\n b: ");
        scanf("%lf",b);
    }

}

void trapecio(){
    int caso, funcion, segmentos;
    double a,b;

    printf("\n Caso: ");
    printf("\n [1] SIMPLE ");
    printf("\n [2] APLICACION MULTIPLE \n");
    scanf("%d",&caso);

    funcion = menu_funcion();
    limites(&a, &b, 0);

    if(caso==1) {
        trapecio_simple(a,b, funcion);
    }
    else if(caso == 2) {
        printf("\n Captura el n\xA3mero de segmentos ");
        scanf("%d",&segmentos);
        trapecio_aplicacionMult(a,b, segmentos, funcion);
    }
}

void simpson(){
    int caso, funcion, segmentos;
    double a,b;

    printf("\n Caso: ");
    printf("\n [1] SIMPLE (1/3)");
    printf("\n [2] APLICACION MULTIPLE (1/3)");
    printf("\n [3] SIMPLE (3/8)\n");
    scanf("%d",&caso);

    funcion = menu_funcion();
    limites(&a, &b, 1);

    if(caso==1) {
        simpson_simple1_3(a,b, funcion);
    }
    else if(caso == 2) {
        do {
            printf("\n Captura el n\xA3mero de segmentos ");
            scanf("%d",&segmentos);
            if(segmentos%2!=0) {printf("\n Ingrese un segmento par");}
        }while(segmentos%2!=0);
        simpson_aplicacionMult1_3(a,b, segmentos, funcion);
    }
    else if(caso==3) {
        simpson_simple3_8(a,b, funcion);
    }

}

void imprimir_funcion(int f)
{
    switch(f) {
    case 1:
        printf("\n 0.2 + 25x - 200x^2 + 675x^3+ - 900x^4 + 400x^5\n");
        break;
    case 2:
         printf("\n  e^x\n");
        break;
    case 3:
        printf("\n 1/(1+x^2)\n");
        break;
    case 4:
        printf("\n logx\n");
        break;
    case 5:
        printf("\n 1-e^-x \n");
        break;
    case 6:
        printf("\n 5+3cosx \n");
        break;
    default:
        printf("\n No existe la función \n");
        break;
    }
}

void trapecio_simple(double a, double b, int funcion) {
    double I;

    printf("\nTRAPECIO SIMPLE");
    printf("\nFUNCION");
    imprimir_funcion(funcion);
    I = (opcion_funcion(funcion,a) + opcion_funcion(funcion,b))*(b-a)/2;
    printf("\nI = %.9f", I);
}

void trapecio_aplicacionMult(double a, double b, int n, int funcion) {
    double I, h, sumatoria=0, aumento[n+1], evaluacion[n+1];
    int i;

    printf("\nTRAPECIO APLICACION MULTIPLE");
    printf("\nFUNCION");
    imprimir_funcion(funcion);
    h = (b-a)/n;

    aumento[0] = a;
    for(i=1;i<=n;i++) {
        aumento[i] =aumento[i-1] + h;
    }

    for(i=0;i<=n;i++) {
        evaluacion[i] = opcion_funcion(funcion,aumento[i]);
        if(i!=0 && i!=n) {sumatoria+= evaluacion[i];}
    }
    printf("\nN\xA3mero de segmentos: %d", n);
    I = ((evaluacion[0] + 2*sumatoria+ evaluacion[n])*(b-a))/(double)(2*n);
    printf("\nI = %.9f", I);
}
void simpson_simple1_3(double a, double b, int funcion) {
    double I,h;
    h = (b-a)/2;

    printf("\nSIMPSON SIMPLE 1/3");
    printf("\nFUNCION");
    imprimir_funcion(funcion);
    I = (opcion_funcion(funcion,a) + 4*opcion_funcion(funcion,h) + opcion_funcion(funcion,b))*(b-a)/6;
    printf("\nI = %.9f", I);
}
void simpson_aplicacionMult1_3(double a, double b, int n, int funcion) {
    double I, h, sumatoria_par=0,sumatoria_impar=0, aumento[n+1], evaluacion[n+1];
    int i;

    printf("\nSIMPSON 1/3 APLICACION MULTIPLE ");
    printf("\nFUNCION");
    imprimir_funcion(funcion);
    h = (b-a)/n;

    aumento[0] = a;
    for(i=1;i<=n;i++) {
        aumento[i] =aumento[i-1] + h;
    }

    for(i=0;i<=n;i++) {
        evaluacion[i] = opcion_funcion(funcion,aumento[i]);
        if(i!=0 && i!=n && i%2==0) {sumatoria_par+= evaluacion[i];}
            else if(i!=0 && i!=n && i%2!=0) {sumatoria_impar+= evaluacion[i];}
    }
    printf("\nN\xA3mero de segmentos: %d", n);
    I = ((evaluacion[0] + 4*sumatoria_impar+ 2*sumatoria_par+ evaluacion[n])*(b-a))/(double)(3*n);
    printf("\nI = %.9f", I);
}

void simpson_simple3_8(double a, double b, int funcion) {
   double I, h, aumento[4], evaluacion[4];
    int i;

    printf("\nSIMSPON SIMPLE 3/8");
    printf("\nFUNCION");
    imprimir_funcion(funcion);
    h = (b-a)/3;

    aumento[0] = a;
    for(i=1;i<=4;i++) {
        aumento[i] =aumento[i-1] + h;
    }
    for(i=0;i<=4;i++) {
        evaluacion[i] = opcion_funcion(funcion,aumento[i]);
    }
    I = ((evaluacion[0] + 3*evaluacion[1]+ 3*evaluacion[2]+ evaluacion[3])*(b-a))/8;
    printf("\nI = %.9f", I);
}
double opcion_funcion(int num, double x) {
    double resultado;

   switch(num) {
    case 1:
           resultado = 0.2 + 25*x - 200*pow(x,2) + 675*pow(x,3)- 900*pow(x,4)+400*pow(x,5);
        break;
    case 2:
            resultado = exp(x);
        break;
    case 3:
            resultado = 1/(1+pow(x,2));
        break;
    case 4:
            resultado = log10(x);
        break;
    case 5:
            resultado = 1-exp(-x);
        break;
    case 6:
            resultado = 5 + 3*cos(x);
        break;
    default:
            resultado = 0;
        break;
   }
   return resultado;
}
