/*VERY ADVANCED TIC TAC TOE :COMPUTER PLAYS WITH PLAYER WITH FOLLOWING PRIORITIES
(1) IT WINS IF POSSIBLE IN VERY HIS NEXT MOVE
(2) OTHERWISE IT DOESN'T ALLOW THE USER TO WIN IF POSSIBLE IN HIS (COMPUTER'S)
    VERY NEXT MOVE.
(3) OTHERWISE IT PLAYS SUCH THAT COMPUTER CAN MAKE LINE THRU ITS NEXT MOVE
    WITH LEAST CHANCE OF USER MAKING LINE IN FOLLOWING A SPECIFIC ORDER
    (OF USER MAKING LINE) WHICH IS NEW FOR EVERY GAME AS IT IS SET RANDOMLY
    IN AN ARRAY NAMED RAND.
(4) OTHERWISE IT PLAYS RANDOMLY.
*/
#include<conio.h>
#include<iostream.h>
#include<stdio.h>
//#include"graphics.cpp"
#include<stdlib.h>
#include<time.h>

int checkforwin(char a[][3]);
void decidemove1(char a[3][3],char b[3][3],int m[],char ch);
void decidemove2(char a[3][3],char b[3][3],int m[],char ch);
void decidemove3(char a[3][3],char b[3][3],int m[],int rand[]);
void copy(char a[3][3],char a2[3][3]);
int countplsucc(char a2[3][3]);
void startinggraphic();

