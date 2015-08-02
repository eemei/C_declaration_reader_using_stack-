#include "unity.h"
#include "switchCase.h"
#include "tree.h"
#include "Token.h"
#include <string.h>

void setUp(void) {}
void tearDown(void) {}

void test_tree_declaration(void){
	Token *root;
	root = tree("int", "[", "x", "2"); 
	declaration(root);
}

void test_secondTree_declaration(void){
	Token *root;
	root = secondTree("int", "*", "[", "2", "app");
	declaration(root);
}

void test_doubleY_declaration(void){
	Token *root;
	root = YisDouble("double", "y");
	declaration(root);
}

void test_yisPointertoPointer_declaration(void){
	Token *root;
	root = yisPointertoPointer("float", "*", "*", "y");
	declaration(root);
}

void test_fooisFunc_declaration(void){
	Token *root;
	root = fooisFunc("char", "(", "foo", "int");
	declaration(root);
}

void test_fooisFuncreturnNoth_declaration(void){
	Token *root;
	root = fooisFuncreturnNoth("long", "(", "foo", "NULL");
	declaration(root);
}

