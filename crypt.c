/*
	Primeiro Trabalho Prático de Engenharia de Segurança
	--- Programa de encriptação de dados

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
	unsigned char buffer;

	while (read(0, &buffer, 1)) {
		switch (buffer) {
			case 'a':
				buffer = argv[1][0] - 1;
				break;
			case 'e':
				buffer = argv[1][1] - 1;
				break;
			case 'i':
				buffer = argv[1][2] - 1;
				break;
			case 'o':
				buffer = argv[1][3] - 1;
				break;
			case 'u':
				buffer = argv[1][4] - 1;
				break;
			case 'A':
				buffer = argv[1][0] + 4;
				break;
			case 'E':
				buffer = argv[1][1] + 4;
				break;
			case 'I':
				buffer = argv[1][2] + 4;
				break;
			case 'O':
				buffer = argv[1][3] + 4;
				break;
			case 'U':
				buffer = argv[1][4] + 4;
				break;
			default:
				if (isalpha(buffer)) {
					if (islower(buffer)) {
						buffer = buffer - salto;
						if (buffer < 'a')
							buffer += 26;
					} else {
						buffer = buffer + salto;
						if (buffer > 'Z')
							buffer -= 26;
					}
				}
		}
		write(1, &buffer, 1);
	}

	return 0;
}
