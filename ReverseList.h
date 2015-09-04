#ifndef REVERT_LIST_H_
#define REVERT_LIST_H_

#include "Common.h"

struct Node{
  Node(int value, Node* next) : value(value), next(next) {;}
  int value;
  Node* next;
};

template<typename Node> Node* ReverseList(Node* head){
  if(!head || !head->next){
    return head;
  }

  Node* prev = NULL;
  Node* curr = head;
  Node* next = NULL;
  while(curr){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

Node* ConstructList(const std::string& list){
  std::istringstream is(list);
  Node* head = NULL;
  Node* tail = NULL;
  while(!is.eof()){
    int value;
    is >> value;
    if(!head){
      head = new Node(value, NULL);
      tail = head;
    } else{
      tail->next = new Node(value, NULL);
      tail = tail->next;
    }
  }
  return head;
}

bool IsListEqual(Node* head1, Node* head2){
  if(!head1 && !head2){
    return true;
  } else if(!head1 || !head2){
    return false;
  }

  Node* p1 = head1;
  Node* p2 = head2;

  while(p1 && p2){
    if(p1->value != p2->value){
      return false;
    }

    p1 = p1->next;
    p2 = p2->next;
  }

  if(p1 || p2){
    return false;
  }

  return true;
}

void RevertListTest(){
  std::string line;

  while(!std::cin.eof()){
    do {
      getline(std::cin, line);
    } while(line.empty());
    std::cout << "Input:" << line << std::endl;

    Node* input_head = ConstructList(line);

    Node* reversed_head = ReverseList(input_head);

    do {
      getline(std::cin, line);
    } while(line.empty());
    std::cout << "Output:" << line << std::endl;
    Node* output_head = ConstructList(line);
    if(!AssertTrue(IsListEqual(reversed_head, output_head))){
      std::cerr << "Faild: " << std::endl;
      return;
    }
  }
  std::cout << "======================" << std::endl;
  std::cout << "|   Test passed.     |" << std::endl;
  std::cout << "======================" << std::endl;

}

#endif
