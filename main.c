//
//
//
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[]) {

  FILE* input_file;                  // Create pointer to input file
  input_file = fopen(argv[1], "r");  // Open file from argv[1]

  if (input_file == NULL) {
    perror("Error opening file.\n");  // Print error if problem opening file
    exit(1);                          // Exit with error
  }

  int num_processes = 5;  // Number of processes as defined in assignment.
  int num_resources = 3;  // Number of resources as defined in assignment.
  int allocated[5][3];    // 2D array that holds allocated resources, 1st
                          // dimension is number of processes and 2nd dimension
                          // is number of resources.

  // This nested for loop reads in the integers from the text file and inserts
  // them into the 2D array.
  // It prints an error if there's an issue reading them.
  for (int i = 0; i < num_processes; ++i) {
    for (int j = 0; j < num_resources; ++j) {
      if (fscanf(input_file, "%d", &allocated[i][j]) != 1) {
        fprintf(stderr,
                "Error reading integers from text file. i = %d, j = %d\n", i,
                j);
        fclose(input_file);
        exit(1);
      }
    }
  }

  fclose(input_file);  // Close the file once reading is done.

  int maximum[5][3] = {
      // Maximum resource 2D array.
      {7, 5, 3},  // Process 0 Maximum
      {3, 2, 2},  // Process 1 Maximum
      {9, 0, 2},  // Process 2 Maximum
      {2, 2, 2},  // Process 3 Maximum
      {4, 3, 3}   // Process 4 Maximum
  };

  int available[3] = {3, 3, 2};  // Resources available
  int f[num_processes];

  for (int i = 0; i < num_processes; ++i) {
    f[i] = 0;
  }

  int need[num_processes][num_resources];

  // This nested loop fills the 2D array called need by subtracting the maximum
  // array from the allocated array.
  for (int i = 0; i < num_processes; ++i) {
    for (int j = 0; j < num_resources; ++j) {
      need[i][j] = maximum[i][j] - allocated[i][j];
    }
  }

  int correct[num_processes];  // Array that holds the correct process order.
  int index = 0;               // Index integer.

  // This nested loop flags a process if it's need is greater than the reaources
  // that are available.
  for (int k = 0; k < 5; ++k) {
    for (int i = 0; i < num_processes; ++i) {
      if (f[i] == 0) {
        int flag = 0;
        for (int j = 0; j < num_resources; ++j) {
          if (need[i][j] > available[j]) {
            flag = 1;
            break;
          }
        }

        if (flag == 0) {
          correct[index++] = i;
          for (int y = 0; y < num_resources; ++y) {
            available[y] += allocated[i][y];
          }
          f[i] = 1;
        }
      }
    }
  }

  int flag = 1;  // Set flag to equal 1 indicating a safe state

  for (int i = 0; i < num_processes; ++i) {
    if (f[i] == 0) {
      flag = 0;
      printf("The system is not in a safe state.");
      break;
    }
  }

  if (flag == 1) {  // Display correct safe sequence
    printf("The following is the safe sequence\n");
    for (int i = 0; i < num_processes - 1; ++i) {
      printf("P%d -> ", correct[i]);
    }
    printf("P%d\n", correct[num_processes - 1]);
  }

  return 0;
}
