#ifndef NODE_h
#define NODE_h
#include "STUDENT.h"
struct Node{
	Student data;
	Node* next;
	Node(const Student& sv){
		data = sv;
		next = NULL; 
	} 
}; 
#endif  
