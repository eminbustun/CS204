#include <iostream>
#include "SUBook.h"
using namespace std;

int main() {
    User u1("name 1");
    {
        User u2("name 2");
        Post& p1 = u1.createPost("Post 1");
        Post& p2 = u2.createPost("Post 2");
        p1.addComment("Comment 1", &u1);
        p1.addComment("Comment 2", &u1);
        p1.addComment("Comment 3", &u2);
        p2.addComment("Comment 4", &u1);
        p2.addComment("Comment 5", &u2);
        for (int i = 0; i < p1.getComments().size(); i++){
            cout << p1.getComments()[i]->getPost().getContent() << endl;
        }
        for (int i = 0; i < p2.getComments().size(); i++){
            cout << p2.getComments()[i]->getPost().getContent() << endl;
        }
    }
    return 0;
}
