#include <iostream>
#include <fstream>
#include <string>
#include <climits>

#define POINTER_DEPTH 100

using namespace std;

int main()
{
	ofstream pointerSource("pointers.cpp");

	std::string pstr = "#include <iostream>\n"
						"\n"
						"using namespace std;\n"
						"\n"
						"int main()\n"
						"{\n"
						"	int a = 5;\n"
						"	int* p1 = &a;\n";

	pointerSource << pstr;


	pstr = "";

	unsigned long long i;
	// maybe use ULLONG_MAX?
	for(i = 2; i <= POINTER_DEPTH; i++)
	{
		std::string stars = "";

		for(unsigned long long j = 1; j <= i; j++)
		{
			stars += "*";
		}

		pstr = "	int" + stars + " p" + std::to_string(i) +
							" = &p" + std::to_string(i-1) + ";\n";

		pointerSource << pstr;
	}

	i--;

	pstr = "";
	pstr += "	cout << ";

	for(unsigned long long j = 1; j <= i; j++)
	{
		pstr += "*";
	}

	pstr += "p" + std::to_string(i) + " << endl;\n" + "	return 0;\n" + "}\n";

	pointerSource << pstr;
}
