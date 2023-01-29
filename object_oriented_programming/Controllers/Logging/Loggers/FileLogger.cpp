#include "FileLogger.hpp"

FileLogger::FileLogger(std::string filename){
    file.open(filename, std::ios_base::out | std::ios_base::app);
}

FileLogger::~FileLogger(){
    file.close();
}

void FileLogger::print(Message* msg){
    if(file.is_open()){
        file << *msg << '\n';
        file.flush();
    }else{
        std::cout << "File opening error. Unable to open 'Log.txt'\n";
    }
}