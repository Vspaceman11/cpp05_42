# cpp05: Exception Handling & Casting

This module focuses on C++ exception handling, custom exception classes, and the implementation of design patterns within a bureaucratic workflow system. It demonstrates proper error handling, RAII principles, and polymorphic behavior through forms and bureaucratic hierarchy.

## Overview

The module explores how to:
- Create and throw custom exception classes
- Implement exception hierarchies
- Handle exceptions with try-catch blocks
- Design polymorphic systems using abstract classes
- Apply factory and strategy patterns
- Manage resources safely with exceptions

## Exercises

### **ex00: Bureaucrat**

**Concepts:** Custom exceptions, exception hierarchies, grade management

A `Bureaucrat` class representing a government employee with a grade (1-150, where 1 is the highest).

**Key Features:**
- `Bureaucrat` manages a name and grade
- Grade range validation: 1 (highest) to 150 (lowest)
- `incrementGrade()` and `decrementGrade()` methods
- Custom exception classes:
  - `GradeTooHighException` - thrown when grade becomes < 1
  - `GradeTooLowException` - thrown when grade becomes > 150

**Learning Goals:**
- Implement exception classes inheriting from `std::exception`
- Override `what()` method for error messages
- Throw and handle exceptions in constructors and methods
- Use member initializer lists for const members

**Build & Run:**
```bash
cd ex00
make
./Bureaucrat
```

---

### **ex01: Form Validation**

**Concepts:** Form design, exception handling, grade-based access control

Extends the bureaucrat system with a `Form` class that represents an administrative document.

**Key Features:**
- `Form` has a name, required signing grade, and required execution grade
- Grades must be in the range 1-150 (same as bureaucrats)
- Forms start unsigned
- `beSigned()` method validates bureaucrat grade before signing
- Exception handling for invalid grades

**Learning Goals:**
- Design classes with grade-based access control
- Validate operations before state changes
- Communicate errors through custom exceptions
- Implement const and non-const accessors

**Build & Run:**
```bash
cd ex01
make
./Bureaucrat
```

---

### **ex02: Abstract Forms & Polymorphism**

**Concepts:** Abstract classes, virtual functions, polymorphic execution, inheritance

Introduces abstract form types that perform specific actions when executed.

**Key Features:**
- `AForm` - abstract base class with pure virtual `execute()` method
- Three concrete form implementations:
  - **PresidentialPardonForm** - pardon a target
  - **RobotomyRequestForm** - robotomize a target (50% success rate)
  - **ShrubberyCreationForm** - create shrubberery in file
- Forms require both signing and execution by qualified bureaucrats
- `FormNotSignedException` - thrown if execution attempted on unsigned form

**Class Hierarchy:**
```
AForm (abstract)
├── PresidentialPardonForm
├── RobotomyRequestForm
└── ShrubberyCreationForm
```

**Learning Goals:**
- Define and implement abstract base classes
- Use pure virtual functions for enforcing interface contracts
- Implement polymorphic behavior with virtual methods
- Handle multiple exception scenarios in derived classes
- Create files and modify state through polymorphic calls

**Build & Run:**
```bash
cd ex02
make
./Bureaucrat
```

---

### **ex03: Intern Factory Pattern**

**Concepts:** Factory pattern, member function pointers, dynamic form creation

Implements an `Intern` class that dynamically creates forms based on user input.

**Key Features:**
- `Intern` class creates `AForm` objects on the heap
- `makeForm()` method takes form name and target
- Uses function pointers for factory method dispatch
- Supports creating:
  - "shrubbery creation" forms
  - "robotomy request" forms
  - "presidential pardon" forms
- Provides meaningful error messages for invalid form names
- Proper memory management for dynamically allocated forms

**Member Function Pointers:**
```cpp
typedef AForm* (Intern::*FormCreator)(const std::string& target) const;
```

**Learning Goals:**
- Implement the factory pattern for object creation
- Use member function pointers for dynamic dispatch
- Handle invalid input gracefully
- Manage heap-allocated objects in polymorphic contexts
- Provide flexible, extensible object creation interfaces

**Build & Run:**
```bash
cd ex03
make
./Bureaucrat
```

