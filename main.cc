#include<iostream>
#include<fstream>
#include "binary.tab.hh"
extern unsigned int total;
extern Node root;
void yy::parser::error(std::string const&err)
{
    root.dump();
    std::cout << "It's one of the bad ones... " << err << std::endl;
}

int main(int argc, char **argv)
{
  yy::parser parser;
  if(!parser.parse()) {
    std::cout << "Built a parse-tree:" << std::endl;
    root.dump();
    std::string graphString = "digraph {\n";
    int id = 0;
    root.dumpToGraph(graphString, id);
    graphString += "\n}";
    std::ofstream ofs;
    ofs.open("./source.dot", std::ofstream::trunc);
    ofs << graphString << std::endl;
    ofs.close();
/*     root.execute(); */
  }
  return 0;
}

