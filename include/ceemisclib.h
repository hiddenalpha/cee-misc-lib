#ifndef INCGUARD_dea1aed718b850f9d3f9d79975276b6e
#define INCGUARD_dea1aed718b850f9d3f9d79975276b6e

#include <sys/types.h>


/**
 * Usually used return code for functions to indicate status.
 *
 * DEPRECATED: Most APIs just use an int return code.
 *
 * @return
 *      =0 (Zero): General Success status.
 *      -1 (Minus one): General/unknown error.
 *      <0 (Other negative values): Indicate function specific errors. Consult
 *         doc of the used function of their meaning.
 *      >0 (Other positive Values): Function specific success codes. Consult
 *         doc of the used function.
 */
typedef  ssize_t  err_t;


err_t
ceemisclib_run( int argc , char*argv[] );


#endif /* INCGUARD_dea1aed718b850f9d3f9d79975276b6e */
