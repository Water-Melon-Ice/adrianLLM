#pragma once

#include "read.h"

namespace adrianllm {

	Reader::Reader(int length, std::string filename) : length(length), filename(filename)
	{

	}

	Reader::~Reader()
	{
	}

	//implement read
	std::string Reader::read(std::string* words)
	{
		std::ifstream file;
		file.open(filename, std::ios::binary);
		if (!file.is_open())
			return "";
		std::string line;
		while (std::getline(file, line)) //Line DOES contain Null bytes
		{
			for (int i = 0; i < line.length(); i++)
			{
				
			}
		}
		return "";
	}

	int Reader::findNull() {
		return 1;
	}

	int Reader::find(std::string& word)
	{
		std::ifstream file;
		file.open(filename, std::ios::binary);
		if (!file.is_open())
			return -1;
		std::string line;
		while (std::getline(file, line)) //Line DOES contain Null bytes
		{
			//get pos of first char in line that equals zero.
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == 0)
					return i;
			}
		}
		return -1;
	}

}
