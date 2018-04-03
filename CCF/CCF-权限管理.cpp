#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<cctype>
#include<list>
#include<map>

using namespace std;

map<string, int> map_privi;
map<string, map<string, int> > map_role;
map<string, map<string, int> > map_user;

//输入权限 
void inputPrivilege(map<string, int> &mmap){
	int n;
	string privi_name;
	cin >> n;
	while(n--){
		cin >> privi_name;
		char c = privi_name[privi_name.length()-1];
		if(isdigit(c)){
			privi_name = privi_name.substr(0, privi_name.find_last_of(":"));
			if(mmap[privi_name] < c - '0') //保证具有最高的等级权限 
				mmap[privi_name] = c - '0';
		}
		else
			mmap[privi_name] = -1;
	}
}
//输入角色 
void inputRole(map<string, map<string, int> > &mmap){
	int n;
	string role_name;
	cin >> n;
	while(n--){
		cin >> role_name;
		map<string, int> m_privi;
		inputPrivilege(m_privi);
		mmap[role_name] = m_privi;
	}
}
//输入用户 
void inputUser(){
	string user_name, role_name;
	int n;
	cin >> n;
	while(n--){
		int m;
		cin >> user_name;
		cin >> m;
		map<string, int> roles;
		while(m--){
			cin >> role_name;
			map<string, int> temp = map_role[role_name];
			map<string, int>::iterator it;
			for(it = temp.begin(); it != temp.end(); it++){
				if(it->second == -1){
					roles[it->first] = -1;
				}else{
					if(roles[it->first] < it->second){
						roles[it->first] = it->second;
					}
				}
			}
		}
		map_user[user_name] = roles;
	}
}
int main() {
	inputPrivilege(map_privi);
	inputRole(map_role);
	inputUser();	
	int n;
	cin >> n;
	string name, privi;
	while(n--){
		cin >> name >> privi;
		map<string, map<string, int> >::iterator t_it = map_user.find(name);
		if(t_it == map_user.end())
			cout << "false" << endl;
		else{
			map<string, int> mm = map_user[name];
			char c = privi[privi.length() - 1];
			privi = privi.substr(0, privi.find_last_of(":"));
			map<string, int>::iterator t_it = mm.find(privi);
			if(t_it == mm.end()) //没有那个权限名 
				cout << "false" << endl;
			else{
				if(isdigit(c))
					cout << (mm[privi] >= c - '0' ? "true" : "false") << endl;
				else{
					if(mm[privi] == -1)
						cout << "true" ;
					else
						cout << mm[privi];
				}
			}
		}
		cout << endl;	
	}	
    return 0;
}

