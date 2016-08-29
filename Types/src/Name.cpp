#include "Name.h"
#include <string.h>

// the starting hash value for djb2
static const uint32_t H0 = 5381;

// the step function for djb2
static inline uint32_t nextHash(uint32_t hash, char c) {
	return hash * 33 ^ static_cast<int>(c);
}

Name::Name(const char* start) : text(start), size(0), hash(H0) {
	puts("null terminated");
	while (text[size] != '\0')
		expand(1);
}

Name::Name(const char* start, uint32_t length) : text(start), size(0), hash(H0) {
	puts("explicitly terminated");
	expand(length);
}

bool Name::operator==(const Name& rhs) {
	if (hash != rhs.hash || size != rhs.size)
		return false;
	return (memcmp(text, rhs.text, size) == 0);
}

void Name::expand(uint32_t n) {
	for (; n > 0; n--) {
		const char nextChar = text[size];
		if (nextChar == '\0') break;
		hash = nextHash(hash, nextChar);
		size++;
	}
}
