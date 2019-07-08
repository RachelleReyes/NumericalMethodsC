#include <stdio.h>

float funcion (float, float,float);
void captura (int *, int *);
void imprimir(float *,int, int);
void aumentarmatriz(float *,float *,int, int);
void resultado(float *,float *,float *,int, int);
void inversamatriz(float *, float *,int, int);
void GaussJordan(float *, float *,float *,float *,int , int );

int main()
{
    int filas=0, columnas=0,i,j,k,metodo;

    captura(&filas,&columnas);
    float arre[filas][columnas];
    float arreb[filas][1];
    float aumentada[filas][columnas*2];
    float aumentada2[filas][columnas+1];
    float inversa [filas][columnas];
    float resultante[filas];

    printf("\nIngrese los numeros de la matriz A");
    capturanumeros(arre, filas, columnas);
    printf("\nIngrese los numeros de la matriz B");
    capturanumeros(arreb, filas, 1);


    do{
        printf("\nIngrese el numero de metodo que desea utilizar: ");
        printf("\n [1] INVERSA ");
        printf("\n [2] GAUSS JORDAN ");
        printf("\n [0] SALIR\n");
        scanf("%d",&metodo);

      getchar();

      if(metodo==1) {
        aumentarmatriz(arre,aumentada,filas, columnas*2);
        imprimir(aumentada, filas, columnas*2);
        inversamatriz(aumentada,inversa,filas,columnas);
        resultado(resultante,inversa,arreb,filas, columnas);
      }
      else if(metodo==2) {
        GaussJordan(arre,arreb,aumentada2,resultante,filas,columnas);
      }


    }while(metodo>0);


    return 0;
}

float funcion (float num1, float num2,float num3) {
    return num1*num2-num3;
}

void captura (int *filas, int *columnas)
{
    printf("Ingrese el numero de filas de la matriz: ");
    scanf("%d",filas);
    printf("Ingrese el numero de columnas de la matriz: ");
    scanf("%d",columnas);

}

void imprimir(float *arreglo,int filas, int columnas) {
    int i, j;
    for (i = 0; i < filas; i++) {
      for (j = 0; j < columnas; j++) {
        printf("%10f", *((arreglo+i*columnas) + j));
      }
      printf("\n");
    }
}

void capturanumeros(float *arreglo,int filas, int columnas)
{
    int i,j;
    for(i=0;i<filas;i++) {
        for(j=0;j<columnas;j++) {
            printf("\nElemento Matriz[%d][%d]: ",i,j);
            scanf("%f",((arreglo+i*columnas) + j));
        }
    }
}

void aumentarmatriz(float *arreglo,float *aumentada,int filas, int columnas)
{
    int i,j,k=0;
    float numero;

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

 void resultado(float *arreglo,float *matrizA,float *matrizB,int filas, int columnas) {
        int i, j;
        for(i=0; i<filas;i++) {
                *(arreglo+i)=0;
            for(j=0; j<columnas;j++) {
               *(arreglo+i)+= *((matrizA+i*columnas) + j)* (*(matrizB+ j));
            }
            printf("\n x%d = %f",i,*(arreglo+i));
        }
}

void inversamatriz(float *aumentada, float *inversa,int filas, int columnas) {
    int i,j,k,l,m,calcular=0,principal,columnaaumentada=columnas*2;
    float auxiliar=0;

    for(k=0; k<columnas;k++) {
        for(i=0; i<filas;i++) {
            for(j=k; j<columnaaumentada;j++) {
                if((i==j && k==j)) {
                    auxiliar = *((aumentada+i*columnaaumentada) + j);
                    principal =i;
                    calcular =1;
                }
                else if(j==principal) {
                    auxiliar = *((aumentada+i*columnaaumentada) + j);
                }

                if(i==principal && calcular==1) {
                    *((aumentada+i*columnaaumentada) + j) = *((aumentada+i*columnaaumentada) + j)/auxiliar;
                }
                else if(*((aumentada+principal*columnaaumentada) + principal)==1 && calcular==1){
                    *((aumentada+i*columnaaumentada) + j) = funcion(auxiliar,*((aumentada+principal*columnaaumentada) + j),*((aumentada+i*columnaaumentada) + j));
                }
            }
        }
          if(j>principal) {
              for(l=0; l<principal;l++) {
                    for(m=principal; m<columnaaumentada;m++) {
                        if(m==principal) {
                             auxiliar = *((aumentada+l*columnaaumentada) + m);
                        }
                        *((aumentada+l*columnaaumentada) + m) = funcion(auxiliar,*((aumentada+principal*columnaaumentada) + m),*((aumentada+l*columnaaumentada) + m));
                        if(*((aumentada+l*columnaaumentada) + m)!=0){*((aumentada+l*columnaaumentada) + m)=*((aumentada+l*columnaaumentada) + m)*-1;}
                    }
                }
          }
        calcular =0;
        printf("\n");
        imprimir(aumentada, filas, columnas*2);
    }

    printf("\nMatriz inversa\n");
    for(i=0; i<filas;i++) {
        for(j=0; j<columnas;j++) {
            *((inversa+i*columnas) + j) =*((aumentada+i*columnaaumentada) + j+filas);
            printf("%10f",*((inversa+i*columnas) + j));
        }
        printf("\n");
    }
}

void GaussJordan(float *arre, float *arreb,float *aumentada,float *resultante,int filas, int columnas) {
    int i,j,k=0,l=0,m,calcular=0,principal,columnaaumentada=columnas+1;
    float auxiliar=0;

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

    for(k=0; k<columnas;k++) {
        for(i=0; i<filas;i++) {
            for(j=k; j<columnaaumentada;j++) {
                if((i==j && k==j)) {
                    auxiliar = *((aumentada+i*columnaaumentada) + j);
                    principal =i;
                    calcular =1;
                }
                else if(j==principal) {
                    auxiliar = *((aumentada+i*columnaaumentada) + j);
                }

                if(i==principal && calcular==1) {
                    *((aumentada+i*columnaaumentada) + j) = *((aumentada+i*columnaaumentada) + j)/auxiliar;
                }
                else if(*((aumentada+principal*columnaaumentada) + principal)==1 && calcular==1){
                    *((aumentada+i*columnaaumentada) + j) = funcion(auxiliar,*((aumentada+principal*columnaaumentada) + j),*((aumentada+i*columnaaumentada) + j));
                }
            }
        }
          if(j>principal) {
              for(l=0; l<principal;l++) {
                    for(m=principal; m<columnaaumentada;m++) {
                        if(m==principal) {
                             auxiliar = *((aumentada+l*columnaaumentada) + m);
                        }
                        *((aumentada+l*columnaaumentada) + m) = funcion(auxiliar,*((aumentada+principal*columnaaumentada) + m),*((aumentada+l*columnaaumentada) + m));
                        if(*((aumentada+l*columnaaumentada) + m)!=0){*((aumentada+l*columnaaumentada) + m)=*((aumentada+l*columnaaumentada) + m)*-1;}
                    }
                }
          }
        calcular =0;
        printf("\n");
        imprimir(aumentada, filas, columnas+1);
    }

        for(i=0; i<filas;i++) {
            for(j=0; j<1;j++) {
               *(resultante+i)= *((aumentada+i*columnaaumentada) + j+filas);
            }
            printf("\n x%d = %f",i,*(resultante+i));
        }
}

