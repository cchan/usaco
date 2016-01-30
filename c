echo Compiling...
g++ -std=c++11 ${PWD##*/}.cpp -o ${PWD##*/}
if [ "$?" = "0" ]; then
	echo Compiled. Running...
	./${PWD##*/}.exe $*
	if [ ! "$?" == "0" ]; then
		echo Error running program.
	fi
	
	echo FILE OUTPUT:
	cat ${PWD##*/}.out
	echo
else
	echo Error compiling.
fi
echo Done.
