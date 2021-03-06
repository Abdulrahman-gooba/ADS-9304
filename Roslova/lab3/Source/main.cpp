#include <iostream>
#include <fstream>
#include <memory>

#include "Node.h"
#include "Tree.h"



int main(int argc, char* argv[]){

    setlocale(LC_ALL, "ru");

    if(argc != 2){
        std::cout << "Неверное кол-во аргуметов!" << std::endl;
        return -1;
    }

    std::fstream file(argv[1]);

    if(!file){
        std::cout << "Файл " << argv[0] << " не может быть открыт на чтение!" << std::endl;
        return -1;
    }

    std::string structTree {};
    std::string levelFind {};
    getline(file, structTree);
    getline(file, levelFind);

    file.close();
     
    std::unique_ptr<Tree<char>> myTree(new Tree<char>(structTree));

    if(myTree->getArr().size() == 0){
        std::cout << "Неверная структура дерева!" << std::endl;
        return -1;
    }
    
    //myTree->removeNode(0);
    //myTree->addNode('p');
    myTree->findLeafs();
    myTree->nodesOnLevel(levelFind);
    //myTree->lkp();


    return 0;
}