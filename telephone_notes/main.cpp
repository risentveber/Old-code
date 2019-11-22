#include "contact.h"

int main(){
    list<Contact> base;
    vector<list<Contact>::iterator> selection;
    map<string, list<Contact>::iterator> nameSearch;
    map<element, list<Contact>::iterator> phoneSearch;
    string command;
    string name;
    string name_2;
    string e_mail;
    element phone;
    element newPhone;
    cout << "please input command or 'help':" << endl;
    while (command != "exit"){
        cin >> command;//ввод комманды
        if (command == "help"){
            cout << "search <string::name> - print list of contacts with prefix name" << endl;
            cout << "add_with_e-mail <string::name> <number of phone> <string::e-mail> - add new contact" << endl;
            cout << "add <string::name> <number of phone> - add new contact without e-mail" << endl;
            cout << "print <string::name> - print the contact" << endl;
            cout << "print_all - print phone book" << endl;
            cout << "delete <string::name> - delete the contact" << endl;
            cout << "delete_phone <number of phone> - delete the phone" << endl;
            cout << "phone <number of phone> - print name of contact with this number" << endl;
            cout << "replace <last phone> <new phone> - replace phone" << endl;
            cout << "exit - leave the program" << endl;
            continue;
        }
        if (command == "search"){
            cin >> name;
            name_2 = name;
            ++name_2[name_2.length() - 1];
            auto it = nameSearch.lower_bound(name);
            selection.resize(0);
            int i = 0;
            for(; it != nameSearch.end() && name_2 > it->first; ++it){
                cout << ++i << ". " << it->first << endl;
                selection.push_back(it->second);
            }
            if (i == 0)
                cout << "Nothing" << endl;
            continue;
        }
        if (command == "add_with_e-mail" || command == "add"){ //добавление абонента с e-mail или без него
            cin >> name;
            cin >> phone;
            auto it = nameSearch.find(name);
            if (it == nameSearch.end()){
                if (command == "add_with_e-mail"){
                    cin >> e_mail;
                }else{
                    e_mail = "";
                }
                base.push_front(Contact(name, phone, e_mail));
                auto newIt = base.begin();
                phoneSearch[phone] = newIt;
                nameSearch[name] = newIt;
            }else{
                if (command == "add_with_e-mail"){
                    cin >> e_mail;
                    it->second->e_mail = e_mail;
                }
                bool flag = true;//надо ли добавлять телефон
                for(unsigned int i = 0; i < it->second->phones.size(); ++i)
                    if (it->second->phones[i] == phone){
                        flag = false;
                        break;
                    }
                if (flag){
                    it->second->phones.push_back(phone);
                    phoneSearch[phone] = it->second;
                }

            }
            continue;
        }
        if (command == "print_all"){
            for(auto i = nameSearch.begin(); i != nameSearch.end(); ++i){
                cout << i->second->name << endl;
                e_mail = i->second->e_mail;
                if (e_mail != "")
                    cout << '\t' << e_mail << endl;
                for(unsigned int k = 0; k < i->second->phones.size(); ++k)
                    cout << '\t' << k + 1 << ". " << i->second->phones[k] << endl;
            }
            continue;
        }
        if (command == "delete"){
            cin >> name;
            auto it = nameSearch.find(name);
            if(it != nameSearch.end()){
                auto elem = it->second;
                nameSearch.erase(it);
                for(unsigned int i = 0; i < elem->phones.size(); ++i){
                    phoneSearch.erase(elem->phones[i]);
                }
                base.erase(elem);
            }
            continue;
        }
        if (command == "phone"){
            cin >> phone;
            auto it = phoneSearch.find(phone);
            if(it != phoneSearch.end()){
                cout << it->second->name << endl;
            }else{
                cout << "There is no contact with this phone" << endl;
            }
            continue;
        }
        if (command == "print"){
            cin >> name;
            auto it = nameSearch.find(name);
            if(it != nameSearch.end()){
                cout << it->second->name << endl;
                auto elem = it->second;
                if (elem->e_mail != "")
                    cout << '\t' << elem->e_mail << endl;
                for(unsigned k = 0; k < elem->phones.size(); ++k)
                    cout << '\t' << k + 1 << ". " << elem->phones[k] << endl;
            }else{
                cout << "There is no contact with this name" << endl;
            }
            continue;
        }
        if (command == "delete_phone"){
            cin >> phone;
            auto it = phoneSearch.find(phone);
            if(it != phoneSearch.end()){
                auto elem = it->second;
                phoneSearch.erase(it);
                auto i = elem->phones.begin();
                for(; i != elem->phones.end(); ++i){
                    if( *i == phone){
                        elem->phones.erase(i);
                        if(elem->e_mail == "" && elem->phones.size() == 0){
                            nameSearch.erase(elem->name);
                            base.erase(elem);
                        }
                        break;
                    }
                }
            }else{
                cout << "There is no contact with this phone" << endl;
            }
            continue;
        }
        if (command == "replace"){
            cin >> phone;
            cin >> newPhone;
            auto it = phoneSearch.find(phone);
            if(it != phoneSearch.end()){
                auto elem = it->second;
                phoneSearch.erase(it);
                phoneSearch[newPhone] = elem;
                for(unsigned int i = 0; i > elem->phones.size(); ++i)
                    if(phone == elem->phones[i]){ // = was before
                        elem->phones[i] = newPhone;
                        break;
                    }

            }else{
                cout << "There is no contact with this phone" << endl;
            }
            continue;
        }
        cout << "command error" << endl;
        cin.clear();
    }
}
