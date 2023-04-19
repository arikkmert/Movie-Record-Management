#include <stdio.h>
#include <stdlib.h>


struct Movie {
    int movieId;
    char *movieName;
    char *movieDirector;
    char *movieCategory;
    double movieIMDBrate;
    struct Movie *next;
    struct Movie *previous;
}* head,tail;

int compare (struct Movie *one , struct Movie *two)
{
return strcmp(one->movieName, two->movieName);
}

void add(struct Movie **pp,int id ,char *movieName, char *movieDirector,char *movieCategory, double movieIMDBrate, int (*cmp)(struct Movie *l, struct Movie *r)) {

    struct Movie *new;
    new = malloc(sizeof(*new));
    new->movieId = id;
    new->movieName = movieName;
    new->movieDirector = movieDirector;
    new->movieCategory= movieCategory;
    new->movieIMDBrate = movieIMDBrate;
	if(head==NULL){
        
        head = new;
    }
    
    for ( ; *pp != NULL; pp = &(*pp)->next) {
        if (cmp(*pp, new) > 0 ) break;
        }

    new->next = *pp;
    *pp = new;
}

void display() {
   struct Movie *ptr = head;

        printf("\n[head] =>");
        while(ptr != NULL) {        
        printf("Movie ID: %d\n", ptr->movieId);
        printf("Movie Name: %s\n", ptr->movieName);
        printf("Movie Director: %s\n", ptr->movieDirector);
        printf("Movie Category: %s\n", ptr->movieCategory);
        printf("Movie IMDB rate: %d\n\n", ptr->movieIMDBrate);
        ptr = ptr->next;
   }

   printf(" [null]\n");
}

void Delete(char* movieName)
{
    struct Movie * temp1 = head;
    struct Movie * temp2 = head; 
    while(temp1!=NULL){
        
        if(strcmp(temp1->movieName,movieName) == 0 ){
            
            
            if(temp1==temp2){
                head = head->next;
                free(temp1);
            }
            else{
                temp2->next = temp1->next;
                free(temp1); 
            }
            
            printf("Record Successfully Deleted !\n");
            return;
            
        }
        temp2 = temp1;
        temp1 = temp1->next;
        
    }
    
}
		static void add(int id) {

        		printf("Enter movie name: ");
                scanf("%s", &movieName);
                printf("Enter movie director: ");
                scanf("%s", &movieDirector);
                printf("Enter movie category: ");
                scanf("%s", &movieCategory);
                printf("Enter movie IMDB rate: ");
                scanf("%ld", &movieIMDBrate);

        Node newNode = new Node(id, movieName, movieDirectory, movieCategory, movieIMDBrate);

        if (head == null) {
            head = newNode;
            tail = newNode;
            System.out.println();
            System.out.println("First movie is added!");
            return;
        } else {
            if (movieName.equalsIgnoreCase(head.movieName)) {
                System.out.println("This movie is already recorded!");
                head = head.next;
                return;
            } else {
                tail.next = newNode;
                tail = newNode;
            }

        }

        Node current = head,
                temp2 = null;

        String name;
        String directory;
        String category;
        double ýmdb;

        if (head == null) {
            return;
        } else {
            while (current != null) {

                temp2 = current.next;
                int compare = current.movieName.compareTo(movieName);

                while (temp2 != null) {
                    if (compare > 0) {
                        name = current.movieName;
                        directory = current.movieDirector;
                        category = current.movieCategory;
                        ýmdb = current.movieIMDBrate;

                        current.movieName = temp2.movieName;
                        current.movieDirector = temp2.movieDirector;
                        current.movieCategory = temp2.movieCategory;
                        current.movieIMDBrate = temp2.movieIMDBrate;

                        temp2.movieName = name;
                        temp2.movieDirector = directory;
                        temp2.movieCategory = category;
                        temp2.movieIMDBrate = ýmdb;
                    }

                    temp2 = temp2.next;
                }
                current = current.next;
            }
            System.out.println("Movie is added!");
        }
    }

int main() {
	
	head = NULL;
	int choice;
    int movieID=0;
    char movieName[100];
    char movieDirector[100];
    char movieCategory[100];
    double movieIMDBrate;
    
        printf("0 to quit\n1 to insert movie details\n2 to delete movie\n3 to display movies details");
        
        
        do{
        	printf("\nEnter Choice: ");
            scanf("%d", &choice);
        	switch (choice){
        		
            case 1:
                printf("Enter movie name: ");
                scanf("%s", &movieName);
                printf("Enter movie director: ");
                scanf("%s", &movieDirector);
                printf("Enter movie category: ");
                scanf("%s", &movieCategory);
                printf("Enter movie IMDB rate: ");
                scanf("%ld", &movieIMDBrate);
                struct Movie *root = NULL;
               // insert(movieID, movieName, movieDirector, movieCategory, movieIMDBrate);
	
				add(&root, movieID, movieName, movieDirector, movieCategory, movieIMDBrate, compare);
                movieID++;
                break;
            
            case 2:
            	printf("Enter movie name to delete: ");
                scanf("%s", &movieName);
                Delete(movieName);
                break;
            case 3:
            	display();
            	break;
                
        }
		}
   while(choice != 0);
    
}


