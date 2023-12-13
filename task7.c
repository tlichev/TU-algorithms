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

// Function to check if the sequence is monotonically decreasing
int monotonicallyDecreasing(int *sequence, int sizeOfSequence, char type){
    switch (type)
    {
    case 'D':
        for (int i = 0; i < sizeOfSequence-2; i+=2)
        {
            if (sequence[i] > sequence[i+2])
            {
                continue;
            }else{
                return 0;
            }
            
        }
        return 1;
        break;
    case 'I':
        for (int i = 1; i < sizeOfSequence-2; i+=2)
        {
            if (sequence[i] > sequence[i+2])
            {
                continue;
            }else{
                return 0;
            }
            
        }
        return 1;
        break;
    
    default:
        break;
    }
    for (int i = 0; i < sizeOfSequence-2; i+=2)
    {
        if (sequence[i] < sequence[i+2])
        {
            continue;
        }else{
            return 0;
        }
        
    }
    return 1;
    
    
}


// Function to check if the sequence is monotonically increasing
int monotonicallyIncreasing(int *sequence, int sizeOfSequence, char type){
    switch (type)
    {
    case 'D':
        for (int i = 1; i < sizeOfSequence-2; i+=2)
        {
            if (sequence[i] < sequence[i+2])
            {
                continue;
            }else{
                return 0;
            }
            
        }
        return 1;
        break;
    case 'I':
        for (int i = 0; i < sizeOfSequence-2; i+=2)
        {
            if (sequence[i] < sequence[i+2])
            {
                continue;
            }else{
                return 0;
            }
            
        }
        return 1;
        break;
    
    default:
        break;
    }
    for (int i = 0; i < sizeOfSequence-2; i+=2)
    {
        if (sequence[i] < sequence[i+2])
        {
            continue;
        }else{
            return 0;
        }
        
    }
    return 1;
    
}

// Function to check if the sequence is sawtooth
int isSawtooth(int* sequence, int sizeOfSequence, char type){

    switch (type)
    {
    case 'D':
        for (int  i = 0; i < sizeOfSequence-1; i++)
            {
                if (i%2 == 0)
                {
                    if (sequence[i] > sequence[i+1]){
                        continue;

                    }else{
                        return 0 ;
                    }
                }else{
                    if (sequence[i] < sequence[i+1]){
                        continue;
                    }else{
                        return 0 ;
                    }
                }
                
            }
            return 1;
        break;
    case 'I':
            for (int  i = 0; i < sizeOfSequence-1; i++)
            {
                if (i%2 == 0)
                {
                    if (sequence[i] < sequence[i+1]){
                        continue;

                    }else{
                        return 0 ;
                    }
                }else{
                    if (sequence[i] > sequence[i+1]){
                        continue;
                    }else{
                        return 0 ;
                    }
                }
                
            }
    
            return 1;
        break;
    
    default:
        break;
    }

}

// Function that iterates the matrix in a spiral and returns a pointer to an array
int* spiralTraversal(int** matrix, int n){
    int sizeOfSequence = (n*n);
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;
   
    int index = 0;
    int* sequence = (int*)malloc(sizeOfSequence * sizeof(int*));
    
    while (top <= bottom && left <= right)
    {
        for (int i = left; i < right+1; i++)
        {
            sequence[index] = matrix[top][i];
            index ++;
        }
        top++;

         for (int i = top; i < bottom+1; i++)
        {
            sequence[index] = matrix[i][right];
            index ++;
        }
        right--;

        for (int i = right; i > left -1; i--)
        {
            sequence[index] = matrix[bottom][i];
            index ++;
        }
        bottom--;

        for (int i = bottom; i > top -1; i--)
        {
            sequence[index] = matrix[i][left];
            index ++;
        }
        left++;

        
    }
    return sequence; 
    
}

int main() {
    int option;
    int n;
    int* sequence;
    char type;
  

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
        break;

    case 2:
        // Input values into the matrix
        inputMatrix(matrix, n);


    default:
        break;
    }


        // Display the matrix
        displayMatrix(matrix, n);

        // Create sequence with values of the matrix
        sequence = spiralTraversal(matrix, n);

        // Free the memory allocated for the matrix
        freeMatrix(matrix, n);
        
        
        if (sequence[0] > sequence[1])
        {
            type = 'D'; // first decreasing then increasing
        }else{
            type = 'I';// first icreasing then decreasing
        }


        if (isSawtooth(sequence, n*n, type) && monotonicallyDecreasing(sequence, n*n, type) && monotonicallyIncreasing(sequence, n*n, type))
        {
            printf("Yes sequence is sawtooth and it is monotonically decreasing and monotonically Increasing");
        }else
        {
            printf("No sequence is not sawtooth");
        }


        // Free the memory allocated for the sequence
        free(sequence);
        
    
    return 0; 
}