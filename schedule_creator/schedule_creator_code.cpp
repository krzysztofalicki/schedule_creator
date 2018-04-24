#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <math.h>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;



class Node2 //klasa obiektow z danymi - sala, wykladowca, grupa, przedmiot
{
public:

	int id;
	string nazwa1;
	string nazwa2;

	Node2 *next;
	Node2 *prev;
};




class Node //klasa obiektow z danymi - zajecie
{
public:

	Node2 *id_sala;
	Node2 *id_wykl;
	Node2 *id_grup;
	Node2 *id_prze;

	Node *next;
	Node *prev;
};

class Lista //pojedynczy blok zajec - jako lista zajec
{

public:

	Node *head;
	Node *tail;
	Node *current;

public:

	Lista(Node*h = NULL, Node*t = NULL, Node*c = NULL)
	{
		head = h;
		tail = t;
		current = c;
	}



	Node *createzero()
	{
		Node *nev;
		nev = new (Node);
		nev->id_sala = NULL;
		nev->id_wykl = NULL;
		nev->id_grup = NULL;
		nev->id_prze = NULL;
		nev->next = NULL;
		nev->prev = NULL;

		return nev;
	}



	void addlastzero()
	{
		Node *tmp = createzero();

		if (head == NULL)
			head = tmp;
		else {
			Node *pom = head;
			while (pom->next != NULL)
				pom = pom->next;
			pom->next = tmp;
			tmp->prev = pom;
		}

		tail = tmp;
	}



	void deletecurrent()
	{
		if (current == head && current == tail) {
			head = NULL;
			tail = NULL;
		}
		else if (current == head) {
			head = (current->next);
			(current->next)->prev = NULL;
		}
		else if (current == tail) {
			tail = (current->prev);
			(current->prev)->next = NULL;
		}
		else {
			(current->next)->prev = (current->prev);
			(current->prev)->next = (current->next);
		}

		delete current;
	}




	void moveright()
	{
		current = current->next;
	}


	void deleteall()
	{
		if (head == NULL);
		else
		{
			Node *pom = head;
			Node *tmp;
			while (pom->next != NULL)
			{
				tmp = pom;
				pom = (pom->next);
				delete tmp;
			}
			delete pom;
			head = NULL;
			tail = NULL;
			current = NULL;
		}
	}



	void showcurrent()
	{
		if (current == NULL)
			cout << "EMPTY!!!" << endl;
		else
		{
			//cout << endl;
			cout << "Sala:\t\t";
			cout << (current->id_sala)->nazwa1 << "   ";
			cout << (current->id_sala)->nazwa2 << endl;
			cout << "Profesor:\t";
			cout << (current->id_wykl)->nazwa1 << "   ";
			cout << (current->id_wykl)->nazwa2 << endl;
			cout << "Grupa:\t\t";
			cout << (current->id_grup)->nazwa1 << "   ";
			cout << (current->id_grup)->nazwa2 << endl;
			cout << "Przedmiot:\t";
			cout << (current->id_prze)->nazwa1 << "   ";
			cout << (current->id_prze)->nazwa2 << endl;
			//cout << endl;
		}
	}


	void showall()
	{
		if (head == NULL)
			cout << "EMPTY!!!" << endl;
		else
		{
			current = head;
			while (current->next != NULL)
			{
				showcurrent();
				cout << endl;
				current = current->next;
			}
			showcurrent();
		}
	}



	void showcurrent2()
	{
		if (current == NULL)
			cout << "EMPTY!!!" << endl;
		else
		{
			cout << "Sala:\t\t";
			cout << (current->id_sala)->id << "   ";
			cout << (current->id_sala)->nazwa1 << "   ";
			cout << (current->id_sala)->nazwa2 << endl;
			cout << "Profesor:\t";
			cout << (current->id_wykl)->id << "   ";
			cout << (current->id_wykl)->nazwa1 << "   ";
			cout << (current->id_wykl)->nazwa2 << endl;
			cout << "Grupa:\t\t";
			cout << (current->id_grup)->id << "   ";
			cout << (current->id_grup)->nazwa1 << "   ";
			cout << (current->id_grup)->nazwa2 << endl;
			cout << "Przedmiot:\t";
			cout << (current->id_prze)->id << "   ";
			cout << (current->id_prze)->nazwa1 << "   ";
			cout << (current->id_prze)->nazwa2 << endl;
			cout << endl;
		}
	}


	void showall2()
	{
		if (head == NULL)
			cout << "EMPTY!!!" << endl;
		else
		{
			cout << endl << "LISTA ZAJEC:" << endl;
			int i = 1;
			current = head;
			while (current->next != NULL)
			{
				cout << "ZAJECIE NR " << i << endl;
				showcurrent2();
				cout << endl;
				current = current->next;
				i++;
			}
			cout << "ZAJECIE NR " << i << endl;
			showcurrent2();
		}
	}




	void savecurrent(fstream *file)
	{
		//cout << endl;
		(*file) << "Sala:\t\t"
			<< (current->id_sala)->nazwa1 << "   "
			<< (current->id_sala)->nazwa2 << endl
			<< "Profesor:\t"
			<< (current->id_wykl)->nazwa1 << "   "
			<< (current->id_wykl)->nazwa2 << endl
			<< "Grupa:\t\t"
			<< (current->id_grup)->nazwa1 << "   "
			<< (current->id_grup)->nazwa2 << endl
			<< "Przedmiot:\t"
			<< (current->id_prze)->nazwa1 << "   "
			<< (current->id_prze)->nazwa2 << endl;
		//cout << endl;
	}



