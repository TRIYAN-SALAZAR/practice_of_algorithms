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
std::vector<std::string> search_code(const std::string &s);
void printVector(const std::vector<std::string> &vector);

std::vector<std::string> alphabethMorse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
std::vector<std::string> numbers_morse = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
std::vector<std::string> special_characters_morse = {".-.-.-", "--..--", "..--..", "-.-.--", "-..-.", "	.-...", "---...", "...-..-", ".--.-."};

std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
std::string special_characters = ".,?!/&:$";
std::string numbers = "0123456789";

std::string decodeMorse(const std::string &morseCode)
{
    std::string decode = "";
    std::vector<std::string> vector = convert_in_vector(morseCode);
    int n = vector.size();
    int i = 0;
    while (i < n)
    {
        if (vector[i] != " ")
        {
            std::vector<std::string> match = search_code(vector[i]);
            decode += match[1];
        }
        else
        {
            decode += " ";
        }
        i++;
    }

    return decode;
}

std::vector<std::string> search_code(const std::string &s)
{
    std::vector<std::string> found;
    for (int i = 0; i < alphabethMorse.size(); i++)
    {
        if (alphabethMorse[i] == s)
        {
            found.push_back(alphabethMorse[i]);
            found.push_back(std::string(1, alphabet[i]));
            return found;
        }
    }

    for (int j = 0; j < numbers_morse.size(); j++)
    {
        if (numbers_morse[j] == s)
        {
            found.push_back(numbers_morse[j]);
            found.push_back(std::string(1, numbers[j]));
            return found;
        }
    }

    for (int k = 0; k < special_characters_morse.size(); k++)
    {
        if (special_characters_morse[k] == s)
        {
            found.push_back(special_characters_morse[k]);
            found.push_back(std::string(1, special_characters[k]));
            return found;
        }
    }

    return found;
}

std::string encode_text(const std::string &text)
{
    std::string encode = "";
    bool firstChar = true;

    for (size_t i = 0; i < text.size(); ++i)
    {
        char x = tolower(text[i]);
        if (x == ' ')
        {
            encode += "   ";
            firstChar = true;
        }
        else
        {
            std::string morse;
            size_t idx = alphabet.find(x);
            if (idx != std::string::npos)
            {
                morse = alphabethMorse[idx];
            }
            else
            {
                idx = numbers.find(x);
                if (idx != std::string::npos)
                {
                    morse = numbers_morse[idx];
                }
                else
                {
                    idx = special_characters.find(x);
                    if (idx != std::string::npos)
                    {
                        morse = special_characters_morse[idx];
                    }
                }
            }
            if (!morse.empty())
            {
                if (!firstChar)
                    encode += " ";
                encode += morse;
                firstChar = false;
            }
        }
    }

    return encode;
}

std::vector<std::string> convert_in_vector(const std::string &code)
{
    std::vector<std::string> result; // String dividido
    std::string current = "";        // Acumula caracteres morse
    int i = 0;
    int n = code.size();

    // 1. Ignorar espacios iniciales
    while (i < n && code[i] == ' ')
    {
        i++;
    }

    while (i < n)
    {
        if (code[i] == '.' || code[i] == '-')
        {
            // 2. Acumular puntos/guiones
            current += code[i];
            i++;
        }
        else if (code[i] == ' ')
        {
            // 3. Si hay caracteres acumulados, se guardan
            if (!current.empty())
            {
                result.push_back(current);
                current = "";
            }

            // 4. Contar espacios consecutivos
            int spaceCount = 0;
            while (i < n && code[i] == ' ')
            {
                spaceCount++;
                i++;
            }

            // 5. Manejar separación de palabras (3+ espacios)
            if (spaceCount >= 3 && i < n)
            {
                result.push_back(" ");
            }
        }
    }

    // 6. Agregar último carácter si existe
    if (!current.empty())
    {
        result.push_back(current);
    }

    return result;
}

void printVector(const std::vector<std::string> &vector)
{
    std::cout << "vector >>> ";
    std::cout << "[ ";
    for (int i = 0; i < vector.size(); i++)
    {
        if (i != vector.size() - 1)
            std::cout << "\"" << vector[i] << "\", ";
        else
            std::cout << "\"" << vector[i] << "\" ]";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> testAlphabet = {".... . -.--   .--- ..- -.. . .-.-.-", ".... --- .-.. .-   -- ..- -. -.. ---", " -.-. .-. . ---   --.- ..- .   -.-- .-   -. ---   -- .   --. ..- ... - .-   ...- ..--.. ..--.."};
    std::vector<std::string> textToEncode = {"HEY JUDE", "HOLA MUNDO"};

    for (int i = 0; i < testAlphabet.size(); i++)
    {
        std::cout << "CODE >>> " << testAlphabet[i] << std::endl;
        std::cout << "DECODE >>> " << decodeMorse(testAlphabet[i]) << std::endl
                  << std::endl;
    }
    std::cout << std::endl
              << std::endl;

    for (int i = 0; i < textToEncode.size(); i++)
    {
        std::cout << "TEXT >>> " << textToEncode[i] << std::endl;
        std::cout << "ENCODE >>> " << (encode_text(textToEncode[i])) << std::endl
                  << std::endl;
    }

    return 0;
}