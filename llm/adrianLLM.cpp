// adrianLLM.cpp : Defines the entry point for the application.
//

#include "adrianLLM.h"

using namespace std;

int main()
{
	vector<string> vec;
	vec.push_back("I");
	for (int i = 0; i < 100; i++)
	{
		adrianllm::Reader reader(30, "test.txt");
		string read = reader.read(&vec[0], vec.size());
		std::cout << read << " ";
		vec.push_back(read);
	}

}
