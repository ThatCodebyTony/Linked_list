/********************************************************************************
 *		TEST1.cpp
 *		author(s): Corey Carito   <ccarito@sfsu.edu>
 *		citations:
 *
 *		goal: test node and linked list data structures 
 *
 *		overview: 
 *
 *		(1) test that pointers are defined (in empty list, for instance)
 *		(2) test creation/deletion
 *		(3) test overload of comparison operators	
 *
 *    use blocks {} to separate tests for least contamination
 *
 ********************************************************************************/
#include <iostream> 
#include <iomanip>		//for formatting output
#include <string>
#include "LinkedList.h"
#include "testll.h"

using namespace std;

enum Choices {DONE, PRIVATE, NODE_BASIC, LL_BASIC, NODE_COMP_OPERATORS, LL_COMP_OPERATORS, RUN_ALL}; 


const int max_test_menu_option = RUN_ALL;

void testPrivate () {
	// everything in this block should fail to compile
	// check the compilation and comment out one at a time as they (properly) fail
/*	{
		Node * tNodePtr = new Node;
		
		if ((*tNodePtr).word == "") 	cout << "# 1. Word is empty" << endl;
		if ((*tNodePtr).next == NULL) 	cout << "# 2. Next is NULL" << endl;
		if ((*tNodePtr).prev == 0) 	cout << "# 3. Prev is NULL" << endl;
		delete tNodePtr;
		tNodePtr = NULL;
	}

	// everything in this block should fail to compile
	// check the compilation and comment out one at a time as they (properly) fail
	{
		LinkedList * lTestPtr = new LinkedList;
		
		if ((*lTestPtr).tail == NULL) 	cout << "# 1. Tail is NULL" << endl;
		if ((*lTestPtr).head == NULL) 	cout << "# 2. Head is NULL" << endl;
		if ((*lTestPtr).listSize == 0) 	 	cout << "# 3. size is 0" << endl;
		(*lTestPtr).setSize(9);
		(*lTestPtr).setHead(new Node("oops"));
		(*lTestPtr).setTail(new Node("uh-oh"));
	
		delete lTestPtr;
		lTestPtr = NULL;
	}
*/
	cout << "Done with \'testPrivate()\'." << endl;
}





