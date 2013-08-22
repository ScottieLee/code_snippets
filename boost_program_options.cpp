#include <boost/program_options.hpp>
#include <iostream>
#include <boost/format.hpp>

// Boost program options examples

// Link with libboost_program_options

namespace po = boost::program_options;
int main(int argc, char* argv[])
{
      std::string file, data_type, side;
      int interp;
      float gain;
      double freq;
      size_t block_size;
      po::options_description desc("Allowed options");
      desc.add_options()
          ("help", "helf message")
          ("file",   po::value<std::string>(&file), "File to transmit")
	  ("data_type", po::value<std::string>(&data_type)->default_value("short"), "Data type in file, complex or short")
	  ("interp", po::value<int>(&interp), "Interp rate. The sample rate crossing usb will be 128M/interp")
	  ("freq", po::value<double>(&freq), "tx frequency")
	  ("side", po::value<std::string>(&side)->default_value("A"), "Side A or B")
	  ("gain", po::value<float>(&gain)->default_value(1), "Multiply Factor, integer.")
	  ("block_size",  po::value<size_t>(&block_size)->default_value(3200), "Reading block size")
      ;

      po::variables_map vm;
      po::store(po::parse_command_line(argc, argv, desc), vm);
      po::notify(vm);

      if (vm.count("help")) {
	std::cout << boost::format("Transmit signals from file, %s") % desc << std::endl;
      }
      if (!vm.count("file")) {
	std::cerr << "You must specify a file." << std::endl;
	exit(1);
      }
      if (!vm.count("interp")) {
	std::cerr << "You must specify the interpolation rate." << std::endl;
	exit(1);
      }
      
      if(not (side == "A" || side == "B")){
	std::cerr << "Side must be A or B." << std::endl;
	exit(1);
     }
     if (not (data_type == "short" || data_type == "complex")){
	std::cerr << "Data type must be short or complex." << std::endl;
	exit(1);
     }
     // Do something...
   
    return 0;
}
