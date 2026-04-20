#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void MostrarPersonas(char *ArreglodeNombres[5]);
void BuscarNombre(char *ArreglodeNombres[5], int ID);
int main(){
    char *ArregloDeNombres[5];
    char buff[100];
    for(int i = 0;i<5;i++){
        printf("Ingrese el nombre: \n");
        gets(buff);
        int cantidadDeCaracteres = strlen(buff);
        ArregloDeNombres[i] = (char *)malloc(sizeof(char) * (cantidadDeCaracteres+1));
        strcpy(ArregloDeNombres[i],buff);
    }
    MostrarPersonas(ArregloDeNombres);
    BuscarNombre(ArregloDeNombres, 0);
    for(int i=0; i<5;i++){
        free(ArregloDeNombres[i]);
    }
    return 0;
}
void MostrarPersonas(char *ArreglodeNombres[5]){
    for(int i=0; i<5; i++){
        printf("%s \n", ArreglodeNombres[i]);
    }
}
void BuscarNombre(char *ArreglodeNombres[5], int ID){
    if(ID>=0 && ID<=4){
        printf("%s", ArreglodeNombres[ID]);
    }
    else{
        printf("No se encontro el valor buscado");
    }

}