void testNodeCompOperators () {
	cout 	<<  "\n===== Node_Comparison Operators =============" << endl
			<< left << setw(50) <<  " Node versus Node, all operators "				<<	"Tests: A\n"
			<< left << setw(50) <<  " Node versus string literal, all operators " 	<<	"Tests: B\n"
			<< left << setw(50) <<  " string literal versus Node, all operators " 	<<	"Tests: C\n"
			<<  "\n=================================================" << endl;

	// test #A: test comparison operators, Node v Node
	{
		cout << "\n-----Node_Comp: Test A --------------------" << endl;
		Node * tNodeAptr = new Node("apple");
		Node * tNodeBptr = new Node("banana");
		Node * tNodeB2ptr = new Node("banana");
		Node * tNodeCptr = new Node("cherry");
		
		if ( *tNodeAptr == *tNodeBptr)		cout << "\t\tERROR: # 1. \'apple\' should NOT == \'banana\'" << endl;
		else 								cout << "# 1. (\'apple\' == \'banana\') is FALSE" << endl;
		if ( *tNodeAptr != *tNodeBptr)		cout << "# 2. (\'apple\' != \'banana\') is TRUE" << endl;
		else 								cout << "\t\tERROR: # 2. \'apple\' should != \'banana\'" << endl;
		if ( *tNodeBptr == *tNodeB2ptr)		cout << "# 3. (\'banana\' == \'banana\') is TRUE" << endl;
		else 								cout << "\t\tERROR: # 3. \'banana\' should == \'banana\'" << endl;
		if ( *tNodeBptr != *tNodeB2ptr)		cout << "\t\tERROR: # 4. \'banana\' should NOT != \'banana\'" << endl;
		else 								cout << "# 4. (\'banana\' != \'banana\') is FALSE" << endl;
		cout << endl;
	
		if ( *tNodeAptr > *tNodeBptr)		cout << "\t\tERROR: # 5. \'apple\' is NOT > \'banana\'" << endl;
		else 								cout << "# 5. (\'apple\' > \'banana\') is FALSE" << endl;
		if ( *tNodeCptr > *tNodeBptr)		cout << "# 6. (\'cherry\' > \'banana\') is TRUE" << endl;
		else 								cout << "\t\tERROR: # 6. \'cherry\' should be > \'banana\'" << endl;
		if ( *tNodeBptr > *tNodeB2ptr)		cout << "\t\tERROR: # 7. \'banana\' should NOT > \'banana\'" << endl;
		else 								cout << "# 7. (\'banana\' > \'banana\') is FALSE" << endl;
		cout << endl;
	
	
		if ( *tNodeAptr < *tNodeBptr)		cout << "# 8. (\'apple\' < \'banana\') is TRUE" << endl;
		else 								cout << "\t\tERROR: # 8. \'apple\' is  < \'banana\'" << endl;
		if ( *tNodeCptr < *tNodeBptr)		cout << "\t\tERROR: # 9. \'cherry\' should NOT be < \'banana\'" << endl;
		else 								cout << "# 9. (\'cherry\' < \'banana\') is FALSE" << endl;
		if ( *tNodeBptr < *tNodeB2ptr)		cout << "\t\tERROR: # 10. \'banana\' should NOT < \'banana\'" << endl;
		else 								cout << "# 10. (\'banana\' < \'banana\') is FALSE" << endl;
		cout << endl;
	
	
		if ( *tNodeAptr >= *tNodeBptr)		cout << "\t\tERROR: # 11. \'apple\' is NOT >= \'banana\'" << endl;
		else 								cout << "# 11. (\'apple\' >= \'banana\') is FALSE" << endl;
		if ( *tNodeCptr >= *tNodeBptr)		cout << "# 12. (\'cherry\' >= \'banana\') is TRUE" << endl;
		else 								cout << "\t\tERROR: # 12. \'cherry\' should be >= \'banana\'" << endl;
		if ( *tNodeBptr >= *tNodeB2ptr)		cout << "# 13. (\'banana\' >= \'banana\') is TRUE" << endl;
		else 								cout << "\t\tERROR: # 13. \'banana\' is >= \'banana\'" << endl;
		cout << endl;
	
	
		if ( *tNodeAptr <= *tNodeBptr)		cout << "# 14. (\'apple\' <= \'banana\') is TRUE" << endl;
		else 								cout << "\t\tERROR: # 14. \'apple\' is  <= \'banana\'" << endl;
		if ( *tNodeCptr <= *tNodeBptr)		cout << "\t\tERROR: # 15. \'cherry\' should NOT be <= \'banana\'" << endl;
		else 								cout << "# 15. (\'cherry\' <= \'banana\') is FALSE" << endl;
		if ( *tNodeBptr <= *tNodeB2ptr)		cout << "# 16. (\'banana\' <= \'banana\') is TRUE" << endl;
		else 								cout << "\t\tERROR: # 16. \'banana\' is <= \'banana\'" << endl;
	
	
		delete tNodeAptr;
		tNodeAptr = NULL;
		delete tNodeBptr;
		tNodeBptr = NULL;
		delete tNodeB2ptr;
		tNodeB2ptr = NULL;
		delete tNodeCptr;
		tNodeCptr = NULL;
		cout << "\n-------------------------------------------" << endl;
		cout << endl;
	}
	
	// test #B: test comparison operators, Node v String
	{
		cout << "\n----- Node_Comp: Test B --------------------" << endl;
		Node * tNodeAptr = new Node("apple");
		Node * tNodeBptr = new Node("banana");
		Node * tNodeB2ptr = new Node("banana");
		Node * tNodeCptr = new Node("cherry");
		
		string	strB = "banana";
		
		if ( *tNodeAptr == strB)		cout << "\t\tERROR: # 1. \'apple\' should NOT == \"banana\"" << endl;
		else 								cout << "# 1. (\'apple\' == \"banana\") is FALSE" << endl;
		if ( *tNodeAptr != strB)		cout << "# 2. (\'apple\' != \"banana\") is TRUE" << endl;
		else 								cout << "\t\tERROR: # 2. \'apple\' should != \"banana\"" << endl;
		if ( *tNodeBptr == strB)		cout << "# 3. (\'banana\' == \"banana\") is TRUE" << endl;
		else 								cout << "\t\tERROR: # 3. \"banana\" should == \"banana\"" << endl;
		if ( *tNodeBptr != strB)		cout << "\t\tERROR: # 4. \'banana\' should NOT != \"banana\"" << endl;
		else 								cout << "# 4. (\'banana\' != \"banana\") is FALSE" << endl;
		cout << endl;
	
		if ( *tNodeAptr > strB)		cout << "\t\tERROR: # 5. \'apple\' is NOT > \"banana\"" << endl;
		else 								cout << "# 5. (\'apple\' > \"banana\") is FALSE" << endl;
		if ( *tNodeCptr > strB)		cout << "# 6. (\'cherry\' > \"banana\") is TRUE" << endl;
		else 								cout << "\t\tERROR: # 6. \'cherry\' should be > \"banana\"" << endl;
		if ( *tNodeBptr > strB)		cout << "\t\tERROR: # 7. \'banana\' should NOT > \"banana\"" << endl;
		else 								cout << "# 7. (\'banana\' > \"banana\") is FALSE" << endl;
		cout << endl;
	
	
		if ( *tNodeAptr < strB)		cout << "# 8. (\'apple\' < \"banana\") is TRUE" << endl;
		else 								cout << "\t\tERROR: # 8. \'apple\' is  < \"banana\"" << endl;
		if ( *tNodeCptr < strB)		cout << "\t\tERROR: # 9. \'cherry\' should NOT be < \"banana\"" << endl;
		else 								cout << "# 9. (\'cherry\' < \"banana\") is FALSE" << endl;
		if ( *tNodeBptr < strB)		cout << "\t\tERROR: # 10. \'banana\' should NOT < \"banana\"" << endl;
		else 								cout << "# 10. (\'banana\' < \"banana\") is FALSE" << endl;
		cout << endl;
	
	
		if ( *tNodeAptr >= strB)		cout << "\t\tERROR: # 11. \'apple\' is NOT >= \"banana\"" << endl;
		else 								cout << "# 11. (\'apple\' >= \"banana\") is FALSE" << endl;
		if ( *tNodeCptr >= strB)		cout << "# 12. (\'cherry\' >= \"banana\") is TRUE" << endl;
		else 								cout << "\t\tERROR: # 12. \'cherry\' should be >= \"banana\"" << endl;
		if ( *tNodeBptr >= strB)		cout << "# 13. (\'banana\' >= \"banana\") is TRUE" << endl;
		else 								cout << "\t\tERROR: # 13. \'banana\' is >= \"banana\"" << endl;
		cout << endl;
	
	
		if ( *tNodeAptr <= strB)		cout << "# 14. (\'apple\' <= \"banana\") is TRUE" << endl;
		else 								cout << "\t\tERROR: # 14. \'apple\' is  <= \"banana\"" << endl;
		if ( *tNodeCptr <= strB)		cout << "\t\tERROR: # 15. \'cherry\' should NOT be <= \"banana\"" << endl;
		else 								cout << "# 15. (\'cherry\' <= \"banana\") is FALSE" << endl;
		if ( *tNodeBptr <= strB)		cout << "# 16. (\'banana\' <= \"banana\") is TRUE" << endl;
		else 								cout << "\t\tERROR: # 16. \'banana\' is <= \"banana\"" << endl;
	
	
		delete tNodeAptr;
		tNodeAptr = NULL;
		delete tNodeBptr;
		tNodeBptr = NULL;
		delete tNodeB2ptr;
		tNodeB2ptr = NULL;
		delete tNodeCptr;
		tNodeCptr = NULL;
		cout << "\n-------------------------------------------" << endl;
	}
	
	
	
		// test #C: test comparison operators, Node v Node
	{
		cout << "\n----- Node_Comp: Test C --------------------" << endl;
		Node * tNodeAptr = new Node("apple");
		Node * tNodeBptr = new Node("banana");
		Node * tNodeB2ptr = new Node("banana");
		Node * tNodeCptr = new Node("cherry");
		
		string	strA = "apple",
				strB = "banana",
				strC = "cherry";
		
		if ( strA == *tNodeBptr)		cout << "\t\tERROR: # 1. \"apple\" should NOT == \'banana\'" << endl;
		else 								cout << "# 1. (\"apple\" == \'banana\') is FALSE" << endl;
		if ( strA != *tNodeBptr)		cout << "# 2. (\"apple\" != \'banana\') is TRUE" << endl;
		else 								cout << "\t\tERROR: # 2. \"apple\" should != \'banana\'" << endl;
		if ( strB == *tNodeB2ptr)		cout << "# 3. (\"banana\" == \'banana\') is TRUE" << endl;
		else 								cout << "\t\tERROR: # 3. \"banana\" should == \'banana\'" << endl;
		if ( strB != *tNodeB2ptr)		cout << "\t\tERROR: # 4. \"banana\" should NOT != \'banana\'" << endl;
		else 								cout << "# 4. (\"banana\" != \'banana\') is FALSE" << endl;
		cout << endl;
	
		if ( strA > *tNodeBptr)		cout << "\t\tERROR: # 5. \"apple\" is NOT > \'banana\'" << endl;
		else 								cout << "# 5. (\"apple\" > \'banana\') is FALSE" << endl;
		if ( strC > *tNodeBptr)		cout << "# 6. (\"cherry\" > \'banana\') is TRUE" << endl;
		else 								cout << "\t\tERROR: # 6. \"cherry\" should be > \'banana\'" << endl;
		if ( strB > *tNodeB2ptr)		cout << "\t\tERROR: # 7. \"banana\" should NOT > \'banana\'" << endl;
		else 								cout << "# 7. (\"banana\" > \'banana\') is FALSE" << endl;
		cout << endl;
	
	
		if ( strA < *tNodeBptr)		cout << "# 8. (\"apple\" < \'banana\') is TRUE" << endl;
		else 								cout << "\t\tERROR: # 8. \"apple\" is  < \'banana\'" << endl;
		if ( strC < *tNodeBptr)		cout << "\t\tERROR: # 9. \"cherry\" should NOT be < \'banana\'" << endl;
		else 								cout << "# 9. (\"cherry\" < \'banana\') is FALSE" << endl;
		if ( strB < *tNodeB2ptr)		cout << "\t\tERROR: # 10. \"banana\" should NOT < \'banana\'" << endl;
		else 								cout << "# 10. (\"banana\" < \'banana\') is FALSE" << endl;
		cout << endl;
	
	
		if ( strA >= *tNodeBptr)		cout << "\t\tERROR: # 11. \"apple\" is NOT >= \'banana\'" << endl;
		else 								cout << "# 11. (\"apple\" >= \'banana\') is FALSE" << endl;
		if ( strC >= *tNodeBptr)		cout << "# 12. (\"cherry\" >= \'banana\') is TRUE" << endl;
		else 								cout << "\t\tERROR: # 12. \"cherry\" should be >= \'banana\'" << endl;
		if ( strB >= *tNodeB2ptr)		cout << "# 13. (\"banana\" >= \'banana\') is TRUE" << endl;
		else 								cout << "\t\tERROR: # 13. \"banana\" is >= \'banana\'" << endl;
		cout << endl;
	
	
		if ( strA <= *tNodeBptr)		cout << "# 14. (\"apple\" <= \'banana\') is TRUE" << endl;
		else 								cout << "\t\tERROR: # 14. \"apple\" is  <= \'banana\'" << endl;
		if ( strC <= *tNodeBptr)		cout << "\t\tERROR: # 15. \"cherry\" should NOT be <= \'banana\'" << endl;
		else 								cout << "# 15. (\"cherry\" <= \'banana\') is FALSE" << endl;
		if ( strB <= *tNodeB2ptr)		cout << "# 16. (\"banana\" <= \'banana\') is TRUE" << endl;
		else 								cout << "\t\tERROR: # 16. \"banana\" is <= \'banana\'" << endl;
	
	
		delete tNodeAptr;
		tNodeAptr = NULL;
		delete tNodeBptr;
		tNodeBptr = NULL;
		delete tNodeB2ptr;
		tNodeB2ptr = NULL;
		delete tNodeCptr;
		tNodeCptr = NULL;
		cout << "\n-------------------------------------------" << endl;
	}

	
	
} //end testNodeCompOperators()


