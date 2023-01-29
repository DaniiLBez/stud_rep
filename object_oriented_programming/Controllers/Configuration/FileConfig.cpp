#include "FileConfig.hpp"

FileConfig::~FileConfig(){
    file.close();
}

std::map<char, Player::command> FileConfig::getConfig(){
    
    std::map<char, Player::command> config;

    if(!file.is_open()){
        throw std::runtime_error("Enable to open Config file");
    }

    std::string line;

    while(getline(file, line)){
        std::istringstream stream(line);
 
        std::string command;
        char key;

        stream >> command;
        stream >> key;

        if(config.find(std::tolower(key)) == config.end()){
            if(isCorrect(command)){
                config[std::tolower(key)] = direction.at(command);
            }else{
                config = defaultConfig();
                break;
            }
        }
    }
    if(config.size() != 5){
        config = defaultConfig();
        return config;
    }
    return config;
}

bool FileConfig::isCorrect(std::string command){
    if(this->direction.find(command) == this->direction.end()){
        return false;
    }
    return true;
}

std::map<char, Player::command> FileConfig::defaultConfig(){
    return std::map<char, Player::command>{
        {'w', Player::UP},
        {'a', Player::LEFT},
        {'s', Player::DOWN},
        {'d', Player::RIGHT},
        {'q', Player::QUIT},
    };
}