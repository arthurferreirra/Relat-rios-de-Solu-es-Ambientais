#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> // biblioteca para pontução abnt
#include <conio.h> // biblioteca para utilizar get


typedef struct 
{
    char nome[50];
    char nomeResponsavel[50];
    char nomedadosEmpresa[50];
    char razaoSocial[50];
    char nomeFantasia[50];
    char endereco[100];
    char email[20];
    char dadosRelevantes[20];

    char cnpj [14];
    char telefone [9];
    char dataAbertura[10];
}cadastrodadosEmpresa;

typedef struct 
{
    char nomeResiduos[50];
    int quantidadesResiduosTratados;
    int quantidadesResiduosNaoTratados;
    float precoSugeridoDeCusto;
}ListaRelatorio; //listagem para o dados da empresa

typedef struct 
{
    int Id;
    ListaRelatorio quantidadeRelatorios[99];
    float totalRelatorio;
}Relatorio; //relatorio dos dados da empresa

int relatorio()
{
    int maiorResiduoTratado;
    int menorResiduoTratado =0;        //variaveis de comparação
    float maiorGastoTratamento;

    int status = 1, id =0, c;       //var para o loop while
    int escolha=0;          // ler a escolha do usuario para input
    Relatorio relatorioVetor[99]; 
    do
    {
        printf("\n1-Criar relatorio\n");
        printf("\n2-Ver relatorio\n");
        printf("\n3-salvar em txt\n");
        printf("\n4-sair\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
        {
        relatorioVetor[id].Id = id;
            printf("Relatorio numero: %d", id+1); // incrementa +1 para começar a contagem no 1
            float total = 0;
            for (int i = 0; i < 99; i++)
            {
                while ((c = getchar()) != '\n' && c != EOF); //loop para tirar ENTER do buffer
                printf("\nDigite o nome do residuos: \n");
                char NomeResiduos[50];
                fgets(NomeResiduos, sizeof(NomeResiduos),stdin); // registra o input do usuario
                NomeResiduos[strcspn(NomeResiduos, "\n")] = '\0';

                printf("\nDigite a quantidade que ja foram tratados: \n");
                int QuantidadesResiduosTratados;
                scanf("%d",&QuantidadesResiduosTratados);

                printf("\nDigite a quantidade que NaO foram tratados: \n");
                int QuantidadesResiduosNaoTratados;
                scanf("%d",&QuantidadesResiduosNaoTratados);

                printf("\nDigite o preco de custo: \n");
                float PrecoSugeridoDeCusto;
                scanf("%f", &PrecoSugeridoDeCusto);

                // cria uma nova lista da struct de relatorio e aplica os dados nessa variavel
                ListaRelatorio relatorioFeito = {.quantidadesResiduosTratados = QuantidadesResiduosTratados, .quantidadesResiduosNaoTratados = QuantidadesResiduosNaoTratados, .precoSugeridoDeCusto = PrecoSugeridoDeCusto};
                strcpy(relatorioFeito.nomeResiduos, NomeResiduos); // cria uma copia em string dos dados

                relatorioVetor[id].quantidadeRelatorios[i] = relatorioFeito; //aponta para o vetor da lista e recebe a variavel da copia
                total += PrecoSugeridoDeCusto * QuantidadesResiduosTratados;  // conta para adicionar na quantia de gasto
                

                printf("Gostaria de adicionar mais itens[s/n]:");
                char novoItem;
                scanf(" %c", &novoItem);
                if (novoItem != 's')
                {
                    break;            
                }

                
                
            }
            relatorioVetor[id].totalRelatorio = total;
            id++;
            
            break;
        }
        case 2:
        {
        for (int i = 0; i < id; i++)
                {
                    printf("Relatorio: %d", i+1);
                    for (int j = 0; j< 99 ; j ++)
                    {   //Imprime os input do usuario
                        printf("\nNome do residuo: %s\n", relatorioVetor[i].quantidadeRelatorios[j].nomeResiduos);
                        printf("\nQuantidade que foram tratados: %d\n", relatorioVetor[i].quantidadeRelatorios[j].quantidadesResiduosTratados);
                        printf("\nQuantidade sem tratamento: %d\n", relatorioVetor[i].quantidadeRelatorios[j].quantidadesResiduosNaoTratados);
                        printf("\nGasto  do tratamento: %f\n", relatorioVetor[i].quantidadeRelatorios[j].precoSugeridoDeCusto);

                        //condição para achar o maior residuo tratado
                        if(relatorioVetor[i].quantidadeRelatorios[j].quantidadesResiduosTratados > maiorResiduoTratado)
                        {
                            maiorResiduoTratado = relatorioVetor[i].quantidadeRelatorios[j].quantidadesResiduosTratados;
                            
                        }
                        // condição para achar o menor residuo tratado
                        if(relatorioVetor[i].quantidadeRelatorios[j].quantidadesResiduosNaoTratados > menorResiduoTratado)
                        {
                            
                            menorResiduoTratado = relatorioVetor[i].quantidadeRelatorios[j].quantidadesResiduosNaoTratados;
                        }

                        // condição para achar o maior gasto para tratamento para cada item tratado
                        if(relatorioVetor[i].quantidadeRelatorios[j].precoSugeridoDeCusto > maiorGastoTratamento)
                        {
                            maiorGastoTratamento = relatorioVetor[i].quantidadeRelatorios[j].precoSugeridoDeCusto;
                        }

                        //condição de parada
                        if(relatorioVetor[i].quantidadeRelatorios[j + 1].quantidadesResiduosTratados == 0 && relatorioVetor[i].quantidadeRelatorios[j + 1].quantidadesResiduosNaoTratados == 00)
                        {
                            break;
                        }
                    }
                    
                }
                printf("\n------Relatorio Global-------\n"); // relatorio goblal
                printf("\nMaior Volume de Residuos tratados: %d\n",maiorResiduoTratado);
                printf("\nMaior volume de residuos  NAO tratados: %d\n",menorResiduoTratado);
                printf("\nMaior aporte de tratamento: %f\n",maiorGastoTratamento);

                printf("\nAperte uma tecla pra continuar\n");
                while ((c = getchar()) != '\n' && c != EOF);
                getchar();
        break;
        }
        case 3:
        {

        
            printf("Gostaria de salvar o relatorio em Txt ou CSV [t/c]: "); 
                        char escolhaSave;
                        scanf(" %c", &escolhaSave);
                        if(escolhaSave == 't')
                        {
                                FILE *salvarTxt = fopen("relatorio.txt", "a"); // abri o arquivo txt e insere os dados do vetor 
                                fprintf(salvarTxt,"%s \n",relatorioVetor->quantidadeRelatorios->nomeResiduos);
                                fprintf(salvarTxt,"%d \n",relatorioVetor->quantidadeRelatorios->quantidadesResiduosTratados);
                                fprintf(salvarTxt,"%d \n",relatorioVetor->quantidadeRelatorios->quantidadesResiduosNaoTratados);
                                fprintf(salvarTxt,"%f \n",relatorioVetor->quantidadeRelatorios->precoSugeridoDeCusto);
                                fclose(salvarTxt);
                        }
                        else
                        {
                            FILE *salvarCsv = fopen("relatorioCsv.csv", "a"); // abri um arquivo csv e insere os dados do vetor
                            fprintf(salvarCsv, "%s ", relatorioVetor->quantidadeRelatorios->nomeResiduos);
                            fprintf(salvarCsv, "%d ", relatorioVetor->quantidadeRelatorios->quantidadesResiduosTratados);
                            fprintf(salvarCsv, "%d ", relatorioVetor->quantidadeRelatorios->quantidadesResiduosNaoTratados);
                            fprintf(salvarCsv, "%f ", relatorioVetor->quantidadeRelatorios->precoSugeridoDeCusto);
                            fclose(salvarCsv);
                        }
            break;
        }
        case 4:
            {
                exit(0);
                break;
            }
        
        }
    } while (status);
     
}

