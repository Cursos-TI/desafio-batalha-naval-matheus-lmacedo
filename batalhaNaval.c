#include <stdio.h>

int main()
{
     // Criação dos navios
     int navio1[3] = {3, 3, 3};
     int navio2[4] = {3, 3, 3, 3};
     int navio3[3] = {3, 3, 3};
     int navio4[4] = {3, 3, 3, 3};

     // Criação das habilidades
     printf("Cone: \n");
     // Cone
     int cone[3][5] = {0};
     for (int i = 0; i < 3; i++)
     {
          for (int j = 0; j < 5; j++)
          {
               if (j >= 2 - i && j <= 2 + i)
               {
                    cone[i][j] = 1;
               }
               printf("%3d", cone[i][j]);
          }
          printf("\n");
     }

     // Cruz
     printf("Cruz: \n");
     int cruz[3][5] = {0};
     for (int i = 0; i < 3; i++)
     {
          cruz[i][2] = 1;
          for (int j = 0; j < 5; j++)
          {
               cruz[1][j] = 1;
               printf("%3d", cruz[i][j]);
          }
          printf("\n");
     }

     // Octaedro
     printf("Octaedro: \n");
     int octaedro[3][5] = {0};
     for (int i = 0; i < 3; i++)
     {
          for (int j = 0; j < 5; j++)
          {
               if (j == 2)
               {
                    octaedro[i][j] = 1;
               }

               if (i == 1 && (j == 1 || j == 3))
               {
                    octaedro[i][j] = 1;
               }

               printf("%3d", octaedro[i][j]);
          }
          printf("\n");
     }

     // Criação do tabuleiro 10x10 e inicializando com 0
     int tabuleiro[10][10] = {0};

     // Posições de inicio dos navios e habilidades pelo índice
     int navio1linhaDeInicio = 0;
     int navio1colunaDeInicio = 0;

     int navio2linhaDeInicio = 6;
     int navio2colunaDeInicio = 0;

     int navio3linhaDeInicio = 5;
     int navio3colunaDeInicio = 9;

     int navio4linhaDeInicio = 0;
     int navio4colunaDeInicio = 6;

     int coneLinhaDeInicio = 0;
     int coneColunaDeInicio = 1;

     int cruzLinhaDeInicio = 3;
     int cruzColunaDeInicio = 3;

     int octaedroLinhaDeInicio = 7;
     int octaedroColunaDeInicio = 3;

     // Verficação das posições para evitar ultrapassagem do tabuleiro
     if (navio1linhaDeInicio > 9 || navio1colunaDeInicio > 7 ||
         navio2linhaDeInicio > 6 || navio2colunaDeInicio > 9 ||
         navio3linhaDeInicio > 9 || navio3colunaDeInicio < 2 ||
         navio4linhaDeInicio > 6 || navio4colunaDeInicio > 9)
     {
          printf("Número inválido para o tamanho do navio!");
          return -1;
     }

     // Inserção das posições dos navios no tabuleiro
     // Navio 1 (horizontal)
     for (int i = 0; i < 3; i++)
     {
          tabuleiro[navio1linhaDeInicio][navio1colunaDeInicio + i] = navio1[i];
     }

     // Navio 2 (vertical)
     for (int i = 0; i < 4; i++)
     {
          tabuleiro[navio2linhaDeInicio + i][navio2colunaDeInicio] = navio2[i];
     }

     // Navio 3 (diagonal, descendo)
     for (int i = 0; i < 3; i++)
     {
          tabuleiro[navio3linhaDeInicio + i][navio3colunaDeInicio - i] = navio3[i];
     }

     // Navio 4 (diagonal, subindo)
     for (int i = 0; i < 4; i++)
     {
          tabuleiro[navio4linhaDeInicio + i][navio4colunaDeInicio + i] = navio4[i];
     }

     // Cone
     for (int i = 0; i < 3; i++)
     {
          for (int j = 0; j < 5; j++)
          {
               if (cone[i][j] == 1)
               {
                    tabuleiro[coneLinhaDeInicio + i][coneColunaDeInicio + j] = cone[i][j];
               }
          }
     }

     // Cruz
     for (int i = 0; i < 3; i++)
     {
          for (int j = 0; j < 5; j++)
          {
               if (cruz[i][j] == 1)
               {
                    tabuleiro[cruzLinhaDeInicio + i][cruzColunaDeInicio + j] = cruz[i][j];
               }
          }
     }

     // Octaedro
     for (int i = 0; i < 3; i++)
     {
          for (int j = 0; j < 5; j++)
          {
               if (octaedro[i][j] == 1)
               {
                    tabuleiro[octaedroLinhaDeInicio + i][octaedroColunaDeInicio + j] = octaedro[i][j];
               }
          }
     }

     // Impressão do tabuleiro no console
     printf("Tabuleiro 10x10:\n");
     for (int i = 0; i < 10; i++)
     {
          for (int j = 0; j < 10; j++)
          {
               printf("%3d", tabuleiro[i][j]);
          }
          printf("\n");
     }

     return 0;
}