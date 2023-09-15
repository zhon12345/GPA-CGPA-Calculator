//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//#pragma warning(disable:4996)
//
//#define MAX_STUDENTS 100
//#define MAX_COURSES 20
//
//struct course {
//	char code[8];
//	int creditHrs;
//	char grade[3];
//	int semester;
//};
//
//struct student {
//	char name[50];
//	char studentID[10];
//	int numCourses;
//	struct course courses[MAX_COURSES];
//};
//
//void staff(struct student students[], int numStudents);
//void enterStudentDetails(struct student student[]);
//void enterCourseDetails(struct student student[]);
//void calcGPAs(struct student student, int isGPA);
//void student(struct student students[]);
//
//void main() {
//	struct student students[MAX_STUDENTS];
//	int input, numSudents = 0;
//
//	while(1) {
//		system("cls");
//		printf("%35s\n", "===============================");
//		printf("%25s\n", "KOLEJ PASAR");
//		printf("%35s\n\n", "===============================");
//		printf("%26s\n", "1. Staff Portal");
//		printf("%28s\n", "2. Student Portal");
//		printf("%18s\n\n\n", "3. Exit");
//		printf("%30s", "Enter your choice => ");
//		scanf("%d", &input);
//        rewind(stdin);
//
//		switch (input) {
//		case 1: staff(students, numSudents); break;
//		case 2: student(students); break;
//		case 3: exit(0); break;
//		default:
//			system("cls");
//			printf("Invalid Option, please try again...\n");
//			system("pause");
//		}
//	}
//	system("pause");
//}
//
//void staff(struct student students[], int numStudents) {
//	int staffInput;
//	while (1) {
//		system("cls");
//		printf("%45s\n", "=========================================");
//		printf("%37s\n", "KOLEJ PASAR ADMINS PORTAL");
//		printf("%45s\n\n", "=========================================");
//		printf("%34s\n", "1. Enter student's details");
//		printf("%41s\n", "2. Enter student's course details");
//		printf("%35s\n", "3. View student's GPA score");
//		printf("%36s\n", "4. View student's CGPA score");
//		printf("%15s\n\n\n", "5. Back");
//		printf("%35s", "Enter your choice => ");
//		scanf("%d", &staffInput);
//		rewind(stdin);
//
//		switch (staffInput) {
//		case 1:
//			if (numStudents < MAX_STUDENTS) {
//				enterStudentDetails(&students[numStudents]);
//
//				printf("\nSuccess!\n");
//				printf("Name: %s\n", students[numStudents].name);
//				printf("StudentID: %s\n", students[numStudents].studentID);
//                system("pause");
//                numStudents++;
//			}
//			else {
//				system("cls");
//				printf("You have reached the max number of students");
//				system("pause");
//			}
//			break;
//		case 2:
//		case 3:
//		case 4:
//			if (numStudents > 0) {
//				char studentID[10];
//
//				system("cls");
//				printf("Enter student's ID: ");
//				fgets(studentID, sizeof(studentID), stdin);
//				studentID[strcspn(studentID, "\n")] = '\0';
//				rewind(stdin);
//
//				for (int i = 0; i < MAX_STUDENTS; i++) {
//					if (strcmp(students[i].studentID, studentID) == 0) {
//						system("cls");
//						printf("Student Found!\n");
//						printf("Student Name: %s\n", students[i].name);
//						printf("Student ID: %s\n", students[i].studentID);
//
//						switch (staffInput) {
//							char confirm;
//						case 3:
//						case 4:
//							if (students[i].numCourses > 0) {
//								switch (staffInput) {
//									case 3:
//										calcGPAs(students[i], 0);
//										break;
//									case 4:
//										calcGPAs(students[i], 1);
//										break;
//								}
//								break;
//							}
//							else {
//								printf("Student has no courses registered, you will be redirected to a page to add courses.\n");
//								rewind(stdin);
//								system("pause");
//							}
//						case 2:
//							do {
//								enterCourseDetails(&students[i]);
//								printf("\nRegister another course? (Y/N): ");
//								confirm = toupper(getchar());
//								rewind(stdin);
//								while (confirm != 'N' && confirm != 'Y') {
//									printf("\033[A\33[2K\rRegister another course? (Y/N):	");
//									confirm = toupper(getchar());
//									rewind(stdin);
//								}
//							} while (confirm != 'N');
//							break;
//						}
//						break;
//					}
//					else {
//						system("cls");
//						printf("Invalid Student ID, please try again...\n");
//						system("pause");
//						break;
//					}
//				}
//				break;
//			}
//			else {
//				system("cls");
//				printf("No students in database, please try again...\n");
//				system("pause");
//			}
//			break;
//		case 5:
//			main();
//			break;
//		default:
//			system("cls");
//			printf("Invalid Option, please try again...\n");
//			system("pause");
//		}
//	}
//}
//
//void enterStudentDetails(struct student student[]) {
//	system("cls");
//	printf("Enter student's name: ");
//	fgets(student->name ,sizeof(student->name), stdin);
//	student->name[strcspn(student->name, "\n")] = '\0';
//
//	printf("Enter student ID (e.g., KPKL12345): ");
//	fgets(student->studentID, sizeof(student->studentID), stdin);
//	student->studentID[strcspn(student->studentID, "\n")] = '\0';
//
//	student->numCourses = 0;
//}
//
//void enterCourseDetails(struct student student[]) {
//	struct course* course = &student->courses[student->numCourses];
//
//	printf("\nCourse code: ");
//	fgets(course->code, sizeof(course->code), stdin);
//	course->code[strcspn(course->code, "\n")] = '\0';
//
//	printf("Cedit hours: ");
//	scanf("%d", &course->creditHrs);
//	rewind(stdin);
//
//	printf("Grade obtained (A, A-, B+, B, B-, C+, C, F): ");
//	fgets(course->grade, sizeof(course->grade), stdin);
//	course->grade[strcspn(course->grade, "\n")] = '\0';
//
//	printf("Current semester session: ");
//	scanf("%d", &course->semester);
//	rewind(stdin);
//
//	student->numCourses++;
//}
//
//void calcGPAs(struct student student, int isCGPA) {
//	float totalQualityPoints = 0.0;
//	int semester, totalCreditHrs = 0;
//
//	if (!isCGPA) {
//		printf("\nCalculate GPA for semester: ");
//		scanf("%d", &semester);
//
//		while (semester < 1 || semester > 3) {
//			printf("Invalid semester, please try again...\n");
//			printf("Calculate GPA for semester: ");
//			scanf("%d", &semester);
//		}
//
//		printf("\nSemester %d\n", semester);
//	}
//	else {
//		semester = 0;
//	}
//
//	for (int i = 0; i < student.numCourses; i++) {
//		if (!isCGPA && student.courses[i].semester != semester) {
//			continue;
//		}
//
//		int creditHrs = student.courses[i].creditHrs;
//		char* grade = student.courses[i].grade;
//		float qualityPoints = 0.0;
//
//		if (strcmp(grade, "A") == 0) qualityPoints = 4.0;
//		else if (strcmp(grade, "A-") == 0) qualityPoints = 3.75;
//		else if (strcmp(grade, "B+") == 0) qualityPoints = 3.5;
//		else if (strcmp(grade, "B") == 0) qualityPoints = 3.0;
//		else if (strcmp(grade, "B-") == 0) qualityPoints = 2.75;
//		else if (strcmp(grade, "C+") == 0) qualityPoints = 2.5;
//		else if (strcmp(grade, "C") == 0) qualityPoints = 2.0;
//
//		printf("%d. %s %s %.2f %d\n", i + 1, student.courses[i].code, grade,qualityPoints, creditHrs);
//
//		totalQualityPoints += (qualityPoints * creditHrs);
//		totalCreditHrs += creditHrs;
//	}
//
//	printf("\nTotal Quality Points: %.2f\n", totalQualityPoints);
//	printf("Total Credit Hours: %d\n", totalCreditHrs);
//	printf(isCGPA ? "CGPA: %.2f\n" : "GPA: %.2f\n", totalQualityPoints / totalCreditHrs);
//	system("pause");
//}
//
//void student(struct student students[]) {
//	char studentID[10];
//	int i;
//
//		system("cls");
//		printf("%39s\n", "===================================");
//		printf("%35s\n", "KOLEJ PASAR STUDENTS PORTAL");
//		printf("%39s\n\n", "===================================");
//		printf("%23s", "Student ID: ");
//		gets(studentID);
//}