#include "ExceptionOpenError.h"


ExceptionOpenError::ExceptionOpenError(std::string add, int code):code(code)
{
	messege = "Problem z otwarciem pliku: " + add;
}

std::string ExceptionOpenError::getString()
{
	return messege;
}

int ExceptionOpenError::getCode()
{
	return code;
}

ExceptionOpenError::~ExceptionOpenError()
{
}
