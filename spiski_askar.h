#ifndef SPISKI_ASKAR_H
#define SPISKI_ASKAR_H

#include <iostream>

using namespace std;

struct List
{
    private:
        struct Node;
        Node *Head, *Tail;
        int count;

        Node* MSort(Node *L, int Length);

    public:
        List();
        List(int Data);
        ~List();

        int AddToTop(int Data);
        int AddToBottom(int Data);
        int Get(int Index);
        int RemoveFirst();
        int Count();

        //Ф-ии Тагирыча

        int Add(int Index, int Data);	//добавления нового элемента в линейный список после элемента с заданным номером
        int AddVal(int Data, int Val);	//добавления нового элемента в линейный список перед элементом с заданным значением
        int AddBetPairs(int Data);		//добавления нового элемента в линейный список между всеми парами элементов с одинаковыми значениями
        void RemovePairs();				//удаления из линейного списка повторяющихся элементов с одинаковыми значениями (первый с таким значением остается, а остальные удаляются)
        List* Merging(List *L);			//Слияние 2-х упорядоченных линейных списков
        void PrintNR(List *L);			//Напечатать из первого списка все те элементы, которых нет во 2-м
        void MergeSort();				//Упорядочить элементы списка по возрастанию
};

struct List::Node
{
    public:
        int Data;
        Node* Next;

        Node();
        Node(int Data);
        ~Node();
};

List::Node::Node()
{
    this->Data = 0;
    this->Next = NULL;
}

List::Node::Node(int Data)
{
    this->Data = Data;
    this->Next = NULL;
}

List::Node::~Node()
{
    if (this->Next)
        delete this->Next;
}

List::List()
{
    this->Head = this->Tail = NULL;
    this->count = 0;
}

List::List(int Data)
{
    this->Head = this->Tail = new Node(Data);
    this->count = 1;
}

int List::AddToTop(int Data)
{
    Node* newNode = new List::Node(Data);
    newNode->Next = this->Head;
    this->Head = newNode;
    this->count++;
    if (this->count ==1)
        this->Tail = this->Head;
    return Data;
}

int List::AddToBottom(int Data)
{
    if (!this->count)
        return this->AddToTop(Data);
    this->Tail->Next = new List::Node(Data);
    this->Tail = this->Tail->Next;
    this->count++;
    return Data;
}

int List::Get(int Index)
{
    Node *Aux = this->Head;
    int i = 0;
    while (i++ < Index)
        Aux = Aux->Next;
    return Aux->Data;
}

int List::RemoveFirst()
{
    if (this->count)
    {
        int Result = this->Head->Data;
        Node *Aux = this->Head;
        this->Head = this->Head->Next;
        Aux->Next = NULL;
        delete Aux;
        this->count--;
        return Result;
    }
    return -1;
}

int List::Count()
{
    return this->count;
}

int List::Add(int Index, int Data)
{
    Node *Aux = this->Head, *newNode = new List::Node(Data);
    int i = 0;
    while (i++ < Index)
        Aux = Aux->Next;
    newNode->Next = Aux->Next;
    Aux->Next = newNode;
    this->count++;
    return Data;
}

int List::AddVal(int Data, int Val)
{
    if (!this->count)
        return -1;
    if (this->Head->Data == Val)
        return this->AddToTop(Data);
    Node *Aux = this->Head;
    while (Aux->Next && Aux->Next->Data != Val)
        Aux = Aux->Next;
    if (Aux->Next)
    {
        Node *newNode = new List::Node(Data);
        newNode->Next = Aux->Next;
        Aux->Next = newNode;
    }
    this->count++;
    return Data;
}

int List::AddBetPairs(int Data)
{
    Node *Aux = this->Head, *newNode;
    for (; Aux && Aux->Next; Aux = Aux->Next)
        if (Aux->Data == Aux->Next->Data)
        {
            newNode = new List::Node(Data);
            newNode->Next = Aux->Next;
            Aux->Next = newNode;
            Aux = Aux->Next;
            this->count++;
        }
    return Data;
}

