#include <iostream>
#include <string>
#include <clocale>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <limits>

struct{
    struct Node {
        int data;
        Node* next;
    };

    void insert(Node*& head, int newData) {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void printList(Node *head, bool ascending) {
        int count = 0;
        Node *current = head;
        int* dataArray = new int[count]; // Array to store node data

        // Store node data in array
        while (current != nullptr) {
            dataArray[count++] = current->data;
            current = current->next;
        }

        // Sort array
        for (int i = 0; i < count - 1; ++i) {
            for (int j = 0; j < count - i - 1; ++j) {
                if ((ascending && dataArray[j] > dataArray[j + 1]) || (!ascending && dataArray[j] < dataArray[j + 1])) {
                    // Swap
                    int temp = dataArray[j];
                    dataArray[j] = dataArray[j + 1];
                    dataArray[j + 1] = temp;
                }
            }
        }

        // Print sorted list
        std::cout << "Lista ordenada " << (ascending ? "crescente" : "decrescente") << ":\n";
        for (int i = 0; i < count; ++i) {
            std::cout << "Pos " << i << ": " << dataArray[i] << std::endl;
        }

        delete[] dataArray; // Free dynamically allocated array
    }

    void deleteList(Node*& head) {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void removeNodeByPosition(Node*& head, int position) {
        if (head == nullptr)
            return;

        Node* temp = head;

        if (position == 0) {
            head = temp->next;
            delete temp;
            std::cout << "N� removido da posi��o " << position << "\n";
            return;
        }

        for (int i = 0; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr)
            return;

        Node* nextNode = temp->next->next;

        delete temp->next;
        temp->next = nextNode;

        std::cout << "N� removido da posi��o " << position << "\n";
    }

    int searchByValue(Node *head, int value) {
        Node *current = head;
        int position = 0;

        while (current != nullptr) {
            if (current->data == value) {
                return position;
            }
            current = current->next;
            ++position;
        }

        return -1;  // Valor n�o encontrado na lista
    }

    void clearScreen() {
        std::cout << "\033[2J\033[1;1H";
    }

    void displayMenu() {
        std::cout << "------ESTRUTURA DE DADOS------" << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "---------Menu de Lista--------" << std::endl;
        std::cout << "==============================" << std::endl << std::endl;
        std::cout << "[1] Inserir n� na lista" << std::endl;
        std::cout << "[2] Remover n� por posi��o" << std::endl;
        std::cout << "[3] Listar n�s" << std::endl;
        std::cout << "[4] Pesquisar por valor" << std::endl;
        std::cout << "[0] Encerrar Programa" << std::endl << std::endl;
        std::cout << "==============================" << std::endl << std::endl;
    }

    void printNodes(Node *head) {
        std::cout << "Lista de n�s:\n";
        int position = 0;
        Node *current = head;
        while (current != nullptr) {
            std::cout << "Pos " << position++ << ": " << current->data << std::endl;
            current = current->next;
        }
    }

    int main() {
        Node* head = nullptr;
        char choice;
        bool exitProgram = false;

        do {
            clearScreen(); // Limpa a tela antes de exibir o menu
            displayMenu(); // Exibe o menu

            std::cout << "Tecle a op��o desejada: ";
            std::cin >> choice;
            std::cout << std::endl;

            switch (choice) {
                case '1': {
                    int value;
                    std::cout << "Digite o valor do n�: ";
                    std::cin >> value;
                    insert(head, value);
                    std::cout << "N� inserido com sucesso!\n";
                    break;
                }
                case '2': {
                    int position;
                    printNodes(head); // Print updated list after removal
                    std::cout << "Digite a posi��o do n� que deseja remover: ";
                    std::cin >> position;
                    removeNodeByPosition(head, position);
                    break;
                }
                case '3': {
                    char order;
                    std::cout << "Deseja imprimir em ordem crescente ou decrescente? (C/D): ";
                    std::cin >> order;
                    bool ascending = (order == 'C' || order == 'c');
                    printList(head, ascending);
                    break;
                }
                case '4': {
                    int searchValue;
                    std::cout << "Digite o valor que deseja pesquisar na lista: ";
                    std::cin >> searchValue;
                    int foundPosition = searchByValue(head, searchValue);
                    if (foundPosition != -1) {
                        std::cout << "Valor " << searchValue << " encontrado na posi��o: " << foundPosition << std::endl;
                    } else {
                        std::cout << "Valor " << searchValue << " n�o encontrado na lista." << std::endl;
                    }
                    break;
                }
                case '0': {
                    exitProgram = true;
                    break;
                }
                default:
                    std::cout << "Op��o inv�lida! Tente novamente.\n";
            }

            std::cout << "\nPressione ENTER para continuar...";
            std::cin.ignore(); // Limpa o buffer de entrada
            std::cin.get();    // Aguarda o usu�rio pressionar ENTER

        } while (!exitProgram);

        deleteList(head);

        std::cout << "\nPrograma encerrado.\n";
        system("cls");
        return 0;
    }

}listaEncadeada;

struct {
    int main(void) {
        int matriz[5][3];
        int *Pmatriz = &matriz[0][0];

        std::setlocale(LC_ALL, "portuguese");

        std::cout << "[                           PONTEIROS                            ]";
        std::cout << "\n[                    Valores iniciais (lixo):                    ]\n==================================================================\n\n";
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << "�ndice [" << i << "][" << j << "] || Vari�vel alocada: " << *(Pmatriz + i * 3 + j) << " || Endere�o da Vari�vel: " << &matriz[i][j] << std::endl;
            }
        }

        std::cin.get();
        system("cls");

        std::cout << "\nDigite os valores para cada posicao da matriz:\n";
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << "�ndice [" << i << "][" << j << "]: ";
                std::cin >> *(*(matriz + i) + j);
                std::cin.ignore(80, '\n');
            }
        }

        std::cin.get();
        system("cls");

        std::cout << "\n[                          PONTEIROS                          ]";
        std::cout << "\n[                     Valores atualizados:                    ]\n===============================================================\n\n";
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << "�ndice [" << i << "][" << j << "] || Vari�vel alocada: " << *(Pmatriz + i * 3 + j) << " || Endere�o da Vari�vel: " << &matriz[i][j] << std::endl;
            }
        }

        std::cout << "\nTecle <ENTER> para encerrar o programa... ";
        std::cin.get();
        return 0;
    }
} ponteiroDuasDim;

struct {
    int main(void) {
        int matriz[10];
        int *Pmatriz = &matriz[0];

        std::setlocale(LC_ALL, "portuguese");

        std::cout << "[                           PONTEIROS                            ]";
        std::cout << "\n[                    Valores iniciais (lixo):                    ]\n==================================================================\n\n";
        for (int i = 0; i < 10; ++i) {
            std::cout << "�ndice [" << i << "] || Valor alocado: " << *(Pmatriz + i) << " || Endere�o da Vari�vel: " << &(matriz[i]) << std::endl;
        }

        std::cin.get();
        system("cls");

        std::cout << "\nDigite os valores para cada posicao da matriz:\n";
        for (int i = 0; i < 10; ++i) {
            std::cout << "�ndice [" << i << "]: ";
            std::cin >> *(Pmatriz + i);
            std::cin.ignore(80, '\n');
        }

        std::cin.get();
        system("cls");

        std::cout << "\n[                          PONTEIROS                          ]";
        std::cout << "\n[                     Valores atualizados:                    ]\n===============================================================\n\n";
        for (int i = 0; i < 10; ++i) {
            std::cout << "�ndice [" << i << "] || Valor alocado: " << *(Pmatriz + i) << " || Endere�o da Vari�vel: " << &(matriz[i]) << std::endl;
        }

        std::cout << "\nTecle <ENTER> para encerrar o programa... ";
        std::cin.get();
        return 0;
    }
} ponteiroVetor;

struct {
    int A;
    int *PA = &A;
    int B;
    int *PB = &B;
    int C;
    int *PC = &C;
    int D;
    int *PD = &D;
    int E;
    int *PE = &E;
    int F;
    int *PF = &F;
    int G;
    int *PG = &G;
    int H;
    int *PH = &H;
    int I;
    int *PI = &I;
    int J;
    int *PJ = &J;

    int apresentarVariaveis(void){
            std::cout << "Vari�vel A || Valor alocado: " << *PA << " || Endere�o da Vari�vel: " << &A << std::endl;
            std::cout << "Vari�vel B || Valor alocado: " << *PB << " || Endere�o da Vari�vel: " << &B << std::endl;
            std::cout << "Vari�vel C || Valor alocado: " << *PC << " || Endere�o da Vari�vel: " << &C << std::endl;
            std::cout << "Vari�vel D || Valor alocado: " << *PD << " || Endere�o da Vari�vel: " << &D << std::endl;
            std::cout << "Vari�vel E || Valor alocado: " << *PE << " || Endere�o da Vari�vel: " << &E << std::endl;
            std::cout << "Vari�vel F || Valor alocado: " << *PF << " || Endere�o da Vari�vel: " << &F << std::endl;
            std::cout << "Vari�vel G || Valor alocado: " << *PG << " || Endere�o da Vari�vel: " << &G << std::endl;
            std::cout << "Vari�vel H || Valor alocado: " << *PH << " || Endere�o da Vari�vel: " << &H << std::endl;
            std::cout << "Vari�vel I || Valor alocado: " << *PI << " || Endere�o da Vari�vel: " << &I << std::endl;
            std::cout << "Vari�vel J || Valor alocado: " << *PJ << " || Endere�o da Vari�vel: " << &J << std::endl;

        return 0;
    }

    int main(void) {
        std::setlocale(LC_ALL, "portuguese");

        std::cout << "[                           PONTEIROS                            ]";
        std::cout << "\n[                    Valores iniciais (lixo):                    ]\n==================================================================\n\n";

        apresentarVariaveis();

        std::cin.get();
        system("cls");

        std::cout << "\nDigite os valores para cada posicao da matriz:\n";

        std::cout << "Vari�vel A: "; std::cin >> *PA;
        std::cin.ignore(80, '\n');
        std::cout << "Vari�vel B: "; std::cin >> *PB;
        std::cin.ignore(80, '\n');
        std::cout << "Vari�vel C: "; std::cin >> *PC;
        std::cin.ignore(80, '\n');
        std::cout << "Vari�vel D: "; std::cin >> *PD;
        std::cin.ignore(80, '\n');
        std::cout << "Vari�vel E: "; std::cin >> *PE;
        std::cin.ignore(80, '\n');
        std::cout << "Vari�vel F: "; std::cin >> *PF;
        std::cin.ignore(80, '\n');
        std::cout << "Vari�vel G: "; std::cin >> *PG;
        std::cin.ignore(80, '\n');
        std::cout << "Vari�vel H: "; std::cin >> *PH;
        std::cin.ignore(80, '\n');
        std::cout << "Vari�vel I: "; std::cin >> *PI;
        std::cin.ignore(80, '\n');
        std::cout << "Vari�vel J: "; std::cin >> *PJ;
        std::cin.ignore(80, '\n');

        std::cin.get();
        system("cls");

        std::cout << "\n[                          PONTEIROS                          ]";
        std::cout << "\n[                     Valores atualizados:                    ]\n===============================================================\n\n";

        apresentarVariaveis();

        std::cout << "\nTecle <ENTER> para encerrar o programa... ";
        std::cin.get();
        return 0;
    }
} ponteiro;

