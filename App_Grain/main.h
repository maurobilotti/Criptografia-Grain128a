#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "bpm-file.h"

char* encrypt_decrypt(char* dir, char *plaintext, bmpInfoHeader header, char* key, char* IV);
void open_image(char* dir, bmpInfoHeader *header, char **body);