#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string.h>

using namespace std;

string generatePass (unsigned len){

    srand(time(0));
    string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string newstr;
    int pos;
    while(newstr.size() != len) {
        pos = ((rand() % (str.size() - 1)));
        newstr += str.substr(pos,1);
    }
    return newstr;
}

void generateFile (string pass, string filename){
    char temp[1024];
    strcpy(temp, filename.append(".txt").c_str());
    ofstream outfile(temp);
    outfile << pass << std::endl;
    outfile.close();
}

using namespace std;

int main()
{
    unsigned size_password;
    string password;
    char option;
    string filename;
    while(1){
        cout << "Tamanho da senha: \n";
        cin >> size_password;
        if (!size_password)break;
        password = generatePass(size_password);
        cout << "Senha: \n"; cout << password <<endl;
        cout << "Deseja gerar o arquivo contendo a senha? [S/N]\n";
        cin >> option;
        if (option == 'S' or option == 's'){
            cout << "Digite o arquivo de saída: ";
            cin >> filename;
            generateFile(password,filename);
        }
    }
    return 0;
}
