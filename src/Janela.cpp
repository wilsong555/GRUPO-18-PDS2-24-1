/*#include "Janela.hpp"

Janela::Janela(int largura, int altura, string titulo) {
    janela.create(sf::VideoMode(largura, altura), titulo);
};
    

    void Janela::mostrar() {
        while (janela.isOpen()) {
            sf::Event evento;
            while (janela.pollEvent(evento)) {
                if (evento.type == sf::Event::Closed)
                    janela.close();
            }

            janela.clear();
            // Aqui você pode adicionar código para desenhar objetos na janela
            janela.display();
        }
    }

    void Janela::fechar() {
        if (janela.isOpen()) {
            janela.close();
        }
    }*/