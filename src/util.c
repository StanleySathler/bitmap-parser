#include "util.h"

unsigned short int is_multiple_of(int number, int value)
{
	return (value > 0 && value % number == 0);
}
