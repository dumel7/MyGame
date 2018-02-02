#pragma once
#include <string>
class ExceptionOpenError
{
private:
	std::string messege;
	int code;
public:
	ExceptionOpenError(std::string add, int code);
	std::string getString();							//zwraca tresc bledu
	int getCode();
	~ExceptionOpenError();
};

