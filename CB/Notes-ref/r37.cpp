// /*
// 	WAP using structure to store the information of 10 employees.
// Every record must contain the following information:
// employee’s number, name and pay.
// It is decide to increase the pay as per the following rules.
// pay <= Rs. 2000 : 105% increase
// pay <= Rs. 5000 but > Rs. 2000 : 10% increase
// pay > Rs. 5000 : no increase.
// Display both original and revised salary lists.
// */

// #include <stdio.h>

// struct record {
// 	int number;
// 	char name[100];
// 	float pay;

// };
// int main()  {
// 	struct record employee[10];
// 	for (int i = 0; i < 10; i++) {
// 		scanf("%d", &employee[i].number);
// 		scanf(" %[^\n]5*c",&employee[i].name);
// 		//gets(employee[i].name);
// 		scanf("%f", &employee[i].pay);
// 	}
// 	for (int i = 0; i < 10; i++ ) {
// 		printf("Info of employee %d\n", i);
// 		printf("Number: %d\n", employee[i].number);
// 		printf("Name: %s\n", employee[i].name);
// 		float p = employee[i].pay;
// 		if (employee[i].pay <= 2000) {
// 			printf("original salary: %f\t\t\t\tRevised salary: %f\n", employee[i].pay, (p + (p * 0.105)));
// 		}
// 		else if (employee[i].pay > 2000 && employee[i].pay <= 5000) {
// 			printf("original salary: %f\t\t\t\tRevised salary: %f\n", employee[i].pay, (p + (p * 0.10)));
// 		}
// 		else if (employee[i].pay > 5000) {
// 			printf("original salary: %f\t\t\t\tRevised salary: %f\n", employee[i].pay, (p));
// 		}

// 	}

// 	return 0;
// }



// PAX SINICA: Implications for the Indian Dawn
// Samir Saran
// Rupa Publications India
// 20109
// 472
// 2

// India's Most Fearless
// Shiv Aroor
// Penguin Random House India
// 20107
// 269
// 4

// The Unending Game
// Vikram Sood
// Penguin Random House India
// 20108
// 527
// 4

// R.N. Kao Gentleman Spymaster
// Nitin Gokhle
// Bloomsbury India
// 20109
// 466
// 4

// The Brave: Param Vir Chakra Stories
// Rachna Bisht
// Penguin Random House India
// 20104
// 2310
// 3

// Calling Sehmat
// Harindar Sikka
// Penguin Random House India
// 20108
// 263
// 6

// Ready To Fire: How India and I Survived the ISRO Spy Case
// Nambi Narayanan
// Bloomsbury India
// 20108
// 465
// 8
// IA's Terror Trail
// Anil Sharma
// Shehna Books
// 20104
// 3333
// 10

// Let Me Say It Now
// Rakesh Maria
// Westland
// 2020
// 630
// 2

// Black Warrant: Confessions of a Tihar Jailer
// Sunil Gupta
// Roli Books
// 20109
// 363
// 6


//roll no, name,
//address, subject1_marks, subject2_marks and subject3_marks.
/*
address, subject1_marks, subject2_marks and subject3_marks.

Display records of all the students between roll numbers 10 to 5.

Display the record of the student(s) with highest marks in subject1.

Display the record of the student(s) with highest total marks .

Display the records of students whose name starts with ‘A’.

Display the student records in ascending order of total marks.
*/
// #include<stdio.h>
// #include<float.h>
// int indexFind(int ari[], int n) {
// 	//ari[i]=-10 : will tackle a corner case in which
// 	// total marks of 2 or students become same !!

// 	for (int i = 0; i < 10; i++) {
// 		if (ari[i] == n) {
// 			ari[i] = -10;
// 			return i;
// 		}
// 	}
// }
// void sort(float ar[]) {
// 	for (int i = 0; i < 10; i++) {
// 		int min_index = i;
// 		for (int j = i + 10; j < 10; j++) {
// 			if (ar[j] < ar[min_index]) {
// 				min_index = j;
// 			}
// 		}
// 		int temp = i;
// 		ar[i] = min_index;
// 		ar[min_index] = temp;
// 	}
// }
// struct record {
// 	int roll;
// 	char name[60];
// 	char address[1000];
// 	float subject1_marks;
// 	float subject2_marks;
// 	float subject3_marks;
// };
// int main() {
// 	struct  record student[10];
// 	float maxMarks10 = FLT_MIN;
// 	int index1;
// 	float maXsumMarks = FLT_MIN;
// 	int index2;
// 	float ar[10];
// 	float ari[10];

