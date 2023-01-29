#include "game.hpp"
#include <stdlib.h>

void Game::run(){

    LoggerPool* pool = LoggerPool::getInstance();
    
    this->notify(LogType::INFO, "Game started");
    // std::string n_str, m_str;
    std::string common_field;

    std::cout << "Добро пожаловать в игру!" << std::endl;
    std::cout << "Выберите уровень (1/2): ";
    std::cin >> common_field;

    std::map<std::string, LevelStrategy*> levels{
        {"1", new TestLevel()},
        {"2", new FirstLevel()}
    };

    LevelStrategy* level = levels.at(common_field);
    field = level->generate();
    FieldLog(field, pool);
    field->react();
        
        // std::cout << "Введите размеры игрового поля: " << std::endl;
        
        // std::cin >> n_str >> m_str;

        // while (!(isNumeric(n_str) && isNumeric(m_str))){
        //     this->notify(LogType::ERROR, "Incorrect size of field entered.");
        //     std::cout << "Incorrect input. Try again\n";
        //     std::cin >> n_str >> m_str;
        // }
        
        // int n = std::stoi(n_str);
        // int m = std::stoi(m_str);

        // if(n >= 3 && m >= 3){
        //     field = new Field(n,m);
        //     std::string log_txt = "Built field with size:" +  std::to_string(n) + 'x' + std::to_string(m);
        //     this->notify(LogType::INFO, log_txt);
        // }else{
        //     std::cout<<"Incorrect size. Build default size (10x10)\n";
        //     field = new Field(10,10);
        //     this->notify(LogType::ERROR, "Incorrect size. Build default size (10x10)");
        // }
    
    //}else{
        // field = new Field();
        // FieldLog(field, pool);
        // EventLog* e_log = new EventLog(pool);
        // field->setEventLog(e_log);
        
        // EventAbstractFactory* factory = new EnemyFactory(field->getPlayer(), field);
        // Event* enemy = factory->createEvent();
        // field->e_log->subscribe(enemy);
        
        // factory = new ExitFactory(field);
        // Event* e_exit = factory->createEvent();
        // field->e_log->subscribe(e_exit);

        // factory = new PowerBuffFactory(field->getPlayer());
        // Event* pb = factory->createEvent();
        // field->e_log->subscribe(pb);

        // field->getField()[2][2].setImpassable();
        // field->getField()[1][0].setImpassable();
        // field->getField()[1][1].setEvent(enemy);
        // field->getField()[1][2].setEvent(pb);
        // field->getField()[1][3].setEvent(e_exit);

        // field->react();
        // this->notify(LogType::INFO, "Built default field");
    //}

    do{
        system("clear");
        fw.printField(*field);
        
        std::cout<<"|power=" << field->getPlayer()->getPower()<< "|HP=" << field->getPlayer()->getHP() <<"|points=" << field->getPlayer()->getPoints() << '|' << std::endl;
        mediator.notifyCommandReader();
        field->move(mediator.getControllerCommand());
        
        if(field->getState() == Field::WIN){
            this->notify(LogType::GAME, "Player win!");
            break;
        }

        if(field->getState() == Field::LOSE){
            this->notify(LogType::GAME, "Player lose!");
            break;
        }
        
    }while (mediator.getControllerCommand() != Player::QUIT);
    std::cout << "До встречи!" << std::endl;
    this->notify(LogType::INFO, "Game finished");
}

bool Game::isNumeric(std::string& input){
    std::string::const_iterator it = input.begin();
    while (it != input.end() && isdigit(*it)) it++;
    return !input.empty() && it == input.end();
}