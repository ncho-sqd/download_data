#include "community.h"

Community::Community()
  : name(""), people(map<string,Person>()) {
}

Community::Community(string _name, map<string,Person> _people){
	bool name_is_valid = _name.length() > 0
			&& _name.length() <= 32
			&& isalpha(_name[0])
			&& str_isalnum(_name);
	bool people_is_valid = !_people.empty();

	if(name_is_valid && people_is_valid) {
		name = _name;
		people = _people;
	}
	else {
		name = "";
		people = map<string,Person>();
	}
}

// implement Community::get_name here!
string Community::get_name(){
	return name;
}

// implement Community::set_name here!
bool Community::set_name(string _name){
	int len = _name.length();
	if(len > 0 && len <= 32 && isalpha(_name[0]) && str_isalnum(_name)){
       	name = _name;
		return true;
	}
	else{
		return false;
	}
}

bool Community::add_person(Person _person) {
    contact to_add(_person.get_username(), _person);
    auto ret = people.insert(to_add);
    return ret.second; // true if inserted, false if already there
}

Person Community::get_member(string username) {
    if (people.find(username) != people.end()) {
        return people[username];
    }
    else {
        return Person();
    }
}
    
list<string> Community::get_all_usernames() {
    list<string> usernames;
    for(auto it=people.begin(); it!=people.end(); ++it) {
        usernames.push_back(it->first);
    }
    return usernames;
}

// implement Community::print_all_usernames here!
void Community::print_all_usernames(){
	list<string> usernames = get_all_usernames();
	for(auto it=usernames.begin(); it!=usernames.end(); ++it){
		cout << *it << '\n';
	}
}
// implement Community::find_member here!
list<Person> Community::find_member(string firstname){
	list<Person> ret;
	for(auto it=people.begin(); it!=people.end(); ++it){
		if((it->second).get_firstname() == firstname){
			ret.push_back(it->second);
		}
	}
	return ret;
}

// implement Community::send_msg here!
bool Community::send_msg(list<string> usernames, string msg){
	bool ret = true;
	Person recipient;
	//Person to_erase;
	for(auto it=usernames.begin(); it!=usernames.end(); ++it){
		recipient = get_member(*it);
		if(recipient.get_firstname().length()!=0){
			recipient.send_msg(recipient,msg); // awwwwk
			people.erase(*it);
			add_person(recipient); //add new copy of recipient to community
		} else{
			ret = false;
		}
	}
	return ret;
}


/* functions for function testing */
string Community::parse_list(list<string> list) {
    string list_str = "";
    for (auto it=list.begin(); it!=list.end(); ++it) {
        list_str+=*it;
        list_str+=",";
    }
    return list_str;
}

string Community::parse_person_list(list<Person> person_list) {
    string person_list_str = "";
    for (auto it=person_list.begin(); it!=person_list.end(); ++it) {
            person_list_str+=(*it).get_username();
            person_list_str+=",";
        }
        return person_list_str;
}

bool Community::constructor_test(string _name, map<string,Person> _people) {
	Community t1 (_name,_people);
	Community t_null;

	return t1.name != t_null.name && t1.people.size() > 0;
}
