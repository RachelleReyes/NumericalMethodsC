#include<stdio.h>
#include<math.h>

#define  CLEAR(); system("CLS")

void biseccion(double, double, double, int, double, int , double);
void ModFalsePos(double , double , double, int, double, int, double);
void NewtonRaphson(double, int, double);
void NewtonRaphson2(double, int, double);
double funcion (double);
double funcion2 (double);
double funcion3 (double);
double funcion3_deriv(double);
double funcion3_deriv2(double);

int main()
{
    double a,b,xs=0,ea=0,es=0,xi;
    int imax=0, iter=0,cifras=5,metodo=-1;

do{

    printf("\nIngrese el numero de metodo que desea ingresar: ");
    printf("\n [1] BISECCION ");
    printf("\n [2] FALSA POSICION ");
    printf("\n [3] NEWTON RAPHSON (1ER ORDEN)");
    printf("\n [4] NEWTON RAPHSON (2DO ORDEN)");
    printf("\n [0] SALIR\n");
    scanf("%d",&metodo);

    if(metodo==1)
    {
        printf("Valor de a: ");
        scanf("%lf",&a);

        printf("\nValor de b: ");
        scanf("%lf",&b);

        printf("\nMaxima iteracion: ");
        scanf("%d",&imax);

        printf("\nValor de es: ");
        scanf("%lf",&es);

        printf("METODO DE BISECCION");
        printf("\n             a                   b                   xs                 fa                  fx                  ea\n");
        biseccion(a,b,es,imax,xs,iter,ea);
    }
    else if(metodo==2)
    {
        printf("Ingrese el valor de a: ");
        scanf("%lf",&a);

        printf("\nIngrese el valor de b: ");
        scanf("%lf",&b);

        printf("\nMaxima iteracion: ");
        scanf("%d",&imax);

        printf("\nValor de es: ");
        scanf("%lf",&es);

        printf("METODO DE FALSA POSICION");
        printf("\n            a                   b                    xs                  fa                  fb                  fx                  ea\n");
        ModFalsePos(a,b,es,imax,xs,iter,ea);
    }
     else if(metodo==3)
    {
        printf("Ingrese el valor inicial: ");
        scanf("%lf",&xi);

        printf("\nIngrese el valor de la iteracion maxima: ");
        scanf("%d",&imax);

        printf("\nIngrese el valor de es: ");
        scanf("%lf",&es);

        printf("NEWTON RAPHSON (1ER ORDEN)");
        printf("\n            xi                  f(xi)                f'(xi)               xi+1               ea\n");
        NewtonRaphson(xi,imax,es);
    }
     else if(metodo==4)
    {
        printf("Ingrese el valor inicial: ");
        scanf("%lf",&xi);

        printf("\nIngrese el valor de la iteracion maxima: ");
        scanf("%d",&imax);

        printf("\nIngrese el valor de es: ");
        scanf("%lf",&es);

        printf("NEWTON RAPHSON (2DO ORDEN)");
        printf("\n            xi                  f(xi)                f'(xi)                f''(xi)               xi+1               ea\n");
        NewtonRaphson2(xi,imax,es);
    }
    getchar();

}while(metodo>0);

    return 0;
}

//Funcion para el metodo de biseccion
double funcion (double x)
{
    //return pow(x,2)-4*x-8.95;
    //return pow(x,3)+ 4*pow(x,2)-10;
    return 2*x*cos(2*x)-pow(x+1,2);
}
void biseccion(double a, double b, double es, int imax, double xs, int iter, double ea)
{
   double xs_orig, fa,fb, fxs,comprobacion;

    fa= funcion(a);
    fb= funcion(b);

    if((fa*fb)<0)
    {
        do
        {
            xs_orig = xs;
            xs = (a+b)/2;
            iter++;

            if(xs_orig!=0){ea = fabs(((xs-xs_orig)/xs)*100);}

            fa= funcion(a);
            fb= funcion(b);
            fxs = funcion(xs);
            comprobacion = fa*fxs;

            if(iter==1){
                printf("%3d %19.15f %19.15f %19.15f %19.15f %19.15f\n",iter,a,b,xs,fa,fxs);
                ea=100;
            }
            else{printf("%3d %19.15f %19.15f %19.15f %19.15f %19.15f %19.15f\n",iter,a,b,xs,fa,fxs,ea);}
            if(comprobacion<0){b=xs;}
                else if(comprobacion>0){a=xs;}
                    else ea=0;

       }while(ea>es && iter<=imax);
    }
}

//Funcion para el metodo de falsa posicion
double funcion2 (double x)
{
   // double e=2.71828;
   // return (pow(e,x)-3*pow(x,2));
   // return pow(x,3)+ 4*pow(x,2)-10;
    return 2*x*cos(2*x)-pow(x+1,2);
}

