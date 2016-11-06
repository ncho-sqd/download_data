#ifndef COMMUNITY_H
#define COMMUNITY_H

#include <string>
#include <list>
#include <map>
#include "person.h"

using namespace std;

// pairs are stl types that contain two inner objects (of the specified template
// types). The two inner objects can be accessed as .first and .second on the
// pair object: 
//   myContact.first gives the inner string object, and
//   myContact.second gives the inner Person object.
// this typedef is to make your life easier when using this particular type
typedef pair<string,Person> contact;

class Community {

  private:

    // the name of the community
    string name;
    // the collection of people within this community
    map<string,Person> people;

  public:

    // constructors
    Community();
    Community(string _name, map<string,Person> _people);

    string get_name();
    bool set_name(string _name);

    // add an instance of Person, _person, to the collection of people
    bool add_person(Person _person);

    // return all usernames of members as a list
    list<string> get_all_usernames();
    // print all usernames to the console
    void print_all_usernames();

    // find users with a certain first name
    list<Person> find_member(string firstname);

    // return the person object for a given username
    Person get_member(string username);
    
    // send msg to the Person objects, addressed by their usernames
    bool send_msg(list<string> usernames, string msg);
    
    /* functions for function testing */
    string parse_list(list<string> list);
    string parse_person_list(list<Person> person_list);
    bool constructor_test(string _name, map<string,Person> _people);
};

#endif /* COMMUNITY_H */

