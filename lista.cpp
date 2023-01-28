#include <iostream>

using namespace std;

struct element {
    int nr_element;
    element *nastepny; // wskaznik na nastepny element
    element(); // konstruktor
};

element::element() {
    nastepny = 0; // konstruktor
}

struct lista {
    element *pierwszy; // wskaznik na poczatek listy
    void dodaj_element(int element);
    void usun_element(int nr);
    void wyswietl_liste();
    void zlicz_elementy();
    void wyszukaj_element(int szukany_element);
    lista();
};
void lista::dodaj_element(int nr_element)
{
    element *nowy = new element;    // tworzy nowy element listy

    // wypelniamy naszymi danymi
    nowy->nr_element = nr_element;

    if (pierwszy==0) // sprawdzamy czy to pierwszy element listy
    {
        // je¿eli tak to nowy element jest teraz pocz¹tkiem listy
        pierwszy = nowy;
    }
    else
    {
        // w przeciwnym wypadku wedrujemy na koniec listy
        element *temp = pierwszy;

        while (temp->nastepny)
        {
            // znajdujemy wskaznik na ostatni element
            temp = temp->nastepny;
        }

        temp->nastepny = nowy;  // ostatni element wskazuje na nasz nowy
        nowy->nastepny = 0;     // ostatni nie wskazuje na nic
    }
}

lista::lista() {
    pierwszy = 0; // konstruktor
}
void lista::usun_element (int nr)
{
    // jezeli to pierwszy element listy
    if (nr==1)
    {
        element *temp = pierwszy;
        pierwszy = temp->nastepny; //ustawiamy poczatek na drugi element
        delete temp; // usuwamy stary pierwszy element z pamieci
    }
    // jezeli nie jest to pierwszy element
    else if (nr>=2)
    {
        int j = 1;

        // do usuniecia srodkowego elemetnu potrzebujemy wskaznika na element n-1
        // wskaznik *temp bedzie wskaznikiem na element poprzedzajacy element usuwany
        element *temp = pierwszy;

        while (temp)
        {
            // sprawdzamy czy wskaznik jest na elemencie n-1 niz usuwany
            if ((j+1)==nr) break;

            // jezeli nie to przewijamy petle do przodu
            temp = temp->nastepny;
            j++;
        }

        // wskaznik *temp wskazuje teraz na element n-1
        // nadpisujemy wkaznik n-1 z elementu n na element n+1
        // bezpowrotnie tracimy elemeny n-ty

        // jezeli usuwamy ostatni element listy
        if (temp->nastepny->nastepny==0) {
            delete temp->nastepny;
            temp->nastepny = 0;
        }
        // jezeli usuwamy srodkowy element
        else {
            element *usuwany = temp->nastepny;
            temp->nastepny = temp->nastepny->nastepny;
            delete usuwany;
        }
    }
}
void lista::wyswietl_liste()
{
    // wskaznik na pierszy element listy
    element *temp = pierwszy;

    // przewijamy wskazniki na nastepne elementy
    while (temp)
    {
        cout << "element: " << temp->nr_element<< endl;
        temp=temp->nastepny;
    }
}
void lista::zlicz_elementy()
{
    // wskaznik na pierwszy element listy
    element *temp = pierwszy;

    // przewijamy wskazniki na nastepne elementy
    int a=0;
    while (temp)
    {
        a++;
        cout << "element nr: " << a<< endl;
        temp=temp->nastepny;
    }
}
void lista::wyszukaj_element(int szukany_element)
{
    // wskaznik na pierwszy element listy
    element *temp = pierwszy;

    // przewijamy wskazniki na nastepne elementy
    int a=0;
    while (temp)
    {
        a++;
        if(temp->nr_element==szukany_element){
            cout<<"Szukany element to "<<a<<" element listy";
            break;
        }
        temp=temp->nastepny;
    }
}

int main()
{
    lista *baza = new lista;    //tworzymy liste

    //dodajemy rekordy do bazy
    baza->dodaj_element(23);
    baza->dodaj_element(44);
    baza->dodaj_element(19);
    baza->dodaj_element(21);
    baza->zlicz_elementy();
    baza->wyszukaj_element(19);
    // wyswietlamy 1. element
    cout << baza->pierwszy->nr_element << endl;

    // wyswietlamy 2. element
    cout << baza->pierwszy->nastepny->nr_element << endl;


    delete (baza);

    return 0;
}