void List::RemovePairs()
{
    Node *Aux0 = this->Head, *Aux1, *Aux2;
    while (Aux0)
    {
        Aux1 = Aux0;
        while (Aux1->Next)
            if (Aux1->Next->Data == Aux0->Data)
            {
                Aux2 = Aux1->Next;
                Aux1->Next = Aux1->Next->Next;
                Aux2->Next = NULL;
                delete Aux2;
                this->count--;
            }
            else
                Aux1 = Aux1->Next;
        Aux0 = Aux0->Next;
    }
}

List* List::Merging(List *L)
{
    List *Result = new List();
    Node *First = this->Head, *Second = L->Head, *Aux;
    while (First && Second)
    {
        if (First->Data < Second->Data)
            Aux = First,
            First = First->Next;
        else
            Aux = Second,
            Second = Second->Next;
        Result->AddToBottom(Aux->Data);
        Aux->Next = NULL;
        delete Aux;
    }
    if (Second)
        First = Second;
    while (First)
        Result->AddToBottom(First->Data),
        Aux = First,
        First = First->Next,
        Aux->Next = NULL,
        delete Aux;
    Result->count = this->count + L->count;
    return Result;
}

void List::PrintNR(List *L)
{
    Node *Aux0 = this->Head, *Aux1;
    while (Aux0)
    {
        Aux1 = L->Head;
        while(Aux1 && Aux1->Data != Aux0->Data)
            Aux1 = Aux1->Next;
        if (!Aux1)
            std::cout << Aux0->Data << " ";
        Aux0 = Aux0->Next;
    }
}

List::Node* List::MSort(List::Node *L, int Length)
        {
            if (!L->Next)
                return L;
            Node *N = L, *M, *Result, *Tail;
            int i = Length / 2;
            while (--i)
                N = N->Next;
            M = N->Next;
            N->Next = NULL;
            M = this->MSort(M, Length - Length / 2);
            L = this->MSort(L, Length / 2);
            if (L->Data < M->Data)
                Result = L,
                L = L->Next;
            else
                Result = M,
                M = M->Next;
            Tail = Result;
            while (L && M) //:D
                if (L->Data < M->Data)
                    Tail->Next = L,
                    L = L->Next,
                    Tail = Tail->Next;
                else
                    Tail->Next = M,
                    M = M->Next,
                    Tail = Tail->Next;
            if (M)
                L = M;
            while (L)
                Tail->Next = L,
                L = L->Next,
                Tail = Tail->Next;
            return Result;
        }

void List::MergeSort()
{
    this->Head = this->MSort(this->Head, this->count);
}

List::~List()
{
    if (this->count)
        delete this->Head;
}

void example()
{
    //Проверка работы всех методов

    List *A = new List(), *B = new List(), *C;
    int i;
    for (i = 0; i < 10; i++)
        A->AddToBottom(i);
    for (i = 0; i < 10; i++)
        cout << A->Get(i) << " ";
    cout << endl;

    for (i = 0; i < 5; i++)
        A->Add(4, i);
    for (i = 0; i < A->Count(); i++)
        cout << A->Get(i) << " ";
    cout << endl;

    for (i = 0; i < 3; i++)
        A->AddToTop(10);
    for (i = 0; i < A->Count(); i++)
        cout << A->Get(i) << " ";
    cout << endl;

    A->AddBetPairs(10);
    for (i = 0; i < A->Count(); i++)
        cout << A->Get(i) << " ";
    cout << endl;

    A->AddVal(10, 1);
    for (i = 0; i < A->Count(); i++)
        cout << A->Get(i) << " ";
    cout << endl;

    A->RemovePairs();
    for (i = 0; i < A->Count(); i++)
        cout << A->Get(i) << " ";
    cout << endl;

    A->RemoveFirst();
    for (i = 0; i < A->Count(); i++)
        cout << A->Get(i) << " ";
    cout << endl;

    for (i = 5; i > 0; i--)
        B->AddToBottom(i);
    for (i = 0; i < B->Count(); i++)
        cout << B->Get(i) << " ";
    cout << endl;

    B->MergeSort();
    for (i = 0; i < B->Count(); i++)
        cout << B->Get(i) << " ";
    cout << endl;

    C = A->Merging(B);
    for (i = 0; i < C->Count(); i++)
        cout << C->Get(i) << " ";
    cout << endl;

}

#endif // SPISKI_ASKAR_H
