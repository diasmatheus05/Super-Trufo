#include "Dinossauro.h"
#include <iostream>
#include <string>

float Dinossauro::get_altura(){
	return altura;
}

float Dinossauro::get_peso(){
	return peso;
}

float Dinossauro::get_comprimento(){
	return comprimento;
}

int Dinossauro::get_viveu_ha(){
	return viveu_ha;
}

bool Dinossauro::get_super_trunfo(){
	return super_trunfo;
}

void Dinossauro::imprime_carta(){
	std::cout << "##########CARTA##########" << std::endl;
	std::cout << "# Nome: " << get_nome() << std::endl;
	std::cout << "# Tipo: " << get_tipo() << std::endl << std::endl;
	std::cout << "# 1 Altura: " << get_altura() << std::endl;
	std::cout << "# 2 Peso: " << get_peso() << std::endl;
	std::cout << "# 3 Comprimento: " << get_comprimento() << std::endl;
	std::cout << "# 4 Viveu ha: " << get_viveu_ha() << std::endl;
	std::cout << "#########################" << std::endl << std::endl;
}

void Dinossauro::set_altura(float altura){
	this-> altura = altura;
}

void Dinossauro::set_peso(float peso){
	this-> peso = peso;
}

void Dinossauro::set_comprimento(float comprimento){
	this-> comprimento = comprimento;
}

void Dinossauro::set_viveu_ha(int viveu_ha){
	this-> viveu_ha = viveu_ha;
}

void Dinossauro::set_super_trunfo(bool super_trunfo){
	this-> super_trunfo = super_trunfo;
}
