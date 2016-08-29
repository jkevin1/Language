#include "Name.h"
#include <Windows.h>

static void print(const Name& name) {
	printf("Length: %u\n", name.getSize());
	printf("Hash:   %u\n", name.getHash());
	printf("Text: \'");
	fwrite(&name[0], 1, name.getSize(), stdout);
	printf("\'\n");
}

static const char* buffer = "asdf this is a large buffer";

int main() {
	const Name name1 = "MEMES?";
	const Name name2("MEMES!");
	const Name name3(buffer + 5, 4);
	const Name name4(buffer + 15);

	puts("--------------------");
	print(name1);
	puts("--------------------");
	print(name2);
	puts("--------------------");
	print(name3);
	puts("--------------------");
	print(name4);
	puts("--------------------\n");

	system("pause");
}
