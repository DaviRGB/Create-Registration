#include <bits/stdc++.h>

using namespace std;

class assistido{
private:
    string nome, CPF, email, endereco, Telefone;
    int idade, Numero_do_RG;

public:
    assistido(string Nome, string cpf, string ema, string ende, string tele, int ida, int RG) : nome(Nome), CPF(cpf), email(ema), endereco(ende), Telefone(tele), idade(ida), Numero_do_RG(RG){}

    string getNome() const {
        return nome;
    }
    void setNome(const string& novoNome) {
        nome = novoNome;
    }

    string getCPF() const {
        return CPF;
    }

    string getEndereco() const {
        return endereco;
    }
    void setEndereco(const string& novoEndereco) {
        endereco = novoEndereco;
    }

    string getTelefone() const {
        return Telefone;
    }
    void setTelefone(const string& novoTelefone) {
        Telefone = novoTelefone;
    }
    string getEmail() const {
        return email;
    }
    void setEmail(const string& novoEmail) {
        email = novoEmail;
    }

    int getIdade() const {
        return idade;
    }
    void setIdade(const int& novaIdade) {
        idade = novaIdade;
    }

    int getRG() const {
        return Numero_do_RG;
    }
    void setRG(const int& novoRG) {
        Numero_do_RG = novoRG;
    }
};