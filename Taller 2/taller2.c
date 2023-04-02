#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void card();
void ganado(char name_color[], int fl, int ca);
void tarjeta_mayor();
void tarjeta_menor();
void decision();
void dinero();
void rounds();

int i, v, perc, perf, ganf, ganc,  puntf,  puntc,  puntwhite,  puntblue,  puntpink, puntf_finp, puntf_finb, puntf_finw, puntc_finp, puntc_finb, puntc_finw, white, blue, pink, finalf, finalc, p, f, c, fl, ca, co, caif, caic, pf, n, r, roundsf, roundsc;
float premio;
char tarjeta, ganador, g[11], g_white[11], g_blue[11], g_pink[11];
bool SD, UD, MD, floyd, canelo;

int main(){

    ganf = ganc = puntf = puntc = puntwhite = puntblue = puntpink = n = roundsf = roundsc = r = 0;

    while (puntwhite == 0 || puntblue == 0 || puntpink == 0)
    {
        printf("\ninserte color de su tarjeta:\n White/Blanco: 'w'\n Blue/Azul: 'b'\n Pink/Rosa: 'p'\n");
        scanf(" %c", &tarjeta);

        switch (tarjeta)
        {
        case 'w':
            card();
            puntwhite = p;
            puntf_finw = f;
            puntc_finw = c;
            while (v != 12)
            {
                g_white[v] = g[v];
                v++;
            }
            break;

         case 'b':
            card();
            puntblue = p;
            puntf_finb = f;
            puntc_finb = c;
            while (v != 12)
            {
               g_blue[v] = g[v];
               v++; 
            }
            break;
            
        case 'p':
            card();
            puntpink = p;
            puntf_finp = f;
            puntc_finp = c;
            while (v != 12)
            {
                g_pink[v] = g[v];
                v++;
            }
            break;

        default:

            printf("\neso no es respuesta\n");

            break;
        }

        puntf = puntc = ganf = perf = perc = ganc = p = f = c = v = 0;

    }

    ganado("Blanco", puntf_finw, puntc_finw);
    white = co;
    ganado("Azul", puntf_finb, puntc_finb);
    blue = co;
    ganado("Rosa", puntf_finp, puntc_finp);
    pink = co;

    decision();
    tarjeta_mayor();
    tarjeta_menor();
    rounds();
    dinero();
    
    system("pause");
    return 0;
}


//Funciones


void card()
{
    for (i = 1; i < 13; i++)
    {
      printf("\nInserte ganador del round %d:\n Floyd: 'f'\n Canelo: 'c'\n Empate: 'e'\n", i);
        scanf(" %c", &ganador);

    switch (ganador)
    {
    case 'f':
    g[n] = ganador;
        puntf = puntf + 10;
        puntc = puntc + 9;
        ganf++;
        perc++;
        n++;
        break;
    case 'c':
    g[n] = ganador;
        puntf = puntf + 9;
        puntc = puntc + 10;
        ganc++;
        perf++;
        n++;
        break;
    case 'e':
    g[n] = ganador;
        puntf = puntf + 10;
        puntc = puntc + 10;
        ganf++;
        ganc++;
        n++;
        break;
    default:

        printf("\neso no es respuesta\n");

        break;
    }


    printf("\ncuantas veces cayo Floyd?\n");
        scanf(" %d", &caif);
        if (caif != 0)
        {
            puntf = puntf - 2*caif;
        }
        
printf("\ncuantas veces cayo Canelo?\n");
        scanf(" %d", &caic);
        if (caic != 0)
        {
            puntc = puntc - 2*caic;
        }

    if (puntf > puntc)
            {
                p = puntf;
            }
            else
            {
                p = puntc;
            }
            f = puntf;
            c = puntc;

    }

    n = 0;

    printf("\nRounds ganados por Floyd: %d\n", ganf);
    printf("\nRounds perdidos por Floyd: %d\n", perf);
    printf("\nRounds ganados pot Canelo: %d\n", ganc);
    printf("\nRounds perdidos por Canelo: %d\n", perc);
}


void ganado(char name_color[], int fl, int ca)
{
    printf("\nPuntaje final del %s:\n Floyd: %d\n Canelo: %d\n", name_color, fl, ca);

    if(fl > ca){
        printf("\nEl ganador es Floyd\n");
        co = 1;
    }
    else if (fl < ca)
     {
        printf("\nEl ganador es Canelo\n");
        co = 2;
    }
    else
    {
        printf("\nSe declara un empate\n");
        co = 0;
    }

}

