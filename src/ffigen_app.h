// gemma_wrapper.h

#ifndef GEMMA_WRAPPER_H
#define GEMMA_WRAPPER_H

#include <stddef.h> // for size_t
#include <stdint.h> // for intptr_t

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GemmaWrapper GemmaWrapper;

// Constructor and destructor
GemmaWrapper* GemmaWrapper_create();
void GemmaWrapper_destroy(GemmaWrapper* gemma);

// Methods
void GemmaWrapper_loadModel(GemmaWrapper* gemma, const char** args, size_t args_count);
void GemmaWrapper_showConfig(GemmaWrapper* gemma);
void GemmaWrapper_showHelp(GemmaWrapper* gemma);
char* GemmaWrapper_completionPrompt(GemmaWrapper* gemma, const char* prompt);

#ifdef __cplusplus
}
#endif

#endif // GEMMA_WRAPPER_H

