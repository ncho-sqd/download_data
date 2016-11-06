#include "person.h"

bool str_isalpha(const string str) {
    // find_if takes two iterators that bound the region of the container to
    // search and a boolean function; if any of the elements in the container
    // cause the function to return true, find_if returns an iterator to that
    // position; if no elements cause the function to return true, then an
    // iterator at the end position is returned. here, the whole string is
    // alphabetic if the end iterator is returned, so we return the boolean
    // indicating that this is the case.
    return find_if(str.begin(), str.end(), 
                   [](char c){ return !(isalpha(c)); }) == str.end();
}

bool str_isalnum(const string str) {
    // same as above, but with an alphanumeric check
    return find_if(str.begin(), str.end(), 
                   [](char c){ return !(isalnum(c)); }) == str.end();
}

Person::Person() 
  : username(""), firstname(""), lastname(""), age(0), tagline("") {
}

Person::Person(string _username, string _firstname, string _lastname, 
               int _age, string _tagline) {
	bool username_is_valid = _username.length() > 0
			&& _username.length() <= 32
			&& isalpha(_username[0])
			&& str_isalnum(_username);

	bool firstname_is_valid = _firstname.length() <= 32
			&& str_isalpha(_firstname);

	bool lastname_is_valid = _lastname.length() <= 32
			&& str_isalpha(_lastname);

	bool age_is_valid = _age >= 0
			&& _age < 128;

	bool tagline_is_valid = _tagline.length() <= 256;


	if(username_is_valid && firstname_is_valid && lastname_is_valid
			&& age_is_valid && tagline_is_valid){
		username = _username;
		firstname = _firstname;
		lastname = _lastname;
		age = _age;
		tagline = _tagline;
	}
	else{
		username = "";
		firstname = "";
		lastname = "";
		age = 0;
		tagline = "";
	}

}

// write Person::get_username here!
string Person::get_username(){
	return username;
}

string Person::get_firstname() {
    return firstname;
}
string Person::get_lastname() {
    return lastname;
}
int Person::get_age() {
    return age;
}
string Person::get_tagline() {
    return tagline;
}

// write Person::get_info here!
string Person::get_info(){
	return username + ','  + firstname + ',' + lastname + ','  + to_string(age)
			+ ',' + tagline;
}

// write Person::set_username here!
bool Person::set_username(string _username){
	int len = _username.length();
	if(len > 0 && len <= 32 && isalpha(_username[0]) && str_isalnum(_username)){
		username = _username;
		return true;
	}
	else {
		return false;
	}
}

bool Person::set_firstname(string _firstname) {
    if (_firstname.length() <= 32 && str_isalpha(_firstname)) {
        firstname = _firstname;
        return true;
    }
    else {
        return false;
    }
}
bool Person::set_lastname(string _lastname) {
    if (_lastname.length() <= 32 && str_isalpha(_lastname)) {
        lastname = _lastname;
        return true;
    }
    else {
        return false;
    }
}
bool Person::set_age(int _age) {
    if (_age >= 0 && _age < 128) {
        age = _age;
        return true;
    }
    else {
        return false;
    }
}
bool Person::set_tagline(string _tagline) {
    if (_tagline.length() <= 256) {
        tagline = _tagline;
        return true;
    }
    else {
        return false;
    }
}

// write Person::set_info here!
// treat as many small modifications
bool Person::set_info(string _username, string _firstname, string _lastname,
                  int _age, string _tagline){
	return set_username(_username) && set_firstname(_firstname) &&
			set_lastname(_lastname) && set_age(_age) && set_tagline(_tagline);
}

// write Person::send_msg here!
void Person::send_msg(Person &recipient, string msg){
	recipient.inbox.push(msg);
}
// write Person::read_msg here!
/* didn't know what to return so returns true if more messages left
 * and false if no more messages */
// insert copy into the community**** o
bool Person::read_msg(){
	if(inbox.size()==0){
		cout << "You have no new messages." << '\n';
	}
	else {
		cout << inbox.front() << '\n';
		inbox.pop(); // remove message
		if(inbox.size()>0){
			return true;
		}
	}
	return false;
}

/* Additional functions used in testing */
string Person::get_msg() {
    if(!inbox.empty()) {
    	string temp = inbox.front();
    	inbox.pop();
    	return temp;//inbox.front();
    } else {
            return "empty";
    }
}

bool Person::constructor_test(string _username,string _firstname,
		string _lastname, int _age, string _tagline){
	Person t1 (_username, _firstname, _lastname, _age, _tagline);
	Person t_null;

	return !(t1.username == t_null.username && t1.firstname == t_null.firstname
			&& t1.lastname == t_null.lastname && t1.age == t_null.age
			&& t1.tagline == t_null.tagline);

}
