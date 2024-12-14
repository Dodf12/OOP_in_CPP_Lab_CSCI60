#include "node.h"
#include <iostream>

node::node(){
  data_ = 0;
  link_ = nullptr;
}
node::node(const int& initdata, node * initlink)
{
    data_ = initdata;
    link_ = initlink;
}

int node::data() const
{
    return data_;
}

node * node::link()
{
    return link_;
}

//returns constant node pointer
const node * node::link() const//This is a const function - I promise the function doesn't change anything - On a const node*, you can only call const functions
{
    return link_;
}

void node::set_data(const int & newdata)
{
    data_ = newdata;
}

void node::set_link(node * newlink)
{
    link_ = newlink;
}

bool isInList(int val, node *head, node *tail)
{
    if (head == nullptr) { return false; }
    if (head->data() == val) { return true; }
    return isInList(val, head->link(), tail);
}

int main()
{
    node *node2 = new node(2, nullptr);
    node *head = new node(1, node2);
    node *tail = node2;
    delete node2;
    std::cout << isInList(2, head, tail) << std::endl;
    std::cout << 'h' << std::endl;
}