void main()
{
 char a[3][3],b[3][3],move,ch='X',ans;
 int i,j,k,player=1,wins=0,m[3],r,c,rand[8],flag,t,pscore=0,cscore=0;
 startinggraphic();

 clrscr();
 cout<<"Enter your name (Your sign is X) : ";
 char playername[80];
 scanf(" %[^\n]",playername);

 again:
 randomize();
 //set move preferences  in rand array
 rand[0]=random(8)+1;
 for(i=1;i<8;i++)
  {
   flag=0;
   t=random(8)+1;

   for(j=0;j<i;j++)
    {
     if(t==rand[j]) {
		 flag=1;
		 break;
		 }
     else continue ;
     }

    if(flag==0)
	  {
	   rand[i]=t;
	  }
    else {
	  i--;
	  }
   }

 //for(i=0;i<8;i++) cout<<rand[i]; getch();
 for(i=0;i<3;i++)
  for(j=0;j<3;j++)
   {
    a[i][j]=' ';
    b[i][j]='e';   //empty
   }

 clrscr();

  cout<<"Amit  :  "<<cscore<<"         "<<playername<<" :  "<<pscore<<endl; //cout<<"Game Code : "; for(i=0;i<8;i++) cout<<rand[i]; cout<<endl;
  //hline();
 cout<<"T I C \nT A C\nT O E\n";

 for(k=0;k<9;k++)
  {
   error:
   //INPUT (GET MOVE)
   if(player==1)
   {
    cout<<endl<<playername<<" :";
    move=getche();
    switch(move)
    {
     case '7':
      if(b[0][0]=='e') { a[0][0]=ch; b[0][0]='f'; break; }
      else { cout<<endl<<"ERROR!!\n"; goto error; }
     case '8':
      if(b[0][1]=='e') { a[0][1]=ch; b[0][1]='f'; break; }
      else { cout<<endl<<"ERROR!!\n"; goto error; }
     case '9':
      if(b[0][2]=='e') { a[0][2]=ch; b[0][2]='f'; break; }
      else { cout<<endl<<"ERROR!!\n"; goto error; }
     case '4':
      if(b[1][0]=='e') { a[1][0]=ch; b[1][0]='f'; break; }
      else { cout<<endl<<"ERROR!!\n"; goto error; }
     case '5':
      if(b[1][1]=='e') { a[1][1]=ch; b[1][1]='f'; break; }
      else { cout<<endl<<"ERROR!!\n"; goto error; }
     case '6':
      if(b[1][2]=='e') { a[1][2]=ch; b[1][2]='f'; break; }
      else { cout<<endl<<"ERROR!!\n"; goto error; }
     case '1':
      if(b[2][0]=='e') { a[2][0]=ch; b[2][0]='f'; break; }
      else { cout<<endl<<"ERROR!!\n"; goto error; }
     case '2':
      if(b[2][1]=='e') { a[2][1]=ch; b[2][1]='f'; break; }
      else { cout<<endl<<"ERROR!!\n"; goto error; }
     case '3':
      if(b[2][2]=='e') { a[2][2]=ch; b[2][2]='f'; break; }
      else { cout<<endl<<"ERROR!!\n"; goto error; }
     default :
      cout<<endl<<"ERROR!!\n";
      goto error;
    }
    player=2;
   }

  else
  {
    cout<<"\nAmit:\n";
    decidemove1(a,b,m,'O');
    if(m[2]!=1) decidemove2(a,b,m,'X');
    if(m[2]!=1) decidemove3(a,b,m,rand);
    if(m[2]==1)
     {
       cout<<"\nm[0]="<<m[0]<<" m[1]="<<m[1];
       r=m[0]; c=m[1];
       a[r][c]='O';
     }
    else
     {
     aa:
      r=random(3);
      c=random(3);
      cout<<"\nr="<<r<<" c="<<c;
      if(b[r][c]=='e')
       a[r][c]='O';
      else goto aa;
     }
    b[r][c]='f';
    player=1;
  }

  //SHOW GAME STATUS
  clrscr();
  cout<<"Amit  :  "<<cscore<<"         "<<playername<<" :  "<<pscore<<endl; //cout<<"Game Code : "; for(i=0;i<8;i++) cout<<rand[i]; cout<<endl;

  //hline();
  //cout<<endl;
  for(i=0;i<3;i++)
     {
      for(j=0;j<3;j++)
       {if(a[i][j]=='X') textcolor(LIGHTRED);
	else textcolor(LIGHTGREEN);
	putch(a[i][j]);
	textcolor(WHITE);  putch(' ');
       }
	cout<<endl;
     }

  wins=checkforwin(a);
  if(wins)
   {
    if(player==1)
    { cout<<endl<<"Amit  WINS !!!"; player=2; cscore++;
      if(cscore==10)
       {
	  clrscr();
	  cout<<"\n\n\n\n\n\n\n\n\n     	     T O U R N A M E N T     W I N N E R\n\n                           AMIT ";
	  getch();    goto end;
       }
    }
    else if(player==2)
    { cout<<endl<<playername<<"  WINS !!!"; player=1;  pscore++;
    if(pscore==10)
       {
	  clrscr();
	  cout<<"\n\n\n\n\n\n\n\n\n 	             T O U R N A M E N T     W I N N E R\n\n                             "<<playername;
	  getch();    goto end;
       }
    }
    break;
   }
 }
 cout<<"\n\nPress e to exit or any other key to continue...";
ans=getch();
if(ans=='e'||ans=='E') goto end;  else goto again;
end:
//cbab();
;
}
//main ends

int checkforwin(char a[][3])
{
 if(  ( (a[0][0]!=' '&&a[0][1]!=' '&&a[0][2]!=' ')
	&&(a[0][0]==a[0][1])&&(a[0][1]==a[0][2]) ) ||
      ( (a[1][0]!=' '&&a[1][1]!=' '&&a[1][2]!=' ')
	&&(a[1][0]==a[1][1])&&(a[1][1]==a[1][2]) ) ||
      ( (a[2][0]!=' '&&a[2][1]!=' '&&a[2][2]!=' ')
	&&(a[2][0]==a[2][1])&&(a[2][1]==a[2][2]) ) ||
      ( (a[0][0]!=' '&&a[1][0]!=' '&&a[2][0]!=' ')
	&&(a[0][0]==a[1][0])&&(a[1][0]==a[2][0]) ) ||
      ( (a[0][1]!=' '&&a[1][1]!=' '&&a[2][1]!=' ')
	&&(a[0][1]==a[1][1])&&(a[1][1]==a[2][1]) ) ||
      ( (a[0][2]!=' '&&a[1][2]!=' '&&a[2][2]!=' ')
	&&(a[0][2]==a[1][2])&&(a[1][2]==a[2][2]) ) ||
      ( (a[0][0]!=' '&&a[1][1]!=' '&&a[2][2]!=' ')
	&&(a[0][0]==a[1][1])&&(a[1][1]==a[2][2]) ) ||
      ( (a[0][2]!=' '&&a[1][1]!=' '&&a[2][0]!=' ')
	&&(a[0][2]==a[1][1])&&(a[1][1]==a[2][0]) )
   )
  return 1;
 else return 0;
}

