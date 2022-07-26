#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <string>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

struct huffman_node
{
	char id;	            // character
	int freq;				// frequency of the character
	string code;			// huffman code for the character
	huffman_node* left;     // pointer to left node
	huffman_node* right;    // pointer to right node
	huffman_node()          // constructer
	{
		left = right = NULL; // intialise nodes with NULL left & right pointers
	}
};

typedef huffman_node* huf_node; // defines huffman_node* as 'huf_node'

class huffman
{
protected:
	huf_node node_array[128]; // array for 128characters in the Ascii Table
	fstream in_file, out_file;
	huf_node child, parent, root; // root refers to root of the huffman tree to be created
	char id;
	string in_file_name, out_file_name;

	class compare // compare funtion to set comparing rule of nodes inserted in priority queue
	{
	public:
		bool operator()(const huf_node& c1, const huf_node& c2) const
		{
			return c1->freq > c2->freq;
		}
	};
	priority_queue<huf_node, vector<huf_node>, compare> pq;	// priority queue
	void create_node_array();
	void traverse(huf_node, string);	// traverse the huffman tree and get huffman code for a character
	int binary_to_decimal(string&);		// convert a 8-bit binary string to a decimal integer
	string decimal_to_binary(int);		// convert decimal integer to a 8-bit binary code
	inline void build_tree(string&, char); // build the huffman tree

public:
	huffman(string, string);
	void make_pq();
	void create_huffman_tree();
	void assign_huffman_codes();
	void encode_file();
	void decode_file();
	void recreate_huffman_tree();
};

#endif