void ponteiros(void){
    int opcao = 1;

    std::setlocale(LC_ALL, "portuguese");

    while (opcao != 0){
        system("cls");
        std::cout << "------------ESTRUTURA DE DADOS------------" << std::endl;
        std::cout << "==========================================" << std::endl;
        std::cout << "------------Menu de Ponteiross------------" << std::endl;
        std::cout << "==========================================" << std::endl << std::endl;
        std::cout << "[1] Valores e Endere�o de Vari�vel" << std::endl;
        std::cout << "[2] Valores e Endere�o de Vari�vel (Vetor)" << std::endl;
        std::cout << "[3] Valores e Endere�o de Vari�vel (Matriz\n de Duas Dimens�es)" << std::endl;
        std::cout << "[0] Voltar para o Menu Principal" << std::endl << std::endl;
        std::cout << "==========================================" << std::endl<< std::endl;
        std::cout << "Tecle a op��o desejada: ";

        std::cin >> opcao;
        std::cin.ignore(80, '\n');

        system("cls");

        switch (opcao){
            case 1: ponteiro.main(); break;
            case 2: ponteiroVetor.main(); break;
            case 3: ponteiroDuasDim.main(); break;
            case 0: std::cout << "\n**Voltando para o Menu Principal...**"; break;
            default: system("cls"); std::cerr << "\n\n**Erro: Op��o indispon�vel... Tente novamente!**" << std::endl << std::endl;
        }
        sleep(1);
        system("cls");
    }
}

//Tipo 0 ou -: �gua
//Tipo 1: Barco Player 1
//Tipo 2: Barco Player 2
//Tipo ~: Acertou a �gua
//Tipo #: Acertou o barco

struct batalhaNaval{

    std::string player1Name;
    std::string player2Name;

    const static int linhas = 10;
    const static int colunas = 10;
    const static int tipo = 2;

    // Utilizei uma matriz de tr�s dimens�es para armazenar uma tabela para apresentar
    // uma tabela para o usu�rio no �ndice 0 de tipo, e uma no �ndice 1 para armazenar
    // as posi��es escolhidas para os barcos.
    char player1Board[linhas][colunas][tipo];
    char player2Board[linhas][colunas][tipo];

    // Vari�veis para armazenar as coordenadas das posi��es dos barcos
    int posicaoLinhaIni;
    int posicaoLinhaFim;
    int posicaoColunaIni;
    int posicaoColunaFim;

    // Vari�vel para determinar se o barco ser� horizontal ou vertical
    int orientacaoBarco = -1;
    int orba = -1;

    // Total de turnos do jogo (100 jogadas para cada)
    int totalTurnos = 200;

    // Vari�veis para armazenar a coordenada onde a bomba ser� lan�ada
    int posicaoLinhaJogada;
    int posicaoColunaJogada;

