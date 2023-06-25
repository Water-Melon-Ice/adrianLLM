// adrianLLM.cpp : Defines the entry point for the application.

#include "preparer.h"

using namespace std;

int main()
{
	adrianllm::Writer writer(30, "test.txt");
	writer.writeAll("input.txt");
}
