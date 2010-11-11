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
			case 'a':
				buffer = argv[1][0];
				break;
			case 'e':
				buffer = argv[1][1];
				break;
			case 'i':
				buffer = argv[1][2];
				break;
			case 'o':
				buffer = argv[1][3];
				break;
			case 'u':
				buffer = argv[1][4];
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
