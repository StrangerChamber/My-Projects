#include <stdio.h>
#include <string.h>
#include <assert.h>


# include <unistd.h>
# include <pwd.h>
# define MAX_PATH FILENAME_MAX

#include "app.h"

sgx_enclave_id_t global_eid = 0;



int SGX_CDECL main(int argc, char *argv[])
{


    //THIS INITS THE ENCLAVE
    sgx_create_enclave(ENCLAVE_FILENAME, SGX_DEBUG_FLAG, NULL, NULL, &global_eid, NULL)

    int summation = addNumbersEcall();
    //should print 400
    printf("%i", summation);

    //destroy enclave

    sgx_destroy_enclave(global_eid);

    return 0;
}