	~Lista()
	{
		deleteall();
	}

};





class Lista2 //obsluga list sal, wykladowcow, przedmiotow, grup
{

public:

	int last_id;
	Node2 *head;
	Node2 *tail;
	Node2 *current;

public:

	Lista2(int id = 0, Node2*h = NULL, Node2*t = NULL, Node2*c = NULL)
	{
		last_id = id;
		head = h;
		tail = t;
		current = c;
	}



	Node2 *createzero()
	{
		Node2 *nev;
		nev = new (Node2);
		nev->id = 0;
		nev->nazwa1 = "0";
		nev->nazwa2 = "0";
		nev->next = NULL;
		nev->prev = NULL;

		return nev;
	}



	void addlastzero()
	{
		Node2 *tmp = createzero();

		if (head == NULL)
			head = tmp;
		else {
			Node2 *pom = head;
			while (pom->next != NULL)
				pom = pom->next;
			pom->next = tmp;
			tmp->prev = pom;
		}

		tail = tmp;
	}




	void moveright()
	{
		current = current->next;
	}


	void deleteall()
	{
		if (head == NULL);
		else
		{
			Node2 *pom = head;
			Node2 *tmp;
			while (pom->next != NULL)
			{
				tmp = pom;
				pom = (pom->next);
				delete tmp;
			}
			delete pom;
			head = NULL;
			tail = NULL;
			current = NULL;
		}
	}



	void showcurrent()
	{
		if (current == NULL)
			cout << "EMPTY!!!" << endl;
		else
		{
			cout << current->id << "   ";
			cout << current->nazwa1 << "   ";
			cout << current->nazwa2;
			cout << endl;
		}
	}



	void showall()
	{
		if (head == NULL)
			cout << "EMPTY!!!" << endl;
		else
		{
			Node2 *pom = head;
			while (pom->next != NULL)
			{
				cout << pom->id << "   ";
				cout << pom->nazwa1 << "   ";
				cout << pom->nazwa2;
				cout << endl;
				pom = pom->next;
			}
			cout << pom->id << "   ";
			cout << pom->nazwa1 << "   ";
			cout << pom->nazwa2 << endl;
		}
	}




	void dodaj_sala()
	{
		int wyswietl = 0;
		cout << "DODAWANIE SALI." << endl;
		cout << "Czy chcesz wyswietlic liste sal: 1-tak, 0-nie: ";
		cin >> wyswietl;
		if (wyswietl == 1)
			showall();
		addlastzero();
		last_id++;
		tail->id = last_id;
		cout << "Podaj numer sali: ";
		cin >> tail->nazwa1;
		int typ = 0;
		cout << "Podaj typ sali: 1-lab, 2-wykl, 3-proj: ";
		cin >> typ;
		if (typ == 1) tail->nazwa2 = "lab";
		else if (typ == 2) tail->nazwa2 = "wykl";
		else tail->nazwa2 = "proj";
		cout << "DODANO SALE." << endl << endl;
	}


	void dodaj_wykladowca()
	{
		int wyswietl = 0;
		cout << "DODAWANIE WYKLADOWCY." << endl;
		cout << "Czy chcesz wyswietlic liste wykladowcow: 1-tak, 0-nie: ";
		cin >> wyswietl;
		if (wyswietl == 1)
			showall();
		addlastzero();
		last_id++;
		tail->id = last_id;
		cout << "Podaj imie wykladowcy: ";
		cin >> tail->nazwa1;
		cout << "Podaj nazwisko wykladowcy: ";
		cin >> tail->nazwa2;
		cout << "DODANO WYKLADOWCE." << endl << endl;
	}

	void dodaj_przedmiot()
	{
		int wyswietl = 0;
		cout << "DODAWANIE PRZEDMIOTU." << endl;
		cout << "Czy chcesz wyswietlic liste przedmiotow: 1-tak, 0-nie: ";
		cin >> wyswietl;
		if (wyswietl == 1)
			showall();
		addlastzero();
		last_id++;
		tail->id = last_id;
		cout << "Podaj nazwa przedmiotu: ";
		cin >> tail->nazwa1;
		int typ = 0;
		cout << "Podaj typ przedmiotu: 1-lab, 2-wykl, 3-proj: ";
		cin >> typ;
		if (typ == 1) tail->nazwa2 = "lab";
		else if (typ == 2) tail->nazwa2 = "wykl";
		else tail->nazwa2 = "proj";
		cout << "DODANO PRZEDMIOT." << endl << endl;
	}

	void dodaj_grupa()
	{
		int wyswietl = 0;
		cout << "DODAWANIE GRUPY." << endl;
		cout << "Czy chcesz wyswietlic liste grup: 1-tak, 0-nie: ";
		cin >> wyswietl;
		if (wyswietl == 1)
			showall();
		addlastzero();
		last_id++;
		tail->id = last_id;
		cout << "Podaj nazwe grupy: ";
		cin >> tail->nazwa1;
		int typ = 0;
		cout << "Podaj typ grupy: 1-stac, 2-nstac: ";
		cin >> typ;
		if (typ == 1) tail->nazwa2 = "stac";
		else tail->nazwa2 = "nstac";
		cout << "DODANO GRUPE." << endl << endl;
	}

