#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"

///se nao houver bike disponivel, vai pra lista de espera
//entrar, sair e editar(campo de destino)

tipoEspera *registrarEspera(tipoEspera espera[],tipoUtente utente[],int *contEspera,int contUtente)
{
    int pos = -1;
    int i;
    int opcao;
    char campus[MAXSTRING];
    int codigo;
    tipoEspera *aux;
    aux = espera;  ///add
    int esperaRealizada=0,naoDisponivel=0;
    int flag = 1;

    codigo = lerInteiro("\nIntroduza o numero de utente:",0,MAXNUMEROUTENTE);

    pos = procurarUtente(utente,codigo,contUtente);


    if(pos == -1)
    {
        printf("\nNao existe nenhum utente com esse numero");
    }
    else
    {
        for(i=0 ; i<*contEspera ; i++)
        {
            if(codigo == espera[i].codigoUtente)
            {
                //    printf("\nO utente ja se encontra na lista de espera, aguarde sua vez! ");
                flag = 0;
            }
            else
            {
                flag=1;
            }
        }

        if(flag == 0)
        {
            printf("\nO utente ja se encontra na lista de espera, aguarde sua vez! ");
        }
        else
        {
            aux = realloc(aux,(*contEspera+1)*sizeof(tipoEspera));

            if(aux == NULL)
            {
                printf("\nImpossivel alocar memoria.");
            }
            else
            {

                printf("\nInsira o campus de origem que deseja:");
                opcao = menuCampus();

                switch(opcao)
                {
                case 1:
                    strcpy(aux[*contEspera].campusOrigem,"residencias");
                    break;
                case 2:
                    strcpy(aux[*contEspera].campusOrigem,"campus 1");
                    break;
                case 3:
                    strcpy(aux[*contEspera].campusOrigem,"campus 2");
                    break;
                case 4:
                    strcpy(aux[*contEspera].campusOrigem,"campus 5");
                    break;
                }

                aux[*contEspera].dataRegistro = lerData();
                aux[*contEspera].codigoUtente = codigo;


                printf("\nInsira o campus de destino que deseja:");
                opcao = menuCampus();   ///menu


                switch(opcao)
                {
                case 1:
                    strcpy(campus,"residencias");
                    break;
                case 2:
                    strcpy(campus,"campus 1");
                    break;
                case 3:
                    strcpy(campus,"campus 2");
                    break;
                case 4:
                    strcpy(campus,"campus 5");
                    break;
                }
            }

            if(strcmp(aux[*contEspera].campusOrigem,campus)==0)
            {
                printf("Insira outro local para deixar a bicicleta");
            }
            else
            {
                (*contEspera)++;
            }
        }
    }
    return aux;
}