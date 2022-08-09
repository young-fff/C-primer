/*
*File : ch13/13.4/Message.h
*Date : 2022-08-09
*Page : 461
*/

#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <new>
#include <set>

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message&, Message&);
public:
    explicit Message(const std::string &str = "") : contents(str) { }
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Floders();
    void addFolder(Folder* f) {folders.insert(f);}
    void deleteFolder(Folder* f) {folders.erase(f);}
};

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
        f -> addMsg(this);
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

void Message::remove_from_Floders()
{
    for (auto f : folders)
        f -> remMsg(this);
}

Message::~Message()
{
    remove_from_Floders();
}

Message& Message::operator=(const Message &rhs)
{
    remove_from_Floders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f : lhs.folders)
        f -> remMsg(&lhs);
    for (auto f : rhs.folders)
        f -> remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (auto f : lhs.folders)
        f -> addMsg(&lhs);
    for (auto f : rhs.folders)
        f -> addMsg(&rhs);
}

class Folder {
public:
    Folder();
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    void addMsg(Message* m) {messages.insert(m);}
    void remMsg(Message* m) {messages.erase(m);}
private:
    std::set<Message*> messages;
};



#endif