	~Lista2()
	{
		deleteall();
	}

};






class Plansza
{

public:

	Lista *plan[7][7];
	Lista2 *sale;
	Lista2 *wykladowcy;
	Lista2 *grupy;
	Lista2 *przedmioty;
	int licznik_plik;

public:

	Plansza(Lista2 *s1, Lista2 *w1, Lista2 *g1, Lista2 *p1, int licz = 0)
	{
		licznik_plik = licz;
		sale = s1;
		wykladowcy = w1;
		grupy = g1;
		przedmioty = p1;
		int i, j;
		for (i = 0; i < 7; i++)
			for (j = 0; j < 7; j++)
				plan[i][j] = NULL;
	}

	void zeruj_plansze()
	{
		int i, j;
		for (i = 0; i < 7; i++)
			for (j = 0; j < 7; j++)
				plan[i][j] = NULL;
	}



	int dodaj_zajecie2()
	{
		cout << "DODAWANIE ZAJECIA." << endl << endl;

		cout << "WCZYTYWANIE BLOKU." << endl;
		int nr_dnia = 0;
		cout << "Podaj nr_dnia (od 0 - poniedzialek do 6 - niedziela): "; //lista numerow dni
		cin >> nr_dnia;
		int j = nr_dnia;
		int nr_bloku = 0;
		cout << "Podaj nr_bloku (od 0 - pierwszy do 6 - ostatni): "; //lista numerow blokow
		cin >> nr_bloku;
		int i = nr_bloku;

		int wyswietl = 0;
		int kolizja = 1;
		string typ_prze = "0";

		while (kolizja == 1)
		{
			int id_p = 0;
			cout << endl;
			cout << "WCZYTYWANIE PRZEDMIOTU." << endl;

			if ((*przedmioty).head == NULL)
			{
				cout << "BLAD!!! Brak przedmiotow na liscie." << endl << endl;
				return 1;
			}

			cout << "Czy chcesz wyswietlic liste przedmiotow: 1-tak, 0-nie: ";
			cin >> wyswietl;
			if (wyswietl == 1)
			{
				cout << "LISTA PRZEDMIOTOW:" << endl;
				(*przedmioty).showall();
			}
			cout << "Podaj id_przedmiotu: ";
			cin >> id_p;
			(*przedmioty).current = (*przedmioty).head;
			while ((*przedmioty).current->id != id_p && (*przedmioty).current != (*przedmioty).tail) {
				(*przedmioty).moveright();
			}
			if ((*przedmioty).current->id == id_p)
			{
				cout << "Brak kolizji przedmiotu." << endl;
				kolizja = 0;

				typ_prze = (*przedmioty).current->nazwa2;
			}
			else
			{
				cout << "BLAD!!! Nie ma takiego przedmiotu. SPROBUJ JESZCZE RAZ!!!" << endl;
				kolizja = 1;
			}
		}

		kolizja = 1;
		string typ_sala = "0";

		while (kolizja == 1)
		{
			int id_s = 0;
			cout << endl;
			cout << "WCZYTYWANIE SALI." << endl;

			if ((*sale).head == NULL)
			{
				cout << "BLAD!!! Brak przedmiotow na liscie." << endl << endl;
				return 1;
			}

			cout << "Czy chcesz wyswietlic liste zajetosci sal: 1-tak, 0-nie: ";
			cin >> wyswietl;

			if (wyswietl == 1)
			{
				(*plan[i][j]).current = (*plan[i][j]).head;
				if ((*plan[i][j]).current == NULL)
				{
					cout << "WSZYSTKIE WOLNE:" << endl;
					(*sale).showall();
				}
				else
				{
					cout << "LISTA ZAJETOSCI:" << endl;
					(*sale).current = (*sale).head;
					int petla = 0;
					while (((*sale).current->next != NULL || (*sale).current == (*sale).tail) && petla == 0)
					{
						while ((((*plan[i][j]).current)->id_sala)->id != (*sale).current->id && (*plan[i][j]).current != (*plan[i][j]).tail)
						{
							(*plan[i][j]).moveright();
						}
						if ((((*plan[i][j]).current)->id_sala)->id != (*sale).current->id)
						{
							cout << "WOLNE\t";
							(*sale).showcurrent();
						}
						else
						{
							cout << "ZAJETE\t";
							(*sale).showcurrent();
						}
						if ((*sale).current == (*sale).tail) petla = 1;
						else (*sale).moveright();
					}
				}
			}

			cout << "Podaj id_sali lub 0 zeby wrocic do menu: ";
			cin >> id_s;
			if (id_s == 0) return 1;
			(*sale).current = (*sale).head;
			while ((*sale).current->id != id_s && (*sale).current != (*sale).tail) {
				(*sale).moveright();
			}
			if ((*sale).current->id == id_s)
			{
				//sprawdz kolizje sali
				typ_sala = (*sale).current->nazwa2;
				kolizja = kolizje_sala(nr_dnia, nr_bloku, id_s, typ_sala, typ_prze);
				if (kolizja == 0) cout << "Brak kolizji sali." << endl;
				else cout << "BLAD!!! Kolizja sali. SPROBUJ JESZCZE RAZ!!!" << endl;
			}
			else
			{
				cout << "BLAD!!! Nie ma takiej sali. SPROBUJ JESZCZE RAZ!!!" << endl;
				kolizja = 1;
			}
		}

		kolizja = 1;

		while (kolizja == 1)
		{
			int id_w = 0;
			cout << endl;
			cout << "WCZYTYWANIE WYKLADOWCY." << endl;

			if ((*wykladowcy).head == NULL)
			{
				cout << "BLAD!!! Brak przedmiotow na liscie." << endl << endl;
				return 1;
			}

			cout << "Czy chcesz wyswietlic liste zajetosci wykladowcow: 1-tak, 0-nie: ";
			cin >> wyswietl;

			if (wyswietl == 1)
			{
				(*plan[i][j]).current = (*plan[i][j]).head;
				if ((*plan[i][j]).current == NULL)
				{
					cout << "WSZYSTKIE WOLNE:" << endl;
					(*wykladowcy).showall();
				}
				else
				{
					cout << "LISTA ZAJETOSCI:" << endl;
					(*wykladowcy).current = (*wykladowcy).head;
					int petla = 0;
					while (((*wykladowcy).current->next != NULL || (*wykladowcy).current == (*wykladowcy).tail) && petla == 0)
					{
						while ((((*plan[i][j]).current)->id_wykl)->id != (*wykladowcy).current->id && (*plan[i][j]).current != (*plan[i][j]).tail)
						{
							(*plan[i][j]).moveright();
						}
						if ((((*plan[i][j]).current)->id_wykl)->id != (*wykladowcy).current->id)
						{
							cout << "WOLNE\t";
							(*wykladowcy).showcurrent();
						}
						else
						{
							cout << "ZAJETE\t";
							(*wykladowcy).showcurrent();
						}
						if ((*wykladowcy).current == (*wykladowcy).tail) petla = 1;
						else (*wykladowcy).moveright();
					}
				}
			}

			cout << "Podaj id_wykladowcy lub 0 zeby wrocic do menu: ";
			cin >> id_w;
			if (id_w == 0) return 1;
			(*wykladowcy).current = (*wykladowcy).head;
			while ((*wykladowcy).current->id != id_w && (*wykladowcy).current != (*wykladowcy).tail) {
				(*wykladowcy).moveright();
			}
			if ((*wykladowcy).current->id == id_w)
			{
				//sprawdz kolizje wykladowcy
				kolizja = kolizje_wykladowca(nr_dnia, nr_bloku, id_w);
				if (kolizja == 0) cout << "Brak kolizji wykladowcy." << endl;
				else cout << "BLAD!!! Kolizja wykladowcy. SPROBUJ JESZCZE RAZ!!!" << endl;
			}
			else
			{
				cout << "BLAD!!! Nie ma takiego wykladowcy. SPROBUJ JESZCZE RAZ!!!" << endl;
				kolizja = 1;
			}
		}

		kolizja = 1;

		while (kolizja == 1)
		{
			int id_g = 0;
			cout << endl;
			cout << "WCZYTYWANIE GRUPY." << endl;

			if ((*grupy).head == NULL)
			{
				cout << "BLAD!!! Brak przedmiotow na liscie." << endl << endl;
				return 1;
			}

			cout << "Czy chcesz wyswietlic liste zajetosci grup: 1-tak, 0-nie: ";
			cin >> wyswietl;

			if (wyswietl == 1)
			{
				(*plan[i][j]).current = (*plan[i][j]).head;
				if ((*plan[i][j]).current == NULL)
				{
					cout << "WSZYSTKIE WOLNE:" << endl;
					(*grupy).showall();
				}
				else
				{
					cout << "LISTA ZAJETOSCI:" << endl;
					(*grupy).current = (*grupy).head;
					int petla = 0;
					while (((*grupy).current->next != NULL || (*grupy).current == (*grupy).tail) && petla == 0)
					{
						while ((((*plan[i][j]).current)->id_grup)->id != (*grupy).current->id && (*plan[i][j]).current != (*plan[i][j]).tail)
						{
							(*plan[i][j]).moveright();
						}
						if ((((*plan[i][j]).current)->id_grup)->id != (*grupy).current->id)
						{
							cout << "WOLNE\t";
							(*grupy).showcurrent();
						}
						else
						{
							cout << "ZAJETE\t";
							(*grupy).showcurrent();
						}
						if ((*grupy).current == (*grupy).tail) petla = 1;
						else (*grupy).moveright();
					}
				}
			}

			cout << "Podaj id_grupy lub 0 zeby wrocic do menu: ";
			cin >> id_g;
			if (id_g == 0) return 1;
			(*grupy).current = (*grupy).head;
			while ((*grupy).current->id != id_g && (*grupy).current != (*grupy).tail) {
				(*grupy).moveright();
			}
			if ((*grupy).current->id == id_g)
			{
				//sprawdz kolizje grupy
				kolizja = kolizje_grupa(nr_dnia, nr_bloku, id_g);
				if (kolizja == 0) cout << "Brak kolizji grupy." << endl;
				else cout << "BLAD!!! Kolizja grupy. SPROBUJ JESZCZE RAZ!!!" << endl;
			}
			else
			{
				cout << "BLAD!!! Nie ma takiej grupy. SPROBUJ JESZCZE RAZ!!!" << endl;
				kolizja = 1;
			}
		}




		//jesli nie ma kolizji to:
		(*plan[nr_bloku][nr_dnia]).addlastzero();
		(*plan[nr_bloku][nr_dnia]).tail->id_sala = (*sale).current;
		(*plan[nr_bloku][nr_dnia]).tail->id_wykl = (*wykladowcy).current;
		(*plan[nr_bloku][nr_dnia]).tail->id_grup = (*grupy).current;
		(*plan[nr_bloku][nr_dnia]).tail->id_prze = (*przedmioty).current;

		return 0;
	}







