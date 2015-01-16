#include <stdio.h>
#include <stdlib.h>

#define MAX 50


void printArray(int arr[], int size) {
	int i;
	for (i=0; i<size; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
}

void merge(int arr[], int begin, int mid, int end) {
	int temp[MAX];
	int i, j, itemp;

	i = begin;
	j = mid + 1;
	itemp = begin;

	while ((i<=mid) && (j<=end)) {			
		if (arr[i] < arr[j]) {
			temp[itemp++] = arr[i++];
		}
		else {
			temp[itemp++] = arr[j++];
		}
	}

	if ((i>mid)) {
		while (j<=end) {
			temp[itemp++] = arr[j++];
		}
	}
	else if (j>end) {
		while (i<=mid) {
			temp[itemp++] = arr[i++];
		}
	}

	//copy temp back to arr
	for (i=begin; i<=end; i++) 
		arr[i] = temp[i];

}


void mergeSort(int arr[], int begin, int end) {
	
	int mid;

	if (begin < end) { 
		mid = (end+begin)/2;
	
		mergeSort(arr, begin, mid);
		mergeSort(arr, mid+1, end);

		merge(arr, begin, mid, end);
	
	}
}


int main(){

	int intArr[] = {88, 34, 56, 79, 102, 534, 46, 90, 1970, 1};

	printArray(intArr, 10); 

	mergeSort(intArr, 0, 9);
	printf("sorting\n");
	printArray(intArr, 10); 

}