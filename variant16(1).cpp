/******************************
 * Автор:   Михайлов Даниил   *
 * Задание: Обработка массивов*
 * Вариант: 16                *
 *****************************/

#include <iostream>

using namespace std;

int main() {
  const int maxSize = 20;
  const int maxMagnitude = 1000;

  int matrix[maxSize][maxSize];
  int rowCount;
  int columnCount;
  int repeatedList[maxSize * maxSize];
  int repeatedCount;
  int sameCount;
  bool hasRepeated;
  int maxRepeated;

  // Input block
  cout << "Enter row count and column count: ";
  cin >> rowCount >> columnCount;
  if (rowCount < 1 || rowCount > maxSize ||
      columnCount < 1 || columnCount > maxSize) {
    cout << "Invalid size";
    return 1;
  }

  cout << "Enter matrix elements: ";
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      cin >> matrix[rowIndex][columnIndex];
      if (matrix[rowIndex][columnIndex] < -maxMagnitude ||
          matrix[rowIndex][columnIndex] > maxMagnitude) {
        cout << "Invalid element";
        return 1;
      }
    }
  }

  // Calculation block
  repeatedCount = 0;
  hasRepeated = false;
  maxRepeated = 0;
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      // Count how many elements are equal to the current one
      sameCount = 0;
      for (int otherRowIndex = 0; otherRowIndex < rowCount; ++otherRowIndex) {
        for (int otherColumnIndex = 0; otherColumnIndex < columnCount;
            ++otherColumnIndex) {
          if (matrix[otherRowIndex][otherColumnIndex] ==
              matrix[rowIndex][columnIndex]) {
            ++sameCount;
          }
        }
      }

      // The element itself is counted too, so more than one means a repeat
      if (sameCount > 1) {
        repeatedList[repeatedCount] = matrix[rowIndex][columnIndex];
        ++repeatedCount;
        // Maximum cannot start from 0, because all numbers may be negative
        if (!hasRepeated || matrix[rowIndex][columnIndex] > maxRepeated) {
          maxRepeated = matrix[rowIndex][columnIndex];
          hasRepeated = true;
        }
      }
    }
  }

  // Output block
  cout << "Matrix:" << endl;
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      cout << matrix[rowIndex][columnIndex] << " ";
    }
    cout << endl;
  }

  cout << "Repeated elements:";
  if (hasRepeated) {
    for (int listIndex = 0; listIndex < repeatedCount; ++listIndex) {
      cout << " " << repeatedList[listIndex];
    }
    cout << endl << "Max repeated element: " << maxRepeated;
  } else {
    cout << " none" << endl << "Max repeated element: none";
  }
  return 0;
}
