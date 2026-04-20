#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void MostrarPersonas(char *ArreglodeNombres[5]);
int BuscarNombre(char *ArreglodeNombres[5], char *palabra);
int main(){
    char *ArregloDeNombres[5];
    char buff[100], palabra[50];
    for(int i = 0;i<5;i++){
        gets(buff);
        int cantidadDeCaracteres = strlen(buff);
        ArregloDeNombres[i] = (char *)malloc(sizeof(char) * cantidadDeCaracteres);
        strcpy(ArregloDeNombres[i],buff);
    }
    MostrarPersonas(ArregloDeNombres);
    printf("Ingrese la palabra clave: \n");
    gets(palabra);
    int encontrada = BuscarNombre(ArregloDeNombres,palabra);
    if(encontrada != -1){
        printf("%s", ArregloDeNombres[encontrada]);
    }
    else{
        printf("No se encontro coincidencias \n");
    }
    return 0;
}
void MostrarPersonas(char *ArreglodeNombres[5]){
    for(int i=0; i<5; i++){
        printf("%s \n", ArreglodeNombres[i]);
    }
}
int BuscarNombre(char *ArreglodeNombres[5], char *palabra){
    for(int i = 0; i < 5; i++) {
        if (strstr(ArreglodeNombres[i], palabra) != NULL) {
            return i;
        }
    }
    return -1;
}