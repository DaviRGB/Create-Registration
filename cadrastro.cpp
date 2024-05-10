#include <bits/stdc++.h>
#include "DefensoriaPublica.h"
#include "validacao.h"

using namespace std;


void cadrastarAssistido(DefensoriaPublica& defensoria){
    cout << "Digite o nome do Assistido\n\n";
    string nome, CPF, email, endereco, Telefone; 
    cin.ignore();
    getline(cin, nome);
    cout << "\nDigite o CPF do Assistido, (sem os pontos e o traco)\n\n";
    int x;

    if(defensoria.search(CPF, x)) {
        cout << "Desculpe Assistido com CPF " << CPF << " ja existe.\n";
        cout << "Consulte o mesmo para mais informaçoes.\n";
        this_thread::sleep_for(chrono::seconds(3));
        system("cls");
        return;
    }

    while (true) {
        getline(cin, CPF);
        if (!validarCPF(CPF)) {
            cout << "O CPF deve ter 11 digitos. Por favor, tente novamente." << endl;
        } else {
            break;
        }
    }

    string CPF2;
    CPF2 = CPF.substr(0, 3) + '.' + CPF.substr(3, 3) + '.' + CPF.substr(6, 3) + '-' + CPF.substr(9, 2);
    //cout << CPF << " " << CPF2 << endl;
    
    cout << "\nDigite o E-mail do Assistido\n\n";
    while(true) {
        getline(cin, email);
        if(!validarEmail(email)) {
            cout << "E-mail nao valido, porfavor digite um e-mail valido\n";
            continue;
        }
        break;
    }
    cout << "\nDigite o Endereco do Assistido\n\n";
    getline(cin, endereco);

    cout << "\nDigite o Telefone do Assistido com o exemplo XX XXXXXXXXX\n\n";
    while (true) {
        getline(cin, Telefone);
        if(!validarNumeroCelular(Telefone)){
            cout << "telefone celular invalido, porfavor digite um telefone celular valido\n";
            continue;
        }
        break;
    }

    int idade;
    string RGt;
    cout << "\nDigite a idade do Assistido\n\n";
    while (true) {
        if (!(cin >> idade)) {
            cout << "Porfavor infome uma idade valida\n";  
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if(idade < 0 || idade > 150) {
            cout << "Porfavor infome uma idade valida\n";
            continue;
        }
        break;
    }

    cout << "\nDigite o numero do RG do Assistido\n\n";
    while (true) {
        cin >> RGt;
        if (RGt.size() != 7 || !all_of(RGt.begin(), RGt.end(), ::isdigit)){
            cout << "Numero de RG invalido, Por favor, digite os 7 digitos do RG\n";
        } else {
            break;
        }
    }
    int RG = stoi(RGt);
    defensoria.cadrastroDeAssistidos(nome, CPF2, email, endereco, Telefone, idade, RG);
    this_thread::sleep_for(chrono::seconds(3));
    system("cls");
}

void consultarAssistido(DefensoriaPublica& defensoria) {
    cout << "Digite o CPF do Assistido para consultar os dados\n";
    string CPF;
    cin >> CPF;
    string CPF2;
    CPF2 = CPF.substr(0, 3) + '.' + CPF.substr(3, 3) + '.' + CPF.substr(6, 3) + '-' + CPF.substr(9, 2);
    system("cls");
    defensoria.consultarAssistido(CPF2);
    this_thread::sleep_for(chrono::seconds(10));
    system("cls");
}

void editarAssistido(DefensoriaPublica& defensoria) {
    cout << "Digite o CPF do assistido que deseja alterar os dados:\n";
    string CPF; cin >> CPF;
    string CPF2;
    CPF2 = CPF.substr(0, 3) + '.' + CPF.substr(3, 3) + '.' + CPF.substr(6, 3) + '-' + CPF.substr(9, 2);
    system("cls");
    defensoria.editarAssistido(CPF2);
    this_thread::sleep_for(chrono::seconds(3));
    system("cls");
}

void excluirAssistido(DefensoriaPublica& defensoria) {
    cout << "Digite o CPF do Assistido que deseja excluir\n";
    string CPF; cin >> CPF;
    string CPF2;
    CPF2 = CPF.substr(0, 3) + '.' + CPF.substr(3, 3) + '.' + CPF.substr(6, 3) + '-' + CPF.substr(9, 2);
    defensoria.excluirAssistido(CPF2);
    this_thread::sleep_for(chrono::seconds(3));
    system("cls");
    //defensoria.imprime(); cout << "\n\n";
}

int main() {
    DefensoriaPublica defensoria; 
    int opcao = 0;

    while(true) {
        cout << "                Defensoria Publica              \n";
        cout << "  1: Deseja Cadastrar Assistido \n";
        cout << "  2: Deseja Consultar Assistido \n";
        cout << "  3: Deseja Editar Cadastro do Assistido\n";
        cout << "  4: Deseja Excluir Assistido\n"; 
        cout << "  5: Sair\n";
        cout << "  Digite a opcao desejada\n";

        try {
            cin >> opcao;
            if(cin.fail()) {
                cin.clear();
                cin.ignore();
                throw runtime_error("Entrada Invalida. Digite apenas numeros vaii ;)\n");
            }

            if(opcao == 1) {
                cadrastarAssistido(defensoria);
            }

            else if(opcao == 2) {
               consultarAssistido(defensoria);
            }
            else if(opcao == 3) {
                editarAssistido(defensoria);
            }

            else if(opcao == 4) {
                excluirAssistido(defensoria);
            }

            else if(opcao == 5) {
                cout << "          ENCERRANDO PROGRAMA ;)     \n";
                break;
            } else {
                throw runtime_error("Opcao invalida. Escolha uma opcao valida, digite algo valido vaii ;)\n");
                
            }
        } catch(const exception& e) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Erro: " << e.what() << '\n';
            this_thread::sleep_for(chrono::seconds(1));
            system("cls");
        }
    }
    return 0;
}
