#include <stdio.h>
#include <string.h>

// Define a structure to hold student information
struct Student {
    
    char first_name[50], last_name[50];
    int physics_marks, maths_marks, chemistry_marks, english_marks, german_marks, geology_marks;
    
};

int main() {
    // Initialize variables
    int input, i, student_count = 0, total_marks = 0;
    struct Student students[20]; // Array of student structures to hold student data
    char search_name[50], search_name_grade[50];
	double percentage;
	int *ptr1 = &students[student_count].maths_marks, *ptr2 = &students[student_count].physics_marks, *ptr3 = &students[student_count].chemistry_marks, *ptr4 = &students[student_count].english_marks, *ptr5 = &students[student_count].german_marks, *ptr6 = &students[student_count].geology_marks;
	// Display school logo
    printf("  \\_/\n");
    printf("--(_)--  \n");
    printf("  / \\  \n\n\n");
    printf("|____[SCHOOL]______|\n");
    printf("  | [] .-.-. [] |\n");
    printf("..|    _____    |\n");
    printf("..|____|_|_|____|\n");
    printf("..|____|_|_|____|\n\n");
	printf("Welcome to the Student Data Tracker \n");
	printf("1. Display all students\n2. Add Student\n3. Remove Student\n4. Search Student\n5. Overall Grade\n6. Quit\n"); // Display menu options
	printf("Please enter the action number you want to perform : ");
    scanf("%d", &input);
    while (input != 6) { // Process user input until the user chooses to quit
        switch (input) {
            case 1: // Display all students
                if (student_count == 0) {  
                    printf("No students added yet.\n");
                    printf("Please enter students data");
                } else {
                    for (i = 0; i < student_count; ++i) {
                        printf("Student %d:\n", i + 1);
                        printf("First Name: %s\n", students[i].first_name);
                        printf("Last Name: %s\n", students[i].last_name);
                        printf("Maths Marks: %d\n", students[i].maths_marks);
                        printf("Physics Marks: %d\n", students[i].physics_marks);
                        printf("Chemistry Marks: %d\n", students[i].chemistry_marks);
                        printf("English Marks: %d\n", students[i].english_marks);
                        printf("German Marks: %d\n", students[i].german_marks);
                        printf("Geology Marks: %d\n", students[i].geology_marks);
                    }
                }
                break;
            case 2: // Add a new student
                if (student_count < 20) {     
                    printf("Enter student details:\n");
                    printf("First Name: ");
                    scanf("%s", students[student_count].first_name);
                    printf("Last Name: ");
                    scanf("%s", students[student_count].last_name);
                    printf("Maths Marks out of 100: ");
                    scanf("%d", &students[student_count].maths_marks);
                    invalid(&students[student_count].maths_marks);
                    printf("Physics Marks out of 100: ");
                    scanf("%d", &students[student_count].physics_marks);
                    invalid(&students[student_count].physics_marks);
                    printf("Chemistry Marks out of 100: ");
                    scanf("%d", &students[student_count].chemistry_marks);
                    invalid(&students[student_count].chemistry_marks);
                    printf("English Marks out of 100: ");
                    scanf("%d", &students[student_count].english_marks);
                    invalid(&students[student_count].english_marks);
                    printf("German Marks out of 100: ");
                    scanf("%d", &students[student_count].german_marks);
                    invalid(&students[student_count].german_marks);
                    printf("Geology Marks out of 100: ");
                    scanf("%d", &students[student_count].geology_marks);
                    invalid(&students[student_count].geology_marks);
                    student_count++;
                } else {
                    printf("Maximum number of students reached.\n");
                }
                break;
            case 3:   // Remove a student
            if (student_count > 0) {
                    int remove_index;
                    printf("Enter index of student to remove (1-%d): ", student_count);
                    scanf("%d", &remove_index);
                    if (remove_index >= 1 && remove_index <= student_count) {
                        // Shift elements to fill the gap
                        for (i = remove_index - 1; i < student_count - 1; ++i) {
                            students[i] = students[i + 1];
                        }
                        student_count--;
                        printf("Student removed successfully.\n");
                    } else {
                        printf("Invalid index.\n");
                    }
                } else {
                    printf("No students to remove.\n");
                }
                break;
            case 4:   // Search for a student by first name
            printf("Enter the First Name of the Student: ");
                scanf("%s", search_name);
                for (i = 0; i < student_count; ++i) {
                    if (strcmp(students[i].first_name, search_name) == 0) {
                        printf("Student found:\n");
                        printf("First Name: %s\n", students[i].first_name);
                        printf("Last Name: %s\n", students[i].last_name);
                        printf("Maths Marks: %d\n", students[i].maths_marks);
                        printf("Physics Marks: %d\n", students[i].physics_marks);
                        printf("Chemistry Marks: %d\n", students[i].chemistry_marks);
                        printf("English Marks: %d\n", students[i].english_marks);
                        printf("German Marks: %d\n", students[i].german_marks);
                        printf("Geology Marks: %d\n", students[i].geology_marks);
                        break;
                    }
                }
                if (i == student_count) {
                    printf("Student not found.\n");
                }
                break;
            case 5:   // Calculate overall grade for a student
            printf("Enter the First Name of the Student: ");
                scanf("%s", search_name_grade);
                for (i = 0; i < student_count; ++i) {
                    if (strcmp(students[i].first_name, search_name_grade) == 0) {
                        printf("Student found:\n");  // Calculate total marks
                        total_marks = students[i].maths_marks + students[i].physics_marks + students[i].chemistry_marks + 
                                      students[i].english_marks + students[i].german_marks + students[i].geology_marks;
                        // Calculate percentage
                        percentage = (double)total_marks / 600.0 * 100.0;
                        printf("Total Marks: %d\n", total_marks);
                        printf("Percentage: %.2f%%\n", percentage);
                        // Determine grade
                        if (percentage >= 90.0) {
                            printf("Grade: A\n");
                        } else if (percentage >= 80.0) {
                            printf("Grade: B\n");
                        } else if (percentage >= 70.0) {
                            printf("Grade: C\n");
                        } else if (percentage >= 60.0) {
                            printf("Grade: D\n");
                        } else {
                            printf("Grade: F\n");
                        }
                        break;
                    }
                }
                if (i == student_count) {
                    printf("Student not found.\n");
                }
                break;
        }
        
        printf("\n1. Display all students\n2. Add Student\n3. Remove Student\n4. Search Student\n5. Overall Grade\n6. Quit\n");
        scanf("%d", &input);
    }

    return 0;
}

int invalid(int *number){
	while (*number > 100) {
        
        

        // Input the number again
        printf("Invalid Input: \n");
        printf("Please enter again : ");
        scanf("%d", number);
    }
}

