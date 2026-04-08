#include "Bureaucrat.hpp"

int main() {
	std::cout << "--- Test 1: Valid Bureaucrat ---" << std::endl;
	try {
		Bureaucrat bob("Bob", 42);
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << "After increment: " << bob << std::endl;
		bob.decrementGrade();
		std::cout << "After decrement: " << bob << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Grade Too High at Creation ---" << std::endl;
	try {
		Bureaucrat alice("Alice", 0);
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: Grade Too Low at Creation ---" << std::endl;
	try {
		Bureaucrat john("John", 151);
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: Incrementing beyond limits ---" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		std::cout << boss << std::endl;
		boss.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
