// Bulent Emin Ustun - 27822


#include <iostream>
#include <vector>
#include <string>

using namespace std;


class User{
	friend class Post; 
	friend class Comment;
public:
	User(string NAME);
	~User();
	Post& createPost(string content);
	vector<Post*> getPosts();
	int getNumComments();
	string getName();

private:
	string name;
	int num_comments;
	vector<Post*> posts; // vector of pointers as a container
	vector<Comment*> Comments; // Amro's Hint
	
};


class Post{
	 friend class User;
	 friend class Comment;
public:
	Post(User &NAME, string& cont);
	~Post();
	void addComment(string content, User* commenter);
	vector<Comment*> getComments();
	User& getUser();
	string getContent();


private:
	User& user;
	string content;
	vector<Comment*> comments; 

};


class Comment{
	friend class User;
	friend class Post;
	
public:
	Comment(User *USER,Post &POST,string CONTENT);
	~Comment();
	User& getUser();
	string getContent();
	Post& getPost();

private:
	User* user; // Amro's hint
	string content;
	Post& post;

};