    // Fun��o que ir� checar o ganhador
    bool checarGanhador(char playerBoard[linhas][colunas][tipo]) {
        int count = 0;

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (playerBoard[i][j][1] == '1') {
                    if (playerBoard[i][j][0] == '#') {
                        count++;
                    }
                }
            }
        }

        return count == 20;
    }

    // Fun��o das jogadas de cada Player
    void realizarJogada(int turno) {
        system("cls");

        if (turno % 2 == 0) {
            // Vez do jogador 1

            std::cout << "Turno do " << player1Name << ":" << std::endl;
            apresentarTabelaJogador2(player2Name);
            std::cout << "\n*Escolha uma coordenada para lan�ar uma bomba* \nLinha: ";
            std::cin >> posicaoLinhaJogada;
            std::cout << "\nColuna: ";
            std::cin >> posicaoColunaJogada;

            if (player2Board[posicaoLinhaJogada][posicaoColunaJogada][1] == '0'){
                player2Board[posicaoLinhaJogada][posicaoColunaJogada][0] = '~';
                system("cls");
                std::cout << "[   Sua bomba atingiu a �gua!!!  ]\n";
                apresentarTabelaJogador2(player2Name);
                sleep(2);

                if (checarGanhador(player2Board)) {
                    system("cls");
                    std::cout << "----------ESTRUTURA DE DADOS----------" << std::endl;
                    std::cout << "======================================" << std::endl;
                    std::cout << "-------------Batalha Naval------------" << std::endl;
                    std::cout << "======================================" << std::endl << std::endl;
                    std::cout << "Parab�ns, " << player1Name << "! \nVoc� ganhou a Batalha Naval!!! :D" << std::endl << std::endl;
                    std::cout << "======================================" << std::endl << std::endl;

                    std::cout << "[ Retornando para o Menu de Vetores e \nMatrizes... ]";
                    sleep(7);
                    menuBatalhaNaval();
                }

            } else if (player2Board[posicaoLinhaJogada][posicaoColunaJogada][1] == '1'){
                player2Board[posicaoLinhaJogada][posicaoColunaJogada][0] = '#';
                system("cls");
                std::cout << "[   FOGO!!! Sua bomba atingiu parte de um barco!  ]\n";
                apresentarTabelaJogador2(player2Name);
                sleep(2);

                // Se o Player1 ganhar
                if (checarGanhador(player2Board)) {
                    system("cls");
                    std::cout << "----------ESTRUTURA DE DADOS----------" << std::endl;
                    std::cout << "======================================" << std::endl;
                    std::cout << "-------------Batalha Naval------------" << std::endl;
                    std::cout << "======================================" << std::endl << std::endl;
                    std::cout << "Parab�ns, " << player1Name << "! \nVoc� ganhou a Batalha Naval!!! :D" << std::endl << std::endl;
                    std::cout << "======================================" << std::endl << std::endl;

                    std::cout << "[ Retornando para o Menu de Vetores e \nMatrizes... ]";
                    sleep(7);
                    menuBatalhaNaval();
                }
            }

        } else if (turno % 2 != 0){
            // Vez do jogador 2

            std::cout << "Turno do " << player2Name << ":" << std::endl;
            apresentarTabelaJogador1(player1Name);
            std::cout << "\n*Escolha uma coordenada para lan�ar uma bomba* \nLinha: ";
            std::cin >> posicaoLinhaJogada;
            std::cout << "\nColuna: ";
            std::cin >> posicaoColunaJogada;

            if (player1Board[posicaoLinhaJogada][posicaoColunaJogada][1] == '0'){
                player1Board[posicaoLinhaJogada][posicaoColunaJogada][0] = '~';
                system("cls");
                std::cout << "[   Sua bomba atingiu a �gua!!!  ]\n";
                apresentarTabelaJogador1(player2Name);
                sleep(2);

                if (checarGanhador(player1Board)) {
                    system("cls");
                    std::cout << "----------ESTRUTURA DE DADOS----------" << std::endl;
                    std::cout << "======================================" << std::endl;
                    std::cout << "-------------Batalha Naval------------" << std::endl;
                    std::cout << "======================================" << std::endl << std::endl;
                    std::cout << "Parab�ns, " << player2Name << "! \nVoc� ganhou a Batalha Naval!!! :D" << std::endl << std::endl;
                    std::cout << "======================================" << std::endl << std::endl;

                    std::cout << "[ Retornando para o Menu de Vetores e \nMatrizes... ]";
                    sleep(7);
                    menuBatalhaNaval();
                }

            } else if (player1Board[posicaoLinhaJogada][posicaoColunaJogada][1] == '1'){
                player1Board[posicaoLinhaJogada][posicaoColunaJogada][0] = '#';
                system("cls");
                std::cout << "[   FOGO!!! Sua bomba atingiu parte de um barco!  ]\n";
                apresentarTabelaJogador1(player2Name);
                sleep(2);

                // Se o Player2 ganhar
                if (checarGanhador(player1Board)) {
                    system("cls");
                    std::cout << "----------ESTRUTURA DE DADOS----------" << std::endl;
                    std::cout << "======================================" << std::endl;
                    std::cout << "-------------Batalha Naval------------" << std::endl;
                    std::cout << "======================================" << std::endl << std::endl;
                    std::cout << "Parab�ns, " << player2Name << "! \nVoc� ganhou a Batalha Naval!!! :D" << std::endl << std::endl;
                    std::cout << "======================================" << std::endl << std::endl;

                    std::cout << "[ Retornando para o Menu de Vetores e \nMatrizes... ]";
                    sleep(7);
                    menuBatalhaNaval();
                }
            }
        }
    }

    void apresentarTabelaJogador2(const std::string& player2Name){

        // Formata��o da Tabela
        std::cout << "[ Tabela do Jogador " << player2Name << "]" << std::endl;
        std::cout << "===============================" << std::endl;

        std::cout << " ";
        for (int i = 0; i < colunas; i++){
            std::cout << " " << i << " ";
        }
        std::cout << std::endl;

        // Loop para cada linha
        for (int i = 0; i < linhas; i++) {
            std::cout << i;
            // Loop para cada coluna
            for (int j = 0; j < colunas; j++) {
                std::cout << "[" << player2Board[i][j][0] << "]";
            }
            std::cout << std::endl;
        }
        std::cout << "===============================" << std::endl;
    }

    void apresentarTabelaJogador1(const std::string& player1Name){

        // Formata��o da Tabela
        std::cout << "[ Tabela do Jogador " << player1Name << "]" << std::endl;
        std::cout << "===============================" << std::endl;

        std::cout << " ";
        for (int i = 0; i < colunas; i++){
            std::cout << " " << i << " ";
        }
        std::cout << std::endl;

        // Loop para cada linha
        for (int i = 0; i < linhas; i++) {
            std::cout << i;
            // Loop para cada coluna
            for (int j = 0; j < colunas; j++) {
                std::cout << "[" << player1Board[i][j][0] << "]";
            }
            std::cout << std::endl;
        }
        std::cout << "===============================" << std::endl;
    }

    void colunaInicialSubmarinos(){
    std::cout << "Informe a coluna da posi��o do Submarino (Ocupa 1 casa): ";
    std::cin >> posicaoColunaIni;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;
    }

    void linhaInicialSubmarinos(){
        std::cout << "Informe a linha da posi��o do Submarino (Ocupa 1 casa): ";
        std::cin >> posicaoLinhaIni;
        std::cin.ignore(80, '\n');
        std::cout << std::endl;
    }

    void submarinosPlayer2() {
        std::cout << "Escolha a posi��o que seu Submarino ir� ocupar (Ocupa 1 posi��o)*" << std::endl;

        system("cls");
        apresentarTabelaJogador2(player2Name);
        std::cout << "\n" << player2Name << ", escolha as coordenadas dos seus \nSubmarinos..." << std::endl << std::endl;

        linhaInicialSubmarinos();

        bool posicaoValida = false;
        while (!posicaoValida) {
            if (posicaoLinhaIni < 0 || posicaoLinhaIni > 9) {
                std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                sleep(1);
                system("cls");
                apresentarTabelaJogador2(player2Name);
                std::cout << player2Name << ", escolha as coordenadas dos seus \nSubmarinos..." << std::endl << std::endl;
                linhaInicialSubmarinos();
            } else {
                posicaoValida = true;
            }
        }

        colunaInicialSubmarinos();

        posicaoValida = false;
        while (!posicaoValida) {
            if (posicaoColunaIni < 0 || posicaoColunaIni > 9) {
                std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                sleep(1);
                system("cls");
                apresentarTabelaJogador2(player2Name);
                std::cout << player2Name << ", escolha as coordenadas dos seus \nSubmarinos..." << std::endl << std::endl;
                std::cout << "Informe a linha da primeira posi��o do Submarino (Ocupa 1 casa): " << posicaoLinhaIni << std::endl << std::endl;
                colunaInicialSubmarinos();
            } else {
                posicaoValida = true;
            }
        }

        if (posicaoColunaIni > 9 || posicaoColunaIni < 0) {
            std::cout << "\n**Posi��o inv�lida.**";
            sleep(1);
            std::cout << std::endl;
            submarinosPlayer2();
        }

        player2Board[posicaoLinhaIni][posicaoColunaIni][0] = 'X';

        player2Board[posicaoLinhaIni][posicaoColunaIni][1] = '1';

        system("cls");
        apresentarTabelaJogador2(player2Name);
        std::cout << "\n" << player2Name << ", escolha as coordenadas dos seus \nsubmarinos..." << std::endl << std::endl;
    }

    void submarinosPlayer1(void){

        std::cout << "Escolha a posi��o que seu Submarino ir� ocupar (Ocupa 1 posi��o)*" << std::endl;

        system("cls");
        apresentarTabelaJogador1(player1Name);
        std::cout << "\n" << player1Name << ", escolha as coordenadas dos seus \nSubmarinos..." << std::endl << std::endl;

        linhaInicialSubmarinos();

        bool posicaoValida = false;
        while (!posicaoValida) {
            if (posicaoLinhaIni < 0 || posicaoLinhaIni > 9) {
                std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                sleep(1);
                system("cls");
                apresentarTabelaJogador1(player1Name);
                std::cout << player1Name << ", escolha as coordenadas dos seus \nSubmarinos..." << std::endl << std::endl;
                linhaInicialSubmarinos();
            } else {
                posicaoValida = true;
            }
        }

        colunaInicialSubmarinos();

        posicaoValida = false;
        while (!posicaoValida) {
            if (posicaoColunaIni < 0 || posicaoColunaIni > 9) {
                std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                sleep(1);
                system("cls");
                apresentarTabelaJogador1(player1Name);
                std::cout << player1Name << ", escolha as coordenadas dos seus \nSubmarinos..." << std::endl << std::endl;
                std::cout << "Informe a linha da primeira posi��o do Submarino (Ocupa 1 casa): " << posicaoLinhaIni << std::endl << std::endl;
                colunaInicialSubmarinos();
            } else {
                posicaoValida = true;
            }
        }

        if(posicaoColunaIni > 9 || posicaoColunaIni < 0){
            std::cout << "\n**Posi��o inv�lida.**";
            sleep(1);
            std::cout << std::endl;
            submarinosPlayer1();
        }

        player1Board[posicaoLinhaIni][posicaoColunaIni][0] = 'X';

        player1Board[posicaoLinhaIni][posicaoColunaIni][1] = '1';

        system("cls");
        apresentarTabelaJogador1(player1Name);
        std::cout << "\n" << player1Name << ", escolha as coordenadas dos seus \nsubmarinos..." << std::endl << std::endl;
    }


    void colunaFinalContratorpedeiros(){
    std::cout << "Informe a coluna da �ltima posi��o do Contratorpedeiro (Ocupa 2 casas): ";
    std::cin >> posicaoColunaFim;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;
    }

    void linhaFinalContratorpedeiros(){
        std::cout << "Informe a linha da �ltima posi��o do Contratorpedeiro (Ocupa 2 casas): ";
        std::cin >> posicaoLinhaFim;
        std::cin.ignore(80, '\n');
        std::cout << std::endl;
    }

    void colunaInicialContratorpedeiros(){
        std::cout << "Informe a coluna da primeira posi��o do Contratorpedeiro (Ocupa 2 casas): ";
        std::cin >> posicaoColunaIni;
        std::cin.ignore(80, '\n');
        std::cout << std::endl;
    }

    void linhaInicialContratorpedeiros(){
        std::cout << "Informe a linha da primeira posi��o do Contratorpedeiro (Ocupa 2 casas): ";
        std::cin >> posicaoLinhaIni;
        std::cin.ignore(80, '\n');
        std::cout << std::endl;
    }

    void contratorpedeirosPlayer2() {
        orientacaoBarco = -1;

        if (orientacaoBarco == -1) {
            std::cout << "Escolha a posi��o que seu Contratorpedeiro ir� ocupar (Ocupa 2 posi��es)*" << std::endl;
            std::cout << "Insira [0] para Horizontal ou [1] para Vertical: ";
            std::cin >> orientacaoBarco; std::cin.ignore(80, '\n');
            orba = orientacaoBarco;
        } else {
            orientacaoBarco = orba;
        }

        if (orientacaoBarco != 0 && orientacaoBarco != 1) {
            orientacaoBarco = -1;
            system("cls");
            apresentarTabelaJogador2(player2Name);
            std::cout << "\n**Insira uma op��o v�lida**" << std::endl << std::endl;
            contratorpedeirosPlayer2();
        } else if (orientacaoBarco == 0) {
            //Se for Horizontal
            system("cls");
            apresentarTabelaJogador2(player2Name);
            std::cout << "\n" << player2Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;
            linhaInicialContratorpedeiros();

            bool posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoLinhaIni < 0 || posicaoLinhaIni > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador2(player2Name);
                    std::cout << player2Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;
                    linhaInicialContratorpedeiros();
                } else {
                    posicaoValida = true;
                }
            }

            colunaInicialContratorpedeiros();

            posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoColunaIni < 0 || posicaoColunaIni > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador2(player2Name);
                    std::cout << player2Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;
                    std::cout << "Informe a linha da primeira posi��o do Contratorpedeiro (Ocupa 2 casas): " << posicaoLinhaIni << std::endl << std::endl;
                    colunaInicialContratorpedeiros();
                } else {
                    posicaoValida = true;
                }
            }

            colunaFinalContratorpedeiros();

            posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoColunaFim < 0 || posicaoColunaFim > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador2(player2Name);
                    std::cout << player2Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;
                    std::cout << "Informe a linha da primeira posi��o do Contratorpedeiro (Ocupa 2 casas): " << posicaoLinhaIni << std::endl << std::endl;
                    std::cout << "Informe a coluna da primeira posi��o do Contratorpedeiro (Ocupa 2 casas): " << posicaoColunaIni << std::endl << std::endl;
                    colunaFinalContratorpedeiros();
                } else {
                    posicaoValida = true;
                }
            }

            if (posicaoColunaIni > 8 || posicaoColunaFim > 9 ||
                posicaoColunaFim > posicaoColunaIni + 1) {
                std::cout << "\n**Posi��o inv�lida, ou o barco ultrapassa a quantidade de casas dispon�veis para o Contratorpedeiro (2 casas)**";
                sleep(1);
                std::cout << std::endl;
                contratorpedeirosPlayer2();
            }

            if (posicaoColunaIni > 8 || posicaoColunaFim > 9 ||
                posicaoColunaIni > posicaoColunaFim - 1) {
                system("cls");
                apresentarTabelaJogador2(player2Name);
                std::cout << "\n**Posi��o inv�lida, ou a quantidade de casas definidas � menor que a quantidade \nde casas exigidas para o Contratorpedeiro (2 casas)**";
                sleep(3);
                std::cout << std::endl;
                contratorpedeirosPlayer2();
            }

            player2Board[posicaoLinhaIni][posicaoColunaIni][0] = 'X';
            player2Board[posicaoLinhaIni][posicaoColunaFim][0] = 'X';

            player2Board[posicaoLinhaIni][posicaoColunaIni][1] = '1';
            player2Board[posicaoLinhaIni][posicaoColunaFim][1] = '1';

            system("cls");
            apresentarTabelaJogador2(player2Name);
            std::cout << "\n" << player2Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;

        } else if (orientacaoBarco == 1) {
            //Se for Vertical
            system("cls");
            apresentarTabelaJogador2(player2Name);
            std::cout << "\n" << player2Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;
            colunaInicialContratorpedeiros();

            bool posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoColunaIni < 0 || posicaoColunaIni > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma coluna de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador2(player2Name);
                    std::cout << "\n" << player2Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;
                    colunaInicialContratorpedeiros();
                } else {
                    posicaoValida = true;
                }
            }linhaInicialContratorpedeiros();

            posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoLinhaIni < 0 || posicaoLinhaIni > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador2(player2Name);
                    std::cout << player2Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;
                    std::cout << "Informe a coluna da primeira posi��o do Contratorpedeiro (Ocupa 2 casas): " << posicaoColunaIni << std::endl << std::endl;
                    linhaInicialContratorpedeiros();
                } else {
                    posicaoValida = true;
                }
            }

            linhaFinalContratorpedeiros();

            posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoLinhaFim < 0 || posicaoLinhaFim > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador2(player2Name);
                    std::cout << player2Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;
                    std::cout << "Informe a coluna da primeira posi��o do Contratorpedeiro (Ocupa 2 casas): " << posicaoColunaIni << std::endl << std::endl;
                    std::cout << "Informe a linha da primeira posi��o do Contratorpedeiro (Ocupa 2 casas): " << posicaoLinhaIni << std::endl << std::endl;
                    linhaFinalContratorpedeiros();
                } else {
                    posicaoValida = true;
                }
            }

            if (posicaoLinhaIni > 8 || posicaoLinhaFim > 9 ||
                posicaoLinhaFim > posicaoLinhaIni + 1) {
                std::cout << "\n**Posi��o inv�lida, ou o barco ultrapassa a quantidade de casas dispon�veis para o Contratorpedeiro (2 casas)**";
                sleep(1);
                std::cout << std::endl;
                contratorpedeirosPlayer2();
            }

            if (posicaoLinhaIni > 8 || posicaoLinhaIni > 9 ||
                posicaoLinhaIni > posicaoLinhaFim - 1) {
                system("cls");
                apresentarTabelaJogador2(player2Name);
                std::cout << "\n**Posi��o inv�lida, ou a quantidade de casas definidas � menor que a quantidade \nde casas exigidas para o Contratorpedeiro (2 casas)**";
                sleep(3);
                std::cout << std::endl;
                contratorpedeirosPlayer2();
            }

            player2Board[posicaoLinhaIni][posicaoColunaIni][0] = 'X';
            player2Board[posicaoLinhaFim][posicaoColunaIni][0] = 'X';

            player2Board[posicaoLinhaIni][posicaoColunaIni][1] = '1';
            player2Board[posicaoLinhaFim][posicaoColunaIni][1] = '1';

            system("cls");
            apresentarTabelaJogador2(player2Name);
            std::cout << "\n" << player2Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;
        }
    }

    void contratorpedeirosPlayer1(void){
        orientacaoBarco = -1;

        if(orientacaoBarco == -1){
            std::cout << "Escolha a posi��o que seu Contratorpedeiro ir� ocupar (Ocupa 2 posi��es)*" << std::endl;
            std::cout << "Insira [0] para Horizontal ou [1] para Vertical: ";
            std::cin >> orientacaoBarco; std::cin.ignore(80, '\n');
            orba = orientacaoBarco;
        }else {
            orientacaoBarco = orba;
        }

        if(orientacaoBarco != 0 && orientacaoBarco != 1){
            orientacaoBarco = -1;
            system("cls");
            apresentarTabelaJogador1(player1Name);
            std::cout << "\n**Insira uma op��o v�lida**" << std::endl << std::endl;
            contratorpedeirosPlayer1();
        }else if(orientacaoBarco == 0){
            //Se for Horizontal
            system("cls");
            apresentarTabelaJogador1(player1Name);
            std::cout << "\n" << player1Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;
            linhaInicialContratorpedeiros();

            bool posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoLinhaIni < 0 || posicaoLinhaIni > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador1(player1Name);
                    std::cout << player1Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;
                    linhaInicialContratorpedeiros();
                } else {
                    posicaoValida = true;
                }
            }

            colunaInicialContratorpedeiros();

            posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoColunaIni < 0 || posicaoColunaIni > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador1(player1Name);
                    std::cout << player1Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;
                    std::cout << "Informe a linha da primeira posi��o do Contratorpedeiro (Ocupa 2 casas): " << posicaoLinhaIni << std::endl << std::endl;
                    colunaInicialContratorpedeiros();
                } else {
                    posicaoValida = true;
                }
            }

            colunaFinalContratorpedeiros();

            posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoColunaFim < 0 || posicaoColunaFim > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador1(player1Name);
                    std::cout << player1Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;
                    std::cout << "Informe a linha da primeira posi��o do Contratorpedeiro (Ocupa 2 casas): " << posicaoLinhaIni << std::endl << std::endl;
                    std::cout << "Informe a coluna da primeira posi��o do Contratorpedeiro (Ocupa 2 casas): " << posicaoColunaIni << std::endl << std::endl;
                    colunaFinalContratorpedeiros();
                } else {
                    posicaoValida = true;
                }
            }

            if(posicaoColunaIni > 8 || posicaoColunaFim > 9 ||
               posicaoColunaFim > posicaoColunaIni + 1){
                std::cout << "\n**Posi��o inv�lida, ou o barco ultrapassa a quantidade de casas dispon�veis para o Contratorpedeiro (2 casas)**";
                sleep(1);
                std::cout << std::endl;
                contratorpedeirosPlayer1();
            }

            if(posicaoColunaIni > 8 || posicaoColunaFim > 9 ||
               posicaoColunaIni > posicaoColunaFim - 1){
                system("cls");
                apresentarTabelaJogador1(player1Name);
                std::cout << "\n**Posi��o inv�lida, ou a quantidade de casas definidas � menor que a quantidade \nde casas exigidas para o Contratorpedeiro (2 casas)**";
                sleep(3);
                std::cout << std::endl;
                contratorpedeirosPlayer1();
            }

            player1Board[posicaoLinhaIni][posicaoColunaIni][0] = 'X';
            player1Board[posicaoLinhaIni][posicaoColunaFim][0] = 'X';

            player1Board[posicaoLinhaIni][posicaoColunaIni][1] = '1';
            player1Board[posicaoLinhaIni][posicaoColunaFim][1] = '1';

            system("cls");
            apresentarTabelaJogador1(player1Name);
            std::cout << "\n" << player1Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;

        } else if(orientacaoBarco == 1){
            //Se for Vertical
            system("cls");
            apresentarTabelaJogador1(player1Name);
            std::cout << "\n" << player1Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;
            colunaInicialContratorpedeiros();

            bool posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoColunaIni < 0 || posicaoColunaIni > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma coluna de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador1(player1Name);
                    std::cout << "\n" << player1Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;
                    colunaInicialContratorpedeiros();
                } else {
                    posicaoValida = true;
                }
            }

            linhaInicialContratorpedeiros();

            posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoLinhaIni < 0 || posicaoLinhaIni > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador1(player1Name);
                    std::cout << player1Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;
                    std::cout << "Informe a coluna da primeira posi��o do Contratorpedeiro (Ocupa 2 casas): " << posicaoColunaIni << std::endl << std::endl;
                    linhaInicialContratorpedeiros();
                } else {
                    posicaoValida = true;
                }
            }

            linhaFinalContratorpedeiros();

            posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoLinhaFim < 0 || posicaoLinhaFim > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador1(player1Name);
                    std::cout << player1Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;
                    std::cout << "Informe a coluna da primeira posi��o do Contratorpedeiro (Ocupa 2 casas): " << posicaoColunaIni << std::endl << std::endl;
                    std::cout << "Informe a linha da primeira posi��o do Contratorpedeiro (Ocupa 2 casas): " << posicaoLinhaIni << std::endl << std::endl;
                    linhaFinalContratorpedeiros();
                } else {
                    posicaoValida = true;
                }
            }

            if(posicaoLinhaIni > 8 || posicaoLinhaFim > 9 ||
               posicaoLinhaFim > posicaoLinhaIni + 1){
                std::cout << "\n**Posi��o inv�lida, ou o barco ultrapassa a quantidade de casas dispon�veis para o Contratorpedeiro (2 casas)**";
                sleep(1);
                std::cout << std::endl;
                contratorpedeirosPlayer1();
            }

            if(posicaoLinhaIni > 8 || posicaoLinhaIni > 9 ||
               posicaoLinhaIni > posicaoLinhaFim - 1){
                system("cls");
                apresentarTabelaJogador1(player1Name);
                std::cout << "\n**Posi��o inv�lida, ou a quantidade de casas definidas � menor que a quantidade \nde casas exigidas para o Contratorpedeiro (2 casas)**";
                sleep(3);
                std::cout << std::endl;
                contratorpedeirosPlayer1();
            }

            player1Board[posicaoLinhaIni][posicaoColunaIni][0] = 'X';
            player1Board[posicaoLinhaFim][posicaoColunaIni][0] = 'X';

            player1Board[posicaoLinhaIni][posicaoColunaIni][1] = '1';
            player1Board[posicaoLinhaFim][posicaoColunaIni][1] = '1';

            system("cls");
            apresentarTabelaJogador1(player1Name);
            std::cout << "\n" << player1Name << ", escolha as coordenadas dos seus \ncontratorpedeiros..." << std::endl << std::endl;
        }
    }

    void colunaFinalNavioTanque(){
        std::cout << "Informe a coluna da �ltima posi��o do Navio-Tanque (Ocupa 3 casas): ";
        std::cin >> posicaoColunaFim;
        std::cin.ignore(80, '\n');
        std::cout << std::endl;
    }

    void linhaFinalNavioTanque(){
        std::cout << "Informe a linha da �ltima posi��o do Navio-Tanque (Ocupa 3 casas): ";
        std::cin >> posicaoLinhaFim;
        std::cin.ignore(80, '\n');
        std::cout << std::endl;
    }

    void colunaInicialNavioTanque(){
        std::cout << "Informe a coluna da primeira posi��o do Navio-Tanque (Ocupa 3 casas): ";
        std::cin >> posicaoColunaIni;
        std::cin.ignore(80, '\n');
        std::cout << std::endl;
    }

    void linhaInicialNavioTanque(){
        std::cout << "Informe a linha da primeira posi��o do Navio-Tanque (Ocupa 3 casas): ";
        std::cin >> posicaoLinhaIni;
        std::cin.ignore(80, '\n');
        std::cout << std::endl;
    }

    void navioTanquePlayer2() {
        orientacaoBarco = -1;

        if (orientacaoBarco == -1) {
            std::cout << "Escolha a posi��o que seu Navio-Tanque ir� ocupar (Ocupa 3 posi��es)*" << std::endl;
            std::cout << "Insira [0] para Horizontal ou [1] para Vertical: ";
            std::cin >> orientacaoBarco;
            std::cin.ignore(80, '\n');
            orba = orientacaoBarco;
        } else {
            orientacaoBarco = orba;
        }

        if (orientacaoBarco != 0 && orientacaoBarco != 1) {
            orientacaoBarco = -1;
            system("cls");
            apresentarTabelaJogador2(player2Name);
            std::cout << "\n**Insira uma op��o v�lida**" << std::endl << std::endl;
            navioTanquePlayer2();
        } else if (orientacaoBarco == 0) {
            // Se for Horizontal
            system("cls");
            apresentarTabelaJogador2(player2Name);
            std::cout << "\n" << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
            linhaInicialNavioTanque();

            bool posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoLinhaIni < 0 || posicaoLinhaIni > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador2(player2Name);
                    std::cout << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                    linhaInicialNavioTanque();
                } else {
                    posicaoValida = true;
                }
            }

            colunaInicialNavioTanque();

            posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoColunaIni < 0 || posicaoColunaIni > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador2(player2Name);
                    std::cout << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                    std::cout << "Informe a linha da primeira posi��o do Navio-Tanque (Ocupa 3 casas): " << posicaoLinhaIni << std::endl << std::endl;
                    colunaInicialNavioTanque();
                } else {
                    posicaoValida = true;
                }
            }

            colunaFinalNavioTanque();

            posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoColunaFim < 0 || posicaoColunaFim > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador2(player2Name);
                    std::cout << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                    std::cout << "Informe a linha da primeira posi��o do Navio-Tanque (Ocupa 3 casas): " << posicaoLinhaIni << std::endl << std::endl;
                    std::cout << "Informe a coluna da primeira posi��o do Navio-Tanque (Ocupa 3 casas): " << posicaoColunaIni << std::endl << std::endl;
                    colunaFinalNavioTanque();
                } else {
                    posicaoValida = true;
                }
            }

            if (posicaoColunaIni > 7 || posicaoColunaFim > 9 ||
                posicaoColunaFim > posicaoColunaIni + 2) {
                std::cout << "\n**Posi��o inv�lida, ou o barco ultrapassa a quantidade de casas dispon�veis para o Navio-Tanque (3 casas)**";
                sleep(1);
                std::cout << std::endl;
                navioTanquePlayer2();
            }

            if (posicaoColunaIni > 7 || posicaoColunaFim > 9 ||
                posicaoColunaIni > posicaoColunaFim - 2) {
                system("cls");
                apresentarTabelaJogador2(player2Name);
                std::cout << "\n**Posi��o inv�lida, ou a quantidade de casas definidas � menor que a quantidade \nde casas exigidas para o Navio-Tanque (3 casas)**";
                sleep(3);
                std::cout << std::endl;
                navioTanquePlayer2();
            }

            player2Board[posicaoLinhaIni][posicaoColunaIni][0] = 'X';
            player2Board[posicaoLinhaIni][posicaoColunaFim][0] = 'X';
            player2Board[posicaoLinhaIni][posicaoColunaIni + 1][0] = 'X';
            player2Board[posicaoLinhaIni][posicaoColunaFim - 1][0] = 'X';

            player2Board[posicaoLinhaIni][posicaoColunaIni][1] = '1';
            player2Board[posicaoLinhaIni][posicaoColunaFim][1] = '1';
            player2Board[posicaoLinhaIni][posicaoColunaIni + 1][1] = '1';
            player2Board[posicaoLinhaIni][posicaoColunaFim - 1][1] = '1';

            system("cls");
            apresentarTabelaJogador2(player2Name);
            std::cout << "\n" << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;

        } else if (orientacaoBarco == 1) {
            // Se for Vertical
            system("cls");
            apresentarTabelaJogador2(player2Name);
            std::cout << "\n" << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
            colunaInicialNavioTanque();

            bool posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoColunaIni < 0 || posicaoColunaIni > 9) {std::cout << "\nPosi��o inv�lida, informe uma coluna de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador2(player2Name);
                    std::cout << "\n" << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                    colunaInicialNavioTanque();
                } else {
                    posicaoValida = true;
                }
            }

            linhaInicialNavioTanque();

            posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoLinhaIni < 0 || posicaoLinhaIni > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador2(player2Name);
                    std::cout << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                    std::cout << "Informe a coluna da primeira posi��o do Navio-Tanque (Ocupa 3 casas): " << posicaoColunaIni << std::endl << std::endl;
                    linhaInicialNavioTanque();
                } else {
                    posicaoValida = true;
                }
            }

            linhaFinalNavioTanque();

            posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoLinhaFim < 0 || posicaoLinhaFim > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador2(player2Name);
                    std::cout << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                    std::cout << "Informe a coluna da primeira posi��o do Navio-Tanque (Ocupa 3 casas): " << posicaoColunaIni << std::endl << std::endl;
                    std::cout << "Informe a linha da primeira posi��o do Navio-Tanque (Ocupa 3 casas): " << posicaoLinhaIni << std::endl << std::endl;
                    colunaFinalNavioTanque();
                } else {
                    posicaoValida = true;
                }
            }

            if (posicaoLinhaIni > 7 || posicaoLinhaFim > 9 ||
                posicaoLinhaFim > posicaoLinhaIni + 2) {
                std::cout << "\n**Posi��o inv�lida, ou o barco ultrapassa a quantidade de casas dispon�veis para o Navio-Tanque (3 casas)**";
                sleep(1);
                std::cout << std::endl;
                navioTanquePlayer2();
            }

            if (posicaoLinhaIni > 7 || posicaoLinhaIni > 9 ||
                posicaoLinhaIni > posicaoLinhaFim - 2) {
                system("cls");
                apresentarTabelaJogador2(player2Name);
                std::cout << "\n**Posi��o inv�lida, ou a quantidade de casas definidas � menor que a quantidade \nde casas exigidas para o Navio-Tanque (3 casas)**";
                sleep(3);
                std::cout << std::endl;
                navioTanquePlayer2();
            }

            player2Board[posicaoLinhaIni][posicaoColunaIni][0] = 'X';
            player2Board[posicaoLinhaFim][posicaoColunaIni][0] = 'X';
            player2Board[posicaoLinhaIni + 1][posicaoColunaIni][0] = 'X';

            player2Board[posicaoLinhaIni][posicaoColunaIni][1] = '1';
            player2Board[posicaoLinhaFim][posicaoColunaIni][1] = '1';
            player2Board[posicaoLinhaIni + 1][posicaoColunaIni][1] = '1';

            system("cls");
            apresentarTabelaJogador2(player2Name);
            std::cout << "\n" << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
        }
    }

    void navioTanquePlayer1(void){
        orientacaoBarco = -1;

        if(orientacaoBarco == -1){
            std::cout << "Escolha a posi��o que seu Navio-Tanque ir� ocupar (Ocupa 3 posi��es)*" << std::endl;
            std::cout << "Insira [0] para Horizontal ou [1] para Vertical: ";
            std::cin >> orientacaoBarco; std::cin.ignore(80, '\n');
            orba = orientacaoBarco;
        }else {
            orientacaoBarco = orba;
        }

        if(orientacaoBarco != 0 && orientacaoBarco != 1){
            orientacaoBarco = -1;
            system("cls");
            apresentarTabelaJogador1(player1Name);
            std::cout << "\n**Insira uma op��o v�lida**" << std::endl << std::endl;
            navioTanquePlayer1();
        }else if(orientacaoBarco == 0){
            //Se for Horizontal
            system("cls");
            apresentarTabelaJogador1(player1Name);
            std::cout << "\n" << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
            linhaInicialNavioTanque();

            bool posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoLinhaIni < 0 || posicaoLinhaIni > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador1(player1Name);
                    std::cout << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                    linhaInicialNavioTanque();
                } else {
                    posicaoValida = true;
                }
            }

            colunaInicialNavioTanque();

            posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoColunaIni < 0 || posicaoColunaIni > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador1(player1Name);
                    std::cout << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                    std::cout << "Informe a linha da primeira posi��o do Navio-Tanque (Ocupa 3 casas): " << posicaoLinhaIni << std::endl << std::endl;
                    colunaInicialNavioTanque();
                } else {
                    posicaoValida = true;
                }
            }

            colunaFinalNavioTanque();

            posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoColunaFim < 0 || posicaoColunaFim > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador1(player1Name);
                    std::cout << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                    std::cout << "Informe a linha da primeira posi��o do Navio-Tanque (Ocupa 3 casas): " << posicaoLinhaIni << std::endl << std::endl;
                    std::cout << "Informe a coluna da primeira posi��o do Navio-Tanque (Ocupa 3 casas): " << posicaoColunaIni << std::endl << std::endl;
                    colunaFinalNavioTanque();
                } else {
                    posicaoValida = true;
                }
            }

            if(posicaoColunaIni > 7 || posicaoColunaFim > 9 ||
               posicaoColunaFim > posicaoColunaIni + 2){
                std::cout << "\n**Posi��o inv�lida, ou o barco ultrapassa a quantidade de casas dispon�veis para o Navio-Tanque (3 casas)**";
                sleep(1);
                std::cout << std::endl;
                navioTanquePlayer1();
            }

            if(posicaoColunaIni > 7 || posicaoColunaFim > 9 ||
               posicaoColunaIni > posicaoColunaFim - 2){
                system("cls");
                apresentarTabelaJogador1(player1Name);
                std::cout << "\n**Posi��o inv�lida, ou a quantidade de casas definidas � menor que a quantidade \nde casas exigidas para o Navio-Tanque (3 casas)**";
                sleep(3);
                std::cout << std::endl;
                navioTanquePlayer1();
            }

            player1Board[posicaoLinhaIni][posicaoColunaIni][0] = 'X';
            player1Board[posicaoLinhaIni][posicaoColunaFim][0] = 'X';
            player1Board[posicaoLinhaIni][posicaoColunaIni + 1][0] = 'X';
            player1Board[posicaoLinhaIni][posicaoColunaFim - 1][0] = 'X';

            player1Board[posicaoLinhaIni][posicaoColunaIni][1] = '1';
            player1Board[posicaoLinhaIni][posicaoColunaFim][1] = '1';
            player1Board[posicaoLinhaIni][posicaoColunaIni + 1][1] = '1';
            player1Board[posicaoLinhaIni][posicaoColunaFim - 1][1] = '1';

            system("cls");
            apresentarTabelaJogador1(player1Name);
            std::cout << "\n" << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;

        } else if(orientacaoBarco == 1){
            //Se for Vertical
            system("cls");
            apresentarTabelaJogador1(player1Name);
            std::cout << "\n" << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
            colunaInicialNavioTanque();

            bool posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoColunaIni < 0 || posicaoColunaIni > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma coluna de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador1(player1Name);
                    std::cout << "\n" << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                    colunaInicialNavioTanque();
                } else {
                    posicaoValida = true;
                }
            }

            linhaInicialNavioTanque();

            posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoLinhaIni < 0 || posicaoLinhaIni > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador1(player1Name);
                    std::cout << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                    std::cout << "Informe a coluna da primeira posi��o do Navio-Tanque (Ocupa 3 casas): " << posicaoColunaIni << std::endl << std::endl;
                    linhaInicialNavioTanque();
                } else {
                    posicaoValida = true;
                }
            }

            linhaFinalNavioTanque();

            posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoLinhaFim < 0 || posicaoLinhaFim > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador1(player1Name);
                    std::cout << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                    std::cout << "Informe a coluna da primeira posi��o do Navio-Tanque (Ocupa 3 casas): " << posicaoColunaIni << std::endl << std::endl;
                    std::cout << "Informe a linha da primeira posi��o do Navio-Tanque (Ocupa 3 casas): " << posicaoLinhaIni << std::endl << std::endl;
                    colunaFinalNavioTanque();
                } else {
                    posicaoValida = true;
                }
            }

            if(posicaoLinhaIni > 7 || posicaoLinhaFim > 9 ||
               posicaoLinhaFim > posicaoLinhaIni + 2){
                std::cout << "\n**Posi��o inv�lida, ou o barco ultrapassa a quantidade de casas dispon�veis para o Navio-Tanque (3 casas)**";
                sleep(1);
                std::cout << std::endl;
                navioTanquePlayer1();
            }

            if(posicaoLinhaIni > 7 || posicaoLinhaIni > 9 ||
               posicaoLinhaIni > posicaoLinhaFim - 2){
                system("cls");
                apresentarTabelaJogador1(player1Name);
                std::cout << "\n**Posi��o inv�lida, ou a quantidade de casas definidas � menor que a quantidade \nde casas exigidas para o Navio-Tanque (3 casas)**";
                sleep(3);
                std::cout << std::endl;
                navioTanquePlayer1();
            }

            player1Board[posicaoLinhaIni][posicaoColunaIni][0] = 'X';
            player1Board[posicaoLinhaFim][posicaoColunaIni][0] = 'X';
            player1Board[posicaoLinhaIni + 1][posicaoColunaIni][0] = 'X';

            player1Board[posicaoLinhaIni][posicaoColunaIni][1] = '1';
            player1Board[posicaoLinhaFim][posicaoColunaIni][1] = '1';
            player1Board[posicaoLinhaIni + 1][posicaoColunaIni][1] = '1';

            system("cls");
            apresentarTabelaJogador1(player1Name);
            std::cout << "\n" << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
        }
    }

    void colunaFinalPortaAvioes(){
        std::cout << "Informe a coluna da �ltima posi��o do Porta-Avi�es (Ocupa 4 casas): ";
        std::cin >> posicaoColunaFim;
        std::cin.ignore(80, '\n');
        std::cout << std::endl;
    }

    void linhaFinalPortaAvioes(){
        std::cout << "Informe a linha da �ltima posi��o do Porta-Avi�es (Ocupa 4 casas): ";
        std::cin >> posicaoLinhaFim;
        std::cin.ignore(80, '\n');
        std::cout << std::endl;
    }

    void colunaInicialPortaAvioes(){
        std::cout << "Informe a coluna da primeira posi��o do Porta-Avi�es (Ocupa 4 casas): ";
        std::cin >> posicaoColunaIni;
        std::cin.ignore(80, '\n');
        std::cout << std::endl;
    }

    void linhaInicialPortaAvioes(){
        std::cout << "Informe a linha da primeira posi��o do Porta-Avi�es (Ocupa 4 casas): ";
        std::cin >> posicaoLinhaIni;
        std::cin.ignore(80, '\n');
        std::cout << std::endl;
    }

    void portaAvioesPlayer2(void){
        orientacaoBarco = -1;

        if(orientacaoBarco == -1){
            std::cout << "\n*Escolha a posi��o que seu Porta-Avi�es ir� ocupar (Ocupa 4 posi��es)*" << std::endl;
            std::cout << "Insira [0] para Horizontal ou [1] para Vertical: ";
            std::cin >> orientacaoBarco; std::cin.ignore(80, '\n');
            orba = orientacaoBarco;
        }else {
            orientacaoBarco = orba;
        }
            if(orientacaoBarco != 0 && orientacaoBarco != 1){
                orientacaoBarco = -1;
                system("cls");
                apresentarTabelaJogador2(player2Name);
                std::cout << "\n**Insira uma op��o v�lida**" << std::endl << std::endl;
                escolhaDosBarcos2();
            }else if(orientacaoBarco == 0){
                //Se for Horizontal
                system("cls");
                apresentarTabelaJogador2(player2Name);
                std::cout << "\n" << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                linhaInicialPortaAvioes();

                bool posicaoValida = false;
                while (!posicaoValida) {
                    if (posicaoLinhaIni < 0 || posicaoLinhaIni > 9) {
                        std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                        sleep(1);
                        system("cls");
                        apresentarTabelaJogador2(player2Name);
                        std::cout << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                        linhaInicialPortaAvioes();
                    } else {
                        posicaoValida = true;
                    }
                }

                colunaInicialPortaAvioes();

                posicaoValida = false;
                while (!posicaoValida) {
                    if (posicaoColunaIni < 0 || posicaoColunaIni > 9) {
                        std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                        sleep(1);
                        system("cls");
                        apresentarTabelaJogador2(player2Name);
                        std::cout << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                        std::cout << "Informe a linha da primeira posi��o do Porta-Avi�es (Ocupa 4 casas): " << posicaoLinhaIni << std::endl << std::endl;
                        colunaInicialPortaAvioes();
                    } else {
                        posicaoValida = true;
                    }
                }

                colunaFinalPortaAvioes();

                posicaoValida = false;
                while (!posicaoValida) {
                    if (posicaoColunaFim < 0 || posicaoColunaFim > 9) {
                        std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                        sleep(1);
                        system("cls");
                        apresentarTabelaJogador2(player2Name);
                        std::cout << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                        std::cout << "Informe a linha da primeira posi��o do Porta-Avi�es (Ocupa 4 casas): " << posicaoLinhaIni << std::endl << std::endl;
                        std::cout << "Informe a coluna da primeira posi��o do Porta-Avi�es (Ocupa 4 casas): " << posicaoColunaIni << std::endl << std::endl;
                        colunaFinalPortaAvioes();
                    } else {
                        posicaoValida = true;
                    }
                }

                if(posicaoColunaIni > 6 || posicaoColunaFim > 9 ||
                   posicaoColunaFim > posicaoColunaIni + 3){
                    std::cout << "\n**Posi��o inv�lida, ou o barco ultrapassa a quantidade de casas dispon�veis para o Porta-Avi�es (4 casas)**";
                    sleep(1);
                    std::cout << std::endl;
                    portaAvioesPlayer2();
                }

                if(posicaoColunaIni > 6 || posicaoColunaFim > 9 ||
                   posicaoColunaIni > posicaoColunaFim - 3){
                    system("cls");
                    apresentarTabelaJogador2(player2Name);
                    std::cout << "\n**Posi��o inv�lida, ou a quantidade de casas definidas � menor que a quantidade \nde casas exigidas para o Porta-Avi�es (4 casas)**";
                    sleep(3);
                    std::cout << std::endl;
                    portaAvioesPlayer2();
                }

                player2Board[posicaoLinhaIni][posicaoColunaIni][0] = 'X';
                player2Board[posicaoLinhaIni][posicaoColunaFim][0] = 'X';
                player2Board[posicaoLinhaIni][posicaoColunaIni + 1][0] = 'X';
                player2Board[posicaoLinhaIni][posicaoColunaFim - 1][0] = 'X';

                player2Board[posicaoLinhaIni][posicaoColunaIni][1] = '1';
                player2Board[posicaoLinhaIni][posicaoColunaFim][1] = '1';
                player2Board[posicaoLinhaIni][posicaoColunaIni + 1][1] = '1';
                player2Board[posicaoLinhaIni][posicaoColunaFim - 1][1] = '1';

                system("cls");
                apresentarTabelaJogador2(player2Name);
                std::cout << "\n" << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;

            }else if(orientacaoBarco == 1){
                //Se for Vertical
                system("cls");
                apresentarTabelaJogador2(player2Name);
                std::cout << "\n" << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                colunaInicialPortaAvioes();

                bool posicaoValida = false;
                while (!posicaoValida) {
                    if (posicaoColunaIni < 0 || posicaoColunaIni > 9) {
                        std::cout << "\nPosi��o inv�lida, informe uma coluna de 0 � 9.";
                        sleep(1);
                        system("cls");
                        apresentarTabelaJogador2(player2Name);
                        std::cout << "\n" << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                        colunaInicialPortaAvioes();
                    } else {
                        posicaoValida = true;
                    }
                }
                linhaInicialPortaAvioes();

            posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoLinhaIni < 0 || posicaoLinhaIni > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador2(player2Name);
                    std::cout << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                    std::cout << "Informe a coluna da primeira posi��o do Porta-Avi�es (Ocupa 4 casas): " << posicaoColunaIni << std::endl << std::endl;
                    linhaInicialPortaAvioes();
                } else {
                    posicaoValida = true;
                }
            }

            linhaFinalPortaAvioes();

            posicaoValida = false;
            while (!posicaoValida) {
                if (posicaoLinhaFim < 0 || posicaoLinhaFim > 9) {
                    std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                    sleep(1);
                    system("cls");
                    apresentarTabelaJogador2(player2Name);
                    std::cout << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                    std::cout << "Informe a coluna da primeira posi��o do Porta-Avi�es (Ocupa 4 casas): " << posicaoColunaIni << std::endl << std::endl;
                    std::cout << "Informe a linha da primeira posi��o do Porta-Avi�es (Ocupa 4 casas): " << posicaoLinhaIni << std::endl << std::endl;
                    colunaFinalPortaAvioes();
                } else {
                    posicaoValida = true;
                }
            }

            if(posicaoLinhaIni > 6 || posicaoLinhaFim > 9 ||
               posicaoLinhaFim > posicaoLinhaIni + 3){
                std::cout << "\n**Posi��o inv�lida, ou o barco ultrapassa a quantidade de casas dispon�veis para o Porta-Avi�es (4 casas)**";
                sleep(1);
                std::cout << std::endl;
                portaAvioesPlayer2();
            }

            if(posicaoLinhaIni > 6 || posicaoLinhaIni > 9 ||
               posicaoLinhaIni > posicaoLinhaFim - 3){
                system("cls");
                apresentarTabelaJogador2(player2Name);
                std::cout << "\n**Posi��o inv�lida, ou a quantidade de casas definidas � menor que a quantidade \nde casas exigidas para o Porta-Avi�es (4 casas)**";
                sleep(3);
                std::cout << std::endl;
                portaAvioesPlayer2();
            }

            player2Board[posicaoLinhaIni][posicaoColunaIni][0] = 'X';
            player2Board[posicaoLinhaFim][posicaoColunaIni][0] = 'X';
            player2Board[posicaoLinhaIni + 1][posicaoColunaIni][0] = 'X';
            player2Board[posicaoLinhaFim - 1][posicaoColunaIni][0] = 'X';

            player2Board[posicaoLinhaIni][posicaoColunaIni][1] = '1';
            player2Board[posicaoLinhaFim][posicaoColunaIni][1] = '1';
            player2Board[posicaoLinhaIni + 1][posicaoColunaIni][1] = '1';
            player2Board[posicaoLinhaFim - 1][posicaoColunaIni][1] = '1';

            system("cls");
            apresentarTabelaJogador2(player2Name);
            std::cout << "\n" << player2Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
        }
    }

    void portaAvioesPlayer1(void){


        if(orientacaoBarco == -1){
            std::cout << "\n*Escolha a posi��o que seu Porta-Avi�es ir� ocupar (Ocupa 4 posi��es)*" << std::endl;
            std::cout << "Insira [0] para Horizontal ou [1] para Vertical: ";
            std::cin >> orientacaoBarco; std::cin.ignore(80, '\n');
            orba = orientacaoBarco;
        }else {
            orientacaoBarco = orba;
        }
            if(orientacaoBarco != 0 && orientacaoBarco != 1){
                orientacaoBarco = -1;
                system("cls");
                apresentarTabelaJogador1(player1Name);
                std::cout << "\n**Insira uma op��o v�lida**" << std::endl << std::endl;
                escolhaDosBarcos1();
            }else if(orientacaoBarco == 0){
                //Se for Horizontal
                system("cls");
                apresentarTabelaJogador1(player1Name);
                std::cout << "\n" << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                linhaInicialPortaAvioes();

                bool posicaoValida = false;
                while (!posicaoValida) {
                    if (posicaoLinhaIni < 0 || posicaoLinhaIni > 9) {
                        std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                        sleep(1);
                        system("cls");
                        apresentarTabelaJogador1(player1Name);
                        std::cout << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                        linhaInicialPortaAvioes();
                    } else {
                        posicaoValida = true;
                    }
                }

                colunaInicialPortaAvioes();

                posicaoValida = false;
                while (!posicaoValida) {
                    if (posicaoColunaIni < 0 || posicaoColunaIni > 9) {
                        std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                        sleep(1);
                        system("cls");
                        apresentarTabelaJogador1(player1Name);
                        std::cout << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                        std::cout << "Informe a linha da primeira posi��o do Porta-Avi�es (Ocupa 4 casas): " << posicaoLinhaIni << std::endl << std::endl;
                        colunaInicialPortaAvioes();
                    } else {
                        posicaoValida = true;
                    }
                }

                colunaFinalPortaAvioes();

                posicaoValida = false;
                while (!posicaoValida) {
                    if (posicaoColunaFim < 0 || posicaoColunaFim > 9) {
                        std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                        sleep(1);
                        system("cls");
                        apresentarTabelaJogador1(player1Name);
                        std::cout << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                        std::cout << "Informe a linha da primeira posi��o do Porta-Avi�es (Ocupa 4 casas): " << posicaoLinhaIni << std::endl << std::endl;
                        std::cout << "Informe a coluna da primeira posi��o do Porta-Avi�es (Ocupa 4 casas): " << posicaoColunaIni << std::endl << std::endl;
                        colunaFinalPortaAvioes();
                    } else {
                        posicaoValida = true;
                    }
                }

                if(posicaoColunaIni > 6 || posicaoColunaFim > 9 ||
                   posicaoColunaFim > posicaoColunaIni + 3){
                    std::cout << "\n**Posi��o inv�lida, ou o barco ultrapassa a quantidade de casas dispon�veis para o Porta-Avi�es (4 casas)**";
                    sleep(1);
                    std::cout << std::endl;
                    portaAvioesPlayer1();
                }

                if(posicaoColunaIni > 6 || posicaoColunaFim > 9 ||
                   posicaoColunaIni > posicaoColunaFim - 3){
                    system("cls");
                    apresentarTabelaJogador1(player1Name);
                    std::cout << "\n**Posi��o inv�lida, ou a quantidade de casas definidas � menor que a quantidade \nde casas exigidas para o Porta-Avi�es (4 casas)**";
                    sleep(3);
                    std::cout << std::endl;
                    portaAvioesPlayer1();
                }

                player1Board[posicaoLinhaIni][posicaoColunaIni][0] = 'X';
                player1Board[posicaoLinhaIni][posicaoColunaFim][0] = 'X';
                player1Board[posicaoLinhaIni][posicaoColunaIni + 1][0] = 'X';
                player1Board[posicaoLinhaIni][posicaoColunaFim - 1][0] = 'X';

                player1Board[posicaoLinhaIni][posicaoColunaIni][1] = '1';
                player1Board[posicaoLinhaIni][posicaoColunaFim][1] = '1';
                player1Board[posicaoLinhaIni][posicaoColunaIni + 1][1] = '1';
                player1Board[posicaoLinhaIni][posicaoColunaFim - 1][1] = '1';

                system("cls");
                apresentarTabelaJogador1(player1Name);
                std::cout << "\n" << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;

            }else if(orientacaoBarco == 1){
                //Se for Vertical
                system("cls");
                apresentarTabelaJogador1(player1Name);
                std::cout << "\n" << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                colunaInicialPortaAvioes();

                bool posicaoValida = false;
                while (!posicaoValida) {
                    if (posicaoColunaIni < 0 || posicaoColunaIni > 9) {
                        std::cout << "\nPosi��o inv�lida, informe uma coluna de 0 � 9.";
                        sleep(1);
                        system("cls");
                        apresentarTabelaJogador1(player1Name);
                        std::cout << "\n" << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                        colunaInicialPortaAvioes();
                    } else {
                        posicaoValida = true;
                    }
                }

                linhaInicialPortaAvioes();

                posicaoValida = false;
                while (!posicaoValida) {
                    if (posicaoLinhaIni < 0 || posicaoLinhaIni > 9) {
                        std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                        sleep(1);
                        system("cls");
                        apresentarTabelaJogador1(player1Name);
                        std::cout << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                        std::cout << "Informe a coluna da primeira posi��o do Porta-Avi�es (Ocupa 4 casas): " << posicaoColunaIni << std::endl << std::endl;
                        linhaInicialPortaAvioes();
                    } else {
                        posicaoValida = true;
                    }
                }

                linhaFinalPortaAvioes();

                posicaoValida = false;
                while (!posicaoValida) {
                    if (posicaoLinhaFim < 0 || posicaoLinhaFim > 9) {
                        std::cout << "\nPosi��o inv�lida, informe uma linha de 0 � 9.";
                        sleep(1);
                        system("cls");
                        apresentarTabelaJogador1(player1Name);
                        std::cout << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
                        std::cout << "Informe a coluna da primeira posi��o do Porta-Avi�es (Ocupa 4 casas): " << posicaoColunaIni << std::endl << std::endl;
                        std::cout << "Informe a linha da primeira posi��o do Porta-Avi�es (Ocupa 4 casas): " << posicaoLinhaIni << std::endl << std::endl;
                        colunaFinalPortaAvioes();
                    } else {
                        posicaoValida = true;
                    }
                }

                if(posicaoLinhaIni > 6 || posicaoLinhaFim > 9 ||
                   posicaoLinhaFim > posicaoLinhaIni + 3){
                    std::cout << "\n**Posi��o inv�lida, ou o barco ultrapassa a quantidade de casas dispon�veis para o Porta-Avi�es (4 casas)**";
                    sleep(1);
                    std::cout << std::endl;
                    portaAvioesPlayer1();
                }

                if(posicaoLinhaIni > 6 || posicaoLinhaIni > 9 ||
                   posicaoLinhaIni > posicaoLinhaFim - 3){
                    system("cls");
                    apresentarTabelaJogador1(player1Name);
                    std::cout << "\n**Posi��o inv�lida, ou a quantidade de casas definidas � menor que a quantidade \nde casas exigidas para o Porta-Avi�es (4 casas)**";
                    sleep(3);
                    std::cout << std::endl;
                    portaAvioesPlayer1();
                }

                player1Board[posicaoLinhaIni][posicaoColunaIni][0] = 'X';
                player1Board[posicaoLinhaFim][posicaoColunaIni][0] = 'X';
                player1Board[posicaoLinhaIni + 1][posicaoColunaIni][0] = 'X';
                player1Board[posicaoLinhaFim - 1][posicaoColunaIni][0] = 'X';

                player1Board[posicaoLinhaIni][posicaoColunaIni][1] = '1';
                player1Board[posicaoLinhaFim][posicaoColunaIni][1] = '1';
                player1Board[posicaoLinhaIni + 1][posicaoColunaIni][1] = '1';
                player1Board[posicaoLinhaFim - 1][posicaoColunaIni][1] = '1';

                system("cls");
                apresentarTabelaJogador1(player1Name);
                std::cout << "\n" << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl << std::endl;
            }
    }

    void escolhaDosBarcos2(void) {
        // Inicializa todas as posi��es do tabuleiro do Player 2 como '0'
        for (int i = 0; i < linhas; ++i) {
            for (int j = 0; j < colunas; ++j) {
                for (int k = 1; k < tipo; ++k) {
                    player2Board[i][j][k] = '0';
                }
            }
        }

        std::cout << std::endl;
        std::cout << player2Name << ", escolha as coordenadas dos seus navios..." << std::endl;

        portaAvioesPlayer2();
        navioTanquePlayer2();
        navioTanquePlayer2();
        contratorpedeirosPlayer2();
        contratorpedeirosPlayer2();
        contratorpedeirosPlayer2();
        submarinosPlayer2();
        submarinosPlayer2();
        submarinosPlayer2();
        submarinosPlayer2();
    }

    void escolhaDosBarcos1(void){
        // Atribui os valores do tipo das casas a '0'
        for (int i = 0; i < linhas; ++i) {
            for (int j = 0; j < colunas; ++j) {
                for (int k = 1; k < tipo; ++k) {
                    player1Board[i][j][k] = '0';
                }
            }
        }

        std::cout << std::endl;
        std::cout << player1Name << ", escolha as coordenadas dos seus \nnavios..." << std::endl;

        portaAvioesPlayer1();
        navioTanquePlayer1();
        navioTanquePlayer1();
        contratorpedeirosPlayer1();
        contratorpedeirosPlayer1();
        contratorpedeirosPlayer1();
        submarinosPlayer1();
        submarinosPlayer1();
        submarinosPlayer1();
        submarinosPlayer1();
    }


    int startGame(void){
        system("cls");

        std::cout << "----------ESTRUTURA DE DADOS----------" << std::endl;
        std::cout << "======================================" << std::endl;
        std::cout << "-------------Batalha Naval------------" << std::endl;
        std::cout << "======================================" << std::endl << std::endl;
        std::cout << "Para que o jogo inicie, Jogador 1 e \nJogador 2 devem informar seus nomes..." << std::endl << std::endl;

        std::cout << "[ Jogador 1 ]: ";
        std::cin >> player1Name;
        std::cin.ignore(80, '\n');
        std::cout << std::endl;

        std::cout << "[ Jogador 2 ]: ";
        std::cin >> player2Name;
        std::cin.ignore(80, '\n');
        std::cout << std::endl;

        system("cls");
        apresentarTabelaJogador1(player1Name);
        escolhaDosBarcos1();
        std::cout << std::endl;

        // Loop para cada linha
        for (int i = 0; i < linhas; i++) {
            std::cout << i;
            // Loop para cada coluna
            for (int j = 0; j < colunas; j++) {
                    for (int k = 1; k < tipo; k++){
                        std::cout << "[" << player1Board[i][j][k] << "]";
                    }
            }
            std::cout << std::endl;
        }

        std::cout << std::endl << "Aperte <ENTER> para prosseguir... "; std::cin.get();

        system("cls");
        apresentarTabelaJogador2(player2Name);
        escolhaDosBarcos2();
        std::cout << std::endl;

        // Loop para cada linha
        for (int i = 0; i < linhas; i++) {
            std::cout << i;
            // Loop para cada coluna
            for (int j = 0; j < colunas; j++) {
                    for (int k = 1; k < tipo; k++){
                        std::cout << "[" << player2Board[i][j][k] << "]";
                    }
            }
            std::cout << std::endl;
        }

        std::cout << std::endl << "Aperte <ENTER> para prosseguir... "; std::cin.get();

        for (int i = 0; i < linhas; ++i) {
            for (int j = 0; j < colunas; ++j) {
                player1Board[i][j][0] = '-';
                player2Board[i][j][0] = '-';
            }
        }

        system("cls");
        std::cout << "----------ESTRUTURA DE DADOS----------" << std::endl;
        std::cout << "======================================" << std::endl;
        std::cout << "-------------Batalha Naval------------" << std::endl;
        std::cout << "======================================" << std::endl << std::endl;
        std::cout << "       [O jogo est� iniciado!!!]      " << std::endl << std::endl;
        std::cout << "======================================" << std::endl << std::endl;
        sleep(2);

        for (int turno = 0; turno <= totalTurnos; turno++) {
            realizarJogada(turno);
        }

        return 0;
    }

    int menuBatalhaNaval(void){

        int opcao = 1;
        // Inicializa a matriz com tra�os
        for (int i = 0; i < linhas; ++i) {
            for (int j = 0; j < colunas; ++j) {
                player1Board[i][j][0] = '-';
                player2Board[i][j][0] = '-';
                player1Board[i][j][1] = '0';
                player2Board[i][j][1] = '0';
            }
        }

        system("cls");
        while (opcao != 0){
            std::cout << "-------------ESTRUTURA DE DADOS-------------" << std::endl;
            std::cout << "============================================" << std::endl;
            std::cout << "----------------Batalha Naval---------------" << std::endl;
            std::cout << "============================================" << std::endl << std::endl;
            std::cout << "[       Bem-vindo ao Batalha Naval!!!      ]" << std::endl << std::endl;
            std::cout << "============================================" << std::endl;
            std::cout << "[1] Iniciar"<< std::endl;
            std::cout << "[0] Voltar para o Menu de Vetores e Matrizes"<< std::endl;
            std::cout << "============================================" << std::endl;

            std::cout << "Digite a op��o desejada: "; std::cin >> opcao;

            switch (opcao){
                case 1: startGame(); break;
                case 0: system("cls"); std::cout << "\n**Voltando para o Menu de Vetores e Matrizes...**"; break;
                default: system("cls"); std::cerr << "\n\n**Erro: Op��o indispon�vel... Tente novamente!**" << std::endl << std::endl;
            }
        }
        return 0;
    }

}batalhaNaval;

