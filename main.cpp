#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
#ifdef PUTS 
    printf("Testing Puts:\n");

    for (int i = 0; i < 8; ++i) {
        Puts(data[i]);
        puts(data[i]);
        printf("%d %d\n", Puts(data[i]), puts(data[i]));
        printf("\n");
    }

#elif STRCHR
    const char* data[] = {"absdvsv", "svasfvas", "aaaaaa", "", " ", "1234567890", "Symon", "ccccccc"};
    printf("Testing Strchr\n");

    for (int i = 0; i < 8; ++i) {
        printf("%p %p\n", Strchr(data[i], 'a'), strchr(data[i], 'a'));
    }

#elif STRLEN
    const char* data[] = {"absdvsv", "svasfvas", "aaaaaa", "", " ", "1234567890", "Symon", "ccccccc"};
    printf("Testing Strlen:\n");

    for (int i = 0; i < 8; ++i) {
        printf("%ld %ld\n", Strlen(data[i]), strlen(data[i]));
    }

#elif STRCPY
    const char* data[] = {"absdvsv", "svasfvas", "aaaaaa", "", " ", "1234567890", "Symon", "ccccccc"};
    printf("Testing Strcpy:\n");
    
    for (int i = 0; i < 8; ++i) {
        char tmp[20];
        scanf("%s", tmp);

        printf("%s %s\n", Strcpy(tmp, data[i]), strcpy(tmp, data[i]));
        printf("%p %p\n", Strcpy(tmp, data[i]), strcpy(tmp, data[i]));
    }

#elif STRNCPY
    const char* data[] = {"absdvsv", "svasfvas", "aaaaaa", "", " ", "1234567890", "Symon", "ccccccc"};
    printf("Testing Strncpy:\n");

    for (int i = 0; i < 8; ++i) {
        char tmp[20];
        scanf("%s", tmp);

        printf("%s %s\n", Strncpy(tmp, data[i], i + 1), strncpy(tmp, data[i], i + 1));
        printf("%p %p\n", Strncpy(tmp, data[i], i + 1), strncpy(tmp, data[i], i + 1));
    }

#elif FGETS
    char buffer[300];

    printf("Testing Fgets:\n");
    FILE* file = fopen("test.txt", "r");

    while (!feof(file)) {
        Fgets(buffer, 300, file);
        printf("%s\n", buffer);
    }

    fclose(file);

#elif STRDUP
    printf("Testing Strdup\n");
    char str[] = "sdasdcsdcsvsdv vvqrvq";
    char* dupstr = Strdup(str);
    printf("%s  %s\n", str, dupstr);
    printf("%p %p\n", str, dupstr);
    free(dupstr);

#elif GETLINE
    printf("Testing Getline\n");
    FILE* file = fopen("test.txt", "r");
    FILE* file1 = fopen("test.txt", "r");

    int n = 15;
    size_t n1 = 15;
    char* buffer = (char*)calloc(n, sizeof(char));
    char* buffer1 = (char*)calloc(n, sizeof(char));

    printf("%d %ld\n", Getline(&buffer, &n, file), getline(&buffer1, &n1, file1));
    printf("%s%s", buffer, buffer1);

    fclose(file);
    fclose(file1);

    free(buffer);
    free(buffer1);


#else 
    const char* data[] = {"absdvsv", "svasfvas", "aaaaaa", "", " ", "1234567890", "Symon", "ccccccc"};
    
    printf("Testing Puts:\n");

    for (int i = 0; i < 8; ++i) {
        Puts(data[i]);
        puts(data[i]);
        printf("%d %d\n", Puts(data[i]), puts(data[i]));
        printf("\n");
    }

    printf("Testing Strlen:\n");

    for (int i = 0; i < 8; ++i) {
        printf("%ld %ld\n", Strlen(data[i]), strlen(data[i]));
    }

    printf("Testing Strcpy:\n");
    
    for (int i = 0; i < 8; ++i) {
        char tmp[20];
        scanf("%s", tmp);

        printf("%s %s\n", Strcpy(tmp, data[i]), strcpy(tmp, data[i]));
        printf("%p %p\n", Strcpy(tmp, data[i]), strcpy(tmp, data[i]));
    }

    printf("Testing Strncpy:\n");

    for (int i = 0; i < 8; ++i) {
        char tmp[20];
        scanf("%s", tmp);

        printf("%s %s\n", Strncpy(tmp, data[i], i + 1), strncpy(tmp, data[i], i + 1));
        printf("%p %p\n", Strncpy(tmp, data[i], i + 1), strncpy(tmp, data[i], i + 1));
    }

    char buffer[300];

    printf("Testing Fgets:\n");
    FILE* file = fopen("test.txt", "r");

    while (!feof(file)) {
        Fgets(buffer, 300, file);
        printf("%s\n", buffer);
    }

    fclose(file);

    printf("Testing Strdup\n");
    char str[] = "sdasdcsdcsvsdv vvqrvq";
    char* dupstr = Strdup(str);
    printf("%s  %s\n", str, dupstr);
    printf("%p %p\n", str, dupstr);
    free(dupstr);

#endif
}