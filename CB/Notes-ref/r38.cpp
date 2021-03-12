#include<stdio.h>
#include<float.h>
int indexFind(float ari[], float n) {
  //ari[i]=-10 : will tackle a corner case in which
  // total marks of 2 or students become same !!

  for (int i = 0; i < 10; i++) {
    if (ari[i] == n) {
      ari[i] = -10;
      return i;
    }
  }
}
void sort(float ar[]) {
  for (int i = 0; i < 10; i++) {
    int min_index = i;
    for (int j = i + 1; j < 10; j++) {
      if (ar[j] < ar[min_index]) {
        min_index = j;
      }
    }
    float temp = ar[i];
    ar[i] = ar[min_index];
    ar[min_index] = temp;
  }
}
struct record {
  int roll;
  char name[60];
  char address[1000];
  float subject1_marks;
  float subject2_marks;
  float subject3_marks;
};
int main() {
  struct  record student[10];
  float maxMarks10 = FLT_MIN;
  int index1;
  float maXsumMarks = FLT_MIN;
  int index2;
  float ar[10];
  float ari[10];

  // ar[]   and ari[] both stores the sum of marks in all the subjects for all the students
  for (int i = 0; i < 10; i++) {
    scanf("%d", &student[i].roll);
    scanf(" %[^\n]%*c", student[i].name);
    scanf(" %[^\n]%*c", student[i].address);
    scanf("%f", &student[i].subject1_marks);
    scanf("%f", &student[i].subject2_marks);
    scanf("%f", &student[i].subject3_marks);
    if (student[i].subject1_marks > maxMarks10) {
      maxMarks10 = student[i].subject1_marks;
      index1 = i;
    }

    if ((student[i].subject1_marks + student[i].subject2_marks + student[i].subject3_marks) > maXsumMarks) {
      maXsumMarks = student[i].subject1_marks + student[i].subject2_marks + student[i].subject3_marks;
      index2 = i;
    }
    ar[i] = student[i].subject1_marks + student[i].subject2_marks + student[i].subject3_marks;
    ari[i] = ar[i];

  }
  // part 1
  int i;
  for ( i = 0; i < 10; i++) {
    if (student[i].roll <= 5) {
      printf("\t\t\t=:Details of student with roll number %d:=\n\n", student[i].roll);
      printf("Roll: %d\n", student[i].roll);
      printf("Name: %s\n", student[i].name);
      printf("Address:  %s\n", student[i].address);
      printf("subject1_marks: %0.2f\n", student[i].subject1_marks);
      printf("subject2_marks: %0.2f\n", student[i].subject2_marks);
      printf("subject3_marks: %0.2f\n", student[i].subject3_marks);
    }
  }
  //part 2
  printf("\n\t\t\t=:Details of student with highest marks in subject1:=\n\n");
  printf("Roll: %d\n", student[index1].roll);
  printf("Name:  %s\n", student[index1].name);
  printf("Address:  %s\n", student[index1].address);
  printf("subject1_marks: %0.2f\n", student[index1].subject1_marks);
  printf("subject2_marks: %0.2f\n", student[index1].subject2_marks);
  printf("subject3_marks: %0.2f\n", student[index1].subject3_marks);

  //part 3
  printf("\n\t\t\t=:Details of student with highest total marks:=\n\n");
  printf("Roll: %d\n", student[index2].roll);
  printf("Name:  %s\n", student[index2].name);
  printf("Address:  %s\n", student[index2].address);
  printf("subject1_marks: %0.2f\n", student[index2].subject1_marks);
  printf("subject2_marks: %0.2f\n", student[index2].subject2_marks);
  printf("subject3_marks: %0.2f\n", student[index2].subject3_marks);
  //part 4
  for ( i = 0; i < 10; i++) {
    if (student[i].name[0] == 'A') {
      index2 = i;
      printf("\n\t\t\t=:Details of student whose name starts with 'A':=\n\n");
      printf("Roll: %d\n", student[index2].roll);
      printf("Name:  %s\n", student[index2].name);
      printf("Address:  %s\n", student[index2].address);
      printf("subject1_marks: %0.2f\n", student[index2].subject1_marks);
      printf("subject2_marks: %0.2f\n", student[index2].subject2_marks);
      printf("subject3_marks: %0.2f\n", student[index2].subject3_marks);
    }
  }
  // part 5
  printf("\n\t\t\t=:Details of students in ascending order of total marks:=\n\n");


  sort(ar);

  for ( i = 0; i < 10; i++) {
    index2 = indexFind(ari, ar[i]);

    printf("Roll: %d\n", student[index2].roll);
    printf("Name:  %s\n", student[index2].name);
    printf("Address:  %s\n", student[index2].address);
    printf("subject1_marks: %0.2f\n", student[index2].subject1_marks);
    printf("subject2_marks: %0.2f\n", student[index2].subject2_marks);
    printf("subject3_marks: %0.2f\n\n", student[index2].subject3_marks);
  }


}