void ModFalsePos(double a, double b, double es, int imax, double xs, int iter, double ea)
{
   double xs_orig, fa,fb, fxs,comprobacion;

    fa= funcion2(a);
    fb= funcion2(b);

    if((fa*fb)<0)
    {
        do
        {
           xs_orig = xs;
           xs = b-(fb*(a-b)/(fa-fb));
           iter++;

            if(xs_orig!=0){ea = fabs(((xs-xs_orig)/xs)*100);}

            fa= funcion2(a);
            fb= funcion2(b);
            fxs = funcion2(xs);
            comprobacion = fa*fxs;

            if(iter==1){
                printf("%3d %19.15f %19.15f %19.15f %19.15f %19.15f %19.15f\n",iter,a,b,xs,fa,fb,fxs);
                ea=100;
            }
            else{printf("%3d %19.15f %19.15f %19.15f %19.15f %19.15f %19.15f %19.15f\n",iter,a,b,xs,fa,fb,fxs,ea);}

            if(comprobacion<0){b=xs;
                                fb= funcion2(b);}
                else if(comprobacion>0){a=xs;
                                fa= funcion2(a);}
                    else ea=0;
        }while(ea>es && iter<=imax);
    }
}

//Funciones para el metodo de Newton-Raphson (1er orden)
double funcion3 (double x)
{
    //return 2*pow(x,3) -11.7*pow(x,2) + 17.7*x -5;
    //  return pow(x,3)+ 4*pow(x,2)-10;
      return 2*x*cos(2*x)-pow(x+1,2);
}
double funcion3_deriv (double x)
{
    //return 6*pow(x,2)-23.4*x+17.7;
     // return 3*pow(x,2)+ 8*x;
    return -4*x*sin(2*x)-2*x+2*cos(2*x)-2;
}


void NewtonRaphson(double xi, int imax, double es){

    double fx,fxd,xi_nuevo,ea,ea_nuevo;
    int iter=0;

     do
    {
      iter++;
      fx= funcion3(xi);
      fxd = funcion3_deriv(xi);
      xi_nuevo = xi - (fx/fxd);

      if(iter==1){
            printf("%3d %19.15f %20.15f %20.15f %20.15f\n",iter,xi,fx,fxd,xi_nuevo);
            ea =100;
      }else {
            printf("%3d %19.15f %20.15f %20.15f %20.15f %20.15f\n",iter,xi,fx,fxd,xi_nuevo,ea);
            }

        if(xi_nuevo!=0){ea = fabs(((xi_nuevo-xi)/xi_nuevo)*100);}
        xi = xi_nuevo;

    }while(ea>es && iter<imax);
      if(++iter<imax)
      {
        fx= funcion3(xi);
        fxd = funcion3_deriv(xi);
        xi_nuevo = xi - (fx/fxd);
        printf("%3d %19.15f %20.15f %20.15f %20.15f %20.15f \n",iter,xi,fx,fxd,xi_nuevo,ea);
      }
}


//Funciones para el metodo de Newton-Raphson (2do orden)
double funcion4 (double x)
{
  // return cos(x)-3*x+5;
  // return pow(x,3)+ 4*pow(x,2)-10;
  return 2*x*cos(2*x)-pow(x+1,2);
}

double funcion4_deriv (double x)
{
    //return -sin(x)-3;
    //return 3*pow(x,2)+ 8*x;
    return -4*x*sin(2*x)-2*x+2*cos(2*x)-2;

}

double funcion4_deriv2 (double x)
{
    //return -cos(x);
   // return 6*x+ 8;
   return -8*x*cos(2*x) - 8*sin(2*x)-2;
}


void NewtonRaphson2(double xi, int imax, double es){

    double fx,fxd,fxd2,xi_nuevo,ea,ea_nuevo;
    int iter=0;

     do
    {
      iter++;
      fx= funcion4(xi);
      fxd = funcion4_deriv(xi);
      fxd2 = funcion4_deriv2(xi);
      xi_nuevo = xi - (fx*fxd)/(pow(fxd,2)-fx*fxd2);

      if(iter==1){
            printf("%3d %19.15f %20.15f %20.15f %20.15f%21.15f\n",iter,xi,fx,fxd,fxd2,xi_nuevo);
            ea =100;
      }else {
            printf("%3d %19.15f %20.15f %20.15f %20.15f %20.15f%20.15f\n",iter,xi,fx,fxd,fxd2,xi_nuevo,ea);
            }

        if(xi_nuevo!=0){ea = fabs(((xi_nuevo-xi)/xi_nuevo)*100);}
        xi = xi_nuevo;

    }while(ea>es && iter<imax);
    if(++iter<imax)
    {
        fx= funcion4(xi);
        fxd = funcion4_deriv(xi);
        fxd2 = funcion4_deriv2(xi);
        xi_nuevo = xi - (fx*fxd)/(pow(fxd,2)-fx*fxd2);
        printf("%3d %19.15f %20.15f %20.15f %20.15f %20.15f%20.15f \n",iter,xi,fx,fxd,fxd2,xi_nuevo,ea);
    }
}
