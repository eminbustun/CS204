// Bulent Emin Ustun - 27822

#include "SUBook.h"
#include <iostream>
#include <string>
#include <vector>

int User::getNumComments(){ // returning number of comments of a user

	return num_comments;

}

string User::getName(){ // returning the name of the user

	return name;

}

User::User(string USER){ // User constructor

	name = USER;
	num_comments = 0;

}

User::~User(){ // User destructor

	for(unsigned int k = 0; k < posts.size(); k++){

		delete posts[k]; // deleting dinamically allocated memory.

	}
	posts.clear(); // clearing the vector

	Comments.clear(); // clearing the vector

}

Post& User::createPost(string cont){ // returning the new post



	Post *pst = new Post(*this, cont); // new post pointer

	posts.push_back(pst);


	return *pst;

}


vector<Post*> User::getPosts(){ // return vector of pointers of posts


	return posts;
}

////////////////////////////////////////////////////////////////////////////////////////////////


Post::Post(User &name, string &cont): user(name), content(cont) {} // Post constructor


Post::~Post(){ // Post destructor


	for(unsigned int k = 0; k < comments.size(); k++){

		delete (comments[k]);

	}
	comments.clear();


	

}


User& Post::getUser(){ // returning to the user who wrote the post

	return user;
}


string Post::getContent(){ // returning the content of the post

	return content;
}


void Post::addComment(string content, User* commenter){ // adding a new comment

	Comment *cmt = new Comment(commenter,*this, content);

	comments.push_back(cmt); // pushing new comment to the comment vector which includes other comments that people made to this post.

	commenter->Comments.push_back(cmt); // User's own comments. There is only their own comments.

}

vector <Comment*> Post::getComments(){ // returning comments


	return comments; 
}

///////////////////////////////////////////////////

Comment::Comment(User *USER, Post &POST, string CONTENT): user(USER) // Comment constructor
	, post(POST), content(CONTENT){
		(user->num_comments)++;  // incrementing number of comments of a user when user makes a comment


}

 
Comment::~Comment(){ // comment destructor.

	if (user != nullptr){
		user->num_comments = user->num_comments - 1; // decrementing comment of a user by one
	}
	if (user->Comments.size() > 0){ // decrementing their own comment by one

		user->Comments.pop_back();
	}
}

User& Comment::getUser(){ // return User

	return *user; 

}

string Comment::getContent(){ //return content

	return content;

}


Post& Comment::getPost(){ // return post

	return post;

}

