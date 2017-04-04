mkdir -Force build
cd build
cmake .. -G "Visual Studio 15" "-DCMAKE_TOOLCHAIN_FILE=$Home\Codice\vcpkg\scripts\buildsystems\vcpkg.cmake"
cmake --build . --target install
cd ..
