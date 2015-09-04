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

template<typename Node> Node* KthReverseList(Node* head, int k){
  if(!head || !head->next || k <= 0){
    return head;
  }

  Node* prev = NULL;
  Node* curr = head;
  Node* next = NULL;
  int count = 0;
  Node* curr_tail = head;
  while(curr && count < k){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    ++count;
  }
  curr_tail->next = KthReverseList(curr, k);
  return prev;
}

template<typename Node> Node* ReversePartList(Node* head, int m, int n){
  if(!head || !head->next || m < 1 || n <= 1){
    return head;
  }

  Node* prev = NULL;
  Node* curr = head;

  for(int i = 0; i < m - 1 && curr ; ++i){
    prev = curr;
    curr = curr->next;
  }

  if(!curr){
    return head;
  }

  Node* last_tail = prev;
  Node* reversed_tail = curr;
  Node* next = NULL;
  int count = 0;
  while(curr && count < n){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    ++count;
  }
  Node* new_head = prev;
  if(last_tail){
    last_tail->next = new_head;
    new_head = head;
  }
  reversed_tail->next = curr;
  return new_head;
}

Node* ConstructList(const std::string& list){
  std::istringstream is(list);
  Node* head = NULL;
  Node* tail = NULL;
  int value;
  while(is >> value){
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

void PrintList(Node* head){
  std::cout << "head -> ";
  Node* curr = head;
  while(curr){
    std::cout << curr->value << " -> ";
    curr = curr->next;
  }
  std::cout << "NULL" << std::endl;
}

void RevertListTest(){
  std::string line;

  while(!std::cin.eof()){
    do {
      getline(std::cin, line);
    } while(line.empty() || line[0] != '>');
    std::cout << "Input:" << line << std::endl;

    Node* input_head = ConstructList(line.substr(1, line.size() -1 ));
    PrintList(input_head);

    Node* reversed_head = ReverseList(input_head);

    do {
      getline(std::cin, line);
    } while(line.empty() || line[0] != '>');
    std::cout << "Output:" << line << std::endl;
    Node* output_head = ConstructList(line.substr(1, line.size() -1 ));
    PrintList(output_head);
    if(!AssertTrue(IsListEqual(reversed_head, output_head))){
      std::cout << "Faild: " << std::endl;
      PrintList(reversed_head);
      return;
    }
  }
  std::cout << "======================" << std::endl;
  std::cout << "|   Test passed.     |" << std::endl;
  std::cout << "======================" << std::endl;

}

void KthRevertListTest(){
  std::string line;

  while(!std::cin.eof()){
    do {
      getline(std::cin, line);
    } while(line.empty() || line[0] != '>');
    std::cout << "Input:" << line << std::endl;

    Node* input_head = ConstructList(line.substr(1, line.size() -1 ));
    PrintList(input_head);

    do {
      getline(std::cin, line);
    } while(line.empty() || line[0] != '>');
    int k;
    std::istringstream is(line.substr(1, line.size() -1 ));
    is >> k;
    std::cout << "K:" << k << std::endl;

    Node* reversed_head = KthReverseList(input_head, k);

    do {
      getline(std::cin, line);
    } while(line.empty() || line[0] != '>');
    std::cout << "Output:" << line << std::endl;
    Node* output_head = ConstructList(line.substr(1, line.size() -1 ));
    PrintList(output_head);

    if(!AssertTrue(IsListEqual(reversed_head, output_head))){
      std::cout << "Faild: " << std::endl;
      PrintList(reversed_head);
      return;
    }
  }
  std::cout << "======================" << std::endl;
  std::cout << "|   Test passed.     |" << std::endl;
  std::cout << "======================" << std::endl;

}

void ReversePartListTest(){
  std::string line;

  while(!std::cin.eof()){
    do {
      getline(std::cin, line);
    } while(line.empty() || line[0] != '>');
    std::cout << "Input:" << line << std::endl;

    Node* input_head = ConstructList(line.substr(1, line.size() -1 ));
    PrintList(input_head);

    do {
      getline(std::cin, line);
    } while(line.empty() || line[0] != '>');
    int m;
    {
      std::istringstream is(line.substr(1, line.size() -1 ));
      is >> m;
    }
    std::cout << "m: " << m << std::endl;

    do {
      getline(std::cin, line);
    } while(line.empty() || line[0] != '>');
    int n;
    {
      std::istringstream is(line.substr(1, line.size() -1 ));
      is >> n;
    }
    std::cout << "n: " << n << std::endl;

    Node* reversed_head = ReversePartList(input_head, m, n);

    do {
      getline(std::cin, line);
    } while(line.empty() || line[0] != '>');
    std::cout << "Output:" << line << std::endl;
    Node* output_head = ConstructList(line.substr(1, line.size() -1 ));
    PrintList(output_head);

    if(!AssertTrue(IsListEqual(reversed_head, output_head))){
      std::cout << "Faild: " << std::endl;
      PrintList(reversed_head);
      return;
    }
  }
  std::cout << "======================" << std::endl;
  std::cout << "|   Test passed.     |" << std::endl;
  std::cout << "======================" << std::endl;

}

#endif
