#include "message.hpp"

LogType Message::get_prefix(){
    return type;
}

std::string Message::get_time_message(){
    return message_time;
}

std::string Message::get_message(){
    return message;
}

Message::Message(LogType type, std::string msg):type(type), message(std::move(msg)){
    auto now = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(now);
    char mbstr[100];
    // struct tm timeinfo;
    // localtime_s(&timeinfo, &end_time);
    std::strftime(mbstr, 100, "%d/%m/%Y %T", localtime(&end_time));
    this->message_time = std::string(mbstr);
}

std::ostream& operator<<(std::ostream& out, Message& message){
    out << message.prefixs.at(message.get_prefix()) << '\t' << message.get_time_message() << '\t' << message.get_message();
    return out;
}

