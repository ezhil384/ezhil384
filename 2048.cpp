#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

void move_up(int arr[4][4])
{
	int i,j,li,ri;
	for(j=0;j<4;j++)
	{
		li=0,ri=j;
		for(i=1;i<4;i++)
		{
			if(arr[i][j]!=0)
			{
				if(arr[i-1][j]==0 || arr[i-1][j]==arr[i][j])
				{
					if(arr[li][ri]==arr[i][j])
					{
						arr[li][ri]*=2;
						arr[i][j]=0;
					}
					else
					{
						if(arr[li][ri]==0)
						{
							arr[li][ri]=arr[i][j];
							arr[i][j]=0;
						}
						else
						{
							arr[++li][ri]=arr[i][j];
							arr[i][j]=0;
						}
					}
				}
				else li++;
			}
		}
	}
}

void move_down(int a[4][4])
{
	int i,j,li,ri;
	for(j=0;j<4;j++)
	{
		li=3,ri=j;
		for(i=2;i>=0;i--)
		{
			if(a[i][j]!=0)
			{
				if(a[i+1][j]==0 || a[i+1][j]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[--li][ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else li--;
			}
		}
	}
}

void move_left(int a[4][4])
{
	int i,j,li,ri;
	for(i=0;i<4;i++)
	{
		li=i,ri=0;
		for(j=1;j<4;j++)
		{
			if(a[i][j]!=0)
			{
				if(a[i][j-1]==0 || a[i][j-1]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[li][++ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else ri++;
			}
		}
	}
}

void move_right(int a[4][4])
{
	int i,j,li,ri;
	for(i=0;i<4;i++)
	{
		li=i,ri=3;
		for(j=2;j>=0;j--)
		{
			if(a[i][j]!=0)
			{
				if(a[i][j+1]==0 || a[i][j+1]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[li][--ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else ri--;
			}
		}
	}
}

void addblock(int arr[4][4])
{
	int row,col;
	srand(time(0));
	while(1)
	{
		row=rand()%4;
		col=rand()%4;
		if(arr[row][col]==0)
		{
			arr[row][col]=pow(2,row%2 + 1);
			break;
		}
	}

}

void display(int arr[4][4])
{
	cout<<"\n\t\t\t\tPress Esc anytime to quit the game";
	cout<<"\n\n\n\n";
	int i,j;
	for(i=0;i<4;i++)
	{
		cout<<"\t\t\t\t---------------------\n\t\t\t\t";
		for(j=0;j<4;j++)
		{
			if(arr[i][j]==0) cout<<"|    ";
			else
			{
                if(arr[i][j]/10==0)
                    cout<<"|  "<<arr[i][j]<<" ";
				else
                    cout<<"| "<<arr[i][j]<<" ";
			}
		}
		cout<<"|"<<endl;
	}
	cout<<"\t\t\t\t---------------------\n";
}

int check(int check[4][4],int arr[4][4])
{
	int fl=1,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(check[i][j]!=arr[i][j])
    		{
    			fl=0;
    			break;
			}
	return fl;
}

int game_ends(int arr[4][4])
{
	int fl=0,gl=0,i,j;
	for(i=0;i<4;i++)
    {
    	for(j=0;j<4;j++)
        {
            if(arr[i][j]==0)
    		{
    			fl=1;
				break;
			}
        }
    }
	for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
    		if(arr[i+1][j]==arr[i][j] || arr[i][j+1]==arr[i][j])
    		{
    			gl=1;
    			break;
			}
        }
    }

	if(fl || gl)
        return 1;
	else
        return 0;
}

int victory(int arr[4][4])
{
    int fl=0,i,j;
	for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]==2048)
    		{
    			fl=1;
				break;
			}
        }
        if(fl==1)
            break;
    }
    return fl;
}

int main()
{
	cout<<"\n\n\t\t\t\t\t2048 GAME\n\n\t\tUse simple arithmetic calculations to achieve the score 2048\n\n\t\tPress any key to continue";
	getch();
	system("cls");
	int i1,i2,i3,i4,i,j;
	int arr[4][4]={0},prev[4][4]={0};
	srand(time(0));
	i1=rand()%4;
	i2=rand()%4;
	int app;
	app=((rand()%2)+1)*2;
	while(1)
	{
		i3=rand()%4;
		i4=rand()%4;
		if(i3!=i1 || i4!=i2) break;
	}
	arr[i1][i2]=2;
	arr[i3][i4]=app;
	display(arr);
	int ch;
	while (1)
    {
    	for(i=0;i<4;i++)
    		for(j=0;j<4;j++)
    			prev[i][j]=arr[i][j];        //stores the current array to compare and see if there needs to be an additional block added
    	ch=getch();
    	system("cls");
    	if(ch==72) move_up(arr);
    	if(ch==80) move_down(arr);
    	if(ch==75) move_left(arr);
    	if(ch==77) move_right(arr);
		if(ch==27) break;                 //escape the game

		if(!check(prev,arr))                 //checks if the moves have made a difference or not
			addblock(arr);
		display(arr);

		if(!game_ends(arr))                 //final game over check
		{
			cout<<"\n\n\t\t\tGAME OVER!!\n\n\n";
			getch();
			break;
		}
		if(victory(arr))                 //final game over check
		{
			cout<<"\n\n\t\t\tYOU HAVE WON THE GAME!!\n\n\n";
			getch();
			break;
		}
	}
	return 0;
}
