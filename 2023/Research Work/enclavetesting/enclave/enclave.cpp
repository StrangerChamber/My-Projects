#include <stdarg.h>
#include "enclave.h"
#include "enclave_t.h"


//ECALLS DEFINED HERE 


int addNumbersEcall()
{
    int sum = 100+100+100+100;
    return sum;
}