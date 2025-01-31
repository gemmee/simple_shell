#include <stdio.h>

int main()
{
	char buffer[20];
	char buffer1[20];
	int written = snprintf(buffer, sizeof(buffer), "Hello, %s!", "Gamachu");
	int written1 = snprintf(buffer1, sizeof(buffer1), "Number %d: %s!", 19, "Gamachu Abara");

	printf("Buffer: %s\n", buffer);
	printf("Characters written: %d\n", written);
	printf("Buffer1: %s\n", buffer1);
	printf("Characters written: %d\n", written1);

	return 0;
}
