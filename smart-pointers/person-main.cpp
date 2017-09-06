// Note, specific namespace members are imported into the global namespace which is
// better practice than importing all of the members
// eg: "using std::string;", "using std::unique_ptr;" etc. rather than "using namespace std;"

#include <memory> // required for smart pointers
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

#include <string>
#include <iostream>
using std::string;
using std::endl;
using std::cout;

#include "Person.h"

//1
// person_ptr is out of scope
// person_ptr_in_main is out of scope



//2
// a 
// b 
// c 
// d 
// e 
// f



//3
// a 2
// b 2
// c 2
// d 2
// e 1
// f 1

//4
// Thabo in main because the last instance of it where as the last instance of sandile_ptr
// is in the last line

Person printName()
{
	Person thabo{"Thabo",12};
	cout << thabo.name() << endl;
	return thabo;
}

shared_ptr<Person> printName2()
{
	auto maryanne_ptr = make_shared<Person>("Maryanne",12);
	cout << maryanne_ptr->name() << endl;
	return maryanne_ptr;
}

void printName3(shared_ptr<Person> person_ptr)
{
	cout << person_ptr->name() << endl;
	return;
}


int main()
{
    auto sandile_ptr = make_unique<Person>("Sandile",15);    

    auto thabo_in_main = printName();
    cout << thabo_in_main.name() << endl; //thabo released here

    auto person_ptr_in_main = printName2(); 
    printName3(person_ptr_in_main); //person pointer released here

    sandile_ptr = make_unique<Person>("Sandile2",11);  
    cout << sandile_ptr->age() << endl;//sandile released here

    return 0;
}


