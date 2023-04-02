#include <stdio.h>

int main(){
    
    int num_u, num_d, div_1, div_2, i;
    printf("escribir el valor de dos numeros enteros \n");
    scanf("%d %d", &num_u, &num_d);
    printf("Num = %d Num = %d \n" ,num_u, num_d);
    div_1 = div_2 = 0;
    for(i=1;i<=((num_u/2) + 1);i++)
    {
        if (num_u%i == 0)
        {
            div_1 = div_1 + i;
        }
        
    }
    for (i=1; i<=((num_d/2) + 1); i++)
    {
        if (num_d%i == 0)
        {
            div_2 = div_2 + i;
        }
        
    }
    printf("los divisores del primer numero suman = %d \nlos del segundo suman = %d\n", div_1, div_2);
        system("pause");
        return 0;
}