#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include<string.h>
#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32
int add=0,d=0,additem=0,bill=0,puritem=0,qtyrcvd[6];
FILE *ptr,*ptr2;
struct {
	char username[20];
	char password[20];
	char phone[10];
}s;

struct addstock{
	char pcode[10];
}code[6];

struct sitems{
	char iCode[10];
	char iName[20];
	int iGst;
	int iHsn;
	int iprice;
	int pprice; // for purchase price
	int astock; //for available qty
}sale[6];
struct employee{
	int emp_id;
	char emp_name[10];
	char emp_desig[20];
	int salary;
}emp[100];


void gotoxy(int x,int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void delay(int x)
{   int i;
	for(i=0;i<=x;i++);
}
void signup()
{   
   
    int i=0;
    char wait[]={'.','.','.','.','.','.','.','.'};
    char ch;
    
    top:
    system("cls");
    
	gotoxy(30,4);
	printf("Signup Zone");
	gotoxy(13,5);
	printf("_________________________________________________\n\n\t\t\t      ");
	
	
	printf("\n\t\tSet Username        :   ");
	
	gets(s.username);
	
	printf("\n\t\tSet Password        :   ");
	
	gets(s.password);
	
	printf("\n\t\tEnter Phone no      :   ");
	
	gets(s.phone);
	
	printf("\n\t\t\tPlease Wait");
    for(i=0;i<8;i++)
    {
    	printf("%c",wait[i]);
    	delay(32002500);
	}
	
	printf("\n\n\t\tPress 'R' to Re-Enter Details\n");
	printf("\n\t\tPress Enter to Confirm.............\n\n");
	
    ptr=fopen("Bhupi2.txt","w");
	fwrite(&s,sizeof(s),1,ptr);
    fclose(ptr);
    
	ch=getch();
	if(ch==114 || ch==82) // Ascii Code of R & r
	{
		goto top;
	}	
	else if(ch==13)
	{
	printf("\t\t\t    Success");
	printf("\n\n\t\t  Press 'H' to go to Home Page");	
	
	ch=getch();
	 if(ch==104 || ch==72)  // Ascii Code of H & h
	 {
	 main();
     }
    }
	 
}

void login()
{
	char waitl[]={'.','.','.','.','.','.','.','.'};
    char username[20],password[20],ch,f;
    int i;
    ptr=fopen("Bhupi2.txt","r");
    fread(&s,sizeof(s),1,ptr);
    top:
    system("cls");
	gotoxy(30,4);
	printf("Login Zone");
	gotoxy(13,5);
	printf("_________________________________________________\n\n\t\t\t      ");
	
	
	printf("\n\t\tEnter Username        :   ");
	
	gets(username);
	
    printf("\n\t\tEnter Password        :   ");
	i=0;
	while(1)
	{
		ch=getch();
		if(ch==ENTER)
		{
			password[i]='\0';
			break;
		}
		else if(ch==BKSP)
		{
			i--;
			printf("\b \b");
		}
		else if(ch==TAB || ch==SPACE)
		{
			continue;
		}
		else
		{
			password[i]=ch;
			i++;
			printf("*");
		}	
	}

    if(strcmp(username,s.username)==0&&strcmp(password,s.password)==0)
    {
    printf("\n\n\t\t\tVerifing Details");
     for(i=0;i<8;i++)
     {
    	printf("%c",waitl[i]);
    	delay(32002500);
	 }
    printf("\n\n\t\t\t\tSuccess");
    delay(59900000);
    welcome();
    }
    
	else if(strcmp(username,s.username)==0 && strcmp(password,s.password)!=0)
    {
	 printf("\n\t\t\tVerifing Details");
     for(i=0;i<8;i++)
     {
    	printf("%c",waitl[i]);
    	delay(32002500);
	 }
	 printf("\n\n\t\t\t  Invalid Password\n");
	 printf("\n\n\t\tPress 'F' if you Forget Password");
	 printf("\n\n\t\tPress 'R' to Re-Enter Details");
	 printf("\n\n\t\tPress 'H' to go to Home Page");
	 f=getch();
	 
	   if(f==114 || f==82) // Ascii Code of R & r
	   goto top;
	   else if(f==104 || f==72) // Ascii Code of H & h
	   main();
	   else if(f==102 || f==70) // Ascii Code of F & f
	   forgot();
    }
    
	else
	{
	 printf("\n\n\t\t\tVerifing Details");
     for(i=0;i<8;i++)
     {
    	printf("%c",waitl[i]);
    	delay(32002500);
	 }
	 printf("\n\n\t\t\t Invalid Credentials\n");
	 printf("\n\n\t\tPress 'R' to Re-Enter Details");
	 printf("\n\n\t\tPress 'H' to go to Home Page");
	 f=getch();
	 
	   if(f==114 || f==82)  // Ascii Code of R & r
	   goto top;            
	   else if(f==104 || f==72) // Ascii Code of H & h
	   main();
    }
	fclose(ptr);
	getch();
}

void forgot()
{
    char username[20],phone[10];
    char waitl[]={'.','.','.','.','.','.','.','.'};
    char d;
    int i;
    ptr=fopen("Bhupi2.txt","r");
    fread(&s,sizeof(s),1,ptr);
    top:
    system("cls");
	gotoxy(30,4);
	printf("Forgot Password");
	gotoxy(13,5);
	printf("_________________________________________________\n\n\t\t\t      ");	
	
	printf("\n\t\tEnter Username        :   ");
	
	gets(username);
	
	printf("\n\t\tEnter Phone no        :   ");
	
	gets(phone);
	
   // Checking details for forgot Password
	if(strcmp(username,s.username)==0&&strcmp(phone,s.phone)==0)
	{   
	    printf("\n\n\t\t\tVerifing Details");
	    for(i=0;i<8;i++)
	       {
		     printf("%c",waitl[i]);
		     delay(32002500);
    	   }
		printf("\n\n\t\t\tYou Password is %s ",s.password);
		printf("\n\n\t\tPress 'L' to go to Login Page ");
		printf("\n\n\t\tPress 'H' to go to Home Page");
		
	
		d=getch();
		
		if(d==108 || d==76) //ascii code of L & l
		login();
	
		else if(d==104||d==72) //ascii code of H & h
		main();
		
	}
	else
	{   
	    printf("\n\n\t\t\tVerifing Details");
	    for(i=0;i<8;i++)
	       {
		     printf("%c",waitl[i]);
		     delay(32002500);
    	   }
	    printf("\n\n\t\t\tInvalid Credentials ");
	    printf("\n\n\t\tPress 'L' to go to Login Page ");
		printf("\n\n\t\tPress 'H' to go to Home Page");
		
	
		d=getch();
		
		if(d==108 || d==76) //ascii code of L & l
		login();
	
		else if(d==104||d==72) //ascii code of H & h
		main();
     }
	fclose(ptr);
}

void main()
     
{   
    int i;

    char wlc[14]={'W',' ','E',' ','L',' ','C',' ','O',' ','M',' ','E'};
    char company[25]={'B','S','B',' ','I','N','D','I','A',' ','P','R','I','V','A','T','E',' '
	               ,'L','I','M','I','T','E','D'};
	char f,username;
	system("cls");
	
	
    
	gotoxy(30,4);
	for(i=0;i<14;i++)
	{
	printf("%c",wlc[i]);
	delay(32002500);
    }
    gotoxy(13,5);
	printf("_________________________________________________\n\t\t\t      ");

	
    printf("\n\t\t\t");
    for(i=0;i<25;i++)
	{
	printf("%c",company[i]);
	delay(10002500);
    }
    
    printf("\n\n\t\t\t   Press F1 For Login");
    printf("\n\n\t\t\t   Press F2 For Signup");
    printf("\n\n\t\t\t   Press F3 For Forgot Password");
    printf("\n\n\t\t\t   Press DEL For Exit");

   getch();
   f=getch();
    if(f==59)
    login();
    
	else if(f==60)
	signup();
	
	else if(f==61)
	forgot();
	
	else if(f==62)
	welcome();
}


//______________________________________________________________________________________________________
void welcome()
{   int i,k,qty,p,sum=0,l;
    char f,icode[10];
    char waitl[]={'.','.','.','.','.','.','.','.'};
	char wel[44]={'W','e','l','c','o','m','e',' ','t','o',' ','t','h','e',' ','D','a','t','a','b','a','s','e',' ',
	'o','f',' ','B','S','B',' ','I','N','D','I','A',' ','P','V','T',' ','L','T','D'};
 	char ch;
 	struct addstock;
 	time_t t;
 	time(&t);
	system("cls");
	ptr=fopen("H:\Mohit\\mohit2.txt","r");
	fread(&s,sizeof(s),1,ptr);
	gotoxy(28,4);
	printf("\t Hi %s",s.username);
    gotoxy(13,5);
	printf("_________________________________________________\n\n\t\t");
	for(i=0;i<44;i++)
	{
	printf("%c",wel[i]);
	delay(10002500);
    }
	printf("\n\n\t\t\t\tSelect Department ");
	printf("\n\n\t\t1. Administration");
	printf("\n\n\t\t2. Sales");
	printf("\n\n\t\t3. Purchase");
	printf("\n\n\t\t4. Inventory P & L");
	
	  gotoxy(13,21);
		printf("_________________________________________________");
		gotoxy(28,23);
    	printf("Press ESC to Logout");

	
	f=getch();
	if(f==49)
	{
	admin();
	}
	else if(f==50)
	{sale:	
	system("cls");

	gotoxy(30,4);
	printf("\t Hi %s",s.username);
    gotoxy(13,5);
	printf("_________________________________________________\n\n\t\t");
	printf("%s",wel);
    printf("\n\n\n\t\t\tPress Serial no to View Details");
	printf("\n\n\t\t1. Sale Items");
	printf("\n\n\t\t2. Generate Invoice");

   gotoxy(13,21);
	printf("_________________________________________________");
    	printf("\n\n\t\t\t   Press Backspace to Go Back.");
    	

	

	ch=getch();
	
	
	if(ch==49)// sale items Page
	{
		
	system("cls");
	
		gotoxy(30,10);
	printf("Loading...\n"); //loading showing on entering sale items page
	gotoxy(33,12);
    for(i=0;i<=100;i++)
	       {
		     printf("%2d",i);
		     delay(11002500);
		     printf("\b\b");
    	   }
	system("cls");

    
    gotoxy(33,4);
    printf("Sale Items");
	
	gotoxy(13,5);
	printf("_________________________________________________\n\n\t\t");
	
	gotoxy(14,7);
	printf("ITEM CODE");
	gotoxy(25,7);
	printf("ITEM NAME");
	gotoxy(41,7);
	printf("GST ");
	gotoxy(46,7);
	printf("HSN CODE");
	gotoxy(56,7);
	printf("S PRICE");
	gotoxy(13,8);
	printf("_________________________________________________\n\n\t\t");
	
	struct sitems;
	strcpy(sale[0].iCode,"BSB001");
	strcpy(sale[0].iName,"LED Cushion");
	sale[0].iGst=18;
	sale[0].iHsn=49430801;
	sale[0].iprice=600;
	
	strcpy(sale[1].iCode,"BSB002");
	strcpy(sale[1].iName,"Normal Cushion");
	sale[1].iGst=18;
	sale[1].iHsn=49430802;
	sale[1].iprice=400;
	
	strcpy(sale[2].iCode,"BSB003");
	strcpy(sale[2].iName,"Magic Mug");
	sale[2].iGst=18;
	sale[2].iHsn=49430803;
	sale[2].iprice=600;
	
	strcpy(sale[3].iCode,"BSB004");
	strcpy(sale[3].iName,"Choco Truffle");
	sale[3].iGst=18;
	sale[3].iHsn=49430804;
	sale[3].iprice=1250;
	
	strcpy(sale[4].iCode,"BSB005");
	strcpy(sale[4].iName,"Ferroro R T-16");
	sale[4].iGst=18;
	sale[4].iHsn=49430805;
	sale[4].iprice=825;
	
	strcpy(sale[5].iCode,"BSB006");
	strcpy(sale[5].iName,"Ferroro R T-24");
	sale[5].iGst=18;
	sale[5].iHsn=49430806;
	sale[5].iprice=1450;
	
	k=10;
	
	for(i=0;i<6;i++)
	{
	gotoxy(14,k);
	printf("%s",sale[i].iCode);
	gotoxy(24,k);
	printf("%s",sale[i].iName);
	gotoxy(41,k);
	printf("%d%%",sale[i].iGst);
	gotoxy(46,k);
	printf("%d",sale[i].iHsn);
	gotoxy(56,k);
	printf("%d",sale[i].iprice);
	k=k+2;
    }
    gotoxy(13,21);
	printf("_________________________________________________");
    	printf("\n\n\t\t\tPress Backspace to Go Back.");
    	
	ch=getch();
	
	if(ch==BKSP)
	{
		goto sale;
	}
    
	}
//______________________________________________________________________________________________________
		else if(ch==50)
		{
			system("cls");
	
				gotoxy(30,10);
			printf("Loading...\n"); //loading showing on entering sale items page
			gotoxy(33,12);
		    for(i=0;i<=100;i++)
			       {
				     printf("%2d",i);
				     delay(11002500);
				     printf("\b\b");
		    	   }
			system("cls");
	
		    gotoxy(33,4);
		    printf("Invoice");
			
			gotoxy(13,5);
			printf("_________________________________________________\n\n\t\t");
			 
	
			
			gotoxy(15,7);
			printf("Enter the no of Items to Sell ");
			scanf("%d",&additem);
			bill++;
			system("cls");
			
			
			gotoxy(33,4);
		    printf("Invoice");
		    gotoxy(50,4);
		    printf("BSB/21-22/%2d",bill);
			gotoxy(13,5);
			printf("_________________________________________________\n\n\t\t");
			gotoxy(13,7);
			printf("ITEM CODE");
			gotoxy(24,7);
			printf("ITEM NAME");
			gotoxy(39,7);
			printf("QTY ");
			gotoxy(43,7);
			printf("AMOUNT");
			gotoxy(51,7);
			printf("TOTAL-AMT");
			gotoxy(13,8);
			printf("_________________________________________________\n\n\t\t");
		// program to find price * qty
		//____________________________________________			
			p=10;
			for(k=0;k<additem;k++)		
			{
			
			gotoxy(13,p);
			scanf("%s",&icode);
			
			
		     for(i=0;i<6;i++)
		     {
		    	if(strcmp(icode,sale[i].iCode)==0)
		    	{	
					gotoxy(24,p);
		    		printf("%s",sale[i].iName);
		    		gotoxy(43,p);
					printf("%d",sale[i].iprice);
		    		break;
				}
			 }
			 
		
		    	gotoxy(39,p);
		    	scanf("%d",&qty);
				gotoxy(52,p);
				printf("%d",sale[i].iprice*qty);
		 		sum=sum+sale[i].iprice*qty;
				p=p+2;
			}
			gotoxy(13,p);
			printf("_________________________________________________\n\n\t\t");
		
		 //________________________________________________
		// calucating tax and total
				p=p+2;
				gotoxy(34,p);
				printf("Amt Before GST =");
				gotoxy(52,p);
				printf("%d",sum);	
				
				p=p+2;
				gotoxy(38,p);
				printf(" GST @ 18%% =");
				gotoxy(52,p);
				printf("%d",sum*18/100);
				
			gotoxy(13,p+1);
			printf("_________________________________________________\n\n\t\t");
				
				p=p+3;
				gotoxy(32,p);
				printf("Total Amt Payble =");
				gotoxy(52,p);
				printf("%d",sum+(sum*18/100));
			
			p=p+1;
			gotoxy(13,p);
			printf("_________________________________________________\n\n\t\t");
			p=p+2;
			gotoxy(19,p);
			printf("This is a Computer Generated Invoice");
			gotoxy(24,p+2);
			printf("%s",ctime(&t));
			gotoxy(20,p+4);
			printf("Thank you for Shopping with us");
			
			gotoxy(13,p+6);
			printf("_________________________________________________");
    		printf("\n\n\t\t\tPress Backspace to Go Back.");
    	
				ch=getch();
	
				if(ch==BKSP)
				{
				goto sale;
				}
			
			
			}
			else if(ch==BKSP)
			{
			welcome();
			}
 	 }
 	 	
 	 //______________________________________________________________
 	 else if(f==51) //purchase department
 	 {
 	 	
		 	 		
			purchase:	
			system("cls");
		
			gotoxy(30,4);
			printf("\t Hi %s",s.username);
		    gotoxy(13,5);
			printf("_________________________________________________\n\n\t\t");
			printf("%s",wel);
		    printf("\n\n\n\t\t\tPress Serial no to View Details");
			printf("\n\n\t\t1. Purchase Items");
			printf("\n\n\t\t2. Purchase Invoice");
			gotoxy(13,21);
			printf("_________________________________________________");
    		printf("\n\n\t\t\tPress Backspace to Go Back.");
		
			ch=getch();
			
			if(ch==49)
			{
					
			 	 	system("cls");
				
					gotoxy(30,10);
				printf("Loading...\n"); //loading showing on entering sale items page
				gotoxy(33,12);
			    for(i=0;i<=100;i++)
				       {
					     printf("%2d",i);
					     delay(11002500);
					     printf("\b\b");
			    	   }
				system("cls");

    
    gotoxy(31,4);
    printf("Purchase Items");
	
	gotoxy(13,5);
	printf("_________________________________________________\n\n\t\t");
	
	gotoxy(14,7);
	printf("ITEM CODE");
	gotoxy(25,7);
	printf("ITEM NAME");
	gotoxy(41,7);
	printf("AVLQTY ");
	gotoxy(49,7);
	printf("GST");
	gotoxy(54,7);
	printf("P PRICE");
	gotoxy(13,8);
	printf("_________________________________________________\n\n\t\t");
	
	struct sitems;
	strcpy(sale[0].iCode,"BSB001");
	strcpy(sale[0].iName,"LED Cushion");
	sale[0].iGst=18;
	sale[0].astock=10;
	sale[0].pprice=350;
	
	strcpy(sale[1].iCode,"BSB002");
	strcpy(sale[1].iName,"Normal Cushion");
	sale[1].iGst=18;
	sale[1].astock=250;
	sale[1].pprice=190;
	
	strcpy(sale[2].iCode,"BSB003");
	strcpy(sale[2].iName,"Magic Mug");
	sale[2].iGst=18;
	sale[2].astock=107;
	sale[2].pprice=450;
	
	strcpy(sale[3].iCode,"BSB004");
	strcpy(sale[3].iName,"Choco Truffle");
	sale[3].iGst=18;
	sale[3].astock=55;
	sale[3].pprice=1050;
	
	strcpy(sale[4].iCode,"BSB005");
	strcpy(sale[4].iName,"Ferroro R T-16");
	sale[4].iGst=18;
	sale[4].astock=19;
	sale[4].pprice=750;
	
	strcpy(sale[5].iCode,"BSB006");
	strcpy(sale[5].iName,"Ferroro R T-24");
	sale[5].iGst=18;
	sale[5].astock=99;
	sale[5].pprice=1000;
	
	k=10;
	l=0;
	for(i=0;i<6;i++)
	{
	gotoxy(14,k);
	printf("%s",sale[i].iCode);
	gotoxy(25,k);
	printf("%s",sale[i].iName);
	
	if(strcmp(code[l].pcode,sale[i].iCode)==0)
	{	gotoxy(43,k);
		printf("%d",sale[i].astock+qtyrcvd[l]);
		l++;
	}
	else
	{	gotoxy(43,k);
		printf("%d",sale[i].astock);
	}
	
	gotoxy(49,k);
	printf("%d%%",sale[i].iGst);
	gotoxy(56,k);
	printf("%d",sale[i].pprice);
	k=k+2;
    }
    gotoxy(13,21);
	printf("_________________________________________________");
    	printf("\n\n\t\t\tPress Backspace to Go Back.");
    	
	ch=getch();
	
	if(ch==BKSP)
	{
		goto purchase;
	}
    
	}
	
	
	
//______________________________________________________________________________________________________
		else if(ch==50)//purchase invoice under purchase
		{
			system("cls");
	
				gotoxy(30,10);
			printf("Loading...\n"); //loading showing on entering purchase invoice page
			gotoxy(33,12);
		    for(i=0;i<=100;i++)
			       {
				     printf("%2d",i);
				     delay(11002500);
				     printf("\b\b");
		    	   }
			system("cls");
	
		    gotoxy(33,4);
		    printf("Purchase Invoice");
			
			gotoxy(13,5);
			printf("_________________________________________________\n\n\t\t");
			 
	
			
			gotoxy(15,7);
			printf("Enter the no of items you have purchased ");
			scanf("%d",&puritem);
			
			system("cls");
			
			
			gotoxy(31,4);
		    printf("Purchase Invoice");
		    
			gotoxy(13,5);
			printf("_________________________________________________\n\n\t\t");
			gotoxy(14,7);
			printf("ITEM CODE");
			gotoxy(25,7);
			printf("ITEM NAME");
			gotoxy(40,7);
			printf("AVLQTY");
			gotoxy(47,7);
			printf("QTYRCVD");
			gotoxy(55,7);
			printf("P PRICE");
			gotoxy(13,8);
			printf("_________________________________________________\n\n\t\t");
		// program to find price * qty
		//____________________________________________			
			p=10;
			for(k=0;k<puritem;k++)		
			{
			
			gotoxy(13,p);
			scanf("%s",code[k].pcode);
			
			
		     for(i=0;i<6;i++)
		     {
		    	if(strcmp(code[k].pcode,sale[i].iCode)==0)
		    	{	
					gotoxy(24,p);
		    		printf("%s",sale[i].iName);
		    		gotoxy(41,p);
		    		printf("%d",sale[i].astock);
		    	//	gotoxy(55,p);
				//	printf("%d",sale[i].pprice);
		    		break;
				}
			 }
			 
		
		    	gotoxy(49,p);
		    	scanf("%d",&qtyrcvd[k]);
				gotoxy(55,p);
				printf("%d",sale[i].pprice*qtyrcvd[k]);
		 		sum=sum+sale[i].pprice*qtyrcvd[k];
				p=p+2;
				
				//sale[i].astock=sale[i].astock+qtyrcvd;
			
			
			}
			gotoxy(13,p);
			printf("_________________________________________________\n\n\t\t");
		
		 //________________________________________________
		// calucating tax and total
				p=p+2;
				gotoxy(37,p);
				printf("Amt Before GST =");
				gotoxy(55,p);
				printf("%d",sum);	
				
				p=p+2;
				gotoxy(41,p);
				printf(" GST @ 18%% =");
				gotoxy(55,p);
				printf("%d",sum*18/100);
				
			gotoxy(13,p+1);
			printf("_________________________________________________\n\n\t\t");
				
				p=p+3;
				gotoxy(37,p);
				printf("Total Amt Due =");
				gotoxy(55,p);
				printf("%d",sum+(sum*18/100));
		
			p=p+1;
			gotoxy(13,p);
			printf("_________________________________________________\n\n\t\t");
			
			printf("\n\t\t\t      Purchase Booked\n");
		
    		printf("\n\n\t\t\tPress Backspace to Go Back.");
    	
				ch=getch();
	
				if(ch==BKSP)
				{
				goto purchase;
				}
			
			
			}
			else if(ch==BKSP)
			{
			welcome();
			}
		
 	 	
 	 	}
 	 	//_____________________________________________________________________________
 	 	else if(f==52) //Inventory (P&L)
 	 	{
 	 			inventory:	
			system("cls");
		
			gotoxy(30,4);
			printf("\t Hi %s",s.username);
		    gotoxy(13,5);
			printf("_________________________________________________\n\n\t\t");
			printf("%s",wel);
		    printf("\n\n\n\t\t\tPress Serial no to View Details");
			printf("\n\n\t\t1. Inventory P & L ");
			printf("\n\n\t\t2. Filter Data");
			gotoxy(13,21);
			printf("_________________________________________________");
    		printf("\n\n\t\t\tPress Backspace to Go Back.");
		
			ch=getch();
 	 		
 	 		if(ch==49)
 	 		{
			 
 	 			system("cls");
				
					gotoxy(30,10);
				printf("Loading...\n"); //loading showing on entering sale items page
				gotoxy(33,12);
			    for(i=0;i<=100;i++)
				       {
					     printf("%2d",i);
					     delay(11002500);
					     printf("\b\b");
			    	   }
				system("cls");

    
			    gotoxy(32,4);
			    printf("Profit & Loss");
				
				gotoxy(13,5);
				printf("_________________________________________________\n\n\t\t");
				
				gotoxy(14,7);
				printf("ITEM CODE");
				gotoxy(25,7);
				printf("ITEM NAME");
				gotoxy(41,7);
				printf("CP");
				gotoxy(46,7);
				printf("SP");
				gotoxy(50,7);
				printf("Profit/Loss");
				gotoxy(13,8);
				printf("_________________________________________________\n\n\t\t");
				
				
				k=10;
				for(i=0;i<6;i++)
				{
				gotoxy(14,k);
				printf("%s",sale[i].iCode);
				gotoxy(25,k);
				printf("%s",sale[i].iName);
				gotoxy(41,k);
				printf("%d",sale[i].pprice);
				gotoxy(46,k);
				printf("%d",sale[i].iprice);
				gotoxy(53,k);
				printf("%d",sale[i].iprice-sale[i].pprice);
				k=k+2;
			    }
					gotoxy(13,21);
					printf("_________________________________________________");
		    		printf("\n\n\t\t\tPress Backspace to Go Back.");
						
						ch=getch();
	
						if(ch==BKSP)
						{
						goto inventory;
						}
				
			}
			
			else if(ch==50)
			{
				system("cls");
				 gotoxy(32,4);
			    printf("Choose Filter");
				
				gotoxy(13,5);
				printf("_________________________________________________\n\n\t\t");
				
			
				gotoxy(29,9);
				printf("Sort by Profit\n");
				gotoxy(29,12);
				printf("1. Low to High\n");
				gotoxy(29,14);
				printf("2. High to Low\n");
			
			
				gotoxy(13,21);
				printf("_________________________________________________\n\n\t\t");	
				
				ch=getch();
				if(ch==49)
				{
					system("cls");
			
						gotoxy(25,10);
					printf("Sorting Data"); //loading showing on entering purchase invoice page
					gotoxy(25,12);
				    for(i=0;i<=10;i++)
					       {
						     printf(".");
						     delay(51002500);
						    
				    	   }
					system("cls");
			
				    gotoxy(20,4);
				    printf("Sorted Successfully - Low to High");
					
					gotoxy(13,5);
					printf("_________________________________________________\n\n\t\t");
						gotoxy(14,7);
						printf("ITEM CODE");
						gotoxy(25,7);
						printf("ITEM NAME");
						gotoxy(41,7);
						printf("CP");
						gotoxy(46,7);
						printf("SP");
						gotoxy(50,7);
						printf("Profit/Loss");
						gotoxy(13,8);
					printf("_________________________________________________\n\n\t\t");
							 
					struct sitems temp;
					for(i=1;i<6;i++)	
					{
						for(k=0;k<6-i;k++)	
						{
							if(sale[k].iprice-sale[k].pprice>sale[k+1].iprice-sale[k+1].pprice)
							{
								temp=sale[k];
								sale[k]=sale[k+1];
								sale[k+1]=temp;
							}
						}
					}
						k=10;
					for(i=0;i<6;i++)
					{
					gotoxy(14,k);
					printf("%s",sale[i].iCode);
					gotoxy(25,k);
					printf("%s",sale[i].iName);
					gotoxy(41,k);
					printf("%d",sale[i].pprice);
					gotoxy(46,k);
					printf("%d",sale[i].iprice);
					gotoxy(53,k);
					printf("%d",sale[i].iprice-sale[i].pprice);
					k=k+2;
			   		}
			   		gotoxy(13,21);
					printf("_________________________________________________");
		    		printf("\n\n\t\t\tPress Backspace to Go Back.");
						
						ch=getch();
	
						if(ch==BKSP)
						{
						goto inventory;
						}
						
					
					
				}
				else if(ch==50)
				{
					system("cls");
			
						gotoxy(25,10);
					printf("Sorting Data"); //loading showing on entering purchase invoice page
					gotoxy(25,12);
				    for(i=0;i<=10;i++)
					       {
						     printf(".");
						     delay(51002500);
						    
				    	   }
					system("cls");
			
				    gotoxy(20,4);
				    printf("Sorted Successfully - High to Low");
					
					gotoxy(13,5);
					printf("_________________________________________________\n\n\t\t");
						gotoxy(14,7);
						printf("ITEM CODE");
						gotoxy(25,7);
						printf("ITEM NAME");
						gotoxy(41,7);
						printf("CP");
						gotoxy(46,7);
						printf("SP");
						gotoxy(50,7);
						printf("Profit/Loss");
						gotoxy(13,8);
					printf("_________________________________________________\n\n\t\t");
							 
					struct sitems temp;
					for(i=1;i<6;i++)	
					{
						for(k=0;k<6-i;k++)	
						{
							if(sale[k].iprice-sale[k].pprice<sale[k+1].iprice-sale[k+1].pprice)
							{
								temp=sale[k];
								sale[k]=sale[k+1];
								sale[k+1]=temp;
							}
						}
					}
						k=10;
					for(i=0;i<6;i++)
					{
					gotoxy(14,k);
					printf("%s",sale[i].iCode);
					gotoxy(25,k);
					printf("%s",sale[i].iName);
					gotoxy(41,k);
					printf("%d",sale[i].pprice);
					gotoxy(46,k);
					printf("%d",sale[i].iprice);
					gotoxy(53,k);
					printf("%d",sale[i].iprice-sale[i].pprice);
					k=k+2;
			   		}
			   		gotoxy(13,21);
					printf("_________________________________________________");
		    		printf("\n\n\t\t\tPress Backspace to Go Back.");
						
						ch=getch();
	
						if(ch==BKSP)
						{
						goto inventory;
						}
						
				}
					
	
			}
				else if(ch==BKSP)
					{
					welcome();
					}	
	   	}
	   	//_____________________________________________________
	   	else if(f==27)//logging out page
	   	{
	   			system("cls");
			
						gotoxy(25,10);
					printf("Logging out"); //loading showing on entering purchase invoice page
					gotoxy(25,12);
				    for(i=0;i<=10;i++)
					       {
						     printf(".");
						     delay(51002500);
						    
				    	   }
					system("cls");
			
					
					gotoxy(13,5);
					printf("_________________________________________________\n\n\t\t");
					
					gotoxy(20,12);
					printf("You have been Logged out Successfully");
					gotoxy(29,14);
					printf("Plz Have a Kit Kat");
					
					gotoxy(13,21);
					printf("_________________________________________________\n\n\t\t");
					getch();
		}
 
	  }

void admin()

{	
	int i,k=10,search=0,remove=0,temp,p;
	char waitl[]={'.','.','.','.','.','.','.','.'};
	char wel[45]={'W','e','l','c','o','m','e',' ','t','o',' ','t','h','e',' ','D','a','t','a','b','a','s','e',' ',
	'o','f',' ','B','S','B',' ','I','N','D','I','A',' ','P','V','T',' ','L','T','D'};
	char ch;
	system("cls");
	//ptr=fopen("H:\Mohit\\mohit2.txt","r");
	//fread(&s,sizeof(s),1,ptr);
	gotoxy(30,4);
	printf("\t Hi %s",s.username);
    gotoxy(13,5);
	printf("_________________________________________________\n\n\t\t");
	printf("%s",wel);
    printf("\n\n\n\t\t\tPress Serial no to View Details");
	printf("\n\n\t\t1. All Employee info");
	printf("\n\n\t\t2. Add Employee");
	printf("\n\n\t\t3. Remove Employee");
	printf("\n\n\t\t4. Search Employee");
	printf("\n\n\t\t5. Sort Data");
	
			gotoxy(13,21);
			printf("_________________________________________________");
    		printf("\n\n\t\t\tPress Backspace to Go Back.");
	
	ch=getch();
//______________________________________________________________________________________________________
	if(ch==50) // Add Employee Page
	{
	
	system("cls");
	
		gotoxy(30,10);
	printf("Loading...\n"); //loading showing on entering Add employee page
	gotoxy(33,12);
    for(i=0;i<=100;i++)
	       {
		     printf("%2d",i);
		     delay(11002500);
		     printf("\b\b");
    	   }
	system("cls");
	
    gotoxy(30,4);
    printf("Add Employee");
	
	gotoxy(13,5);
	printf("_________________________________________________\n\n\t\t");
	gotoxy(15,7);
	printf("Enter the no of Employee you want to Add ");
	scanf("%d",&add);
	
	system("cls");
    gotoxy(30,4);
    printf("Add Employee");
	gotoxy(13,5);
	printf("_________________________________________________\n\n\t\t");
	gotoxy(15,7);
	
	
	gotoxy(13,7);
	printf("EMP ID");
	gotoxy(21,7);
	printf("EMP NAME");
	gotoxy(32,7);
	printf("EMP DESIGNATION");
	gotoxy(52,7);
	printf("EMP SALARY");
	gotoxy(13,8);
	printf("_________________________________________________\n\n\t\t");
	
	struct employee;
	
	// input add employee
    ptr=fopen("addemp.txt","a");
    for(i=3;i<3+add;i++)
    {
	gotoxy(13,k);
	scanf("%d",&emp[i].emp_id);
	gotoxy(21,k);
	scanf("%s",&emp[i].emp_name);
	gotoxy(32,k);
	scanf("%s",&emp[i].emp_desig);
	gotoxy(52,k);
	scanf("%d",&emp[i].salary);
	
	fwrite(&emp[i],sizeof(emp[i]),1,ptr);
	k=k+2;
	}	
	printf("\n\n\t\t\tSaving Information");
	for(i=0;i<8;i++)
	       {
		     printf("%c",waitl[i]);
		     delay(32002500);
    	   }
    	printf("\n\n\t\t\t\tSuccess");
    	printf("\n\n\t\t\tPress Backspace to Go Back.");
    	
	ch=getch();
	
	if(ch==BKSP)
	{
		admin();
	}
   
    fclose(ptr);
	
	}
	
//______________________________________________________________________________________________________	
	else if(ch==49) // All Employee Page
	{ 
		system("cls");
		
		
	gotoxy(30,10);
	printf("Loading...\n"); //loading showing on entering all employee page
	gotoxy(33,12);
    for(i=0;i<=100;i++)
	       {
		     printf("%2d",i);
		     delay(11002500);
		     printf("\b\b");
    	   }
    system("cls");
    
    gotoxy(30,4);
    printf("All Employee info");
	
	gotoxy(13,5);
	printf("_________________________________________________\n\n\t\t");
	
	gotoxy(13,7);
	printf("EMP ID");
	gotoxy(21,7);
	printf("EMP NAME");
	gotoxy(32,7);
	printf("EMP DESIGNATION");
	gotoxy(52,7);
	printf("EMP SALARY");
	gotoxy(13,8);
	printf("_________________________________________________\n\n\t\t");

	struct employee;
/*	printf("%d",emp[2].emp_id);
	emp[0].emp_id=1000;
	strcpy(emp[0].emp_name,"Bhupi");
	strcpy(emp[0].emp_desig,"Managing Director");
	emp[0].salary=150000;
	
	emp[1].emp_id=1002;
	strcpy(emp[1].emp_name,"Sanchita");
	strcpy(emp[1].emp_desig,"CEO");
	emp[1].salary=185000;
	
	emp[2].emp_id=1003;
	strcpy(emp[2].emp_name,"Bhanu");
	strcpy(emp[2].emp_desig,"Managing Director");
	emp[2].salary=160000; 
	
	ptr=fopen("addemp.txt","a");
	
	for(i=0;i<3;i++)
	{
		fwrite(&emp[i],sizeof(emp[i]),1,ptr);
	}
	fclose(ptr);   */
	ptr=fopen("addemp.txt","r"); 

	for(i=0;i<3+add-d;i++)
	{
	fread(&emp[i],sizeof(emp[i]),1,ptr);
	}
	
	fclose(ptr); 
	
	
	k=10;
	
	for(i=0;i<3+add-d;i++)
	{

	gotoxy(13,k);
	printf("%d",emp[i].emp_id);
	gotoxy(21,k);
	printf("%s",emp[i].emp_name);
	gotoxy(32,k);
	printf("%s",emp[i].emp_desig);
	gotoxy(52,k);
	printf("%d",emp[i].salary);
	k=k+2;
    }
    	printf("\n\n\t\t\tPress Backspace to Go Back.");
    	
	ch=getch();
	
	if(ch==BKSP)
	{
		admin();
	}
    
  
	}
//______________________________________________________________________________________________________	
	else if(ch==51) // remove employee page
	{
		system("cls");
	
		gotoxy(30,10);
	printf("Loading...\n"); //loading showing on entering Add employee page
	gotoxy(33,12);
    for(i=0;i<=100;i++)
	       {
		     printf("%2d",i);
		     delay(11002500);
		     printf("\b\b");
    	   }

	system("cls");
	
	gotoxy(13,5);
	printf("_________________________________________________\n\n\t\t");
	gotoxy(13,7);
	printf("EMP ID");
	gotoxy(21,7);
	printf("EMP NAME");
	gotoxy(32,7);
	printf("EMP DESIGNATION");
	gotoxy(52,7);
	printf("EMP SALARY");
	gotoxy(13,8);
	printf("_________________________________________________\n\n\t\t");
	
	
	gotoxy(13,10);
	scanf("%d",&remove);
		
    
	gotoxy(22,10);
	printf("\n\n\t\t\tSearching Information");
	for(i=0;i<8;i++)
	       {
		     printf("%c",waitl[i]);
		     delay(32002500);
    	   }
    // again print all after searching	   
    system("cls");
    gotoxy(30,4);
    printf("Remove Employee");
	
	gotoxy(13,5);
	printf("_________________________________________________\n\n\t\t");
	
	gotoxy(13,7);
	printf("EMP ID");
	gotoxy(21,7);
	printf("EMP NAME");
	gotoxy(32,7);
	printf("EMP DESIGNATION");
	gotoxy(52,7);
	printf("EMP SALARY");
	gotoxy(13,8);
	printf("_________________________________________________\n\n\t\t"); 
  	ptr=fopen("addemp.txt","r");
	
	// reading data from file
	
	
		
	for(i=0;i<3+add;i++)
    {
    	fread(&emp[i],sizeof(emp[i]),1,ptr);
   		
   		if(remove==emp[i].emp_id)
   		   {	
				break;
		   }
    }
    
	
    //printing the search data if found (removing page
	
	
	
	if(remove==emp[i].emp_id)
   		{	
   			gotoxy(13,10);
   			printf("%d",emp[i].emp_id);
   			gotoxy(21,10);
			printf("%s",emp[i].emp_name);
			gotoxy(32,10);
			printf("%s",emp[i].emp_desig);
			gotoxy(52,10);
			printf("%d",emp[i].salary);
		
			printf("\n\n\n\t\t\t\tData Found");
			printf("\n\n\n\t\t    Are you sure to Remove data (y/n)");
			ch=getch();
		     // to remove or not command
		     if(ch==89 || ch==121)
		     {	 d++; // telling all employee to print by -1.
		     	 temp=i;
		    	 for(i=temp;i<3+add-d;i++)
		    	 {
		    	 	emp[i]=emp[i+1];
				 }
		    // displaying data after removing. 	
			system("cls");
			gotoxy(29,10);
			printf("Removing Data\n"); //sorting data showing on entering sort data page
			gotoxy(31,11);
    		for(i=0;i<8;i++)
	        {
		     printf("%c",waitl[i]);
		     delay(52002500);
    	    }
    	    system("cls");
    		
    
    		 gotoxy(22,4);
   			 printf("EMPLOYEE DATA REMOVED SUCCESSFULLY ");
	
			gotoxy(13,5);
			printf("_________________________________________________\n\n\t\t");
			gotoxy(13,7);
			printf("EMP ID");
			gotoxy(21,7);
			printf("EMP NAME");
			gotoxy(32,7);
			printf("EMP DESIGNATION");
			gotoxy(52,7);
			printf("EMP SALARY");
			gotoxy(13,8);
			printf("_________________________________________________\n\n\t\t");
			
			k=10;
			for(i=0;i<3+add-d;i++)
			{

			gotoxy(13,k);
			printf("%d",emp[i].emp_id);
			gotoxy(21,k);
			printf("%s",emp[i].emp_name);
			gotoxy(32,k);
			printf("%s",emp[i].emp_desig);
			gotoxy(52,k);
			printf("%d",emp[i].salary);
			k=k+2;
    		}	
		     	
					    
			}
		
	    }
		else
		{
		gotoxy(13,10);
   		printf("%d",remove);
		printf("\n\n\t\t\t\tData Not Found");
		}
    	
    	printf("\n\n\t\t\tPress Backspace to Go Back.");
    	fclose(ptr);	
		ch=getch();
	
		if(ch==BKSP)
		{
		admin();
		}	
		
		
	}	

//______________________________________________________________________________________________________	
	else if(ch==52)  //search employee page
	{
		system("cls");
		
		
	gotoxy(30,10);
	printf("Loading...\n"); //loading showing on entering search employee page
	gotoxy(33,12);
    for(i=0;i<=100;i++)
	       {
		     printf("%2d",i);
		     delay(11002500);
		     printf("\b\b");
    	   }
    system("cls");
    
    gotoxy(30,4);
    printf("Search Employee");
	
	gotoxy(13,5);
	printf("_________________________________________________\n\n\t\t");
	
	gotoxy(13,7);
	printf("EMP ID");
	gotoxy(21,7);
	printf("EMP NAME");
	gotoxy(32,7);
	printf("EMP DESIGNATION");
	gotoxy(52,7);
	printf("EMP SALARY");
	gotoxy(13,8);
	printf("_________________________________________________\n\n\t\t");
	
	gotoxy(13,10);
	scanf("%d",&search);	
	ptr=fopen("addemp.txt","r");
	gotoxy(22,10);
	printf("\n\n\t\t\tSearching Information");
	for(i=0;i<8;i++)
	       {
		     printf("%c",waitl[i]);
		     delay(32002500);
    	   }
    // again print all after searching	   
    system("cls");
    gotoxy(30,4);
    printf("Search Employee");
	
	gotoxy(13,5);
	printf("_________________________________________________\n\n\t\t");
	
	gotoxy(13,7);
	printf("EMP ID");
	gotoxy(21,7);
	printf("EMP NAME");
	gotoxy(32,7);
	printf("EMP DESIGNATION");
	gotoxy(52,7);
	printf("EMP SALARY");
	gotoxy(13,8);
	printf("_________________________________________________\n\n\t\t");
  
	// finding the location of search in a data
    for(i=0;i<3+add;i++)
    {
    	fread(&emp[i],sizeof(emp[i]),1,ptr);
   		
   		if(search==emp[i].emp_id)
   		   {
				break;
		   }
    }
    
    //printing the search data if found
	if(search==emp[i].emp_id)
   		{	
   			gotoxy(13,10);
   			printf("%d",emp[i].emp_id);
   			gotoxy(21,10);
			printf("%s",emp[i].emp_name);
			gotoxy(32,10);
			printf("%s",emp[i].emp_desig);
			gotoxy(52,10);
			printf("%d",emp[i].salary);
			printf("\n\n\n\t\t\t\tData Found");
		
	    }
	else
	{
	gotoxy(13,10);
   	printf("%d",search);
	printf("\n\n\t\t\t\tData Not Found");
	}
    	
    printf("\n\n\t\t\tPress Backspace to Go Back.");
    fclose(ptr);	
	ch=getch();
	
	if(ch==BKSP)
	{
		admin();
	}	
		
		
	}
	
	//bubble sort data page by emp id
	else if(ch==53) 
	{  
		system("cls");
		
		
	gotoxy(30,10);
	printf("Loading...\n"); //loading showing on entering sort data page
	gotoxy(33,12);
    for(i=0;i<=100;i++)
	       {
		     printf("%2d",i);
		     delay(11002500);
		     printf("\b\b");
    	   }
    system("cls");
    
    gotoxy(30,4);
    printf("SORT DATA");
	
	gotoxy(13,5);
	printf("_________________________________________________\n\n\t\t");
	gotoxy(13,7);
	printf("EMP ID");
	gotoxy(21,7);
	printf("EMP NAME");
	gotoxy(32,7);
	printf("EMP DESIGNATION");
	gotoxy(52,7);
	printf("EMP SALARY");
	gotoxy(13,8);
	printf("_________________________________________________\n\n\t\t");

	ptr=fopen("addemp.txt","r");  
	for(i=0;i<3+add;i++)
	{
	fread(&emp[i],sizeof(emp[i]),1,ptr);
	}
	
	fclose(ptr); 
	
	
	k=10;
	
	for(i=0;i<3+add-d;i++)
	{

	gotoxy(13,k);
	printf("%d",emp[i].emp_id);
	gotoxy(21,k);
	printf("%s",emp[i].emp_name);
	gotoxy(32,k);
	printf("%s",emp[i].emp_desig);
	gotoxy(52,k);
	printf("%d",emp[i].salary);
	k=k+2;
    }	
		printf("\n\n\n\t\t    Are you sure to sort data (y/n)");
		ch=getch();
		
	if(ch==89 || ch==121) //Ascii Code of Y & y 
		{   // sorting condition entering by pressing y
			system("cls");
		
		
			gotoxy(29,10);
			printf("Sorting Data\n"); //sorting data showing on entering sort data page
			gotoxy(31,11);
    		for(i=0;i<8;i++)
	        {
		     printf("%c",waitl[i]);
		     delay(52002500);
    	    }
    	    system("cls");
    		
    
    		 gotoxy(22,4);
   			 printf("EMPLOYEE DATA SORTED SUCCESSFULLY ");
	
			gotoxy(13,5);
			printf("_________________________________________________\n\n\t\t");
			gotoxy(13,7);
			printf("EMP ID");
			gotoxy(21,7);
			printf("EMP NAME");
			gotoxy(32,7);
			printf("EMP DESIGNATION");
			gotoxy(52,7);
			printf("EMP SALARY");
			gotoxy(13,8);
			printf("_________________________________________________\n\n\t\t");
	
		struct employee temp;
			for(i=1;i<3+add-d;i++)	
			{
				for(k=0;k<(3+add-d)-i;k++)	
				{
					if(emp[k].emp_id>emp[k+1].emp_id)
					{
						temp=emp[k];
						emp[k]=emp[k+1];
						emp[k+1]=temp;
					}
				}
			}
			k=10;
			
			for(i=0;i<3+add-d;i++)
			{

			gotoxy(13,k);
			printf("%d",emp[i].emp_id);
			gotoxy(21,k);
			printf("%s",emp[i].emp_name);
			gotoxy(32,k);
			printf("%s",emp[i].emp_desig);
			gotoxy(52,k);
			printf("%d",emp[i].salary);
			k=k+2;
    		}	
				
		}
	else if(ch==78 || ch==110) // Assci code of N & n.
	{
		admin();
	}
    	printf("\n\n\n\t\t       Press Backspace to Go Back.");
    	
	ch=getch();
	
	if(ch==BKSP)
	{
		admin();
	}
	
	}
	else if(ch==BKSP)
	{
		welcome();
	}
 
}

