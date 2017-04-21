#include <stdio.h>
#include <string.h>

void encryptionMain() {

}

void encryptionChooser() {

}


// ENCRYPTION

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

void encryptionMethod3(char *input, char *output) {
	// ??? encryption
	// For use only with the encryption method identifier
}

// DECRYPTION

void decryptionMethod1(char *input, char *output) {
	// XOR decryption
	// XOR is decrypted by running data through same algorithm.
	encryptionMethod1(input, output);
}

void decryptionMethod2(char *input, char *output) {
	// AES decryption
} 
