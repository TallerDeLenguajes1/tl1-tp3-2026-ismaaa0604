#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void MostrarPersonas(char *ArreglodeNombres[5]);
void BuscarNombrePorId(char *ArreglodeNombres[5], int ID);
int BuscarNombrePorPalabra(char *ArreglodeNombres[5], char *palabra);
int main(){
    char *ArregloDeNombres[5];
    char buff[100], palabra[50];
    for(int i = 0;i<5;i++){
        printf("Ingrese el nombre: \n");
        gets(buff);
        int cantidadDeCaracteres = strlen(buff);
        ArregloDeNombres[i] = (char *)malloc(sizeof(char) * (cantidadDeCaracteres+1));
        strcpy(ArregloDeNombres[i],buff);
    }
    MostrarPersonas(ArregloDeNombres);
    BuscarNombrePorId(ArregloDeNombres, 0);
    printf("Ingrese la palabra clave: \n");
    gets(palabra);
    int encontrada = BuscarNombrePorPalabra(ArregloDeNombres,palabra);
    if(encontrada != -1){
        printf("%s", ArregloDeNombres[encontrada]);
    }
    else{
        printf("No se encontro coincidencias \n");
    }
    for(int i=0; i<5; i++){
        free(ArregloDeNombres[i]);
    }
    return 0;
}
void MostrarPersonas(char *ArreglodeNombres[5]){
    for(int i=0; i<5; i++){
        printf("%s \n", ArreglodeNombres[i]);
    }
}
void BuscarNombrePorId(char *ArreglodeNombres[5], int ID){
    if(ID>=0 && ID<=4){
        printf("%s", ArreglodeNombres[ID]);
    }
    else{
        printf("No se encontro el valor buscado");
    }

}
int BuscarNombrePorPalabra(char *ArreglodeNombres[5], char *palabra){
    for(int i = 0; i < 5; i++) {
        if (strstr(ArreglodeNombres[i], palabra) != NULL) {
            return i;
        }
    }
    return -1;
}