struct{

char checkWin(const int posWin[24][2], const char pos[3][3]) {
    for (int i = 0; i < 24; i += 3) {
        int x1 = posWin[i][0], y1 = posWin[i][1];
        int x2 = posWin[i + 1][0], y2 = posWin[i + 1][1];
        int x3 = posWin[i + 2][0], y3 = posWin[i + 2][1];

        if (pos[x1][y1] != '-' && pos[x1][y1] == pos[x2][y2] && pos[x1][y1] == pos[x3][y3]) {
            return pos[x1][y1];
        }
    }
    return ' ';
}


void printBoard(const char pos[3][3]) {
    std::cout << "  0 1 2" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << pos[i][j];
            if (j < 2) std::cout << "|";
        }
        std::cout << std::endl;
    }
}

int main() {
    const int posWin[24][2] = {
        {0, 0}, {0, 1}, {0, 2},
        {1, 0}, {1, 1}, {1, 2},
        {2, 0}, {2, 1}, {2, 2},
        {0, 0}, {1, 0}, {2, 0},
        {0, 1}, {1, 1}, {2, 1},
        {0, 2}, {1, 2}, {2, 2},
        {0, 0}, {1, 1}, {2, 2},
        {0, 2}, {1, 1}, {2, 0}
    };

    char pos[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    int xPlay = 0;
    bool win = false;

    while (!win) {
        system("cls");
        printBoard(pos);

        int coluna, linha;
        std::cout << "Informe a coluna e a linha (0 a 2): ";
        std::cin >> coluna >> linha;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (coluna >= 0 && coluna < 3 && linha >= 0 && linha < 3) {
            if (pos[coluna][linha] == '-') {
                pos[coluna][linha] = (xPlay % 2 == 0) ? 'X' : 'O';
                xPlay++;
            } else {
                std::cout << "Posi��o j� ocupada. Tente novamente.\n";
                continue;
            }

            char winner = checkWin(posWin, pos);

            if (winner != ' ' || xPlay == 9) {
                if (winner != ' ')
                    std::cout << "\nO jogador " << winner << " ganhou!\n";
                else
                    std::cout << "Empate!\n";

                win = true;
                std::cout << "\nDeseja voltar ao menu (M) ou reiniciar o jogo (R)? ";
                char choice;
                std::cin >> choice;
                std::cout << std::endl;

                if (choice == 'M' || choice == 'm') {
                    system("cls"); break;
                } else if (choice == 'R' || choice == 'r') {
                    xPlay = 0;

                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            pos[i][j] = '-';
                        }
                    }
                    win = false;
                } else {
                    std::cout << "Escolha inv�lida. O jogo ser� encerrado.\n";
                    break;
                }
            }
        } else {
            std::cout << "Entrada inv�lida. Tente novamente.\n";
        }
    }

    return 0;
}

}hashGame;

