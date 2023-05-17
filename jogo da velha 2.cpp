#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>

int main()
{
  using namespace std;

  char jogo[3][3];
  int i, j, linha, coluna, jogador = 1, ganhou = 0, jogadas, opcao, numero_teste, k;
  i = 0;
  j = 0;
  do{
    jogador = 1;
    ganhou = 0;
    jogadas = 0;

    for (i = 0; i < 3; i++){
      for (j = 0; j < 3; j++){
        jogo[i][j] = ' ';
      }
    }
    do{
      // imprimir o jogo
      cout << endl;
      k = 0;
      for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
          k++;
          if (jogo[i][j] != 'X' && jogo[i][j] != 'O'){
            cout << k;
          }
          else{
            cout << jogo[i][j];
          }
          if (j < 2){
            cout << "  |";
          }
        }
        if (i < 2){
          cout << "\n-----------";
          cout << "\n";
        }
      }
      // ler coordenadas
      do{
        cout << "\nDigite um numero: ";
        cin >> numero_teste;
        system("cls");
        switch (numero_teste){
        case 1:
          linha = 0;
          coluna = 0;
          break;

        case 2:
          linha = 0;
          coluna = 1;
          break;

        case 3:
          linha = 0;
          coluna = 2;
          break;

        case 4:
          linha = 1;
          coluna = 0;
          break;

        case 5:
          linha = 1;
          coluna = 1;
          break;

        case 6:
          linha = 1;
          coluna = 2;
          break;

        case 7:
          linha = 2;
          coluna = 0;
          break;

        case 8:
          linha = 2;
          coluna = 1;
          break;

        case 9:
          linha = 2;
          coluna = 2;
          break;

        default:
          cout << endl;
          cout << "Invalido, tente novamente!" << endl;
          break;
        }
      }while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');
      // salvar coodernadas
      if (jogador == 1){
        jogo[linha][coluna] = 'O';
        jogador++;
      }
      else{
        jogo[linha][coluna] = 'X';
        jogador = 1;
      }
      jogadas++;
      // alguem ganhou por linha
      if (jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] == 'O' ||
          jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] == 'O' ||
          jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] == 'O'){
        cout << "Parabens! O jogador O venceu!";
        ganhou = 1;
      }
      if (jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' ||
          jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X' ||
          jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X'){
        cout << "Parabens! O jogador X venceu!";
        ganhou = 1;
      }
      // alguem ganhou por coluna
      if (jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O' ||
          jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] == 'O' ||
          jogo[0][2] == 'O' && jogo[1][2] == 'O' && jogo[2][2] == 'O'){
        cout << "Parabens! O jogador O venceu!";
        ganhou = 1;
      }
      if (jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||
          jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X' ||
          jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X'){
        cout << "Parabens! O jogador X venceu!";
        ganhou = 1;
      }
      // alguem ganhou na diagonal principal
      if (jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O'){
        cout << "\nParabens! o jogador O venceu!";
        ganhou = 1;
      }
      if (jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X'){
        cout << "\nParabens! O jogador X venceu!";
        ganhou = 1;
      }
      // alguem ganhou na diagonal sencundaria
      if (jogo[0][2] == 'O' && jogo[1][1] == 'O' && jogo[2][0] == 'O'){
        cout << "\nParabens! O jogador O venceu!";
        ganhou = 1;
      }
      if (jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X'){
        cout << "\nParabens! O jogador X venceu!";
        ganhou = 1;
      }
    }while (ganhou == 0 && jogadas < 9);
    if (ganhou == 0){
      cout << "\nO jogo finalizou sem ganhador!";
      cout << "\nDigite 1 para jogar novamente: ";
      cin >> opcao;
    }
    if (ganhou == 1){
      cout << "\nDigite 1 para jogar novamente: ";
      cin >> opcao;
    }
  } while (opcao == 1);
  return 0;
}