void decidemove1(char a[3][3],char b[3][3],int m[],char ch)
{
 int r,c;
 m[2]=0;

 if( (a[0][0]==ch&&a[0][1]==ch)||(a[0][0]==ch&&a[0][2]==ch)||(a[0][1]==ch&&a[0][2]==ch) )
    {
      cout<<"\n1";
      r=0;
      if(b[0][0]=='e') { c=0; m[2]=1;  goto decided;}
      else if(b[0][1]=='e') { c=1; m[2]=1;  goto decided;}
      else if(b[0][2]=='e') { c=2; m[2]=1;  goto decided;}
    }
  if( (a[1][0]==ch&&a[1][1]==ch)||(a[1][0]==ch&&a[1][2]==ch)||(a[1][1]==ch&&a[1][2]==ch) )
    {
       cout<<"\n2";
      r=1;
      if(b[1][0]=='e') { c=0; m[2]=1;  goto decided;}
      else if(b[1][1]=='e') { c=1; m[2]=1;  goto decided;}
      else if(b[1][2]=='e') { c=2; m[2]=1;  goto decided;}
    }
  if( (a[2][0]==ch&&a[2][1]==ch)||(a[2][0]==ch&&a[2][2]==ch)||(a[2][1]==ch&&a[2][2]==ch) )
    {
       cout<<"\n3";
      r=2;
      if(b[2][0]=='e') { c=0; m[2]=1;  goto decided;}
      else if(b[2][1]=='e') { c=1; m[2]=1;  goto decided;}
      else if(b[2][2]=='e') { c=2; m[2]=1;  goto decided;}
    }
  if( (a[0][0]==ch&&a[1][0]==ch)||(a[0][0]==ch&&a[2][0]==ch)||(a[1][0]==ch&&a[2][0]==ch) )
    {
       cout<<"\n4";
      c=0;
      if(b[0][0]=='e') { r=0; m[2]=1;  goto decided;}
      else if(b[1][0]=='e') { r=1; m[2]=1;  goto decided;}
      else if(b[2][0]=='e') { r=2; m[2]=1;  goto decided;}
    }
  if( (a[0][1]==ch&&a[1][1]==ch)||(a[0][1]==ch&&a[2][1]==ch)||(a[1][1]==ch&&a[2][1]==ch) )
    {
       cout<<"\n5";
      c=1;
      if(b[0][1]=='e') { r=0; m[2]=1;  goto decided;}
      else if(b[1][1]=='e') { r=1; m[2]=1;  goto decided;}
      else if(b[2][1]=='e') { r=2; m[2]=1;  goto decided;}
    }
  if( (a[0][2]==ch&&a[1][2]==ch)||(a[0][2]==ch&&a[2][2]==ch)||(a[1][2]==ch&&a[2][2]==ch) )
    {
       cout<<"\n6";
      c=2;
      if(b[0][2]=='e') { r=0; m[2]=1;  goto decided;}
      else if(b[1][2]=='e') { r=1; m[2]=1;  goto decided;}
      else if(b[2][2]=='e') { r=2; m[2]=1;  goto decided;}
    }

  if( a[0][0]==ch&&a[1][1]==ch)
    { if(b[2][2]=='e') {r=2;c=2;m[2]=1;goto decided;}}

  if( a[0][0]==ch&&a[2][2]==ch)
    { if(b[1][1]=='e') {r=1;c=1;m[2]=1;goto decided;}}

  if( a[1][1]==ch&&a[2][2]==ch)
    { if(b[0][0]=='e') {r=0;c=0;m[2]=1;goto decided;}}

  if( a[0][2]==ch&&a[1][1]==ch)
    { if(b[2][0]=='e') {r=2;c=0;m[2]=1;goto decided;}}

  if( a[0][2]==ch&&a[2][0]==ch)
    { if(b[1][1]=='e') {r=1;c=1;m[2]=1;goto decided;}}

  if( a[1][1]==ch&&a[2][0]==ch)
    { if(b[0][2]=='e') {r=0;c=2;m[2]=1;goto decided;}}

  m[2]=0;

 decided:
  m[0]=r;
  m[1]=c;
 return ;
}

