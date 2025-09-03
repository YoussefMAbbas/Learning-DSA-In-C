#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE (size_t)25

void InsertionSortStringAZ(int start, int end, char list[][MAX_NAME_SIZE]);
void InsertionSortStringZA(int start, int end, char list[][MAX_NAME_SIZE]);

int main(void) {
  char names[][MAX_NAME_SIZE] = {
      "Tarry A. Davis",       "Tzrry A. Davis", "Youssef Mohamed",
      "Richard W. Stalleman", "Ahmed Mohamed",  "Terry A. Davis",
  };

  int size = sizeof(names) / sizeof(names[0]);

  printf("Unsorted: ");
  for (int i = 0; i < size; i++) {
    printf("%s%s", names[i], (i == size - 1) ? "" : ", ");
  }

  printf("\n");
  printf("\n");

  InsertionSortStringAZ(0, size, names);
  printf("A-Z Order: ");
  for (int i = 0; i < size; i++) {
    printf("%s%s", names[i], (i == size - 1) ? "" : ", ");
  }

  printf("\n");
  printf("\n");

  InsertionSortStringZA(0, size, names);
  printf("Z-A Order: ");
  for (int i = 0; i < size; i++) {
    printf("%s%s", names[i], (i == size - 1) ? "" : ", ");
  }

  printf("\n");
  printf("\n");

  return EXIT_SUCCESS;
}

void InsertionSortStringAZ(int start, int end, char list[][MAX_NAME_SIZE]) {

  for (int i = start + 1; i < end; i++) {

    char key[MAX_NAME_SIZE];

    memmove(key, list[i], MAX_NAME_SIZE);
    int prevIndex = i - 1;

    while (prevIndex >= start && strcmp(key, list[prevIndex]) < 0) {
      memmove(list[prevIndex + 1], list[prevIndex], MAX_NAME_SIZE);
      memmove(list[prevIndex], key, MAX_NAME_SIZE);
      --prevIndex;
    }
    memmove(list[prevIndex + 1], key, MAX_NAME_SIZE);
  }
}

void InsertionSortStringZA(int start, int end, char list[][MAX_NAME_SIZE]) {

  for (int i = start + 1; i < end; i++) {

    char key[MAX_NAME_SIZE];

    memmove(key, list[i], MAX_NAME_SIZE);
    int prevIndex = i - 1;

    while (prevIndex >= start &&
           strncmp(key, list[prevIndex], MAX_NAME_SIZE) > 0) {
      memmove(list[prevIndex + 1], list[prevIndex], MAX_NAME_SIZE);
      memmove(list[prevIndex], key, MAX_NAME_SIZE);
      --prevIndex;
    }
    memmove(list[prevIndex + 1], key, MAX_NAME_SIZE);
  }
}
