#include <stdio.h>
#include <string.h>

#define CONSOLE_INPUT_STRING_SIZE 1000
#define USERS_INITIAL_CAPACITY 2

/*
PROGRAM
0 load config file
    0.1 validate config file
        0.1.1 if file not found load defoult configuration
        0.1.2 if not valid display msg and exit program
    0.2 load data from config file into app (struct wiil be used)
1 stat server
    1.1 insert port
    1.2 start server
Constraints
CONSOLE_INPUT_STRING_SIZE console input string size no biger than 1000
*/

// start model
struct user {
    char *userName;
    char *password;
};

struct user *createUser(char *name, char *password) {
    struct user *u = malloc(sizeof(struct user));

    u->userName = malloc(strlen(name)+1);
    strcpy(u->userName, name);

    u->password = malloc(strlen(password)+1);
    strcpy(u->password, name);

    return u;
}

/*
one instance can exist in app
instance is created in main metod (init part)
used to save list of users form cong file
*/
struct userList {
    int size;
    int index;
    int capacity;
    struct user* usersList;
};
struct userList *users;
// https://medium.com/@imjacobclark/working-with-dynamic-arrays-in-c-c7d40a3cea01
void addUserToUserList(struct userList *users, struct user user) {
    if(users->size > users->size){
          realloc(users->usersList, sizeof(users->usersList) * 2);
          users->capacity = sizeof(users->usersList) * 2;
     }

    users->usersList[users->index] = user;
    users->index += 1;
    users->size = users->size + 1;
}

// end model


void loadConfFIle();

void startServer();

int main( int argc, const char* argv[])
{
    // start program init
    users = malloc(sizeof(struct userList));
    users->size=0;
    users->index=0;
    users->capacity = USERS_INITIAL_CAPACITY;
    users->usersList = malloc(USERS_INITIAL_CAPACITY * sizeof(struct user));
    //end program init	

    printf("File Server\n");
    printf("0 Load conf file\n");
    printf("1 Start server\n");

    int chose = -1;
    scanf("%d", &chose);
    if(chose == 0) {
        loadConfFIle();
    }
    if(chose == 1) {

    }
	return 0;
}

void loadConfFIle() {
    printf("Selected: 0 Load cong file\n");
    printf("Inser full file path: Ex: home/x/file.config\n");
    char path[CONSOLE_INPUT_STRING_SIZE];
    scanf("%s", &path);


    FILE *file;
    file=fopen(path, "r");

    if(file == NULL) {
        printf("File not foud. Loaded defoult configuration.\n");
        struct user *u = createUser("rwar1", "dada"); //TODO DEFAULT PARAMS
        addUserToUserList(users, (*u)); //PS: acces users->usersList[0].userName
        return;
    }

     while(!feof(file)) {
        struct user *n= (struct user*)malloc(sizeof(struct user));
        fscanf(file,"%s %s", n->userName, n->password); //TODO file format?

         addUserToUserList(users, (*n));
    }
    //TODO TEST



}

void startServer() {

}
