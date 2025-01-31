#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * splitString: split a string into words
 * @str: the string to be splitted
 * @delimiter: the delimiter character
 * @wordCount:
 *
 * Return: an array of strings
 */
char** splitString(const char* str, const char* delimiter, int* wordCount)
{
	/* Make a copy of the input string because strtok modifies the string */
	char* strCopy = strdup(str);
	if (!strCopy)
	{
		perror("strdup failed");
		return NULL;
	}

	/* Calculate the maximum number of words to allocate memory */
	int maxWords = 10;
	char** result = malloc(maxWords * sizeof(char*));
	if (!result)
	{
		perror("malloc failed");
		free(strCopy);
		return NULL;
	}

	/* Tokenize the string using strtok */
	char* token = strtok(strCopy, delimiter);
	int count = 0;
	while (token != NULL)
	{
		/* Reallocate memory if needed */
		if (count >= maxWords)
		{ 
			maxWords *= 2;
			char** temp = realloc(result, maxWords * sizeof(char*));
			if (!temp)
			{
				perror("realloc failed");
				free(result);
				free(strCopy);
				return NULL;
			}
			result = temp;
		}

		/* Allocate memory for the current token and store it */
		result[count] = strdup(token);
		if (!result[count])
		{
			perror("strdup failed");
			for (int i = 0; i < count; i++)
			{
				free(result[i]);
			}
			free(result);
			free(strCopy);
			return NULL;
		}
		count++;
		token = strtok(NULL, delimiter);
	}

	/* Free the copy of the original string */
	free(strCopy);

	/* Store the number of words */
	*wordCount = count;

	/* Resize the result array to fit the exact number of words */
	/* this ensures that no extra memory remains allocated*/
	char** finalResult = realloc(result, count * sizeof(char*));
	if (!finalResult)
	{
		perror("realloc failed");
		return result;
	}
	return finalResult;

}

/**
 * main: demonstrate the splitString function
 *
 * Return: 0
 */
int main()
{
	const char* input = "This is an example string to split.";
	const char* delimiter = " ";
	int wordCount;

	char** words = splitString(input, delimiter, &wordCount);
	if (!words)
	{
		return 1;
	}
	printf("The string contains %d words:\n", wordCount);
	for (int i = 0; i < wordCount; i++)
	{
		printf("%s\n", words[i]);
		free(words[i]); /* free each word*/
	}
	free(words); /* free the array of words */

	return 0;
}
