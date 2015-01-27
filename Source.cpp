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
	skillDamage[clas - 1][skill - 1] = damage;
}

int getSkillDamage(int clas, int skill){
	return skillDamage[clas - 1][skill - 1];
};

//HitChance
void setSkillHitChance(int clas, int skill, float hitChance) {
	skillHitChance[clas - 1][skill - 1] = hitChance;
}

float getSkillHitChance(int clas, int skill){
	return skillHitChance[clas - 1][skill - 1];
};


//DisplayHitChance
void setSkillDisplayHitChance(int clas, int skill, string displayHitChance) {
	skillDisplayHitChance[clas - 1][skill - 1] = displayHitChance;
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
	addInfoSkill(1, 4, "Rest", -50, 5.0f, "50%");

	//Mage
	float mageHealth = 120;
	//AbilitiesMage
	//Firebolt
	addInfoSkill(2, 1, "Firebolt", 20, 10.0f, "100%");
	
	//Magic Missile
	addInfoSkill(2, 2, "Magic Missile", 30, 8.0f, "80%");
	
	//Thunder
	addInfoSkill(2, 3, "Thunder", 50, 6.0f, "60%");
	
	//Pyroblast
	addInfoSkill(2, 4, "Pyroblast", 100, 2.0f, "20%");

	//Archer
	float archerHealth = 150;
	//AbilitiesArcher
	//Sure Shot
	addInfoSkill(3, 1, "Sure Shot", 20, 10.0f, "100%");
	
	//Falcon Shot
	addInfoSkill(3, 2, "Falcon Shot", 50, 4.0f, "40%");
	
	//Headshot
	addInfoSkill(3, 3, "Headshot", 120, 1.5f, "15%");
	
	//Explosive Shot
	addInfoSkill(3, 4, "Explosive Shot", 40, 7.0f, "70%");

	//Rogue
	float rogueHealth = 150;
	//AbilitiesRogue
	//Backstab
	addInfoSkill(4, 1, "Backstab", 40, 6.0f, "60%");
	
	//Dagger Throw
	addInfoSkill(4, 2, "Dagger Throw", 50, 5.0f, "50%");
	
	//Swift Slash
	addInfoSkill(4, 3, "Swift Slash", 20, 10.0f, "100%");
	
	//Flurry
	addInfoSkill(4, 4, "Flurry", 20, 10.0f, "25%");
	

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
			//Skill 1
			player1Skill1Name = getSkillName(1, 1);
			player1Skill1Damage = getSkillDamage(1, 1);
			player1Skill1HitChance = getSkillHitChance(1, 1);
			player1Skill1DisplayHitChance = getSkillDisplayHitChance(1, 1);
			//Skill 2
			player1Skill2Name = getSkillName(1, 2);
			player1Skill2Damage = getSkillDamage(1, 2);
			player1Skill2HitChance = getSkillHitChance(1, 2);
			player1Skill2DisplayHitChance = getSkillDisplayHitChance(1, 2);
			//Skill 3
			player1Skill3Name = getSkillName(1, 3);
			player1Skill3Damage = getSkillDamage(1, 3);
			player1Skill3HitChance = getSkillHitChance(1, 3);
			player1Skill3DisplayHitChance = getSkillDisplayHitChance(1, 3);
			//Skill 4
			player1Skill4Name = getSkillName(1, 4);
			player1Skill4Damage = getSkillDamage(1, 4);
			player1Skill4HitChance = getSkillHitChance(1, 4);
			player1Skill4DisplayHitChance = getSkillDisplayHitChance(1, 4);
		}
		//Mage
		else if (player1Hero == 2) {
			player1Health = mageHealth;
			//Skill 1
			player1Skill1Name = getSkillName(2, 1);
			player1Skill1Damage = getSkillDamage(2, 1);
			player1Skill1HitChance = getSkillHitChance(2, 1);
			player1Skill1DisplayHitChance = getSkillDisplayHitChance(2, 1);
			//Skill 2
			player1Skill2Name = getSkillName(2, 2);
			player1Skill2Damage = getSkillDamage(2, 2);
			player1Skill2HitChance = getSkillHitChance(2, 2);
			player1Skill2DisplayHitChance = getSkillDisplayHitChance(2, 2);
			//Skill 3
			player1Skill3Name = getSkillName(2, 3);
			player1Skill3Damage = getSkillDamage(2, 3);
			player1Skill3HitChance = getSkillHitChance(2, 3);
			player1Skill3DisplayHitChance = getSkillDisplayHitChance(2, 3);
			//Skill 4
			player1Skill4Name = getSkillName(2, 4);
			player1Skill4Damage = getSkillDamage(2, 4);
			player1Skill4HitChance = getSkillHitChance(2, 4);
			player1Skill4DisplayHitChance = getSkillDisplayHitChance(2, 4);
		}
		//Archer
		else if (player1Hero == 3) {
			player1Health = archerHealth;
			//Skill 1
			player1Skill1Name = getSkillName(3, 1);
			player1Skill1Damage = getSkillDamage(3, 1);
			player1Skill1HitChance = getSkillHitChance(3, 1);
			player1Skill1DisplayHitChance = getSkillDisplayHitChance(3, 1);
			//Skill 2
			player1Skill2Name = getSkillName(3, 2);
			player1Skill2Damage = getSkillDamage(3, 2);
			player1Skill2HitChance = getSkillHitChance(3, 2);
			player1Skill2DisplayHitChance = getSkillDisplayHitChance(3, 2);
			//Skill 3
			player1Skill3Name = getSkillName(3, 3);
			player1Skill3Damage = getSkillDamage(3, 3);
			player1Skill3HitChance = getSkillHitChance(3, 3);
			player1Skill3DisplayHitChance = getSkillDisplayHitChance(3, 3);
			//Skill 4
			player1Skill4Name = getSkillName(3, 4);
			player1Skill4Damage = getSkillDamage(3, 4);
			player1Skill4HitChance = getSkillHitChance(3, 4);
			player1Skill4DisplayHitChance = getSkillDisplayHitChance(3, 4);
		}
		//Rogue
		else if (player1Hero == 4) {
			player1Health = archerHealth;
			//Skill 1
			player1Skill1Name = getSkillName(4, 1);
			player1Skill1Damage = getSkillDamage(4, 1);
			player1Skill1HitChance = getSkillHitChance(4, 1);
			player1Skill1DisplayHitChance = getSkillDisplayHitChance(4, 1);
			//Skill 2
			player1Skill2Name = getSkillName(4, 2);
			player1Skill2Damage = getSkillDamage(4, 2);
			player1Skill2HitChance = getSkillHitChance(4, 2);
			player1Skill2DisplayHitChance = getSkillDisplayHitChance(4, 2);
			//Skill 3 
			player1Skill3Name = getSkillName(4, 3);
			player1Skill3Damage = getSkillDamage(4, 3);
			player1Skill3HitChance = getSkillHitChance(4, 3);
			player1Skill3DisplayHitChance = getSkillDisplayHitChance(4, 3);
			//Skill 4
			player1Skill4Name = getSkillName(4, 4);
			player1Skill4Damage = getSkillDamage(4, 4);
			player1Skill4HitChance = getSkillHitChance(4, 4);
			player1Skill4DisplayHitChance = getSkillDisplayHitChance(4, 4);
		}

			//Player 2

		//Warrior
		if (player2Hero == 1) {
			player2Health = warriorHealth;
			//Skill 1
			player2Skill1Name = getSkillName(1, 1);
			player2Skill1Damage = getSkillDamage(1, 1);
			player2Skill1HitChance = getSkillHitChance(1, 1);
			player2Skill1DisplayHitChance = getSkillDisplayHitChance(1, 1);
			//Skill 2
			player2Skill2Name = getSkillName(1, 2);
			player2Skill2Damage = getSkillDamage(1, 2);
			player2Skill2HitChance = getSkillHitChance(1, 2);
			player2Skill2DisplayHitChance = getSkillDisplayHitChance(1, 2);
			//Skill 3
			player2Skill3Name = getSkillName(1, 3);
			player2Skill3Damage = getSkillDamage(1, 3);
			player2Skill3HitChance = getSkillHitChance(1, 3);
			player2Skill3DisplayHitChance = getSkillDisplayHitChance(1, 3);
			//Skill 4
			player2Skill4Name = getSkillName(1, 4);
			player2Skill4Damage = getSkillDamage(1, 4);
			player2Skill4HitChance = getSkillHitChance(1, 4);
			player2Skill4DisplayHitChance = getSkillDisplayHitChance(1, 4);
		}
		//Mage
		else if (player2Hero == 2) {
			player2Health = mageHealth;
			//Skill 1
			player2Skill1Name = getSkillName(2, 1);
			player2Skill1Damage = getSkillDamage(2, 1);
			player2Skill1HitChance = getSkillHitChance(2, 1);
			player2Skill1DisplayHitChance = getSkillDisplayHitChance(2, 1);
			//Skill 2
			player2Skill2Name = getSkillName(2, 2);
			player2Skill2Damage = getSkillDamage(2, 2);
			player2Skill2HitChance = getSkillHitChance(2, 2);
			player2Skill2DisplayHitChance = getSkillDisplayHitChance(2, 2);
			//Skill 3
			player2Skill3Name = getSkillName(2, 3);
			player2Skill3Damage = getSkillDamage(2, 3);
			player2Skill3HitChance = getSkillHitChance(2, 3);
			player2Skill3DisplayHitChance = getSkillDisplayHitChance(2, 3);
			//Skill 4
			player2Skill4Name = getSkillName(2, 4);
			player2Skill4Damage = getSkillDamage(2, 4);
			player2Skill4HitChance = getSkillHitChance(2, 4);
			player2Skill4DisplayHitChance = getSkillDisplayHitChance(2, 4);
		}
		//Archer
		else if (player2Hero == 3) {
			player2Health = archerHealth;
			//Skill 1
			player2Skill1Name = getSkillName(3, 1);
			player2Skill1Damage = getSkillDamage(3, 1);
			player2Skill1HitChance = getSkillHitChance(3, 1);
			player2Skill1DisplayHitChance = getSkillDisplayHitChance(3, 1);
			//Skill 2
			player2Skill2Name = getSkillName(3, 2);
			player2Skill2Damage = getSkillDamage(3, 2);
			player2Skill2HitChance = getSkillHitChance(3, 2);
			player2Skill2DisplayHitChance = getSkillDisplayHitChance(3, 2);
			//Skill 3
			player2Skill3Name = getSkillName(3, 3);
			player2Skill3Damage = getSkillDamage(3, 3);
			player2Skill3HitChance = getSkillHitChance(3, 3);
			player2Skill3DisplayHitChance = getSkillDisplayHitChance(3, 3);
			//Skill 4
			player2Skill4Name = getSkillName(3, 4);
			player2Skill4Damage = getSkillDamage(3, 4);
			player2Skill4HitChance = getSkillHitChance(3, 4);
			player2Skill4DisplayHitChance = getSkillDisplayHitChance(3, 4);
		}
		//Rogue
		else if (player2Hero == 4) {
			player2Health = rogueHealth;
			//Skill 1
			player2Skill1Name = getSkillName(4, 1);
			player2Skill1Damage = getSkillDamage(4, 1);
			player2Skill1HitChance = getSkillHitChance(4, 1);
			player2Skill1DisplayHitChance = getSkillDisplayHitChance(4, 1);
			//Skill 2
			player2Skill2Name = getSkillName(4, 2);
			player2Skill2Damage = getSkillDamage(4, 2);
			player2Skill2HitChance = getSkillHitChance(4, 2);
			player2Skill2DisplayHitChance = getSkillDisplayHitChance(4, 2);
			//Skill 3
			player2Skill3Name = getSkillName(4, 3);
			player2Skill3Damage = getSkillDamage(4, 3);
			player2Skill3HitChance = getSkillHitChance(4, 3);
			player2Skill3DisplayHitChance = getSkillDisplayHitChance(4, 3);
			//Skill 4
			player2Skill4Name = getSkillName(4, 4);
			player2Skill4Damage = getSkillDamage(4, 4);
			player2Skill4HitChance = getSkillHitChance(4, 4);
			player2Skill4DisplayHitChance = getSkillDisplayHitChance(4, 4);
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
						if (player1Skill3Name == getSkillName(1, 3)) {
							if (attackRoll(randomGenerator) <= getSkillHitChance(1, 3)) {
								cout << "DDD     EEEE       MM    MM           AA       CCCC   II       AA\n";
								cout << "D  D    E         M  M  M  M         A  A     CC      II      A  A\n";
								cout << "D   D   EEE      M    MM    M       AAAAAA    C       II     AAAAAA\n";
								cout << "D  D    E       M            M     A      A   CC      II    A      A\n";
								cout << "DDD     EEEE   M              M   A        A   CCCC   II   A        A\n\n";

								cout << "You did " << getSkillDamage(1, 3) << " damage!.";

								player2Health = player2Health - getSkillDamage(1, 3);
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
						if (player1Skill4Damage == getSkillDamage(1, 4)) {
							if (attackRoll(randomGenerator) <= getSkillHitChance(1, 4)) {
								player1Health = player1Health - getSkillDamage(1, 4);
								cout << "You healed yourself for " << getSkillDamage(1, 4);
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

					cout << "Player 1 Health " << player1Health << "      " << "Player 2 Health " << player2Health << endl << endl;

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
						if (player2Skill3Name == getSkillName(1, 3)) {
							if (attackRoll(randomGenerator) <= getSkillHitChance(1, 3)) {
								cout << "DDD     EEEE       MM    MM           AA       CCCC   II       AA\n";
								cout << "D  D    E         M  M  M  M         A  A     CC      II      A  A\n";
								cout << "D   D   EEE      M    MM    M       AAAAAA    C       II     AAAAAA\n";
								cout << "D  D    E       M            M     A      A   CC      II    A      A\n";
								cout << "DDD     EEEE   M              M   A        A   CCCC   II   A        A\n\n";

								cout << "You did " << getSkillDamage(1, 3) << " damage!.";

								player1Health = player1Health - getSkillDamage(1, 3);
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
						if (player2Skill4Damage == getSkillDamage(1, 4)) {
							if (attackRoll(randomGenerator) <= getSkillHitChance(1, 4)) {
								player2Health = player2Health - getSkillDamage(1, 4);
								cout << "You healed yourself for " << getSkillDamage(1, 4);
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
			return 0;
		}