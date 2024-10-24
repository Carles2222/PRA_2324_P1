#ifndef LIST_H
#define LIST_H

template <typename T> 
class List {
public:
    virtual ~List() {}  

    
    virtual void insert(const T& item) = 0;   
    virtual void remove(const T& item) = 0;   
    virtual T get(int index) const = 0;       
    virtual int size() const = 0;             
    virtual bool isEmpty() const = 0;         
};

#endif

