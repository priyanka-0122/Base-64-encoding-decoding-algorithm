#define ADD_TABLES
#include "defs.h"

void encode_to_base64(char *string) {

	int byte_1, byte_2, byte_3;
	int size = 0;

	while(string[size] != 0)
		size++;

	// Handling 3bytes of the Input string
	for (int i = 0; i < size; i += 3) {
		byte_1 = byte_2 = byte_3 = 0;

		// 1st Char: Top 6 bits of Byte 1
		byte_1 = string[i];
		printf("%c", Base_64[(byte_1 & 0xFC) >> 2]);

		if (i + 1 < size) {
			// 2nd Char: Bottom 2 of Byte 1 + Top 4 of Byte 2
			byte_2 = string[i+1];
			printf("%c", Base_64[(((byte_1 & 0x3) << 4) | ((byte_2 & 0xF0) >> 4))]);

			if (i + 2 < size) {
				// 3rd Char: Bottom 4 of Byte 2 + Top 2 of Byte 3
				byte_3 = string [i+2];
				printf("%c", Base_64[((byte_2 & 0xF) << 2) | ((byte_3 & 0xC0) >> 6)]);

				// 4th Char: Bottom 6 of Byte 3
				printf("%c", Base_64[byte_3 & 0x3F]);
			} else {
				// Final char: Bottom 4 bits of Byte 2, shifted left 2
				printf("%c", Base_64[((byte_2 & 0xF) << 2) | 0x0]);

				// Padding for 1 input bytes
				printf("=");
			}
		} else {
			// Final char: Bottom 2 bits of Byte 1, shifted left 4
			printf("%c", Base_64[((byte_1 & 0x3) << 4) | 0x0]);

			// Padding for 2 input bytes
			printf("==");
		}
	}
	printf("\n");
}