	int kolizje_sala(int dzien, int godz, int kol_sala, string typ_s, string typ_p)
	{
		int i, j, id_s;
		i = godz;
		j = dzien;
		id_s = kol_sala;

		if (typ_s != typ_p)
		{
			if (typ_s == "wykl") return 1;
			else if (typ_p == "wykl") return 1;
		}

		if ((*plan[i][j]).head == NULL) return 0;
		else
		{
			(*plan[i][j]).current = (*plan[i][j]).head;
			while ((((*plan[i][j]).current)->id_sala)->id != id_s && (*plan[i][j]).current != (*plan[i][j]).tail)
			{
				(*plan[i][j]).moveright();
			}
			if ((((*plan[i][j]).current)->id_sala)->id == id_s) return 1;
			else return 0;
		}
	}


	int kolizje_wykladowca(int dzien, int godz, int kol_wykl)
	{
		int i, j, id_w;
		i = godz;
		j = dzien;
		id_w = kol_wykl;
		if ((*plan[i][j]).head == NULL) return 0;
		else
		{
			(*plan[i][j]).current = (*plan[i][j]).head;
			while ((((*plan[i][j]).current)->id_wykl)->id != id_w && (*plan[i][j]).current != (*plan[i][j]).tail)
			{
				(*plan[i][j]).moveright();
			}
			if ((((*plan[i][j]).current)->id_wykl)->id == id_w) return 1;
			else return 0;
		}
	}


