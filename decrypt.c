/*
	Primeiro Trabalho Prático de Engenharia de Segurança
	--- Programa de decriptação de dados

	Autores:
	-	Arthur Nascimento - nºUSP 5634455
	-	Gabriel Lima      - nºUSP 5744830

 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

void help(char * arg0)
{
	fprintf(stderr, "uso: %s <chave>\n", arg0);
	fprintf(stderr, "\t<chave>: os números 1 a 5\n");
	exit(1);
}

int main (int argc, char ** argv, char ** envp)
{
	if (argc < 2)
		help(argv[0]);

	if (strlen(argv[1]) != 5)
		help(argv[0]);

	int salto = argv[1][0] + argv[1][2] + argv[1][4] - '1' * 3;
	unsigned char buffer, vogais[5];
	for (int i = 0; i < 5; i++)
		switch (argv[1][i]) {
			case '1':
				vogais[i] = 'a';
				break;
			case '2':
				vogais[i] = 'e';
				break;
			case '3':
				vogais[i] = 'i';
				break;
			case '4':
				vogais[i] = 'o';
				break;
			case '5':
				vogais[i] = 'u';
				break;
		}

	while (read(0, &buffer, 1)) {
		switch (buffer) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
				buffer = vogais[buffer - '0'];
				break;
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				buffer = vogais[buffer - '5'] + ('A' - 'a');
				break;
			default:
				if (isalpha(buffer)) {
					if (islower(buffer)) {
						buffer = buffer + salto;
						if (buffer > 'z')
							buffer -= 26;
					} else {
						buffer = buffer - salto;
						if (buffer < 'A')
							buffer += 26;
					}
				}
		}
		write(1, &buffer, 1);
	}

	return 0;
}
