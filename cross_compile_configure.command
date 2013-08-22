# Add cross compiler path into ENV PATH:
	e.g. PATH=/usr/arm-2008q3/bin:"${PATH}"
# To compile from source using LIBTOOL AUTOMAKE tool chain, configure like this:
	e.g. CC=arm-linux-gcc CXX=arm-linux-g++ ./configure --build=i686-linux --host=arm-linux --prefix=`pwd`/install
 	e.g. CC=arm-linux-gcc CXX=arm-linux-g++ CXXFLAGS="-I/home/boost1.4.2/install/include -L/home/boost1.4.2/install/lib -O3 -mtune=cortex-a8 -mfpu=neon" ./configure --build=i686-linux --host=arm-linux --prefix=`pwd`/install


