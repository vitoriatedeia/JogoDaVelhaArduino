//Criar o tabuleiro e jogadores, cirar as variáveis
//
//0: Posição vazia
//1: jogada na posição do jogador 1
//2: jogada a posição do jogador 2

int linha;
int coluna;
int velha;
bool haVencedor = false;
String jogador1 = "Jogador1";
String jogador2 = "Jogador2";
int jogadorDaVez = 1;
int tabuleiro[3][3];
int index;
String jogada;

//Função de reiniciar o jogo (tabuleiro)
void reiniciarJogo(int jogadorDaVez, int tabuleiro[3][3], int velha, bool haVencedor) {

  velha = 0;
  jogadorDaVez = 1;
  haVencedor = false;
  for (int linha = 0; linha <= 2; linha++) {
    for (int coluna = 0; coluna <= 2; coluna++) {
      tabuleiro[linha][coluna] = 0;
    }
  }
}

//Função de imprimir o tabuleiro quando reiniciar jogo
void imprimirTabuleiro(int tabuleiro[3][3]) {

  for (int linha = 0; linha <= 2; linha++) {
    if (linha == 1 || linha == 2) {
      Serial.println("");
    }
    for (int coluna = 0; coluna <= 2; coluna++) {
      Serial.print(tabuleiro[linha][coluna]);
    }
  }

  Serial.println("");
  Serial.print("Digite sua jogada jogador");
  Serial.println(jogadorDaVez);
}
// Função de validar a jogada
bool validaJogada(int linha, int coluna) {
  if (linha == 0 || linha == 1 || linha == 2) {
    if (coluna == 0 || coluna == 1 || coluna == 2) {
      return true;
    }
  }
  return false;
};

//Função de validar posição
bool validaPosicao(int tabuleiro[3][3], int linha, int coluna) {

  if (tabuleiro[linha][coluna] == 0) {
    return true;
  } else {
    return false;
  }
};

void setup() {

  Serial.begin(9600);
  reiniciarJogo(jogadorDaVez, tabuleiro, velha, haVencedor);
  imprimirTabuleiro(tabuleiro);
}

void loop() {


  do {

    while (!Serial.available())
      ;

    jogada = Serial.readString();
    linha = jogada.substring(0, 1).toInt();
    coluna = jogada.substring(2, 3).toInt();

    Serial.println(linha);
    Serial.println(coluna);



    if (validaJogada(linha, coluna)) {
      if (validaPosicao(tabuleiro, linha, coluna)) {
        Serial.println("Jogada Valida");

        tabuleiro[linha][coluna] = jogadorDaVez;

        // Verifica se há vencedor na linha
        if ((tabuleiro[0][0] == jogadorDaVez && tabuleiro[0][1] == jogadorDaVez && tabuleiro[0][2] == jogadorDaVez) || (tabuleiro[1][0] == jogadorDaVez && tabuleiro[1][1] == jogadorDaVez && tabuleiro[1][2] == jogadorDaVez) || (jogadorDaVez && tabuleiro[2][0] == jogadorDaVez && tabuleiro[2][1] == jogadorDaVez && tabuleiro[2][2] == jogadorDaVez)) {
          Serial.println("Ha um VENCEDOR LINHA!!");
          haVencedor = true;

          //Verifica se há vencedor na coluna
        } else if ((tabuleiro[0][0] == jogadorDaVez && tabuleiro[1][0] == jogadorDaVez && tabuleiro[2][0] == jogadorDaVez) || (tabuleiro[0][1] == jogadorDaVez && tabuleiro[1][1] == jogadorDaVez && tabuleiro[2][1] == jogadorDaVez) || (tabuleiro[0][2] == jogadorDaVez && tabuleiro[1][2] == jogadorDaVez && tabuleiro[2][2] == jogadorDaVez)) {
          haVencedor = true;
          Serial.println("Ha um VENCEDOR COLUNA!!");


          //Verifica se há vencedor na diagonal
        } else if ((tabuleiro[0][0] == jogadorDaVez && tabuleiro[1][1] == jogadorDaVez && tabuleiro[2][2] == jogadorDaVez) || (tabuleiro[0][2] == jogadorDaVez && tabuleiro[1][1] == jogadorDaVez && tabuleiro[2][0] == jogadorDaVez)) {
          haVencedor = true;
          Serial.println("Ha um VENCEDOR DIAGONAL!!");

        } else {


          for (int linha = 0; linha <= 2; linha++) {
            if (linha == 1 || linha == 2) {
              Serial.println("");
            }
            for (int coluna = 0; coluna <= 2; coluna++) {
              Serial.print(tabuleiro[linha][coluna]);
            }
          }
          if (jogadorDaVez == 1) {
            jogadorDaVez = 2;

          } else {
            jogadorDaVez = 1;
          }
          velha = velha + 1;
          Serial.println("");
          Serial.print("Valor da variavel velha: ");
          Serial.println(velha);

          //Pede para o jogador da vez digitar a sua jogada
          Serial.println("");
          Serial.print("Digite sua jogada jogador");
          Serial.println(jogadorDaVez);
        }

        //Mostra que a posição está ocupada e pede para o jogador da vez digitar sua jogada novamente
      } else {
        Serial.println("Posicao ocupada");
        Serial.print("Digite sua jogada novamente jogador");
        Serial.println(jogadorDaVez);
      }
      //Diz que a jogada está invalida e pede para o jogador da vez digitar sua jogada novamente
    } else {
      Serial.println("Jogada Invalida");
      Serial.print("Digite sua jogada novamente jogador");
      Serial.println(jogadorDaVez);
    }

  } while (!haVencedor && velha < 9);
  // Diz parabéns pela vitória do jogador da vez
  if (haVencedor) {
    Serial.println("Parabéns por sua vitória");
    Serial.println(jogadorDaVez);
    //Depois de 5 segundos, reinicia o jogo e imprime o tabuleiro
    delay(5000);
    reiniciarJogo(jogadorDaVez, tabuleiro, velha, haVencedor);
    imprimirTabuleiro(tabuleiro);
  } else {
    Serial.println("Deu velha!!");
    delay(5000);
    reiniciarJogo(jogadorDaVez, tabuleiro, velha, haVencedor);
    imprimirTabuleiro(tabuleiro);
  }
}
