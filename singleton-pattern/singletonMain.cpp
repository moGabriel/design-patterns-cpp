#include <iostream>
#include <string>

class Leader{
private:
    static Leader* _leader;

    Leader(){
        std::cout << "New Leader Constructed\n";
    }    

public:
    static Leader* getLeader(){
        if (_leader == NULL){
            _leader = new Leader;
        }

        return _leader;
    }

    void giveSpeech(const std::string name)const {
        std::cout << "I am addressing the public: " << name << std::endl;
    }    
};

Leader* Leader::_leader = NULL;

int main(void){

    Leader::getLeader()->giveSpeech("First Leader !!!!!!!");

    Leader* elected = elected->getLeader();
    elected->giveSpeech("elected");

    Leader* newElected = newElected->getLeader();
    elected->giveSpeech("newElected");

    Leader* againElected = elected->getLeader();
    elected->giveSpeech("againElected");

    Leader* lastElected = elected->getLeader();
    elected->giveSpeech("lastElected");

    return EXIT_SUCCESS;
}