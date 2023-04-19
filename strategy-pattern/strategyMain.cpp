#include <iostream>
#include <string>

class GreetingStrategy{
public:    
    virtual void greet(const std::string & name) const = 0;
    virtual ~GreetingStrategy() {};
};

class NormalGreetingStrategy : public GreetingStrategy{
public:
    void greet(const std::string & name) const{
        std::cout << "Hi " << name << ", how are you?\n";
    }
};

class InformalGreetingStrategy : public GreetingStrategy{
public:    
    void greet(const std::string & name) const{
        std::cout << "Hey " << name << ", what's up?\n";
    }
};

class FormalGreetingStrategy : public GreetingStrategy{
public:     
    void greet(const std::string & name) const{
        std::cout << "Good morning " << name << ", how do you do?\n";
    }
};

class Client{
private:
    GreetingStrategy* greetingStrategy;
public:
    Client(GreetingStrategy* greetingStrategy) : 
        greetingStrategy (greetingStrategy) {}

    ~Client () { delete greetingStrategy; }

    void greet(const std::string & name) const{
        greetingStrategy -> greet(name);
    }    
};

int main(void){
    Client businessClient( new FormalGreetingStrategy());
    Client coolClient( new InformalGreetingStrategy());
    Client normalClient( new NormalGreetingStrategy());

    businessClient.greet("Ahmet Bey");
    coolClient.greet("Ali");
    normalClient.greet("Merve");
    
    return EXIT_SUCCESS;
}