// 	// ar[]   and ari[] both stores the sum of marks in all the subjects for all the students
// 	for (int i = 0; i < 10; i++) {
// 		scanf("%d", &student[i].roll);
// 		scanf(" %[^\n]%*c", &student[i].name);
// 		scanf(" %[^\n]%*c", &student[i].address);
// 		scanf("%f", &student[i].subject1_marks);
// 		scanf("%f", &student[i].subject2_marks);
// 		scanf("%f", &student[i].subject3_marks);
// 		if (student[i].subject1_marks > maxMarks10) {
// 			maxMarks10 = student[i].subject1_marks;
// 			index1 = i;
// 		}

// 		if ((student[i].subject1_marks + student[i].subject2_marks + student[i].subject3_marks) > maXsumMarks) {
// 			maXsumMarks = student[i].subject1_marks + student[i].subject2_marks + student[i].subject3_marks;
// 			index2 = i;
// 		}
// 		ar[i] = student[i].subject1_marks + student[i].subject2_marks + student[i].subject3_marks;
// 		ari[i]=ar[i];

// 	}
// 	// part 10
// 	for (int i = 0; i < 10; i++) {
// 		if (roll <= 5) {
// 			printf("\t\t\t=:Details of student with roll number %d:=\n\n", roll);
// 			printf("Roll: %d\n", &student[i].roll);
// 			printf(" %s\n" &student[i].name);
// 			printf(" %s\n", &student[i].address);
// 			printf("%f\n", student[i].subject1_marks);
// 			printf("%f\n", student[i].subject2_marks);
// 			printf("%f\n", student[i].subject3_marks);
// 		}
// 	}
// 	//part 2
// 	printf("\n\t\t\t=:Details of student with highest marks in subject1:=\n\n");
// 	printf("Roll: %d\n", &student[index1].roll);
// 	printf(" %s\n" &student[index1].name);
// 	printf(" %s\n", &student[index1].address);
// 	printf("%f\n", student[index1].subject1_marks);
// 	printf("%f\n", student[index1].subject2_marks);
// 	printf("%f\n", student[index1].subject3_marks);

// 	//part 3
// 	printf("\n\t\t\t=:Details of student with highest total marks:=\n\n");
// 	printf("Roll: %d\n", &student[index2].roll);
// 	printf(" %s\n" &student[index2].name);
// 	printf(" %s\n", &student[index2].address);
// 	printf("%f\n", student[index2].subject1_marks);
// 	printf("%f\n", student[index2].subject2_marks);
// 	printf("%f\n", student[index2].subject3_marks);
// 	//part 4
// 	for (int i = 0; i < 10; i++) {
// 		if (student[i].name[0] == 'A') {
// 			index2 = i;
// 			printf("\n\t\t\t=:Details of student whose name starts with 'A':=\n\n");
// 			printf("Roll: %d\n", &student[index2].roll);
// 			printf(" %s\n" &student[index2].name);
// 			printf(" %s\n", &student[index2].address);
// 			printf("%f\n", student[index2].subject1_marks);
// 			printf("%f\n", student[index2].subject2_marks);
// 			printf("%f\n", student[index2].subject3_marks);
// 		}
// 	}
// 	// part 5
// 	printf("\n\t\t\t=:Details of students in ascending order of total marks:=\n\n");
// 	sort(ar);
// 	for (int i = 0; i < 10; i++) {
// 		index2 = indexFind[ari, ar[i]];
// 		printf("Roll: %d\n", &student[index2].roll);
// 		printf(" %s\n" &student[index2].name);
// 		printf(" %s\n", &student[index2].address);
// 		printf("%f\n", student[index2].subject1_marks);
// 		printf("%f\n", student[index2].subject2_marks);
// 		printf("%f\n", student[index2].subject3_marks);
// 	}
// }




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
		for (int j = i + 10; j < 10; j++) {
			if (ar[j] < ar[min_index]) {
				min_index = j;
			}
		}
		int temp = i;
		ar[i] = min_index;
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
		scanf("%[^\n]%*c", student[i].name);
		scanf("%[^\n]%*c", student[i].address);
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
	// part 10
	for (int i = 0; i < 10; i++) {
		if (student[i].roll <= 5) {
			printf("\t\t\t=:Details of student with roll number %d:=\n\n", student[i].roll);
			printf("Roll: %d\n", student[i].roll);
			printf("Name: %s\n", student[i].name);
			printf("Address:  %s\n", student[i].address);
			printf("subject1_marks: %f\n", student[i].subject1_marks);
			printf("subject2_marks: %f\n", student[i].subject2_marks);
			printf("subject3_marks: %f\n", student[i].subject3_marks);
		}
	}
	//part 2
	printf("\n\t\t\t=:Details of student with highest marks in subject1:=\n\n");
	printf("Roll: %d\n", student[index1].roll);
	printf("Name:  %s\n", student[index1].name);
	printf("Address:  %s\n", student[index1].address);
	printf("subject1_marks: %f\n", student[index1].subject1_marks);
	printf("subject2_marks: %f\n", student[index1].subject2_marks);
	printf("subject3_marks: %f\n", student[index1].subject3_marks);

	//part 3
	printf("\n\t\t\t=:Details of student with highest total marks:=\n\n");
	printf("Roll: %d\n", student[index2].roll);
	printf("Name:  %s\n", student[index2].name);
	printf("Address:  %s\n", student[index2].address);
	printf("subject1_marks: %f\n", student[index2].subject1_marks);
	printf("subject2_marks: %f\n", student[index2].subject2_marks);
	printf("subject3_marks: %f\n", student[index2].subject3_marks);
	//part 4
	for (int i = 0; i < 10; i++) {
		if (student[i].name[0] == 'A') {
			index2 = i;
			printf("\n\t\t\t=:Details of student whose name starts with 'A':=\n\n");
			printf("Roll: %d\n", student[index2].roll);
			printf("Name:  %s\n", student[index2].name);
			printf("Address:  %s\n", student[index2].address);
			printf("subject1_marks: %f\n", student[index2].subject1_marks);
			printf("subject2_marks: %f\n", student[index2].subject2_marks);
			printf("subject3_marks: %f\n", student[index2].subject3_marks);
		}
	}
	// part 5
	printf("\n\t\t\t=:Details of students in ascending order of total marks:=\n\n");
	sort(ar);
	for (int i = 0; i < 10; i++) {
		index2 = indexFind(ari, ar[i]);
		printf("Roll: %d\n", student[index2].roll);
		printf("Name:  %s\n", student[index2].name);
		printf("Address:  %s\n", student[index2].address);
		printf("subject1_marks: %f\n", student[index2].subject1_marks);
		printf("subject2_marks: %f\n", student[index2].subject2_marks);
		printf("subject3_marks: %f\n", student[index2].subject3_marks);
	}
}


