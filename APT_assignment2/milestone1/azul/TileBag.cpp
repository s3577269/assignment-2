
#include "TileBag.h"

#include <iostream>
#include <fstream>
#include <exception>

Node::Node(Tile tile, Node* next) :
   tile(tile),
   next(next)
{}

TileBag::TileBag(bool enhanced, int seed){
   head = nullptr;
   if(enhanced && seed!=0)
      boxLid = new BoxLid(seed);
}

TileBag::TileBag(TileBag& other) {
   head = nullptr;
   for(int i=0;i!=other.size();++i){
      addBack(other.get(i));
   }
}

TileBag::~TileBag() {
   clear();
   delete boxLid;
}

int TileBag::size()  const{
   int count = 0;
   Node* current = head;
   while(current!=nullptr){
      ++count;
      current = current->next;
   }
   return count;
}

Tile TileBag::get(int index){
   if (size()==0 && boxLid)
   {
      prepare();
   }
   
   int count = 0;
   Node* current = head;
   Tile returnValue = NO_TILE;
   if(index>=0&&index<size()){
      while(count<index){
         ++count;
         current = current->next;
      }
      returnValue = current->tile;
   } else {
      throw std::out_of_range("Linked List get - index out of range");
   }
   return returnValue;
}

void TileBag::addBack(Tile tile) {
   if(boxLid)
   {
      boxLid->addTile(tile);
   }
   else
   {
      addTile(tile);
   }
}

void TileBag::removeFront() {
   if(head!=nullptr){
      Node* current = head;
      head = head->next;
      delete current;
   }
}

void TileBag::clear() {
   while(head!=nullptr){
      removeFront();
   }
}

void TileBag::addTile(Tile tile)
{
   Node* toAdd = new Node(tile, nullptr);
   if(head == nullptr){
      head = toAdd;
   } else {
      Node* current = head;
      while(current->next!=nullptr){
         current = current->next;
      }
      current->next = toAdd;
   }
}

void TileBag::prepare()
{
   if (boxLid)
   {
      boxLid->shuffle();
      for (const auto& t:  boxLid->tiles)
      {
         addTile(t);
      }
      boxLid->clear();      
   }
   
}
