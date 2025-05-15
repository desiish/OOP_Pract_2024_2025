#pragma once
namespace UserConstants
{
	const int USERNAME = 8;
	const int PHONELENGHT = 10;
	const int BOOK_CAPACITY = 50;
}
class User
{
private:
	char _username[UserConstants::USERNAME + 1];
	int _phone[UserConstants::PHONELENGHT];
public:
	User();
	User(const char* name,const int* phone);


	//setters
	void setName(const char* username);
	void setPhone(const int* phone);

	//getters
	const char* getName() const;
	const int* getPhone() const;

	void printPhone();
	void printName();


};
