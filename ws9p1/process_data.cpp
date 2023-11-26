// Workshop 9 - Multi-Threading, Thread Class
// process_data.cpp
// 2021/1/5 - Jeevan Pant
// 2023/11/17 - Cornel

#include <string>
#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
#include <thread>
#include "process_data.h"

namespace sdds
{
	// The following function receives array (pointer) as the first argument, number of array
	//   elements (size) as second argument, divisor as the third argument, and avg as fourth argument.
	//   size and divisor are not necessarily same. When size and divisor hold same value, avg will
	//   hold average of the array elements. When they are different, avg will hold a value called
	// 	 as average-factor. For part 1, you will be using same value for size and double. Use of
	//   different values for size and divisor will be useful for multi-threaded implementation in part-2.
	void computeAvgFactor(const int* arr, int size, int divisor, double& avg) {
		avg = 0;
		for (int i = 0; i < size; i++) {
			avg += arr[i];
		}
		avg /= divisor;
	}

	// The following function receives array (pointer) as the first argument, number of array elements
	//   (size) as second argument, divisor as the third argument, computed average value of the data items
	//   as fourth argument, and var as fifth argument. Size and divisor are not necessarily same as in the
	//   case of computeAvgFactor. When size and divisor hold same value, var will get total variance of
	//   the array elements. When they are different, var will hold a value called as variance factor.
	//   For part 1, you will be using same value for size and double. Use of different values for size
	//   and divisor will be useful for multi-threaded implementation in part-2.
	void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var) {
		var = 0;
		for (int i = 0; i < size; i++) {
			var += (arr[i] - avg) * (arr[i] - avg);
		}
		var /= divisor;
	}

	// The following constructor of the functor receives name of the data file, opens it in
	//   binary mode for reading, reads first int data as total_items, allocate memory space
	//   to hold the data items, and reads the data items into the allocated memory space.
	//   It prints first five data items and the last three data items as data samples.
	//   
	ProcessData::ProcessData(const std::string& filename) {
		// TODO: Open the file whose name was received as parameter and read the content
		//         into variables "total_items" and "data". Don't forget to allocate
		//         memory for "data".
		//       The file is binary and has the format described in the specs.

		std::fstream file{};
		file.open(filename, std::ios_base::in | std::ios_base::binary);
		if (!file) {
			std::cerr << "Error: Unable to open file " << filename << std::endl;
			return;
		}
		file.read(reinterpret_cast<char*>(&total_items), sizeof(total_items));
		data = new int[total_items]; // Allocate memory for "data"
		file.read(reinterpret_cast<char*>(data), sizeof(total_items) * total_items);

		std::cout << "Item's count in file '" << filename << "': " << total_items << std::endl;
		std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
			<< data[total_items - 3] << ", " << data[total_items - 2] << ", "
			<< data[total_items - 1] << "]" << std::endl;
	}

	ProcessData::~ProcessData() {
		delete[] data;
	}

	ProcessData::operator bool() const {
		return total_items > 0 && data != nullptr;
	}

	// TODO You create implementation of function operator(). See workshop instructions for details.
	int ProcessData::operator()(const std::string& target_file, double& avg, double& var)
	{
		computeAvgFactor(data, total_items, total_items, avg);
		computeVarFactor(data, total_items, total_items, avg, var);
		// Open the file in binary mode
		std::ofstream oFile(target_file, std::ios::binary);
		if (!oFile) {
			std::cerr << "Error: Unable to open file " << target_file << " for writing" << std::endl;
			throw std::runtime_error("Unable to open the target file for writing.");
		}
		oFile.write(reinterpret_cast<const char*>(&total_items), sizeof(int));
		// Writing "data" to the "target_file"
		oFile.write(reinterpret_cast<const char*>(data), total_items * sizeof(int));
		return 0;
	}




}