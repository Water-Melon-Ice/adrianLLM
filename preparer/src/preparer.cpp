// adrianLLM.cpp : Defines the entry point for the application.
//

#include "preparer.h"

using namespace std;

const int words = 30;

int main()
{
	adrianllm::Writer writer(5, "test.txt");
	std::string test[4] = { "Blue", "Red", "Orange", "Yellow" };
	writer.write(test, 4, 0.5);

	adrianllm::Reader reader(5, "test.txt");
	std::string test2[4] = { "Blue", "Red", "Orange", "Yellow" };
	std::cout << reader.find(test2);
}
