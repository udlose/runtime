// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

#include "pal_compiler.h"
#include <stdint.h>
#include "opensslshim.h"

typedef enum
{
    PalKemId_Unknown = 0,
    PalKemId_MLKem512 = 1,
    PalKemId_MLKem768 = 2,
    PalKemId_MLKem1024 = 3,
} PalKemId;

PALEXPORT int32_t CryptoNative_EvpKemAvailable(const char* algorithm);
PALEXPORT int32_t CryptoNative_EvpKemGetPalId(const EVP_PKEY* pKey,
                                              int32_t* kemId,
                                              int32_t* hasSeed,
                                              int32_t* hasDecapsulationKey);
PALEXPORT EVP_PKEY* CryptoNative_EvpKemGeneratePkey(const char* kemName, uint8_t* seed, int32_t seedLength);
PALEXPORT int32_t CryptoNative_EvpKemExportPrivateSeed(const EVP_PKEY* pKey, uint8_t* destination, int32_t destinationLength);
PALEXPORT int32_t CryptoNative_EvpKemExportDecapsulationKey(const EVP_PKEY* pKey, uint8_t* destination, int32_t destinationLength);
PALEXPORT int32_t CryptoNative_EvpKemExportEncapsulationKey(const EVP_PKEY* pKey, uint8_t* destination, int32_t destinationLength);
PALEXPORT int32_t CryptoNative_EvpKemEncapsulate(EVP_PKEY* pKey,
                                                 void* extraHandle,
                                                 uint8_t* ciphertext,
                                                 int32_t ciphertextLength,
                                                 uint8_t* sharedSecret,
                                                 int32_t sharedSecretLength);
PALEXPORT int32_t CryptoNative_EvpKemDecapsulate(EVP_PKEY* pKey,
                                                 void* extraHandle,
                                                 const uint8_t* ciphertext,
                                                 int32_t ciphertextLength,
                                                 uint8_t* sharedSecret,
                                                 int32_t sharedSecretLength);
PALEXPORT EVP_PKEY* CryptoNative_EvpKemImportKey(const char* kemName, uint8_t* key, int32_t keyLength, int32_t privateKey);
