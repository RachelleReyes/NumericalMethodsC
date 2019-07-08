#include <stdio.h>

void captura (int *, int *);
void imprimir(double *,int, int);
void aumentarmatriz(double *,double *,int, int);
void resultado_inversa(double *,double *,double *,int, int);
void Inversa(double *, double *,double *,double *,double *,int, int);
void GaussJordan(double *, double *,double *,double *,int , int );
void procedimiento (double *,int, int, int);
void capturanumeros(double *,int, int );
void Jacobi(double *, double *,double *,int, int);
void Gauss_Seidel(double *, double *,double *,int, int);
int convergencia(double *, double *,int, int);
void imprimir_sistemaEc(double *arre, double *arreb,int filas, int columnas);
void comprobacion(double *arre, double *arreb,double *resultante,int filas, int columnas);
void imprimir_tabla(double *resultante,int fila, int columnas);

int main()
{
    int filas=0, columnas=0,metodo;

    captura(&filas,&columnas);
    double arre[filas*columnas];
    double arreb[filas];
    double aumentada[filas*columnas*2];
    double aumentada2[filas*columnas+1];
    double inversa [filas*columnas];
    double resultante[filas];

    printf("\nIngrese los numeros de la matriz A");
    //capturanumeros(arre, filas, columnas);
    printf("\nIngrese los numeros de la matriz B");
   // capturanumeros(arreb, filas, 1);

   arre[0*columnas + 0] = 8;
   arre[0*columnas + 1] = 2;
   arre[0*columnas + 2] = -2;
   arre[1*columnas + 0] = 1;
   arre[1*columnas + 1] = -8;
   arre[1*columnas + 2] = 3;
   arre[2*columnas + 0] = 2;
   arre[2*columnas + 1] = 1;
   arre[2*columnas + 2] = 9;

   arreb[0] = 8;
   arreb[1] = -4;
   arreb[2] = 12;


/*
   arre[0*columnas + 0] = 3;
   arre[0*columnas + 1] = -13;
   arre[0*columnas + 2] = 9;
   arre[0*columnas + 3] = 3;
   arre[1*columnas + 0] = -6;
   arre[1*columnas + 1] = 4;
   arre[1*columnas + 2] = 1;
   arre[1*columnas + 3] = -18;
   arre[2*columnas + 0] = 6;
   arre[2*columnas + 1] = -2;
   arre[2*columnas + 2] = 2;
   arre[2*columnas + 3] = 4;
   arre[3*columnas + 0] = 12;
   arre[3*columnas + 1] = -8;
   arre[3*columnas + 2] = 6;
   arre[3*columnas + 3] = 10;

   arreb[0] = -19;
   arreb[1] = -34;
   arreb[2] = 16;
   arreb[3] = 26;

*/

/*
   arre[0*columnas + 0] = 6;
   arre[0*columnas + 1] = -2;
   arre[0*columnas + 2] = 2;
   arre[0*columnas + 3] = 4;
   arre[1*columnas + 0] = 0;
   arre[1*columnas + 1] = 2;
   arre[1*columnas + 2] = 3;
   arre[1*columnas + 3] = -14;
   arre[2*columnas + 0] = 0;
   arre[2*columnas + 1] = -12;
   arre[2*columnas + 2] = 8;
   arre[2*columnas + 3] = 1;
   arre[3*columnas + 0] = 0;
   arre[3*columnas + 1] = -4;
   arre[3*columnas + 2] = 2;
   arre[3*columnas + 3] = 2;

   arreb[0] = 16;
   arreb[1] = -18;
   arreb[2] = -27;
   arreb[3] = -6;

*/
/*
   arre[0*columnas + 0] = 6;
   arre[0*columnas + 1] = -2;
   arre[0*columnas + 2] = 2;
   arre[0*columnas + 3] = 4;
   arre[1*columnas + 0] = 12;
   arre[1*columnas + 1] = -8;
   arre[1*columnas + 2] = 6;
   arre[1*columnas + 3] = 10;
   arre[2*columnas + 0] = 3;
   arre[2*columnas + 1] = -13;
   arre[2*columnas + 2] = 9;
   arre[2*columnas + 3] = 3;
   arre[3*columnas + 0] = -6;
   arre[3*columnas + 1] = 4;
   arre[3*columnas + 2] = 1;
   arre[3*columnas + 3] = -18;

   arreb[0] = 16;
   arreb[1] = 26;
   arreb[2] = -19;
   arreb[3] = -34;
*/
    do{
        printf("\n\nIngrese el numero de metodo que desea utilizar: ");
        printf("\n [1] INVERSA ");
        printf("\n [2] GAUSS JORDAN ");
        printf("\n [3] JACOBI ");
        printf("\n [4] GAUSS-SEIDEL ");
        printf("\n [0] SALIR\n");
        scanf("%d",&metodo);

      getchar();

      switch(metodo) {
        case 1:
            printf("\n METODO INVERSA \n");
            Inversa(arre, arreb, aumentada,inversa,resultante, filas,columnas);
            break;
        case 2:
            printf("\n METODO GAUSS JORDAN \n");
            GaussJordan(arre,arreb,aumentada2,resultante,filas,columnas);
            break;
        case 3:
            printf("\n METODO JACOBI \n");
            Jacobi(arre, arreb,resultante,filas,columnas);
        break;
        case 4:
            printf("\n METODO GAUSS-SEIDEL \n");
            Gauss_Seidel(arre, arreb,resultante,filas,columnas);
        break;
      }
    }while(metodo>0);

    return 0;
}

