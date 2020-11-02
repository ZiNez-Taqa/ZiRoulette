#include <iostream>
#include <ctime>
using namespace std;

int main() {
	/*M�ste inkludera ���*/
	setlocale(LC_ALL, "swedish");
	int saldo = 1000;
	int insats;
	int slumpen;
	int i;
	int rp;
	rp = 1;
	int totvinst;
	totvinst = 0;
	int totloss;
	totloss = 0;
	cout << "V�lkommen till Zi'Roulette!" << endl;
	cout << "Man m�ste var �ver 18 �r f�r att spela, hur gammal �r du?" << endl;
	/*M�ste ju enligt lag kontrollera spelarens �lder f�r casinospel :P*/
	int age;
	cin >> age;
	if (age <= 17) {
		cout << "Du �r f�r ung f�r att spela detta spelet!" << endl;
		return 0;
	}
	cout << "Let's Rock this place!" << endl;
	/*Lite l�tt info om hur spelet funkar*/
	cout << "Lite information om hur spelet funkar" << endl;
	cout << "Roulette �r ett spel d�r man v�ljer en siffra mellan 1-36 eller s� v�ljer man mellan f�rgerna r�d/svart" << endl;
	cout << "Man kan ox� v�lja nummer 0 som �r gr�n" << endl;
	cout << "F�r att vinna m�ste den slumpade siffran eller f�rgen st�mma �verens med talet eller f�rgen du valde" << endl;
	cout << "Om de st�mmmer �verens vinner man om inte f�rlorar man" << endl;
	cout << "Du kommer att f� 1000kr att b�rja med." << endl;
	int tal1 = 100; int tal2 = 300; int tal3 = 500;
	while (rp == 1) {
		/*Valet av insats*/
		cout << "V�lj din insats ";
		cin >> insats;
		i = 0;
		while (i != 1) {
			if ((insats != tal1) && (insats != tal2) && (insats != tal3)) {
				cout << "Du kan bara v�lja 100, 300 eller 500 som insats" << endl;
				cout << "V�lj din insats ";
				cin >> insats;
			}
			else if (saldo < insats) {
				cout << "Du kan inte satsa: " << insats << " eftersom du har f�r lite saldo." << endl;
				cout << "Ditt saldo �r: " << saldo << ". Var god och v�lj en ny insats." << endl;
				cin >> insats;
			}
			else {
				i = 1;
			}
		}
		/*Chans att �ndra sitt val*/
		int jn;
		int vf;
		cout << "Du har valt att satsa " << insats << " Vill du �ndra? Ja[1] / Nej[2]" << endl;
		cin >> jn;
		if (jn != 2) {
			cout << "Hur mycket vill du satsa ist�llet?" << endl;
			cin >> insats;
			while (insats != tal1 && insats != tal2 && insats != tal3) {
				cout << "Du kan bara v�lja 100, 300 eller 500 som insats" << endl;
				cout << "Hur mycket vill du satsa ist�llet?" << endl;
				cin >> insats;
			}
		}
		else {

		}
		cout << "Game ON!" << endl;
		/*F�rg eller Nummer valet*/
		int fn;
		cout << "Nu v�ljer du f�rg[1], nummer[2] eller gr�n/noll[3]" << endl;
		cin >> fn;
		if (fn == 1) {
			/*Valt F�rg*/
			int f;
			cout << "Du har valt att spela p� f�rg" << endl;
			cout << "V�ljer du Svart[1] eller R�d[2]" << endl;
			cin >> f;
			if (f != 2) {
				cout << "Du har valt Svart f�rg" << endl;
				/*Kulan kastas*/
				srand(time(0));
				slumpen = rand() % 2 + 1;
				if (f != slumpen) {
					cout << "Kulan hamnade p� " << slumpen << "!!!" << endl;
					cout << "Du f�rlorade!" << endl;
					vf = 0;
				}
				else {
					cout << "Kulan hamnade p� " << slumpen << "!!!" << endl;
					cout << "Du vann!" << endl;
					vf = 2;
				}
			}
			else {
				cout << "Du har valt R�d f�rg" << endl;
				/*Kulan kastas*/
				srand(time(0));
				slumpen = rand() % 2 + 1;
				if (f != slumpen) {
					cout << "Kulan hamnade p� " << slumpen << "!!!" << endl;
					cout << "Du f�rlorade!" << endl;
					vf = 0;
				}
				else {
					cout << "Kulan hamnade p� " << slumpen << "!!!" << endl;
					cout << "Du vann!" << endl;
					vf = 2;
				}
			}
		}
		else if (fn == 2) {
			/*Valt Nummer*/
			int nummer;
			cout << "Du har valt att spela p� nummer" << endl;
			cout << "V�lj ett tal mellan 1-36" << endl;
			cin >> nummer;
			/*Kulan kastas*/
			srand(time(0));
			slumpen = rand() % 37;
			if (nummer != slumpen) {
				cout << "Kulan hamnade p� " << slumpen << "!!!" << endl;
				cout << "Du f�rlorade!" << endl;
				vf = 0;
			}
			else {
				cout << "Kulan hamnade p� " << slumpen << "!!!" << endl;
				cout << "Du vann!" << endl;
				vf = 1;
			}
		}
		else {
			/*Valt Gr�n/Noll*/
			int zero;
			cout << "Du har valt att spela p� Gr�n/Noll" << endl;
			zero = 0;
			/*Kulan kastas*/
			srand(time(0));
			slumpen = rand() % 37;
			if (zero != slumpen) {
				cout << "Kulan hamnade p� " << slumpen << "!!!" << endl;
				cout << "Du f�rlorade!" << endl;
				vf = 0;
			}
			else {
				cout << "Kulan hamnade p� " << slumpen << "!!!" << endl;
				cout << "Du vann!" << endl;
				vf = 1337;
			}
		}
		int pms;
		int vinst;
		int loss;
		/*Vinst/F�rlust ber�kning + redovisning*/
		if (vf == 1) {
			cout << "Du satsade: " << insats << " och vann!" << endl;
			vinst = insats * 10;
			cout << "Din vinst blev: " << vinst << endl;
			totvinst = totvinst + vinst;
			cout << "Du har totalt vunnit: " << totvinst << endl;
			pms = 1;
		}
		else if (vf == 2) {
			cout << "Du satsade: " << insats << " och vann!" << endl;
			vinst = insats * 2;
			cout << "Din vinst blev: " << vinst << endl;
			totvinst = totvinst + vinst;
			cout << "Du har totalt vunnit: " << totvinst << endl;
			pms = 1;
		}
		else if (vf == 1337) {
			cout << "Du satsade: " << insats << " och vann!" << endl;
			vinst = insats * 25;
			cout << "Din vinst blev: " << vinst << endl;
			totvinst = totvinst + vinst;
			cout << "Du har totalt vunnit: " << totvinst << endl;
			pms = 1;
		}
		else {
			loss = insats;
			cout << "Du satsade: " << loss << " och f�rlorade." << endl;
			totloss = totloss + loss;
			cout << "Du har totalt f�rlorat: " << totloss << endl;
			pms = 0;
		}
		int vfsaldo;
		/*Saldo +/-*/
		if (pms == 1) {
			vfsaldo = saldo + vinst;
			cout << "Saldo: " << saldo << " + " << vinst << " = " << vfsaldo << endl;
			saldo = vfsaldo;
		}
		else {
			vfsaldo = saldo - loss;
			cout << "Saldo: " << saldo << " - " << loss << " = " << vfsaldo << endl;
			saldo = vfsaldo;
		}
		int si;
		cout << "Vill du spela igen? Ja[1] / Nej[2]" << endl;
		cin >> si;
		if (si == 1) {
			if (saldo >= 100) {
				cout << "Ditt saldo �r: " << saldo << endl;
				cout << "Hur mycket vill du satsa nu?" << endl;
				rp = 1;
			}
			else if (saldo <= 100) {
				cout << "Ditt saldo �r f�r l�gt f�r kunna forts�tta spela!" << endl;
				cout << "Tack f�r att du spelade Zi'Roulette!" << endl;
				cout << "V�lkommen �ter!" << endl;
				rp = 0;
			}
			else {

			}
		}
		else if (si == 2) {
			cout << "Tack f�r att du spelade Zi'Roulette!" << endl;
			cout << "V�lkommen �ter!" << endl;
			rp = 0;
		}
		else {

		}
	}
	return 0;
}
