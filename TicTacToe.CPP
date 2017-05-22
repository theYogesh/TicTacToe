#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>

char mat[3][3],p1='O',p2='X';
int a,flag,m;

void print(void)
{
    clrscr();
    gotoxy(37,10);
    cout<<mat[0][0]<<(char)-77<<mat[0][1]<<(char)-77<<mat[0][2];
    gotoxy(37,11);
    cout<<"-+-+-";
    gotoxy(37,12);
    cout<<mat[1][0]<<(char)-77<<mat[1][1]<<(char)-77<<mat[1][2];
    gotoxy(37,13);
    cout<<"-+-+-";
    gotoxy(37,14);
    cout<<mat[2][0]<<(char)-77<<mat[2][1]<<(char)-77<<mat[2][2];
    gotoxy(35,25);
}

void initial(void)
{
    int i,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            mat[i][j]=' ';
        }
    }
}

int comp(void)
{
    int c;
    c=random(9)+1;
    return c;
}

int check(void)
{
    int flag=0;
    if(mat[1][1]!=' ')
    {
        if(((mat[0][1]==mat[1][1])&&(mat[1][1]==mat[2][1]))||((mat[1][0]==mat[1][1])&&(mat[1][1]==mat[1][2]))||((mat[0][0]==mat[1][1])&&(mat[1][1]==mat[2][2]))||((mat[0][2]==mat[1][1])&&(mat[1][1]==mat[2][0])))
        {
            flag=1;
        }
    }
    if(mat[0][0]!=' ')
    {
        if(((mat[0][0]==mat[1][0])&&(mat[1][0]==mat[2][0]))||((mat[0][0]==mat[0][1])&&(mat[0][1]==mat[0][2])))
        {
            flag=1;
        }
    }
    if(mat[2][2]!=' ')
    {
        if(((mat[0][2]==mat[1][2])&&(mat[1][2]==mat[2][2]))||((mat[2][0]==mat[2][1])&&(mat[2][1]==mat[2][2])))
        {
            flag=1;
        }
    }
    return flag;
}

int putin(int a,char x)
{
    int flag=1;
    if(a==1)
    {
        if(mat[2][0]!=' ')
        {
            flag=0;
        }
        else
        {
            mat[2][0]=x;
        }
    }

    else if(a==2)
    {
        if(mat[2][1]!=' ')
        {
            flag=0;
        }

        else
        {
            mat[2][1]=x;
        }
    }
    else if(a==3)
    {
        if(mat[2][2]!=' ')
        {
            flag=0;
        }
        else
        {
            mat[2][2]=x;
        }
    }

    else if(a==4)
    {
        if(mat[1][0]!=' ')
        {
            flag=0;
        }
        else
        {
            mat[1][0]=x;
        }
    }

    else if(a==5)
    {
        if(mat[1][1]!=' ')
        {
            flag=0;
        }
        else
        {
            mat[1][1]=x;
        }
    }

    else if(a==6)
    {
        if(mat[1][2]!=' ')
        {
            flag=0;
        }
        else
        {
            mat[1][2]=x;
        }
    }

    else if(a==7)
    {
        if(mat[0][0]!=' ')
        {
            flag=0;
        }
        else
        {
            mat[0][0]=x;
        }
    }

    else if(a==8)
    {
        if(mat[0][1]!=' ')
        {
            flag=0;
        }
        else
        {
            mat[0][1]=x;
        }
    }

    else if(a==9)
    {
        if(mat[0][2]!=' ')
        {
            flag=0;
        }
        else
        {
            mat[0][2]=x;
        }
    }

    else
    {
        flag=0;
    }
    return flag;
}

void ani(char txt[100],int a,int y=5)
{
    int x,i;
    if(a==1)
    {
        y=25;
        strcat(txt,"'s TURN");
        x=(80-strlen(txt))/2+1;
        gotoxy(x,y);
        for(i=0; txt[i]!='\0'; i++)
        {
            delay(50);
            cout<<txt[i];
        }
    }

    else if(a==2)
    {
        y=30;
        txt="!!! INVALID MOVE !!!\a\a\a";
        x=(80-strlen(txt))/2+1;
        gotoxy(x,y);
        for(i=0; txt[i]!='\0'; i++)
        {
            delay(50);
            cout<<txt[i];
        }
        getch();
    }

    else if(a==3)
    {
        y=30;
        strcat(txt,"  W O N");
        x=(80-strlen(txt))/2+1;
        gotoxy(x,y);
        for(i=0; txt[i]!='\0'; i++)
        {
            delay(50);
            cout<<txt[i];
        }
        getch();
    }

    else
    {
        x=(80-strlen(txt))/2+1;
        gotoxy(x,y);
        for(i=0; txt[i]!='\0'; i++)
        {
            delay(50);
            cout<<txt[i];
        }
    }
}

