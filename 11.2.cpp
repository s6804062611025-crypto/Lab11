#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_SCORE 5
#define NO_STD   10

typedef struct {
    char name[32];
    int score[NO_SCORE];
    float total;
} Student;

void writeData(Student std[], int n);
void readData(Student std[], int n);
float findAverage(Student s);
void findLessThanTen(Student s);

int main() {
    Student std[NO_STD];
    int i,j;

    for(i=0; i<NO_STD; i++) {
        printf("Enter name for student %d: ", i+1);
        scanf("%s", std[i].name);
        std[i].total = 0;
        for(j=0; j<NO_SCORE; j++) {
            printf("Enter score %d: ", j+1);
            scanf("%d", &std[i].score[j]);
            std[i].total += std[i].score[j];
        }
    }

    writeData(std, NO_STD);

    Student readStd[NO_STD];
    readData(readStd, NO_STD);

    for(i=0; i<NO_STD; i++) {
        printf("\n%s total = %.2f, average = %.2f", 
               readStd[i].name, readStd[i].total, findAverage(readStd[i]));
        findLessThanTen(readStd[i]);
    }

    return 0;
}

void writeData(Student std[], int n) {
    FILE *fp = fopen(".\\lab11\\no2\\std10.dat","wb");
    if(fp==NULL) { printf("File error\n"); exit(1); }
    fwrite(std, sizeof(Student), n, fp);
    fclose(fp);
}

void readData(Student std[], int n) {
    FILE *fp = fopen(".\\lab11\\no2\\std10.dat","rb");
    if(fp==NULL) { printf("File error\n"); exit(1); }
    fread(std, sizeof(Student), n, fp);
    fclose(fp);
}

float findAverage(Student s) {
    return s.total / NO_SCORE;
}

void findLessThanTen(Student s) {
    int i, found=0;
    printf("\nScores less than 10:");
    for(i=0; i<NO_SCORE; i++) {
        if(s.score[i] <= 10) {
            printf(" Test%d=%d", i+1, s.score[i]);
            found=1;
        }
    }
    if(!found) printf(" None");
}

