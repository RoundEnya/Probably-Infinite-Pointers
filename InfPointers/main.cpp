#include <iostream>
#include <fstream>
#include <string>
#include <climits>

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


	unsigned long long i;
	// maybe use ULLONG_MAX?
	for(i = 2; i <= 1000; i++)
	{
		std::string stars = "";

		for(unsigned long long j = 1; j <= i; j++)
		{
			stars += "*";
		}

		std::string nstr = "	int" + stars + " p" + std::to_string(i) +
							" = &p" + std::to_string(i-1) + ";\n";

		pointerSource << nstr;
	}

	pointerSource << "	cout << ";

	i--;

	for(unsigned long long j = 1; j <= i; j++)
	{
		pointerSource << "*";
	}

	pointerSource << "p" + std::to_string(i) + " << endl;\n";

	pointerSource << "	return 0;\n";
	pointerSource << "}\n";
}
