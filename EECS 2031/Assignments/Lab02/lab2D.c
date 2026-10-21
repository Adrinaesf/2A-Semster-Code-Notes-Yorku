#include <stdio.h>
#include <string.h>

#define SIZE 35
void my_strcat(char des[], char src[]);

int main() {
    char a[SIZE], b[SIZE], c[SIZE], d[SIZE];

    printf("Enter the first string: ");
    scanf("%s", a);
    printf("Enter the second string: ");
    scanf("%s", b);

    while (!(strcmp(a, "xxx") == 0 && strcmp(b, "xxx") == 0)) {
        strcpy(c, a);
        strcpy(d, b);

        strcat(a, b);
        my_strcat(c, d);

        printf("Original strcat: %s\n", a);
        printf("My strcat: %s\n\n", c);

        printf("Enter the first string: ");
        scanf("%s", a);

        printf("Enter the second string: ");
        scanf("%s", b);
    }
    return 0;
}

void my_strcat(char des[], char src[]) {
    int start = strlen(des);
    int j = 0;

    while (src[j] != '\0') {
        des[start] = src[j];
        start++;
        j++;
    }

    des[start] = '\0';
}