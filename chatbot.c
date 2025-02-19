#include <stdio.h> 
#include <string.h> 
#include <ctype.h> // to include functions to remove case sensivity 
#include <stdlib.h> // to include functions like rand() and srand() 
#include <time.h> // to include functions like time() 


// Structure to store keywords and their responses


typedef struct {
    char keyword[300];
    char response[600];
} KeywordPair;


// converts the input into lowercase to remove case sensivity


void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}


// Function to return a random joke 


void tellJoke() {
    char *jokes[] = {
        "Why don’t skeletons fight each other? They don’t have the guts!",
        "Parallel lines have so much in common. It’s a shame they’ll never meet!",
        "Why did the scarecrow win an award? Because he was outstanding in his field!",
        "Why don’t some couples go to the gym? Because some relationships don’t work out!"
    };
    int numJokes = sizeof(jokes) / sizeof(jokes[0]);
    printf("Chitti: %s\n", jokes[rand() % numJokes]);
}


// Function to return a random riddle


void tellRiddle() {

    char *riddles[] = {
        "I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?",
        "The more of me you take, the more you leave behind. What am I?",
        "I am not alive, but I can grow. I don’t have lungs, but I need air. What am I?",
        "The person who makes it, sells it. The person who buys it never uses it. The person who uses it never knows they’re using it. What is it?"
    };
    int numRiddles = sizeof(riddles) / sizeof(riddles[0]);
    printf("Chitti: %s\n", riddles[rand() % numRiddles]);

}


// Function to return a random motivational quote


void tellQuote() {

    char *quotes[] = {
        "Success is not final, failure is not fatal: It is the courage to continue that counts.",
        "Believe you can and you're halfway there.",
        "The only way to do great work is to love what you do.",
        "Your time is limited, so don’t waste it living someone else’s life."
    };

    int numQuotes = sizeof(quotes) / sizeof(quotes[0]);
    printf("Chitti: %s\n", quotes[rand() % numQuotes]);

}


// Function to perform basic calculations


void calculator() {

    double num1, num2;
    char operator;
    printf("Chitti: Enter an expression (e.g., 5 + 3): ");
    scanf("%lf %c %lf", &num1, &operator, &num2);
    getchar(); // Clear newline from input buffer

    switch (operator) {
        case '+': printf("Chitti: Result = %.2lf\n", num1 + num2); break;

        case '-': printf("Chitti: Result = %.2lf\n", num1 - num2); break;

        case '*': printf("Chitti: Result = %.2lf\n", num1 * num2); break;
        
        case '/':

            if (num2 != 0)
                printf("Chitti: Result = %.2lf\n", num1 / num2);
            else
                printf("Chitti: Error! Division by zero.\n");
            break;
        default: printf("Chitti: Invalid operation!\n");
    }
}


// drivers code


int main() {
    srand(time(NULL)); // Initialize random seed
   
    KeywordPair keywords[] = {

        {"hello", "Hi there!"},
        
        {"hey", "Hello!"},

        {"hi", "Sup!"},

        {"how are you", "I'm doing well, thanks!"},

        {"what is your name", "I'm  chitti!"},

        {"suggest me some movies to watch", "Tell me a genre: Horror, Comedy, Sci-Fi, Adventure, Action, or Fantasy"},

        {"horror", "The Nun, The Conjuring, Insidious, Sinister, Hereditary, It, The Exorcist"},

        {"comedy", "Hangover, Home Alone, Superbad, Dumb and Dumber, Step Brothers, The Office (series)"},

        {"sci-fi", "Inception, Interstellar, Gravity, The Martian, Blade Runner 2049, Dune"},

        {"adventure", "The Hobbit, The Lord of the Rings, Jumanji, Indiana Jones, Pirates of the Caribbean"},

        {"action", "Fast and Furious, Avengers, John Wick, Mad Max, The Dark Knight, Gladiator"},

        {"fantasy", "Harry Potter, The Chronicles of Narnia, Spider-Man, Journey to the West, The Witcher (series)"},

        {"what is the meaning of life", "42, according to The Hitchhiker's Guide to the Galaxy!"},

        {"favorite programming language", "I have a soft spot for C, but Python is also cool!"},

        {"do you believe in ghosts", "I haven't seen one, but I hear they like the dark!"},

        {"what is the weather like", "I'm indoors, so I'm not sure!"},

        {"what is the time", "I don't have a watch, but I can tell you the time is now!"},

        {"what is the date", "Today is a great day to chat with you!"},

        {"what is the capital of India", "New Delhi, the land of spices and culture!"},

        {"what is the capital of the United States", "Washington, D.C., where the White House is!"},

        {"what is the capital of France", "Paris, the city of love and baguettes!"},

        {"what is the capital of Japan", "Tokyo, the land of sushi and cherry blossoms!"},

        {"what is the capital of Australia", "Canberra, the home of kangaroos and koalas!"},

        {"what is the capital of China", "Beijing, the land of the Great Wall and pandas!"},

        {"what is the capital of Russia", "Moscow, the city of onion domes and Red Square!"},

        {"what is the capital of Brazil", "Brasília, the land of samba and soccer!"},

        {"what is the capital of Canada", "Ottawa, the home of maple syrup and hockey!"},

        {"what is the capital of South Africa", "Pretoria, the land of safaris and Nelson Mandela!"},

        {"what is the capital of Germany", "Berlin, the city of history and currywurst!"},
        
        {"what is the capital of Italy", "Rome, the city of pasta and the Colosseum!"},

        {"what is the capital of Spain", "Madrid"},

        {"what is love", "Baby, don't hurt me!"},

        {"what is your favorite color", "I like binary—black and white!"},

        {"do you dream", "Only about electric sheep."},

        {"where are you from", "I exist in the digital world!"},

        {"what's up", "Not much, just chatting with you!"},

        {"do you like music", "Yes! I enjoy anything with a good rhythm."},

        {"can you dance", "I can make your screen blink—does that count?"},

        {"are you human", "Nope, I am 100 percent a chatbot!"},

        {"do you sleep", "I don't, but I can pretend to!"},

        {"do you have a pet", "Not yet, but I'd love a virtual cat!"},

        {"exit", "Goodbye! Have a great day!"}

    };
   
    int numKeywords = sizeof(keywords) / sizeof(KeywordPair);
    char userInput[600];
   
    while (1) {

        printf("You: ");
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\n")] = '\0';
        toLowerCase(userInput);

        if (strcmp(userInput, "tell me a joke") == 0) {
            tellJoke();
            continue;
        } else if (strcmp(userInput, "tell me a riddle") == 0) {
            tellRiddle();
            continue;
        } else if (strcmp(userInput, "motivate me") == 0) {
            tellQuote();
            continue;
        } else if (strcmp(userInput, "calculate") == 0) {
            calculator();
            continue;
        }

        int found = 0;
        for (int i = 0; i < numKeywords; i++) {
            if (strcmp(userInput, keywords[i].keyword) == 0) {
                printf("Chitti: %s\n", keywords[i].response);
                found = 1;
                break;
            }
        }

        if (!found) printf("Chitti: I'm not sure how to respond to that. Try asking something else!\n");
        if (strcmp(userInput, "exit") == 0) break;
    }
    return 0;

}