#include "defs.h"

// Finds the index of a character within the Base_64 lookup table.
int foundChar (char searchChar) {
	int foundIndex = -1;

	for (int j = 0; j < 64; j++) {
		if (Base_64[j] == searchChar) {
			foundIndex = j;
			break;
		}
	}
	return foundIndex;
}

void decode_from_base64(char *string){
	int size = 0;
	int byte_1, byte_2, byte_3, byte_4;
	char searchChar;

	// Calculating size of the input string
	while(string[size] != 0)        
        	size++;

	// Processing the Base64 string in blocks of 4 characters
	for (int i=0; i < size; i+=4) {

		// Fetch index for 1st Base64 character
		searchChar = string[i];
		byte_1 = foundChar(searchChar);

		// Fetch index for 2nd Base64 character
		searchChar = string[i+1];
		byte_2 = foundChar(searchChar);

		// 1st Output Byte: 6 bits from byte_1 + top 2 bits from byte_2
		printf("%c", ((byte_1 << 2) | ((byte_2 & 0xF0) >> 4)));

		// Check if 3rd character is padding
		searchChar = string[i+2];
		if (searchChar != '=') {
			byte_3 = foundChar(searchChar);

			// 2nd Output Byte: bottom 4 bits from byte_2 + top 4 bits from byte_3
			printf("%c", (((byte_2 & 0xF) << 4) | ((byte_3 & 0x3C) >> 2)));

			// Check if 4th character is padding
			searchChar = string[i+3];
			if (searchChar != '=') {
				byte_4 = foundChar(searchChar);

				// 3rd Output Byte: bottom 2 bits from byte_3 + 6 bits from byte_4
				printf("%c", (((byte_3 & 0x3) << 6) | (byte_4 & 0x3F)));
			}
		}
	}
	printf("\n");
}
