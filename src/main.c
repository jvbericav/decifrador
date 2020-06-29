/* Tarefa de decifrar uma cifra
 *
 * João Vitor Berica Vicente, 199867
 */

#include <stdio.h>

#define TAM_BUFFER 55
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];
const char senha[] = "SENHASECRETA";

char decoder(char c, char b){
	char a;
	if(c>='A' && c<='Z'){
		/*isolando <a> na fórmula do c0 do codificador*/
		a = 'A'+(c-b)%('Z'-'A'+1);
		/*contempla casos em que a letra de entrada é menor que a letra da senha*/
		if((c-b)<0)
			a += 26; 
		return a;
	}
	else return c;
}

int main() {

	int i=0, j=0;

	/* Leitura da entrada */
	fgets(buffer_entrada, TAM_BUFFER, stdin);

	for(i=0; (i<TAM_BUFFER) && (buffer_entrada[i]!='\0') && (buffer_entrada[i]!='\n'); i++){
		buffer_saida[i] = decoder(buffer_entrada[i], senha[j]);
		j++;
		if(senha[j]=='\0')
			j=0;
	}
	buffer_saida[i]='\0';

	/* Escreve a saida na tela */
	printf("%s\n", buffer_saida);

	return 0;
}