	int kolizje_grupa(int dzien, int godz, int kol_grup)
	{
		int i, j, id_g;
		i = godz;
		j = dzien;
		id_g = kol_grup;
		if ((*plan[i][j]).head == NULL) return 0;
		else
		{
			(*plan[i][j]).current = (*plan[i][j]).head;
			while ((((*plan[i][j]).current)->id_grup)->id != id_g && (*plan[i][j]).current != (*plan[i][j]).tail)
			{
				(*plan[i][j]).moveright();
			}
			if ((((*plan[i][j]).current)->id_grup)->id == id_g) return 1;
			else return 0;
		}
	}





	int pokaz_plansze_grupa()
	{
		int wyswietl = 0;
		int id_g = 0;
		cout << "WCZYTYWANIE GRUPY." << endl;

		if ((*grupy).head == NULL)
		{
			cout << "BLAD!!! Brak grup na liscie." << endl << endl;
			return 1;
		}

		cout << "Czy chcesz wyswietlic liste grup: 1-tak, 0-nie: ";
		cin >> wyswietl;
		if (wyswietl == 1)
		{
			cout << "LISTA GRUP:" << endl;
			(*grupy).showall();
		}
		cout << "Podaj id_grupy: ";
		cin >> id_g;
		(*grupy).current = (*grupy).head;
		while ((*grupy).current->id != id_g && (*grupy).current != (*grupy).tail) {
			(*grupy).moveright();
		}
		if ((*grupy).current->id == id_g);
		else {
			cout << "BLAD!!! Nie ma takiej grupy.";
			//wywolac funkcje powrotu do menu
			return 1;
		}

		licznik_plik++;
		fstream plik;
		ostringstream numer;
		numer << licznik_plik;
		string str = numer.str();
		string nazwa_pliku = "PLAN" + str + ".txt";
		plik.open(nazwa_pliku.c_str(), ios::out);

		if (plik.good() == true);
		else cout << "BLAD PLIKU!!!" << endl;

		string tab_dni[7] = { "Poniedzialek","Wtorek","Sroda","Czwartek","Piatek","Sobota","Niedziela" };
		string tab_godz[7] = { "8:00-9:35","9:50-11:25","11:40-13:15","13:30-15:05","15:45-17:20","17:35-19:10","19:25-21:00" };

		cout << endl << "PLAN GRUPY " << (*grupy).current->nazwa1 << "   " << (*grupy).current->nazwa2 << endl;
		plik << endl << "PLAN GRUPY " << (*grupy).current->nazwa1 << "   " << (*grupy).current->nazwa2 << endl;

		int i, j;
		for (j = 0; j < 7; j++)
		{
			cout << endl;
			cout << tab_dni[j] << endl << endl;
			plik << endl << tab_dni[j] << endl << endl;

			for (i = 0; i < 7; i++)
			{

				cout << tab_godz[i] << endl;
				plik << tab_godz[i] << endl;

				if ((*plan[i][j]).head == NULL)
				{
					cout << "Brak zajec w tym bloku." << endl;
					plik << "Brak zajec w tym bloku." << endl;
				}
				else
				{
					(*plan[i][j]).current = (*plan[i][j]).head;
					while ((((*plan[i][j]).current)->id_grup)->id != id_g && (*plan[i][j]).current != (*plan[i][j]).tail) {
						(*plan[i][j]).moveright();
					}
					if ((((*plan[i][j]).current)->id_grup)->id == id_g)
					{
						(*plan[i][j]).showcurrent();
						(*plan[i][j]).savecurrent(&plik);
					}
					else
					{
						cout << "Brak zajec w tym bloku." << endl;
						plik << "Brak zajec w tym bloku." << endl;
					}

					//(*plan[i][j]).showall();
				}
			}
		}

		plik.close();
		return 0;
	}








