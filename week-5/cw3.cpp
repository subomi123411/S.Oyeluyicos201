#include <iostream>
using namespace std;

// Function prototype
void merge(const int list1[], int size1, const int list2[], int size2, int list3[]);
void printArray(const int arr[], int size);

int main() {
    // Test case 1: Example from the problem
    int list1[] = {2, 3, 8, 10};
    int list2[] = {1, 7, 9, 11, 13};
    int size1 = sizeof(list1) / sizeof(list1[0]);
    int size2 = sizeof(list2) / sizeof(list2[0]);
    int list3[size1 + size2];
    
    cout << "Test Case 1:" << endl;
    cout << "List 1: ";
    printArray(list1, size1);
    cout << "List 2: ";
    printArray(list2, size2);
    
    merge(list1, size1, list2, size2, list3);
    
    cout << "Merged List: ";
    printArray(list3, size1 + size2);
    cout << endl;
    
    // Test case 2: Lists of equal size
    int list4[] = {1, 3, 5, 7, 9};
    int list5[] = {2, 4, 6, 8, 10};
    int size4 = sizeof(list4) / sizeof(list4[0]);
    int size5 = sizeof(list5) / sizeof(list5[0]);
    int list6[size4 + size5];
    
    cout << "Test Case 2:" << endl;
    cout << "List 1: ";
    printArray(list4, size4);
    cout << "List 2: ";
    printArray(list5, size5);
    
    merge(list4, size4, list5, size5, list6);
    
    cout << "Merged List: ";
    printArray(list6, size4 + size5);
    cout << endl;
    
    // Test case 3: One empty list
    int list7[] = {};
    int list8[] = {1, 2, 3};
    int size7 = 0;
    int size8 = sizeof(list8) / sizeof(list8[0]);
    int list9[size7 + size8];
    
    cout << "Test Case 3 (One empty list):" << endl;
    cout << "List 1: ";
    printArray(list7, size7);
    cout << "List 2: ";
    printArray(list8, size8);
    
    merge(list7, size7, list8, size8, list9);
    
    cout << "Merged List: ";
    printArray(list9, size7 + size8);
    cout << endl;
    
    // Test case 4: Duplicate elements
    int list10[] = {1, 2, 2, 3, 4};
    int list11[] = {2, 3, 5, 5, 6};
    int size10 = sizeof(list10) / sizeof(list10[0]);
    int size11 = sizeof(list11) / sizeof(list11[0]);
    int list12[size10 + size11];
    
    cout << "Test Case 4 (With duplicates):" << endl;
    cout << "List 1: ";
    printArray(list10, size10);
    cout << "List 2: ";
    printArray(list11, size11);
    
    merge(list10, size10, list11, size11, list12);
    
    cout << "Merged List: ";
    printArray(list12, size10 + size11);
    
    return 0;
}

// Function to merge two sorted arrays into a third sorted array
void merge(const int list1[], int size1, const int list2[], int size2, int list3[]) {
    int i = 0;  // Index for list1
    int j = 0;  // Index for list2
    int k = 0;  // Index for list3
    
    // Merge elements from both lists while both have elements
    while (i < size1 && j < size2) {
        if (list1[i] <= list2[j]) {
            list3[k] = list1[i];
            i++;
        } else {
            list3[k] = list2[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements from list1, if any
    while (i < size1) {
        list3[k] = list1[i];
        i++;
        k++;
    }
    
    // Copy remaining elements from list2, if any
    while (j < size2) {
        list3[k] = list2[j];
        j++;
        k++;
    }
}

// Function to print an array
void printArray(const int arr[], int size) {
    if (size == 0) {
        cout << "[]" << endl;
        return;
    }
    
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

/*#include <iostream>
using namespace std;

// Function to merge two sorted arrays
void merge(const int list1[], int size1, const int list2[], int size2, int list3[]) {
    // Initialize pointers for all three arrays
    int p1 = 0;  // Pointer for list1
    int p2 = 0;  // Pointer for list2
    int p3 = 0;  // Pointer for list3 (result)
    
    // Traverse both arrays simultaneously
    // Continue until we reach the end of either array
    while (p1 < size1 && p2 < size2) {
        // Compare current elements of both arrays
        // Take the smaller element and add it to result
        if (list1[p1] < list2[p2]) {
            list3[p3++] = list1[p1++];
        } else {
            // If list2[p2] <= list1[p1], take from list2
            // This also handles equal elements
            list3[p3++] = list2[p2++];
        }
    }
    
    // At this point, one array is exhausted
    // Copy any remaining elements from list1 (if any)
    while (p1 < size1) {
        list3[p3++] = list1[p1++];
    }
    
    // Copy any remaining elements from list2 (if any)
    while (p2 < size2) {
        list3[p3++] = list2[p2++];
    }
}

int main() {
    // Example from the problem
    int arr1[] = {2, 3, 8, 10};
    int arr2[] = {1, 7, 9, 11, 13};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int merged[n1 + n2];
    
    // Merge the arrays
    merge(arr1, n1, arr2, n2, merged);
    
    // Display results
    cout << "First sorted array: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    cout << "Second sorted array: ";
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    cout << "Merged sorted array: ";
    for (int i = 0; i < n1 + n2; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;
    
    return 0;
}
*/