void vetoresMatrizes(void){
    int opcao = 1;

    std::setlocale(LC_ALL, "portuguese");

    while (opcao != 0){
        system("cls");
        std::cout << "-------ESTRUTURA DE DADOS-------" << std::endl;
        std::cout << "================================" << std::endl;
        std::cout << "---Menu de Vetores e Matrizes---" << std::endl;
        std::cout << "================================" << std::endl << std::endl;
        std::cout << "[1] Jogo da Velha" << std::endl;
        std::cout << "[2] Batalha Naval" << std::endl;
        std::cout << "[0] Voltar para o Menu Principal" << std::endl << std::endl;
        std::cout << "================================" << std::endl<< std::endl;
        std::cout << "Tecle a op��o desejada: ";

        std::cin >> opcao;
        std::cin.ignore(80, '\n');

        system("cls");

        switch (opcao){
            case 1: hashGame.main(); break;
            case 2: batalhaNaval.menuBatalhaNaval(); break;
            case 0: std::cout << "\n**Voltando para o Menu Principal...**"; break;
            default: system("cls"); std::cerr << "\n\n**Erro: Op��o indispon�vel... Tente novamente!**" << std::endl << std::endl;
        }
        sleep(1);
        system("cls");
    }
}

struct {

    int pilha[10];
    int contador = 0;

