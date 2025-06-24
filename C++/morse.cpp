/*
    Puntos
    - Cada caracter esta separado por un espacio
    - Cada palabra esta separado por 3 espacios
    - Espacios adicionales al iniciar o finalizar el codigo deben de ser ignorados.
*/

#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> convert_in_vector(const std::string &code);
void printVector(const std::vector<std::string> &vector);

std::vector<std::string> alphabethMorse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".-.-.-"};
std::vector<std::string> special_characters_morse = {};
std::vector<std::string> numbers_morse = {};
std::vector<std::string> alphabet = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "."};
std::vector<std::string> special_characters = {};
std::vector<std::string> numbers = {};

std::string decodeMorse(const std::string &morseCode)
{
    std::string decode = "";
    std::vector<std::string> vector = convert_in_vector(morseCode);
    int n = vector.size();
    int i = 0;
    while( i < n) {
        if(vector[i] != " ") {
            int match;
            for(int j = 0; j < alphabethMorse.size(); j++) {
                if(alphabethMorse[j] == vector[i]) {
                    match = j;
                    break;
                }
            }
            decode += alphabet[match];
        } else {
            decode += " ";
        }
        i++;
    }

    return decode;
}

std::vector<std::string> convert_in_vector(const std::string &code) {
    std::vector<std::string> result;  // String dividido
    std::string current = "";         // Acumula caracteres morse
    int i = 0;
    int n = code.size();

    // 1. Ignorar espacios iniciales
    while (i < n && code[i] == ' ') {
        i++;
    }

    while (i < n) {
        if (code[i] == '.' || code[i] == '-') {
            // 2. Acumular puntos/guiones
            current += code[i];
            i++;
        } else if (code[i] == ' ') {
            // 3. Si hay caracteres acumulados, se guardan
            if (!current.empty()) {
                result.push_back(current);
                current = "";
            }

            // 4. Contar espacios consecutivos
            int spaceCount = 0;
            while (i < n && code[i] == ' ') {
                spaceCount++;
                i++;
            }

            // 5. Manejar separación de palabras (3+ espacios)
            if (spaceCount >= 3 && i < n) {
                result.push_back(" ");
            }
        }
    }

    // 6. Agregar último carácter si existe
    if (!current.empty()) {
        result.push_back(current);
    }

    return result;
}

void printVector(const std::vector<std::string> &vector) {
    std::cout << "vector >>> ";
    std::cout << "[ ";
    for (int i = 0; i < vector.size(); i++) {
        if(i != vector.size() - 1)
            std::cout << "\"" << vector[i] << "\", ";
        else
            std::cout << "\"" <<  vector[i] << "\" ]";

    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> testAlphabet = {".... . -.--   .--- ..- -.. ."};

    for(int i = 0; i < testAlphabet.size(); i++) {
        std::cout << "DECODE >>> " << decodeMorse(testAlphabet[i]);
        std::cout << std::endl << "CODE >>> " << testAlphabet[i];
    }
    return 0;
}