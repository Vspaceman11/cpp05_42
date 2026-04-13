#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << "--- Test 1: Successful Signing ---" << std::endl;
	try {
		Bureaucrat chief("Chief", 2);
		Form contract("Top Secret Contract", 5, 10);

		std::cout << chief << std::endl;
		std::cout << contract << std::endl;

		chief.signForm(contract);
		std::cout << contract << std::endl; // Must be signed True
	} catch (std::exception &e) {
		std::cout << "Unexpected Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Grade Too Low to Sign ---" << std::endl;
	try {
		Bureaucrat intern("Intern", 150);
		Form highLevelForm("High Level Form", 1, 1);

		std::cout << intern << std::endl;
		std::cout << highLevelForm << std::endl;

		intern.signForm(highLevelForm);
	} catch (std::exception &e) {
		std::cout << "Unexpected Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: Invalid Form Creation (Grade Too High) ---" << std::endl;
	try {
		Form impossibleForm("Impossible", 0, 50);
	} catch (std::exception &e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: Invalid Form Creation (Grade Too Low) ---" << std::endl;
	try {
		Form trashForm("Trash", 151, 150);
	} catch (std::exception &e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	return 0;
}
