@echo on

REM git submodule update --init --recursive --remote

mkdir build
pushd build
cmake -G"Visual Studio 16" -A x64 ..
cmake --build . --config Release
popd

mkdir dist
copy build\win64\Release\brainfuck-module.dll dist
