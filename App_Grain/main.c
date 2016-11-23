#include "ecrypt-config.h"
#include "main.h"
#include "ecrypt-sync.h"
#include "bpm-file.h"


char* encrypt_decrypt(char* dir, char *plaintext, bmpInfoHeader header, char* key, char* IV) 
{

	ECRYPT_ctx ctx;


	u32 msglen = header.imgsize;
	char* ciphertext = malloc(sizeof(char) * msglen);

	ECRYPT_init();
	ECRYPT_keysetup(&ctx, key, 128, 96);
	ECRYPT_ivsetup(&ctx, IV);
	ECRYPT_encrypt_bytes(&ctx, plaintext, ciphertext, msglen);
	SaveBMP(dir, ciphertext, msglen);
	return ciphertext;
}

void open_image(char* dir, bmpInfoHeader *header, char **body) {
	*body = LoadBMP(dir, header);
	return;
}
