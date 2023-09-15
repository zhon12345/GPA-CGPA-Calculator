#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#pragma warning(disable:4996)

#define MAX_STUDENTS 100
#define MAX_COURSES 20

struct course {
	char code[8];
	int creditHrs;
	char grade[3];
	int semester;
};

struct student {
	char name[50];
	char studentID[10];
	int numCourses;
	struct course courses[MAX_COURSES];
	float gpa[3];
};

void staffLogin(struct student students[], int *numStudents);
void staffMenu(struct student students[], int *numStudents);
void studentLogin(struct student students[], int* numStudents);
void studentMenu(struct student student);
void enterStudentDetails(struct student student[]);
void enterCourseDetails(struct student student[]);
void dispGPAs(struct student student, int isCGPA);
void calcGPAs(struct student student, int semester, int isGPA);

int main() {
	struct student students[MAX_STUDENTS];
	int input, numStudents = 0;

	while(1) {
		system("cls");
		printf("%45s\n", "=========================================");
		printf("%30s\n", "KOLEJ PASAR");
		printf("%45s\n\n", "=========================================");
		printf("%31s\n", "1. Staff Portal");
		printf("%33s\n", "2. Student Portal");
		printf("%23s\n\n\n", "3. Exit");
		printf("%35s", "Enter your choice => ");
		scanf("%d", &input);
        rewind(stdin);

		switch (input) {
		case 1: staffLogin(students, &numStudents); break;
		case 2: studentLogin(students, &numStudents); break;
		case 3: exit(0);
		default:
			printf("\033[A\33[2K\r%41s\n", "ERROR: Invalid Option selected...");
			printf("\033[A\033[41C");
			system("pause > NULL");
		}
	}
}

void staffLogin(struct student students[], int *numStudents) {
	char username[6], password[10];
	int input;

	while (1) {
		system("cls");
		printf("%45s\n", "=========================================");
		printf("%37s\n", "KOLEJ PASAR ADMINS PORTAL");
		printf("%45s\n\n", "=========================================");
		printf("%28s\n", "1. Login");
		printf("%27s\n\n\n", "2. Back");
		printf("%35s", "Enter your choice => ");
		scanf("%d", &input);
		rewind(stdin);

		switch (input) {
		case 1:
			system("cls");
			printf("%45s\n", "=========================================");
			printf("%37s\n", "KOLEJ PASAR ADMINS PORTAL");
			printf("%45s\n\n", "=========================================");
			printf("%25s", "Username: ");
			fgets(username, sizeof(username), stdin);
			username[strcspn(username, "\n")] = '\0';
			rewind(stdin);

			printf("%25s", "Password: ");
			fgets(password, sizeof(password), stdin);
			password[strcspn(password, "\n")] = '\0';

			if (strcmp(username, "admin") == 0 && strcmp(password, "admin123!") == 0) {
				staffMenu(students, numStudents);
				break;
			}
			else {
				system("cls");
				printf("Incorrect username or password, please try again...\n");
				system("pause");
			}
			break;
		case 2:
			return;
		default:
			printf("\033[A\33[2K\r%41s\n", "ERROR: Invalid Option selected...");
			printf("\033[A\033[41C");
			system("pause > NULL");
		}
	}
}