---

## File Structure

```
cpp05/
├── ex00/
│   ├── Bureaucrat.hpp
│   ├── Bureaucrat.cpp
│   ├── main.cpp
│   └── Makefile
├── ex01/
│   ├── Bureaucrat.hpp
│   ├── Bureaucrat.cpp
│   ├── Form.hpp
│   ├── Form.cpp
│   ├── main.cpp
│   └── Makefile
├── ex02/
│   ├── Bureaucrat.hpp
│   ├── Bureaucrat.cpp
│   ├── AForm.hpp
│   ├── AForm.cpp
│   ├── PresidentialPardonForm.hpp
│   ├── PresidentialPardonForm.cpp
│   ├── RobotomyRequestForm.hpp
│   ├── RobotomyRequestForm.cpp
│   ├── ShrubberyCreationForm.hpp
│   ├── ShrubberyCreationForm.cpp
│   ├── main.cpp
│   └── Makefile
├── ex03/
│   ├── Bureaucrat.hpp
│   ├── Bureaucrat.cpp
│   ├── AForm.hpp
│   ├── AForm.cpp
│   ├── Intern.hpp
│   ├── Intern.cpp
│   ├── PresidentialPardonForm.hpp
│   ├── PresidentialPardonForm.cpp
│   ├── RobotomyRequestForm.hpp
│   ├── RobotomyRequestForm.cpp
│   ├── ShrubberyCreationForm.hpp
│   ├── ShrubberyCreationForm.cpp
│   ├── main.cpp
│   └── Makefile
└── README.md
```

## Building

### Build a Single Exercise

```bash
cd exXX
make
```

### Clean a Single Exercise

```bash
cd exXX
make clean      # Remove object files
make fclean     # Remove all generated files
make re         # Clean and rebuild
```

## Key Concepts

### Exception Handling
- **Custom Exception Classes** - Derive from `std::exception` and override `what()`
- **Throwing Exceptions** - Use `throw` to signal errors
- **Exception Safety** - Ensure resources are properly managed even when exceptions occur

### Abstract Classes
- **Pure Virtual Functions** - `virtual void method() = 0;`
- **Cannot instantiate abstract classes** - Only derived concrete classes can be instantiated
- **Enforce interface contracts** - All derived classes must implement pure virtual methods

### Design Patterns
- **Factory Pattern (ex03)** - Centralized object creation logic
- **Strategy Pattern (ex02)** - Different form execution strategies
- **RAII Principle** - Resource Acquisition Is Initialization

### Grade System
- Grade 1 is the **highest** (most powerful)
- Grade 150 is the **lowest** (least powerful)
- Operations throw exceptions if bureaucrat grade is insufficient

## Example Usage

### ex00: Create and test a Bureaucrat
```cpp
Bureaucrat b("Alice", 50);
std::cout << b;           // Output: Alice, bureaucrat grade 50
b.incrementGrade();       // Grade becomes 49
```

### ex02: Create and execute a form
```cpp
Bureaucrat b("Bob", 5);
ShrubberyCreationForm form("Home", "backyard");
form.beSigned(b);         // Sign the form
form.execute(b);          // Execute - creates file
```

### ex03: Use intern factory
```cpp
Intern intern;
AForm* form = intern.makeForm("presidential pardon", "Alice");
if (form)
    delete form;          // Clean up heap memory
```

## Learning Objectives

By completing this module, you will understand:

✓ How to design and implement custom exception classes
✓ Exception handling and error propagation in C++
✓ Abstract base classes and polymorphic interfaces
✓ Virtual functions and late binding
✓ Factory and strategy design patterns
✓ Memory management with polymorphic types
✓ Grade-based access control systems
✓ RAII and resource safety with exceptions

## Notes

- All code follows the **C++17 standard**
- Proper use of `const` and `noexcept` specifiers
- Memory allocated on heap is properly cleaned up
- Exception safety is maintained throughout
- Classes follow the Orthodox Canonical Form (constructor, copy, assignment, destructor)

---

**Start with ex00** and progress sequentially to understand the complete flow from basic exceptions through abstract polymorphism and factory patterns.
