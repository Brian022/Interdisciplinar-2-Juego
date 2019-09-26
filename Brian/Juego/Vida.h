#include <iostream>

using namespace std;

template<typename T>
class Node
{
    public:
    Node<T> *sgte;
    T data;

    Node(T data){this->data = data;}

    void imprimirN ()const
    {
        cout << data << "-> ";
    }

};

template<typename T>
class Lista
{
    public:

    Node<T> *head;
    Node<T> *actual;

    Lista(T data)
    {
        head = new Node<T>(data);
        return;
    }

    void add(T data)
    {

        Node<T> *actual = head;
        while(actual->sgte != NULL){actual = actual->sgte;}
        actual->sgte = new Node<T>(data);
    }


    void addF(T data)
    {
        Node<T> *newHead = new Node<T>(data);
        newHead->sgte = head;
        head = newHead;
    }

    void deleteV(T x)
    {

        if(head->data == x)
        {
            Node<T> *temp = head;
            head = head->sgte;
            delete temp;
            return;
        }

        Node<T> *actual = head;
        while(actual->sgte != NULL)
        {
            if(actual->sgte->data == x)
            {
                actual->sgte = actual->sgte->sgte;
                return;
            }
            actual = actual->sgte;
        }

    }

    void imprimir()const
    {
        Node<T> *temp = head;
        if (!head) {
            cout << "Lista no inicializada " << endl;
        } else {
            while (temp) {
                temp->imprimirN();
                if (!temp->sgte) cout << "NULL";
                    temp = temp->sgte;
            }
      }
      cout << endl << endl;
    }
};


template<typename T>
class Iterator
{
    Node<T> *iter;
    Node<T> *head;

    public:

    void operator =(Node<T> * nodo)
    {
        iter = nodo;
        head = nodo;
    }

    void operator++()
    {
        iter= iter->sgte;
    }

    void datos()
    {
        cout<<iter->data<<"\n";
    }
    bool hasMore()
    {
        if(iter->sgte != NULL)
            return true;
        else
            return false;
    }

    void found(T n)
    {
        if(head->data == n)
        {
            cout<<"Se encontro!!"<<n<<"\n";
        }

        Node<T> * temp = head;
        while(temp->sgte != NULL)
            {
                if(temp->sgte->data == n)
                {
                    cout<<"Se encontro!!"<<n<<"\n";
                    break;
                }
                else if(temp->sgte == NULL)
                {
                    if(temp->data == n)
                        cout<<"Se encontro!!"<<n<<"\n";
                }
            }

    }


};
/*
int main()
{
    Lista<int> a(9);
    a.add(5);
    a.add(4);
    a.add(3);
    a.add(2);
    a.add(15);
    a.addF(4);
    a.imprimir();
    a.deleteV(4);
    a.deleteV(4);
    a.imprimir();

    Iterator<int> iterador;
    iterador = a.head;
    iterador.hasMore();
    iterador.datos();
    ++iterador;
    while(iterador.hasMore())
    {
        iterador.datos();
        ++iterador;
        if(!iterador.hasMore())
            iterador.datos();

    }

    iterador.found(5);
    iterador.found(15);
    return 0;
}
*/
