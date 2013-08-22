#include <fstream>
#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>

// Read file into mapped region
int main()
{
	std::string file("mmap_test.dat");
	// Create the file mapping
	boost::interprocess::file_mapping fm(file.c_str(), boost::interprocess::read_only); // boost::interprocess::read_write
	// Map the file in memory
	boost::interprocess::mapped_region region(fm, boost::interprocess::read_only); // boost::interprocess::read_write
	char* addr = (char *)region.get_address();
	std::size_t elements  = region.get_size()/sizeof(char);
	// Do something using the addr pointer

	return 0;
}