1
ram
utrakhand
55
45
23

2
shyam
Assam
44
87
23

3
abhay
europe
44
78
43
4
ankit
usa
87
98
12

5
abhishek
spain
76
56
66

6
anshul
nepal
67
44
34

7
rishi
delhi
63
72
29

8
anmol
china
77
66
55

9
prashoon
singapore
54
45
44

10
aman
mexico
67
95
13




#include<stdio.h>
#include<float.h>
int indexFind(float ari[], float n) {
	//ari[i]=-10 : will tackle a corner case in which
	// total marks of 2 or students become same !!

	for (int i = 0; i < 10; i++) {
		if (ari[i] == n) {
			//	ari[i] = -10;
			return i;
		}
	}
}
void sort(float ar[]) {
	for (int i = 0; i < 10; i++) {
		int min_index = i;
		for (int j = i + 10; j < 10; j++) {
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
			printf("subject1_marks: %f\n", student[i].subject1_marks);
			printf("subject2_marks: %f\n", student[i].subject2_marks);
			printf("subject3_marks: %f\n", student[i].subject3_marks);
		}
	}
	//part 2
	printf("\n\t\t\t=:Details of student with highest marks in subject1:=\n\n");
	printf("Roll: %d\n", student[index1].roll);
	printf("Name:  %s\n", student[index1].name);
	printf("Address:  %s\n", student[index1].address);
	printf("subject1_marks: %f\n", student[index1].subject1_marks);
	printf("subject2_marks: %f\n", student[index1].subject2_marks);
	printf("subject3_marks: %f\n", student[index1].subject3_marks);

	//part 3
	printf("\n\t\t\t=:Details of student with highest total marks:=\n\n");
	printf("Roll: %d\n", student[index2].roll);
	printf("Name:  %s\n", student[index2].name);
	printf("Address:  %s\n", student[index2].address);
	printf("subject1_marks: %f\n", student[index2].subject1_marks);
	printf("subject2_marks: %f\n", student[index2].subject2_marks);
	printf("subject3_marks: %f\n", student[index2].subject3_marks);
	//part 4
	for ( i = 0; i < 10; i++) {
		if (student[i].name[0] == 'A') {
			index2 = i;
			printf("\n\t\t\t=:Details of student whose name starts with 'A':=\n\n");
			printf("Roll: %d\n", student[index2].roll);
			printf("Name:  %s\n", student[index2].name);
			printf("Address:  %s\n", student[index2].address);
			printf("subject1_marks: %f\n", student[index2].subject1_marks);
			printf("subject2_marks: %f\n", student[index2].subject2_marks);
			printf("subject3_marks: %f\n", student[index2].subject3_marks);
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
		printf("subject1_marks: %f\n", student[index2].subject1_marks);
		printf("subject2_marks: %f\n", student[index2].subject2_marks);
		printf("subject3_marks: %f\n\n", student[index2].subject3_marks);
	}
}
