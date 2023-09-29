#include "header.h"
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Publisher publ("Ï¸òð", "Ïåòðîâ", "Ïåòðîâè÷", 24);
	Transaction<Author> author;
	SmartPointer<Book> book1 = new Book("ðåöåïòû ìèðà","êóëèíàðèÿ","ïåðâûé ðåöåïò ÿè÷íèöû");
	author->set_emp("Èâàí", "Èâàíîâ", "Èâàíîâè÷", 23);
	author->set_book(book1);
	author->set_books(book1);
	author->set_cont(author->Get_book()->Get_content());
	publ.publicate(book1);
	author.showState(State::begin);//íå îáÿçàòåëüíî
	author.beginTransactions("ÍÅÒ ÐÅÖÅÏÒÀÌ");
	author.showState(State::middle);
	author.deleteTransactions();
	author.commit();
	author.showState(State::begin);
	author.beginTransactions("Ðåöåïòàì áûòü");
	author.showState(State::middle);
	author.commit();
	author->Get_book().~SmartPointer();
	cout<<book1->Get_content()<<endl;
	publ.publicate(book1);
	
	return 0;
}
