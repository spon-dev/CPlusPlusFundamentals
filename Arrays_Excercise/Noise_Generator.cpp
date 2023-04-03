#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

string generateNoise(int length) {
    string noise = "";
    string possibleChars = "!@#$%^&*()_+-=[]{}|;':\",./<>?\\abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < length; i++) {
        noise += possibleChars[rand() % possibleChars.length()];
    }

    return noise;
}

string insertNoiseBetweenDigits(int number) {
    string numberString = to_string(number);
    string noisyNumber = "";

    for (size_t i = 0; i < numberString.length(); i++) {
        noisyNumber += numberString[i];
        if (i < numberString.length() - 1) {
            int noiseLength = rand() % 3; // Adjust the maximum length of noise between digits (0 to 2 here)
            noisyNumber += generateNoise(noiseLength);
        }
    }

    return noisyNumber;
}

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    int number = rand() % 100 + 1; // Generate a random number between 1 and 100
    string noisyNumber = insertNoiseBetweenDigits(number);

    int noiseLength = rand() % 10; // Generate a random noise length between 0 and 9
    string noiseBefore = generateNoise(noiseLength); // Generate random noise before the number
    noiseLength = rand() % 10; // Generate another random noise length between 0 and 9
    string noiseAfter = generateNoise(noiseLength); // Generate random noise after the number

    string input = noiseBefore + noisyNumber + noiseAfter + ".";

    cout << "Input: " << input << endl;
    cout << "Expected Output: " << sqrt(number) << endl;

    return 0;
}
