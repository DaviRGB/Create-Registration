#include <bits/stdc++.h>
#include "assistido.h"

using namespace std;

class DefensoriaPublica {
private:
    static const int MAXN = 300;
    assistido* assistidos[MAXN];
    int numeroAssistidos;

public:
    DefensoriaPublica() : numeroAssistidos(0){}
    ~DefensoriaPublica() {
        for(int i = 0; i < numeroAssistidos; i++) {
            delete assistidos[i];
        }
    }
    
    void cadrastroDeAssistidos(string NomeAssistido, string const CPFAssistido, string email, string enderecoAssistido, string Telefone, int IdadeAssistido, int RGAssistido) {
        if(numeroAssistidos < MAXN) {
            assistidos[numeroAssistidos++] = new assistido(NomeAssistido, CPFAssistido, email, enderecoAssistido, Telefone, IdadeAssistido, RGAssistido);
            //cout << numeroAssistidos;
            cout << " Assistido Cadastrado com Sucesso!!\n";
        }
        else {
            cout << " Limete de assistido cadastrados atigindo\n";
        }
    }
    void consultarAssistido(string CPF) const{
        for (int i = 0; i < numeroAssistidos; i++) {
            if (assistidos[i]->getCPF() == CPF) {
                cout << " - Nome: " << assistidos[i]->getNome() << "\n - CPF: " << assistidos[i]->getCPF();
                cout << "\n - RG: " << assistidos[i]->getRG() << "\n - Numero de Telefone: " << assistidos[i]->getTelefone() << "\n - Idade: " << assistidos[i]->getIdade();
                cout << "\n - E-mail: " << assistidos[i]->getEmail() << "\n - Endereco: " << assistidos[i]->getEndereco() << "\n\n\n";
                return;
            }
        }
        cout << "CPF nao encontrado." << "\n\n";
    }
    
    bool search(string CPF, int& index) {
        for(int i = 0; i < numeroAssistidos; i++) {
            if (assistidos[i]->getCPF() == CPF) {
                index = i;
                return true;
            }
        }
        return false;
    }
    void editarAssistido(string CPF) {
        int index; bool ok;

        if(search(CPF, index)) {
            while(true) {
                ok = false;
                cout << " - Nome: " << assistidos[index]->getNome() << "\n - Telefone: " << assistidos[index]->getTelefone();
                cout << "\n - RG: " << assistidos[index]->getRG() << "\n - Idade: " << assistidos[index]->getIdade();
                cout << "\n - E-mail: " << assistidos[index]->getEmail() << "\n - Endereco: " << assistidos[index]->getEndereco() << "\n\n";
                
                cout << "  Deseja alterar qual dos dados acima, Digite o campo que deseja ser alterado da forma que ele esta escrito\n";
                cout << "  Caso deseje sair digite Sair\n";
                try{
                    string opcao; cin >> opcao;
                    if(opcao == "Nome") {
                        string novonome; ok = true;
                        cout << "Digite o nome corretamente: ";
                        cin.ignore();
                        getline(cin, novonome);
                        assistidos[index]->setNome(novonome);
                    }
                    
                    else  if(opcao == "E-mail") {
                        string novoEmail; ok = true;
                        cout << "Digite o E-mail corretamente: ";
                        cin.ignore();
                        getline(cin, novoEmail);
                        assistidos[index]->setEmail(novoEmail);
                    }
                    
                    else if(opcao == "Endereco") {
                        string novoEndereco; ok = true;
                        cout << "Digite novo Endereco: ";
                        cin.ignore();
                        getline(cin, novoEndereco);
                        assistidos[index]->setEndereco(novoEndereco);
                    }

                    else if(opcao == "Telefone") {
                        string novoTelefone; ok = true;
                        cout << "Digite novo Telefone: ";
                        cin.ignore();
                        getline(cin, novoTelefone);
                        assistidos[index]->setTelefone(novoTelefone);
                    }
                    
                    else if(opcao == "RG") {
                        int novoRG; ok = true;
                        cout << "Digite novo Numero do RG: ";
                        cin >> novoRG;
                        assistidos[index]->setRG(novoRG);
                    }
                    
                    else if(opcao == "Idade") {
                        int novaIdade; ok = true;
                        cout << "Digite a nova idade: ";
                        cin >> novaIdade;
                        assistidos[index]->setIdade(novaIdade);
                    }

                    if(ok) {
                        cout << "Cadastro alterado com sucesso!!\n\n";
                        this_thread::sleep_for(chrono::seconds(3));
                        system("cls");
                    }
                    
                    else if(opcao == "Sair") {
                        return;
                    } else {
                        throw runtime_error("Opcao invalida. Escolha uma opcao valida, digite algo valido vaii ;)\n");
                    }
                } catch(const exception& e) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "Erro: " << e.what() << '\n';
                    this_thread::sleep_for(chrono::seconds(3));
                    system("cls");
                }
            }
        }
        else {
            cout << "Assistido com CPF " << CPF << " não encontrado.\n";
        }
    }

    void excluirAssistido(string CPF) {
        for (int i = 0; i < numeroAssistidos; i++) {
            if (assistidos[i]->getCPF() == CPF) {
                delete assistidos[i];
                assistidos[i] = assistidos[numeroAssistidos - 1];
                numeroAssistidos--;
                cout << "Assistido excluido com sucesso!" << endl;
                return;
            }
        }
        cout << "CPF nao encontrado para exclusao." << endl;
    }
    void imprimeTest() {
        for(int i = 0; i < numeroAssistidos; i++) {
            cout << assistidos[i]->getNome() << '\n';
        }
        
    }
};