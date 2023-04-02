#include <stdio.h>
#include <math.h>

int main(){
    int num, aux, cont, cinco, tres;
    tres = 0;
    cinco = 0;
    aux = 0;
    printf("ingrese el numero\n");
    scanf("%d", &num);
    if (fabs(num) > 99)
    {
    while (num != 0)
    {
        cont = num%10;
        if (fabs(cont) == 3)
        {
            tres++;
        }
        if (fabs(cont) == 5)
        {
            cinco++;
        }
        aux = aux*10 + cont;
        num = num/10;
    }
    printf("\nnumero invertido: %d\n cantidad de cincos: %d\n cantidad de tres: %d \n", aux, cinco, tres);
    }
    else
    {
        printf("el numero tiene que tener mas de 3 digitos\n");
    }
    system("pause");
    return 0;
}