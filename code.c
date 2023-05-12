#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
# define CLEAR_SCREEN system("cls")
#else
# define CLEAR_SCREEN puts("\x1b[H\x1b[2J")
#endif

struct Locacao{
  char cep[255];
  char rua[255];
  char bairro[255];
  char numero[255];
};

struct Material{
  char numeroSerie[255];
  char nomeMaterial[255];
  char modeloMaterial[255];
  char precoMaterial[255];
  char tipoMaterial[255];
};

struct Fornecedor{
  int cnpjFornecedor[255];
  char nomeFornecedor[255];
  char idFornecedor[255];
  char telefoneFornecedor[255];
  struct Locacao locacao;
  struct Material material;
}tpFornecedor;

struct Fornecedor fornecedor;
struct Fornecedor fornecedores[100];
int qtdFornecedores = 0;

void cadastrarFornecedor(){
  CLEAR_SCREEN;
  printf("\nInforme o cnpj do Fornecedor: ");
  scanf("%d", tpFornecedor.cnpjFornecedor);
  getc(stdin);

    CLEAR_SCREEN;
  printf("\nInforme o nome do Fornecedor: ");
  fflush(stdin);
  fgets(tpFornecedor.nomeFornecedor, 255, stdin);

  CLEAR_SCREEN;
  printf("\nInforme o id do Fornecedor: ");
  fflush(stdin);
  fgets(tpFornecedor.idFornecedor, 255, stdin);

  CLEAR_SCREEN;
  printf("\nInforme o telefone do Fornecedor: ");
  fflush(stdin);
  fgets(tpFornecedor.telefoneFornecedor, 255, stdin);

  CLEAR_SCREEN;
  printf("\nInforme o cep da Locacao: ");
  fflush(stdin);
  fgets(tpFornecedor.locacao.cep, 255, stdin);

  CLEAR_SCREEN;
  printf("\nInforme a rua da Locacao: ");
  fflush(stdin);
  fgets(tpFornecedor.locacao.rua, 255, stdin);

  CLEAR_SCREEN;
  printf("\nInforme o bairro da Locacao: ");
  fflush(stdin);
  fgets(tpFornecedor.locacao.bairro, 255, stdin);

  CLEAR_SCREEN;
  printf("\nInforme o numero da Locacao: ");
  fflush(stdin);
  fgets(tpFornecedor.locacao.numero, 255, stdin);

  CLEAR_SCREEN;
  printf("\nInforme o numero de serie do Material: ");
  fflush(stdin);
  fgets(tpFornecedor.material.numeroSerie, 255, stdin);

  CLEAR_SCREEN;
  printf("\nInforme o nome do material: ");
  fflush(stdin);
  fgets(tpFornecedor.material.nomeMaterial, 255, stdin);

  CLEAR_SCREEN;
  printf("\nInforme o modelo do material: ");
  fflush(stdin);
  fgets(tpFornecedor.material.modeloMaterial, 255, stdin);

  CLEAR_SCREEN;
  printf("\nInforme o preco do material: ");
  fflush(stdin);
  fgets(tpFornecedor.material.precoMaterial, 255, stdin);

  CLEAR_SCREEN;
  printf("\nInforme o tipo do material: ");
  fflush(stdin);
  fgets(tpFornecedor.material.tipoMaterial, 255, stdin);

  CLEAR_SCREEN;
  printf("\n\t\t\tDados Cadastrados com sucesso!!!");

  fornecedores[qtdFornecedores] = tpFornecedor;
  qtdFornecedores++;
}

void listarFornecedores(struct Fornecedor *fornecedores, int qtdFornecedores) {
  for(int i = 0; i < qtdFornecedores; i++) {
    printf("\n\n Dados do Fornecedor");
    printf("\n CNPJ: %d", *fornecedores[i].cnpjFornecedor);
    printf("\n\n Nome: %s", fornecedores[i].nomeFornecedor);
    printf("\n ID: %s", fornecedores[i].idFornecedor);
    printf("\n Telefone: %s", fornecedores[i].telefoneFornecedor);
    printf("\n\n Dados da Locação");
    printf("\n CEP: %s", fornecedores[i].locacao.cep);
    printf("\n Rua: %s", fornecedores[i].locacao.rua);
    printf("\n Bairro: %s", fornecedores[i].locacao.bairro);
    printf("\n Número: %s", fornecedores[i].locacao.numero);
    printf("\n\n Dados do Material");
    printf("\n Número de série: %s", fornecedores[i].material.numeroSerie);
    printf("\n Nome: %s", fornecedores[i].material.nomeMaterial);
    printf("\n Modelo: %s", fornecedores[i].material.modeloMaterial);
    printf("\n Preço: %s", fornecedores[i].material.precoMaterial);
    printf("\n Tipo: %s", fornecedores[i].material.tipoMaterial);
    printf("\n-------------------------------------------------------------");
  }
}

int main(void) {
  int op;
  do{
    printf("\n\n\t[1] - Cadastrar Fornecedor");
    printf("\n\t[2] - Listar Fornecedores cadastrados");
    printf("\n\t[3] - Sair\n");
    printf("\tInforme uma opcao: ");
    scanf("%d", &op);
    switch(op){
      case 1:
        cadastrarFornecedor();
        break;

      case 2:
        CLEAR_SCREEN;
        listarFornecedores(fornecedores, qtdFornecedores);
        break;

      case 3:
        printf("\nSaindo...\n");
        break;

      default:
        printf("\nOpção inválida. Digite novamente.\n");
    }
}while(op!=3);

  return 0;
}
