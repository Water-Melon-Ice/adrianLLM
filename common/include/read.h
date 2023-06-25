#pragma once

#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>
#include "stringutils.h"

namespace adrianllm 
{
	class Reader {
	public:
		Reader(int, std::string);
		~Reader();
		std::string read(std::string*, int);
		int find(std::string&);

	private:
		std::string filename;
		int length;
	};
}