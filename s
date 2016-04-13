# s
# Wrapper around start.py with utility functionality

# best to run with ". s", so cd will work

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
name=$(python "$DIR/setup/start.py")

if [ ! "$?" = "0" ]; then
	echo An error occurred.
else
	echo Done.
fi

cd "$DIR/$name"
"C:\Program Files (x86)\Notepad++\notepad++.exe" "$DIR/$name/$name.cpp"
