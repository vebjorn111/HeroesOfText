#include <iostream>
#include <string>
#include <random>
#include <ctime>
#define _WIN32_WINNT 0x0500
#include <windows.h>

using namespace std;


string skillName[4][4];
int skillDamage[4][4];
float skillHitChance[4][4];
string skillDisplayHitChance[4][4];

//Name
void setSkillName(int clas, int skill, string name) {
	skillName[clas - 1][skill - 1] = name;
}

string getSkillName(int clas, int skill){
	return skillName[clas - 1][skill - 1];
};

//Damage
void setSkillDamage(int clas, int skill, int damage) {
	skillName[clas - 1][skill - 1] = damage;
}

int getSkillDamage(int clas, int skill){
	return skillDamage[clas - 1][skill - 1];
};

//HitChance
void setSkillHitChance(int clas, int skill, float hitChance) {
	skillName[clas - 1][skill - 1] = hitChance;
}

float getSkillHitChance(int clas, int skill){
	return skillHitChance[clas - 1][skill - 1];
};


//DisplayHitChance
void setSkillDisplayHitChance(int clas, int skill, string displayHitChance) {
	skillName[clas - 1][skill - 1] = displayHitChance;
}

string getSkillDisplayHitChance(int clas, int skill){
	return skillDisplayHitChance[clas - 1][skill - 1];
};


void addInfoSkill(int clas, int skill, string name, int damage, float hitChance, string displayHitChance){
	setSkillName(clas, skill, name);
	setSkillDamage(clas, skill, damage);
	setSkillHitChance(clas, skill, hitChance);
	setSkillDisplayHitChance(clas, skill, displayHitChance);
}

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
	addInfoSkill(1, 1, "Cleaving Strike", 40, 3.0f, "30%");
	
	//Slash
	addInfoSkill(1, 2, "Slash", 50, 2.0f, "20%");

	//Spin to Win
	addInfoSkill(1, 3, "Spin to win!", 300, 1.0f, "10%");
	
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
		system("CLS");

		//player 2 Hero select
		cout << "Player 2. Choose your Hero (1/2/3/4)\n" << "1. Warrior	2. Mage		3. Archer	 4. Rogue\n\n";
		cin >> player2Hero;
		cout << endl;

		cout << "\n\n";
		system("CLS");

		//Player 1

		//Warrior
		if (player1Hero == 1) {		
			player1Health = warriorHealth;
			
			for (int i = 1; i <= 4; i++){
				player1Skill1Name = getSkillName(1, i);
				player1Skill1Damage = getSkillDamage(1, i);
				player1Skill1HitChance = getSkillHitChance(1, i);
				player1Skill1DisplayHitChance = getSkillDisplayHitChance(1, i);
		}
			//Mage
		if (player1Hero == 2) {		
			player1Health = mageHealth;
			
			for (int i = 1; i <= 4; i++){
				player1Skill1Name = getSkillName(2, i);
				player1Skill1Damage = getSkillDamage(2, i);
				player1Skill1HitChance = getSkillHitChance(2, i);
				player1Skill1DisplayHitChance = getSkillDisplayHitChance(2, i);
			}
		}
		//Archer
		else if (player1Hero == 3) {		
			player1Health = archerHealth;
			
			for (int i = 1; i <= 4; i++){
				player1Skill1Name = getSkillName(3, i);
				player1Skill1Damage = getSkillDamage(3, i);
				player1Skill1HitChance = getSkillHitChance(3, i);
				player1Skill1DisplayHitChance = getSkillDisplayHitChance(3, i);
			}
		}
		//Rogue
		else if (player1Hero == 4) {		
			player1Health = archerHealth;
			
			for (int i = 1; i <= 4; i++){
				player1Skill1Name = getSkillName(4, i);
				player1Skill1Damage = getSkillDamage(4, i);
				player1Skill1HitChance = getSkillHitChance(4, i);
				player1Skill1DisplayHitChance = getSkillDisplayHitChance(4, i);
			}
		}

		//Player 2

		//Warrior
		if (player2Hero == 1) {		
			player2Health = warriorHealth;
			
			for (int i = 1; i <= 4; i++){
				player2Skill1Name = getSkillName(1, i);
				player2Skill1Damage = getSkillDamage(1, i);
				player2Skill1HitChance = getSkillHitChance(1, i);
				player2Skill1DisplayHitChance = getSkillDisplayHitChance(1, i);
			}
		}
		//Mage
		else if (player2Hero == 2) {		
			player2Health = mageHealth;
			
			for (int i = 1; i <= 4; i++){
				player2Skill1Name = getSkillName(2, i);
				player2Skill1Damage = getSkillDamage(2, i);
				player2Skill1HitChance = getSkillHitChance(2, i);
				player2Skill1DisplayHitChance = getSkillDisplayHitChance(2, i);
			}
		}
		//Archer
		else if (player2Hero == 3) {		
			player2Health = archerHealth;
			
			for (int i = 1; i <= 4; i++){
				player2Skill1Name = getSkillName(3, i);
				player2Skill1Damage = getSkillDamage(3, i);
				player2Skill1HitChance = getSkillHitChance(3, i);
				player2Skill1DisplayHitChance = getSkillDisplayHitChance(3, i);
			}
		}
		//Rogue
		else if (player2Hero == 4) {		
			player2Health = rogueHealth;
			
			for (int i = 1; i <= 4; i++){
				player2Skill1Name = getSkillName(4, i);
				player2Skill1Damage = getSkillDamage(4, i);
				player2Skill1HitChance = getSkillHitChance(4, i);
				player2Skill1DisplayHitChance = getSkillDisplayHitChance(4, i);
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