    int listarElementos(void) {
        int I = 0;

        system("cls");

        if (contador > 0) {
            std::cout << "----------ESTRUTURA DE DADOS----------" << std::endl;
            std::cout << "======================================" << std::endl;
            std::cout << "-----------Valores da Pilha-----------" << std::endl;
            std::cout << "======================================" << std::endl;

                for (I = 0; I < contador; I++) {
                    std::cout << "\nPosi��o [" << (I + 1) << "]: " << pilha[I] << std::endl;
                }

            std::cout << std::endl;
            std::cout << "======================================" << std::endl;
        } else {
            std::cout << "\nA pilha est� vazia!" << std::endl;
            std::cout << "\nVoltando para o menu...";
            sleep(1);
            system("cls");
            return 0;
        }

        std::cout << std::endl;

        std::cout << "Voltando para o menu...";
        sleep(7);
        system("cls");
        return 0;
    }

    int removerElementos(void){
        int I = 0;

        if (contador > 0 && contador <= 10){
            std::cout << "\nO seguinte valor foi removido da Pilha: " << pilha[contador - 1] << std::endl;

            contador--;

            if (contador == 1){
                std::cout << "\nExiste [" << 10 - (contador) << "] espa�o livre na Pilha!" << std::endl;
            } else {
                std::cout << "\nExistem [" << 10 - (contador) << "] espa�os livres na Pilha!" << std::endl;
            }
        }
        else
            std::cout << "\nA fila est� vazia!" << std::endl;

        sleep(3);
        system("cls");
        return 0;
    }

