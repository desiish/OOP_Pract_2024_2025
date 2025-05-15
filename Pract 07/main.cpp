#include <iostream>
#include "Library.h"

int main()
{
	try
	{
		Library library1;
		int phone2[UserConstants::PHONELENGHT] = { 0,8,9,6,6,5,2,7,3,3 };

		User user2("AliceAbrahamMelissaChelseaTheThird", phone2);
		User user1("Bob", phone2);

		library1.addBook("hey", "F. Scott Fitzgerald");
		library1.addBook("hi", "George Orwell3");
		library1.addBook("hi", "George Orwell2");
		library1.addBook("hi", "George Orwell1"); 

		library1.printAllBooks();

		library1.borrowBook(8678, user1);
		library1.borrowBook(0, user1);

		library1.printAllBooks();

		library1.returnBook(10);

		library1.printAllBooks();

	
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Unexpected!\n";
	}

}
