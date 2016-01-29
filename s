# IN SHELL, RUN WITH:
#. s

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
name=$(python "$DIR/setup/start.py")

if [ ! "$?" = "0" ]; then
	echo An error occurred.
else
	echo Done.
fi

cd "$DIR/$name"
npp "$DIR/$name/$name.cpp"