    int adicionarElementos(void){
        int valorAdicionado;

        if ((contador + 1) <= 10){
            std::cout << "\nAdicione o seguinte valor a Pilha: "; std::cin >> valorAdicionado;
            std::cin.ignore(80, '\n');

            pilha[contador] = valorAdicionado;
            contador++;

            std::cout << "\nO valor [" << valorAdicionado << "] foi adicionado na posi��o [" << contador << "] da Pilha! " << std::endl << std::endl;
        } else if ((contador + 1) > 10){
            std::cout << "\nA Pilha est� cheia!" << std::endl << std::endl;
        }

        sleep(1);
        system("cls");
        return 0;
    }

    int menuPilha(void){
        int opcao;

        std::setlocale(LC_ALL, "portuguese");

        while (opcao != 0){
            std::cout << "--------ESTRUTURA DE DADOS--------" << std::endl;
            std::cout << "==================================" << std::endl;
            std::cout << "------------Menu Pilha------------" << std::endl;
            std::cout << "==================================" << std::endl << std::endl;
            std::cout << "[1] Adicionar elemento" << std::endl;
            std::cout << "[2] Remover elemento" << std::endl;
            std::cout << "[3] Listar elementos" << std::endl;
            std::cout << "[0] Voltar para o menu principal" << std::endl << std::endl;
            std::cout << "==================================" << std::endl << std::endl;
            std::cout << "Tecle a op��o desejada: ";

            std::cin >> opcao;
            std::cin.ignore(80, '\n');

            switch (opcao){
                case 1: adicionarElementos(); break;
                case 2: removerElementos(); break;
                case 3: listarElementos(); break;
                case 0: std::cout << "\n**Voltando para o Menu Principal...**"; break;
                default: system("cls"); std::cerr << "\n\n**Erro: Op��o indispon�vel... Tente novamente!**" << std::endl << std::endl;
            }
        }

        sleep(1);
        system("cls");
        return 0;
    }
} minhaPilha;

