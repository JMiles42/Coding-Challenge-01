#pragma once
#include <vector>
class Stream
{
public:
	// Implemented by subclasses; reads up to `bytes` bytes into `buf`, returns 
	// number of bytes actually read.  If the return value is less than requested 
	// `bytes`, the end of the stream has been encountered.
	virtual size_t Read(char* buf, size_t bytes) = 0;

	// Candidate to implement: return a vector with all bytes in the file.  Note 
	// that the size of the stream is unknown.
	std::vector<char> ReadAll();
};


