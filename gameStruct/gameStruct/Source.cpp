#include "Header.h"


int main() {
	char word[15];
	short opc = 0, counter = 0, counter2 = 0;
	string auxWord, auxWord2 = "", letterFind;
	string vector[15], auxVector[15];
	Nodo* lista = NULL;
	

	do{
		for (short i = 0; i < 15; i++) {//se inicializan el vector y el char con espacios
			vector[i] = "_";
			word[i] = ' ';

		}
		system("cls");
		cout << "*---------------------------*\n";
		cout << "|           Ahorcado        |\n";
		cout << "*---------------------------*\n";
		cout << endl;

		cout << " 1. ............... Play\n";
		cout << " 2. ............... Exit\n";
		cin >> opc;

		switch (opc){
		case 1:
			cout << "Give me your secret word!\n";// se introduce la palabra ha adivinar mas adelante
			cin >> word;

			system("cls");
			
			auxWord = word; // se guarda la palabra del char en un string para saber cuantas letras debemos iterar
			
			
			

			for (short i = auxWord.size(); i >= 0; i--) {
				lista->push(lista, word[i]); // se manda una por una cada letra de la palabra a nuestra lista
				//ejemplo: lista-> p -> e -> r -> r -> o -> NULL;

			}
			
			do{
				system("cls");
				cout << "Contador: " << counter << "\n";// Lleva la cuenta de errores, max 11
				cout << "Your word: ";
				for (short i = 0; i < auxWord.size(); i++){
					cout << vector[i]<<" ";//mostramos las letras acertadas
				}
				cout << endl;
				cout << "Tell me a letter: "; //preguntamos y guardamos la letra
				cin >> letterFind;
				
				if (lista->find(lista, letterFind)) {//usamos el metodo find a ver si hay coincidencias con en nuestra lista
					cout << "Good\n";
					for (short i = auxWord.length(); i >= 0; i--) {
						string s;
						s.push_back(word[i]);//se convierte un char en string para poder comparar las letras
						if (s._Equal(letterFind)) {
							vector[i] = word[i]; // se guarda en el vector [i] la letra encontrada; 
						}


					}

				}
				else {
					if (counter == 11) {
						cout << "ups! You were hanged\n";//se pierde el juego al contador llegar a 11;

					}
					else {
						cout << "sorry, try again!\n";
					}
					
					counter++;
				}
				for (short i = 0; i < auxWord.size(); i++){
					auxVector[i] = word[i]; //en nuetro  vector aux se guarda la respuesta del juego
				}
				
				for (short i = 0; i < auxWord.size(); i++){
					
					if (vector[i] == auxVector[i]) { //se compara lo que lleva nuestro vector con aux que tiene la respuesta en el, ejemplo p_rr_ == perro
						counter2++;// si esto se cumple el número de veces que conforman el tamaño de la palabra en este caso perro tiene 5, esto significa que hemos ganado
					}

				}
				if (counter2 == auxWord.size()) {//comparamos los tamaños
					cout << "You win!!!!" << endl;
					cout << "word: " << auxWord << endl;
					counter = 12;
				}
				else {
					counter2 = 0;
				}

			
				
				system("pause");
			} while (counter < 12);
			counter = 0;//se reinician los contadores para volverse a utilizar
			counter2 = 0;
			while (lista != NULL) {// se eliminan elementos de la lista despues de adivinar la palabra
				string dato = lista->getWord();
				lista->pop(lista, dato);

			}

			break;

		default:
			cout << "Incorrect value\n";
			break;
		}
		system("pause");
	} while (opc < 2 );

	return 0;
}

