// Workshop 9 - Multi-Threading, Thread Class
// process_data.h
// 2021/1/5 - Jeevan Pant
// 2023/11/17 - Cornel

#ifndef SDDS_PROCESSDATA_H
#define SDDS_PROCESSDATA_H

#include<string>

namespace sdds {
	void computeAvgFactor(const int* arr, int size, int divisor, double& avg);
	void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var);

	class ProcessData {
		int total_items{};
		int* data{};
	public:
		ProcessData(const std::string& input_file);
		ProcessData(const ProcessData&) = delete;
		ProcessData& operator=(const ProcessData&) = delete;
		~ProcessData();
		operator bool() const;
		int operator()(const std::string& target_file, double& avg, double& var);
	};
}

#endif