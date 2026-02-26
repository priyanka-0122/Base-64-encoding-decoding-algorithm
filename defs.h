#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decl.h"

# ifdef ADD_TABLES
	// This actually creates the array (Allocation)
	char Base_64[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
        	          'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                	  'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
	                  'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
        	          'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                	  'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	                  'w', 'x', 'y', 'z', '0', '1', '2', '3',
        	          '4', '5', '6', '7', '8', '9', '+', '/'};
# else
	// This just tells the file the array exists elsewhere (Reference)
	extern char Base_64[];
# endif

# endif
