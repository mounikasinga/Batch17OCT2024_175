#include <stdio.h>

typedef enum {
    E2F = 1, E2, E3, E4, E5
} Designation;
const char* getDesignationString(Designation designation) {
    switch(designation) {
        case E2F:
		return "Software Fresher";
        case E2: 
		return "Software Engineer";
        case E3: 
		return "Senior Software Engineer";
        case E4: 
		return "Team Lead";
        case E5: 
		return "Senior Team Lead";
        default: 
		return "Unknown Designation";
    }
}
int main() {
    int input;
    printf("Enter the designation (1 for E2F, 2 for E2, 3 for E3, 4 for E4, 5 for E5): ");
    scanf("%d", &input);
    if (input < E2F || input > E5) {
        printf("Invalid input.\n");
        return 1;
    }
    Designation designation = (Designation)input;
    printf("Designation: %d\n", designation);
    printf("Designation String: %s\n", getDesignationString(designation));
    return 0;
}

