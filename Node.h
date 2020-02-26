#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <cmath>

class Node {
    bool isFloat(std::string &one, std::string &two) {
        std::string searchVal = ".";
        std::size_t findOne = one.find(searchVal);
        std::size_t findTwo = two.find(searchVal);

        bool isFloat = ((findOne != std::string::npos) 
        || (findTwo != std::string::npos));

        return (isFloat);
    }

    std::string binop(std::string &binOperator,std::string &one, std::string &two) {
        char switchVal = binOperator[0];
        switch(switchVal) {
            case '+':
                return isFloat(one, two) ? 
                std::to_string(std::stof(one) + std::stof(two)) : 
                std::to_string(std::stoi(one) + std::stoi(two));
            case '-':
                return isFloat(one, two) ? 
                std::to_string(std::stof(one) - std::stof(two)) : 
                std::to_string(std::stoi(one) - std::stoi(two));
            case '/':
                return isFloat(one, two) ? 
                std::to_string(std::stof(one) / std::stof(two)) : 
                std::to_string(std::stoi(one) / std::stoi(two));
            case '*':
                return isFloat(one, two) ? 
                std::to_string(std::stof(one) * std::stof(two)) : 
                std::to_string(std::stoi(one) * std::stoi(two));
            case '^':
                return isFloat(one, two) ? 
                std::to_string(
                    std::pow(std::stof(one), std::stof(two))) : 
                std::to_string(
                    std::pow(std::stoi(one), std::stoi(two)));

        }
    }

public:
    std::string tag, value;
    std::list<Node> children;
    Node(std::string t, std::string v) : tag(t), value(v) {}
    Node() { tag="uninitialised"; value="uninitialised"; }   // Bison needs this.
    void dump(int depth=0) {
        for(int i=0; i<depth; i++)
            std::cout << "  ";

        std::cout << tag << ":" << value << std::endl;
        for(std::_List_iterator<Node> i=children.begin(); i!=children.end(); i++) {
            (*i).dump(depth+1);
        }
    }

    void dumpToGraph(std::string &graphString, int &id) {
        int oldId = id;
        std::ostringstream ss;
        ss << id;
        graphString += "\n" + ss.str() + " [label=\"" + tag + ":" + value + "\"];";

        for(std::_List_iterator<Node> i=children.begin(); i!=children.end(); i++) {
            id++;
            ss.str("");
            ss << oldId << "->" << id << ";";
            graphString += "\n" + ss.str();
            (*i).dumpToGraph(graphString, id);

        }
    }

    std::string execute() {
        auto childrenIt = children.begin();
        std::string result;
        if(tag ==  "stream") {
            return (*childrenIt).execute();

        } else if( tag == "functioncall") {
            std::string functionName = (*childrenIt).execute();
            childrenIt++;
            result = (*childrenIt).execute();
            if(functionName == "print") {
                childrenIt++;
                std::cout << result << std::endl;
            }
            return result;
        } else if(tag == "prefixexp") {
            return (*childrenIt).execute();

        } else if(tag == "var") {
            return value;

        } else if(tag == "args") {
            return (*childrenIt).execute();

        } else if(tag == "explist") {
            return (*childrenIt).execute();

        } else if(tag == "binop") {
            std::string numberOne = (*childrenIt).execute();
            childrenIt++;
            std::string numberTwo = (*childrenIt).execute();
            std::cout << "Executing: " << numberOne << value << numberTwo << std::endl;
            return binop(value, numberOne, numberTwo);

        } else if(tag == "float" || tag == "int") {
            return value;
        }     
    }
};

