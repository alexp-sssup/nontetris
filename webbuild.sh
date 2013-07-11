rm -Rf webbuild/
mkdir webbuild/

cd webbuild/
cmake -DEMSCRIPTEN=1 -DCMAKE_TOOLCHAIN_FILE=~/homemade/emscripten/cmake/Platform/Emscripten_unix.cmake -DCMAKE_MODULE_PATH=~/homemade/emscripten/cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" ..
~/homemade/emscripten/emmake make VERBOSE=1
mv nontetris nontetris.bc

cp ../wshader.vert ../wshader.frag ../pieces/1.png ../pieces/2.png ../pieces/3.png ../pieces/4.png ../pieces/5.png ../pieces/6.png ../pieces/7.png .

~/homemade/emscripten/emcc -0x -O0 nontetris.bc Box2D/Box2D/libBox2D.so -o project.html --preload-file wshader.vert --preload-file wshader.frag --preload-file 1.png --preload-file 2.png --preload-file 3.png --preload-file 4.png --preload-file 5.png --preload-file 6.png --preload-file 7.png -s FORCE_GL_EMULATION=1
