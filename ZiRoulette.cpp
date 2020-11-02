#include <iostream>
#include <ctime>
using namespace std;

int main() {
	/*Måste inkludera åäö*/
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
	cout << "Välkommen till Zi'Roulette!" << endl;
	cout << "Man måste var över 18 år för att spela, hur gammal är du?" << endl;
	/*Måste ju enligt lag kontrollera spelarens ålder för casinospel :P*/
	int age;
	cin >> age;
	if (age <= 17) {
		cout << "Du är för ung för att spela detta spelet!" << endl;
		return 0;
	}
	cout << "Let's Rock this place!" << endl;
	/*Lite lätt info om hur spelet funkar*/
	cout << "Lite information om hur spelet funkar" << endl;
	cout << "Roulette är ett spel där man väljer en siffra mellan 1-36 eller så väljer man mellan färgerna röd/svart" << endl;
	cout << "Man kan oxå välja nummer 0 som är grön" << endl;
	cout << "För att vinna måste den slumpade siffran eller färgen stämma överens med talet eller färgen du valde" << endl;
	cout << "Om de stämmmer överens vinner man om inte förlorar man" << endl;
	cout << "Du kommer att få 1000kr att börja med." << endl;
	int tal1 = 100; int tal2 = 300; int tal3 = 500;
	while (rp == 1) {
		/*Valet av insats*/
		cout << "Välj din insats ";
		cin >> insats;
		i = 0;
		while (i != 1) {
			if ((insats != tal1) && (insats != tal2) && (insats != tal3)) {
				cout << "Du kan bara välja 100, 300 eller 500 som insats" << endl;
				cout << "Välj din insats ";
				cin >> insats;
			}
			else if (saldo < insats) {
				cout << "Du kan inte satsa: " << insats << " eftersom du har för lite saldo." << endl;
				cout << "Ditt saldo är: " << saldo << ". Var god och välj en ny insats." << endl;
				cin >> insats;
			}
			else {
				i = 1;
			}
		}
		/*Chans att ändra sitt val*/
		int jn;
		int vf;
		cout << "Du har valt att satsa " << insats << " Vill du ändra? Ja[1] / Nej[2]" << endl;
		cin >> jn;
		if (jn != 2) {
			cout << "Hur mycket vill du satsa istället?" << endl;
			cin >> insats;
			while (insats != tal1 && insats != tal2 && insats != tal3) {
				cout << "Du kan bara välja 100, 300 eller 500 som insats" << endl;
				cout << "Hur mycket vill du satsa istället?" << endl;
				cin >> insats;
			}
		}
		else {

		}
		cout << "Game ON!" << endl;
		/*Färg eller Nummer valet*/
		int fn;
		cout << "Nu väljer du färg[1], nummer[2] eller grön/noll[3]" << endl;
		cin >> fn;
		if (fn == 1) {
			/*Valt Färg*/
			int f;
			cout << "Du har valt att spela på färg" << endl;
			cout << "Väljer du Svart[1] eller Röd[2]" << endl;
			cin >> f;
			if (f != 2) {
				cout << "Du har valt Svart färg" << endl;
				/*Kulan kastas*/
				srand(time(0));
				slumpen = rand() % 2 + 1;
				if (f != slumpen) {
					cout << "Kulan hamnade på " << slumpen << "!!!" << endl;
					cout << "Du förlorade!" << endl;
					vf = 0;
				}
				else {
					cout << "Kulan hamnade på " << slumpen << "!!!" << endl;
					cout << "Du vann!" << endl;
					vf = 2;
				}
			}
			else {
				cout << "Du har valt Röd färg" << endl;
				/*Kulan kastas*/
				srand(time(0));
				slumpen = rand() % 2 + 1;
				if (f != slumpen) {
					cout << "Kulan hamnade på " << slumpen << "!!!" << endl;
					cout << "Du förlorade!" << endl;
					vf = 0;
				}
				else {
					cout << "Kulan hamnade på " << slumpen << "!!!" << endl;
					cout << "Du vann!" << endl;
					vf = 2;
				}
			}
		}
		else if (fn == 2) {
			/*Valt Nummer*/
			int nummer;
			cout << "Du har valt att spela på nummer" << endl;
			cout << "Välj ett tal mellan 1-36" << endl;
			cin >> nummer;
			/*Kulan kastas*/
			srand(time(0));
			slumpen = rand() % 37;
			if (nummer != slumpen) {
				cout << "Kulan hamnade på " << slumpen << "!!!" << endl;
				cout << "Du förlorade!" << endl;
				vf = 0;
			}
			else {
				cout << "Kulan hamnade på " << slumpen << "!!!" << endl;
				cout << "Du vann!" << endl;
				vf = 1;
			}
		}
		else {
			/*Valt Grön/Noll*/
			int zero;
			cout << "Du har valt att spela på Grön/Noll" << endl;
			zero = 0;
			/*Kulan kastas*/
			srand(time(0));
			slumpen = rand() % 37;
			if (zero != slumpen) {
				cout << "Kulan hamnade på " << slumpen << "!!!" << endl;
				cout << "Du förlorade!" << endl;
				vf = 0;
			}
			else {
				cout << "Kulan hamnade på " << slumpen << "!!!" << endl;
				cout << "Du vann!" << endl;
				vf = 1337;
			}
		}
		int pms;
		int vinst;
		int loss;
		/*Vinst/Förlust beräkning + redovisning*/
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
			cout << "Du satsade: " << loss << " och förlorade." << endl;
			totloss = totloss + loss;
			cout << "Du har totalt förlorat: " << totloss << endl;
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
				cout << "Ditt saldo är: " << saldo << endl;
				cout << "Hur mycket vill du satsa nu?" << endl;
				rp = 1;
			}
			else if (saldo <= 100) {
				cout << "Ditt saldo är för lågt för kunna fortsätta spela!" << endl;
				cout << "Tack för att du spelade Zi'Roulette!" << endl;
				cout << "Välkommen åter!" << endl;
				rp = 0;
			}
			else {

			}
		}
		else if (si == 2) {
			cout << "Tack för att du spelade Zi'Roulette!" << endl;
			cout << "Välkommen åter!" << endl;
			rp = 0;
		}
		else {

		}
	}
	return 0;
}
