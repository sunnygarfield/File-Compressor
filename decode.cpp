#include <iostream>
#include "./header/huffman.h"
using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Invalid input format" << endl;
		exit(1);
	}

	// constructor for the abstract class huffman, takes the compressed file & file to be decoded to
	huffman h(argv[1], argv[2]);

	// recreates the huffman tree from the encoded data {character,freq}
	h.recreate_huffman_tree();

	// decodes the compressed file
	h.decode_file();

	cout << endl;
	return 0;
}