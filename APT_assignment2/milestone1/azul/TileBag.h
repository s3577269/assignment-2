#ifndef TILE_BAG_H
#define TILE_BAG_H 

#include "Type.h"
#include "BoxLid.h"

class Node {
public:
   Node(Tile tile, Node* next);

   Tile tile;
   Node* next;
};

class TileBag {
public:
   TileBag(bool enhanced, int seed);
   TileBag(TileBag& other);
   ~TileBag();

   /**
    * Return the current size of the Tile Bag.
    */
   int size() const;

   /**
    * Get the tile at the given index.
    */
   Tile get(int index);

   /**
    * Add the tile to the back of the Tile Bag
    */
   void addBack(Tile tile);

   /**
    * Remove the tile at the front of the Tile Bag
    */
   void removeFront();

   /**
    * Removes all tiles from the Tile Bag
    */
   void clear();

   // prepare the Tile bag - shuffle box lid if there's one, move tiles from box lid to the tile bag
   void prepare();
private:
   void addTile(Tile tile);

   Node* head;
   BoxLid* boxLid = nullptr;
};

#endif // TILE_BAG_H