void captura (int *filas, int *columnas) {
    do {
        printf("Ingrese el numero de filas de la matriz: ");
        scanf("%d",filas);
        printf("Ingrese el numero de columnas de la matriz: ");
        scanf("%d",columnas);
        if(*filas!=*columnas) {printf("\nIngrese las dimensiones de nuevo\n");}
    }while(*filas!=*columnas);
}

void imprimir(double *arreglo,int filas, int columnas) {
    int i, j;

    printf("\n");
    for (i = 0; i < filas; i++) {
      for (j = 0; j < columnas; j++) {
       printf("%10f", *((arreglo+i*columnas) + j));
      }
      printf("\n");
    }
}

void capturanumeros(double *arreglo,int filas, int columnas) {
    int i,j;
    for(i=0;i<filas;i++) {
        for(j=0;j<columnas;j++) {
            printf("\nElemento Matriz[%d][%d]: ",i,j);
            scanf("%lf",((arreglo+i*columnas) + j));
        }
    }
}

void aumentarmatriz(double *arreglo,double *aumentada,int filas, int columnas) {
    int i,j,k=0;
    double numero;

    for(i=0; i<filas;i++) {
        for(j=0; j<columnas;j++) {

            if (j>=filas){
                if(i+filas==j) {
                    *((aumentada+i*columnas) + j) =1;
                }
                else {
                    *((aumentada+i*columnas) + j)=0;
                }
            }
            else {
                numero=*(arreglo+k);
                *((aumentada+i*columnas) + j) = numero;
                k++;
            }
        }
    }
}

 void resultado_inversa(double *arreglo,double *matrizA,double *matrizB,int filas, int columnas) {
        int i, j;

        printf("\n Resultado:\n");
        for(i=0; i<filas;i++) {
                *(arreglo+i)=0;
            for(j=0; j<columnas;j++) {
               *(arreglo+i)+= *((matrizA+i*columnas) + j)* (*(matrizB+ j));
            }
            printf("\n x%d = %f",i,*(arreglo+i));
        }
}