void decidemove2(char a[3][3],char b[3][3],int m[],char ch)
{
 decidemove1(a,b,m,ch);
 return;
}

void decidemove3(char a[3][3],char b[3][3],int m[],int rand[])
{
  char a2[3][3];
  int i,j,r,c,p=0,t1=8,t2=8,t3=8,k=0;
  m[2]=0;

  if(b[1][1]=='e') { r=1; c=1; m[2]=1; goto decided; }

  cout<<"\ndm3\n";
  for(i=0;i<3;i++)
   for(j=0;j<3;j++)
    {
     a2[i][j]=a[i][j];
    }
 do
 {
 switch(rand[k])
 {
  case 1:
  p=0;
  for(i=0;i<3;i++)
   {
    if(a[0][i]==' '||a[0][i]=='O') p++;
    else break;
   }
   if(p==3)
    {
     cout<<"dm3 1";
     r=0;
     if(b[0][0]=='e')
     { a2[0][0]='O';  t1=countplsucc(a2); copy(a,a2); }
     if(b[0][1]=='e')
     { a2[0][1]='O';  t2=countplsucc(a2); copy(a,a2);}
     if(b[0][2]=='e')
     { a2[0][2]='O';  t3=countplsucc(a2); copy(a,a2);}

     if(t1<=t2&&t1<=t3) { c=0; m[2]=1; goto decided; }
     else if(t2<=t1&&t2<=t3) { c=1; m[2]=1; goto decided; }
     else { c=2; m[2]=1; goto decided; }
    }
  break;
  case 2:
  p=0;
  for(i=0;i<3;i++)
   {
    if(a[1][i]==' '||a[1][i]=='O') p++;
    else break;
   }
   if(p==3)
    {
      cout<<"dm3 2";
     r=1;
     if(b[1][0]=='e')
     { a2[1][0]='O';  t1=countplsucc(a2); copy(a,a2); }
     if(b[1][1]=='e')
     { a2[1][1]='O';  t2=countplsucc(a2); copy(a,a2);}
     if(b[1][2]=='e')
     { a2[1][2]='O';  t3=countplsucc(a2); copy(a,a2);}

     if(t1<=t2&&t1<=t3) { c=0; m[2]=1; goto decided; }
     else if(t2<=t1&&t2<=t3) { c=1; m[2]=1; goto decided; }
     else { c=2; m[2]=1; goto decided; }
    }
  break;
  case 3:
  p=0;
  for(i=0;i<3;i++)
   {
    if(a[2][i]==' '||a[2][i]=='O') p++;
    else break;
   }
   if(p==3)
    {
      cout<<"dm3 3";
     r=2;
     if(b[2][0]=='e')
     { a2[2][0]='O';  t1=countplsucc(a2); copy(a,a2); }
     if(b[2][1]=='e')
     { a2[2][1]='O';  t2=countplsucc(a2); copy(a,a2);}
     if(b[2][2]=='e')
     { a2[2][2]='O';  t3=countplsucc(a2); copy(a,a2);}

     if(t1<=t2&&t1<=t3) { c=0; m[2]=1; goto decided; }
     else if(t2<=t1&&t2<=t3) { c=1; m[2]=1; goto decided; }
     else { c=2; m[2]=1; goto decided; }
    }
  break;
  case 4:
  p=0;
  for(i=0;i<3;i++)
   {
    if(a[i][0]==' '||a[i][0]=='O') p++;
    else break;
   }
   if(p==3)
    {
      cout<<"dm3 4";
     c=0;
     if(b[0][0]=='e')
     { a2[0][0]='O';  t1=countplsucc(a2); copy(a,a2); }
     if(b[1][0]=='e')
     { a2[1][0]='O';  t2=countplsucc(a2); copy(a,a2);}
     if(b[2][0]=='e')
     { a2[2][0]='O';  t3=countplsucc(a2); copy(a,a2);}

     if(t1<=t2&&t1<=t3) { r=0; m[2]=1; goto decided; }
     else if(t2<=t1&&t2<=t3) { r=1; m[2]=1; goto decided; }
     else { r=2; m[2]=1; goto decided; }
    }
  break;
  case 5:
  p=0;
  for(i=0;i<3;i++)
   {
    if(a[i][1]==' '||a[i][1]=='O') p++;
    else break;
   }
   if(p==3)
    {
      cout<<"dm3 5";
     c=1;
     if(b[0][1]=='e')
     { a2[0][1]='O';  t1=countplsucc(a2); copy(a,a2); }
     if(b[1][1]=='e')
     { a2[1][1]='O';  t2=countplsucc(a2); copy(a,a2);}
     if(b[2][1]=='e')
     { a2[2][1]='O';  t3=countplsucc(a2); copy(a,a2);}

     if(t1<=t2&&t1<=t3) { r=0; m[2]=1; goto decided; }
     else if(t2<=t1&&t2<=t3) { r=1; m[2]=1; goto decided; }
     else { r=2; m[2]=1; goto decided; }
    }
  break;
  case 6:
  p=0;
  for(i=0;i<3;i++)
   {
    if(a[i][2]==' '||a[i][2]=='O') p++;
    else break;
   }
   if(p==3)
    {
      cout<<"dm3 6";
     c=2;
     if(b[0][2]=='e')
     { a2[0][2]='O';  t1=countplsucc(a2); copy(a,a2); }
     if(b[1][2]=='e')
     { a2[1][2]='O';  t2=countplsucc(a2); copy(a,a2);}
     if(b[2][2]=='e')
     { a2[2][2]='O';  t3=countplsucc(a2); copy(a,a2);}

     if(t1<=t2&&t1<=t3) { r=0; m[2]=1; goto decided; }
     else if(t2<=t1&&t2<=t3) { r=1; m[2]=1; goto decided; }
     else { r=2; m[2]=1; goto decided; }
    }
   break;
   case 7:
    p=0;
   if(a[0][0]==' '||a[0][0]=='O') p++;
   if(a[1][1]==' '||a[1][1]=='O') p++;
   if(a[2][2]==' '||a[2][2]=='O') p++;
   if(p==3)
    {
      cout<<"dm3 7";
     if(b[0][0]=='e')
     { a2[0][0]='O';  t1=countplsucc(a2); copy(a,a2);}
     if(b[1][1]=='e')
     { a2[1][1]='O';  t2=countplsucc(a2); copy(a,a2);}
     if(b[2][2]=='e')
     { a2[2][2]='O';  t3=countplsucc(a2); copy(a,a2);}

     if(t1<=t2&&t1<=t3) { r=0; c=0; m[2]=1;  goto decided; }
     else if(t2<=t1&&t2<=t3) { r=1; c=1; m[2]=1;  goto decided; }
     else { r=2; c=2; m[2]=1;  goto decided; }
    }
   break;
   case 8:
   p=0;
   if(a[0][2]==' '||a[0][2]=='O') p++;
   if(a[1][1]==' '||a[1][1]=='O') p++;
   if(a[2][0]==' '||a[2][0]=='O') p++;
   if(p==3)
    {
      cout<<"dm3 8";
     if(b[0][2]=='e')
     { a2[0][2]='O';  t1=countplsucc(a2); copy(a,a2);}
     if(b[1][1]=='e')
     { a2[1][1]='O';  t2=countplsucc(a2); copy(a,a2);}
     if(b[2][0]=='e')
     { a2[2][0]='O';  t3=countplsucc(a2); copy(a,a2);}

     if(t1<=t2&&t1<=t3) { r=0; c=2; m[2]=1;  goto decided; }
     else if(t2<=t1&&t2<=t3) { r=1; c=1; m[2]=1;  goto decided; }
     else { r=2; c=0; m[2]=1; goto decided; }
    }
   break;
  }//switch ends
  k++;
  }while(k<=8);//do while ends

  decided:
  m[0]=r;
  m[1]=c;
 return;
}

