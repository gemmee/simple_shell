#include <string.h>
#include <stdio.h>

int main()
{
	char str[] = "This is a example";
	const char* delimiter = " axe";

	/*First token*/
	char* token = strtok(str, delimiter);
	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = strtok(NULL, delimiter);
	}
	printf("The original string becomes %s\n", str);
	printf("%c\n", *str);
	return 0;
}