void Inversa(double *arre, double *arreb, double *aumentada, double *inversa,double *resultante, int filas, int columnas) {
    int i,j,columnaaumentada=columnas*2;

    aumentarmatriz(arre,aumentada,filas,columnaaumentada);
    printf("\n Sistema de ecuaciones \n");
    imprimir_sistemaEc(arre,arreb,filas,columnas+1);
    procedimiento(aumentada,filas,columnas,columnaaumentada);

    printf("\n Matriz inversa\n\n");
    for(i=0; i<filas;i++) {
        for(j=0; j<columnas;j++) {
            *((inversa+i*columnas) + j) =*((aumentada+i*columnaaumentada) + j+filas);
            printf("%10f",*((inversa+i*columnas) + j));
        }
        printf("\n");
    }

    resultado_inversa(resultante,inversa,arreb,filas, columnas);
    comprobacion(arre, arreb,resultante,filas,columnas);

}


void imprimir_sistemaEc(double *arre, double *arreb,int filas, int columnas) {
    int i, j, l=0, k=0;
    double aumentada[columnas*filas];

    for(i=0; i<filas;i++) {
        for(j=0; j<columnas;j++) {
            if(j==filas) {
                *((aumentada+i*columnas) + j) = *(arreb+k);
                k++;
            }
            else {
                *((aumentada+i*columnas) + j) =*(arre+l);
                l++;
            }
        }
    }

    printf("\n");
    for (i = 0; i < filas; i++) {
      for (j = 0; j < columnas; j++) {
       printf("%10f", *((aumentada+i*columnas) + j));
      }
      printf("\n");
    }
}

void GaussJordan(double *arre, double *arreb,double *aumentada,double *resultante,int filas, int columnas) {
    int i,j,k=0,l=0,columnaaumentada=columnas+1;

   for(i=0; i<filas;i++) {
        for(j=0; j<columnaaumentada;j++) {
            if(j==columnas) {
                *((aumentada+i*columnaaumentada) + j) = *(arreb+k);
                k++;
            }
            else {
                *((aumentada+i*columnaaumentada) + j) =*(arre+l);
                l++;
            }
        }
    }
    printf("\n Sistema de ecuaciones \n");
    imprimir_sistemaEc(arre,arreb,filas,columnas+1);
    procedimiento(aumentada,filas,columnas,columnaaumentada);

    printf("\n Resultado:\n");
    for(i=0; i<filas;i++) {
        for(j=0; j<1;j++) {
           *(resultante+i)= *((aumentada+i*columnaaumentada) + j+filas);
        }
        printf("\n x%d = %f",i,*(resultante+i));
    }
    comprobacion(arre, arreb,resultante,filas,columnas);

}

void procedimiento (double *aumentada,int filas, int columnas, int columnaaumentada) {
    int i,j,k,a,b,calcular=0;
    double auxiliar=0;

    printf("\n Matriz aumentada \n");
    imprimir(aumentada,filas,columnaaumentada);

   for(i=0; i<columnas+1;i++) {

    if(calcular==1) {
        i--;
        a=0;
        b=i;
        calcular=0;
    }
    else {
        a=i;
        b= filas;
    }
    for(j=a;j<b;j++) {
        for (k=i; k<columnaaumentada;k++) {
            if((j==k && i==k)|| i==k) {
                    auxiliar = *((aumentada+j*columnaaumentada) + k);

            }

            if(i==j) { *((aumentada+j*columnaaumentada) + k)= *((aumentada+j*columnaaumentada) + k)/auxiliar;}
                else {*((aumentada+j*columnaaumentada) + k)= -1*auxiliar*(*((aumentada+i*columnaaumentada) + k))+*((aumentada+j*columnaaumentada) + k);
                }
        }
    }
        if(i>0 && j==filas && *((aumentada+i*columnaaumentada) + i)==1 && k>i) {calcular=1;}

   }
   printf("\n Matriz resuelta \n");
   imprimir(aumentada,filas,columnaaumentada);
}

