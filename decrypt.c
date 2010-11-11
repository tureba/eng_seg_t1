#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

int main (int argc, char ** argv, char ** envp)
{
	if (argc < 2)
		return 1;

	if (strlen(argv[1]) != 5)
		return 1;

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