void staffMenu(struct student students[], int *numStudents) {
	int input;
	while (1) {
		system("cls");
		printf("%45s\n", "=========================================");
		printf("%37s\n", "KOLEJ PASAR ADMINS PORTAL");
		printf("%45s\n\n", "=========================================");
		printf("%34s\n", "1. Enter student's details");
		printf("%41s\n", "2. Enter student's course details");
		printf("%35s\n", "3. View student's GPA score");
		printf("%36s\n", "4. View student's CGPA score");
		printf("%15s\n\n\n", "5. Logout");
		printf("%35s", "Enter your choice => ");
		scanf("%d", &input);
		rewind(stdin);

		switch (input) {
		case 1:
			if (*numStudents < MAX_STUDENTS) {
				enterStudentDetails(&students[*numStudents]);

				printf("\nSuccess!\n");
				printf("Name: %s\n", students[*numStudents].name);
				printf("StudentID: %s\n", students[*numStudents].studentID);
				(*numStudents)++;
                system("pause");
			}
			else {
				system("cls");
				printf("You have reached the max number of students");
				system("pause");
			}
			break;
		case 2:
		case 3:
		case 4:
			if (*numStudents <= 0) {
				system("cls");
				printf("No students in database, please try again...\n");
				system("pause");
			}
			else {
				char studentID[10];
				int studentIndex = -1;

				system("cls");
				printf("Enter student's ID: ");
				fgets(studentID, sizeof(studentID), stdin);
				studentID[strcspn(studentID, "\n")] = '\0';
				rewind(stdin);

				for (int i = 0; i < MAX_STUDENTS; i++) {
					if (strcmp(students[i].studentID, studentID) == 0) {
						studentIndex = i;
						system("cls");
						printf("Student Name: %s\n", students[i].name);
						printf("Student ID: %s\n", students[i].studentID);
						switch (input) {
						case 3:
						case 4:
							if (students[i].numCourses > 0) {
								switch (input) {
								case 3:
									dispGPAs(students[i], 0);
									break;
								case 4:
									dispGPAs(students[i], 1);
								}
								break;
							}
							else {
								printf("\nStudent has no courses registered, you will be redirected to a page to add courses.\n");
								system("pause");
							}
						case 2:
							while (1) {
								enterCourseDetails(&students[i]);
								printf("\nRegister another course? (Y/N): ");
								char confirm = toupper(getchar());
								rewind(stdin);
								while (confirm != 'N' && confirm != 'Y') {
									printf("\033[A\33[2K\rRegister another course? (Y/N): ");
									confirm = toupper(getchar());
									rewind(stdin);
								}
								if (confirm == 'N') break;
							} 
							break;
						}
						break;
					}
				}

				if (studentIndex == -1) {
					system("cls");
					printf("Invalid Student ID, please try again...\n");
					system("pause");
				}
			}
			break;
		case 5:
			return;
		default:
			printf("\033[A\33[2K\r%41s\n", "ERROR: Invalid Option selected...");
			printf("\033[A\033[41C");
			system("pause > NULL");
		}
	}
}

void studentLogin(struct student students[], int* numStudents) {
	if (*numStudents <= 0) {
		system("cls");
		printf("No students in database, please contact your system admin.\n");
		system("pause");
	}
	else {
		char studentID[10];
		int input, studentIndex = -1;

		while (1) {
			system("cls");
			printf("%45s\n", "=========================================");
			printf("%38s\n", "KOLEJ PASAR STUDENTS PORTAL");
			printf("%45s\n\n", "=========================================");
			printf("%28s\n", "1. Login");
			printf("%27s\n\n\n", "2. Back");
			printf("%35s", "Enter your choice => ");
			scanf("%d", &input);
			rewind(stdin);

			switch (input) {
			case 1:
				system("cls");
				printf("%45s\n", "=========================================");
				printf("%38s\n", "KOLEJ PASAR STUDENTS PORTAL");
				printf("%45s\n\n", "=========================================");
				printf("%26s", "Student ID: ");
				fgets(studentID, sizeof(studentID), stdin);
				studentID[strcspn(studentID, "\n")] = '\0';
				rewind(stdin);

				for (int i = 0; i < MAX_STUDENTS; i++) {
					if (strcmp(students[i].studentID, studentID) == 0) {
						studentIndex = i;
						studentMenu(students[i]);
						break;
					}
				}

				if (studentIndex == -1) {
					system("cls");
					printf("Invalid Student ID, please try again...\n");
					system("pause");
				}
				break;
			case 2:
				return;
			default:
				printf("\033[A\33[2K\r%41s\n", "ERROR: Invalid Option selected...");
				printf("\033[A\033[41C");
				system("pause > NULL");
			}
		}
	}
}

void studentMenu(struct student student) {
	while (1) {
		system("cls");
		printf("%45s\n", "=========================================");
		printf("%38s\n", "KOLEJ PASAR STUDENTS PORTAL");
		printf("%45s\n\n", "=========================================");
		printf("%25s %s\n", "Student Name:", student.name);
		printf("%25s %s\n\n", "Student ID:", student.studentID);
		printf("%33s\n", "1. View GPA score");
		printf("%34s\n", "2. View CGPA score");
		printf("%26s\n\n\n", "3. Logout");
		printf("%35s", "Enter your choice => ");
		int input;
		scanf("%d", &input);
		rewind(stdin);

		switch (input) {
		case 1:
		case 2:
			if (student.numCourses > 0) {
				system("cls");
				printf("Name: %s\n", student.name);
				printf("StudentID: %s\n", student.studentID);
				switch (input) {
				case 1:
					dispGPAs(student, 0);
					break;
				case 2:
					dispGPAs(student, 1);
				}
				break;
			}
			else {
				system("cls");
				printf("You currently have no courses registered, please contact your system admin.\n");
				system("pause");
				break;
			}
		case 3:
			return;
		default:
			printf("\033[A\33[2K\r%41s\n", "ERROR: Invalid Option selected...");
			printf("\033[A\033[41C");
			system("pause > NULL");
		}
	}
}