void main()
{
    textcolor(1);
    textbackground(15);
    randomize();
    clrscr();
play:
    textcolor(1);
    textbackground(15);

    int me,i,j,c,p,s,n,turn,st,nt,tt;
    time_t t;
    char ch,name1[25],name2[25],name3[25];
    clrscr();
    initial();
    cout<<"\n\n\t\t\t\tSelect Game Type";
    cout<<"\n\n\t\t\t\t1.Player Vs Player";
    cout<<"\n\n\t\t\t\t2.Player vs Computer";
    cout<<"\n\n\t\t\t\tEnter your choice:";
    cin>>me;
    if(me==1)
    {
        clrscr();
        cout<<"\n\n\n\t\t\t\tEnter Name of PLAYER 1:";
        cin>>name1;
        cout<<"\n\n\n\t\t\t\tEnter Name of PLAYER 2:";
        cin>>name2;

        s=random(2)+1;

        if(s==2)
        {
            strcpy(name3,name1);

            for(a=0; name2[a]!='\0'; a++)
            {
                name1[a]=name2[a];
            }

            for(a=0; name3[a]!='\0'; a++)
            {
                name2[a]=name3[a];
            }

        }
        clrscr();

        int s=0;

        do
        {
            initial();
            do
            {
                st=(unsigned)time(&t);
                print();
                cout<<name1<<"'s TURN";
                cin>>a;

                if(a==1)
                {
                    m=2;
                    n=0;
                }

                if(a==2)
                {
                    m=2;
                    n=1;
                }

                if(a==3)
                {
                    m=2;
                    n=2;
                }

                if(a==4)
                {
                    m=1;
                    n=0;
                }

                if(a==5)
                {
                    m=1;
                    n=1;
                }

                if(a==6)
                {
                    m=1;
                    n=2;
                }

                if(a==7)
                {
                    m=0;
                    n=0;
                }

                if(a==8)
                {
                    m=0;
                    n=1;
                }

                if(a==9)
                {
                    m=0;
                    n=2;
                }

                while((a>10)||(mat[m][n]==p1)||(mat[m][n]==p2))
                {
                    cout<<"\aINVALID MOVE!!!!!!!!";
                    cin>>a;

                    if(a==1)
                    {
                        m=2;
                        n=0;
                    }

                    if(a==2)
                    {
                        m=2;
                        n=1;
                    }

                    if(a==3)
                    {
                        m=2;
                        n=2;
                    }

                    if(a==4)
                    {
                        m=1;
                        n=0;
                    }

                    if(a==5)
                    {

                        m=1;
                        n=1;
                    }

                    if(a==6)
                    {
                        m=1;
                        n=2;
                    }

                    if(a==7)
                    {
                        m=0;
                        n=0;
                    }

                    if(a==8)
                    {
                        m=0;
                        n=1;
                    }

                    if(a==9)
                    {
                        m=0;
                        n=2;
                    }
                }
                mat[m][n]=p1;
                s++;
                print();

                if(mat[0][0]==p1&&mat[0][0]==mat[1][1]&&mat[1][1]==mat[2][2])
                {
                    textbackground(4);
                    nt=(unsigned)time(&t);
                    tt=nt-st;
                    cout<<'\a'<<name1<<" WINS";
                    gotoxy(35,26);
                    cout<<"In just \" "<<tt<<" \" seconds";
                    break;
                }

                if(mat[2][0]==p1&&mat[2][0]==mat[1][1]&&mat[1][1]==mat[0][2])
                {
                    textbackground(4);
                    nt=(unsigned)time(&t);
                    tt=nt-st;
                    cout<<'\a'<<name1<<" WINS";
                    gotoxy(35,26);
                    cout<<"In just  "<<tt<<"  seconds";

                    break;
                }

                if(mat[0][0]==p1&&mat[0][0]==mat[1][0]&&mat[1][0]==mat[2][0])
                {
                    textbackground(4);
                    nt=(unsigned)time(&t);
                    tt=nt-st;
                    cout<<'\a'<<name1<<" WINS";
                    gotoxy(35,26);
                    cout<<"In just "<<tt<<"  seconds" ;
                    break;
                }

                if(mat[0][1]==p1&&mat[0][1]==mat[1][1]&&mat[1][1]==mat[2][1])
                {
                    textbackground(4);
                    nt=(unsigned)time(&t);
                    tt=nt-st;
                    cout<<'\a'<<name1<<" WINS";
                    gotoxy(35,26);
                    cout<<"In just "<<tt<<"  seconds";
                    break;
                }

                if(mat[0][2]==p1&&mat[0][2]==mat[1][2]&&mat[1][2]==mat[2][2])
                {
                    textbackground(4);
                    nt=(unsigned)time(&t);
                    tt=nt-st;
                    cout<<'\a'<<name1<<" WINS";
                    gotoxy(35,26);
                    cout<<"In just "<<tt<<"  seconds";
                    break;
                }

                if(mat[0][0]==p1&&mat[0][0]==mat[0][1]&&mat[0][1]==mat[0][2])
                {
                    textbackground(4);
                    nt=(unsigned)time(&t);
                    tt=nt-st;
                    cout<<'\a'<<name1<<" WINS";
                    gotoxy(35,26);
                    cout<<"In just "<<tt<<" seconds";
                    break;
                }

                if(mat[1][0]==p1&&mat[1][0]==mat[1][1]&&mat[1][1]==mat[1][2])
                {
                    textbackground(4);
                    nt=(unsigned)time(&t);
                    tt=nt-st;
                    cout<<'\a'<<name1<<" WINS";
                    gotoxy(35,26);
                    cout<<"In just "<<tt<<"  seconds";
                    break;
                }

                if(mat[2][0]==p1&&mat[2][0]==mat[2][1]&&mat[2][1]==mat[2][2])
                {
                    textbackground(4);
                    nt=(unsigned)time(&t);
                    tt=nt-st;
                    cout<<'\a'<<name1<<" WINS";
                    gotoxy(35,26);
                    cout<<"In just "<<tt<<" seconds";
                    break;
                }

                if(s==9)
                {
                    textbackground(4);
                    cout<<"\aIts a DRAW:";
                    break;
                }

                cout<<name2<<"'s TURN";
                cin>>a;

                if(a==1)
                {
                    m=2;
                    n=0;
                }

                if(a==2)
                {
                    m=2;
                    n=1;
                }

                if(a==3)
                {
                    m=2;
                    n=2;
                }

                if(a==4)
                {
                    m=1;
                    n=0;
                }

                if(a==5)
                {
                    m=1;
                    n=1;
                }

                if(a==6)
                {
                    m=1;
                    n=2;
                }

                if(a==7)
                {
                    m=0;
                    n=0;
                }

                if(a==8)
                {
                    m=0;
                    n=1;
                }

                if(a==9)
                {
                    m=0;
                    n=2;
                }

                while((a>10)||(mat[m][n]==p1)||(mat[m][n]==p2))
                {
                    cout<<"\aINVALID MOVE!!!!!!!!";
                    cin>>a;

                    if(a==1)
                    {
                        m=2;
                        n=0;
                    }

                    if(a==2)
                    {
                        m=2;
                        n=1;
                    }

                    if(a==3)
                    {
                        m=2;
                        n=2;
                    }

                    if(a==4)
                    {
                        m=1;
                        n=0;
                    }

                    if(a==5)
                    {
                        m=1;
                        n=1;
                    }

                    if(a==6)
                    {
                        m=1;
                        n=2;
                    }

                    if(a==7)
                    {
                        m=0;
                        n=0;
                    }

                    if(a==8)
                    {
                        m=0;
                        n=1;
                    }

                    if(a==9)
                    {
                        m=0;
                        n=2;
                    }

                }
                mat[m][n]=p2;
                s++;
                print();

                if(mat[0][0]==p2&&mat[0][0]==mat[1][1]&&mat[1][1]==mat[2][2])
                {
                    textbackground(4);
                    tt=(unsigned)time(&t);
                    tt=nt-st;
                    cout<<'\a'<<name2<<" WINS";
                    gotoxy(35,26);
                    cout<<"In just "<<tt<<" seconds";
                    break;
                }

                if(mat[2][0]==p2&&mat[2][0]==mat[1][1]&&mat[1][1]==mat[0][2])
                {
                    textbackground(4);
                    tt=(unsigned)time(&t);
                    tt=nt-st;
                    cout<<'\a'<<name2<<" WINS";
                    gotoxy(35,26);
                    cout<<"In just "<<tt<<" seconds";
                    break;
                }

                if(mat[0][0]==p2&&mat[0][0]==mat[1][0]&&mat[1][0]==mat[2][0])
                {
                    textbackground(4);
                    tt=(unsigned)time(&t);
                    tt=nt-st;
                    cout<<'\a'<<name2<<" WINS";
                    gotoxy(35,26);
                    cout<<"In just "<<tt<<" seconds";
                    break;
                }

                if(mat[0][1]==p2&&mat[0][1]==mat[1][1]&&mat[1][1]==mat[2][1])
                {
                    textbackground(4);
                    tt=(unsigned)time(&t);
                    tt=nt-st;
                    cout<<'\a'<<name2<<" WINS";
                    gotoxy(35,26);
                    cout<<"In just "<<tt<<" seconds";
                    break;
                }

                if(mat[0][2]==p2&&mat[0][2]==mat[1][2]&&mat[1][2]==mat[2][2])
                {
                    textbackground(4);
                    tt=(unsigned)time(&t);
                    tt=nt-st;
                    cout<<'\a'<<name2<<" WINS";
                    gotoxy(35,26);
                    cout<<"In just "<<tt<<" seconds";
                    break;
                }

                if(mat[0][0]==p2&&mat[0][0]==mat[0][1]&&mat[0][1]==mat[0][2])
                {
                    textbackground(4);
                    tt=(unsigned)time(&t);
                    tt=nt-st;
                    cout<<'\a'<<name2<<" WINS";
                    gotoxy(35,26);
                    cout<<"In just "<<tt<<" seconds";
                    break;
                }

                if(mat[1][0]==p2&&mat[1][0]==mat[1][1]&&mat[1][1]==mat[1][2])
                {
                    textbackground(4);
                    tt=(unsigned)time(&t);
                    tt=nt-st;
                    cout<<'\a'<<name2<<" WINS";
                    gotoxy(35,26);
                    cout<<"In just "<<tt<<" seconds";
                    break;
                }

                if(mat[2][0]==p2&&mat[2][0]==mat[2][1]&&mat[2][1]==mat[2][2])
                {
                    textbackground(4);
                    tt=(unsigned)time(&t);
                    tt=nt-st;
                    cout<<'\a'<<name2<<" WINS";
                    gotoxy(35,26);
                    cout<<"In just "<<tt<<" seconds";
                    break;
                }
            } while(5);
        } while(ch=='Y'||ch=='y');
        
        getch();
        cout<<"\n\n\n\nWant to play more(Y/N)";
        cin>>ch;
        if(ch=='N'||ch=='n')
        {
            exit(0);
        }
        else
        {
            goto play;
        }
    }

    if(me==2)
    {

        clrscr();
        cout<<"Enter your Name:";
        cin>>name1;

        s=random(2)+1;
        if(s==1)
        {
            n=10;
        }
        if(s==2)
        {
            n=11;
        }
        clrscr();
        st=(unsigned)time(&t);
        for(i=s; i<n; i++)
        {
tp1:
            print();
            if(i%2==0)
            {
                cout<<name1<<"'s TURN: ";
                cin>>turn;
                p=putin(turn,p2);
                if(p==0)
                {
                    ani("invalid",2);
                    goto tp1;
                }
                c=check();
                if(c==1)
                {
                    print();
                    tt=(unsigned)time(&t);
                    textbackground(4);
                    tt=nt-st;
                    cout<<'\a'<<name1<<" WINS";
                    gotoxy(35,26);
                    cout<<"In just "<<tt<<" seconds";
                    goto won1;
                }
            }

            else
            {
                delay(250);
                turn=comp();
                p=putin(turn,p1);
                if(p==0)
                {
                    goto tp1;
                }
                c=check();
                if(c==1)
                {
                    print();
                    tt=(unsigned)time(&t);
                    textbackground(4);
                    tt=nt-st;
                    cout<<"\aCOMPUTER W O N";
                    gotoxy(35,26);
                    cout<<"In just "<<tt<<" seconds";

                    goto won1;
                }
            }
        }

        ani("IT's a DRAW",5,30);
won1:
        getch();
        ani("Want to play more(Y/N)",5,28);
        cin>>ch;
        if(ch=='N'||ch=='n')
        {
            exit(0);
        }
        else
        {
            goto play;
        }
    }
    else
    {
        ani("!!!WRONG CHOICE!!!",5,25);
        getch();
        goto play;
    }
}
