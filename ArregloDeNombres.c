#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void MostrarPersonas(char ArreglodeNombres[5]);
int main(){
    char *ArregloDeNombres[5];
    char *buff[100];
    for(int i = 0;i<5;i++){
        scanf("%s", &buff);
        int cantidadDeCaracteres = strlen(buff);
        ArregloDeNombres[i] = (char *)malloc(sizeof(char) * cantidadDeCaracteres);
        strcpy(ArregloDeNombres[i],buff);
    }
    MostrarPersonas(&ArregloDeNombres);
    return 0;
}
void MostrarPersonas(char ArreglodeNombres[]){
    for(int i=0; i<5; i++){
        printf("%s \n", ArregloDeNombres[i]);
    }
}