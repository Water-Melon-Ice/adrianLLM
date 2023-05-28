#pragma once
#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>

namespace adrianllm 
{
	class Reader {
	public:
		Reader(int, std::string);
		int find(std::string*);
	private:
		std::string filename;
		int length;
	};
}