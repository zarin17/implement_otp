



#include <iostream>

#include <string>

#include <bitset>

#include <random>


// Generate a random key

std::string generate_key(int length) {

    std::string key;

    std::random_device rd;

    std::mt19937 eng(rd());

    std::uniform_int_distribution<> distr(0, 255);

    for (int i = 0; i < length; i++) {

        key += static_cast<char>(distr(eng));

    }

    return key;

}


// Encrypt message using the One-Time Pad method

std::string encrypt(std::string message, std::string key) {

    std::string ciphertext;

    for (int i = 0; i < message.length(); i++) {

        char c = message[i] ^ key[i];

        ciphertext += c;

    }

    return ciphertext;

}


// Decrypt ciphertext using the One-Time Pad method

std::string decrypt(std::string ciphertext, std::string key) {

    std::string message;

    for (int i = 0; i < ciphertext.length(); i++) {

        char c = ciphertext[i] ^ key[i];

        message += c;

    }

    return message;

}


int main() {

    std::string message = "Hello World!";

    std::string key = generate_key(message.length());

    std::string ciphertext = encrypt(message, key);

    std::string decrypted = decrypt(ciphertext, key);


    std::cout << "Original Message: " << message << std::endl;

    std::cout << "Key: " << key << std::endl;

    std::cout << "Ciphertext: " << ciphertext << std::endl;

    std::cout << "Decrypted Message: " << decrypted << std::endl;


    return 0;

}







