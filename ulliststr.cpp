#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


//Function implementation

void ULListStr::push_back(const std::string& val){
  if(head_ == nullptr){ //case 1 its empty
    Item* newItem = new Item;

    newItem->first = 0;
    newItem->last = 0;

    head_ = tail_ = newItem;

    tail_->val[tail_->last] = val;
    tail_->last++;

    size_++;

  } else if(tail_->last < ARRSIZE){ //case 2 tail has room in the back
    tail_->val[tail_->last] = val;

    tail_->last++;

    size_++;

  } else{ //case 3 tail is full and need to allocate a new node
    Item* newItem = new Item;
    
    newItem->first = 0;
    newItem->last = 0;

    newItem->prev = tail_;
    tail_->next = newItem;
    newItem->next = nullptr;
    tail_ = newItem;

    tail_->val[0] = val;
    tail_->last++;

    size_++;
  }

}


void ULListStr::pop_back(){

  if (head_ == nullptr) return;

  if(tail_->last - tail_->first > 1){
    tail_->last--;
  
  }else{
    Item* old_tail = tail_;
    tail_ = tail_->prev;
    
    if(tail_){
      tail_->next = nullptr;
    }else{
      head_ = nullptr;
      
    }
    delete old_tail;
  }

  size_--;
}


void ULListStr::push_front(const std::string& val){
  if(head_ == nullptr){ 
    Item* newItem = new Item;

    newItem->first = 0;
    newItem->last = 0;

    head_ = tail_ = newItem;

    head_->val[head_->first] = val;
    head_->last++;

    size_++;

  }else if(head_->first > 0){
    
    head_->first--;
    head_->val[head_->first] = val;
    
    
    size_++;
  }else{
    Item* newItem = new Item;

    newItem->first = ARRSIZE - 1;
    newItem->last = ARRSIZE;

    newItem->val[newItem->first] = val;

    newItem->next = head_; 
    head_->prev = newItem;
    newItem->prev = nullptr;
    head_ = newItem; 
    size_++;
  }

}



void ULListStr::pop_front(){
  if (!head_) return;

  if (head_->last - head_->first > 1){
    head_->first++;
  
  }else{
    Item* old_head = head_;
    head_ = head_->next;

    if(head_){
      head_->prev = nullptr;
    }else{
      tail_ = nullptr;
    }
    delete old_head;
  }
  size_--;
}


std::string const& ULListStr::back() const{

  if (size_ == 0) throw std::invalid_argument("empty list");

  return tail_->val[tail_->last - 1];
}


std::string const & ULListStr::front() const{
  if (size_ == 0) throw std::invalid_argument("empty list");

  return head_->val[head_->first];
}


std::string* ULListStr::getValAtLoc(size_t loc) const{
  //returns pointer to the i-th element 
  //if location doesnt exit return nullptr
  //pointer to the element will be loc 
  //O(1) front & end
  //O(n) walk through list, use while loop
  
  //case 1 empty 

  //case 2 in this block 

  //case 3 not there, go next node

  if(loc >= size_) return nullptr; 

  Item* cur = head_;
  size_t index = loc;

  while(cur){
    size_t items_in_block = cur->last - cur->first;

    if(index < items_in_block){ //item could be in block
      return &cur->val[cur->first + index];
    }

    index -= items_in_block;

    cur = cur->next;
  }

  return nullptr;
}