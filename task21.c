#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for an n*n matrix
int** createMatrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    
    return matrix;
}

// Function to input values into an n*n matrix
void inputMatrix(int** matrix, int n) {
    printf("Enter the elements of the matrix at possition:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("[%d][%d] -> ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}
// Auto generates matrix n*n
void autoGenerateMatrix(int** matrix, int n) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand()%10;
        }
    }
}

// Function to display an n*n matrix
void displayMatrix(int** matrix, int n) {
    printf("Your Matrix is:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the memory allocated for an n*n matrix
void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to count zero diagonals

int countZeroDiagonals(int** matrix, int n){
    int size = n-1;
    int curr = 1;
    int counter;
   
    
    while (size >=curr)
    {
        int flag1 = 0;
        int flag2 = 0;
        for (int i = 0; i < size; i++)
        {
            if (matrix[i+curr][i] == 0){
                flag1 = 1;
            }
            if (matrix[i][i+curr] == 0)
            {
                flag2 =1;
            }
            
        }
        curr+=1;
        size -= 1;
        if (flag1)
        {
            counter += 1;
        }
        if (flag2)
        {
            counter += 1;
        }
        
    }
    return counter;
    
}


int main() {
    int option;
    int n;
    int res;


   // Validate the matrix size 
    while (n != EOF)
    {

        printf("Enter the size of the matrix\nEnter CTRL + C to exit the program\n-> ");
        scanf("%d", &n);
        
       if (n <= 0) {
            printf("Invalid matrix size. Please enter a positive integer.\n");
            continue; 
        
        }else{
            break;
        }
    }
    
   
     // Create an n*n matrix
    int** matrix = createMatrix(n);
    

    // Validate the options
    while (option != EOF)
    {
        printf("Enter 1 for auto generated matrix with numbers from 0 to 9.\nEnter 2 to enter the matrix manually.\nEnter CTRL + C to exit the program \n-> ");
        scanf("%d", &option);
        if ((option == 1) || (option == 2))
        {
           break;
        
        }else{
             printf("Invalid input. Please enter 1 or 2.\n");
            continue; 
        }
        
    }
   

    switch (option)
    {
    case 1:


        // Auto generate matrix
        autoGenerateMatrix(matrix, n);

        // Display the matrix
        displayMatrix(matrix, n);

        // Count zero diagonals
        res = countZeroDiagonals(matrix,n);
        printf("Count diagonals with zero vlues is %d .", res);

        // Free the memory allocated for the matrix
        freeMatrix(matrix, n);
   
        break;

    case 2:

        // Input values into the matrix
        inputMatrix(matrix, n);

        // Display the matrix
        displayMatrix(matrix, n);

        // Count zero diagonals
        res = countZeroDiagonals(matrix,n);
        printf("Count diagonals with zero vlues is %d.", res);
        
        // Free the memory allocated for the matrix
        freeMatrix(matrix, n);
   

        break;
    
    default:
        break;
    }

    return 0; 
}
