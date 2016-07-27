# C
# a compilation script for usaco stuff
# usage:
#	./c				# runs the cpp file with name matching directory
#	./c progname	# runs the specified cpp

echo Compiling...

if [ "$1" != "" ]; then
	name=$1
else
	name=${PWD##*/}
fi

g++ -std=c++11 $name.cpp -o $name.exe
if [ "$?" = "0" ]; then
	echo Compiled. Running...
	./$name.exe $*
	if [ ! "$?" == "0" ]; then
		echo Error running program.
	fi
	
	echo FILE OUTPUT:
	cat $name.out
	echo
else
	echo Error compiling.
fi
echo Done.
