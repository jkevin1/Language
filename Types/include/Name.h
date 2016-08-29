#pragma once

#include <stdint.h>
#include <stdio.h>

// Name: a non-owning string that is pre-hashed and allows for
// dynamically expanding the string and updating the hash value

class Name {
public:
	// construct from existing text
	Name(const char* start);
	Name(const char* start, uint32_t length);

	// accessor for the internal hash value
	uint32_t getHash() const { return hash; }

	// accessor for the size of the string
	uint32_t getSize() const { return size; }

	// accessor for the internal string
	const char& operator[](uint32_t i) const { return text[i]; } // TODO debug only range check

	bool operator==(const Name& rhs);

	// TODO usual string functions, e.g. find, substring, etc.

	// expand the string by n characters
	void expand(uint32_t n = 1);

private:
	const char* text;
	uint32_t size; // a name is assumed to be far shorter than 4294967295
	uint32_t hash; // 32 bits is plenty for hashing
};