	int pokaz_plansze_wykladowca()
	{
		int wyswietl = 0;
		int id_w = 0;
		cout << "WCZYTYWANIE WYKLADOWCY." << endl;

		if ((*wykladowcy).head == NULL)
		{
			cout << "BLAD!!! Brak wykladowcow na liscie." << endl << endl;
			return 1;
		}

		cout << "Czy chcesz wyswietlic liste wykladowcow: 1-tak, 0-nie: ";
		cin >> wyswietl;
		if (wyswietl == 1)
		{
			cout << "LISTA WYKLADOWCOW:" << endl;
			(*wykladowcy).showall();
		}
		cout << "Podaj id_wykladowcy: ";
		cin >> id_w;
		(*wykladowcy).current = (*wykladowcy).head;
		while ((*wykladowcy).current->id != id_w && (*wykladowcy).current != (*wykladowcy).tail) {
			(*wykladowcy).moveright();
		}
		if ((*wykladowcy).current->id == id_w);
		else {
			cout << "BLAD!!! Nie ma takiego wykladowcy.";
			//wywolac funkcje powrotu do menu
			return 1;
		}

		licznik_plik++;
		fstream plik;
		ostringstream numer;
		numer << licznik_plik;
		string str = numer.str();
		string nazwa_pliku = "PLAN" + str + ".txt";
		plik.open(nazwa_pliku.c_str(), ios::out);

		if (plik.good() == true);
		else cout << "BLAD PLIKU!!!" << endl;

		string tab_dni[7] = { "Poniedzialek","Wtorek","Sroda","Czwartek","Piatek","Sobota","Niedziela" };
		string tab_godz[7] = { "8:00-9:35","9:50-11:25","11:40-13:15","13:30-15:05","15:45-17:20","17:35-19:10","19:25-21:00" };

		cout << endl << "PLAN WYKLADOWCY " << (*wykladowcy).current->nazwa1 << "   " << (*wykladowcy).current->nazwa2 << endl;
		plik << endl << "PLAN WYKLADOWCY " << (*wykladowcy).current->nazwa1 << "   " << (*wykladowcy).current->nazwa2 << endl;

		int i, j;
		for (j = 0; j < 7; j++)
		{

			cout << endl;
			cout << tab_dni[j] << endl << endl;
			plik << endl << tab_dni[j] << endl << endl;

			for (i = 0; i < 7; i++)
			{

				cout << tab_godz[i] << endl;
				plik << tab_godz[i] << endl;

				if ((*plan[i][j]).head == NULL)
				{
					cout << "Brak zajec w tym bloku." << endl;
					plik << "Brak zajec w tym bloku." << endl;
				}
				else
				{
					(*plan[i][j]).current = (*plan[i][j]).head;
					while ((((*plan[i][j]).current)->id_wykl)->id != id_w && (*plan[i][j]).current != (*plan[i][j]).tail) {
						(*plan[i][j]).moveright();
					}
					if ((((*plan[i][j]).current)->id_wykl)->id == id_w)
					{
						(*plan[i][j]).showcurrent();
						(*plan[i][j]).savecurrent(&plik);
					}
					else
					{
						cout << "Brak zajec w tym bloku." << endl;
						plik << "Brak zajec w tym bloku." << endl;
					}

					//(*plan[i][j]).showall();
				}
			}
		}

		plik.close();
		return 0;
	}






	int pokaz_plansze_sala()
	{
		int wyswietl = 0;
		int id_s = 0;
		cout << "WCZYTYWANIE SALI." << endl;

		if ((*sale).head == NULL)
		{
			cout << "BLAD!!! Brak sal na liscie." << endl << endl;
			return 1;
		}

		cout << "Czy chcesz wyswietlic liste sal: 1-tak, 0-nie: ";
		cin >> wyswietl;
		if (wyswietl == 1)
		{
			cout << "LISTA SAL:" << endl;
			(*sale).showall();
		}
		cout << "Podaj id_sali: ";
		cin >> id_s;
		(*sale).current = (*sale).head;
		while ((*sale).current->id != id_s && (*sale).current != (*sale).tail) {
			(*sale).moveright();
		}
		if ((*sale).current->id == id_s);
		else {
			cout << "BLAD!!! Nie ma takiej sali.";
			//wywolac funkcje powrotu do menu
			return 1;
		}

		licznik_plik++;
		fstream plik;
		ostringstream numer;
		numer << licznik_plik;
		string str = numer.str();
		string nazwa_pliku = "PLAN" + str + ".txt";
		plik.open(nazwa_pliku.c_str(), ios::out);

		if (plik.good() == true);
		else cout << "BLAD PLIKU!!!" << endl;

		string tab_dni[7] = { "Poniedzialek","Wtorek","Sroda","Czwartek","Piatek","Sobota","Niedziela" };
		string tab_godz[7] = { "8:00-9:35","9:50-11:25","11:40-13:15","13:30-15:05","15:45-17:20","17:35-19:10","19:25-21:00" };

		cout << endl << "PLAN SALI " << (*sale).current->nazwa1 << "   " << (*sale).current->nazwa2 << endl;
		plik << endl << "PLAN SALI " << (*sale).current->nazwa1 << "   " << (*sale).current->nazwa2 << endl;

		int i, j;
		for (j = 0; j < 7; j++)
		{

			cout << endl;
			cout << tab_dni[j] << endl << endl;
			plik << endl << tab_dni[j] << endl << endl;

			for (i = 0; i < 7; i++)
			{

				cout << tab_godz[i] << endl;
				plik << tab_godz[i] << endl;

				if ((*plan[i][j]).head == NULL)
				{
					cout << "Brak zajec w tym bloku." << endl;
					plik << "Brak zajec w tym bloku." << endl;
				}
				else
				{
					(*plan[i][j]).current = (*plan[i][j]).head;
					while ((((*plan[i][j]).current)->id_sala)->id != id_s && (*plan[i][j]).current != (*plan[i][j]).tail) {
						(*plan[i][j]).moveright();
					}
					if ((((*plan[i][j]).current)->id_sala)->id == id_s)
					{
						(*plan[i][j]).showcurrent();
						(*plan[i][j]).savecurrent(&plik);
					}
					else
					{
						cout << "Brak zajec w tym bloku." << endl;
						plik << "Brak zajec w tym bloku." << endl;
					}

					//(*plan[i][j]).showall();
				}
			}
		}

		plik.close();
		return 0;
	}






