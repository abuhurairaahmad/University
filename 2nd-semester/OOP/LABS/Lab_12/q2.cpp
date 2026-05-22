#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream out("file_org.txt");
    if(out.is_open()){
        out << "This is some data that should be cpied to another file." << endl;
        out.close();
    }

    ifstream in("file_org.txt");
    ofstream out_copy("file_copy.txt");
    
    if(in.is_open() && out_copy.is_open()){
        string line;
        while(getline(in, line)){
            out_copy << line << endl;
        }
        in.close();
        out_copy.close();
    }

    return 0;
}
