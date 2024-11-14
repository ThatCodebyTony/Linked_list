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
const int max_dict_option = 10;
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
        } else if (dictChoice == 10) {
            cout << "ERROR! Cannot read chosen dictionary dictionary10.txt. Dictionary 1 remains open." << endl;
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

void addWord(LinkedList& myList) {
    string addWordInput;
    string cleanedAddedWord;
    string prevWord;
    string nextWord;
    cout << "Enter a word to add to the end of the chosen Dictionary: ";
    cin >> addWordInput;

    // Clean the input word (remove non-alphabetic characters and convert to lowercase)
    for (char c : addWordInput) {
        if (isalpha(c)) {
            cleanedAddedWord += tolower(c);
        }
    }

    cout << "Your word was '" << cleanedAddedWord << "'." << endl;

    // Search for the word in the list (before insertion)
    Node* node = myList.linearSearch(cleanedAddedWord, prevWord, nextWord);

    if (node == nullptr) {
        // Word is not found, so add it
        cout << " We did not find your word." << endl;
        myList.push_back(cleanedAddedWord);  // Add the word to the list
        cout << " Adding word to dictionary..." << endl;
        cout << "        Added!" << endl;

        // After the word is inserted, check for the previous and next words
        // Get the last node (tail)
        Node* tailNode = myList.getTail();

        if (tailNode != nullptr) {
            // Handle the previous word (the word before the newly added word)
            if (tailNode->getPrev()) {
                prevWord = tailNode->getPrev()->getWord();
            } else {
                // Case when it is the first word
                prevWord = "";
            }

            // Handle the next word (after the newly added word)
            if (tailNode->getNext()) {
                nextWord = tailNode->getNext()->getWord();
            } else {
                // Case when it is the last word
                nextWord = "";
            }

            // Only print the previous and next words if they are different from the added word
            if (prevWord != cleanedAddedWord && nextWord != cleanedAddedWord) {
                // If prevWord is not the same as cleanedAddedWord, print it
                if (prevWord.empty()) {
                    cout << " There is no word before " << cleanedAddedWord << ". It is the first word." << endl;
                } else {
                    cout << " The previous word would be '" << prevWord << "'." << endl;
                }

                // If nextWord is not the same as cleanedAddedWord, print it
                if (nextWord.empty()) {
                    cout << " There is no word after " << cleanedAddedWord << ". It is the last word." << endl;
                } else {
                    cout << " The next word would be '" << nextWord << "'." << endl;
                }
            } else {
                // If the previous and next words are the same as the cleaned added word
                // Simply print that it's the first and last word
                if (prevWord == cleanedAddedWord && nextWord == cleanedAddedWord) {
                    cout << " There is no word before " << cleanedAddedWord << ". It is the first word." << endl;
                    cout << " There is no word after " << cleanedAddedWord << ". It is the last word." << endl;
                }
            }
        }
    } else {
        // Word is already in the dictionary, just report its position
        // Output the previous and next words of the found word
        if (prevWord.empty()) {
            cout << " There is no word before " << cleanedAddedWord << ". It is the first word." << endl;
        } else {
            cout << " The previous word would be '" << prevWord << "'." << endl;
        }

        if (nextWord.empty()) {
            cout << " There is no word after " << cleanedAddedWord << ". It is the last word." << endl;
        } else {
            cout << " The next word would be '" << nextWord << "'." << endl;
        }
    }
}


void linearSearch(LinkedList& myList) {
    string searchWord;
    cout << "Enter a word to find: ";
    cin >> searchWord;

    // Clean the input word for display purposes
    string cleanedInput;
    for (char c : searchWord) {
        if (isalpha(c)) {
            cleanedInput += tolower(c);
        }
    }

    cout << "Your word was '" << cleanedInput << "'." << endl;

    // Perform a linear search to find the node and get previous and next words
    string prevWord, nextWord;
    Node* resultNode = myList.linearSearch(cleanedInput, prevWord, nextWord);

    if (resultNode != nullptr) {
        // Handle the first word case (no previous word)
        if (prevWord.empty()) {
            cout << "There is no word before " << cleanedInput << ". It is the first word." << endl;
        } else {
            cout << "The previous word would be '" << prevWord << "'." << endl;
        }

        // Handle the last word case (no next word)
        if (nextWord.empty()) {
            cout << "There is no word after " << cleanedInput << ". It is the last word." << endl;
        } else {
            cout << "The next word would be '" << nextWord << "'." << endl;
        }
    } else {
        cout << "We did not find your word." << endl;
    }
}


void deleteWordFromDictionary(LinkedList& myList) {
    string deleteWordInput;
    string cleanedDeleteWord;
    string prevWord;
    string nextWord;

    cout << "Enter a word to delete from the chosen Dictionary: ";
    cin >> deleteWordInput;

    for (char c : deleteWordInput) {
        if (isalpha(c)) {
            cleanedDeleteWord += tolower(c);
        }
    }


    cout << "Your word was '" << cleanedDeleteWord << "'." << endl;

    // Perform a linear search to find the node and get previous and next words
    Node* nodeToDelete = myList.linearSearch(cleanedDeleteWord, prevWord, nextWord);

    if (nodeToDelete != nullptr) {
        // Handle the first word case (no previous word)
        if (prevWord.empty()) {
            cout << " There is no word before " << cleanedDeleteWord << ". It is the first word." << endl;
        } else {
            cout << " The previous word would be '" << prevWord << "'." << endl;
        }

        // Handle the last word case (no next word)
        if (nextWord.empty()) {
            cout << " There is no word after " << cleanedDeleteWord << ". It is the last word." << endl;
        } else {
            cout << " The next word would be '" << nextWord << "'." << endl;
        }

        // Delete the node
        myList.deleteWord(nodeToDelete);

        cout << " The word '" << cleanedDeleteWord << "' has been deleted." << endl;
    } else {
        cout << " We did not find your word." << endl;
    }
}

void insertInOrder(LinkedList& myList) {
    string wordToInsert;
    string cleanedWordToInsert;

    cout << "Enter a word to insert in order in the chosen Dictionary: ";
    // Enter a word to insert in order in the chosen Dictionary: Your word was 'vomit'.
    cin >> wordToInsert;

    for (char c : wordToInsert) {
        if (isalpha(c)) {
            cleanedWordToInsert += tolower(c);
        }
    }

    myList.insert_in_order(cleanedWordToInsert);  // Use . instead of ->
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
                cout << endl;
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
            case ADD_WORD:
                addWord(*myList);
                break;
            case LINEAR_SEARCH:
                linearSearch(*myList);
                break;
            case DELETE_WORD:
                deleteWordFromDictionary(*myList);
                break;
            case INSERT_IN_ORDER:
                insertInOrder(*myList);
                break;
            default:
                cout << "Coming Soon!" << endl; 
                cout << endl;
                break;
        }
    } while (choice != QUIT); 

    delete myList; // Clean up the allocated memory
    return 0; 
}