void limparBuffer() {
    while(getchar() != '\n');  // Remove todos os caracteres até o próximo '\n'
}

void cadastrarCliente()
{
    cadastrodadosEmpresa dadosDaEmepresa;
    FILE *ponteiro_arquivo; //aponta variavel de arquivo

    printf("\n################################################################## \n");
    printf("\n########## Voce esta na tela para cadastrar seu cliente ########## \n");
    printf("\n################################################################## \n");



    printf("Digite o nome do Responsavel: ");
    fgets(dadosDaEmepresa.nomeResponsavel, sizeof(dadosDaEmepresa.nomeResponsavel), stdin);
    dadosDaEmepresa.nomeResponsavel[strcspn(dadosDaEmepresa.nomeResponsavel, "\n")] = '\0'; // recebe o input do usuario e aloca em um espaço

    printf("Digite o nome do dados da Empresa: ");
    fgets(dadosDaEmepresa.nomedadosEmpresa, sizeof(dadosDaEmepresa.nomedadosEmpresa), stdin);
    dadosDaEmepresa.nomedadosEmpresa[strcspn(dadosDaEmepresa.nomedadosEmpresa, "\n")] = '\0';

    printf("Digite o cnpj: ");
    fgets(dadosDaEmepresa.cnpj, sizeof(dadosDaEmepresa.cnpj), stdin);
    dadosDaEmepresa.cnpj[strcspn(dadosDaEmepresa.cnpj, "\n")] = '\0';

    printf("Digite a razao social: ");
    fgets(dadosDaEmepresa.razaoSocial, sizeof(dadosDaEmepresa.razaoSocial), stdin);
    dadosDaEmepresa.razaoSocial[strcspn(dadosDaEmepresa.razaoSocial, "\n")] = '\0';

    printf("Digite o nome fantasia: ");
    fgets(dadosDaEmepresa.nomeFantasia, sizeof(dadosDaEmepresa.nomeFantasia), stdin);
    dadosDaEmepresa.nomeFantasia[strcspn(dadosDaEmepresa.nomeFantasia, "\n")] = '\0';

    printf("Digite o telefone: ");
    fgets(dadosDaEmepresa.telefone, sizeof(dadosDaEmepresa.telefone), stdin);
    dadosDaEmepresa.telefone[strcspn(dadosDaEmepresa.telefone, "\n")] = '\0';

    printf("Digite o endereço (Rua, Numero, Bairro, Cidade, Estado, CEP): ");
    fgets(dadosDaEmepresa.endereco, sizeof(dadosDaEmepresa.endereco), stdin);
    dadosDaEmepresa.endereco[strcspn(dadosDaEmepresa.endereco, "\n")] = '\0';

    printf("Digite o e-mail: ");
    fgets(dadosDaEmepresa.email, sizeof(dadosDaEmepresa.email), stdin);
    dadosDaEmepresa.email[strcspn(dadosDaEmepresa.email, "\n")] = '\0';

    printf("Digite a data de abertura (dd/mm/aaaa): ");
    fgets(dadosDaEmepresa.dataAbertura, sizeof(dadosDaEmepresa.dataAbertura), stdin);
    dadosDaEmepresa.dataAbertura[strcspn(dadosDaEmepresa.dataAbertura, "\n")] = '\0';

    printf("Digite outros dados relevantes: ");
    fgets(dadosDaEmepresa.dadosRelevantes, sizeof(dadosDaEmepresa.dadosRelevantes), stdin);
    dadosDaEmepresa.dadosRelevantes[strcspn(dadosDaEmepresa.dadosRelevantes, "\n")] = '\0';

    // Abrindo o arquivo para salvar as informações da dadosDaEmepresa
    ponteiro_arquivo = fopen("cadastro de Cliente.txt", "a");  // "a" para adicionar ao final do arquivo
    if (ponteiro_arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(ponteiro_arquivo, "Nome do Responsavel: %s\n", dadosDaEmepresa.nomeResponsavel); // insere no arquivo txt os dados do usuario
    fprintf(ponteiro_arquivo, "Nome da Empresa: %s\n", dadosDaEmepresa.nomedadosEmpresa);
    fprintf(ponteiro_arquivo, "CNPJ: %s\n", dadosDaEmepresa.cnpj);
    fprintf(ponteiro_arquivo, "Razao Social: %s\n", dadosDaEmepresa.razaoSocial);
    fprintf(ponteiro_arquivo, "Nome Fantasia: %s\n", dadosDaEmepresa.nomeFantasia);
    fprintf(ponteiro_arquivo, "Telefone: %s\n", dadosDaEmepresa.telefone);
    fprintf(ponteiro_arquivo, "Endereço: %s\n", dadosDaEmepresa.endereco);
    fprintf(ponteiro_arquivo, "E-mail: %s\n", dadosDaEmepresa.email);
    fprintf(ponteiro_arquivo, "Data de Abertura: %s\n", dadosDaEmepresa.dataAbertura);
    fprintf(ponteiro_arquivo, "Outros Dados: %s\n", dadosDaEmepresa.dadosRelevantes);
    fprintf(ponteiro_arquivo, "\n-------------------------------------------------\n\n");

    fclose(ponteiro_arquivo); // fecha o arquivo txt
    printf("\nCadastro realizado com sucesso\n");
}

void consultarCliente(char cnpjInformado[])// recebe uma variavel de string
{
    FILE *ponteiro_arquivo;
    int i = 0;
    char linha[500];
    char cnpjLido[20];
    int encontrado = 0;

    ponteiro_arquivo = fopen("cadastro de Cliente.txt", "r"); // abri arquivo txt

    
    //fgets(dadosDaEmpresa.cnpj,sizeof(dadosDaEmepresa.cnpj),stdin);
    //dadosDaEmepresa.cnpj[strcspn(dadosDaEmepresa.cnpj,"\n")] ='\0';

    while (fgets(linha, sizeof(linha), ponteiro_arquivo)) // loop para verificar cnpj
    {
        if(strstr(linha, "CNPJ:") != NULL)
        {
            
            sscanf(linha, "CNPJ: %s", cnpjLido);

            if(strcmp(cnpjLido, cnpjInformado) == 0)
            {
            encontrado = 1;
            break;
            }
        }
        
    }
    if(encontrado)
    {
        printf("Cliente ja cadastrado");
    }
    else
    {
        printf("Cliente nao possui cadastro");
    }
    fclose(ponteiro_arquivo);
    
}

int main() 
{
    int escolha;
    int escolhaLogin;
    char usuario[20];
    char senha[20];
    char mascaraSenha;
    char cnpjInformado[14];
    int i = 0;
    
    printf("######### Bem-vindo ao seu RSA #########\n");

    do
    {
        //Menu Principal
        printf("1-Realizar Login\n");
        printf("2-Sair\n");
        scanf("%d",&escolha);
        switch(escolha) // switch case para guardar a escolha do usuario
        {
            case 1: //login do usuario
                printf("Digite seu usuario: ");
                gets(usuario);
                scanf("%s",usuario);

                printf("Digite sua senha:");
                    while (1)// MASCARAR SENHA DO USUARIO
                    {
                        mascaraSenha = getch();
                        if (mascaraSenha == 13)
                        {
                            break;
                        }
                        else if(mascaraSenha == 8)
                        {
                            if (i > 0)
                            {
                                i--;
                                printf("\b \b");
                            }                           
                        }
                        else
                        {
                            senha[i] = mascaraSenha;
                            i++;
                            printf("*"); // imprimi * no lugar no input do usuario
                        }
                    }

                printf("\n################### Login Realizado ###################\n"); // login efetuado
                do // loop  para outro switch case
                {
                    printf("\n1-Cadastrar Cliente\n");
                    printf("2-Consultar Cliente\n");
                    printf("3-Relatorios e gerenciamento\n");
                    printf("4-Sair\n");
                    scanf("%d",&escolhaLogin);
                    switch (escolhaLogin)
                    {
                    case 1:
                        printf("\n-------Escolheu cadastrar cliente-------\n");
                        limparBuffer(); // função para limpar o buffer do \n 
                        cadastrarCliente();
                        break;
                    case 2:
                        printf("\n---------Escolheu consultar cliente--------\n");
                        limparBuffer();
                        printf("Digite o CNPJ do cliente para consultar o cadastro: ");
                        fgets(cnpjInformado,sizeof(cnpjInformado), stdin); // le input do usuario e aloca espaço na memoria para consultar o cnpj
                        cnpjInformado[strcspn(cnpjInformado, "\n")] = '\0';
                        consultarCliente(cnpjInformado);
                        break;

                    case 3:
                        printf("\n---------Escolheu Relatorios e gerenciamento--------\n");
                        limparBuffer();
                        relatorio();
                        break;
                    
                    case 4:
                        exit(0);
                        break;
                    }
                } while (escolhaLogin != 4);

            break; //break 1

            case 2:
            exit(0);
            break;
        }
    }while (escolha !=2);
    
    return 0;
}