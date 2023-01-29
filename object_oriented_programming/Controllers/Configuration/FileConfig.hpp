#ifndef FILE_CONFIG_HPP
#define FILE_CONFIG_HPP

#include "Config.hpp"
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

class FileConfig: public Config{

private:
    std::map<char, Player::command> defaultConfig();
    bool isCorrect(std::string command);

protected:
    std::ifstream file;
    
    std::map<std::string, Player::command> direction{
        {"UP", Player::UP},
        {"LEFT", Player::LEFT},
        {"DOWN", Player::DOWN},
        {"RIGHT", Player::RIGHT},
        {"QUIT", Player::QUIT},
    };

    Field* field;

public:
    FileConfig(std::string filename = "./Config.txt"){
        file.open(filename, std::ios::in);
    };

    ~FileConfig();

    std::map<char, Player::command> getConfig();
};
#endif