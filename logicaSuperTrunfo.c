#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);
    
    //Variáveis declaradas de cada carta registrada - Total de duas cartas
    char EstadoAlagoas = 'A',EstadoAmazonas ='B';
    char CodigoCarta1[4] = "A01", CodigoCarta2[4] = "B02";
    char NomeCidade1[50] = "MACEIO", NomeCidade2[50] = "MANAUS";
    unsigned long int PopulacaoMaceio = 957916, PopulacaoManaus = 2279686;
    float AreaemKmMaceio = 75000.00, AreaemKmManaus = 75000.00;
    float PibMaceio = 27484016.31, PibManaus = 103281436.04;//Pib declarado em reais
    int PontTuristMaceio = 30, PontTuristManaus = 30;
    
    //Declaração das variáveis que armazenarão a densidade populacional e Pib per capita de Maceio e Manaus
    float DensPopMaceio;
    float DensPopManaus;
    float PibPerCapMaceio;
    float PibPerCapManaus;

    //Declaração variáveis densidade populacional invertida Maceio e Manaus
    float DensPopInvMaceio; 
    float DensPopInvManaus;  

    //Declaração variáveis Super Poder Maceio e Manaus
    float SuperPoderMaceio;
    float SuperPoderManaus;

    //Cálculo densidade demográfica e Pib per capita Maceio
    DensPopMaceio = (float)PopulacaoMaceio/ AreaemKmMaceio; //Conversão explicita para igualar o tipo dos números da divisão
    PibPerCapMaceio = PibMaceio / PopulacaoMaceio; 

    //Cálculo densidade demográfica e Pib per capita Manaus
    DensPopManaus = (float)PopulacaoManaus / AreaemKmManaus; //Conversão explicita para igualar o tipo dos números da divisão
    PibPerCapManaus = PibManaus / PopulacaoManaus; 

    //Cálculo densidade populacionalinvertida Maceio e Manaus
    DensPopInvMaceio = (float)1/DensPopMaceio;
    DensPopInvManaus = (float)1/DensPopManaus; 

    //Cálculo do Super Poder Maceio 
    SuperPoderMaceio = (float)PopulacaoMaceio + AreaemKmMaceio + PibMaceio + PibPerCapMaceio + DensPopInvMaceio + (float)PontTuristMaceio;

    //Cálculo do Super Poder Manaus
    SuperPoderManaus = (float)PopulacaoManaus + AreaemKmManaus + PibManaus + PibPerCapManaus + DensPopInvManaus + (float)PontTuristManaus; 

    //Variável controle do Switch Case
    int Opcao1Jogador1,Opcao1Jogador2,Opcao2Jogador1,Opcao2Jogador2;

    //Variáveis auxiliares para comparação das cartas
    unsigned long PopJog1, PopJog2;
    float AreaJog1, AreaJog2, PibJog1, PibJog2, DensJog1, DensJog2, PibPerCapJog1, PibPerCapJog2, SupPodJog1, SupPodJog2;
    int PonTurJog1, PonTurJog2;

    //Instruções para os jogadores
    //printf("Atenção usuário, utilize letra maiúscula, sem acento e ponto como separador de dezenas!!!\n");
        printf("***** Instruções aos Jogadores *****\n");
        printf("\n1. O primeiro jogador escolherá entre a carta A ou B.\n");
        printf("\n2. O segundo jogador ficará com a carta restante.\n");
        printf("\n3. A cada rodada selecione um atributo para comparação.\n");
        printf("\n4. O atributo da primeira rodada não poderá ser escolhido na segunda rodada.\n");
        printf("\n5. Ao final das duas rodadas teremos um grande vencedor.\n");
    
    //Variáveis que indicam a letra das cartas e a opção dos jogadores
    char CartaA = 'A';
    char CartaB = 'B';
    char OpJog1, OpJog2;

    //Solicitando ao jogador 1 para escolher entre a carta A e B
    printf("\n***** Escolhendo a carta *****\n");
    printf("\nJogador nº 1, escolha entre a carta A e B: ");
    scanf(" %c", &OpJog1);

    //Verificando se o valor digitado está correto, se não encerra o programa
    if((OpJog1 != 'A') && (OpJog1 != 'a') && (OpJog1 != 'B') && (OpJog1 != 'b')){
        printf("\nValor inválido!\n");
        return 1;
    }

    //Imprimi na tela qual a letra da carta que foi escolhida
    (OpJog1 == 'A' || OpJog1 == 'a') ? printf("\nA carta selecionada foi a A - Macéio!\n") : printf("\nA carta selecionada foi a B - Manaus!\n");

    //Informando qual é a rodada da partida
    printf("\n----- 1ª Rodada de Comparações -----\n");

    //Solicitação ao jogador nº 1 para escolher o primeiro atributo
    printf("\n***** Atributos para comparação: *****\n");
    printf("\n1. População\n");
    printf("2. Área em Km²\n");
    printf("3. Pib\n");
    printf("4. Ponto Turístico\n");
    printf("5. Densidade Populacional\n");
    printf("6. Pib Per Capita\n");
    printf("7. Super Poder\n");
    printf("\nJogador nº 1 escolha o primeiro atributo: ");
    scanf("%d",&Opcao1Jogador1);

    //Menu de opções 1º jogador - Escolha do 1º atributo para comparação
    switch (Opcao1Jogador1){
    case 1:
        printf("\nJogador nº 1: População\n");
        break;
    case 2:
        printf("\nJogador nº 1: Área em Km²\n");
        break;
    case 3:
        printf("\nJogador nº 1: Pib\n");
        break;     
    case 4:
        printf("\nJogador nº 1: Ponto Turístico\n");
        break;       
    case 5:
        printf("\nJogador nº 1: Densidade Populacional\n");
        break; 
    case 6:
        printf("\nJogador nº 1: Pib Per Capita\n");
        break; 
    case 7:
        printf("\nJogador nº 1: Super Poder\n");
        break; 
        default:
        printf("\nOpção inválida!\n");
    }

    printf("\n----------------------------------\n");

    (OpJog1 == 'A' || OpJog1 == 'a') ? printf("\nA carta do jogador nº 2 é a B - Manaus!\n") : printf("\nA carta do jogador nº 2 é a A - Macéio!\n");
   
      //Solicitação ao jogador nº 2 para escolher o primeiro atributo
      printf("\n***** Atributos para comparação: *****\n");
      printf("\n1. População\n");
      printf("2. Área em Km²\n");
      printf("3. Pib\n");
      printf("4. Ponto Turístico\n");
      printf("5. Densidade Populacional\n");
      printf("6. Pib Per Capita\n");
      printf("7. Super Poder\n");
      printf("\nJogador nº 2 escolha o primeiro atributo: ");
      scanf("%d",&Opcao1Jogador2);

    //Menu de opções 2º jogador - Escolha do 1º atributo para comparação
    switch (Opcao1Jogador2){
    case 1:
        printf("\nJogador nº 2: População\n");
        break;
    case 2:
        printf("\nJogador nº 2: Área em Km²\n");
        break;
    case 3:
        printf("\nJogador nº 2: Pib\n");
        break;     
    case 4:
        printf("\nJogador nº 2: Ponto Turístico\n");
        break;       
    case 5:
        printf("\nJogador nº 2: Densidade Populacional\n");
        break; 
    case 6:
        printf("\nJogador nº 2: Pib Per Capita\n");
        break; 
    case 7:
        printf("\nJogador nº 2: Super Poder\n");
        break; 
        default:
        printf("\nOpção inválida!\n");
    }
    
    //Atribuindo a escolha das cartas as variáveis auxiliares
    if(OpJog1 == 'A' || OpJog1 == 'a'){
        PopJog1 = PopulacaoMaceio;
        AreaJog1 = AreaemKmMaceio;
        PibJog1 = PibMaceio;
        DensJog1 = DensPopInvMaceio;
        PibPerCapJog1 = PibPerCapMaceio;
        SupPodJog1 = SuperPoderMaceio;
        PonTurJog1 = PontTuristMaceio;

        PopJog2 = PopulacaoManaus;
        AreaJog2 = AreaemKmManaus;
        PibJog2 = PibManaus;
        DensJog2 = DensPopInvManaus;
        PibPerCapJog2 = PibPerCapManaus;
        SupPodJog2 = SuperPoderManaus;
        PonTurJog2 = PontTuristManaus;
    }else{
        PopJog1 = PopulacaoManaus;
        AreaJog1 = AreaemKmManaus;
        PibJog1 = PibManaus;
        DensJog1 = DensPopInvManaus;
        PibPerCapJog1 = PibPerCapManaus;
        SupPodJog1 = SuperPoderManaus;
        PonTurJog1 = PontTuristManaus;

        PopJog2 = PopulacaoMaceio;
        AreaJog2 = AreaemKmMaceio;
        PibJog2 = PibMaceio;
        DensJog2 = DensPopInvMaceio;
        PibPerCapJog2 = PibPerCapMaceio;
        SupPodJog2 = SuperPoderMaceio;
        PonTurJog2 = PontTuristMaceio;
    } 

    //Comparativo de atributos usando if-else-if (População Vs Outros Atributos)
    if((Opcao1Jogador1 == 1) && (Opcao1Jogador2 == 1)) {
        if((PopJog1 > PopJog2)){ 
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(PopJog1 < PopJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 1) && (Opcao1Jogador2 == 2)){
        if(PopJog1 > AreaJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(PopJog1 < AreaJog2){
                printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 1) && (Opcao1Jogador2 == 3)){
        if(PopJog1 > PibJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(PopJog1 < PibJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 1) && (Opcao1Jogador2 == 4)){
        if(PopJog1 > PonTurJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!!\n");
        }else if(PopJog1 < PonTurJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 1) && (Opcao1Jogador2 == 5)){
        if(PopJog1 < DensJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(PopJog1 > DensJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 1) && (Opcao1Jogador2 == 6)){
        if(PopJog1 > PibPerCapJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(PopJog1 < PibPerCapJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");    
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 1) && (Opcao1Jogador2 == 7)){
        if(PopJog1 > SupPodJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(PopJog1 < SupPodJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }

    //Comparativo de atributos usando if-else-if (Area em Km² Vs Outros Atributos)
    if((Opcao1Jogador1 == 2) && (Opcao1Jogador2 == 2 )){
        if((AreaJog1 > AreaJog2)){ 
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(AreaJog1 < AreaJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 2) && (Opcao1Jogador2 == 3)){
        if(AreaJog1 > PibJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(AreaJog1 < PibJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 2) && (Opcao1Jogador2 == 4)){
        if(AreaJog1 > PonTurJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(AreaJog1 < PonTurJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 2) && (Opcao1Jogador2 == 5)){
        if(AreaJog1 < DensJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(AreaJog1 > DensJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 2) && (Opcao1Jogador2 == 6)){
        if(AreaJog1 > PibPerCapJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(AreaJog1 < PibPerCapJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 2) && (Opcao1Jogador2 == 7)){
        if(AreaJog1 > SupPodJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(AreaJog1 < SupPodJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }
    //Comparativo de atributos usando if-else-if (Pib Vs Outros Atributos)
    if((Opcao1Jogador1 == 3) && (Opcao1Jogador2 == 3 )) {
        if((PibJog1 > PibJog2)){ 
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(PibJog1 < PibJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 3) && (Opcao1Jogador2 == 4)){
        if(PibJog1 > PonTurJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(PibJog1 < PonTurJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 3) && (Opcao1Jogador2 == 5)){
        if(PibJog1 < DensJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(PibJog1 > DensJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 3) && (Opcao1Jogador2 == 6)){
        if(PibJog1 > PibPerCapJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(PibJog1 < PibPerCapJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 3) && (Opcao1Jogador2 ==7)){
        if(PibJog1 > SupPodJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(PibJog1 < SupPodJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }

    //Comparativo de atributos usando if-else-if (Ponto Turistico Vs Outros Atributos)
    if((Opcao1Jogador1 == 4) && (Opcao1Jogador2 == 4 )) {
        if((PonTurJog1 > PonTurJog2)){ 
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(PonTurJog1 < PonTurJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 4) && (Opcao1Jogador2 == 5)){
        if(PonTurJog1 < DensJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(PonTurJog1 > DensJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 4) && (Opcao1Jogador2 == 6)){
        if(PonTurJog1 > PibPerCapJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(PonTurJog1 < PibPerCapJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 4) && (Opcao1Jogador2 == 7)){
        if(PonTurJog1 > SupPodJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(PonTurJog1 < SupPodJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }

    //Comparativo de atributos usando if-else-if (Densidade Demografica Invertida Vs Outros Atributos)
    if((Opcao1Jogador1 == 5) && (Opcao1Jogador2 == 5 )) {
        if((DensJog1 < DensJog2)){ 
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(DensJog1 > DensJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 5) && (Opcao1Jogador2 == 6)){
        if(DensJog1 < PibPerCapJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(DensJog1 > PibPerCapJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 5) && (Opcao1Jogador2 == 7)){
        if(DensJog1 < SupPodJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(DensJog1 > SupPodJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }

    //Comparativo de atributos usando if-else-if (Pib Per Capita Vs Pib Per Capita Vs Super Poder)
    if((Opcao1Jogador1 == 6) && (Opcao1Jogador2 == 6)){
        if(PibPerCapJog1 > PibPerCapJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(PibPerCapJog1 < PibPerCapJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }else if((Opcao1Jogador1 == 6) && (Opcao1Jogador2 == 7)){
        if(PibPerCapJog1 > SupPodJog2){
           printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(PibPerCapJog1 < SupPodJog2){
           printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
           printf("\n1ª Rodada - Empate!\n"); 
        } 
    }

    //Comparativo de atributos usando if-else-if (Super poder Vs Super Poder)
    if((Opcao1Jogador1 == 7) && (Opcao1Jogador2 == 7)){
        if(SupPodJog1 > SupPodJog2){
            printf("\nJogador nº 1 venceu a primeira rodada!!!\n");
        }else if(SupPodJog1 < SupPodJog2){
            printf("\nJogador nº 2 venceu a primeira rodada!!!\n");
        }else{
            printf("\n1ª Rodada - Empate!\n");
        }
    }

    //Informando qual é a rodada da partida
    printf("\n-----2ª Rodada de Comparações-----\n");

    //Solicitação ao jogador nº 1 para escolher o segundo atributo
    printf("\n***** Atributos para comparação: *****\n");
    printf("\n1. População\n");
    printf("2. Área em Km²\n");
    printf("3. Pib\n");
    printf("4. Ponto Turístico\n");
    printf("5. Densidade Populacional\n");
    printf("6. Pib Per Capita\n");
    printf("7. Super Poder\n");
    printf("\nJogador nº 1 escolha o segundo atributo: ");
    scanf("%d",&Opcao2Jogador1);

    if(Opcao2Jogador1 == Opcao1Jogador1){
        printf("\nO atributo já foi escolhido!\n");
        printf("\nEscolha outra opção: ");
        scanf("%d", &Opcao2Jogador1);
    } 

    //Menu de opções 1º jogador - Escolha do 2º atributo para comparação
    switch (Opcao2Jogador1){
        case 1:
            printf("\nJogador nº 1: População\n");
            break;
        case 2:
            printf("\nJogador nº 1: Área em Km²\n");
            break;
        case 3:
            printf("\nJogador nº 1: Pib\n");
            break;     
        case 4:
            printf("\nJogador nº 1: Ponto Turístico\n");
            break;       
        case 5:
            printf("\nJogador nº 1: Densidade Populacional\n");
            break; 
        case 6:
            printf("\nJogador nº 1: Pib Per Capita\n");
            break; 
        case 7:
            printf("\nJogador nº 1: Super Poder\n");
            break; 
            default:
            printf("\nOpção inválida!\n");
        }

    //Solicitação ao jogador nº 2 para escolher o segundo atributo
      printf("\n***** Atributos para comparação: *****\n");
      printf("\n1. População\n");
      printf("2. Área em Km²\n");
      printf("3. Pib\n");
      printf("4. Ponto Turístico\n");
      printf("5. Densidade Populacional\n");
      printf("6. Pib Per Capita\n");
      printf("7. Super Poder\n");
      printf("\nJogador nº 2 escolha o segundo atributo: ");
      scanf("%d",&Opcao2Jogador2);

      if(Opcao2Jogador2 == Opcao1Jogador2){
        printf("\nO atributo já foi escolhido!\n");
        printf("\nEscolha outra opção: ");
        scanf("%d", &Opcao2Jogador2);
    } 

    //Menu de opções 2º jogador - Escolha do 2º atributo para comparação
    switch (Opcao2Jogador2){
        case 1:
            printf("\nJogador nº 2: População\n");
            break;
        case 2:
            printf("\nJogador nº 2: Área em Km²\n");
            break;
        case 3:
            printf("\nJogador nº 2: Pib\n");
            break;     
        case 4:
            printf("\nJogador nº 2: Ponto Turístico\n");
            break;       
        case 5:
            printf("\nJogador nº 2: Densidade Populacional\n");
            break; 
        case 6:
            printf("\nJogador nº 2: Pib Per Capita\n");
            break; 
        case 7:
            printf("\nJogador nº 2: Super Poder\n");
            break; 
            default:
            printf("\nOpção inválida!\n");
        }

     //Comparativo de atributos usando if-else-if (População Vs Outros Atributos)
     if((Opcao2Jogador1 == 1) && (Opcao2Jogador2 == 1 )) {
        if((PopJog1 > PopJog2)){ 
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(PopJog1 < PopJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }else if((Opcao2Jogador1 == 1) && (Opcao2Jogador2 == 2)){
        if(PopJog1 > AreaJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(PopJog1 < AreaJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }else if((Opcao2Jogador1 == 1) && (Opcao2Jogador2 == 3)){
        if(PopJog1 > PibJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(PopJog1 < PibJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }else if((Opcao2Jogador1 == 1) && (Opcao2Jogador2 == 4)){
        if(PopJog1 > PonTurJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(PopJog1 < PonTurJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }  
    }else if(((Opcao2Jogador1 == 1) && (Opcao2Jogador2 == 5))){
        if(PopJog1 < DensJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(PopJog1 > DensJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }else if((Opcao2Jogador1 == 1) && (Opcao2Jogador2 == 6)){
        if(PopJog1 > PibPerCapJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(PopJog1 < PibPerCapJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");    
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }else if((Opcao2Jogador1 == 1) && (Opcao2Jogador2 == 7)){
        if(PopJog1 > SupPodJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(PopJog1 < SupPodJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }

    //Comparativo de atributos usando if-else-if (Area em Km² Vs Outros Atributos)
    if((Opcao2Jogador1 == 2) && (Opcao2Jogador2 == 2 )){
        if((AreaJog1 > AreaJog2)){ 
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(AreaJog1 < AreaJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }    
    }else if((Opcao2Jogador1 == 2) && (Opcao2Jogador2 == 3)){
        if(AreaJog1 > PibJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(AreaJog1 < PibJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }else if((Opcao2Jogador1 == 2) && (Opcao2Jogador2 == 4)){
        if(AreaJog1 > PonTurJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(AreaJog1 < PonTurJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }else if((Opcao2Jogador1 == 2) && (Opcao2Jogador2 == 5)){
        if(AreaJog1 < DensJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(AreaJog1 > DensJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }else if((Opcao2Jogador1 == 2) && (Opcao2Jogador2 == 6)){
        if(AreaJog1 > PibPerCapJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(AreaJog1 < PibPerCapJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }else if((Opcao2Jogador1 == 2) && (Opcao2Jogador2 == 7)){
        if(AreaJog1 > SupPodJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(AreaJog1 < SupPodJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }

    //Comparativo de atributos usando if-else-if (Pib Vs Outros Atributos)
    if((Opcao2Jogador1 == 3) && (Opcao2Jogador2 == 3 )) {
        if((PibJog1 > PibJog2)){ 
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(PibJog1 < PibJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }else if((Opcao2Jogador1 == 3) && (Opcao2Jogador2 == 4)){
        if(PibJog1 > PonTurJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(PibJog1 < PonTurJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }else if((Opcao2Jogador1 == 3) && (Opcao2Jogador2 == 5)){
        if(PibJog1 < DensJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(PibJog1 > DensJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }else if((Opcao2Jogador1 == 3) && (Opcao2Jogador2 == 6)){
        if(PibJog1 > PibPerCapJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(PibJog1 < PibPerCapJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }else if((Opcao2Jogador1 == 3) && (Opcao2Jogador2 ==7)){
        if(PibJog1 > SupPodJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(PibJog1 < SupPodJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }

    //Comparativo de atributos usando if-else-if (Ponto Turistico Vs Outros Atributos)
    if((Opcao2Jogador1 == 4) && (Opcao2Jogador2 == 4 )) {
        if((PonTurJog1 > PonTurJog2)){ 
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(PonTurJog1 < PonTurJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
     }else if((Opcao2Jogador1 == 4) && (Opcao2Jogador2 == 5)){
        if(PonTurJog1 < DensJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(PonTurJog1 > DensJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }else if((Opcao2Jogador1 == 4) && (Opcao2Jogador2 == 6)){
        if(PonTurJog1 > PibPerCapJog2){
                printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(PonTurJog1 < PibPerCapJog2){
                printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }else if((Opcao2Jogador1 == 4) && (Opcao2Jogador2 == 7)){
        if(PonTurJog1 > SupPodJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(PonTurJog1 < SupPodJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }

    //Comparativo de atributos usando if-else-if (Densidade Demografica Invertida Vs Outros Atributos)
    if((Opcao2Jogador1 == 5) && (Opcao2Jogador2 == 5 )) {
        if((DensJog1 < DensJog2)){ 
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(DensJog1 > DensJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }else if((Opcao2Jogador1 == 5) && (Opcao2Jogador2 == 6)){
        if(DensJog1 < PibPerCapJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(DensJog1 > PibPerCapJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }else if((Opcao2Jogador1 == 5) && (Opcao2Jogador2 == 7)){
        if(DensJog1 < SupPodJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(DensJog1 > SupPodJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }

    //Comparativo de atributos usando if-else-if (Pib Per Capita Vs Pib Per Capita Vs Super Poder)
    if((Opcao2Jogador1 == 6) && (Opcao2Jogador2 == 6)){
        if(PibPerCapJog1 > PibPerCapJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(PibPerCapJog1 < PibPerCapJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }else if((Opcao2Jogador1 == 6) && (Opcao2Jogador2 == 7)){
        if(PibPerCapJog1 > SupPodJog2){
           printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(PibPerCapJog1 < SupPodJog2){
           printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
           printf("\n2ª Rodada - Empate!\n"); 
        } 
    }

    //Comparativo de atributos usando if-else-if (Super poder Vs Super Poder)
    if((Opcao2Jogador1 == 7) && (Opcao2Jogador2 == 7)){
        if(SupPodJog1 > SupPodJog2){
            printf("\nJogador nº 1 venceu a segunda rodada!!!\n");
        }else if(SupPodJog1 < SupPodJog2){
            printf("\nJogador nº 2 venceu a segunda rodada!!!\n");
        }else{
            printf("\n2ª Rodada - Empate!\n");
        }
    }

    //Mostrando os atributos e valores dos atributos escolhidos 1ª e 2ª rodadas

    printf("\n-----Atributos escolhidos pelo jogador nº1-----\n");

    if(Opcao1Jogador1 == 1){
        printf("\n1º Atributo.: População - Valor.: %lu\n",PopJog1);
    }else if(Opcao1Jogador1 == 2){
        printf("\n1º Atributo.: Área em Km² - Valor.: %.2f\n",AreaJog1);
    }else if(Opcao1Jogador1 == 3){
        printf("\n1º Atributo.: Pib - Valor.: %.2f\n",PibJog1);
    }else if(Opcao1Jogador1 == 4){
        printf("\n1º Atributo.: Ponto Turístico - Valor.: %d\n",PonTurJog1);
    }else if(Opcao1Jogador1 == 5){
        printf("\n1º Atributo.: Densidade Populacional - Valor.: %.2f\n",DensJog1);
    }else if(Opcao1Jogador1 == 6){
        printf("\n1º Atributo.: Pib Per Capita - Valor.: %.2f\n",PibPerCapJog1);
    }else if(Opcao1Jogador1 == 7){
        printf("\n1º Atributo.: Super Poder - Valor.: %.2f\n",SupPodJog1);
    }

    if(Opcao2Jogador1 == 1){
        printf("\n2º Atributo.: População - Valor.: %lu\n",PopJog1);
    }else if(Opcao2Jogador1 == 2){
        printf("\n2º Atributo.: Área em Km² - Valor.: %.2f\n",AreaJog1);
    }else if(Opcao2Jogador1 == 3){
        printf("\n2º Atributo.: Pib - Valor.: %.2f\n",PibJog1);
    }else if(Opcao2Jogador1 == 4){
        printf("\n2º Atributo.: Ponto Turístico - Valor.: %d\n",PonTurJog1);
    }else if(Opcao2Jogador1 == 5){
        printf("\n2º Atributo.: Densidade Populacional - Valor.: %.2f\n",DensJog1);
    }else if(Opcao2Jogador1 == 6){
        printf("\n2º Atributo.: Pib Per Capita - Valor.: %.2f\n",PibPerCapJog1);
    }else if(Opcao2Jogador1 == 7){
        printf("\n2º Atributo.: Super Poder - Valor.: %.2f\n",SupPodJog1);
    }

    printf("\n-----Atributos escolhidos pelo jogador nº2-----\n");

    if(Opcao1Jogador2 == 1){
        printf("\n1º Atributo.: População - Valor.: %lu\n",PopJog2);
    }else if(Opcao1Jogador2 == 2){
        printf("\n1º Atributo.: Área em Km² - Valor.: %.2f\n",AreaJog2);
    }else if(Opcao1Jogador2 == 3){
        printf("\n1º Atributo.: Pib - Valor.: %.2f\n",PibJog2);
    }else if(Opcao1Jogador2 == 4){
        printf("\n1º Atributo.: Ponto Turístico - Valor.: %d\n",PonTurJog2);
    }else if(Opcao1Jogador2 == 5){
        printf("\n1º Atributo.: Densidade Populacional - Valor.: %.2f\n",DensJog2);
    }else if(Opcao1Jogador2 == 6){
        printf("\n1º Atributo.: Pib Per Capita - Valor.: %.2f\n",PibPerCapJog2);
    }else if(Opcao1Jogador2 == 7){
        printf("\n1º Atributo.: Super Poder - Valor.: %.2f\n",SupPodJog2);
    }

    if(Opcao2Jogador2 == 1){
        printf("\n2º Atributo.: População - Valor.: %lu\n",PopJog2);
    }else if(Opcao2Jogador2 == 2){
        printf("\n2º Atributo.: Área em Km² - Valor.: %.2f\n",AreaJog2);
    }else if(Opcao2Jogador2 == 3){
        printf("\n2º Atributo.: Pib - Valor.: %.2f\n",PibJog2);
    }else if(Opcao2Jogador2 == 4){
        printf("\n2º Atributo.: Ponto Turístico - Valor.: %d\n",PonTurJog2);
    }else if(Opcao2Jogador2 == 5){
        printf("\n2º Atributo.: Densidade Populacional - Valor.: %.2f\n",DensJog2);
    }else if(Opcao2Jogador2 == 6){
        printf("\n2º Atributo.: Pib Per Capita - Valor.: %.2f\n",PibPerCapJog2);
    }else if(Opcao2Jogador2 == 7){
        printf("\n2º Atributo.: Super Poder - Valor.: %.2f\n",SupPodJog2);
    }

    //Variáveis para armazenar o valor dos atributos escolhidos pelos dois jogadores nas duas rodadas
    float SomaJog1 = 0, SomaJog2 = 0;
    
    //Titulo de soma dos atributos
    printf("\n-----Soma dos atributos-----\n");

    //Soma dos atributos do 1º jogador - 1ª Escolha
    if(Opcao1Jogador1 == 1) {
        SomaJog1 += PopJog1;
    }else if (Opcao1Jogador1 == 2){
        SomaJog1 += AreaJog1;
    }else if (Opcao1Jogador1 == 3){
        SomaJog1 += PibJog1;
    }else if (Opcao1Jogador1 == 4){
        SomaJog1 += PonTurJog1;
    }else if (Opcao1Jogador1 == 5){
        SomaJog1 += DensJog1;
    }else if (Opcao1Jogador1 == 6){
        SomaJog1 += PibPerCapJog1;
    }else if (Opcao1Jogador1 == 7){
        SomaJog1 += SupPodJog1;
    } 

    //Soma dos atributos do 1º jogador - 2ª Escolha
    if(Opcao2Jogador1 == 1){
        SomaJog1 += PopJog1;
    }else if (Opcao2Jogador1 == 2){
        SomaJog1 += AreaJog1;
    }else if (Opcao2Jogador1 == 3){
        SomaJog1 += PibJog1;
    }else if (Opcao2Jogador1 == 4){
        SomaJog1 += PonTurJog1;
    }else if (Opcao2Jogador1 == 5){
        SomaJog1 += DensJog1;
    }else if (Opcao2Jogador1 == 6){
        SomaJog1 += PibPerCapJog1;
    }else if (Opcao2Jogador1 == 7){
        SomaJog1 += SupPodJog1;
    } 

    //Soma dos atributos do 2º jogador - 1ª Escolha
    if(Opcao1Jogador2 == 1){
        SomaJog2 += PopJog2;
    }else if (Opcao1Jogador2 == 2){
        SomaJog2 += AreaJog2;
    }else if (Opcao1Jogador2 == 3){
        SomaJog2 += PibJog2;
    }else if (Opcao1Jogador2 == 4){
        SomaJog2 += PonTurJog2;
    }else if (Opcao1Jogador2 == 5){
        SomaJog2 += DensJog2;
    }else if (Opcao1Jogador2 == 6){
        SomaJog2 += PibPerCapJog2;
    }else if (Opcao1Jogador2 == 7){
        SomaJog2 += SupPodJog2;
    } 
    
     //Soma dos atributos do 2º jogador - 2ª Escolha
     if(Opcao2Jogador2 == 1){
        SomaJog2 += PopJog2;
    }else if (Opcao2Jogador2 == 2){
        SomaJog2 += AreaJog2;
    }else if (Opcao2Jogador2 == 3){
        SomaJog2 += PibJog2;
    }else if (Opcao2Jogador2 == 4){
        SomaJog2 += PonTurJog2;
    }else if (Opcao2Jogador2 == 5){
        SomaJog2 += DensJog2;
    }else if (Opcao2Jogador2 == 6){
        SomaJog2 += PibPerCapJog2;
    }else if (Opcao2Jogador2 == 7){
        SomaJog2 += SupPodJog2;
    } 

    //Resultado da soma
    printf("\n*****Jogador n° 1: Atributos somados: %.2f*****\n",SomaJog1);
    printf("\n*****Jogador n° 2: Atributos somados: %.2f*****\n",SomaJog2);
    
    //Titulo do resultado final
    printf("\n-----Resultado final-----\n");

    //Comparação para dizer quem é o grande vencedor
    if(SomaJog1 > SomaJog2){
        printf("\n*****Parabéns, o jogador nº 1 é o - Grande Vencedor!!!*****\n");
    }else if(SomaJog1 < SomaJog2){
        printf("\n*****Parabéns, o jogador nº 2 é o - Grande Vencedor!!!*****\n");
    }else{
        printf("\n*****O Jogo terminou empatado!!!*****\n");
    }

    return 0;
}