void enterStudentDetails(struct student student[]) {
	system("cls");
	printf("Enter student details:\n\n");

	printf("Student's name (e.g., Tan Ah Kao): ");
	fgets(student->name ,sizeof(student->name), stdin);
	student->name[strcspn(student->name, "\n")] = '\0';

	printf("Student's ID (e.g., KPKL12345): ");
	fgets(student->studentID, sizeof(student->studentID), stdin);
	student->studentID[strcspn(student->studentID, "\n")] = '\0';

	student->numCourses = 0;
}

void enterCourseDetails(struct student student[]) {
	struct course* course = &student->courses[student->numCourses];

	printf("\nCourse code (e.g., AAA1003): ");
	fgets(course->code, sizeof(course->code), stdin);
	course->code[strcspn(course->code, "\n")] = '\0';

	printf("Cedit hours: ");
	scanf("%d", &course->creditHrs);
	rewind(stdin);

	printf("Grade obtained (A, A-, B+, B, B-, C+, C, F): ");
	fgets(course->grade, sizeof(course->grade), stdin);
	course->grade[strcspn(course->grade, "\n")] = '\0';

	while (1) {
		printf("Current semester session (1/2/3): ");
		if (scanf("%d", &course->semester) == 1 && (course->semester >= 1 && course->semester <= 3)) {
			rewind(stdin);
			break;
		}
		else {
			rewind(stdin);
			printf("\033[A\33[2K\r");
		}
	}

	student->numCourses++;
}

void dispGPAs(struct student student, int isCGPA) {
	int semester;

	if (!isCGPA) {
		printf("\n");
		while (1) {	
			printf("GPA for semester (1/2/3): ");
			if (scanf("%d", &semester) == 1 && (semester >= 1 && semester  <= 3)) {
				rewind(stdin);
				break;
			}
			else {
				rewind(stdin);
				printf("\033[A\33[2K\r");
			}
		}
		calcGPAs(student, semester, isCGPA);
	}
	else {
		for (semester = 1; semester <= 3; semester++) {
			calcGPAs(student, semester, 0);
		}

		calcGPAs(student, 0, 1);
	}
	system("pause");
}

void calcGPAs(struct student student,int semester, int isCGPA) {
	float totalQualityPoints = 0.0;
	int totalCreditHrs = 0;

	if (!isCGPA) {
		printf("\nSemester %d\n\n", semester);
	}

	for (int i = 0; i < student.numCourses; i++) {
			if (!isCGPA && student.courses[i].semester != semester) {
				continue;
			}

			int creditHrs = student.courses[i].creditHrs;
			char* grade = student.courses[i].grade;
			float qualityPoints = 0.0;

			if (strcmp(grade, "A") == 0) qualityPoints = 4.0;
			else if (strcmp(grade, "A-") == 0) qualityPoints = 3.75;
			else if (strcmp(grade, "B+") == 0) qualityPoints = 3.5;
			else if (strcmp(grade, "B") == 0) qualityPoints = 3.0;
			else if (strcmp(grade, "B-") == 0) qualityPoints = 2.75;
			else if (strcmp(grade, "C+") == 0) qualityPoints = 2.5;
			else if (strcmp(grade, "C") == 0) qualityPoints = 2.0;

			if (!isCGPA) {
				printf("%d. %s %s %.2f %d\n", i + 1, student.courses[i].code, grade, qualityPoints, creditHrs);
			}

			totalQualityPoints += (qualityPoints * creditHrs);
			totalCreditHrs += creditHrs;
	}

	student.gpa[semester] = totalQualityPoints / totalCreditHrs;

	if (isnan(student.gpa[semester])) {
		printf("No data found...\n");
	}
	else {
		float total = isCGPA ? student.gpa[1] + student.gpa[2] + student.gpa[3] : totalQualityPoints / totalCreditHrs;

		if (isCGPA && (total < 0 || totalCreditHrs < 21)) {
			printf("\nNot eligible for graduation, l");
			printf(total > 0 && totalCreditHrs < 21 ? "minimum of 21 Credit Hours not fulfilled\n" : "minimum of 3 semesters not completed\n");
		}
		else {
			printf("\nTotal Quality Points: %.2f\n", totalQualityPoints);
			printf("Total Credit Hours: %d\n", totalCreditHrs);
			printf(isCGPA ? "CGPA: %.2f\n" : "GPA: %.2f\n", total);
		}
	}
}