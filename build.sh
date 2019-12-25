!#/bin/bash
echo "Building project..."
make
echo "Done compiling and linking"
echo "Moving statz to /bin..."
sudo cp ./bin/main /bin/statz
echo "Build completed!"
