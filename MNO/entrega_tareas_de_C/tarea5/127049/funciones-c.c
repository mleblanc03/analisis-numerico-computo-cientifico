#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
//definiciones de las matrices sin inicializar
static int i=0,j=0, k=0;
static double **matriz1;
static double **matriz2;
static double **matriz_resultado;

//inicializamos y rellenamos las matrices usando malloc

void modificacion1_c(void){
    size_t rowl1, rowl2, rowl3, coll1, coll2, coll3;
    rowl1 = NUM_REN_MAT1 * sizeof(double*);
    rowl2 = NUM_REN_MAT2 * sizeof(double*);
    rowl3 = NUM_REN_MAT1 * sizeof(double*);
    coll1 = NUM_COL_MAT1  * sizeof(double);
    coll2 = NUM_COL_MAT2  * sizeof(double);
    coll3 = NUM_COL_MAT2  * sizeof(double);

    matriz1 = malloc(rowl1);
    matriz2 = malloc(rowl2);
    matriz_resultado = malloc(rowl3);

    **matriz1 = 0;
    *(*(matriz1)+1) = 1.5;
    *(*(matriz1+1)) = 4;
    *(*(matriz1+1)+1) = -5;
    *(*(matriz1+2)) = -1;
    *(*(matriz1+2)+1) = 2.5;
    **matriz2 = 1;
    *(*(matriz2)+1) = 0;
    *(*(matriz2)+2) = 0;
    *(*(matriz2+1)) = 0;
    *(*(matriz2+1)+1) = -1;
    *(*(matriz2+1)+2) = 1;
}


void imprime_matrices(void){
	printf("Matriz1\n");
		for(i=0;i<NUM_REN_MAT1;i++){ //el nombre: NUM_REN_MAT1 está definido en "definiciones.h"
			for(j=0;j<NUM_COL_MAT1;j++){
				if(j<NUM_COL_MAT1-1)
				printf("matriz1[%d][%d]=%4.2f\t",i,j,matriz1[i][j]);
				else
				printf("matriz1[%d][%d]=%4.2f\n",i,j,matriz1[i][j]);
			}
		}
	printf("\n");
	printf("Matriz2\n");
		for(i=0;i<NUM_REN_MAT2;i++){
			for(j=0;j<NUM_COL_MAT2;j++){
				if(j<NUM_COL_MAT2-1)
				printf("matriz2[%d][%d]=%4.2f\t",i,j,matriz2[i][j]);
				else
				printf("matriz2[%d][%d]=%4.2f\n",i,j,matriz2[i][j]);
			}
		}
	printf("\n");
}

void imprime_matriz_resultado(void){
	printf("Matriz resultado\n");
		for(i=0;i<NUM_REN_MAT1;i++){
			for(j=0;j<NUM_COL_MAT2;j++){
				if(j<NUM_COL_MAT2-1)
				printf("matriz_res[%d][%d]=%4.2f\t",i,j,matriz_resultado[i][j]);
				else
				printf("matriz_res[%d][%d]=%4.2f\n",i,j,matriz_resultado[i][j]);
			}
		}

	printf("\n");

}

void multiplica_matrices(void){
	for(i=0;i<NUM_REN_MAT1;i++){
		for(k=0;k<NUM_COL_MAT2;k++){
	 		matriz_resultado[i][k]=0;
 			for(j=0;j<NUM_COL_MAT1;j++)
  				matriz_resultado[i][k]=matriz_resultado[i][k]+matriz1[i][j]*matriz2[j][k];
		}
	}
}

void modificacion2_c(void){
  free(matriz1);
  free(matriz2);
  free(matriz_resultado);
}  
