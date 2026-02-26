#include "defs.h"

// Wrong set of argument passed
static void argv_error() {
	printf("Error\n");
	printf("Expected argument in the below format:\n");
	printf("./a.out -encode <string in ASCII>\n");
	printf("./a.out -decode <string in BASE64>\n");
	exit(1);
}

int main(int argc, char** argv) {

	if (argc != 3)
		argv_error();
    
	if (strcmp(argv[1], "-encode") == 0)
		encode_to_base64(argv[2]);
	else if (strcmp(argv[1], "-decode") == 0)
		decode_from_base64(argv[2]);
	else
		argv_error();
}
