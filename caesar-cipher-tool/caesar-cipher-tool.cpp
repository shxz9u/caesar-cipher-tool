#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable : 6031)

#include <stdio.h>

#define MAX_LENGTH 256

void encrypt(char input[], char output[], int key)
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        char ch = input[i];

        if (ch >= 'a' && ch <= 'z')
        {
            ch = ((ch - 'a' + key) % 26) + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ((ch - 'A' + key) % 26) + 'A';
        }

        output[i] = ch;
    }
}

void decrypt(char input[], char output[], int key)
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        char ch = input[i];

        if (ch >= 'a' && ch <= 'z')
        {
            ch = ((ch - 'a' - key + 26) % 26) + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ((ch - 'A' - key + 26) % 26) + 'A';
        }

        output[i] = ch;
    }
}

int main()
{
    char input[MAX_LENGTH];
    char output[MAX_LENGTH] = { 0 };
    int key;
    int choice;

    printf("암호화(1) 또는 복호화(2)를 선택하세요: ");
    scanf("%d", &choice);
    getchar();

    printf("문자열을 입력하세요: ");
    fgets(input, MAX_LENGTH, stdin);

    printf("키 값을 입력하세요: ");
    scanf("%d", &key);

    if (choice == 1)
    {
        encrypt(input, output, key);
        printf("암호화된 문자열: %s\n", output);
    }
    else if (choice == 2)
    {
        decrypt(input, output, key);
        printf("복호화된 문자열: %s\n", output);
    }
    else
    {
        printf("잘못된 선택입니다.\n");
    }

    return 0;
}
