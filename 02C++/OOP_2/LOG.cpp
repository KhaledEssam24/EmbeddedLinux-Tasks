#include <iostream>
#include <vector>
#include <sstream>

enum class Level_t {WARN,INFO,ERROR,DEBUG};
class LOG {
public:
    friend std::ostream& operator<<(std::ostream& os,const Level_t &level);
    std::ostream& Level(const Level_t &level);
    void store(const std::string& message);
    void dumpAll();

private:
    static std::vector<std::string> logBuffer;
};

std::vector<std::string> LOG::logBuffer;

std::ostream& operator<<(std::ostream& os,const Level_t &level){
    switch (level) {
        case Level_t::DEBUG: os << "[DEBUG]: "; break;
        case Level_t::INFO:  os << "[INFO]: " ; break;
        case Level_t::WARN:  os << "[WARN]: " ; break;
        case Level_t::ERROR: os << "[ERROR]: "; break;
    }
    return os;
}

std::ostream& LOG::Level(const Level_t &level){
    std::ostringstream oss;
    oss << level;
    logBuffer.push_back(oss.str());
    return std::cout<<level;
}

void LOG::store(const std::string& message) {
    if (!logBuffer.empty()) {
        logBuffer.back() += message;
    } else {
        logBuffer.push_back(message);
    }
}

void LOG::dumpAll() {
    for (std::string msg : logBuffer)
    {
        std::cout<<msg<<std::endl;
    }
}

int main(){
    LOG log;
    log.Level(Level_t::DEBUG) << "This is a debug message." << std::endl;
    log.store("This is a debug message.");
    log.Level(Level_t::WARN) << "This is a warning message." << std::endl;
    log.store("This is a warning message.");
    log.Level(Level_t::INFO) << "This is a Info message." << std::endl;
    log.store("This is a Info message.");
    log.Level(Level_t::ERROR) << "This is a error message." << std::endl;
    log.store("This is a error message.");  
    std::cout<<"------------------------------"<<std::endl;
    log.dumpAll();
    return 0;
}
