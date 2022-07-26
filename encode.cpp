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

	// constructor for the abstract class huffman, takes the input file & file to be encoded to
	huffman h(argv[1], argv[2]);

	// creates min priority queue of nodes containing {character,frequency}
	h.make_pq();

	// creates the huffman tree using the priority queue
	h.create_huffman_tree();

	// assign codes for the unique characters in the huffman tree
	h.assign_huffman_codes();

	// compresses the input file with generated huffman codes
	h.encode_file();

	cout << endl;
	return 0;
}