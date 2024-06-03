
#include<stdio.h>
#include<string.h>
typedef struct player
{
	int jerrcynum;
	char name[20];
	int matches;
	int runs;
	int wickets;
}player;
void storevalue( player*,int);
void displayvalue(player*, int);
void searchjerrcy(player* ,int );
void searchname(player* , int );
void top(player*, int);
void update(player*, int);
void deletep(player*,int);
void main()
{
	 player p1[5];
	storevalue(p1,5);
	int n, i, ch, exit=1;
	do
	{
		printf("............MENU...........\n\n");
		printf(" press 1. to display information of all players\n press 2. to search the player\n");
		printf(" press 3. Top 3 Player\n press 4. Update the player\n");
		printf(" press 5. To Delete the player\n\n");
		printf("*********************************\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
	        displayvalue(p1,5);
	        break;
			case 2:
				do
				{
				printf("............MENU...........\n\n");
	           	printf(" press 1.Search the player by jerrcy no.\n press 2. Search the player by Name\n");
	            printf("*********************************\n\n");
	           	scanf("%d",&ch);
	           	switch(ch)
	           	{
	            case 1:
	            	searchjerrcy(p1,5);
	                  	break;
	            case 2:
	            	searchname(p1,5);
					break;
					default:
					   printf("Enter correct choice");
					   scanf("%d",&ch);		
				}
				printf("\nDo you want to continue press 1\nTo exit press 0\n");
                scanf("%d",&exit);	
	            }while(exit==1);
	                                               
                 	break;
			case 3: 
			    top(p1,5);
	                               	
				break;
			case 4:     
	            update(p1, 5);
				break;
			case 5:
                  deletep(p1,5);	
				break;
		
			default:
				printf("Enter correct choice");	
		}
		printf("\nDo you want to continue press 1\nTo exit press 0\n");
        scanf("%d",&exit);	
	}while(exit==1);
  }
	
void storevalue( player* p1, int n)
{
	p1[0].jerrcynum = 8;
	strcpy(p1[0].name,"Sachin");
	p1[0].matches = 5;
	p1[0].runs = 45;
	p1[0].wickets = 5;
	p1[1].jerrcynum = 18;
	strcpy(p1[1].name,"Virat");
	p1[1].matches = 6;
	p1[1].runs = 35;
	p1[1].wickets=7;
	
	p1[2].jerrcynum = 7;
	strcpy(p1[2].name, "Dhoni");
	p1[2].matches = 6;
	p1[2].runs = 47;
	p1[2].wickets = 6;
	
	p1[3].jerrcynum = 13;
	strcpy(p1[3].name,"Rohit");
	p1[3].matches = 8;
	p1[3].runs = 45;
	p1[3].wickets = 8;
	
	p1[4].jerrcynum = 11;
	strcpy(p1[4].name,"Hardik");
	p1[4].matches = 23;
	p1[4].runs = 56;
	p1[4].wickets = 9;
}
void displayvalue( player* p1, int n)
{
	int i;
	printf("*----------------------------------------------------------------------*\n");
	printf(" JerrcyNo. |  Name          |  Matches    |  Runs      |  Wickets  \n ");
	printf("*-----------------------------------------------------------------------*\n");
	for(i=0; i<n; i++)
	{
		printf("\n %-5d ",p1[i].jerrcynum);
		printf(" %-20s",p1[i].name);
		printf(" %-15d",p1[i].matches);
		printf(" %-14d",p1[i].runs);
		printf(" %-17d",p1[i].wickets);
		
	}
	printf("\n*----------------------------------------------------------------------*");
}
void searchjerrcy(player*p1, int n)
{
	int ch, i, flag=0, no;
	printf("Enter the jerrcy number ");
			scanf("%d",&no);
			for(i=0; i<n; i++)
			{
				if(p1[i].jerrcynum==no)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			printf("\njerrcy no.%d\n Name %s\n Matchs %d\n Runs%d \nWickets%d\n\n",p1[i].jerrcynum,p1[i].name,p1[i].runs,p1[i].wickets);
			else
			printf("search is not found");
}
void searchname(player* p1, int n)
{
	int ch, i, result;
	char name[20];
	 printf("Enter the player name ");
	 fflush(stdin);
		 scanf("%s",&name);
		 for (i=0; i<n; i++)
		 {
			result=strcmp(p1[i].name,name);
			if(result==0){
			
		 	printf("\njerrcy no.%d\n Name %s\n Matchs %d\n Runs%d Wickets%d\n\n",p1[i].jerrcynum,p1[i].name,p1[i].matches,p1[i].runs,p1[i].wickets);
		 	}
		 	
		 }		
	
}

void top(player* p1, int n)
{
	int ch, i, j,exit;
	do{
	
	printf("............MENU...........\n\n");
  	printf(" press 1 Top Player according Runs\n press 2 Top Player according Wickets\n");
  	printf("*********************************\n\n");
   	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
	{

	int temp1;
    for (i = 0; i < n; i++) {
    	for(j=i+1; j<n; j++)
	    {
        if (p1[i].runs>p1[j].runs) {
            temp1=p1[i].runs;
            p1[i].runs=p1[j].runs;
            p1[j].runs=temp1;
        } 
       }
}
	printf("\n Top 3 Player according to Runs:\n");
	for(i=2; i<n; i++){
	
    
    printf("jerrcy no.%d\n Name %s\n Matchs %d\n Runs %d\n Wickets %d\n\n",p1[i].jerrcynum,p1[i].name,p1[i].matches,p1[i].runs,p1[i].wickets);
    
  }
}
    break;
    
    case 2:
 	{
   
	int temp1;
    for (i = 0; i < n; i++) {
    	for(j=i+1; j<n; j++ )
        if (p1[i].wickets>p1[j].wickets) {
            temp1=p1[i].wickets;
            p1[i].wickets=p1[j].wickets;
            p1[j].wickets=temp1;
        } 
    }
    printf("Enter the Top 3 according to Wickets :\n");
    for(i=2; i<n; i++){
     printf("jerrcy no.%d\n Name %s\n Matchs %d\n Runs %d \n Wickets %d\n\n",p1[i].jerrcynum,p1[i].name,p1[i].matches,p1[i].runs,p1[i].wickets);
     }
}
    break;
	default:
	printf("Enter the correct choice:");
	}
	printf("\nDo You Want to Continou Press 1\nTo Exit Press 0\n");
	scanf("%d",&exit);
}
	while(exit==1);
}

