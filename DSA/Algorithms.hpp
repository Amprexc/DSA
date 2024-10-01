#pragma once
#include <vector>


class Algorithms {
public:
	void static BubbleSort(int array[], int size) {
		for (int i = size - 1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (array[j] > array[j + 1]) {
					std::cout << "Swaping: " << array[j] << " " << array[j + 1] << std::endl;
					int temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
				else {
					std::cout << "Not swaping: " << array[j] << " " << array[j + 1] << std::endl;
				}
			}
		}
	}

	void static SelectionSort(int array[], int size) {
		for (int i = 0; i < size; i++) {
			int minIndex = i;
			for (int j = i+1; j < size; j++) {
				if (array[j] < array[minIndex]) {
					minIndex = j;
				}
				if (i != minIndex) {
					int temp = array[i];
					array[i] = array[minIndex];
					array[minIndex] = temp;
				}
				
			}
		}
	}

	void static InsertionSort(int array[], int size) {
		for (int i = 1; i < size; i++) {
			int temp = array[i];
			int j = i - 1;
			while (j > -1 && temp < array[j]) {
				array[j + 1] = array[j];
				array[j] = temp;
				j--;
			}
		}
	}
};