	int usun_zajecie()
	{
		cout << "USUWANIE ZAJECIA." << endl << endl;

		cout << "WCZYTYWANIE BLOKU." << endl;
		int nr_dnia = 0;
		cout << "Podaj nr_dnia (od 0 - poniedzialek do 6 - niedziela): "; //lista numerow dni
		cin >> nr_dnia;
		int nr_bloku = 0;
		cout << "Podaj nr_bloku (od 0 - pierwszy do 6 - ostatni): "; //lista numerow blokow
		cin >> nr_bloku;

		int check = 1;
		if ((*plan[nr_bloku][nr_dnia]).head == NULL)
		{
			cout << "Brak zajec w tym bloku." << endl << endl;
			return check;
		}

		int usun = 0;
		cout << endl << "WEDLUG CZEGO USUNAC? 1-sala, 2-wykladowca, 3-grupa: ";
		cin >> usun;
		cout << endl;
		if (usun == 1) check = usun_zajecie_sala(nr_dnia, nr_bloku);
		else if (usun == 2) check = usun_zajecie_wykl(nr_dnia, nr_bloku);
		else check = usun_zajecie_grup(nr_dnia, nr_bloku);

		return check;
	}


	int usun_zajecie_sala(int dn, int godz)
	{
		int wyswietl = 0;
		int id_s = 0;
		cout << "WCZYTYWANIE SALI." << endl;
		cout << "Czy chcesz wyswietlic liste zajec w bloku: 1-tak, 0-nie: ";
		cin >> wyswietl;
		if (wyswietl == 1)
			(*plan[godz][dn]).showall2();
		cout << "Podaj id_sali: ";
		cin >> id_s;

		int i, j;
		i = godz;
		j = dn;

		(*plan[i][j]).current = (*plan[i][j]).head;
		while ((((*plan[i][j]).current)->id_sala)->id != id_s && (*plan[i][j]).current != (*plan[i][j]).tail)
		{
			(*plan[i][j]).moveright();
		}
		if ((((*plan[i][j]).current)->id_sala)->id == id_s)
		{
			(*plan[i][j]).deletecurrent();
			return 0;
		}
		else
		{
			//nie udalo sie usunac
			return 1;
		}
	}


	int usun_zajecie_wykl(int dn, int godz)
	{
		int wyswietl = 0;
		int id_w = 0;
		cout << "WCZYTYWANIE WYKLADOWCY." << endl;
		cout << "Czy chcesz wyswietlic liste zajec w bloku: 1-tak, 0-nie: ";
		cin >> wyswietl;
		if (wyswietl == 1)
			(*plan[godz][dn]).showall2();
		cout << "Podaj id_wykladowcy: ";
		cin >> id_w;

		int i, j;
		i = godz;
		j = dn;

		(*plan[i][j]).current = (*plan[i][j]).head;
		while ((((*plan[i][j]).current)->id_wykl)->id != id_w && (*plan[i][j]).current != (*plan[i][j]).tail)
		{
			(*plan[i][j]).moveright();
		}
		if ((((*plan[i][j]).current)->id_wykl)->id == id_w)
		{
			(*plan[i][j]).deletecurrent();
			return 0;
		}
		else
		{
			//nie udalo sie usunac
			return 1;
		}
	}


	int usun_zajecie_grup(int dn, int godz)
	{
		int wyswietl = 0;
		int id_g = 0;
		cout << "WCZYTYWANIE GRUPY." << endl;
		cout << "Czy chcesz wyswietlic liste zajec w bloku: 1-tak, 0-nie: ";
		cin >> wyswietl;
		if (wyswietl == 1)
			(*plan[godz][dn]).showall2();
		cout << "Podaj id_grupy: ";
		cin >> id_g;

		int i, j;
		i = godz;
		j = dn;

		(*plan[i][j]).current = (*plan[i][j]).head;
		while ((((*plan[i][j]).current)->id_grup)->id != id_g && (*plan[i][j]).current != (*plan[i][j]).tail)
		{
			(*plan[i][j]).moveright();
		}
		if ((((*plan[i][j]).current)->id_grup)->id == id_g)
		{
			(*plan[i][j]).deletecurrent();
			return 0;
		}
		else
		{
			//nie udalo sie usunac
			return 1;
		}
	}

