#include<iostream>
#include<string>
#include<set>

using std::cout;
using std::endl;
using std::string;
using std::set;

class Folder;
/*
 * the realization of Message
 *
 */
class Message {
    friend class Folder;
    friend void swap(Message&, Message&);
public:
    explicit Message(const string &str = ""): contents(str) { }
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    Message(Message &&);
    Message& operator=(Message &&);

    void save(Folder&);
    void remove(Folder&);
    void print_folders();
    void swap(Message&, Message&);
    void add_folder(Folder&);
    void remove_folder(Folder&);
private:
    string contents;
    set<Folder*> folders;

    void add_to_Folders(const Message&);
    void remove_from_Folders();
    void move_Folders(Message*);
};
/*
 * the realization of Folder
 *
 */
class Folder {
    friend class Message;
public:
    Folder()=default;

    void addMsg(Message*);
    void remMsg(Message*);

    void print_data();
private:
    set<Message*> data;
};

/*
 * The function of Folder
 * P464 practice 13.36
 */
void Folder::addMsg(Message *ms){
    data.insert(ms);
}
void Folder::remMsg(Message *ms){
    data.erase(ms);
}

void Folder::print_data(){
    for(auto i : data)
        cout << i->contents << " ";
}

/*
 * The function of Message
 *
 */
void Message::save(Folder &f){
    folders.insert(&f);
    f.addMsg(this);
}
void Message::remove(Folder &f){
    folders.erase(&f);
    f.remMsg(this);
}
/*
 * 若str1调用add_to_Folders(str2)，只会在str2中每个folders中插入str1
 * 问题在与str1的folders为空。解决方法很简单把str2的folders复制给str1就可以
 * 既是拷贝构造函数实现的功能
 */
void Message::add_to_Folders(const Message &ms){
    for(auto i : ms.folders)
        i->addMsg(this);
}
Message::Message(const Message &ms): contents(ms.contents), folders(ms.folders) {
    add_to_Folders(ms);
}

void Message::remove_from_Folders(){
    for(auto i : folders)
        i->remMsg(this);
}
Message::~Message(){
    remove_from_Folders();
}

Message& Message::operator=(const Message &ms){

    remove_from_Folders();
    contents = ms.contents;
    folders = ms.folders;
    add_to_Folders(*this);

    return *this;
}
void swap(Message &lhs, Message &rhs){
    using std::swap;
    for(auto i : lhs.folders)
        i->remMsg(&lhs);
    for(auto i : rhs.folders)
        i->remMsg(&rhs);
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    for(auto i : lhs.folders)
        i->addMsg(&lhs);
    for(auto i : rhs.folders)
        i->addMsg(&rhs);
}
/*
 * p464 practice 13.37
 *
 */
void Message::add_folder(Folder &fl){
    folders.insert(&fl);
    fl.data.insert(this);
}
void Message::remove_folder(Folder &fl){
    folders.erase(&fl);
    fl.data.erase(this);
}
void Message::print_folders(){
    for(const auto i : folders){
        for(const auto m : i->data){
            cout << m->contents << " ";
        }
        cout << endl;
    }
}
/*
 * mobile structure
 *
 */
 void Message::move_Folders(Message *m){
    folders = std::move(m->folders);
    for(auto f : folders){
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
 }
 Message::Message(Message &&m): contents(std::move(m.contents)){
    move_Folders(&m);
 }
 Message& Message::operator=(Message &&rhs){
    if(this!=&rhs){
        remove_from_Folders();
        contents = rhs.contents;
        move_Folders(&rhs);
    }
    return *this;
 }