void tarjeta_mayor()
{
     if (puntblue > puntwhite > puntpink || puntblue > puntpink > puntwhite)
    {
        printf("\nLa tarjeta de mayor puntuacion es la azul\n");
    }
    else if (puntwhite > puntblue > puntpink || puntwhite > puntpink > puntblue)
    {
        printf("\nLa tarjeta de mayor puntuacion es la blanca\n");
    }
    else
    {
        printf("\nLa tarjeta de mayor puntuacion es la rosa\n");
    }
}

void tarjeta_menor()
{
    if (puntblue < puntwhite < puntpink || puntblue < puntpink < puntwhite)
    {
        printf("\nLa tarjeta de menor puntuacion es la azul\n");
    }
    else if (puntwhite < puntblue < puntpink || puntwhite < puntpink < puntblue)
    {
        printf("\nLa tarjeta de menor puntuacion es la blanca\n");
    }
    else
    {
        printf("\nLa tarjeta de menor puntuacion es la rosa\n");
    }
}

void decision()
{
    finalf = puntf_finp + puntf_finb + puntf_finw;
    finalc = puntc_finp + puntc_finb + puntc_finw;

    printf("\nPuntuacion final de Floyd: %d\n", finalf);
    printf("\nPuntuacion final de Canelo: %d\n", finalc);

    if (finalf > finalc)
    {
        pf = 1;
    }
    else if (finalf < finalc)
    {
        pf = 2;
    }
    else
    {
        pf = 0;
    }

    if (((white == 1 && pink == 1) || pf == 1) || ((white == 1 && blue == 1) || pf == 1) || ((blue == 1 && pink == 1) || pf == 1))
    {
        printf("\nEl ganador definitivo fue Floyd\n");
        floyd = true;
        canelo = false;
    }
    else if (((white == 2 && pink == 2) || pf == 2) || ((white == 2 && blue == 2) || pf == 2) || ((blue == 2 && pink == 2) || pf == 2))
     {
        printf("\nEl ganador definitivo fue Canelo\n");
        floyd = false;
        canelo = true;
    }
    else
    {
        printf("\nse declaro un empate como resultado final\n");
        floyd = false;
        canelo = false;
    }
    
    

    if (white == blue && pink == blue && white == pink)
    {
        printf("\nDecision de forma unanime!\n");
        SD = false; 
        UD = true; 
        MD = false;
    }
    else if ((white == blue && pf == 0) || (pink == blue && pf == 0) || (white == pink && pf == 0))
    {
        printf("\nDecision por mayoria!\n");
        SD = false; 
        UD = false; 
        MD = true;
    }
    else
    {
        printf("\nDecision Dividida!\n");
        SD = true; 
        UD = false; 
        MD = false;
    }
    
}

void rounds()
{
    
    while (r != 12)
    {
        
    if ((g_white[r] == 'f' && g_blue[r] == 'f') || (g_pink[r] == 'f' && g_blue[r] == 'f') || (g_white[r] == 'f' && g_pink[r] == 'f'))
    {
        printf("\nganador del round %d fue Floyd", r+1);
        roundsf++;
    }
    else if ((g_white[r] == 'c' && g_blue[r] == 'c') || (g_pink[r] == 'c' && g_blue[r] == 'c') || (g_white[r] == 'c' && g_pink[r] == 'c')) 
    {
        printf("\nganador del round %d fue Canelo", r+1);
        roundsc++;
    }
    else {
        printf("\nel round %d fue Empate", r+1);
    }

    r++;
    
    }  
}

void dinero()
{
    if (floyd == true)
    {
        if (SD == true)
        {
            premio = 100000 + 100000*0.05*roundsf;
        }
        else if (UD == true)
        {
            premio = 100000 + 100000*0.1*roundsf;
        }
        else 
        {
            premio = 100000 + 100000*0.15*roundsf;
        }

        printf("\nEl ganador Floyd se lleva consigo %.2f$\n", premio);

        premio = 100000 - 100000*0.4;

        printf("\nEl perdedor Canelo se lleva consigo %.2f$\n", premio);
    }
    else if (canelo == true)
    {
        if (SD == true)
        {
            premio = 100000 + 100000*0.05*roundsc;
        }
        else if (UD == true)
        {
            premio = 100000 + 100000*0.1*roundsc;
        }
        else 
        {
            premio = 100000 + 100000*0.15*roundsc;
        }

         printf("\nEl ganador Canelo se lleva consigo %.2f$\n", premio);

        premio = 100000 - 100000*0.4;

        printf("\nEl perdedor Floyd se lleva consigo %.2f$\n", premio);
    }
    else
    {
        printf("\ncomo se declaro un empate no se define el premio\n");
    }
    
}


