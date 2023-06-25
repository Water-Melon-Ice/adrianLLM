#pragma once

#include "write.h"
#include <iostream>

namespace adrianllm {



	Writer::Writer(int wordlength, std::string filename) : wordlength(wordlength), filename(filename)
	{

	}

	Writer::~Writer()
	{
		if(!finalized)
		{
			finalize();
		}
	}
	
	void Writer::writeTemp(std::string* word, int wordcount)
	{
		std::ofstream file;
		std::string tempfilename(this->filename);
		tempfilename.append(".temp");
		file.open(tempfilename, std::ios::app | std::ios::binary);
		for (int i = 0; i < wordcount-1; i++)
		{
			file.write(word[i].c_str(), word[i].length());
			file.write(&NULLBYTE, 1);
		}
		file.write(word[wordcount-1].c_str(), word[wordcount-1].length());
		file << std::endl;
		file.close();
	}

	void Writer::writeAll(std::string filename)
	{
		std::ifstream file;
		file.open(filename, std::ios::in | std::ios::binary);
		std::string line;
		while (std::getline(file, line))
		{
			rstrip(line);
			std::vector tokens = splitStringWithNull(line, ' ');
			for (int i = 0; i < tokens.size(); i++)
			{
				int max = std::min(wordlength, i);
				for (int p = 0; p <= max; p++)
				{
					std::string* words = new std::string[p+1];
					for (int j = 1; j <= p; j++)
					{
						words[p-j] = tokens[i - p + j - 1];
					}
					words[p] = tokens[i];
					this->writeTemp(words, p+1);
					delete[] words;
				};
			};
		}
		file.close();
	}



	void Writer::finalize()
	{
		/*std::string tempfilename(this->filename);
		tempfilename.append(".temp");

		bubbleSortFileLines(tempfilename, this->filename);*/

		//ifile.open(tempfilename, std::ios::in | std::ios::binary);
		//std::string line;
		//std::string tryline;
		//
		//int count;

		//while (std::getline(ifile, line))
		//{

		//	
		//	/*std::ofstream ofile;
		//	file.open(filename, std::ios::app | std::ios::binary);
		//	for (int i = 0; i < wordlength; i++)
		//	{

		//	}*/
		//}


		/*std::ofstream file;
		file.open(filename, std::ios::app | std::ios::binary);
		for (int i = 0; i < wordlength; i++)
		{
			file.write(word[i].c_str(), word[i].length());
			file.write(&NULLBYTE, 1);
		}
		file.write(&NULLBYTE, 1);
		file << probability << std::endl;
		file.close();
		finalized = true;*/
	}


	

	
}
