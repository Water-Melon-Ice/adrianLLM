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
	std::string Reader::read(std::string* words, int count)
	{
		std::ifstream file;
		file.open(filename, std::ios::binary);
		if (!file.is_open())
			return "";

		int currentlength = -1;
		std::string currans;

		std::string line;
		while (std::getline(file, line)) //Line DOES contain Null bytes
		{
			int templength = 0;
			std::vector<std::string> vec = splitStringWithNull(line, '\0');
			if(vec.size() == 0)
				continue;
			for (int i = 0; i < vec.size() - 1; i++)
			{
				if (vec[i] == words[count - i - 1])
				{
					templength++;
				}
				else
				{
					break;
				}
			}
			if (templength > currentlength)
			{
				currentlength = templength;
				currans = vec[vec.size() - 1];
			}
		}
		return currans;
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
