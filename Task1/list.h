typedef char* String;

/**
 *  Initializes the list to an empty list.
 *  First element* is set to NULL.
 */
void StringListInit(char** &list);

/**
 * Frees all the memory allocated for the list.
 */
void StringListDestroy(char** &list);

/**
 * Adds a copy of the string to the list.
 */
void StringListAdd(char** &list, const char* str);

/**
 * Removes all occurances of str in the list
 */
void StringListRemove(char** &list, const char* str);

/**
 * Returns the number of strings in the list.
 */
int StringListSize(char** list);

/**
 * Returns the index of the first occurrence of the string in the list.
 * Returns -1 if the string is not found.
 */
int StringListIndexOf(char** list, char* str);

/**
 * Removes all duplicate strings from the list.
 */
void StringListRemoveDuplicates(char** list);

/**
 * Replaces all occurrences of the string before with the string after in all strings in the list.
 */
void StringListReplaceInStrings(char** &list, const char* before, const char* after);

/**
 * Sorts the list in ascending order.
 */
void StringListSort(char** list);