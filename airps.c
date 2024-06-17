#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int ai1score,ai2score = 0;
struct ai{
	char name[1024];
};
int win(char ainame[1024]){
	printf("%s won!\n",ainame);
	ai1score++;
	ai2score--;
	if(ai2score<=0){
		ai2score=0;
	}
}
int loss(char ainame[1024]){
	printf("%s won!\n",ainame);
	ai2score++;
	ai1score--;
	if(ai1score<=0){
		ai1score=0;
	}
}
int tie(){
	printf("tie!\n");
}
int ai1choice(){
	int choice1 = rand()%3;
	return choice1;
}
//0=r,1=p,2=s
int ai2choice(){
	int choice2 = rand()%3;
	return choice2;
}
int main(){
	system("clear");
	struct ai ai1;struct ai ai2;
	char name1[1024],name2[1024];
	int bestto;
	printf("ai1 name >> ");fgets(name1,1024,stdin);
	name1[strlen(name1)-1]='\0';
	strcpy(ai1.name,name1);
	system("clear");
	printf("ai2 name >> ");fgets(name2,1024,stdin);
	name2[strlen(name2)-1]='\0';
	strcpy(ai2.name,name2);
	system("clear");
	printf("best to [int] >> ");scanf("%d",&bestto);
	while(true){
		srand(time(NULL));
		sleep(1);
		system("clear");
		printf("%s:%d\t%s:%d\n",ai1.name,ai1score,ai2.name,ai2score);
		if(ai2score>=bestto||ai1score>=bestto){
			if(ai2score==bestto){
				printf("%s WON!\n",ai2.name);
			}
			else if(ai1score==bestto){
				printf("%s WON!\n",ai1.name);
			}
			break;
		}
		switch(ai1choice()){
			case(0):
				if(ai2choice()==0){
					tie();
				}
				else if(ai2choice()==1){
					loss(ai2.name);
				}
				else{
					win(ai1.name);
				}
				break;
			case(1):
				if(ai2choice()==0){
					win(ai1.name);
				}
				else if(ai2choice()==1){
					tie();
				}
				else{
					loss(ai2.name);
				}
				break;
			case(2):
				if(ai2choice()==0){
					loss(ai2.name);
				}
				else if(ai2choice()==1){
					win(ai1.name);
				}
				else{
					tie();
				}
				break;
		}
	}
}
