#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iterator>

#include "../include/Command.hpp"

//std::string Command::execute( std::string cmd )
//{
//    std::string file_name = "./src/result.txt" ;
//    
//    // redirect output to file
//    std::system( ( cmd + " > " + file_name ).c_str() ) ;
//    
//    // open file for input, return string containing characters in the file
//    std::ifstream file(file_name) ;
//    return { std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>() } ;
//}

std::string Command::execute(std::string cmd)
{
    std::string data;
    FILE * stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream) {
         while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
        pclose(stream);
    }
    return data;
}
