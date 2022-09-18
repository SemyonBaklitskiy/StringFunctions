#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

void test_puts() {
    const char* data[] = {"absdvsv", "svasfvas", "aaaaaa", "", "q", "1234567890", "Symon", "ccccccc"};
    printf("Testing Puts:\n");

    for (int i = 0; i < 8; ++i) {
        int n = Puts(data[i]);
        int n1 = puts(data[i]);
        printf("%d %d\n", n, n1);
    }
}

void test_strchr() {
    const char* data[] = {"absdvsv", "svasfvas", "aaaaaa", "", "q", "1234567890", "Symon", "ccccccc"};
    printf("Testing Strchr ('a'):\n");

    for (int i = 0; i < 8; ++i) {
        printf("%p %p\n", Strchr(data[i], 'a'), strchr(data[i], 'a'));
    }
}

void test_strlen() {
    const char* data[] = {"absdvsv", "svasfvas", "aaaaaa", "", "q", "1234567890", "Symon", "ccccccc"};
    printf("Testing Strlen:\n");

    for (int i = 0; i < 8; ++i) {
        printf("%d %ld\n", Strlen(data[i]), strlen(data[i]));
    }
}

void test_strcpy() {
    const char* data[] = {"absdvsv", "svasfvas", "aaaaaa", "", "q", "1234567890", "Symon", "ccccccc"};
    printf("Testing Strcpy:\n");
    
    for (int i = 0; i < 8; ++i) {
        char tmp[50];

        printf("%s\n", Strcpy(tmp, data[i]));
        printf("%p\n", Strcpy(tmp, data[i]));
    }
}

void test_strncpy() {
    const char* data[] = {"absdvsv", "svasfvas", "aaaaaa", "", "q", "1234567890", "Symon", "ccccccc"};
    printf("Testing Strncpy:\n");

    for (int i = 0; i < 8; ++i) {
        char tmp[50];

        printf("%s\n", Strncpy(tmp, data[i], i + 1));
        printf("%p\n", Strncpy(tmp, data[i], i + 1));
    }
}

void test_fgets() {
    char buffer[100];
    char buffer1[100];

    printf("Testing Fgets:\n");
    FILE* file = fopen("test.txt", "r");
    FILE* file1 = fopen("test.txt", "r");

    printf("My Fgets:\n");

    while (!feof(file)) {
        Fgets(buffer, 100, file);
        printf("%s", buffer);
    }

    printf("\n");
    printf("Library fgets:\n");

    while (!feof(file1)) {
        fgets(buffer1, 100, file1);
        printf("%s", buffer1);
    }

    fclose(file);
    fclose(file1);
}

void test_strdup() {
    printf("Testing Strdup\n");

    char str[] = "Copied string";
    char* dupstr = Strdup(str);

    printf("%s %s\n", str, dupstr);
    printf("%p %p\n", str, dupstr);
    free(dupstr);
}

void test_strcat() {
    const char* data[] = { "absdvsv", "svasfvas", "aaaaaa", "", "q", "1234567890", "Symon", "ccccccc" };
    char result[50];

    printf("Testing strcat:\n");
    
    printf("Enter string: ");
    scanf("%s", result);

    for (int i = 0; i < 8; ++i) {
        printf("%s\n", result);
        printf("%s\n", data[i]);
        printf("%s\n", Strcat(result, data[i]));
        printf("\n");
    }
}

void test_strncat() {
    const char* data[] = { "absdvsv", "svasfvas", "aaaaaa", "", "q", "1234567890", "Symon", "ccccccc" };
    char result[50];

    printf("Testing strncat:\n");
    
    printf("Enter string: ");
    scanf("%s", result);

    for (int i = 0; i < 8; ++i) {
        printf("%s\n", result);
        printf("%s\n", data[i]);
        printf("%s\n", Strncat(result, data[i], i + 1));
        printf("\n");
    }
}

void test_getline() {
    int n = 100;
    char* buffer = NULL;


    FILE* f = fopen("test.txt", "r");

    int i = 0;

    while (i < 8) {
        buffer = (char*)calloc(n, sizeof(char));
        Getline(&buffer, &n, f);
        printf("%s", buffer);
        free(buffer);
        buffer = NULL;
        ++i;
    }

    fclose(f);
}
