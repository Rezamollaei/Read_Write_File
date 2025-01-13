#include <stdio.h>
#include <stdlib.h>
int main() {
    //write on txt files

    FILE *fptr;
    int num;
    char name[30];
    int number_of_persons;
    fptr = fopen("file.txt", "a");
    if (fptr == NULL) {
        printf("Error");
        exit(1);
    }
    printf("Pleas enter number of persons: ");
    scanf("%d", &number_of_persons);
    for (int i = 0; i < number_of_persons; ++i) {
        printf("enter id and name: ");
        scanf("%d %29s", &num, &name);
        fprintf(fptr, "%d %s \n", num, name);
    }
    fclose(fptr);


    //------>read text from file and print it<---------

    FILE *fptr2;
    int number;
    char name2[30];
    fptr2 = fopen("file.txt", "r");
    if (fptr2 == NULL) {
        printf("error");
        exit(1);
    }

    int lineCount = 0;
    char ch;
    while ((ch = fgetc(fptr2)) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }
    }
    rewind(fptr2);

    for (int i = 0; i < lineCount; ++i) {
        fscanf(fptr2, "%d %s", &number, name2);
        printf("student name is:%s \n matricola is :%d \n ", name2, number);
    }
    fclose(fptr2);


    //-------->work with binary files<----------//
    struct threenum {
        int n1, n2, n3;
    };
        int n;
        struct threenum num1;
        FILE *fptr3;

        if ((fptr3 = fopen("mybinary.bin", "wb")) == NULL) {
            printf("error");
            exit(1);
        }
        for (int n = 1; n < 5; ++n) {
            num1.n1 = n;
            num1.n2 = 5 * n;
            num1.n3 = 5 * n + 1;
            fwrite(&num1, sizeof(struct threenum), 1, fptr3);
        }
        fclose(fptr3);
        for (int n = 1; n < 5; ++n) {
            fread(&num1, sizeof(struct threenum), 1, fptr3);
            printf("n1:%d \t n2:%d \t n3:%d \t n4:%d ", num1.n1, num1.n2, num1.n3);

        }
        fclose(fptr3);

    return 0;
}