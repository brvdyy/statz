!#/bin/bash
echo "Building project..."
mkdir bin
make
echo "Done compiling and linking"
echo "Moving statz to /bin..."
sudo cp ./bin/main /bin/statz
echo "Build completed!"
