#include <iostream>
#include <vector>

using namespace std;

#define newline cout << "\n"

void merge(vector<int> &arr, int l, int m, int r) {
    int s1 = m - l + 1;
    int s2 = r - m;
    
    if (s1 <= 0 || s2 <= 0) {
        return;
    }

    int* L = new int[s1];
    int* R = new int[s2];
    
    for (int i = 0; i < s1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < s2; j++) {
        R[j] = arr[m + 1 + j]; 
    }

    int i = 0, j = 0, k = l;

    while (i < s1 && j < s2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < s1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < s2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergesort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        mergesort(arr, l, m);

        mergesort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int binary(vector<int>& arr, int target) {
    int n = arr.size();
    mergesort(arr, 0, n - 1);


    cout << "Sorted array:" << endl;
    
    vector<int> outArr;

    for(int i = 0; i < n; i++) {
        outArr.push_back(arr[i]);
        cout << outArr[i] << ", ";
    }

    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // calculate the middle index

        if (arr[mid] == target) { // check if middle element is the target
            return mid; // return the index of the target
        } else if (arr[mid] > target) { // search the left half
            right = mid - 1;
        } else { // search the right half
            left = mid + 1;
        }
    }

    return -1; // target not found
}


int main() {
    vector<int> arr =
{
52, 23, 71, 59, 17, 50, 72, 36, 67, 72, 85, 34, 30, 23, 97, 53, 58, 76, 52, 12, 13, 83, 38, 1, 27, 27, 35, 38, 68, 62, 14, 52, 78, 18, 4, 45, 5, 3, 25, 49, 100, 12, 61, 15, 5, 88, 64, 33, 43, 94, 90, 83, 51, 47, 4, 47, 6, 9, 52, 31, 93, 0, 17, 50, 8, 97, 80, 14, 33, 45, 44, 37, 75, 17, 5, 77, 17, 17, 50, 91, 76, 79, 39, 46, 17, 14, 74, 46, 64, 2, 28, 97, 17, 60, 31, 44, 17, 55, 55, 99, 54, 5, 46, 55, 54, 34, 51, 73, 94, 80, 52, 41, 19, 52, 49, 37, 89, 22, 93, 86, 89, 12, 38, 19, 2, 80, 55, 18, 26, 11, 73, 20, 7, 51, 86, 28, 68, 98, 86, 56, 4, 34, 76, 66, 34, 47, 25, 44, 58, 93, 21, 32, 14, 99, 70, 3, 52, 57, 67, 37, 92, 16, 88, 96, 59, 3, 83, 9, 78, 50, 13, 24, 9, 25, 98, 35, 89, 24, 79, 52, 11, 30, 53, 45, 20, 33, 9, 85, 82, 3, 27, 68, 91, 79, 70, 95, 35, 14, 5, 46, 96, 61, 80, 80, 65, 29, 44, 68, 40, 80, 42, 83, 11, 21, 92, 2, 86, 25, 74, 64, 79, 69, 88, 30, 51, 55, 3, 44, 12, 89, 60, 3, 25, 6, 59, 63, 70, 18, 98, 78, 81, 63, 29, 11, 59, 65, 12, 51, 74, 50, 58, 14, 5, 52, 66, 92, 17, 51, 26, 80, 68, 18, 25, 98, 89, 92, 32, 49, 76, 26, 95, 58, 63, 84, 43, 61, 41, 95, 22, 12, 21, 10, 1, 60, 2, 99, 17, 88, 57, 6, 47, 52, 46, 77, 5, 7, 4, 12, 1, 71, }; 

    

    //int n = arr.size();

    //mergesort(arr, 0, n - 1);

    //cout << "Sorted array:" << endl;
    
    //vector<int> outArr;

    //for(int i = 0; i < n; i++) {
    //    outArr.push_back(arr[i]);
    //    cout << outArr[i] << " ";
    //}
    //
    //
    cout << "input the number you would like to search :";
    int targ;
    cin >> targ;
    int non = binary(arr, targ);
    
    if (non == -1) {
        cout << "\nthe number :" << targ << " was not found";
    } else {
        cout << "\nthe number :" << targ << " was found at index :" << non;
    }

    return 0;
}
