#include "CartasHeroi.h"
#include <iostream>
#include <string>
#include <stack>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <thread>

void inverte_pilhaH(std::stack<Heroi> *pilha) {
    std::stack<Heroi> stack_temp_1;
    std::stack<Heroi> stack_temp_2;

    while (!pilha->empty()){
        stack_temp_1.push(pilha->top());
        pilha->pop();
    }
    while (!stack_temp_1.empty()){
        stack_temp_2.push(stack_temp_1.top());
        stack_temp_1.pop();
    }
    while (!stack_temp_2.empty()){
        pilha->push(stack_temp_2.top());
        stack_temp_2.pop();
    }
}

int compara_cartasH(Heroi carta1, Heroi carta2, std::string atributo) {
    if (atributo.compare("1") == 0) {
        if ((carta1.get_velocidade() - carta2.get_velocidade()) != 0)
            return carta1.get_velocidade() - carta2.get_velocidade();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());
    }
    else if (atributo.compare("2") == 0) {
        if ((carta1.get_inteligencia() - carta2.get_inteligencia()) != 0)
            return carta1.get_inteligencia() - carta2.get_inteligencia();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());
    }
    else if (atributo.compare("3") == 0) {
        if ((carta1.get_agilidade() - carta2.get_agilidade()) != 0)
            return carta1.get_agilidade() - carta2.get_agilidade();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());

    }
    else if (atributo.compare("4") == 0) {
        if ((carta1.get_forca() - carta2.get_forca()) != 0)
            return carta1.get_forca() - carta2.get_forca();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());
    }
    else if (atributo.compare("5") == 0) {
    	if ((carta1.get_habilidade() - carta2.get_habilidade()) != 0)
    		return carta1.get_habilidade() - carta2.get_habilidade();
        else
        	return carta2.get_tipo().compare(carta1.get_tipo());
    }

    return 0;
}

void jogada_playerH(std::stack<Heroi> *pilha_jogador, std::stack<Heroi> *pilha_adversario) {
    Heroi carta_jogador = pilha_jogador->top();
    Heroi carta_adversario = pilha_adversario->top();

    int player_atual1 = 1;
    int player_adversario;

    if (player_atual1 == 2)
        player_adversario = 1;
    else
        player_adversario = 2;

    std::cout << std::endl << "[NOVA JOGADA]" << std::endl;
    std::cout << "PLAYER " << player_atual1 << std::endl;
    std::cout << std::endl << "CARTA PLAYER " << player_atual1 << std::endl;
    carta_jogador.imprime_carta();

    if (carta_jogador.get_super_trunfo() == true) {
        std::cout << "[EH TRUNFO]" << std::endl;
        std::cout << std::endl << "CARTA PLAYER " << player_adversario << std::endl;
        carta_adversario.imprime_carta();

        if(carta_adversario.get_tipo().substr(0,1).compare("A") == 0) {
            std::cout << std::endl << "PLAYER " << player_adversario << " Vencedor da Rodada]" << std::endl;

            Heroi temp = pilha_adversario->top();
            pilha_adversario->pop();
            inverte_pilhaH(pilha_adversario);
            pilha_adversario->push(pilha_jogador->top());
            pilha_adversario->push(temp);
            pilha_jogador->pop();
            inverte_pilhaH(pilha_adversario);
            player_atual1 = player_adversario;
        }else {
            std::cout << std::endl << "[PLAYER " << player_atual1 << " Vencedor da Rodada]" << std::endl;

            Heroi temp = pilha_jogador->top();
            pilha_jogador->pop();
            inverte_pilhaH(pilha_jogador);
            pilha_jogador->push(pilha_adversario->top());
            pilha_jogador->push(temp);
            inverte_pilhaH(pilha_jogador);
            pilha_adversario->pop();
        }
    }else {

        std::string atributo;

        std::cout << "Selecione um Atributo [1 | 2 | 3 | 4 | 5 ]: ";
        std::cin >> atributo;

        while(!valida_atributoH(atributo)) {
            std::cin.clear();
            std::cin.ignore();

            std::cout << "ATRIBUTO INVALIDO!" << std::endl;
            std::cout << "Selecione um Atributo [1 | 2 | 3 | 4 | 5 ]: ";
            std::cin >> atributo;
        }

        std::cout << "ATRIBUTO ESCOLHIDO: " << atributo << std::endl;
        std::cout << std::endl << "CARTA PLAYER " << player_adversario << std::endl;
        carta_adversario.imprime_carta();

        if(compara_cartasH(carta_jogador, carta_adversario, atributo) > 0) {
            std::cout << std::endl << "[PLAYER " << player_atual1 << " Vencedor da Rodada]" << std::endl;

            Heroi temp = pilha_jogador->top();
            pilha_jogador->pop();
            inverte_pilhaH(pilha_jogador);
            pilha_jogador->push(pilha_adversario->top());
            pilha_jogador->push(temp);
            inverte_pilhaH(pilha_jogador);
            pilha_adversario->pop();
        }else {
            std::cout << std::endl << "[PLAYER " << player_adversario << " Vencedor da Rodada]" << std::endl;

            Heroi temp = pilha_adversario->top();
            pilha_adversario->pop();
            inverte_pilhaH(pilha_adversario);
            pilha_adversario->push(pilha_jogador->top());
            pilha_adversario->push(temp);
            inverte_pilhaH(pilha_adversario);
            pilha_jogador->pop();
            player_atual1 = player_adversario;
        }
    }
}

bool valida_atributoH(std::string atributo) {
    if (atributo.compare("1") == 0)
        return true;
    else if (atributo.compare("2") == 0)
        return true;
    else if (atributo.compare("3") == 0)
        return true;
    else if (atributo.compare("4") == 0)
        return true;
    else if (atributo.compare("5") == 0)
    	return true;
    else
        return false;
}