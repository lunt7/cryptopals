#ifndef CRYPTOPALS_H
#define CRYPTOPALS_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "mt19937.h"
#include "sha1.h"
#include "md4.h"

#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

#define SIZEOF_ARRAY(arr) (sizeof(arr) / sizeof(arr[0]))

#define TEST_STRING_EQUAL(x, ans) \
    do { \
        if (strcmp(x, ans) != 0) \
            printf("Wrong answer!\n"); \
    } while (0)

typedef enum {
    AES_CBC,
    AES_ECB
} AES_MODE;

size_t hexDecode(const char* in, unsigned char** out);
char* hexEncode(const unsigned char* in, size_t len);

size_t base64Encode(const unsigned char* in, size_t inlen, char** out);
size_t base64Decode(const char* in, size_t inlen, unsigned char** out);

unsigned char* xor(const unsigned char* in, size_t inlen, const unsigned char* key, size_t keylen);
unsigned char findXorKey(const unsigned char* in, size_t len);

float scoreEnglish(const unsigned char* in, size_t len);

int hammingDistance(const unsigned char* s1, const unsigned char* s2, size_t len);
size_t guessKeySize(const unsigned char* in, size_t len, size_t maxKeySize);
void breakRepeatingKeyXor(const unsigned char* in, size_t inlen,
                          unsigned char* key, size_t keySize,
                          unsigned char** decoded);

size_t AES128EncryptECB(const unsigned char* in, size_t len, const unsigned char* key, unsigned char** out);
void AES128DecryptECB(const unsigned char* in, size_t inlen, const unsigned char* key, unsigned char** out);
size_t AES128EncryptCBC(const unsigned char* in, size_t inlen,
                      const unsigned char* key, const unsigned char* iv, unsigned char** out);
void AES128DecryptCBC(const unsigned char* in, size_t inlen,
                      const unsigned char* key, const unsigned char* iv, unsigned char** out);
void AES128EncryptCTR(const unsigned char* in, size_t len,
                      const unsigned char* key, uint64_t nonce, unsigned char** out);
void AES128DecryptCTR(const unsigned char* in, size_t len,
                      const unsigned char* key, uint64_t nonce, unsigned char** out);
bool detectAES128ECB(const unsigned char* in, size_t inlen);

size_t pkcs7Pad(const char* in, size_t inlen, size_t blklen, char** out);
char* pkcs7Strip(char* in, size_t inlen);
bool pkcs7Validate(const char* in, size_t inlen);

unsigned char* randomBytes(size_t len);

void sha1(const unsigned char* in, size_t inlen, unsigned char* hash);
void sha1KeyedMAC(const unsigned char* in, size_t inlen, const unsigned char* key, size_t keylen,
                  unsigned char* hash);

void md4(const unsigned char* in, size_t inlen, unsigned char* hash);
void md4KeyedMAC(const unsigned char* in, size_t inlen, const unsigned char* key, size_t keylen,
                 unsigned char* hash);

void hmac_sha1(const unsigned char* in, size_t inlen, const unsigned char* key, size_t keylen,
               unsigned char* hash);

uint32_t byteSwap32(uint32_t num);
uint64_t byteSwap64(uint64_t num);

void strip_newlines(char* s);
void printHex(const unsigned char* arr, size_t len);
void printArray(const char* arr, size_t len);

#endif
