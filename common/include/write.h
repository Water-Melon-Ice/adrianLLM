#pragma once

#include <string>
#include <fstream>
#include <filesystem>
#include "stringutils.h"

constexpr char NULLBYTE = 0;

namespace adrianllm
{

	class Writer {
	public:
		Writer(int, std::string);
		~Writer();
		void writeTemp(std::string*, int);
		void writeAll(std::string);
		void finalize();

	private:
		std::string filename;
		int wordlength;
		bool finalized = false;
	};


}