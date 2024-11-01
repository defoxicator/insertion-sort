#include<iostream>

// Main insertion sort function
void insertion_sort(int* array, int array_size) {
	for (int i = 1; i < array_size; i++) {
		for (int j = i; j > 0; j--) {
			if (array[j] < array[j - 1]) {
				int temp{ array[j] };
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
			else {
				break;
			}
		}
	}
}

void show_array(int* array, int array_size, char input_output) {
	switch (input_output) {
	case 'i': // input
		std::cout << "\nZadeklarowana: [";
		break;
	case 'o': // output
		std::cout << "\nPosortowana: [";
		break;
	}
	
	for (int i = 0; i < array_size - 1; i++) {
		std::cout << array[i] << ", ";
	}
	std::cout << array[array_size - 1] << "]\n";
}

int main() {
	int array_size{};
	std::cout << "Input size of the array.\n> ";
	std::cin >> array_size;

	int* array = new int[array_size];

	// Pseudorandom fill for array
	srand(time(NULL));
	for (int i = 0; i < array_size; i++) {
		array[i] = rand();
	}

	show_array(array, array_size, 'i');

	insertion_sort(array, array_size);

	show_array(array, array_size, 'o');

	delete[] array;
	return 0;
}
