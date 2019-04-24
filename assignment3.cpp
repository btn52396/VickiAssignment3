#include <vector>       // std::vector
#include <string>       // string
#include <iostream>     // cout
#include <sstream>      // string stream

class Agent {
private:
    std::string agentId;
    std::string name;
    std::string phone;
    std::string homeAddress;

public:
    Agent(std::string agentId, std::string name, std::string phone, std::string homeAddress) {
        this->agentId = agentId;
        this->name = name;
        this->phone = phone;
        this->homeAddress = homeAddress;
    }

    ~Agent() {
        std::cout << " Agent destroyed @" << this << std::endl;
    }

    std::string objString(std::string msg = "") {
        std::stringstream sout;
        sout << msg << " Agent[ Name: " << name
             << ", this:" << this << " ]";
        return sout.str();
    }
};

class Client {
private:
    std::string clientId;
    std::string name;
    std::string phone;
    std::string homeAddress;

public:
    Client(std::string clientId, std::string name, std::string phone, std::string homeAddress) {
        this->clientId = clientId;
        this->name = name;
        this->phone = phone;
        this->homeAddress = homeAddress;
    }

    ~Client() {
        std::cout << " Client destroyed @" << this << std::endl;
    }

    std::string getClientId() {
        return this->clientId;
    }

    std::string getName() {
        return this->name;
    }

    std::string objString(std::string msg = "") {
        std::stringstream sout;
        sout << msg << " Client[ Name: " << name
             << ", this: " << this << " ]";
        return sout.str();
    }
};

class AgentClientRelationship {
private:
    Agent *agentPtr;
    std::vector<Client*> vclient;

public:
    AgentClientRelationship(Agent *agentPtr = nullptr) {
        this -> agentPtr = agentPtr;
    }

    ~AgentClientRelationship() {
        std::cout << " AgentClientRel destroyed @ " << this << std::endl; 
    }

    void addClient(Client *clientPtr) {
        vclient.push_back(clientPtr);
    }

    Client* findClientLocation(std::string clientId) {
        Client* c;
        for (int i = 0; i < vclient.size(); i++) {
            c = vclient.at(i);
            if (clientId == c->getClientId()) {
                return c;
            }
        }
        return nullptr;
    }

    std::string objString(std::string msg = "") {
        std::ostringstream cList;
        for (int i = 0; i < vclient.size(); i++) {
            cList << vclient.at(i) << ", ";
        }

        std::stringstream sout;

        sout << msg
             << "AgentCleintRel [ Agent:" << agentPtr
             << ", Clients: [" << cList.str()
             << "], this: " << this
             << " ]";

        return sout.str();
    }
};


int main() {
    Agent a1("A1", "Ben Franklin", "555-0001", "1 Main Aug Phylad");
    std::cout << a1.objString(" a1") << std::endl;

    Client c1("C100", "Happy Client 1", "555-0100", "1 Crenshaw CA");
    std::cout << c1.objString(" c1") << std::endl;

    Client c2("C200", "Happy Client 2", "555-0200", "7 Evalid Clov, OH");
    std::cout << c2.objString(" c2") << std::endl;

    AgentClientRelationship ac1(&a1);
    ac1.addClient(&c1);
    ac1.addClient(&c2);

    std::cout << ac1.objString(" ac1") << std::endl;

    // findClientLocation test
    std::string clientId = "C100";
    Client* c = ac1.findClientLocation(clientId);
    if (c != nullptr) {
        std::string name = c->getName();
        std::cout << " Name of client " << clientId << " is: " << name << std::endl;
    } else {
        std::cout << " Client not found " << std::endl;
    }

    std::cout << "\n All done!\n";

    return 0;
}
