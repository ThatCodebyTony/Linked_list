#include <iostream> 
#include "LinkedList.h"
#include <fstream>
#include <string>
#include "testll.h" 

#define DEFAULT_DICT "dictionary1.txt"
#define DEFAULT_OUTPUT_FILE "dict-updated.txt"
using namespace std;

enum Actions {
    QUIT = 0, 
    DICT_SIZE = 1, 
    PRINT_TO_SCREEN = 2, 
    ADD_WORD = 3, 
    LINEAR_SEARCH = 4, 
    DELETE_WORD = 5,
    INSERT_IN_ORDER = 6, 
    SWAP = 7, 
    MERGE_DICTS = 8, 
    MERGE_SORT =9, 
    LOAD_NEW_DICT = 10, 
    WRITE_DICT_TO_FILE = 11,
    UNIT_TEST = 12
    
}; 

const int min_menu_option = 1;   // Not including Quit, which is zero
const int max_menu_option = UNIT_TEST;
const int min_dict_option = 1;
const int max_dict_option = 6;
bool isDefaultFileWritten = false;

int getMenuChoice() {
    int userInput;

    cout << "--------------------------------------------" << endl;
    cout << "Options menu: " << endl;
    cout << "(" << DICT_SIZE << ")" << " Count - get number of words in dictionary list" << endl;
    cout << "(" << PRINT_TO_SCREEN << ")" << " Print words to screen" << endl;
    cout << "(" << ADD_WORD << ")" << " Add a word (to end of dictionary list)" << endl;
    cout << "(" << LINEAR_SEARCH << ")" << " Find a word (Linear Search)" << endl;
    cout << "(" << DELETE_WORD << ")" << " Find word, delete if found" << endl;
    cout << "(" << INSERT_IN_ORDER << ")" << " Find word, insert if not found (assumes words are sorted alphabetically)" << endl;
    cout << "(" << SWAP << ")" << " Swap two words" << endl;
    cout << "(" << MERGE_DICTS << ")" << " Merge two dictionaries (assumes words are sorted alphabetically)" << endl;
    cout << "(" << MERGE_SORT << ")" << " Sort words (Merge Sort)" << endl;
    cout << "(" << LOAD_NEW_DICT << ")" << " Load a dictionary (closes current dictionary)" << endl;
    cout << "(" << WRITE_DICT_TO_FILE << ")" << " Write current dictionary to file" << endl;
    cout << "(" << UNIT_TEST << ")" << " Unit test of data structure" << endl;
    cout << "Enter a number from " << min_menu_option << " to " << max_menu_option << ", or " 
         << min_menu_option - 1 << " to exit: " << endl;

    cin >> userInput; 

    if (userInput < min_menu_option - 1 || userInput > max_menu_option) {
        cout << "Error! Input must be a number between " << min_menu_option << " and " << max_menu_option
             << " ,or " << min_menu_option - 1 << " to exit." << endl;
        return getMenuChoice(); 
    }
   
    return userInput;
}

void loadDictionary(LinkedList& list, const string& filename) {
    ifstream file(filename);
    string word;

    if (!file.is_open()) {
        cout << "ERROR! Cannot read the dictionary file \"" << filename << "\". Exiting." << endl;
        exit(EXIT_FAILURE);
    }

    while (getline(file, word)) {
        list.push_back(word); // Add each word to the linked list
    }

    file.close();
}

void openDict(LinkedList& myList, int& currentDictionary) {
    int dictChoice;
    bool validChoice = false;
    cout << "Which Dictionary should be opened? Enter a number from \"" << min_dict_option << "\" to \"" << max_dict_option << "\": " << endl;
    
    do {
        cin >> dictChoice;
        if (dictChoice == 0) {
            validChoice = true;
        } else if (dictChoice == currentDictionary) {
            cout << "That dictionary is already open! Pick another." << endl;
            cout << endl;
            cout << "Which Dictionary should be opened? Enter a number from \"" << min_dict_option << "\" to \"" << max_dict_option << "\": " << endl;
        } else if (dictChoice < min_dict_option || dictChoice > max_dict_option) {
            cout << "That number is not in the available range! Pick another." << endl;
            cout << endl;
            cout << "Which Dictionary should be opened? Enter a number from \"" << min_dict_option << "\" to \"" << max_dict_option << "\": " << endl;
        } else if (dictChoice == 6) {
            cout << "ERROR! Cannot read chosen dictionary dictionary6.txt. Dictionary 1 remains open." << endl;
            cout << endl;
            validChoice = true;
        } else {
            validChoice = true;
            currentDictionary = dictChoice;
            myList.clear();
            loadDictionary(myList, "dictionary" + to_string(currentDictionary) + ".txt");
            cout << "Dictionary " << currentDictionary << " is now open." << endl;
        }
    } while (!validChoice);
}

void writeDictToFile(LinkedList& myList, string& filename) {
    string userFileNameInput;
    cout << "Enter name of file (.txt will be appended automatically), or enter 'd' to use default filename: " << endl;
    cin >> userFileNameInput;

    if (userFileNameInput != "d") {
        filename = userFileNameInput + ".txt";
    } else {
        filename = DEFAULT_OUTPUT_FILE;  // Default filename
    }

    // Check if the file already exists
    if (ifstream(filename)) {
        cout << "ERROR! The file " << filename << " already exists. No data was written to file." << endl;
        return;  // Don't proceed with writing if file exists
    }

    // Proceed with writing to the file
    cout << "Writing to file ... " << endl;
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "ERROR! Cannot open the file for writing!" << endl;
        exit(EXIT_FAILURE);
    }

    // Use the LinkedList::print() method to write to the file
    myList.print(file);

    file.close();  // Close the file after writing
    cout << "                   ...Done!" << endl;
}

void unitTest() {
    promptUnitTest();
}

int main() 
{
    LinkedList* myList = new LinkedList; 
    loadDictionary(*myList, DEFAULT_DICT); 
    string default_output_file_name = DEFAULT_OUTPUT_FILE;
    int choice;
    int currentDictionary = 1;

    do {
        choice = getMenuChoice(); // Display menu and get user choice
        switch (choice) {
            case QUIT:
                cout << "Thank you! Bye!" << endl;
                break; 
            case DICT_SIZE:
                cout << "There are " << (*myList).size() << " words in dictionary #" << currentDictionary << "." << endl;
                break;
            case PRINT_TO_SCREEN:
                (*myList).print();
                break;
            case LOAD_NEW_DICT:
                openDict(*myList, currentDictionary);
                break;
            case WRITE_DICT_TO_FILE:
                writeDictToFile(*myList, default_output_file_name);
                break;
            case UNIT_TEST:
                promptUnitTest();
                break;
            default:
                cout << "Coming Soon!" << endl; 
                break;
        }
    } while (choice != QUIT); 

    delete myList; // Clean up the allocated memory
    return 0; 
}