void update(player* p1, int n)
{
    int ch,i,exit, runs1, wickets1;
    char name[20];
    do
	{
		printf("............MENU...........\n\n");
	   	printf(" press 1 to update Run of Player\n press 2 to update Wicket of player\n");
	   	printf("*********************************\n\n");
       	scanf("%d",&ch);
	   	switch(ch)
	 	{
       	case 1:
		printf("Enter player name:");
		scanf("%s",&name);
		printf("Enter updated Runs:");
		scanf("%d",&runs1);
	  	   for(i=0;i<n;i++)
					{
						if(strcmp(p1[i].name,name)==0)
						{
						    p1[i].runs=runs1;
						    printf("jerrcy no.%d\n Name %s\n Matchs %d\n Runs%d Wickets%d\n\n",p1[i].jerrcynum,p1[i].name,p1[i].matches,p1[i].runs,p1[i].wickets);
						  
						}
				            }					                               			
	                        break;
	           		case 2:
					printf("Enter player name:");
					scanf("%s",&name);
					printf("Enter updated Wicket:");
					scanf("%d",&wickets1);
					for(i=0;i<n;i++)
					{
						if((strcmp(p1[i].name,name))==0)
						{
						    p1[i].wickets=wickets1;
						  printf("jerrcy no.%d\n Name %s\n Matchs %d\n Runs%d Wickets%d\n\n",p1[i].jerrcynum,p1[i].name,p1[i].matches,p1[i].runs,p1[i].wickets);
						}
				            }
	                 		break;
					default:
				   printf("Enter correct choice");		
				}
				printf("\nDo you want to continue press 1\nTo exit press 0\n");
                scanf("%d",&exit);	
	              }while(exit==1);
	
}
void deletep(player* p1, int n)
{
	int jerrcynum,i;
	printf("Enter Jerrcy number:");
	scanf("%d",&jerrcynum);
       if(p1[i].jerrcynum==jerrcynum)
       {
           printf("\njerrcy no.%d Name %s",p1[i].jerrcynum,p1[i].name);	
   }
    
          for(i=jerrcynum;i<n-1;i++)
           {
             p1[i]=p1[i+1];	
           }
            printf("\nafter delete :\n");
               
	   for(i=0;i<n-1;i++)
                {
                   printf("jerrcy no.%d\n Name %s\n Matchs %d\n Runs%d Wickets%d\n\n",p1[i].jerrcynum,p1[i].name,p1[i].runs,p1[i].wickets);					
                }            	
      
}


