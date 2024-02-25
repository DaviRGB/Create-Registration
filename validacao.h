#include <bits/stdc++.h>

using namespace std;

bool validarCPF(const string& cpf) {
    if (cpf.size() != 11 || !std::all_of(cpf.begin(), cpf.end(), ::isdigit)) {
        return false;
    }

    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    int primeiroDigito = 11 - (soma % 11);
    if (primeiroDigito == 10 || primeiroDigito == 11) {
        primeiroDigito = 0;
    }
    if (cpf[9] - '0' != primeiroDigito) {
        return false;
    }

    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    int segundoDigito = 11 - (soma % 11);
    if (segundoDigito == 10 || segundoDigito == 11) {
        segundoDigito = 0;
    }
    if (cpf[10] - '0' != segundoDigito) {
        return false;
    }
    return true;
}

bool validarEmail(const string& email) {
    const regex pattern("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Z|a-z]{2,4}$");
    return regex_match(email, pattern);
}

bool validarNumeroCelular(const string& numero) {
    const regex pattern("^(\\d{2}\\s)?\\d{5}-?\\d{4}$");
    return regex_match(numero, pattern);
}