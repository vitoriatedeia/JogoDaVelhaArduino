7function main() {
    // Criar o tabuleiro e jogadores, zerar as variáveis
    // 
    // 0: Posição vazia
    // 1: Jogada na posição do jogador 1
    // 2: Jogada na posição do jogador 2
    var haVencedor;
    var tabuleiro = createArray(9);

    // Limpar/zerar o tabuleiro
    var index;

    for (index = 0; index <= 8; index++) {
        tabuleiro[index] = 0;
    }
    var jogador1;

    jogador1 = "Jogador1";
    var jogador2;

    jogador2 = "Jogador2";
    var jogada;
    var jogadorDaVez;

    jogadorDaVez = 1;
    var validarTabuleiro;

    // Iniciar o jogo, definir quem joga primeiro.
    var linha;
    var coluna;
    var velha;

    velha = 1;

    // Anotar/Registrar a jogada do primeiro jogador.
    do {
        window.alert(tabuleiro[0].ToString() + tabuleiro[1] + tabuleiro[2]);
        window.alert(tabuleiro[3].ToString() + tabuleiro[4] + tabuleiro[5]);
        window.alert(tabuleiro[6].ToString() + tabuleiro[7] + tabuleiro[8]);
        jogada = "";
        window.alert("Digite a posição da sua peça, JOGADOR" + jogadorDaVez);
        jogada = window.prompt('Enter a value for jogada');
        if (validaPosicao(jogada)) {

            // Simula a função Serial.parseint() do Arduino
            linha = parseInt(jogada.charAt(0));
            coluna = parseInt(jogada.charAt(2));
            window.alert("Linha: " + linha + ";Coluna: " + coluna);

            // Verificar se a posição 'jogada' é válida.
            // Verificar jogada vencedora nas linhas
            // Converter a jogada texto em dois inteiros linha e coluna.
            if (tabuleiro[3 * linha + coluna] == 0) {
                tabuleiro[3 * linha + coluna] = jogadorDaVez;

                // Verifica se há jogador na linha
                validarTabuleiro = validaTabuleiro(jogadorDaVez, tabuleiro);
                window.alert("validarTabuleiro: " + validarTabuleiro);

                // Troca o jogador.
                if (validarTabuleiro != 2) {
                    if (jogadorDaVez == 1) {
                        jogadorDaVez = 2;
                    } else {
                        jogadorDaVez = 1;
                    }
                }
            } else {
                window.alert("Posição ocupada, jogue novamente em outra posição!");

                // Informar ao Jogador 1 que a posição está preenchida, é inválida e ele precisa informar uma posição válida.
            }

            // Verificar o tabuleiro, se houver vencedor ou empate, finalizar o jogo.
            velha = velha + 1;
        } else {
            window.alert("ENTRADA INVÁLIDA");
        }
    } while (validarTabuleiro == 0 && velha <= 9);
    if (validarTabuleiro == 2) {
        window.alert("Parabéns por sua vitória, jogador" + jogadorDaVez);
    } else {
        window.alert("VELHA!!!");
    }

    // Verificar o tabuleiro, se houver ganhador ou empate, finalizar o jogo
}

function toFloat(texto) {
    var resultado;

    resultado = "";
    var convertido;

    convertido = "";
    var i;

    for (i = 0; i <= texto.length() - 1; i++) {
        if (texto.charAt(i) == "0" || texto.charAt(i) == "1" || texto.charAt(i) == "2" || texto.charAt(i) == "3" || texto.charAt(i) == "4" || texto.charAt(i) == "5" || texto.charAt(i) == "6" || texto.charAt(i) == "7" || texto.charAt(i) == "8" || texto.charAt(i) == "9" || texto.charAt(i) == "") {
            convertido = convertido + texto.charAt(i);
            if (texto.charAt(i) == ",") {
                convertido = convertido + ".";
            } else {
                convertido = convertido + texto.charAt(i);
            }
        }
    }
    resultado = convertido;
    
    return resultado;
}

function validaPosicao(entrada) {
    var entradaValida;

    entradaValida = false;
    if (entrada.length() == 3) {
        if (entrada.charAt(0) == "0" || entrada.charAt(0) == "1" || entrada.charAt(0) == "2") {
            if (entrada.charAt(2) == "0" || entrada.charAt(2) == "1" || entrada.charAt(2) == "2") {
                entradaValida = true;
            }
        }
    }
    
    return entradaValida;
}

function validaTabuleiro(jogadorDaVez, tabuleiro) {
    var resultado;

    resultado = 0;
    if (tabuleiro[0] == jogadorDaVez && tabuleiro[1] == jogadorDaVez && tabuleiro[2] == jogadorDaVez || tabuleiro[3] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[5] == jogadorDaVez || tabuleiro[6] == jogadorDaVez && tabuleiro[7] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
        resultado = 2;
    } else {

        // Verifica se há jogador na coluna
        if (tabuleiro[0] == jogadorDaVez && tabuleiro[3] == jogadorDaVez && tabuleiro[6] == jogadorDaVez || tabuleiro[1] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[7] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[5] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
            resultado = 2;
        } else {

            // Verifica se há jogador na diagonal
            if (tabuleiro[0] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[8] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[6] == jogadorDaVez) {
                resultado = 2;
            }
        }
    }
    
    return resultado;
}
