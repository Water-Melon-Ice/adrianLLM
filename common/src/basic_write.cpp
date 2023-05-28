#include "write.h"

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
	
	//add writemethod, write to file in text mode from filename.
	void Writer::write(std::string* word, int wordlength, double probability)
	{
		std::ofstream file;
		file.open(filename.append(".temp"), std::ios::app | std::ios::binary);
		for (int i = 0; i < wordlength; i++)
		{
			file.write(word[i].c_str(), word[i].length());
			file.write(&NULLBYTE, 1);
		}
		file.close();
	}

	void Writer::finalize()
	{
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
