#include<iostream>
#include "../build/config.h"
using namespace std;

int main(int argc, char* argv[]){
    if (argc < 2) {
    // report version
    std::cout << argv[0] <<"Project name:" << PROJECT_NAME << " Version " << PROJECT_VERSION << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
   }
    cout<<"hello world 3333 " << argc;
    return 0;
}