	~Plansza()
	{
		sale = NULL;
		wykladowcy = NULL;
		grupy = NULL;
		przedmioty = NULL;
		int i, j;
		for (i = 0; i < 7; i++)
			for (j = 0; j < 7; j++)
				plan[i][j] = NULL;
	}

};



class Menu
{
public:

	Plansza *plan;
	Lista2 *sale;
	Lista2 *wykladowcy;
	Lista2 *grupy;
	Lista2 *przedmioty;
	int tryb;
	int akcja;
	int koniec;


	Menu(Plansza *pl, Lista2 *s1, Lista2 *w1, Lista2 *g1, Lista2 *p1, int t = 0, int a = 0, int k = 100)
	{
		plan = pl;
		sale = s1;
		wykladowcy = w1;
		grupy = g1;
		przedmioty = p1;
		tryb = t;
		akcja = a;
		koniec = k;
	}


	void menu_poczatkowe()
	{
		system("cls");
		cout << "GENERATOR PLANU ZAJEC" << endl << endl;

		cout << "1 - dodaj sale" << endl;
		cout << "2 - dodaj wykladowce" << endl;
		cout << "3 - dodaj grupe" << endl;
		cout << "4 - dodaj przedmiot" << endl << endl;

		cout << "5 - dodaj zajecie" << endl;
		cout << "6 - usun zajecie" << endl << endl;

		cout << "7 - wyswietl i zapisz plan zajec" << endl << endl;

		cout << "0 - koniec" << endl << endl;

		cout << "Co chcesz zrobic? ";
		cin >> koniec;
		if (koniec == 0);
		else koordynator();
	}

	void koordynator()
	{
		system("cls");

		if (koniec == 1)
		{
			(*sale).dodaj_sala();
			cout << endl << endl << "Wcisnij 1 aby wrocic do menu: ";
			cin >> akcja;
			menu_poczatkowe();
		}
		else if (koniec == 2)
		{
			(*wykladowcy).dodaj_wykladowca();
			cout << endl << endl << "Wcisnij 1 aby wrocic do menu: ";
			cin >> akcja;
			menu_poczatkowe();
		}
		else if (koniec == 3)
		{
			(*grupy).dodaj_grupa();
			cout << endl << endl << "Wcisnij 1 aby wrocic do menu: ";
			cin >> akcja;
			menu_poczatkowe();
		}
		else if (koniec == 4)
		{
			(*przedmioty).dodaj_przedmiot();
			cout << endl << endl << "Wcisnij 1 aby wrocic do menu: ";
			cin >> akcja;
			menu_poczatkowe();
		}

		else if (koniec == 5)
		{
			tryb = (*plan).dodaj_zajecie2();
			if (tryb == 0) cout << endl << endl << "POPRAWNIE DODANO ZAJECIE!!!" << endl << endl;
			else cout << endl << endl << "NIE DODANO ZAJECIA (blad lub twoj wybor)!!!" << endl << endl;
			cout << endl << endl << "Wcisnij 1 aby wrocic do menu: ";
			cin >> akcja;
			menu_poczatkowe();
		}
		else if (koniec == 6)
		{
			tryb = (*plan).usun_zajecie();
			if (tryb == 0) cout << endl << endl << "POPRAWNIE USUNIETO ZAJECIE!!!" << endl << endl;
			else cout << endl << endl << "NIE USUNIETO ZAJECIA (blad lub twoj wybor)!!!" << endl << endl;
			cout << endl << endl << "Wcisnij 1 aby wrocic do menu: ";
			cin >> akcja;
			menu_poczatkowe();
		}

		else if (koniec == 7)
		{
			cout << "WEDLUG CZEGO POKAZAC PLAN? 1-sala, 2-wykladowca, 3-grupa: ";
			cin >> tryb;
			if (tryb == 1) tryb = (*plan).pokaz_plansze_sala();
			else if (tryb == 2) tryb = (*plan).pokaz_plansze_wykladowca();
			else tryb = (*plan).pokaz_plansze_grupa();

			if (tryb == 0) cout << endl << endl << "POPRAWNIE WYGENEROWANO PLAN!!!" << endl << endl;
			else cout << endl << endl << "NIE UDALO SIE WYGENEROWAC PLANU!!!" << endl << endl;
			cout << endl << endl << "Wcisnij 1 aby wrocic do menu: ";
			cin >> akcja;
			menu_poczatkowe();
		}
	}


	~Menu()
	{
		plan = NULL;
		sale = NULL;
		wykladowcy = NULL;
		grupy = NULL;
		przedmioty = NULL;
	}

};



int main()
{
	Lista2 s1, w1, g1, p1;

	Lista bloki[7][7];

	Plansza plan1(&s1, &w1, &g1, &p1);

	int i, j;
	for (i = 0; i < 7; i++)
		for (j = 0; j < 7; j++)
			plan1.plan[i][j] = &(bloki[i][j]);

	Menu m(&plan1, &s1, &w1, &g1, &p1);

	m.menu_poczatkowe();

	cout << endl << "KONIEC!!!" << endl << endl;


	system("pause");
	return 0;
}