void testLinkedListBasic () {
	cout 	<<  "\n===== LinkedList_Basic: Methods Tested =============" << endl
			<< left << setw(40) <<  " LinkedList ();" 						<<	"Tests: A\n"
			<< left << setw(40) <<  " LinkedList (std::string wordInfo);" 	<<	"Tests: B\n"
			<< left << setw(40) <<  " Node * getHead();" 					<<	"Tests: A\n"
			<< left << setw(40) <<  " Node * getTail();" 					<<	"Tests: A\n"
			<< left << setw(40) <<  " int size();" 							<<	"Tests: A, B\n"
			<< left << setw(40) <<  " void push_back(std::string newWord);" <<	"Tests: C\n"
			<<  "\n=================================================" << endl;


	// test #A: create empty list, check NULL
	{
		cout << "\n-----Test LL_A -----------------------------" << endl;
		LinkedList * lTestPtr = new LinkedList;
		
		cout << "## CALL TO:\tLinkedList * lTestPtr = new LinkedList;\t##" << endl
			 << "## Expected behavior: List should be empty: size == 0 and pointers should equal NULL (or nullptr).\t##"
			 << "\n-------------------------------------------" << endl;

		if ((*lTestPtr).getTail() == NULL) 	cout << "# 1. Tail is NULL" << endl;
		else 								cout << "\t\tERROR: # 1. Tail is not NULL" << endl;
		if ((*lTestPtr).getHead() == NULL) 	cout << "# 2. Head is NULL" << endl;
		else 								cout << "\t\tERROR: # 2. Head is not NULL" << endl;
		if ((*lTestPtr).size() == 0) 	 	cout << "# 3. size is 0" << endl;
		else 								cout << "\t\tERROR: # 3. size is " << (*lTestPtr).size() << endl;
		delete lTestPtr;
		lTestPtr = NULL;
		cout << "\n-------------------------------------------" << endl;
		}	
	
	// test #B: create list, check NULL
	{
		cout << "\n-----Test LL-B --------------------" << endl;
		LinkedList * lTestPtr = new LinkedList("word");
		
		cout << "## CALL TO:\tLinkedList * lTestPtr = new LinkedList(\"word\");\t##" << endl
			 << "## Expected behavior: List should have one Node: size == 1 and head and tail pointers should point to it.\t##"
			 << "\n-------------------------------------------" << endl;
		
		if ((*lTestPtr).getTail() == NULL) 	cout << "\t\tERROR: # 1. Tail is NULL" << endl;
		else 								cout << "# 1. Tail is not NULL, points to \'" << (*(*lTestPtr).getTail()).getWord() << "\'" << endl;
		if ((*lTestPtr).getHead() == NULL) 	cout << "\t\tERROR: # 2. Head is NULL" << endl;
		else 								cout << "# 2. Head is not NULL, points to \'" << (*(*lTestPtr).getHead()).getWord() << "\'" << endl;
		if ((*lTestPtr).size() == 0) 	 	cout << "\t\tERROR: # 3. size is 0" << endl;
		else 								cout << "# 3. size is " << (*lTestPtr).size() << endl;
		delete lTestPtr;
		lTestPtr = NULL;
		cout << "\n-------------------------------------------" << endl;
	}	

	// test #C: add to list, check pointers, navigate and check links [[too much in this test]]
	{
		cout << "\n-----Test LL-C --------------------" << endl;
		LinkedList * lTestPtr = new LinkedList("original");
		
		cout << "## CALLS TO:\tLinkedList * lTestPtr = new LinkedList(\"original\");\t##" << endl
			 << "##          \t (*lTestPtr).push_back(\"one\");   // and also \"two\" and \"three\"\t##" << endl
			 << "## Expected behavior: List should have four Nodes: size == 4 and head and \n"
			 << "                      tail pointers should be pointing at \"original\" and \"three\".\t##"
			 << "\n-------------------------------------------" << endl;
		
		(*lTestPtr).push_back("one");
		(*lTestPtr).push_back("two");
		(*lTestPtr).push_back("three");

		if ((*lTestPtr).getTail() == NULL) 	{		
			cout << "\t\tERROR: # 1. Tail is NULL" << endl;
		} else if ( (*(*lTestPtr).getTail()).getWord() != "three" ) {
			cout << "\t\tERROR: # 1. Tail should be \'three\' but is " << (*(*lTestPtr).getTail()).getWord() << endl;
		} else {										
			cout << "# 1. Tail is not NULL, correctly points to \'" << (*(*lTestPtr).getTail()).getWord() << "\'" << endl;
		}
		if ((*lTestPtr).getHead() == NULL)  	{		
			cout << "\t\tERROR: # 2. Head is NULL" << endl;
		} else if ( (*(*lTestPtr).getHead()).getWord() != "original" ) {
			cout << "\t\tERROR: # 2. Head should be \'original\' but is " << (*(*lTestPtr).getHead()).getWord() << endl;
		} else {										
			cout << "# 2. Head is not NULL, correctly points to \'" << (*(*lTestPtr).getHead()).getWord() << "\'" << endl;
		}
		if ((*lTestPtr).size() == 4)				cout << "# 3. size is " << (*lTestPtr).size()  << endl;
		else 										cout << "\t\tERROR: # 3. size is " << (*lTestPtr).size() << endl;
		
		string temp;
		temp.reserve ((*lTestPtr).size() * 10);		// assume words average to 10 characters long (should give enough space)
		Node * lCurrNodePtr = (*lTestPtr).getHead();
		while (lCurrNodePtr != NULL) {
			temp += (*lCurrNodePtr).getWord() + " ";
			lCurrNodePtr = (*lCurrNodePtr).getNext();
		}
		if (temp == "original one two three ") 		cout << "# 4. navigating list correctly gives all words as \'" << temp << "\'" << endl;
		else 										cout << "\t\tERROR: # 4. all words are \'" << temp << "\'" << endl;
		
		string temp2;
		temp2.reserve ((*lTestPtr).size() * 10);		// assume words average to 10 characters long (should give enough space)
		lCurrNodePtr = (*lTestPtr).getTail();
		while (lCurrNodePtr != NULL) {
			temp2 += (*lCurrNodePtr).getWord() + " ";
			lCurrNodePtr = (*lCurrNodePtr).getPrev();
		}
		if (temp2 == "three two one original ") 		cout << "# 5. navigating list in reverse correctly gives all words as \'" << temp2 << "\'" << endl;
		else 										cout << "\t\tERROR: # 5. all words listed in reverse  are \'" << temp2 << "\'" << endl;
		
		delete lTestPtr;
		lTestPtr = NULL;
		cout << "\n-------------------------------------------" << endl;
	}	


} //end testLinkedListBasic()

