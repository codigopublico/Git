
echo "script para compilar para windows/n"
echo ""
echo "archvivos a compilar    " $1
echo ""
echo "::::::::::::::::::::::::::::::::::::::::::Errores::::::::::::::::::::::::::::::::::::::::::::::::::::"
i586-mingw32msvc-g++ $1 -o win.exe

