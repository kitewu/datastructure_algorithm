#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Hero{
	int attack;
	int health;
	Hero(){
		attack = 0;
		health = 30;
	}
	Hero(int heal, int att){
		attack = att;
		health = heal;
	}
};

using namespace std;

int main(){
	vector<Hero> player[2];
	player[0].push_back(Hero());
	player[1].push_back(Hero());

	int n, flag = 0;
	string option;
	cin >> n;
	while(n-- && player[0][0].health > 0 && player[1][0].health > 0){
		cin >> option;
		if(option[0] == 'e'){
			flag = (flag + 1) % 2;
			continue;
		}else if(option[0] == 'a'){//¹¥»÷ 
			int pos1, pos2;
			cin >> pos1 >> pos2;
			player[flag][pos1].health -= player[(flag + 1) % 2][pos2].attack;
			player[(flag + 1) % 2][pos2].health -= player[flag][pos1].attack;
			if(player[flag][pos1].health <= 0 && pos1 != 0)
				player[flag].erase(player[flag].begin() + pos1);
			if(player[(flag + 1) % 2][pos2].health <= 0 && pos2 != 0)
				player[(flag + 1) % 2].erase(player[(flag + 1) % 2].begin() + pos2);
		}else{//ÕÙ»½
			int pos, att, heal;
			cin >> pos >> att >> heal; 
			player[flag].insert(player[flag].begin() + pos, Hero(heal, att));
		}
	}
	if(player[0][0].health > 0 && player[1][0].health <= 0)
		cout << 1 << endl;
	else if(player[0][0].health <= 0 && player[1][0].health > 0)
		cout << -1 << endl;
	else
		cout << 0 << endl;
	for(int k = 0; k < 2; k++){
		cout << player[k][0].health << endl;
		cout << player[k].size() - 1;
		for(int i = 1; i < player[k].size(); i++)
			cout << " " << player[k][i].health;
		cout << endl;
	}
}
