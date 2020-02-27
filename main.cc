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
  std::ifstream t(argv[1]);
  std::stringstream buffer;
  buffer << "label=<";
  buffer << t.rdbuf();
  buffer << ">;labelloc = \"t\"\n";
  yy::parser parser;
  if(!parser.parse()) {
    std::cout << "Built a parse-tree:" << std::endl;
    root.dump();
    std::string graphString = "digraph {\n";
    graphString += buffer.str();
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

