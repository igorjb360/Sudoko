
/*
  * Cicero Pizetta Pizutti
  * Igor Jose Bourscheid
  * Pablo da Silva Marques
  *
  * Às diretrizes do professor: Rafael Ballottin Martins
  * Junho/2021
*/

#include <iostream>
using std::cout, std::cin, std::endl;
#include <locale.h>
#include <time.h>

#define TAM 9

int main() {
  setlocale(LC_ALL, "Portuguese");

  int escolha=0, pause, aleatorio;
  int linha, coluna, valor;
  int contadorLinhas=0;
  int contadorValor=0;
  int contadorEspacos=0;
  int dificuldade=2, espacosVazios=53; //POR PADRÃO, A DIFICULDADE SERÁ A MÉDIA

  int matrizPrincipal[TAM][TAM]= 
    {{4,9,5,2,8,7,3,6,1},
    {7,2,8,6,1,3,4,9,5},
    {3,6,1,9,5,4,7,2,8},
    {6,5,3,8,4,9,2,1,7},
    {9,8,4,1,7,2,6,5,3},
    {2,1,7,5,3,6,9,8,4},
    {1,3,2,4,6,5,8,7,9},
    {5,4,6,7,9,8,1,3,2},
    {8,7,9,3,2,1,5,4,6}};
  int matrizTransposta[TAM][TAM];
  int matrizLinhaInvertida[TAM][TAM];
  int matrizColunaInvertida[TAM][TAM];
  int matrizJogo[TAM][TAM];

  while(escolha != 4) {
    system("clear");
    cout<<"==================     SUDOKU     =================\n\n[1] Novo Jogo | [2] cotinuar | [3] Sobre | [4] Modo de jogo\n\n===================================================\n\nSua escolha: ";
    cin>>escolha;
    system("clear");
    contadorEspacos=0;//PARA GARANTIR QUE O CONTADOR E ESPAÇOS ESTEJAM ZERADOS 

    switch(escolha) {
      case 1: 
        srand(time(NULL));
        aleatorio=rand()%4; 
        
        contadorValor=0;
        contadorEspacos=0;
        contadorLinhas=0;

        switch (aleatorio) {

          //CASE REFERENTE A MATRIZ PRINCIPAL
          case 0:
          /* EXIBIÇÃO DA MATRIZ GABARITO PARA FINS DE TESTE
            cout<<"Matriz principal"<<endl;
            cout<<"      C0  C1  C2  C3  C4  C5  C6  C7  C8\n\n      -----------------------------------"<<endl;
            for (int i=0; i < TAM; i++) {
              cout<<"L"<<contadorLinhas++<<"  ";
              for (int j=0; j< TAM; j++) {
                cout<<" | "<<matrizPrincipal[i][j];
              }
              cout<<" |";
              cout<<endl<<"      -----------------------------------"<<endl;
            }
            cout<<endl<<endl<<endl;
            contadorLinhas=0;
            */
        
           
            for (int i=0; i < TAM; i++){
              for (int j=0; j< TAM; j++) {
                int aleatorio2=rand()%2;            
                if (aleatorio2==0) {
                  matrizJogo[i][j]=0;
                  contadorEspacos++;
                }
                else {
                  matrizJogo[i][j]=matrizPrincipal[i][j];
                }
              }  
            }
            
            
            cout<<"      C0  C1  C2  C3  C4  C5  C6  C7  C8\n\n      -----------------------------------"<<endl;
            for (int i=0; i < TAM; i++){
              cout<<"L"<<contadorLinhas++<<"  ";
              for (int j=0; j< TAM; j++) {
                if (contadorEspacos<espacosVazios && matrizJogo[i][j]!=0) {
                  int aleatorio2=rand()%2;

                  if (aleatorio2==0) {
                    matrizJogo[i][j]=0;
                    cout<<" | "<<" ";
                    contadorEspacos++;
                  }
                  else {    
                    matrizJogo[i][j]=matrizPrincipal[i][j];
                    cout<<" | "<<matrizJogo[i][j];
                  }
                }
                else if (matrizJogo[i][j]==0){
                  cout<<" | "<<" ";
                }    
                else {
                  cout<<" | "<<matrizJogo[i][j];
                  
                }
                    
              }
              cout<<" |";
              cout<<endl<<"      -----------------------------------"<<endl;
            }
            cout<<endl<<"  ** DIGITE [100] NA LINHA PARA SAIR **"<<endl<<endl;

           
            do {
              do {
                cout<<"Linha: ";
                cin>>linha;
                if (linha !=100 && (linha>8 || linha<0)) { //VERIFICA SE O VALOR PARA LINHA É VÁLIDO
                  while (linha>8 || linha<0) {
                    cout<<"** Linha inexistente. Tente novamente **"<<endl;
                    cout<<"Linha: ";
                    cin>>linha;
                  }
                }
                else if (linha==100){ //CAUSA O BREAK DO SEGUNDO DO/WHILE
                  break;
                }
                cout<<"Coluna: ";
                cin>>coluna;
                if (coluna>8 || coluna<0) { //VERIFICA SE O VALOR PARA COLUNA É VÁLIDO
                  while (coluna>8 || coluna<0) {
                    cout<<"** Coluna inexistente. Tente novamente **"<<endl;
                    cout<<"Coluna: ";
                    cin>>coluna;
                  }
                }

                if (matrizJogo[linha][coluna]!=0) { 
                  cout<<"** Posição inválida. Tente novamente **"<<endl;
                } 
                else {
                  cout<<"Valor: ";
                  cin>>valor;
                  contadorValor++;
                }
              } while (matrizJogo[linha][coluna]!=0);

              if (linha==100)
                break;

              while (valor!=matrizPrincipal[linha][coluna]) { 
                cout<<"** Valor incorreto. Tente novamente **"<<endl;
                cout<<"Valor: ";
                cin>>valor;
                contadorValor++;
              }

              
              if (valor==matrizPrincipal[linha][coluna]) {
                matrizJogo[linha][coluna]=valor;
                contadorLinhas=0;
                system("clear");
                cout<<"      C0  C1  C2  C3  C4  C5  C6  C7  C8\n\n      -----------------------------------"<<endl;
                for(int i=0; i<TAM; i++) {
                  cout<<"L"<<contadorLinhas++<<"  ";
                  for (int j=0; j<TAM; j++) {
                    if (matrizJogo[i][j]==0) {
                      cout<<" | "<<" ";
                    }
                    else {
                      cout<<" | "<<matrizJogo[i][j];
                    }
                  }
                  cout<<" | ";
                  cout<<endl<<"      -----------------------------------"<<endl;
                }
                contadorEspacos--;
              }
              cout<<endl<<"  ** DIGITE [100] NA LINHA PARA SAIR **"<<endl<<endl;
            
            } while (matrizJogo[linha][coluna]==matrizPrincipal[linha][coluna] && contadorEspacos!=0);

            
            if (contadorEspacos==0) {
              system("clear");
              cout<<endl<<endl<<"\t"<<"**********************************************\n\t*\t\t\t\t\t\t\t\t\t\t\t *\n\t*  Parabéns! Sua paciência é impressionante  *\n\t*\t\t\t\t\t\t\t\t\t\t\t *\n\t**********************************************"<<endl<<endl<<endl<<"Dificuldade: "<<dificuldade<<endl<<"Jogadas realizadas: "<<contadorValor<<endl<<"Erros cometidos: "<<contadorValor-espacosVazios<<endl<<endl<<"[0] Continuar"<<endl;
              cin>>pause;
            }
          break;
          
          //CASE REFERENTE A MATRIZ TRANSPOSTA
          case 1:
            //COUTS ABAIXO PODEM SER DESCOMENTADOS PARA FINS DE TESTE
            //cout<<"       C0  C1  C2  C3  C4  C5  C6  C7  C8\n\n      -----------------------------------"<<endl;
            for (int i=0; i < TAM; i++){
              //cout<<"L"<<contadorLinhas++<<"  ";
              for (int j=0; j< TAM; j++) {
                matrizTransposta[i][j]=matrizPrincipal[j][i]; 
                //cout<<" | "<<matrizTransposta[i][j];
              }
              //cout<<" |";
              //cout<<endl<<"      -----------------------------------"<<endl;
            }
            //cout<<endl<<endl<<endl;
            contadorLinhas=0; 
            
            //PREENCHE A MATRIZ JOGO
            for (int i=0; i < TAM; i++){
              for (int j=0; j< TAM; j++) {
                int aleatorio2=rand()%2;            
                if (aleatorio2==0) {
                  matrizJogo[i][j]=0;
                  contadorEspacos++;
                }
                else {
                  matrizJogo[i][j]=matrizTransposta[i][j];
                }
              }  
            }
            
            //EXIBE A MATRIZ JOGO 1
            cout<<"       C0  C1  C2  C3  C4  C5  C6  C7  C8\n\n      -----------------------------------"<<endl;
            for (int i=0; i < TAM; i++){
              cout<<"L"<<contadorLinhas++<<"  ";
              for (int j=0; j< TAM; j++) {
                if (contadorEspacos<espacosVazios && matrizJogo[i][j]!=0) {
                  int aleatorio2=rand()%2;
                  if (aleatorio2==0) {
                    matrizJogo[i][j]=0;
                    cout<<" | "<<" ";
                    contadorEspacos++;
                  }
                  else {
                    matrizJogo[i][j]=matrizTransposta[i][j];
                    cout<<" | "<<matrizJogo[i][j];
                  }
                }
                 else if (matrizJogo[i][j]==0){
                  cout<<" | "<<" ";
                }    
                else {
                  cout<<" | "<<matrizJogo[i][j];
                }        
              }
              cout<<" |";
              cout<<endl<<"      -----------------------------------"<<endl;
            }
            cout<<endl<<"  ** DIGITE [100] NA LINHA PARA SAIR **"<<endl<<endl;

            do {
              do {
                cout<<"Linha: ";
                cin>>linha;
                if (linha !=100 && (linha>8 || linha<0)) {
                  while (linha>8 || linha<0) {
                    cout<<"** Linha inexistente. Tente novamente **"<<endl;
                    cout<<"Linha: ";
                    cin>>linha;
                  }
                }
                else if (linha==100){
                  break;
                }
                cout<<"Coluna: ";
                cin>>coluna;
                if (coluna>8 || coluna<0) {
                  while (coluna>8 || coluna<0) {
                    cout<<"** Coluna inexistente. Tente novamente **"<<endl;
                    cout<<"Coluna: ";
                    cin>>coluna;
                  }
                }

                if (matrizJogo[linha][coluna]!=0) {
                  cout<<"** Posição inválida. Tente novamente **"<<endl;
                } 
                else {
                  cout<<"Valor: ";
                  cin>>valor;
                  contadorValor++;
                }
              } while (matrizJogo[linha][coluna]!=0);

              if (linha==100)
                break;

              while (valor!=matrizTransposta[linha][coluna]) {
                cout<<"** Valor incorreto. Tente novamente **"<<endl;
                cout<<"Valor: ";
                cin>>valor;
                contadorValor++;
              }

              if (valor==matrizTransposta[linha][coluna]) {
                matrizJogo[linha][coluna]=valor;
                contadorLinhas=0;
                system("clear");
                cout<<"      C0  C1  C2  C3  C4  C5  C6  C7  C8\n\n      -----------------------------------"<<endl;
                for(int i=0; i<TAM; i++) {
                  cout<<"L"<<contadorLinhas++<<"  ";
                  for (int j=0; j<TAM; j++) {
                    if (matrizJogo[i][j]==0) {
                      cout<<" | "<<" ";
                    }
                    else {
                      cout<<" | "<<matrizJogo[i][j];
                    }
                  }
                  cout<<" | ";
                  cout<<endl<<"      -----------------------------------"<<endl;
                }
                contadorEspacos--;
              }
              cout<<endl<<"  ** DIGITE [100] NA LINHA PARA SAIR **"<<endl<<endl;
            
            } while (matrizJogo[linha][coluna]==matrizTransposta[linha][coluna] && contadorEspacos!=0);

            if (contadorEspacos==0) {
              system("clear");
              cout<<endl<<endl<<"\t"<<"**********************************************\n\t*\t\t\t\t\t\t\t\t\t\t\t *\n\t*  Parabéns! Sua paciência é impressionante  *\n\t*\t\t\t\t\t\t\t\t\t\t\t *\n\t**********************************************"<<endl<<endl<<endl<<"Dificuldade: "<<dificuldade<<endl<<"Jogadas realizadas: "<<contadorValor<<endl<<"Erros cometidos: "<<contadorValor-espacosVazios<<endl<<endl<<"[0] Continuar"<<endl;
              cin>>pause;
            }
          break;

         
          case 2: 
            //OS COMENTÁRIOS ABAIXO SÃO PARA FINS DE TESTE
            //cout<<"Matriz invertida por linha"<<endl; 
            //cout<<"       C0  C1  C2  C3  C4  C5  C6  C7  C8\n\n      -----------------------------------"<<endl;
            for(int i=TAM-1; i >= 0; i--){ 
              //cout<<"L"<<contadorLinhas++<<"  ";
              for(int j=0; j < TAM; j++) {
                matrizLinhaInvertida[i][j]=matrizPrincipal[i][j];
                //cout<<" | "<<matrizLinhaInvertida[i][j];
              }
              //cout<<" |";
              //cout<<endl<<"      -----------------------------------"<<endl;
            }
            //cout<<endl<<endl<<endl;
            contadorLinhas=0;

            //PREENCHE A MATRIZ JOGO
            for(int i=TAM-1; i >= 0; i--){ //LINHAS CONTINUAM INVERTIDAS
              for(int j=0; j < TAM; j++) {
                int aleatorio2=rand()%2;            
                if (aleatorio2==0) {
                  matrizJogo[i][j]=0;
                  contadorEspacos++;
                }
                else {
                  matrizJogo[i][j]=matrizLinhaInvertida[i][j];
                }
              }  
            }
            
            //EXIBE A MATRIZ JOGO
            cout<<"       C0  C1  C2  C3  C4  C5  C6  C7  C8\n\n      -----------------------------------"<<endl;
            for(int i=TAM-1; i >= 0; i--){ //LINHAS CONTINUAM INVERTIDAS
              cout<<"L"<<contadorLinhas++<<"  ";
              for(int j=0; j < TAM; j++) {
                if (contadorEspacos<espacosVazios && matrizJogo[i][j]!=0) {
                  int aleatorio2=rand()%2;
                  if (aleatorio2==0) {
                    matrizJogo[i][j]=0;
                    cout<<" | "<<" ";
                    contadorEspacos++;
                  }
                  else {
                    matrizJogo[i][j]=matrizLinhaInvertida[i][j];
                    cout<<" | "<<matrizJogo[i][j];
                  }
                }
                else if (matrizJogo[i][j]==0){
                  cout<<" | "<<" ";
                }    
                else {
                  cout<<" | "<<matrizJogo[i][j];
                }        
              }
              cout<<" |";
              cout<<endl<<"      -----------------------------------"<<endl;
            }
            cout<<endl<<"  ** DIGITE [100] NA LINHA PARA SAIR **"<<endl<<endl;

            do {
              do {
                cout<<"Linha: ";
                cin>>linha;
                if (linha !=100 && (linha>8 || linha<0)) {
                  while (linha>8 || linha<0) {
                    cout<<"** Linha inexistente. Tente novamente **"<<endl;
                    cout<<"Linha: ";
                    cin>>linha;
                  }
                }
                else if (linha==100){
                  break;
                }

               
               
                switch (linha) {
                  case 0:
                    linha=8;
                  break;
                  case 1:
                    linha=7;
                  break;  
                  case 2:
                    linha=6;
                  break;
                  case 3:
                    linha=5;
                  break;  
                  case 4:
                    linha=4;
                  break;
                  case 5: 
                    linha=3;
                  break;
                  case 6:
                    linha=2;
                  break;  
                  case 7:
                    linha=1;
                  break;
                  case 8:
                    linha=0;
                  break;  
                }

                cout<<"Coluna: ";
                cin>>coluna;
                if (coluna>8 || coluna<0) {
                  while (coluna>8 || coluna<0) {
                    cout<<"** Coluna inexistente. Tente novamente **"<<endl;
                    cout<<"Coluna: ";
                    cin>>coluna;
                  }
                }

                if (matrizJogo[linha][coluna]!=0) {
                  cout<<"** Posição inválida. Tente novamente **"<<endl;
                } 
                else {
                  cout<<"Valor: ";
                  cin>>valor;
                  contadorValor++;
                }
              } while (matrizJogo[linha][coluna]!=0);

              if (linha==100)
                break;

              while (valor!=matrizLinhaInvertida[linha][coluna]) {
                cout<<"** Valor incorreto. Tente novamente **"<<endl;
                cout<<"Valor: ";
                cin>>valor;
                contadorValor++;
              }

              if (valor==matrizLinhaInvertida[linha][coluna]) {
                matrizJogo[linha][coluna]=valor;
                contadorLinhas=0;
                system("clear");
                cout<<"      C0  C1  C2  C3  C4  C5  C6  C7  C8\n\n      -----------------------------------"<<endl;
                for(int i=TAM-1; i >= 0; i--) { //LINHAS CONTINUAM INVERTIDAS
                  cout<<"L"<<contadorLinhas++<<"  ";
                  for(int j=0; j < TAM; j++) {
                    if (matrizJogo[i][j]==0) {
                      cout<<" | "<<" ";
                    }
                    else {
                      cout<<" | "<<matrizJogo[i][j];
                    }
                  }
                  cout<<" | ";
                  cout<<endl<<"      -----------------------------------"<<endl;
                }
                contadorEspacos--;
              }
              cout<<endl<<"  ** DIGITE [100] NA LINHA PARA SAIR **"<<endl<<endl;
            
            } while (matrizJogo[linha][coluna]==matrizLinhaInvertida[linha][coluna] && contadorEspacos!=0);
            
            if (contadorEspacos==0) {
              system("clear");
              cout<<endl<<endl<<"\t"<<"**********************************************\n\t*\t\t\t\t\t\t\t\t\t\t\t *\n\t*  Parabéns! Sua paciência é impressionante  *\n\t*\t\t\t\t\t\t\t\t\t\t\t *\n\t**********************************************"<<endl<<endl<<endl<<"Dificuldade: "<<dificuldade<<endl<<"Jogadas realizadas: "<<contadorValor<<endl<<"Erros cometidos: "<<contadorValor-espacosVazios<<endl<<endl<<"[0] Continuar"<<endl;
              cin>>pause;
            }
          break;

         
          case 3:
            //COMENTÁRIOS BAIXO SERVEM PARA TESTES, APENAS      
            //cout<<"Matriz invertida por coluna"<<endl; 
            //cout<<"       C0  C1  C2  C3  C4  C5  C6  C7  C8\n\n      -----------------------------------"<<endl;
            for (int i=0; i < TAM; i++){
              //cout<<"L"<<contadorLinhas++<<"  ";
              for (int j=TAM-1; j >= 0; j--) { //POR SE TRATAR DE UMA MATRIZ COM AS COLUNAS INVERTIDAS, ESSE FOR ATUA DE FORMA DECRESCENTE
                matrizColunaInvertida[i][j]=matrizPrincipal[i][j];
                //cout<<" | "<<matrizColunaInvertida[i][j];
              }
              //cout<<" |";
              //cout<<endl<<"      -----------------------------------"<<endl;
            }
            //cout<<endl<<endl<<endl;
            contadorLinhas=0;

            //PREENCHE A MATRIZ JOGO
            for (int i=0; i < TAM; i++){
              for (int j=TAM-1; j >= 0; j--) { //AS COLUNAS CONTINUAM INVERTIDAS
                int aleatorio2=rand()%2;            
                if (aleatorio2==0) {
                  matrizJogo[i][j]=0;
                  contadorEspacos++;
                }
                else {
                  matrizJogo[i][j]=matrizColunaInvertida[i][j];
                }
              }  
            }
            
            //EXIBI A MATRIZ JOGO
            cout<<"       C0  C1  C2  C3  C4  C5  C6  C7  C8\n\n      -----------------------------------"<<endl;
            for (int i=0; i < TAM; i++){
              cout<<"L"<<contadorLinhas++<<"  ";
              for (int j=TAM-1; j >= 0; j--) { //AS COLUNAS CONTINUAM INVERTIDAS
                if (contadorEspacos<espacosVazios && matrizJogo[i][j]!=0) {
                  int aleatorio2=rand()%2;
                  if (aleatorio2==0) {
                    matrizJogo[i][j]=0;
                    cout<<" | "<<" ";
                    contadorEspacos++;
                  }
                  else {
                    matrizJogo[i][j]=matrizColunaInvertida[i][j];
                    cout<<" | "<<matrizJogo[i][j];
                  }
                }
                else if (matrizJogo[i][j]==0){
                  cout<<" | "<<" ";
                }    
                else {
                  cout<<" | "<<matrizJogo[i][j];
                }        
              }
              cout<<" |";
              cout<<endl<<"      -----------------------------------"<<endl;
            }
            cout<<endl<<"  ** DIGITE [100] NA LINHA PARA SAIR **"<<endl<<endl;
            
            do {
              do {
                cout<<"Linha: ";
                cin>>linha;
                if (linha !=100 && (linha>8 || linha<0)) {
                  while (linha>8 || linha<0) {
                    cout<<"** Linha inexistente. Tente novamente **"<<endl;
                    cout<<"Linha: ";
                    cin>>linha;
                  }
                }
                else if (linha==100){
                  break;
                }
                cout<<"Coluna: ";
                cin>>coluna;
                if (coluna>8 || coluna<0) {
                  while (coluna>8 || coluna<0) {
                    cout<<"** Coluna inexistente. Tente novamente **"<<endl;
                    cout<<"Coluna: ";
                    cin>>coluna;
                  }
                }

                //COMO AS COLUNAS ESTÃO EM POSIÇÕES INVERTIDAS, ESSE SWITCH GARANTIRÁ A OPERAÇÃO PRETENDIDA PELO USUÁRIO ESTEJA CORRETAMENTE
                //OBSERVE, A MATRIZ EXIBIDA PARA O USUÁRIO ESTÁ CORRETA, MAS A COMPARAÇÃO ENTRE OS RESULTADOS RESULTARÁ EM ERRO SEM ESSE SWITCH
                switch (coluna) {
                  case 0:
                    coluna=8;
                  break;
                  case 1:
                    coluna=7;
                  break;  
                  case 2:
                    coluna=6;
                  break;
                  case 3:
                    coluna=5;
                  break;  
                  case 4:
                    coluna=4;
                  break;
                  case 5: 
                    coluna=3;
                  break;
                  case 6:
                    coluna=2;
                  break;  
                  case 7:
                    coluna=1;
                  break;
                  case 8:
                    coluna=0;
                  break;  
                }

                if (matrizJogo[linha][coluna]!=0) {
                  cout<<"** Posição inválida. Tente novamente **"<<endl;
                } 
                else {
                  cout<<"Valor: ";
                  cin>>valor;
                  contadorValor++;
                }
              } while (matrizJogo[linha][coluna]!=0);

              if (linha==100)
                break;

              while (valor!=matrizColunaInvertida[linha][coluna]) {
                cout<<"** Valor incorreto. Tente novamente **"<<endl;
                cout<<"Valor: ";
                cin>>valor;
                contadorValor++;
              }

              if (valor==matrizColunaInvertida[linha][coluna]) {
                matrizJogo[linha][coluna]=valor;
                contadorLinhas=0;
                system("clear");
                cout<<"      C0  C1  C2  C3  C4  C5  C6  C7  C8\n\n      -----------------------------------"<<endl;
                for(int i=0; i<TAM; i++) {
                  cout<<"L"<<contadorLinhas++<<"  ";
                  for (int j=TAM-1; j >= 0; j--) { //AS COLUNAS CONTINUAM INVERTIDAS
                    if (matrizJogo[i][j]==0) {
                      cout<<" | "<<" ";
                    }
                    else {
                      cout<<" | "<<matrizJogo[i][j];
                    }
                  }
                  cout<<" | ";
                  cout<<endl<<"      -----------------------------------"<<endl;
                }
                contadorEspacos--;
              }
              cout<<endl<<"  ** DIGITE [100] NA LINHA PARA SAIR **"<<endl<<endl;
            
            } while (matrizJogo[linha][coluna]==matrizColunaInvertida[linha][coluna] && contadorEspacos!=0);

            if (contadorEspacos==0) {
              system("clear");
              cout<<endl<<endl<<"\t"<<"**********************************************\n\t*\t\t\t\t\t\t\t\t\t\t\t *\n\t*  Parabéns! Sua paciência é impressionante  *\n\t*\t\t\t\t\t\t\t\t\t\t\t *\n\t**********************************************"<<endl<<endl<<endl<<"Dificuldade: "<<dificuldade<<endl<<"Jogadas realizadas: "<<contadorValor<<endl<<"Erros cometidos: "<<contadorValor-espacosVazios<<endl<<endl<<"[0] Continuar"<<endl;
              cin>>pause;
            }
          break;
        }
      break; 

      case 2:
        cout<<"===================================================\n\t\t\t\t\t DIFICULDADE\n===================================================\n\n[1] Fácil: exibe 50% dos valores ao iniciar\n[2] Média: exibe 35% dos valores ao iniciar\n[3] Difícil: exibe 15% dos valores ao iniciar\n\n[0] Voltar: ";
        cin>>dificuldade;

        if (dificuldade==1)
          espacosVazios=41;

        else if (dificuldade==3)
          espacosVazios=69;

        else {
          dificuldade=2;
          espacosVazios=53;
        }
      break;

      case 3:
        cout<<"===================================================\n\t\t\t\t\tSOBRE O GAME\n===================================================\n\nDesenvolvedores:\n\tCicero Pizetta Pizutti\n\tIgor José Bourscheid\n\tPablo da Silva Marques\n\nDesenvolvido em junho/2021, sob as diretrizes de:\n\tProfessor Rafael Ballottin Martins\n\t- Algoritmos e Programação\n\n[0] Voltar: ";
        cin>>pause;
      break;
    }
  }
  return 0;
}