int controller_loadFromText(char* path , LinkedList* pArrayListEnvios);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEnvios);
int controller_addEnvios(LinkedList* pArrayListEnvios);
int controller_editEnvios(LinkedList* pArrayListEnvios);
int controller_removeEnvios(LinkedList* pArrayListEnvios);
int controller_ListEnvios(LinkedList* pArrayListEnvios);
int controller_sortEnvios(LinkedList* pArrayListEnvios);
int controller_saveAsText(char* path , LinkedList* pArrayListEnvios);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEnvios);

int controller_findById(LinkedList* pArrayListEnvios, int id);
int controller_printOneEnvios(LinkedList* pArrayListEnvios, int index);