struct {

    int fila[10];
    int contador = 0;

    int listarElementos(void) {
        int I = 0;

        system("cls");

        if (contador > 0) {
            std::cout << "----------ESTRUTURA DE DADOS---------" << std::endl;
            std::cout << "=====================================" << std::endl;
            std::cout << "-----------Valores da Fila-----------" << std::endl;
            std::cout << "=====================================" << std::endl;

                for (I = 0; I < contador; I++) {
                    std::cout << "\nPosi��o [" << (I + 1) << "]: " << fila[I] << std::endl;
                }

            std::cout << std::endl;
            std::cout << "=====================================" << std::endl;
        } else {
            std::cout << "\nA fila est� vazia!" << std::endl;
            std::cout << "\nVoltando para o menu...";
            sleep(1);
            system("cls");
            return 0;
        }

        std::cout << std::endl;

        std::cout << "Voltando para o menu...";
        sleep(7);
        system("cls");
        return 0;
    }

    int removerElementos(void){
        int I = 0;

        if (contador > 0 && contador <= 10){
            std::cout << "\nO seguinte valor foi removido da fila: " << fila[0] << std::endl;

            for (int I = 0; I < 10; I++){
                fila[I] = fila[I + 1];
            }

            contador--;

            std::cout << "\nExistem [" << 10 - (contador) << "] espa�os livres na Fila!" << std::endl;
        }
        else
            std::cout << "\nA fila est� vazia!" << std::endl;

        sleep(3);
        system("cls");
        return 0;
    }

    int adicionarElementos(void){
        int valorAdicionado;

        if ((contador + 1) <= 10){
            std::cout << "\nAdicione o seguinte valor a Fila: "; std::cin >> valorAdicionado;
            std::cin.ignore(80, '\n');

            fila[contador] = valorAdicionado;
            contador++;

            std::cout << "\nO valor [" << valorAdicionado << "] foi adicionado na posi��o [" << contador << "] da fila! " << std::endl << std::endl;
        } else if ((contador + 1) > 10){
            std::cout << "\nA fila est� cheia!" << std::endl << std::endl;
        }

        sleep(1);
        system("cls");
        return 0;
    }

    int menuFila(void){
        int opcao;

        std::setlocale(LC_ALL, "portuguese");

        while (opcao != 0){
            std::cout << "--------ESTRUTURA DE DADOS-------" << std::endl;
            std::cout << "=================================" << std::endl;
            std::cout << "------------Menu Fila------------" << std::endl;
            std::cout << "=================================" << std::endl << std::endl;
            std::cout << "[1] Adicionar elemento" << std::endl;
            std::cout << "[2] Remover elemento" << std::endl;
            std::cout << "[3] Listar elementos" << std::endl;
            std::cout << "[0] Voltar para o menu principal" << std::endl << std::endl;
            std::cout << "=================================" << std::endl << std::endl;
            std::cout << "Tecle a op��o desejada: ";

            std::cin >> opcao;
            std::cin.ignore(80, '\n');

            switch (opcao){
                case 1: adicionarElementos(); break;
                case 2: removerElementos(); break;
                case 3: listarElementos(); break;
                case 0: std::cout << "\n**Voltando para o Menu Principal...**"; break;
                default: system("cls"); std::cerr << "\n\n**Erro: Op��o indispon�vel... Tente novamente!**" << std::endl << std::endl;
            }
        }

        sleep(1);
        system("cls");
        return 0;
    }
} minhaFila;

int main(void){
    int opcao = 1;

    std::setlocale(LC_ALL, "portuguese");
    while (opcao != 0){
        std::cout << "------ESTRUTURA DE DADOS------" << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "--------Menu Principal--------" << std::endl;
        std::cout << "==============================" << std::endl << std::endl;
        std::cout << "[1] Fila" << std::endl;
        std::cout << "[2] Pilha" << std::endl;
        std::cout << "[3] Vetores e Matrizes" << std::endl;
        std::cout << "[4] Ponteiros" << std::endl;
        std::cout << "[5] Lista" << std::endl;
        std::cout << "[0] Encerrar Programa" << std::endl << std::endl;
        std::cout << "==============================" << std::endl<< std::endl;
        std::cout << "Tecle a op��o desejada: ";

        std::cin >> opcao;
        std::cin.ignore(80, '\n');

        system("cls");

        switch (opcao){
            case 1: minhaFila.menuFila(); break;
            case 2: minhaPilha.menuPilha(); break;
            case 3: vetoresMatrizes(); break;
            case 4: ponteiros(); break;
            case 5: listaEncadeada.main(); break;
            case 0: break;
            default: system("cls"); std::cerr << "\n\n**Erro: Op��o indispon�vel... Tente novamente!**" << std::endl << std::endl;
        }
    }

    std::cout << "Tecle <ENTER> para encerrar o programa... " << std::endl;
    return 0;
}

