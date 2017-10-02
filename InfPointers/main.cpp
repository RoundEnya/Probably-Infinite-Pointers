#include <iostream>
#include <fstream>
#include <string>
#include <climits>

using namespace std;

int main()
{
	ofstream pointerSource("pointers.cpp");

	string pstr = "#include <iostream>\n"
						"\n"
						"using namespace std;\n"
						"\n"
						"int main()\n"
						"{\n"
						"	int a = 5;\n"
						"	int* p1 = &a;\n";

	pointerSource << pstr;


	pstr = "";

	unsigned long long i, depth;

	cout << "Enter a pointer depth for the generation of pointers.cpp: ";
	cin >> depth;

	// maybe use ULLONG_MAX?
	for(i = 2; i <= depth; i++)
	{
		string stars = "";

		for(unsigned long long j = 1; j <= i; j++)
		{
			stars += "*";
		}

		pstr = "	int" + stars + " p" + to_string(i) +
							" = &p" + to_string(i-1) + ";\n";

		pointerSource << pstr;
	}

	i--;

	pstr = "";
	pstr += "	cout << ";

	for(unsigned long long j = 1; j <= i; j++)
	{
		pstr += "*";
	}

	pstr += "p" + to_string(i) + " << endl;\n" + "	return 0;\n" + "}\n";

	pointerSource << pstr;
}
