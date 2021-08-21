#include<stdio.h>

int insertdvd();
int deletedvd();
int updatedvd();

int main(void){
    printf("Enter the option number\n 1.Insert a dvd\n 2.Delete a dvd\n 3.Update a dvd\n\n");
    printf("Your option : ");

	int option;
    scanf("%d",&option);

    switch(option){
        case 1 : insertdvd();
        break;
        case 2 : deletedvd();
        break;
        case 3 : updatedvd();
    }
}

struct insertdvd{
    char title[50];
    float price;
    int available;
} s;
int insertdvd() {
	printf("Enter information:-");
	FILE*cfPtr;
	cfPtr = fopen("dvd.txt", "w");
	
    if(cfPtr == NULL){
        printf("Cannot create file\n");
	}
    else{
		int i;
		for(i=0;i<3;++i){
			printf("\n\tEnter movie Title: ");
	    	scanf("%s", &s.title);
	
	    	printf("\tEnter movie Price: ");
	    	scanf("%f", &s.price);
	
	    	printf("\tEnter no of available DVDs: ");
	    	scanf("%d", &s.available);
	
	    	printf("\nDisplaying Information:-");
			printf("\nMovie Title: %s",s.title);
			printf("\nMovie Price: %f",s.price);
			printf("\nNo of available DVDs: %d\n",s.available);
		}
    }
    printf("\nData added successfully\n");
    fclose(cfPtr);
    
    char title[50];
    float price;
    int available;

	printf("\nEnter search DVD title: ");
    scanf("%s", &s.title);
    
	if((cfPtr = fopen("dvd.txt", "r")) == NULL){
		printf("%s DVD is not available\n");
	}
	else{
		printf("%DVD is available\n");
		printf("\n%-10s%-13f%d\n", "Title", "Price", "Available");
		fscanf(cfPtr, "%s%f%ld", &title, price,&available);

		while(!feof(cfPtr)) {
			printf("%-10s%-13f%7.2d\n",&title,price, &available);
			fscanf(cfPtr, "%d%s%lf", &title, price, &available);
	    } 
		fclose(cfPtr);
	}
}

struct deletedvd{
    char title[50];
} t;
int deletedvd(){
    printf("Enter the movie title: ");
    scanf("%s",t.title);
    printf("DVD with title %s was deleted.",t.title);
}

struct updatedvd{
    char title[50];
    float price;
    int available;
} u;
int updatedvd(){
    printf("Enter the movie title: ");
    scanf("%s",u.title);

    printf("Enter movie price: ");
    scanf("%f",&u.price);

    printf("Enter no of available DVDs: ");
    scanf("%d",&u.available);
    
    printf("\nDisplaying Information:");
	printf("\n\tMovie Title: %s",u.title);
	printf("\n\tMovie Price: %f",u.price);
	printf("\n\tNo of available DVDs: %d",u.available);
	printf("\n\nDVD with title %s was updated.",u.title);
}