void Jacobi(double *arre, double *arreb,double *resultante,int filas, int columnas) {
    int i, j, iter=0;
    double temp, suma=0;
    double temporal[filas];
    int converge;

    printf("\n Sistema de ecuaciones \n");
    imprimir_sistemaEc(arre,arreb,filas,columnas+1);

    for(int i =0;i<filas;i++) {
        *(resultante+i) = 0;
        *(temporal+i) = 0;
    }
    do
    {
        iter++;
        for(i=0; i<filas; i++) {
            for(j=0;j<columnas;j++) {
                if(i==j) {
                    temp = *((arre+i*columnas) +j);
                    suma+= *(arreb+i);
                }
                else {
                  suma+= *((arre+i*columnas) +j)* (*(temporal+j))*-1;
                }
            }
            *(resultante +i) =  suma/temp;
            suma =0;
        }

        converge = convergencia(temporal, resultante,filas,columnas);


         for(int k =0;k<filas;k++) {
            *(temporal+k) =  *(resultante+k);
        }

        if(converge==0) {
           // printf("\nIteracion: %d",iter);
            //imprimir(resultante,filas,1);
             imprimir_tabla(resultante,iter-1,columnas);
        }

    }while(converge == 0);

}

void Gauss_Seidel(double *arre, double *arreb,double *resultante,int filas, int columnas) {
    int i, j, iter=0,converge;
    double temp, suma=0;
    double temporal[filas];

    printf("\n Sistema de ecuaciones \n");
    imprimir_sistemaEc(arre,arreb,filas,columnas+1);

    for(int i =0;i<filas;i++) {
        *(resultante+i) = 0;
        *(temporal+i) = 0;
    }
    printf(" Iteracion  ");
    for(int i =0;i<filas;i++) {
       printf("        x%d            ",i);
    }
    printf("\n");

    do
    {
        iter++;
        for(i=0; i<filas; i++) {
            for(j=0;j<columnas;j++) {
                if(i==j) {
                    temp = *((arre+i*columnas) +j);
                    suma+= *(arreb+i);
                }
                else {
                  suma+= *((arre+i*columnas) +j)* (*(resultante+j))*-1;
                }
            }
            *(resultante +i) =  suma/temp;
            suma =0;
        }

        converge = convergencia(temporal, resultante,filas,columnas);

         for(int k =0;k<filas;k++) {
            *(temporal+k) =  *(resultante+k);
        }

        if(converge==0) {
            //printf("\nIteracion: %d",iter);
           imprimir_tabla(resultante,iter-1,columnas);
        }
    }while(converge==0);
}

int convergencia(double *temporal, double *resultante,int filas, int columnas) {
    int i=0, converge=1;
    //double error = 0.00000000000000000001;
    double error = 0;
     while(converge == 1 && i<filas) {
           if((*(resultante+i)-*(temporal+i))<=error) {
                converge = 1;
           }
           else {
            converge =0;
           }
           i++;
    }
    return converge;
}

void comprobacion(double *arre, double *arreb,double *resultante,int filas, int columnas) {
    int i, j,exacto =1;
    double suma[filas], error = 0.1;

    printf("\n\n Comprobaci\xA2n\n\n");
     for (i=0; i<filas; i++) {
        *(suma+i) =0;
      for (j=0; j<columnas; j++) {
        printf(" %.2f(%.2f) ",*((arre+i*columnas) + j),*(resultante+ j));
        *(suma+i)+= *((arre+i*columnas) + j) * (*(resultante+ j));
        if(j<(columnas-1) && *((arre+i*columnas) + j+1)>0) {printf("+");}
      }
      printf("= %.2f\n",*(suma+i));
    }
    i=0;
    while(i<filas && exacto == 1) {
            //printf("\nsuma %f, arreb %f\n",*(suma+i),*(arreb+i));
        if((*(suma+i) - *(arreb+i))<= error){
            exacto =1;
        }
        else {
            exacto =0;
            printf("\n\n No satisfacen el sistema de ecuaciones \n");
        }
          i++;
    }

    if(i==filas && exacto ==1) {
        printf("\n S\xA1 satisfacen el sistema de ecuaciones \n");
    }
}

void imprimir_tabla(double *resultante,int fila, int columnas) {

    int i;
    printf(" %5d ",fila);
    for(i=0; i<columnas; i++) {
        printf("%22.15lf",*(resultante+i));
    }
    printf("\n");

}
