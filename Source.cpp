#include <iostream>
#include <string>
#include <random>
#include <ctime>
#define _WIN32_WINNT 0x0500
#include <windows.h>

using namespace std;

int main() {

	//Console Window Size
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); 

	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, 800, 300, TRUE);
	
	cout << endl;
	Sleep(1000);
	

	//Warrior
	float warriorHealth = 200;
	//AbilitiesWarrior
	//Cleaving Strike
	string warriorSkill1Name = "Cleaving Strike";
	int warriorSkill1Damage = 40;
	float warriorSkill1HitChance = 3.0f;
	string warriorSkill1DisplayHitChance = "30%";
	//Slash
	string warriorSkill2Name = "Slash";
	int warriorSkill2Damage = 50;
	float warriorSkill2HitChance = 2.0f;
	string warriorSkill2DisplayHitChance = "20%";
	//Spin to Win
	string warriorSkill3Name = "Spin to win!";
	int warriorSkill3Damage = 300;
	float warriorSkill3HitChance = 1.0f;
	string warriorSkill3DisplayHitChance = "10%";
	//Rest (Heal)
	string warriorSkill4Name = "Rest";
	int warriorSkill4Heal = -50;
	float warriorSkill4HitChance = 5.0;
	string warriorSkill4DisplayHitChance = "50%";

	//Mage
	float mageHealth = 120;
	//AbilitiesMage
	//Firebolt
	string mageSkill1Name = "Firebolt";
	int mageSkill1Damage = 20;
	float mageSkill1HitChance = 10.0f;
	string mageSkill1DisplayHitChance = "100%";
	//Magic Missile
	string mageSkill2Name = "Magic Missile";
	int mageSkill2Damage = 30;
	float mageSkill2HitChance = 8.0f;
	string mageSkill2DisplayHitChance = "80%";
	//Thunder
	string mageSkill3Name = "Thunder";
	int mageSkill3Damage = 50;
	float mageSkill3HitChance = 6.0f;
	string mageSkill3DisplayHitChance = "60%";
	//Pyroblast
	string mageSkill4Name = "Pyroblast";
	int mageSkill4Damage = 100;
	float mageSkill4HitChance = 2.0f;
	string mageSkill4DisplayHitChance = "20%";

	//Archer
	float archerHealth = 150;
	//AbilitiesArcher
	//Sure Shot
	string archerSkill1Name = "Sure Shot";
	int archerSkill1Damage = 20;
	float archerSkill1HitChance = 10.0f;
	string archerSkill1DisplayHitChance = "100%";
	//Falcon Shot
	string archerSkill2Name = "Falcon Shot";
	int archerSkill2Damage = 50;
	float archerSkill2HitChance = 4.0f;
	string archerSkill2DisplayHitChance = "40%";
	//Headshot
	string archerSkill3Name = "Headshot";
	int archerSkill3Damage = 120;
	float archerSkill3HitChance = 1.5f;
	string archerSkill3DisplayHitChance = "15%";
	//Explosive Shot
	string archerSkill4Name = "Explosive Shot";
	int archerSkill4Damage = 40;
	float archerSkill4HitChance = 7.0f;
	string archerSkill4DisplayHitChance = "70%";

	//Rogue
	float rogueHealth = 150;
	//AbilitiesRogue
	//Backstab
	string rogueSkill1Name = "Backstab";
	int rogueSkill1Damage = 40;
	float rogueSkill1HitChance = 6.0f;
	string rogueSkill1DisplayHitChance = "60%";
	//Dagger Throw
	string rogueSkill2Name = "Dagger Throw";
	int rogueSkill2Damage = 50;
	float rogueSkill2HitChance = 5.0f;
	string rogueSkill2DisplayHitChance = "50%";
	//Swift Slash
	string rogueSkill3Name = "Swift Slash";
	int rogueSkill3Damage = 20;
	float rogueSkill3HitChance = 10.0f;
	string rogueSkill3DisplayHitChance = "100%";
	//Flurry
	string rogueSkill4Name = "Flurry";
	int rogueSkill4Damage = 90;
	float rogueSkill4HitChance = 2.5f;
	string rogueSkill4DisplayHitChance = "25%";

	//Player Heroes
	int player1Hero;
	int player2Hero;

	//Player Attack
	int player1Attack;
	int player2Attack;

	//Player1 Skills
	float player1Health;
	//Skill1
	string player1Skill1Name;
	int player1Skill1Damage;
	float player1Skill1HitChance;
	string player1Skill1DisplayHitChance;
	//Skill2
	string player1Skill2Name;
	int player1Skill2Damage;
	float player1Skill2HitChance;
	string player1Skill2DisplayHitChance;
	//skill3
	string player1Skill3Name;
	int player1Skill3Damage;
	float player1Skill3HitChance;
	string player1Skill3DisplayHitChance;
	//Skill4
	string player1Skill4Name;
	int player1Skill4Damage;
	float player1Skill4HitChance;
	string player1Skill4DisplayHitChance;

	//Player2 Skills
	float player2Health;
	//Skill1
	string player2Skill1Name;
	int player2Skill1Damage;
	float player2Skill1HitChance;
	string player2Skill1DisplayHitChance;
	//Skill2
	string player2Skill2Name;
	int player2Skill2Damage;
	float player2Skill2HitChance;
	string player2Skill2DisplayHitChance;
	//skill3
	string player2Skill3Name;
	int player2Skill3Damage;
	float player2Skill3HitChance;
	string player2Skill3DisplayHitChance;
	//Skill4
	string player2Skill4Name;
	int player2Skill4Damage;
	float player2Skill4HitChance;
	string player2Skill4DisplayHitChance;

	default_random_engine randomGenerator(time(0));
	uniform_real_distribution<float> attackRoll(0.0f, 10.0f);

	bool runProgram = true;

	while (runProgram == true) {

		cout << "Heroes of Text\n\n";

		//player 1 Hero select
		cout << "Player 1. Choose your Hero (1/2/3/4)\n" << "1. Warrior	2. Mage		3. Archer	 4. Rogue\n\n";
		cin >> player1Hero;
		cout << endl;

		cout << "\n\n";
		system("PAUSE");
		system("CLS");

		//player 2 Hero select
		cout << "Player 2. Choose your Hero (1/2/3/4)\n" << "1. Warrior	2. Mage		3. Archer	 4. Rogue\n\n";
		cin >> player2Hero;
		cout << endl;

		cout << "\n\n";
		system("PAUSE");
		system("CLS");

		//Player 1
		if (player1Hero == 1) {		//Warrior
			player1Health = warriorHealth;
			//Skill 1
			player1Skill1Name = warriorSkill1Name;
			player1Skill1Damage = warriorSkill1Damage;
			player1Skill1HitChance = warriorSkill1HitChance;
			player1Skill1DisplayHitChance = warriorSkill1DisplayHitChance;
			//Skill 2
			player1Skill2Name = warriorSkill2Name;
			player1Skill2Damage = warriorSkill2Damage;
			player1Skill2HitChance = warriorSkill2HitChance;
			player1Skill2DisplayHitChance = warriorSkill2DisplayHitChance;
			//Skill 3
			player1Skill3Name = warriorSkill3Name;
			player1Skill3Damage = warriorSkill3Damage;
			player1Skill3HitChance = warriorSkill3HitChance;
			player1Skill3DisplayHitChance = warriorSkill3DisplayHitChance;
			//Skill 4
			player1Skill4Name = warriorSkill4Name;
			player1Skill4Damage = warriorSkill4Heal;
			player1Skill4HitChance = warriorSkill4HitChance;
			player1Skill4DisplayHitChance = warriorSkill4DisplayHitChance;
		}
		else if (player1Hero == 2) {		//Mage
			player1Health = mageHealth;
			//Skill 1
			player1Skill1Name = mageSkill1Name;
			player1Skill1Damage = mageSkill1Damage;
			player1Skill1HitChance = mageSkill1HitChance;
			player1Skill1DisplayHitChance = mageSkill1DisplayHitChance;
			//Skill 2
			player1Skill2Name = mageSkill2Name;
			player1Skill2Damage = mageSkill2Damage;
			player1Skill2HitChance = mageSkill2HitChance;
			player1Skill2DisplayHitChance = mageSkill2DisplayHitChance;
			//Skill 3
			player1Skill3Name = mageSkill3Name;
			player1Skill3Damage = mageSkill3Damage;
			player1Skill3HitChance = mageSkill3HitChance;
			player1Skill3DisplayHitChance = mageSkill3DisplayHitChance;
			//Skill 4
			player1Skill4Name = mageSkill4Name;
			player1Skill4Damage = mageSkill4Damage;
			player1Skill4HitChance = mageSkill4HitChance;
			player1Skill4DisplayHitChance = mageSkill4DisplayHitChance;
		}
		else if (player1Hero == 3) {		//Archer
			player1Health = archerHealth;
			//Skill 1
			player1Skill1Name = archerSkill1Name;
			player1Skill1Damage = archerSkill1Damage;
			player1Skill1HitChance = archerSkill1HitChance;
			player1Skill1DisplayHitChance = archerSkill1DisplayHitChance;
			//Skill 2
			player1Skill2Name = archerSkill2Name;
			player1Skill2Damage = archerSkill2Damage;
			player1Skill2HitChance = archerSkill2HitChance;
			player1Skill2DisplayHitChance = archerSkill2DisplayHitChance;
			//Skill 3
			player1Skill3Name = archerSkill3Name;
			player1Skill3Damage = archerSkill3Damage;
			player1Skill3HitChance = archerSkill3HitChance;
			player1Skill3DisplayHitChance = archerSkill3DisplayHitChance;
			//Skill 4
			player1Skill4Name = archerSkill4Name;
			player1Skill4Damage = archerSkill4Damage;
			player1Skill4HitChance = archerSkill4HitChance;
			player1Skill4DisplayHitChance = archerSkill4DisplayHitChance;
		}
		else if (player1Hero == 4) {		//Rogue
			player1Health = archerHealth;
			//Skill 1
			player1Skill1Name = rogueSkill1Name;
			player1Skill1Damage = rogueSkill1Damage;
			player1Skill1HitChance = rogueSkill1HitChance;
			player1Skill1DisplayHitChance = rogueSkill1DisplayHitChance;
			//Skill 2
			player1Skill2Name = rogueSkill2Name;
			player1Skill2Damage = rogueSkill2Damage;
			player1Skill2HitChance = rogueSkill2HitChance;
			player1Skill2DisplayHitChance = rogueSkill2DisplayHitChance;
			//Skill 3
			player1Skill3Name = rogueSkill3Name;
			player1Skill3Damage = rogueSkill3Damage;
			player1Skill3HitChance = rogueSkill3HitChance;
			player1Skill3DisplayHitChance = rogueSkill3DisplayHitChance;
			//Skill 4
			player1Skill4Name = rogueSkill4Name;
			player1Skill4Damage = rogueSkill4Damage;
			player1Skill4HitChance = rogueSkill4HitChance;
			player1Skill4DisplayHitChance = rogueSkill4DisplayHitChance;
		}

		//Player 2
		if (player2Hero == 1) {		//Warrior
			player2Health = warriorHealth;
			//Skill 1
			player2Skill1Name = warriorSkill1Name;
			player2Skill1Damage = warriorSkill1Damage;
			player2Skill1HitChance = warriorSkill1HitChance;
			player2Skill1DisplayHitChance = warriorSkill1DisplayHitChance;
			//Skill 2
			player2Skill2Name = warriorSkill2Name;
			player2Skill2Damage = warriorSkill2Damage;
			player2Skill2HitChance = warriorSkill2HitChance;
			player2Skill2DisplayHitChance = warriorSkill2DisplayHitChance;
			//Skill 3
			player2Skill3Name = warriorSkill3Name;
			player2Skill3Damage = warriorSkill3Damage;
			player2Skill3HitChance = warriorSkill3HitChance;
			player2Skill3DisplayHitChance = warriorSkill3DisplayHitChance;
			//Skill 4
			player2Skill4Name = warriorSkill4Name;
			player2Skill4Damage = warriorSkill4Heal;
			player2Skill4HitChance = warriorSkill4HitChance;
			player2Skill4DisplayHitChance = warriorSkill4DisplayHitChance;
		}
		else if (player2Hero == 2) {		//Mage
			player2Health = mageHealth;
			//Skill 1
			player2Skill1Name = mageSkill1Name;
			player2Skill1Damage = mageSkill1Damage;
			player2Skill1HitChance = mageSkill1HitChance;
			player2Skill1DisplayHitChance = mageSkill1DisplayHitChance;
			//Skill 2
			player2Skill2Name = mageSkill2Name;
			player2Skill2Damage = mageSkill2Damage;
			player2Skill2HitChance = mageSkill2HitChance;
			player2Skill2DisplayHitChance = mageSkill2DisplayHitChance;
			//Skill 3
			player2Skill3Name = mageSkill3Name;
			player2Skill3Damage = mageSkill3Damage;
			player2Skill3HitChance = mageSkill3HitChance;
			player2Skill3DisplayHitChance = mageSkill3DisplayHitChance;
			//Skill 4
			player2Skill4Name = mageSkill4Name;
			player2Skill4Damage = mageSkill4Damage;
			player2Skill4HitChance = mageSkill4HitChance;
			player2Skill4DisplayHitChance = mageSkill4DisplayHitChance;
		}
		else if (player2Hero == 3) {		//Archer
			player2Health = archerHealth;
			//Skill 1
			player2Skill1Name = archerSkill1Name;
			player2Skill1Damage = archerSkill1Damage;
			player2Skill1HitChance = archerSkill1HitChance;
			player2Skill1DisplayHitChance = archerSkill1DisplayHitChance;
			//Skill 2
			player2Skill2Name = archerSkill2Name;
			player2Skill2Damage = archerSkill2Damage;
			player2Skill2HitChance = archerSkill2HitChance;
			player2Skill2DisplayHitChance = archerSkill2DisplayHitChance;
			//Skill 3
			player2Skill3Name = archerSkill3Name;
			player2Skill3Damage = archerSkill3Damage;
			player2Skill3HitChance = archerSkill3HitChance;
			player2Skill3DisplayHitChance = archerSkill3DisplayHitChance;
			//Skill 4
			player2Skill4Name = archerSkill4Name;
			player2Skill4Damage = archerSkill4Damage;
			player2Skill4HitChance = archerSkill4HitChance;
			player2Skill4DisplayHitChance = archerSkill4DisplayHitChance;
		}
		else if (player2Hero == 4) {		//Rogue
			player2Health = rogueHealth;
			//Skill 1
			player2Skill1Name = rogueSkill1Name;
			player2Skill1Damage = rogueSkill1Damage;
			player2Skill1HitChance = rogueSkill1HitChance;
			player2Skill1DisplayHitChance = rogueSkill1DisplayHitChance;
			//Skill 2
			player2Skill2Name = rogueSkill2Name;
			player2Skill2Damage = rogueSkill2Damage;
			player2Skill2HitChance = rogueSkill2HitChance;
			player2Skill2DisplayHitChance = rogueSkill2DisplayHitChance;
			//Skill 3
			player2Skill3Name = rogueSkill3Name;
			player2Skill3Damage = rogueSkill3Damage;
			player2Skill3HitChance = rogueSkill3HitChance;
			player2Skill3DisplayHitChance = rogueSkill3DisplayHitChance;
			//Skill 4
			player2Skill4Name = rogueSkill4Name;
			player2Skill4Damage = rogueSkill4Damage;
			player2Skill4HitChance = rogueSkill4HitChance;
			player2Skill4DisplayHitChance = rogueSkill4DisplayHitChance;
		}

		while (player1Health > 0 && player2Health > 0) {
			cout << "Player 1 Health " << player1Health << "      " << "Player 2 Health " << player2Health << endl << endl;

			//Player 1
			cout << " Player 1 Choose your move (1/2/3/4)\n\n";
			cout << "1. " << player1Skill1Name << "(" << player1Skill1Damage << "/" << player1Skill1DisplayHitChance << ")" << "  " << "2. " << player1Skill2Name << "(" << player1Skill2Damage << "/" << player1Skill2DisplayHitChance << ")" << "  " << "3. " << player1Skill3Name << "(" << player1Skill3Damage << "/" << player1Skill3DisplayHitChance << ")" << "  " << "4. " << player1Skill4Name << "(" << player1Skill4Damage << "/" << player1Skill4DisplayHitChance << ")" << "\n\n";
			cin >> player1Attack;
			cout << endl;

			if (player1Attack == 1) {
				if (attackRoll(randomGenerator) <= player1Skill1HitChance){
					player2Health = player2Health - player1Skill1Damage;
					cout << "You did " << player1Skill1Damage << " damage!";
				}
				else {
					cout << "You missed.";
				}
			}
			else if (player1Attack == 2) {
				if (attackRoll(randomGenerator) <= player1Skill2HitChance){
					player2Health = player2Health - player1Skill2Damage;
					cout << "You did " << player1Skill2Damage << " damage!";
				}
				else {
					cout << "You missed.";
				}
			}
			else if (player1Attack == 3) {
				if (player1Skill3Name == warriorSkill3Name) {
					if (attackRoll(randomGenerator) <= warriorSkill3HitChance) {
						cout << "DDD     EEEE       MM    MM           AA       CCCC   II       AA\n";
						cout << "D  D    E         M  M  M  M         A  A     CC      II      A  A\n";
						cout << "D   D   EEE      M    MM    M       AAAAAA    C       II     AAAAAA\n";
						cout << "D  D    E       M            M     A      A   CC      II    A      A\n";
						cout << "DDD     EEEE   M              M   A        A   CCCC   II   A        A\n\n";

						cout << "You did " << warriorSkill3Damage << " damage!.";

						player2Health = player2Health - warriorSkill3Damage;
					}
					else {
						cout << "You missed.";
					}
				}
				else if (attackRoll(randomGenerator) <= player1Skill3HitChance){
					player2Health = player2Health - player1Skill3Damage;
					cout << "You did " << player1Skill3Damage << " damage!";
				}
				else {
					cout << "You missed.";
				}
			}
			else if (player1Attack == 4) {
				if (player1Skill4Damage == warriorSkill4Heal) {
					if (attackRoll(randomGenerator) <= warriorSkill4HitChance) {
						player1Health = player1Health - warriorSkill4Heal;
						cout << "You healed yourself for " << warriorSkill4Heal;
					}
					else {
						cout << "You failed to heal your self.";
					}
				}
				else if (attackRoll(randomGenerator) <= player1Skill4HitChance) {
					player2Health = player2Health - player1Skill4Damage;
					cout << "You did " << player1Skill4Damage << " damage!";
				}
				else {
					cout << "You missed.";
				}
			}

			cout << "\n\n";
			system("PAUSE");
			system("CLS");

			//Player 2
			cout << " Player 2 Choose your move (1/2/3/4)\n\n";
			cout << "1. " << player2Skill1Name << "  " << "2. " << player2Skill2Name << "  " << "3. " << player2Skill3Name << "  " << "4. " << player2Skill4Name << "\n\n";
			cin >> player2Attack;
			cout << endl;

			if (player2Attack == 1) {
				if (attackRoll(randomGenerator) <= player2Skill1HitChance){
					player1Health = player1Health - player2Skill1Damage;
					cout << "You did " << player2Skill1Damage << " damage!";
				}
				else {
					cout << "You missed.";
				}
			}
			else if (player2Attack == 2) {
				if (attackRoll(randomGenerator) <= player2Skill2HitChance){
					player1Health = player1Health - player2Skill2Damage;
					cout << "You did " << player2Skill2Damage << " damage!";
				}
				else {
					cout << "You missed.";
				}
			}
			else if (player2Attack == 3) {
				if (player2Skill3Name == warriorSkill3Name) {
					if (attackRoll(randomGenerator) <= warriorSkill3HitChance) {
						cout << "DDD     EEEE       MM    MM           AA       CCCC   II       AA\n";
						cout << "D  D    E         M  M  M  M         A  A     CC      II      A  A\n";
						cout << "D   D   EEE      M    MM    M       AAAAAA    C       II     AAAAAA\n";
						cout << "D  D    E       M            M     A      A   CC      II    A      A\n";
						cout << "DDD     EEEE   M              M   A        A   CCCC   II   A        A\n\n";

						cout << "You did " << warriorSkill3Damage << " damage!.";

						player1Health = player1Health - warriorSkill3Damage;
					}
					else {
						cout << "You missed.";
					}
				}
				else if (attackRoll(randomGenerator) <= player2Skill3HitChance){
					player1Health = player1Health - player2Skill3Damage;
					cout << "You did " << player2Skill3Damage << " damage!";
				}
				else {
					cout << "You missed.";
				}
			}
			else if (player2Attack == 4) {
				if (player2Skill4Damage == warriorSkill4Heal) {
					if (attackRoll(randomGenerator) <= warriorSkill4HitChance) {
						player2Health = player2Health - warriorSkill4Heal;
						cout << "You healed yourself for " << warriorSkill4Heal;
					}
					else {
						cout << "You failed to heal yourself.";
					}
				}
				else if (attackRoll(randomGenerator) <= player2Skill4HitChance) {
					player1Health = player1Health - player2Skill4Damage;
					cout << "You did " << player2Skill4Damage << " damage!";
				}
				else {
					cout << "You missed.";
				}
			}

			cout << "\n\n";
			system("PAUSE");
			system("CLS");
		}

		//Resultat
		cout << "Player 1 Health " << player1Health << "  " << "Player 2 Health " << player2Health << "\n\n";
		
		if (player1Health > 0 && player2Health <= 0) {
			cout << "Player 1 wins!!!";
		}
		else if (player2Health > 0 && player1Health <= 0) {
			cout << "Player 2 wins!!!";
		}
		else if (player1Health <= 0 && player2Health <= 0) {
			cout << "It's a tie. You are both dead.";
		}

		cout << "\n\n";
		system("PAUSE");
		system("CLS");

		char tryAgain;
		cout << "Do you want to Play again? y/n\n";
		cin >> tryAgain;
		cout << endl << endl;

		if (tryAgain == 'y' || tryAgain == 'Y') {
			system("CLS");
			runProgram = true;
		}
		else {
			runProgram = false;
		}
	}
	system("PAUSE");
	return 0;
}