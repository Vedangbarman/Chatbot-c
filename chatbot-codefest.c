#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define ID_INPUT 1
#define ID_OUTPUT 2
#define ID_BUTTON 3

typedef struct {
    char keyword[300];
    char response[600];
} KeywordPair;

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

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void tellJoke(char *response) {
    char *jokes[] = {
        "Why don’t skeletons fight each other? They don’t have the guts!",
        "Why did the scarecrow win an award? Because he was outstanding in his field!"
    };
    int numJokes = sizeof(jokes) / sizeof(jokes[0]);
    strcpy(response, jokes[rand() % numJokes]);
}

void tellRiddle(char *response) {
    char *riddles[] = {
        "I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?",
        "The more of me you take, the more you leave behind. What am I?",
        "I am not alive, but I can grow. I don’t have lungs, but I need air. What am I?",
        "The person who makes it, sells it. The person who buys it never uses it. The person who uses it never knows they’re using it. What is it?"

    };
    int numRiddles = sizeof(riddles) / sizeof(riddles[0]);
    strcpy(response, riddles[rand() % numRiddles]);
}

void tellQuote(char *response) {
    char *quotes[] = {
        "Success is not final, failure is not fatal: It is the courage to continue that counts.",
        "Believe you can and you're halfway there.",
        "The only way to do great work is to love what you do.",
        "Your time is limited, so don’t waste it living someone else’s life."
    };
    int numQuotes = sizeof(quotes) / sizeof(quotes[0]);
    strcpy(response, quotes[rand() % numQuotes]);
}

void processUserInput(HWND hOutput, const char *input) {
    char response[600] = "I'm not sure how to respond to that.";

    toLowerCase(response);

    if (strcmp(input, "tell me a joke") == 0) {
        tellJoke(response);
    } else if (strcmp(input, "tell me a riddle") == 0) {
        tellRiddle(response);
    } else if (strcmp(input, "motivate me") == 0) {
        tellQuote(response);
    } else {
        for (int i = 0; i < numKeywords; i++) {
            if (strcmp(input, keywords[i].keyword) == 0) {
                strcpy(response, keywords[i].response);
                break;
            }
        }
    }

    SetWindowText(hOutput, response);
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    static HWND hInput, hOutput, hButton;

    switch (msg) {
        case WM_CREATE:
            hInput = CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
                                  50, 50, 300, 30, hWnd, (HMENU)ID_INPUT, NULL, NULL);

            hOutput = CreateWindow("STATIC", "Chatbot Ready!", WS_CHILD | WS_VISIBLE | SS_LEFT,
                                   50, 100, 400, 30, hWnd, (HMENU)ID_OUTPUT, NULL, NULL);

            hButton = CreateWindow("BUTTON", "Send", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                   360, 50, 80, 30, hWnd, (HMENU)ID_BUTTON, NULL, NULL);
            break;

        case WM_COMMAND:
            if (LOWORD(wp) == ID_BUTTON) {
                char userInput[256];
                GetWindowText(hInput, userInput, sizeof(userInput));
                processUserInput(hOutput, userInput);
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hWnd, msg, wp, lp);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    srand(time(NULL));

    WNDCLASS wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = "ChatbotWindow";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClass(&wc)) return -1;

    CreateWindow("ChatbotWindow", "Chatbot UI", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 400, NULL, NULL, NULL, NULL);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
