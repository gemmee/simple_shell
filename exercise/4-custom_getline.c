#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream) {
    // Check if lineptr or n is NULL
    if (lineptr == NULL || n == NULL || stream == NULL) {
        return -1;
    }

    // Allocate memory if not already allocated
    if (*lineptr == NULL) {
        *n = 128; // Default buffer size
        *lineptr = malloc(*n);
        if (*lineptr == NULL) {
            return -1; // Memory allocation failed
        }
    }

    size_t pos = 0; // Current position in the buffer
    int c;          // Character being read

    while ((c = fgetc(stream)) != EOF) {
        // Resize buffer if necessary
        if (pos + 1 >= *n) {
            size_t new_size = *n * 2; // Double the buffer size
            char *new_buffer = realloc(*lineptr, new_size);
            if (new_buffer == NULL) {
                return -1; // Memory reallocation failed
            }
            *lineptr = new_buffer;
            *n = new_size;
        }

        // Append character to the buffer
        (*lineptr)[pos++] = c;

        // Stop reading on newline
        if (c == '\n') {
            break;
        }
    }

    // Handle EOF without reading any characters
    if (pos == 0 && c == EOF) {
        return -1;
    }

    // Null-terminate the string
    (*lineptr)[pos] = '\0';

    return pos; // Return the number of characters read
}

int main(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    printf("Custom getline shell\n");
    printf("Press Ctrl+D to exit.\n");

    while (1) {
        printf("$ ");
        fflush(stdout);

        nread = custom_getline(&line, &len, stdin);

        if (nread == -1) { // End-of-file or error
            printf("\n");
            break;
        }

        printf("You entered: %s", line);
    }

    free(line); // Free the allocated memory
    return 0;
}

