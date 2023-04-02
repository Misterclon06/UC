#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){
    int clientes, cliente_des, record, gif, par, inpar, cedula, productos, i, n, resp, resp2;
    char color;
    float precio, precio_aux, precio_total, porc_client, precio_desc, precio_sin_desc, precio_desco;
    bool etiqueta, num_producto, rango; 

    gif = 0;
    inpar = 0;
    par = 0;
    clientes = 0;
    cliente_des = 0;
    productos = 0;
    precio_sin_desc = 0;
    precio_desc = 0;
    precio_desco = 0;
    n = 1;
    i = 1;

    while (n != 0)
    {

    while (i != 0)
    {   
        printf("inserte etiqueta el producto:\n(ejemplo: M)\n");
        scanf(" %c", &color);
        if (color == 'M' || color == 'm' || color == 'A' || color == 'a')
        {
            etiqueta = true;
        }
        else
        {
            etiqueta = false;
        }
        

        printf("ingrese precio del producto:\n");
        scanf(" %f", &precio);
        
        productos++;

        if (etiqueta == true)
        {
            precio_desc = precio_desc + precio;
        }
        else
        {
            precio_sin_desc = precio_sin_desc + precio;
        }
        

        if (productos > 3)
        {
            num_producto = true;
        }
        else
        {
            num_producto = false;
        }
        

        if (1000 <= precio_aux && precio_aux <= 5000)
        {
            rango = true;
        }
        else
        {
            rango = false;
        }
        

        if (etiqueta == true && num_producto == true && rango == true)
    {
        precio_desco = precio_desco + precio_desc*0.5;
    }

    precio_aux =  precio_sin_desc + precio_desc; 

    printf("¿Registrar nuevo producto?\n(otro numero:si 0:no)\n");
        scanf("%d", &i);

    } 

    

    if (precio_desco > 0)
    {
        cliente_des++;
        precio_aux =  precio_sin_desc + precio_desco;
        printf("ingrese cedula del cliente:\n");
    scanf("%d", &cedula);

    if (cedula%2 == 0)
    {
        precio_aux = precio_aux - precio_desc*0.05;
        par++;
    }
    else
    {
        precio_aux = precio_aux - precio_desc*0.03;
        inpar++;
    }
    }
    else
    {
        precio_aux =  precio_sin_desc + precio_desc; 
        printf("ingrese cedula del cliente:\n");
    scanf("%d", &cedula);
    }
    
    
    clientes++;
    
    
    if (record < precio_aux)
    {
        printf("HAS ROTO EL RECORD DEL MONTO MAS ALTO!!!,\n Como premio te daremos una GIF de 300$ para tu proxima compra");
        gif++;
    }
    

    record = precio_aux;


    printf("\nFactura:\n Nro. de cliente: %d\n C.I. del cliente: %d\n Nro. de productos: %d\n Precio total: %.2f$\n\n\n  Gracias por su compra, Vuelva pronto!\n\n\n", clientes, cedula, productos, precio_aux);

    i = 1;
    productos = 0;
    precio_sin_desc = 0;
    precio_desc = 0;
    precio_desco = 0;
    
    printf("¿Registrar nueva factura?\n (otro numero: si, 0: no)\n");
    scanf("%d", &n);

    }

    porc_client = (cliente_des*100)/clientes;
    
    printf("Registro de ventas:\n Porcentaje de cliente ganadores de descuento: %f \n cantidad de ganadores de GIF: %d\n cantidad de descuento 'par': %d\ncantidad de descuento 'impar': %d\n", porc_client, gif, par, inpar);

    system("pause");

    return 0;

}