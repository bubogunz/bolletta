#include <iostream>

using namespace std;
//liberamente ispirato all'appello del 25-06-2013
class Empty { }; //classe eccezione stack vuoto

template<class T=int>
class stack;
template<class T=int>
class queue;
template<class T=int>
class node;
template<class T=int>
ostream& operator<<(ostream& os, const node<T>& n);
template<class T=int>
ostream& operator<<(ostream& os, const queue<T>& n);
template<class T=int>
ostream& operator<<(ostream& os, const stack<T>& n);

template<class T>
class node{
private:
    friend class stack<T>;
    friend class queue<T>;
    friend ostream& operator<< <T>(ostream& os, const node<T>& n);
    friend ostream& operator<< <T>(ostream& os, const stack<T>& n);
    friend ostream& operator<< <T>(ostream& os, const queue<T>& n);
    T info;
    node* next;
public:
    node(): info(), next(nullptr) { }
    node(const node& n): info(n.info), next(nullptr) { }
    node(const T& t, node* n=nullptr): info(t), next(n) { }
};
template<class T>
ostream& operator<<(ostream& os, const node<T>& n){
    return os << n.info;
}

template<class T>
class stack{ //LIFO
private:
    friend ostream& operator<< <T>(ostream& os, const stack<T>& n);
    node<T>* first, *last;
public:
    stack(): first(nullptr), last(nullptr) { }
    stack(int k, const T& t){ //costruttore che costruisce k nodi, tutti contenenti t
        if(k){
            node<T>* L;
            first = L = last = new node<T>(t); --k;
            while(k){
                last = L->next = new node<T>(t);
                --k; L = L->next;
            }
        }
        else first = last = nullptr;
    }
    bool isEmpty() const {
        return first;
    }
    void push(const T& t){
        if(!first) first = last = new node<T>(t);
        first = new node<T>(t,first);
    }
    T pop(){
        if(!first) throw Empty();
        T& t = first->info;
        node<T>* L = first->next;
        delete first;
        if(!L) last = nullptr;
        first = L;
        return t;
    }
    T* top() const{ //restituisce il puntatore al primo elemento dello stack
        if(!first) return nullptr;
        return &(first->info);
    }
    node<T>* copy(node<T>* c) const{
        if(c){
            node<T>* f = new node<T>(*c);
            f->next = copy(c->next);
            return f;
        }
    }
    void destroy(node<T>* n){
        if(n){
            destroy(n->next);
            delete n;
        }
    }
    ~stack(){
        if(first) destroy(first);
    }
    stack& operator=(const stack& s){
        if(this != &s){
            delete this;
            node<T>* L;
            L = first = copy(s.first);
            for(; L->next != nullptr; L=L->next)
                L = L->next;
            last = L;
            return *this;
        }
    }
    node<T>& operator[](int k) const{ //overloading dell'operatore [] così da poter usare lo stack come se fosse un array
        node<T>* L = first;
        while(k && L->next){
            L = L->next;
            --k;
        }
        return *L;
    }
};
template<class T>
ostream& operator<<(ostream& os, const stack<T>& n){
    for(node<T>* i = n.first; i != nullptr; i = i->next)
        os << *i << ' ';
    return os;
}

template<class T>
class queue{ //FIFO
private:
    friend ostream& operator<< <T>(ostream& os, const queue<T>& n);
    node<T>* first, *last;
public:
    queue(): first(nullptr), last(nullptr) { }
    queue(int k, const T& t){ //costruttore che costruisce k nodi, tutti contenenti t
        if(k){
            node<T>* L;
            first = L = last = new node<T>(t); --k;
            while(k){
                last = L->next = new node<T>(t);
                --k; L = L->next;
            }
        }
        else first = last = nullptr;
    }
    bool isEmpty() const {
        return first;
    }
    void push(const T& t){
        if(!first) first = last = new node<T>(t);
        last->next = new node<T>(t);
        last = last->next;
    }
    T pop(){
        if(!first) throw Empty();
        T& t = first->info;
        node<T>* L = first->next;
        delete first;
        if(!L) last = nullptr;
        first = L;
        return t;
    }
    T* top() const{ //restituisce il puntatore al primo elemento dello stack
        if(!first) return nullptr;
        return &(first->info);
    }
    node<T>* copy(node<T>* c) const{
        if(c){
            node<T>* f = new node<T>(*c);
            f->next = copy(c->next);
            return f;
        }
    }
    void destroy(node<T>* n){
        if(n){
            destroy(n->next);
            delete n;
        }
    }
    ~queue(){
        if(first) destroy(first);
    }
    queue& operator=(const queue& s){
        if(this != &s){
            delete this;
            node<T>* L;
            L = first = copy(s.first);
            for(; L->next != nullptr; L=L->next)
                L = L->next;
            last = L;
            return *this;
        }
    }
    node<T>& operator[](int k) const{ //overloading dell'operatore []
        node<T>* L = first;
        while(k && L->next){
            L = L->next;
            --k;
        }
        return *L;
    }
};
template<class T>
ostream& operator<<(ostream& os, const queue<T>& n){
    for(node<T>* i = n.first; i != nullptr; i = i->next)
        os << *i << ' ';
    return os;
}

int main(){
    stack<char> c(6, 'k');
    c.push('b');
    cout << c << endl;
    char e = c.pop();
    cout << c << endl;
    queue<char> x(7, '@');
    cout << x << endl;
    x.push('b');
    cout << x << endl;
    e = x.pop();
    cout << x << endl;
    cout << x[6] << " = b" << endl;
    cout << c[0] << " = k" << endl;
}