int getTestMenuChoice () {   

	int choiceOption;
	
	do {
		choiceOption = -678123; //init with unlikely value so it will loop again if no valid input is entered
		cout << "\n--------------------------------------------\n"
			 << "Test options menu: \n"
			 << "  (" << PRIVATE <<") Run public/private tests\n"			 
			 << "  (" << NODE_BASIC <<") Run basic Node tests\n" 
			 << "  (" << LL_BASIC <<") Run basic Linked List tests\n"
			 << "  (" << NODE_COMP_OPERATORS <<") Test comparison operator overload of Node\n"
			 << "  (" << LL_COMP_OPERATORS <<") Test += operator overload of LinkedList\n"
			 << "  (" << RUN_ALL <<") Run all tests \n"
			 << "Enter a number from 1 to " << max_test_menu_option << ", or " << DONE << " to exit: ";
		cin >> choiceOption;
		/* check for failure of cin (for instance, when data type read in is not int */
		if (cin.fail()) {
			cin.clear();
			//discard bad characters
			/*zyBooks rejects: cin.ignore (numeric_limits<streamsize>::max(), '\n');
			 */
		}
		/* check if input is in valid range */
		if ( (choiceOption < 0) || (choiceOption > max_test_menu_option) ) {
			cout << "\nError! Input must be a number between 1 and " << max_test_menu_option 
			     << ", or " << DONE << " to exit." << endl;
			choiceOption = -678123; // loop again. 
		}
		cout << endl;
	} while (choiceOption == -678123);


	return choiceOption;


} // end getTestMenuChoice()

