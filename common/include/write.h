#pragma once
#include <string>
#include <fstream>
#include <filesystem>

constexpr char NULLBYTE = 0;

namespace adrianllm
{
	class Writer {
	public:
		Writer(int, std::string);
		~Writer();
		void write(std::string*, int, double);
		void finalize();
	private:
		std::string filename;
		int wordlength;
		bool finalized = false;
	};


}