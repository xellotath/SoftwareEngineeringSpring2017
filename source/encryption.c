#include <stdio.h>
#include <string.h>

void encryptionMain() {
	char readData; // Data read from game
	char writeData; // encrypted output

	encryptionChooser(readData, writeData);
}

void encryptionChooser(char *input, char *output) {
	// If 0-49 -> method 1. If 50-99 -> method 2
	int choice = rand() % (99 + 1 - 0);

	if (choice < 50) {
		encryptionMethod1(input, output);
		encryptionMethod3('a');
	}
	else {
		encryptionMethod2(input, output);
		encryptionMethod3('b');
	}
}


/////////////////
// ENCRYPTION //
///////////////

void encryptionMethod1(char *input, char *output) {
	// XOR encryption
	char key[] = { 'M', 'E', 'S', 'K' }; // TODO: Randomly generate key for increased security.

	int i;
	for (i = 0; i < strlen(input); i++) {
		output[i] = input[i] ^ key[i % (sizeof(key) / sizeof(char))];
	}
}

void encryptionMethod2(char *input, char *output) {
	// AES encryption
}

void encryptionMethod3(char *indicator) {
	// ??? encryption
	// For use only with the encryption method identifier
}


/////////////////
// DECRYPTION //
///////////////

void decryptionMethod1(char *input, char *output) {
	// XOR decryption
	// XOR is decrypted by running data through same algorithm.
	encryptionMethod1(input, output);
}

void decryptionMethod2(char *input, char *output) {
	// AES decryption
} 

void decryptionMethod3(char *input, char *output) {
	// ??? decryption
}
