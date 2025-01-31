#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PATH_DELIM ":"

void find_executable(const char *filename) {
    char *path_env = getenv("PATH");
    if (!path_env) {
        fprintf(stderr, "Error: PATH environment variable not found.\n");
        return;
    }
    
    char *path = strdup(path_env);
    if (!path) {
        perror("strdup");
        return;
    }
    
    char *dir = strtok(path, PATH_DELIM);
    while (dir) {
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, filename);
        
        if (access(full_path, X_OK) == 0) {
            printf("%s\n", full_path);
        }
        
        dir = strtok(NULL, PATH_DELIM);
    }
    
    free(path);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    for (int i = 1; i < argc; i++) {
        find_executable(argv[i]);
    }
    
    return EXIT_SUCCESS;
}

