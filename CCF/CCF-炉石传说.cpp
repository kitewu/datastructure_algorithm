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
	Hero player[2][8];
	player[0][0] = Hero();
	player[1][0] = Hero();

	int count[2] = {0, 0};

	int n, flag = 0;
	string option;
	cin >> n;
	while(n--){
		cin >> option;
		if(option[0] == 'e'){
			flag = (flag + 1) % 2;
			continue;
		}else if(option[0] == 'a'){//¹¥»÷
			if(player[0][0].health <= 0 || player[1][0].health <= 0)
				continue;
			int pos1, pos2;
			cin >> pos1 >> pos2;
			player[flag][pos1].health -= player[(flag + 1) % 2][pos2].attack;
			player[(flag + 1) % 2][pos2].health -= player[flag][pos1].attack;
			if(player[flag][pos1].health <= 0 && pos1 != 0){
				for(int i = pos1; i < 7; i++)
					player[flag][i] = player[flag][i + 1];
				count[flag]--;
			}
			if(player[(flag + 1) % 2][pos2].health <= 0 && pos2 != 0){
				for(int i = pos2; i < 7; i++)
					player[(flag + 1) % 2][i] = player[(flag + 1) % 2][i + 1];
				count[(flag + 1) % 2]--;
			}
		}else{//ÕÙ»½
			if(player[0][0].health <= 0 || player[1][0].health <= 0)
				continue;
			int pos, att, heal;
			cin >> pos >> att >> heal;
			int i = 7;
			for(; i > pos; i--)
				player[flag][i] = player[flag][i - 1];
			player[flag][i] = Hero(heal, att);
			count[flag]++;
		}
	}
	if(player[0][0].health > 0 && player[1][0].health <= 0)
		cout << 1 << endl;
	else if(player[0][0].health <= 0 && player[1][0].health > 0)
		cout << -1 << endl;
	else
		cout << 0 << endl;

	cout << (player[0][0].health <= 0 ? 0 : player[0][0].health) << endl;

	int i = 1;
	for(; i < count[0]; i++)
		cout << player[0][i].health << " ";
	cout << player[0][i].health << endl;

	cout << (player[1][0].health <= 0 ? 0 : player[1][0].health) << endl;

	for(i = 1; i < count[1]; i++)
		cout << player[1][i].health << " ";
	cout << player[1][i].health << endl;
}