void testNodeBasic() {

	cout 	<<  "\n===== NodeBasic: Methods Tested ================" << endl
			<< left << setw(40) << " Node ();" 								<<	"Tests: A\n"
			<< left << setw(40) <<  " Node (std::string wordInfo);" 		<<	"Tests: B, also C, D\n"
			<< left << setw(40) <<  " std::string getWord() const;" 		<<	"Tests: A, also B, C, D\n"
			<< left << setw(40) <<  " void setWord (std::string newWord);" 	<< 	"Tests: C\n"
			<< left << setw(40) <<  " Node * getNext() const;" 				<<	"Tests: A, B, D\n"
			<< left << setw(40) <<  " void setNext (Node * newNext);" 		<<	"Tests: D\n"
			<< left << setw(40) <<  " Node * getPrev() const;" 				<<	"Tests: A,B, D\n"
			<< left << setw(40) <<  " void setPrev (Node * newPrev);" 		<<	"Tests: D\n"
			<<  "\n=================================================" << endl;


	// test #A: create Node
	{
		cout << "\n----- NodeBasic: Test A --------------------" << endl;
		Node * tNodePtr = new Node;
		
		cout << "## CALL TO:\tNode * tNodePtr = new Node;\t##" << endl
			 << "## Expected behavior: String/data should be empty and pointers should equal NULL (or nullptr).\t##"
			 << "\n-------------------------------------------" << endl;

		if ((*tNodePtr).getWord() == "") 	cout << "# 1. Word is empty" << endl;
		else 								cout << "\t\tERROR: # 1. Word is " << (*tNodePtr).getWord() << endl;
		if ((*tNodePtr).getNext() == NULL) 	cout << "# 2. Next is NULL" << endl;
		else 								cout << "\t\tERROR: # 2. Next is not NULL" << endl;
		if ((*tNodePtr).getPrev() == NULL) 	cout << "# 3. Prev is NULL" << endl;
		else 								cout << "\t\tERROR: # 3. Prev is not NULL" << endl;
		delete tNodePtr;
		tNodePtr = NULL;
		cout << "\n-------------------------------------------" << endl;
	}
	
	// test #B: create Node with word
	{
		cout << "\n----- NodeBasic: Test B --------------------" << endl;
		Node * tNodePtr = new Node("test");
		
		cout << "## CALL TO:\tNode * tNodePtr = new Node(\"test\");\t##" << endl
			 << "## Expected behavior: String/data should be \"test\" and pointers should equal NULL (or nullptr).\t##"
			 << "\n-------------------------------------------" << endl;

		if ((*tNodePtr).getWord() == "test")cout << "# 1. Word is \'test\'" << endl;
		else 								cout << "\t\tERROR: # 1. Word is " << (*tNodePtr).getWord() << endl;
		if ((*tNodePtr).getNext() == NULL) 	cout << "# 2. Next is NULL" << endl;
		else 								cout << "\t\tERROR: # 2. Next is not NULL" << endl;
		if ((*tNodePtr).getPrev() == NULL) 	cout << "# 3. Prev is NULL" << endl;
		else 								cout << "\t\tERROR: # 3. Prev is not NULL" << endl;
		delete tNodePtr;
		tNodePtr = NULL;
		cout << "\n-------------------------------------------" << endl;
	}
	
	
	// test #C: create Node with word & update
	{
		cout << "\n----- NodeBasic: Test C -------------------------------" << endl;
		Node * tNodePtr = new Node("test");
		
		
		cout << "## CALLS TO:\tNode * tNodePtr = new Node(\"test\");\n"
			 << "##          \t(*tNodePtr).setWord(\"change\");\t##" << endl
			 << "## Expected behavior: String/data should first be \"test\" and then should equal \"change\".\t##"
			 << "\n-------------------------------------------" << endl;

		if ((*tNodePtr).getWord() == "test")	cout << "# 1. Word is \'test\'" << endl;
		else 									cout << "\t\tERROR: # 1. Word is " << (*tNodePtr).getWord() << endl;
		(*tNodePtr).setWord("change");
		if ( (*tNodePtr).getWord() == "change")	cout << "# 2. Word is \'change\'" << endl;
		else 									cout << "\t\tERROR: # 2. Word is " << (*tNodePtr).getWord() << endl;
	
		cout << "\n-------------------------------------------" << endl;
	}
	
	
	// test #D: create Nodes with words & link
	{
		cout << "\n----- NodeBasic: Test D --------------------" << endl;
		Node * tNodePtr = new Node("original");
		
		
		cout << "## CALLS TO:\tNode * tNodePtr = new Node(\"original\");\n"
			 << "##          \tNode * tNextPtr = new Node(\"second\");\t##" << endl
			 << "##          \t(*tNodePtr).setNext(tNextPtr);\t##" << endl
			 << "##          \tNode * tPrevPtr = new Node(\"first\");\t##" << endl
			 << "##          \t(*tNodePtr).setPrev(tPrevPtr);\t##" << endl
			 << "## Expected behavior: From the  \"original\" Node, should be able to "
			 <<				 "access/read prev & next Nodes.\t##"
			 << "\n-------------------------------------------" << endl;

		Node * tNextPtr = new Node("second");
		(*tNodePtr).setNext(tNextPtr);
		
		Node * tPrevPtr = new Node("first");
		(*tNodePtr).setPrev(tPrevPtr);
		
		if ( (*tNodePtr).getNext() == tNextPtr  && (*(*tNodePtr).getNext()).getWord() == "second" ) 	
			cout << "# 1. getNext())->getWord() is \'" << (*(*tNodePtr).getNext()).getWord() << "\'" << endl;
		else 									cout << "\t\tERROR: # 1. Next fails" << endl;
		if ( (*(*tNodePtr).getNext()).getNext() == NULL ) 	cout << "# 2. Next->next is NULL " << endl;
		else 									cout << "\t\tERROR: # 2. Next->next is not NULL" << endl;
		if ( (*tNodePtr).getPrev() == tPrevPtr	&& (*(*tNodePtr).getPrev()).getWord() == "first" ) 	
			cout << "# 3. getPrev())->getWord() is \'" << (*(*tNodePtr).getPrev()).getWord() << "\'" << endl;
		else 									cout << "\t\tERROR: # 3. Prev is not NULL" << endl;
		if ( (*(*tNodePtr).getPrev()).getPrev() == NULL ) 	cout << "# 4. Prev->prev is NULL " << endl;
		else 									cout << "\t\tERROR: # 4. Prev->prev is not NULL" << endl;
		delete tNodePtr;
		tNodePtr = NULL;
		delete tNextPtr;
		tNextPtr = NULL;
		delete tPrevPtr;
		tPrevPtr = NULL;
		cout << "\n-------------------------------------------" << endl;
	}

} // end testNodeBasic()

