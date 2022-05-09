#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

#define MAX 72

typedef struct { //criação da struct carta 
    	int numero;
    	int cor;
    	/*
		cor 0 = amarelo
		cor 1 = verde
		cor 2 = azul
		cor 3 = vermelho
		cor 4 = preto
		*/
		/*
		numero 1-9
		numero 15 = block
		numero 16 = reverse
		numero 17 = +2
		numero 18 = +4
		numero 19 = troca cor
		*/
}carta;

typedef struct {  // cria o baralho
    int topo;
    carta c[MAX];
} baralho;

struct Lista {  // Criação da Lista em struct (lista simplesmente encadeada) mão
 carta c;
 struct Lista* prox;
};
typedef struct Lista lista;

int pilha_vazia(baralho *p){ // Verifica se o baralho está vazio
    if(p->topo == -1){
        return 1;
    }else{
        return 0;
    }
}

int pilha_cheia(baralho *p){  // Verifica se baralho está cheio
    if(p->topo == MAX-1){
        return 1;
    }else{
        return 0;
    }
}

int push(baralho *p, carta c){ // Inserindo novo elemento no topo do baralho
    if(pilha_cheia(p)){
        return 0;
    }else{
        p->topo++;
        p->c[p->topo] = c;
        return 1;
    }
}

int pop(baralho *p, carta *c){ // Removendo elemento do topo do baralho
    if(pilha_vazia(p)){
        return 0;
    }else{
        *c = p->c[p->topo];
        p->topo--;
        return 1;
    }
}

int altura_pilha(baralho *p){ // Imprime quantas cartas tem e retorna essa quantidade
	printf("%d", p->topo+1);
    return p->topo+1;
}



void inicializa_pilha(baralho *p){ // inicializa o baralho
    p->topo = -1;
}


void imprime_baralho(baralho p){ // Imprime a pilha 
    carta c;
    printf("\n");
    while(!pilha_vazia(&p)){
        pop(&p,&c);            
        if (c.numero == 15) {
        	printf("Cor = %d Numero = Block  \n",c.cor);
		}
		if (c.numero == 16) {
        	printf("Cor = %d Numero = Reverse \n",c.cor);
		}
		if (c.numero == 17) {
        	printf("Cor = %d Numero = Mais 4 \n",c.cor);
		}
		if (c.numero == 18) {
        	printf("Cor = %d Numero = +2 \n",c.cor);
		}
		if (c.numero == 19 ){
        	printf("Cor = %d Numero = Troca de cor \n",c.cor);
		}
		if (c.numero < 10) {
        	printf("Cor = %d Numero = %d \n",c.cor, c.numero);
		}
	} 
}

/*
int embaralhamento(int embaralhar) {
	baralho *pilha_restante;
    // copia as cartas que sobraram da pilha para um array de cartas
    baralho *atual = pilha_restante;
    carta *array = malloc(sizeof(carta)*embaralhar);
    if (array==NULL) {
      libera_baralho(pilha_restante);
      return 1;
    }
    for (int i=0; i<embaralhar; i++) {
        array[i] = atual->carta;
        atual = atual->next;
    }
    
    // fazendo loop no array de cartas e entregando aleatóriamente
    for (int i=0; i<embaralhar; i++) {
        // procura uma inicial aleatória para trocar com a atual
        int aleatoria_inicial = rand() % (embaralhar-i) +i;
        troca(&array[aleatoria_inicial],&array[i]);
    }

    // coloca cartas do array de volta na pilha_restante
    atual = pilha_restante;
    for (int i=0; i<embaralhar-1; i++) {
        atual-> carta = array[i];
        atual = atual->next;
    }
    
	// para ter certeza que há espaço na memória para o novo baralho, colocado o ultimo elemento para dar null
    atual->carta = array[embaralhar-1];
    atual->next = NULL;
    free(array);
    return 0;
}
                 	
*/	

int main(){
	carta c[MAX];
	int i=0;
	int cor=0;
	int numero=0;
	int count=0;
	
	for(cor=0;cor<4;cor++){
		for(numero=0;numero<10;numero++){
			c[count].cor=cor;
			c[count].numero=numero;
			count++;
		}
	}
	
	for(cor=0;cor<4;cor++){
		c[count].cor=cor;
		c[count].numero=15;
		count++;
		c[count].cor=cor;
		c[count].numero=15;
		count++;
	}
	for(cor=0;cor<4;cor++){
		c[count].cor=cor;
		c[count].numero=16;
		count++;
		c[count].cor=cor;
		c[count].numero=16;
		count++;
	}
	for(cor=0;cor<4;cor++){
		c[count].cor=cor;
		c[count].numero=17;
		count++;
		c[count].cor=cor;
		c[count].numero=17;
		count++;
	}
	for(i=0;i<4;i++){
		c[count].cor=4;
		c[count].numero=18;
		count++;
	}
	for(i=0;i<4;i++){
		c[count].cor=4;
		c[count].numero=19;
		count++;
	}
		
	count=0;
		
	for(count=0;count<MAX;count++){
		printf("Numero: %i \nCor: %i \n", c[count].numero, c[count].cor);
	}
}
