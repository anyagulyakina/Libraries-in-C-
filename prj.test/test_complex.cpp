#include <complex/complex.hpp>


bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Complex z;
	istrm >> z;

	if (istrm.good())
	{
		cout << "Read success: " << str << " -> " << z << endl;
	}
	else
	{
		cout << "Read error : " << str << " -> " << z << endl;
	}
	return istrm.good();
}

void test(const std::string& a, const std::string& b) {
	std::istringstream ia(a);
	std::istringstream ib(b);
	Complex a1;
	Complex b1;
	ia >> a1;
	ib >> b1;
	if (ia.good()) {
		std::cout << "OK: reading first element successful" << std::endl;
	}
	else {
		std::cout << "ERROR: reading first element failed" << std::endl;
	}
	if (ib.good()) {
		std::cout << "OK: reading second element successful" << std::endl;
	}
	else {
		std::cout << "ERROR: reading second element failed" << std::endl;
	}
	std::cout << "a+b: " << a1 << " + " << b1 << " = " << a1 + b1 << '\n';
	std::cout << "a-b: " << a1 << " - " << b1 << " = " << a1 - b1 << '\n';
	std::cout << "a*b: " << a1 << " * " << b1 << " = " << a1 * b1 << '\n';
	try {
		std::cout << "a/b: " << a1 << " / " << b1 << " = " << a1 / b1 << '\n';
	}
	catch (const std::exception) {
		std::cout << "ERROR: division by zero!" << '\n';
	}

	if (a1 == b1) {
		std::cout << "Comparison: Elements are equal" << '\n';
	}
	else {
		std::cout << "Comparison: Elements are not equal" << '\n';
	}

	a1 = b1;
	std::cout << "a=b: " << " a = " << a1 << '\n';
}

int main() {

	test("{3.0, 3.3}", "{3.0, 3.3}");
	std::cout << std::endl;
	test("{0.2,2.3}", "{0.0, 0.0}");
	std::cout << std::endl;
	test("{0.1,5.4}", "{0.0, 2.7}");
	

	return 0;
}