void testLinkedListCompOperator() {
    cout << "-----LL_Comp: Test A --------------------" << endl;
    LinkedList* list2Ptr = new LinkedList;
    (*list2Ptr).push_back(new Node("kiwi"));
    (*list2Ptr).push_back(new Node("orange"));
    (*list2Ptr).push_back(new Node("tangerine"));
    (*list2Ptr).push_back(new Node("watermelon"));

	cout << "## CALLS TO:	LinkedList * list2Ptr = new LinkedList; ##" << endl;
	cout << "##          	 (*list2Ptr).push_back(new Node(\"tangerine\"));   // four Nodes in total 	##" << endl;
	cout << "## Expected behavior: List should have four Nodes: size == 4 and head and " << endl;
	cout << "                      tail pointers should be pointing at \"kiwi\" and \"watermelon\".	##" << endl;
	cout << "-------------------------------------------" << endl;

    // Test the first list
    if (list2Ptr->getTail() != NULL && list2Ptr->getTail()->getWord() == "watermelon") 
        cout << "# 1. Tail is not NULL, correctly points to 'watermelon'" << endl;
    else 
        cout << "\t\tERROR: # 1. Tail is not correctly set" << endl;

    if (list2Ptr->getHead() != NULL && list2Ptr->getHead()->getWord() == "kiwi") 
        cout << "# 2. Head is not NULL, correctly points to 'kiwi'" << endl;
    else 
        cout << "\t\tERROR: # 2. Head is not correctly set" << endl;

    if (list2Ptr->getTail()->getNext() == NULL) 
        cout << "# 3a. Tail->next is NULL" << endl;
    else 
        cout << "\t\tERROR: # 3a. Tail->next is not NULL" << endl;

    if (list2Ptr->getHead()->getPrev() == NULL) 
        cout << "# 3b. Head->Prev is NULL" << endl;
    else 
        cout << "\t\tERROR: # 3b. Head->Prev is not NULL" << endl;

    if (list2Ptr->size() == 4) 
        cout << "# 4. size is " << list2Ptr->size() << endl;
    else 
        cout << "\t\tERROR: # 4. Incorrect size" << endl;

    string listContents;
    Node* currentNode = list2Ptr->getHead();
    while (currentNode != NULL) {
        listContents += currentNode->getWord() + " ";
        currentNode = currentNode->getNext();
    }
    if (listContents == "kiwi orange tangerine watermelon ") 
        cout << "# 5. navigating list correctly gives all words as '" << listContents << "'" << endl;
    else 
        cout << "\t\tERROR: # 5. List contents do not match expected order" << endl;

    string reverseListContents;
    currentNode = list2Ptr->getTail();
    while (currentNode != NULL) {
        reverseListContents += currentNode->getWord() + " ";
        currentNode = currentNode->getPrev();
    }
    if (reverseListContents == "watermelon tangerine orange kiwi ") 
        cout << "# 6. navigating list in reverse correctly gives all words as '" << reverseListContents << "'" << endl;
    else 
        cout << "\t\tERROR: # 6. List contents in reverse do not match expected order" << endl;

    cout << "-------------------------------------------" << endl;

    // Now for test B: Merging two lists.
    cout << "-----LL_Comp: Test B --------------------" << endl;
    LinkedList* list1Ptr = new LinkedList;
    (*list1Ptr).push_back(new Node("apple"));
    (*list1Ptr).push_back(new Node("banana"));
    (*list1Ptr).push_back(new Node("cherry"));
    (*list1Ptr).push_back(new Node("grape"));

    cout << "## CALLS TO:	*list1Ptr += *list2Ptr;	##" << endl;
	cout << "##          	 " << endl;
    cout << "## Expected behavior: List should have eight Nodes: size == 8 and head and tail pointers should be pointing at \"apple\" and \"watermelon\".	##" << endl;
	cout << "-------------------------------------------" << endl;



    // Merging lists
    (*list1Ptr) += (*list2Ptr);

    // Test the merged list
    if (list1Ptr->getTail() != NULL && list1Ptr->getTail()->getWord() == "watermelon") 
        cout << "# 1. Tail is not NULL, correctly points to 'watermelon'" << endl;
    else 
        cout << "\t\tERROR: # 1. Tail is not correctly set" << endl;

    if (list1Ptr->getHead() != NULL && list1Ptr->getHead()->getWord() == "apple") 
        cout << "# 2. Head is not NULL, correctly points to 'apple'" << endl;
    else 
        cout << "\t\tERROR: # 2. Head is not correctly set" << endl;

    if (list1Ptr->getTail()->getNext() == NULL) 
        cout << "# 3a. Tail->next is NULL" << endl;
    else 
        cout << "\t\tERROR: # 3a. Tail->next is not NULL" << endl;

    if (list1Ptr->getHead()->getPrev() == NULL) 
        cout << "# 3b. Head->Prev is NULL" << endl;
    else 
        cout << "\t\tERROR: # 3b. Head->Prev is not NULL" << endl;

    if (list1Ptr->size() == 8) 
        cout << "# 4. size is " << list1Ptr->size() << endl;
    else 
        cout << "\t\tERROR: # 4. Incorrect size" << endl;

    string mergedListContents;
    Node* currentMergedNode = list1Ptr->getHead();
    while (currentMergedNode != NULL) {
        mergedListContents += currentMergedNode->getWord() + " ";
        currentMergedNode = currentMergedNode->getNext();
    }
    if (mergedListContents == "apple banana cherry grape kiwi orange tangerine watermelon ") 
        cout << "# 5. navigating list correctly gives all words as '" << mergedListContents << "'" << endl;
    else 
        cout << "\t\tERROR: # 5. List contents do not match expected order" << endl;

    string reverseMergedListContents;
    currentMergedNode = list1Ptr->getTail();
    while (currentMergedNode != NULL) {
        reverseMergedListContents += currentMergedNode->getWord() + " ";
        currentMergedNode = currentMergedNode->getPrev();
    }
    if (reverseMergedListContents == "watermelon tangerine orange kiwi grape cherry banana apple ") 
        cout << "# 6. navigating list in reverse correctly gives all words as '" << reverseMergedListContents << "'" << endl;
    else 
        cout << "\t\tERROR: # 6. List contents in reverse do not match expected order" << endl;

    cout << "# 7. size of list2Ptr is " << list2Ptr->size() << endl;
    cout << "# 8. Tail of list2Ptr is " << (list2Ptr->getTail() == NULL ? "NULL" : "Not NULL") << endl;
    cout << "# 9. Head of list2Ptr is " << (list2Ptr->getHead() == NULL ? "NULL" : "Not NULL") << endl;
	cout << endl;
	cout << "-------------------------------------------" << endl;

    delete list1Ptr;
    delete list2Ptr;
}



void promptUnitTest() {
	/* variables */
	int menuChoice;

	do {										 
		menuChoice = getTestMenuChoice ();
		
		switch (menuChoice) {
			case PRIVATE:
				testPrivate ();
				break;
			case NODE_BASIC:  
				testNodeBasic();
				break;
			case LL_BASIC: 
				testLinkedListBasic ();
				break;
			case NODE_COMP_OPERATORS: 
				testNodeCompOperators ();
				break;
			case LL_COMP_OPERATORS: 
				testLinkedListCompOperator ();
				break;
			case RUN_ALL: 
				testPrivate ();
				testNodeBasic();
				testLinkedListBasic ();
				testNodeCompOperators ();
				testLinkedListCompOperator ();
				break;
			default: 	//DONE entered zero, exit
				cout << "Returning to main menu." << endl;	
				menuChoice = 0;				//in case it was a non-listed option
		} //end switch

	
	} while (menuChoice != 0);

} //end promptUnitTest()
