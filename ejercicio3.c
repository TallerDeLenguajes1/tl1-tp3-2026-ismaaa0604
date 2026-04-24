#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct Producto {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
};
struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    struct Producto *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
};
float costoTotal(struct Producto prod);
int main(){
    int cantidad;
    char nombre[100];
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    srand(time(NULL));
    printf("Ingrese la cantidad de clientes(hasta 5): \n");
    scanf("%d", &cantidad);
    struct Cliente * cliente = malloc(sizeof(struct Cliente)* cantidad);
    for (int i = 0; i< cantidad; i++){
        cliente[i].ClienteID = i;
        printf("Ingrese el nombre: \n");
        fgets(nombre, sizeof(nombre), stdin);
        nombre[strcspn(nombre, "\n")] = '\0';
        int cantidadDeCaracteres = strlen(nombre);
        cliente[i].NombreCliente = (char *)malloc(sizeof(char) * (cantidadDeCaracteres+1));
        strcpy(cliente[i].NombreCliente,nombre);
        cliente[i].CantidadProductosAPedir = 1 + rand()%(5-1+1);
        cliente[i].Productos = malloc(sizeof(struct Producto)* cliente[i].CantidadProductosAPedir);
        for(int j=0; j<cliente[i].CantidadProductosAPedir; j++){
            int aleatorio = rand()%5;
           cliente[i].Productos[j].ProductoID = j;
           cliente[i].Productos[j].Cantidad = 1+ rand()%(10-1+1);
           cliente[i].Productos[j].PrecioUnitario = 10 + rand()%(100-10+1);
           cliente[i].Productos[j].TipoProducto = TiposProductos[aleatorio];
           float costoT = costoTotal(cliente[i].Productos[j]);
           //printf("El costo total de este producto es: %f \n", costoT); 
        }
    }
    for (int i = 0; i < cantidad; i++){
        float totalApagar = 0;
        printf("El ID del cliente es: %d \n", cliente[i].ClienteID);
        printf("El nombre del cliente es: %s \n",cliente[i].NombreCliente);
        printf("La cantidad de productos a pedir por este cliente es: %d \n", cliente[i].CantidadProductosAPedir);
        for(int j=0; j<cliente[i].CantidadProductosAPedir; j++){
           printf("El ID del producto del ciente %d es: %d \n",i,cliente[i].Productos[j].ProductoID);
           printf("La cantidad de este producto es: %d \n",cliente[i].Productos[j].Cantidad);
           printf("El precio unitario de este procuto es: %f \n",cliente[i].Productos[j].PrecioUnitario);
           printf("El tipo del producto es: %s \n",cliente[i].Productos[j].TipoProducto);
           float costoT = costoTotal(cliente[i].Productos[j]);
           totalApagar = totalApagar + costoT; 
        }
        printf("El costo total a pagar del cliente %d es: %f \n",i,totalApagar);
    }
    return 0;
}
float costoTotal(struct Producto prod){
    return prod.PrecioUnitario * (float)prod.Cantidad;
}