void copy(char a[3][3],char a2[3][3])
{
int i,j;
 for(i=0;i<3;i++)
   for(j=0;j<3;j++)
    {
     a2[i][j]=a[i][j];
    }
 return;
}

int countplsucc(char a2[3][3])
{
  int t=0,p=0;

   if(a2[0][0]==' '||a2[0][0]=='X') p++;
   if(a2[0][1]==' '||a2[0][1]=='X') p++;
   if(a2[0][2]==' '||a2[0][2]=='X') p++;
   if(p==3) t++;

   p=0;
   if(a2[1][0]==' '||a2[1][0]=='X') p++;
   if(a2[1][1]==' '||a2[1][1]=='X') p++;
   if(a2[1][2]==' '||a2[1][2]=='X') p++;
   if(p==3) t++;

   p=0;
   if(a2[2][0]==' '||a2[2][0]=='X') p++;
   if(a2[2][1]==' '||a2[2][1]=='X') p++;
   if(a2[2][2]==' '||a2[2][2]=='X') p++;
   if(p==3) t++;

   p=0;
   if(a2[0][0]==' '||a2[0][0]=='X') p++;
   if(a2[1][0]==' '||a2[1][0]=='X') p++;
   if(a2[2][0]==' '||a2[2][0]=='X') p++;
   if(p==3) t++;

   p=0;
   if(a2[0][1]==' '||a2[0][1]=='X') p++;
   if(a2[1][1]==' '||a2[1][1]=='X') p++;
   if(a2[2][1]==' '||a2[2][1]=='X') p++;
   if(p==3) t++;

   p=0;
   if(a2[0][2]==' '||a2[0][2]=='X') p++;
   if(a2[1][2]==' '||a2[1][2]=='X') p++;
   if(a2[2][2]==' '||a2[2][2]=='X') p++;
   if(p==3) t++;

   p=0;
   if(a2[0][0]==' '||a2[0][0]=='X') p++;
   if(a2[1][1]==' '||a2[1][1]=='X') p++;
   if(a2[2][2]==' '||a2[2][2]=='X') p++;
   if(p==3) t++;

   p=0;
   if(a2[0][2]==' '||a2[0][2]=='X') p++;
   if(a2[1][1]==' '||a2[1][1]=='X') p++;
   if(a2[2][0]==' '||a2[2][0]=='X') p++;
   if(p==3) t++;

 return t;
}

void startinggraphic()
{
 char tic[9]={'T','I','C','T','A','C','T','O','E'};
 int i;
 clrscr();
 cout<<"\n\n\n\n\n\n\n\n    AMITRONIX PRESENTS . . .";
 //wait();
 clrscr();
  for(i=0;i<9;i++)
   {
    if(i%2==0) textcolor(LIGHTRED);
    else textcolor(LIGHTGREEN);
    putch(tic[i]);
    textcolor(WHITE);  putch(' ');
    //waitp(0.5);
    if( (i+1)%3==0 ) cout<<endl;
   }

   cout<<"\n\n\n\nUSE NUMERIC KEYPAD TO PLAY     (imagine 3X3 array of numbers to be game board)\n\nPRESS ENTER TO CONTINUE PLAYING\n\nPRESS E OR e AFTER A GAME IS OVER TO EXIT\n\nPRESS ANY KEY TO START GAME\n\nYOU CAN PRESS ALT+<ENTER> TO MINIMISE OR MAXIMISE\n\n\n\n\n\nThe one who makes a score of 10 first wins the tournament.";
   getch();
 return;
}























