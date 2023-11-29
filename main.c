//
//
//
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]) {

  FILE *input_file;
  input_file = fopen(argv[1], "r");

  if (input_file == NULL) {
    perror("Error opening file.\n");
    exit(1);
  }

  int num_processes = 5;
  int num_resources = 3;

  int allocated[5][3];

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

  fclose(input_file);

  int maximum[5][3] = {
    {7, 5, 3}, // Process 0 Maximum
    {3, 2, 2}, // Process 1 Maximum
    {9, 0, 2}, // Process 2 Maximum
    {2, 2, 2}, // Process 3 Maximum
    {4, 3, 3}  // Process 4 Maximum
  };

  int available[3] = {3, 3, 2}; // Resources available
  int f[num_processes];

  for (int i = 0; i < num_processes; ++i) {
    f[i] = 0;
  }

  int need[num_processes][num_resources];

  for (int i = 0; i < num_processes; ++i) {
    for (int j = 0; j < num_resources; ++j) {
      need[i][j] = maximum[i][j] - allocated[i][j];
    }
  }

  int ans[num_processes];
  int ind = 0;
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
          ans[ind++] = i;
          for (int y = 0; y < num_resources; ++y) {
            available[y] += allocated[i][y];
          }
          f[i] = 1;
        }
      }
    }
  }

  int flag = 1;

  for (int i = 0; i < num_processes; ++i) {
    if (f[i] == 0) {
      flag = 0;
      printf("The following system is not safe");
      break;
    }
  }

  if (flag == 1) {
    printf("The following is the safe sequence\n");
    for (int i = 0; i < num_processes - 1; ++i) {
      printf("P%d -> ", ans[i]);
    }
    printf("P%d\n", ans[num_processes - 1]);
  }

  return 0;
}
