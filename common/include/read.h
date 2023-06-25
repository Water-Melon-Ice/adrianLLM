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
		std::string read(std::string*);
		int find(std::string&);
		int findNull();

	private:
		std::string filename;
		int length;
	};
}