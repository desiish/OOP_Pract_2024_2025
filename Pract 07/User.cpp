#include "User.h"
#pragma warning (disable : 4996)
#include <iostream>
#include <stdexcept>
#include <cstring>

//DEF CTOR
User::User()
{
    setName("none");   
    int defaultPhone[UserConstants::PHONELENGHT] = { 0 };
    setPhone(defaultPhone);
    
}
//CTOR
User::User(const char* username,const int* phone)
{
    if (!username || std::strlen(username) > UserConstants::USERNAME) 
    {
        setName("none");
    }
    else
    {
        setName(username);
    }
    setPhone(phone);

}

//SETTERS - used by def ctor and ctor
void User::setName(const char* username)
{
    if (!username)
    {
        std::cout << "Invalid name! Skipping user.\n";
        return;
    }
    size_t len = std::strlen(username);

    if (len > UserConstants::USERNAME)
    {
        std::cout << "Username is too long! Skipping user.\n";
        return;
    }
    
    //STRONG SAFETY
    char temp[UserConstants::USERNAME];
    std::strcpy(temp, username);

    //only if valid, this will be updated
    std::memcpy(_username, temp, UserConstants::USERNAME);
}

void User::setPhone(const int* phone)
{
    if (!phone)
    {
        //it will be set to the default one
        std::cout << "Invalid phone number! Using def phone...\n";
        return;
    }
    //STRONG SAFETY
    int temp[UserConstants::PHONELENGHT];
    for (int i = 0; i < UserConstants::PHONELENGHT; ++i) 
    {
        temp[i] = phone[i];
    }
    //if okay:
    std::memcpy(_phone, temp, sizeof(_phone));
}

//GETTERS
const char* User::getName() const
{
    return _username;
}
const int* User::getPhone() const
{
    return _phone;
}

void User::printPhone()
{
    for (int i = 0; i < UserConstants::PHONELENGHT; ++i)
    {
        std::cout << _phone[i];
    }
    
}
void User::printName()
{
    for (int i = 0; i < std::strlen(_username); ++i)
    {
        std::cout << _username[i];
    }
}
