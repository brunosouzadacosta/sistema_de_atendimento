#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> senhasGeradas;
    queue<int> senhasAtendidas;
    int opcao;
    int senha = 1;

    do {
        cout << "Menu de Atendimento" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Gerar senha" << endl;
        cout << "2. Realizar atendimento" << endl;
        cout << "Senhas aguardando atendimento: " << senhasGeradas.size() << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 0:
                if(!senhasGeradas.empty()) {
                    cout << "Ainda existem senhas aguardando atendimento. Não é possível sair." << endl;
                }
                break;

            case 1:
                senhasGeradas.push(senha);
                cout << "Senha " << senha << " gerada." << endl;
                senha++;
                break;

            case 2:
                if(senhasGeradas.empty()) {
                    cout << "Nenhuma senha aguardando atendimento." << endl;
                } else {
                    int senhaAtendida = senhasGeradas.front();
                    senhasGeradas.pop();
                    senhasAtendidas.push(senhaAtendida);
                    cout << "Atendendo senha: " << senhaAtendida << endl;
                }
                break;

            default:
                cout << "Opcao invalida!" << endl;
        }

        cout << endl;

    } while(opcao != 0 || !senhasGeradas.empty());

    cout << "Quantidade de senhas atendidas: " << senhasAtendidas.size() << endl;
    cout << "Programa encerrado." << endl;

    return 0;
}
