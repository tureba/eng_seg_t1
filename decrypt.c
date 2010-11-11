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
	unsigned char buffer;

	while (read(0, &buffer, 1)) {
		switch (buffer) {
			case '1':
				buffer = 'a';
				break;
			case '2':
				buffer = 'e';
				break;
			case '3':
				buffer = 'i';
				break;
			case '4':
				buffer = 'o';
				break;
			case '5':
				buffer = 'u';
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
